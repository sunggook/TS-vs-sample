#include "HostTextureStream.h"

#include "CameraCapturer.h"
#include "DrawRBGManager.h"

using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Callback;

HostTextureStream::HostTextureStream(
    const wchar_t* stream_id,
    ID3D11Device* d3d_device,
    ICoreWebView2ExperimentalEnvironment12* webview2_environment,
    HWND window_handle) : d3d_device_(d3d_device), window_handle_(window_handle) {

    // stream_id is L"webview2-abcd1234".
    DX::ThrowIfFailed(webview2_environment->CreateTextureStream(stream_id, d3d_device, &texture_stream_));

    texture_stream_->AddAllowedOrigin(L"https://sunggook.github.io", TRUE);
    RegisterTextureStreamEvent();
}

HostTextureStream::~HostTextureStream() = default;

HRESULT HostTextureStream::SendTexture(int buffer_resource_id, ULONGLONG timestamp) {
    // Present API should be called on same thread where main WebView
    // object is created.
    auto it = buffer_resource_id_to_texture_buffer_.find(buffer_resource_id);
    if (it == buffer_resource_id_to_texture_buffer_.end()) {
        return HRESULT_FROM_WIN32(ERROR_INVALID_STATE);
    }

    // assert(texture_buffer != nullptr);
    auto texture_buffer = it->second;
    texture_buffer->put_Timestamp(timestamp);
    texture_stream_->PresentTexture(texture_buffer.Get());

    return S_OK;
}

HRESULT HostTextureStream::GetAvailableBuffer() {
    // Register only buffers of the first TextureStream.
    ComPtr<ICoreWebView2ExperimentalTexture> texture_buffer;
    HRESULT hr = texture_stream_->GetAvailableTexture(&texture_buffer);
    if (FAILED(hr)) {
        // No buffer is available.
        SendToSlimCoreWithResource(false, nullptr, -1);
        return hr;
    }

    IUnknown* dxgi_resource;
    texture_buffer->get_Resource(&dxgi_resource);

    // Force IntPtr to int type.
    int buffer_resource_id = static_cast<int>(reinterpret_cast<intptr_t>(dxgi_resource));
    SendToSlimCoreWithResource(false, nullptr, buffer_resource_id);

    return S_OK;
}

HRESULT HostTextureStream::CreateNewBuffer(uint32_t width, uint32_t height) {
    width_ = width;
    height_ = height;

    ComPtr<ICoreWebView2ExperimentalTexture> texture_buffer;
    DX::ThrowIfFailed(texture_stream_->CreateTexture(width_, height_, &texture_buffer));
    assert(texture_buffer);
    
    // texture_buffer->get_Handle(&slimCoreHandle);
    IUnknown* texture_resource = nullptr;
    texture_buffer->get_Resource(&texture_resource);
    int buffer_resource_id = static_cast<int>(reinterpret_cast<intptr_t>(texture_resource));
    buffer_resource_id_to_texture_buffer_[buffer_resource_id] = texture_buffer;

    SendToSlimCoreWithResource(true, texture_resource, buffer_resource_id);
    return S_OK;
}

void HostTextureStream::RegisterTextureStreamEvent() {
    EventRegistrationToken start_token;
    texture_stream_->add_StartRequested(Callback<ICoreWebView2ExperimentalTextureStreamStartRequestedEventHandler>(
        [this](ICoreWebView2ExperimentalTextureStream* texture_stream, IUnknown* eventArgs) -> HRESULT {

            // Create IPC thread when stream is requested.
            // Respective thread proc handles unique stream id.
            if (!thread_id_) {
                ::CreateThread(nullptr, 0, ThreadProcForStreamId, window_handle_, 0, &thread_id_);
            }

            // Start streaming.
            DX::ThrowIfFailed(CameraCapturer::GetInstance()->StartMediaFoundationCapture(window_handle_));

            return S_OK;
        }).Get(), &start_token);

    EventRegistrationToken stop_token;
    texture_stream_->add_Stopped(Callback<ICoreWebView2ExperimentalTextureStreamStoppedEventHandler>(
        [](ICoreWebView2ExperimentalTextureStream* texture_stream, IUnknown* eventArgs) -> HRESULT {
            // TODO: you could stop streaming here if not already stopped.
            return S_OK;
        }).Get(), &stop_token);

    EventRegistrationToken texture_token;
    texture_stream_->add_ErrorReceived(Callback<ICoreWebView2ExperimentalTextureStreamErrorReceivedEventHandler>(
        [](ICoreWebView2ExperimentalTextureStream* sender, ICoreWebView2ExperimentalTextureStreamErrorReceivedEventArgs* args) {
            COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND kind;
            HRESULT hr = args->get_Kind(&kind);
            assert(SUCCEEDED(hr));

            switch (kind)
            {
            case COREWEBVIEW2_TEXTURE_STREAM_ERROR_NO_VIDEO_TRACK_STARTED:
            case COREWEBVIEW2_TEXTURE_STREAM_ERROR_TEXTURE_IN_USE:
                // assert(false);
                break;
            default:
                break;
            }
            return S_OK;
        }).Get(), &texture_token);


    EventRegistrationToken post_token;
    texture_stream_->add_WebTextureReceived(Callback<ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventHandler>(
        [&](ICoreWebView2ExperimentalTextureStream* sender, ICoreWebView2ExperimentalTextureStreamWebTextureReceivedEventArgs* args) {
            static bool posted_window_visible = false;

            if (!posted_window_visible_) {
                posted_window_visible_ = true;
                ShowWindow(web_texture_window_handle_, SW_SHOW);
            }
            ULONGLONG timestamp;
            ComPtr<ICoreWebView2ExperimentalWebTexture> web_texture;

            DX::ThrowIfFailed(args->get_WebTexture(&web_texture));
            DX::ThrowIfFailed(web_texture->get_Timestamp(&timestamp));

            HANDLE handle;
            DX::ThrowIfFailed(web_texture->get_Handle(&handle));

            ComPtr<IUnknown> texture_2d;
            DX::ThrowIfFailed(web_texture->get_Resource(&texture_2d));

            DX::ThrowIfFailed(draw_rgb_manager_->DrawTextureWithWICBitmap(handle, std::move(texture_2d)));

            return S_OK;
        }).Get(), &post_token);

    EventRegistrationToken post_stop_token;
    texture_stream_->add_WebTextureStreamStopped(Callback<ICoreWebView2ExperimentalTextureStreamWebTextureStreamStoppedEventHandler>(
        [&](ICoreWebView2ExperimentalTextureStream* sender, IUnknown* args) {
            ShowWindow(web_texture_window_handle_, SW_HIDE);
            posted_window_visible_ = false;

            return S_OK;
        }).Get(), &post_stop_token);

    if (!web_texture_window_handle_) {
        web_texture_window_handle_ = CreateSubWindow(nullptr, SW_HIDE, L"ChildWClass", L"Posted Texture");
    }

    draw_rgb_manager_ = std::make_unique<DrawRBGManager>();
    draw_rgb_manager_->Init(web_texture_window_handle_, d3d_device_);
}
