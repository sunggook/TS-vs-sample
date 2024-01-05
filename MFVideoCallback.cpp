
#include "MFVideoCallback.h"

#include <utility>

using Microsoft::WRL::ComPtr;

MFVideoCallback::MFVideoCallback(HWND hWnd) :
    hwnd_(hWnd) {
}

MFVideoCallback::~MFVideoCallback() {}

void MFVideoCallback::Init(ID3D11Device* d3d_device, IDXGISwapChain* swapChain) {
    d3d_device_ = d3d_device;
    d3d_device_->GetImmediateContext(&device_context_);
    swap_chain_ = swapChain;
    ui_thread_id_ = ::GetCurrentThreadId();
}

IFACEMETHODIMP MFVideoCallback::QueryInterface(REFIID riid, void** object) {
    HRESULT hr = E_NOINTERFACE;
    if (riid == IID_IUnknown) {
        *object = this;
        hr = S_OK;
    }
    else if (riid == IID_IMFCaptureEngineOnSampleCallback) {
        *object = static_cast<IMFCaptureEngineOnSampleCallback*>(this);
        hr = S_OK;
    }
    else if (riid == IID_IMFCaptureEngineOnEventCallback) {
        *object = static_cast<IMFCaptureEngineOnEventCallback*>(this);
        hr = S_OK;
    }

    return hr;
}

IFACEMETHODIMP_(ULONG) MFVideoCallback::AddRef()  {
    return (ULONG)InterlockedIncrement(&m_iRefCount);
}

IFACEMETHODIMP_(ULONG) MFVideoCallback::Release()  {
    ULONG cRef = InterlockedDecrement(&m_iRefCount);
    if (0 == cRef)
    {
        delete this;
    }
    return cRef;
}

HRESULT MFVideoCallback::SetCaptureErrorEvent(HANDLE capture_error, HANDLE capture_initialize) {
    capture_error_ = capture_error;
    capture_initialize_ = capture_initialize;
    return S_OK;
}

IFACEMETHODIMP MFVideoCallback::OnEvent(IMFMediaEvent* media_event) {
    //if (!observer_) {
    //    return S_OK;
    //}
    //observer_->OnEvent(media_event);
    GUID capture_event_guid = GUID_NULL;
    HRESULT hr;
    media_event->GetStatus(&hr);
    media_event->GetExtendedType(&capture_event_guid);

    if (capture_event_guid == MF_CAPTURE_ENGINE_ERROR || FAILED(hr)) {
        ::SetEvent(capture_error_);
        // There should always be a valid error
        hr = SUCCEEDED(hr) ? E_UNEXPECTED : hr;
    }
    else if (capture_event_guid == MF_CAPTURE_ENGINE_INITIALIZED) {
        ::SetEvent(capture_initialize_); // 
    }
    return S_OK;
}

IFACEMETHODIMP MFVideoCallback::OnSample(IMFSample* sample) {

    if (!sample) {
        return S_OK;
    }

    LONGLONG raw_time_stamp = 0;
    sample->GetSampleTime(&raw_time_stamp);

    DWORD count = 0;
    sample->GetBufferCount(&count);

    assert(count == 1);
    for (DWORD i = 0; i < count; ++i) {
        ComPtr<IMFMediaBuffer> buffer;
        sample->GetBufferByIndex(i, &buffer);
        if (buffer) {
            ComPtr<ID3D11Texture2D> texture;
            GetTextureFromMFBuffer(buffer.Get(), &texture);
            static int counts_ = 0;

            RequestToWebViewProcess(texture.Get(), raw_time_stamp);
            counts_++;
        }
    }
    return S_OK;
}

void MFVideoCallback::RequestToWebViewProcess(ID3D11Texture2D* source_texture, ULONGLONG raw_time_stamp) {
    EnsureMemoryMappedSection();

    // Request available buffer
    int64_t buffer_id = -1;
    SendToWebViewProcess(false, true, 0, 0, -1, 0);
    bool result = WaitFromWebViewProcess(false, true, buffer_id);
    if (!result || buffer_id == -1) {
        // Request new buffer
        D3D11_TEXTURE2D_DESC desc = {};
        source_texture->GetDesc(&desc);

        SendToWebViewProcess(true, false, desc.Width, desc.Height, -1, 0);
        bool result = WaitFromWebViewProcess(true, false, buffer_id);
        assert(result);
        return;
    }

    // Copy source texture to the shared texture.
    ComPtr<ID3D11Texture2D> sharedTexture = buffer_id_to_texture_2ds_[buffer_id];

    ComPtr<IDXGIKeyedMutex> keyed_mutex;
    sharedTexture.As(&keyed_mutex);
    keyed_mutex->AcquireSync(0, INFINITE);
    device_context_->CopySubresourceRegion(
        sharedTexture.Get(),
        0,
        0,
        0,
        0,
        source_texture,
        0,
        nullptr);
    keyed_mutex->ReleaseSync(0);

    // Request setbuffer and present.
    SendToWebViewProcess(false, false, 0, 0, static_cast<int>(buffer_id), raw_time_stamp);
}

bool MFVideoCallback::SendToWebViewProcess(bool buffer_create_request, bool avaialable_buffer_request, UINT32 width, UINT32 height, int buffer_id, ULONGLONG timestamp) {
    EnsureMemoryMappedSection();

    if (buffer_create_request) {
        texture_buffer_info_on_slimcore_->command = SharedBufferCommand::RequestCreateNewBuffer;
        texture_buffer_info_on_slimcore_->width = width;
        texture_buffer_info_on_slimcore_->height = height;
    }
    else if (avaialable_buffer_request) {
        texture_buffer_info_on_slimcore_->command = SharedBufferCommand::RequestBuffer;
    }
    else {
        // It is for SetBufferAndPresent
        texture_buffer_info_on_slimcore_->command = SharedBufferCommand::RequestSetBuferAndPresent;
        texture_buffer_info_on_slimcore_->timestamp = timestamp;
        texture_buffer_info_on_slimcore_->buffer_id = buffer_id;
    }

    ::SetEvent(from_slimcore_to_webview_process_);

    return true;
}

bool MFVideoCallback::WaitFromWebViewProcess(bool buffer_create_request, bool avaialable_buffer_request, int64_t& out_buffer_id) {
    
    constexpr int kMaxSlimCoreWaitTimeout = 2 * 100000; // 2s, but use 200s for debug.
    DWORD result = ::WaitForSingleObject(from_webview_process_to_slimcore_, kMaxSlimCoreWaitTimeout);

    if (result == WAIT_OBJECT_0) {
        if (buffer_create_request) {
            if (texture_buffer_info_on_slimcore_->command == SharedBufferCommand::ResponseBufferCreated) {
                HANDLE texture_handle = reinterpret_cast<HANDLE>(texture_buffer_info_on_slimcore_->handle);
                ComPtr<ID3D11Device1> d3d_device1_;
                d3d_device_.As(&d3d_device1_);

                ComPtr<ID3D11Texture2D> texture_2d;
                DX::ThrowIfFailed(d3d_device1_->OpenSharedResource1(texture_handle, IID_PPV_ARGS(&texture_2d)));

                assert(texture_buffer_info_on_slimcore_->buffer_id != -1);
                buffer_id_to_texture_2ds_.insert(std::pair<int64_t, ComPtr<ID3D11Texture2D>>(texture_buffer_info_on_slimcore_->buffer_id, texture_2d));

                out_buffer_id = texture_buffer_info_on_slimcore_->buffer_id;
                return true;
            }
            else {
                // assert(false);
            }
        }
        else if (avaialable_buffer_request) {
            if (texture_buffer_info_on_slimcore_->command == SharedBufferCommand::ResponseBufferAvailableRequest) {
                if (texture_buffer_info_on_slimcore_->buffer_id != -1) {
                    out_buffer_id = texture_buffer_info_on_slimcore_->buffer_id;
                    return true;
                }
            }
        }
        else {
            // Request setBufer and Present. 
        }
    }
    else {
        // result = GetLastError();
    }
    return false;
}

void MFVideoCallback::EnsureMemoryMappedSection() {
    DWORD error = 0;

    if (from_webview_process_to_slimcore_ == INVALID_HANDLE_VALUE) {

        // 
        from_webview_process_to_slimcore_ = CreateEvent(nullptr, FALSE, FALSE, L"Local\\SendToSimCore");
        error = GetLastError();

        assert(from_webview_process_to_slimcore_ != INVALID_HANDLE_VALUE);

        from_slimcore_to_webview_process_ =
            OpenEvent(EVENT_MODIFY_STATE, FALSE, L"Local\\RequestFromSlimCore1");

        error = GetLastError();
        assert(from_slimcore_to_webview_process_ != INVALID_HANDLE_VALUE);
    }

    if (!texture_buffer_info_on_slimcore_) {
        
        mapping_handle_ =
            ::OpenFileMappingW(FILE_MAP_ALL_ACCESS, FALSE, L"Local\\webview2-abcd1234");
        error = GetLastError();

        texture_buffer_info_on_slimcore_ = reinterpret_cast<TextureBufferInfo*>(
            ::MapViewOfFile(mapping_handle_, FILE_MAP_ALL_ACCESS, 0, 0, 0));
        error = GetLastError();
    }
}

HRESULT MFVideoCallback::GetTextureFromMFBuffer(IMFMediaBuffer* mf_buffer, ID3D11Texture2D** texture_out) {
    Microsoft::WRL::ComPtr<IMFDXGIBuffer> dxgi_buffer;
    DX::ThrowIfFailed(mf_buffer->QueryInterface(IID_PPV_ARGS(&dxgi_buffer)));

    Microsoft::WRL::ComPtr<ID3D11Texture2D> d3d_texture;
    DX::ThrowIfFailed(dxgi_buffer->GetResource(IID_PPV_ARGS(&d3d_texture)));
    *texture_out = d3d_texture.Detach();

    return S_OK;
}

