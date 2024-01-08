
#include "MFCaptureManager.h"

#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using Microsoft::WRL::ComPtr;

MFCaptureManager::MFCaptureManager(HWND hwnd) : 
        hwnd_(hwnd) {

    RECT bounds;
    GetClientRect(hwnd_, &bounds);
    window_width_ = (bounds.right - bounds.left) / 2;
    window_height_ = bounds.bottom - bounds.top;
    // CreateMFDevice();
}

MFCaptureManager::~MFCaptureManager() {
    mf_engine_ = nullptr;

    video_callback_ = nullptr;
}

HRESULT MFCaptureManager::InitMF() {
    DX::ThrowIfFailed(CreateCaptureEngine(&mf_engine_));

    ComPtr<IMFAttributes> attributes;
    DX::ThrowIfFailed(MFCreateAttributes(&attributes, 1));
    DX::ThrowIfFailed(attributes->SetUINT32(MF_CAPTURE_ENGINE_USE_VIDEO_DEVICE_ONLY, TRUE));
    DX::ThrowIfFailed(attributes->SetUnknown(MF_CAPTURE_ENGINE_D3D_MANAGER, mf_dxgi_device_manager_.Get()));

    DX::ThrowIfFailed(CreateDeviceSourceMediaFoundation());

    video_callback_ = new MFVideoCallback(hwnd_);
    video_callback_->Init(d3d_device_.Get(), swapChain_.Get());

    // We pass the lifetime of MFVideoCallback to the mf_engine_.
    DX::ThrowIfFailed(mf_engine_->Initialize(video_callback_.Get(), attributes.Get(), nullptr,
        mf_source_.Get()));
    DX::ThrowIfFailed(WaitOnCaptureEvent(MF_CAPTURE_ENGINE_INITIALIZED));
    return S_OK;
}

HRESULT MFCaptureManager::CreateMFDevice(LUID luid, bool warp_mode, ID3D11Device** device) {
    UINT d3d_device__reset_token = 0;
    DX::ThrowIfFailed(MFCreateDXGIDeviceManager(&d3d_device__reset_token,
        &mf_dxgi_device_manager_));

    mf_dxgi_device_manager_->ResetDevice(d3d_device_.Get(), d3d_device__reset_token);

    static const D3D_FEATURE_LEVEL s_featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_3,
        D3D_FEATURE_LEVEL_9_2,
        D3D_FEATURE_LEVEL_9_1,
    };

    // Enumerate adapters and select with given LUID.
    // The code below until d3d_device_.CopyTo(device) can be located only in the
    // WebView process, and all this function is on the SlimCore.
    Microsoft::WRL::ComPtr<IDXGIFactory> spFactory;
    DX::ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&spFactory)));
    UINT i = 0;
    IDXGIAdapter* pAdapter;
    std::vector<IDXGIAdapter*> vAdapters;

    D3D_DRIVER_TYPE driveType = warp_mode ? D3D_DRIVER_TYPE_WARP : D3D_DRIVER_TYPE_HARDWARE;
    const uint32_t kDeviceFlags = warp_mode ? D3D11_CREATE_DEVICE_BGRA_SUPPORT :
        D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_VIDEO_SUPPORT;

    while (spFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND)
    {
        DXGI_ADAPTER_DESC desc;
        DX::ThrowIfFailed(pAdapter->GetDesc(&desc));
        if (desc.AdapterLuid.HighPart == luid.HighPart &&
            desc.AdapterLuid.LowPart == luid.LowPart) {
            dxgi_adapter_ = pAdapter;
            driveType = D3D_DRIVER_TYPE_UNKNOWN;
            break;
        }

        vAdapters.push_back(pAdapter);
        ++i;
    }

    DX::ThrowIfFailed(D3D11CreateDevice(dxgi_adapter_.Get(), driveType, nullptr,
        kDeviceFlags, s_featureLevels, ARRAYSIZE(s_featureLevels), D3D11_SDK_VERSION,
        &d3d_device_, nullptr, &d3d_context_));

    d3d_device_.CopyTo(device);

    Microsoft::WRL::ComPtr<ID3D10Multithread> d3d_device_multithread;
    DX::ThrowIfFailed(d3d_device_.As(&d3d_device_multithread));
    DX::ThrowIfFailed(d3d_device_multithread->SetMultithreadProtected(TRUE));
    DX::ThrowIfFailed(mf_dxgi_device_manager_->ResetDevice(d3d_device_.Get(), d3d_device__reset_token));
    return S_OK;
}

HRESULT MFCaptureManager::AllocateAndStartLocked() {
    if (!mf_engine_) {
        return E_FAIL;
    }

    ComPtr<IMFCaptureSource> capture_source;
    DX::ThrowIfFailed(mf_engine_->GetSource(&capture_source));

    std::list<CapabilityWin> video_capabilities;
    HRESULT hr = FillCapabilities(capture_source.Get(), false, &video_capabilities);

    VideoCaptureFormat requested_format = {};
    requested_format.frame_size = { 640, 480 };
    requested_format.frame_rate = 30.0;
    
    CapabilityWin best_match_video_capability;
    if (video_capabilities.empty()) {
        //best_match_video_capability.stream_index = 0;
        //best_match_video_capability.media_type_index = 0;g
        //best_match_video_capability.supported_format.frame_rate = 30;
        //best_match_video_capability.supported_format.frame_size = { 640, 480 };
        //best_match_video_capability.supported_format.pixel_format = PIXEL_FORMAT_NV12;
        return E_FAIL;
    }
    else {
        const CapabilityWin out_best_match_video_capability = 
            GetBestMatchedCapability(requested_format, video_capabilities);
        best_match_video_capability = out_best_match_video_capability;
    }

    ComPtr<IMFMediaType> source_video_media_type;
    DX::ThrowIfFailed(capture_source->GetAvailableDeviceMediaType(
        best_match_video_capability.stream_index,
        best_match_video_capability.media_type_index,
        &source_video_media_type));

    DX::ThrowIfFailed(capture_source->SetCurrentDeviceMediaType(
        best_match_video_capability.stream_index, source_video_media_type.Get()));

    ComPtr<IMFCaptureSink> capture_sink;
    DX::ThrowIfFailed(mf_engine_->GetSink(MF_CAPTURE_ENGINE_SINK_TYPE_PREVIEW, &capture_sink));

    ComPtr<IMFCapturePreviewSink> preview_sink;
    DX::ThrowIfFailed(capture_sink->QueryInterface(IID_PPV_ARGS(&preview_sink)));

    DX::ThrowIfFailed(preview_sink->RemoveAllStreams());

    ComPtr<IMFMediaType> sink_video_media_type;
    DX::ThrowIfFailed(MFCreateMediaType(&sink_video_media_type));

    DX::ThrowIfFailed(ConvertToVideoSinkMediaType(
        source_video_media_type.Get(),
        true, // /*use_hardware_format=*/static_cast<bool>(mf_dxgi_device_manager_),
        sink_video_media_type.Get()));

    DWORD dw_sink_stream_index = 0;
    DX::ThrowIfFailed(preview_sink->AddStream(best_match_video_capability.stream_index,
        sink_video_media_type.Get(), nullptr,
        &dw_sink_stream_index));

    DX::ThrowIfFailed(preview_sink->SetSampleCallback(dw_sink_stream_index, video_callback_.Get()));

    // Note, that it is not sufficient to wait for
    // MF_CAPTURE_ENGINE_PREVIEW_STARTED as an indicator that starting capture has
    // succeeded. If the capture device is already in use by a different
    // application, MediaFoundation will still emit
    // MF_CAPTURE_ENGINE_PREVIEW_STARTED, and only after that raise an error
    // event. For the lack of any other events indicating success, we have to wait
    // for the first video frame to arrive before sending our |OnStarted| event to
    // |client_|.
    has_sent_on_started_to_client_ = false;
    DX::ThrowIfFailed(mf_engine_->StartPreview());

    selected_video_capability_ = std::make_unique<CapabilityWin>(best_match_video_capability);

    is_started_ = true;
    return S_OK;
}

void MFCaptureManager::DeallocateAndStop() {
    if (mf_engine_ && is_started_) {
        mf_engine_->StopPreview();
        is_started_ = false;
    }
}

void MFCaptureManager::CreateSwapChain() {
    // Step 3: Create the swap chain
    ComPtr<IDXGIDevice> dxgiDevice;
    d3d_device_.As(&dxgiDevice);

    dxgiDevice->GetParent(IID_PPV_ARGS(&dxgi_adapter_));

    ComPtr<IDXGIFactory2> dxgiFactory;
    dxgi_adapter_->GetParent(IID_PPV_ARGS(&dxgiFactory));

    DXGI_SWAP_CHAIN_FULLSCREEN_DESC fullScreenDesc;
    ZeroMemory(&fullScreenDesc, sizeof(fullScreenDesc));
    fullScreenDesc.RefreshRate.Numerator = 30;
    fullScreenDesc.RefreshRate.Denominator = 1;
    fullScreenDesc.Windowed = true;

    DXGI_SWAP_CHAIN_DESC1 SwapChainDesc = {};
    // SwapChainDesc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
    SwapChainDesc.Width = window_width_;
    SwapChainDesc.Height = window_height_;
    SwapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; //DXGI_FORMAT_B8G8R8A8_UNORM
    SwapChainDesc.BufferUsage = DXGI_USAGE_BACK_BUFFER | DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferCount = 2;
    SwapChainDesc.SampleDesc.Count = 1;
    SwapChainDesc.SampleDesc.Quality = 0;

    // //  DXGI_SCALING_ASPECT_RATIO_STRETCH value cause failure of CreateSwapChainForHwnd.
    SwapChainDesc.Scaling = DXGI_SCALING_NONE;
    SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; //  DXGI_SWAP_EFFECT_FLIP_DISCARD;
    SwapChainDesc.Stereo = false;
    SwapChainDesc.Flags = D3D11_RESOURCE_MISC_SHARED; //  (m_options & c_AllowTearing) ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0u;
                             // Create a swap chain for the window.

    ComPtr<IDXGISwapChain1> swapChain;
    dxgiFactory->CreateSwapChainForHwnd(d3d_device_.Get(),
        hwnd_, &SwapChainDesc, &fullScreenDesc, nullptr, &swapChain);
    swapChain.As(&swapChain_);
}

void MFCaptureManager::CreateDeviceForWindow() {

}

HRESULT MFCaptureManager::CreateDeviceSourceMediaFoundation() {

    ComPtr<IMFAttributes> attributes;
    const auto& attributes_data = { MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID };

    //true // capture_api == VideoCaptureApi::WIN_MEDIA_FOUNDATION
    //? GetMFAttributes()[0].second
    //: GetMFAttributes()[1].second;
// We allocate attributes_data.size() + 1 (+1 is for sym_link below) elements
// in attributes store.

// PrepareVideoCaptureAttributesMediaFoundation
    {
        DX::ThrowIfFailed(MFCreateAttributes(&attributes, 2));
        DX::ThrowIfFailed(attributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID));
    }

    IMFActivate** devices;
    UINT32 count;
    DX::ThrowIfFailed(EnumerateDeviceSourcesMediaFoundation(attributes, &devices, &count));
    for (UINT32 i = 0; i < count; ++i) {
        wchar_t* name;
        UINT32 name_size;
        HRESULT hr = devices[i]->GetAllocatedString(
            MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME, &name, &name_size);
        if (SUCCEEDED(hr)) {
            wchar_t* id;
            UINT32 id_size;
            hr = devices[i]->GetAllocatedString(
                MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK, &id,
                &id_size);
            if (SUCCEEDED(hr)) {
                mf_device_id = id;
                const std::wstring model_id = GetDeviceModelId(mf_device_id);

                const std::wstring display_name = name;
                //if (IsDeviceBlockedForMediaFoundationByModelId(model_id) ||
                //    IsDeviceBlockedForMediaFoundationByDisplayName(display_name)) {
                //    continue;
                //}

                if (!mf_device_id.empty()) {
                    attributes->SetString(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK, mf_device_id.c_str());

                    DX::ThrowIfFailed(MFCreateDeviceSource(attributes.Get(), &mf_source_));

                    ////   DXGIManager::RegisterWithMediaSource
                    Microsoft::WRL::ComPtr<IMFMediaSourceEx> source_ext;
                    DX::ThrowIfFailed(mf_source_.As(&source_ext));
                    DX::ThrowIfFailed(source_ext->SetD3DManager(mf_dxgi_device_manager_.Get()));

                    ////VideoCaptureControlSupport control_support;
                    ////VideoCaptureFormats supported_formats;
                    //if (CreateDeviceSourceMediaFoundation(
                    //    device_id, api_attributes.first, &source) ==
                    //    MFSourceOutcome::kSuccess) {
                    //    //control_support =
                    //    //    VideoCaptureDeviceMFWin::GetControlSupport(source);
                    //    //supported_formats =
                    //    //    GetSupportedFormatsMediaFoundation(source, display_name);
                    //}
                    //devices_info.emplace_back(VideoCaptureDeviceDescriptor(
                    //    display_name, device_id, model_id, api_attributes.first,
                    //    control_support));
                    //devices_info.back().supported_formats =
                    //    std::move(supported_formats);
                }
            }
        }
        devices[i]->Release();
    }

    return S_OK;
}

std::wstring MFCaptureManager::GetDeviceModelId(const std::wstring& device_id) {
    const wchar_t kVidPrefix[] = L"vid_";  // Also contains '\0'.
    const wchar_t kPidPrefix[] = L"pid_";  // Also contains '\0'.
    const size_t kVidPidSize = 4;

    const size_t vid_prefix_size = sizeof(kVidPrefix) - 1;
    const size_t pid_prefix_size = sizeof(kPidPrefix) - 1;
    const size_t vid_location = device_id.find(kVidPrefix);
    if (vid_location == std::wstring::npos ||
        vid_location + vid_prefix_size + kVidPidSize > device_id.size()) {
        return std::wstring();
    }
    const size_t pid_location = device_id.find(kPidPrefix);
    if (pid_location == std::wstring::npos ||
        pid_location + pid_prefix_size + kVidPidSize > device_id.size()) {
        return std::wstring();
    }
    const std::wstring id_vendor =
        device_id.substr(vid_location + vid_prefix_size, kVidPidSize);
    const std::wstring id_product =
        device_id.substr(pid_location + pid_prefix_size, kVidPidSize);
    return id_vendor + L":" + id_product;
}

HRESULT MFCaptureManager::EnumerateDeviceSourcesMediaFoundation(ComPtr<IMFAttributes> attributes, IMFActivate*** devices, UINT32* count) {
    MFEnumDeviceSources(attributes.Get(), devices, count);
    return S_OK;
}

HRESULT MFCaptureManager::WaitOnCaptureEvent(GUID capture_event_guid) {
    HRESULT hr = S_OK;
    capture_error_ = CreateEvent(nullptr, FALSE, TRUE, nullptr);
    capture_initialize_ = CreateEvent(nullptr, FALSE, TRUE, nullptr);

    video_callback_->SetCaptureErrorEvent(capture_error_, capture_initialize_);

    HANDLE events[] = { nullptr, capture_error_ };

    // TODO(http://crbug.com/1093521): Add cases for Start
    // MF_CAPTURE_ENGINE_PREVIEW_STARTED and MF_CAPTURE_ENGINE_PREVIEW_STOPPED
    if (capture_event_guid == MF_CAPTURE_ENGINE_INITIALIZED) {
        events[0] = capture_initialize_;
    }
    else {
        // no registered event handle for the event requested
        hr = E_NOTIMPL;
        return hr;
    }

    DWORD wait_result = ::WaitForMultipleObjects(2, events, FALSE, INFINITE);
    switch (wait_result) {
    case WAIT_OBJECT_0:
        break;
    case WAIT_FAILED:
        hr = HRESULT_FROM_WIN32(::GetLastError());
        break;
    default:
        hr = E_UNEXPECTED;
        break;
    }
    return hr;
}

HRESULT MFCaptureManager::ConvertToVideoSinkMediaType(IMFMediaType* source_media_type,
    bool use_hardware_format,
    IMFMediaType* sink_media_type) {
    HRESULT hr = sink_media_type->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    if (FAILED(hr))
        return hr;

    bool passthrough = false;
    GUID mf_sink_media_subtype;
    hr = GetMFSinkMediaSubtype(source_media_type, use_hardware_format,
        &mf_sink_media_subtype, &passthrough);
    if (FAILED(hr))
        return hr;

    hr = sink_media_type->SetGUID(MF_MT_SUBTYPE, mf_sink_media_subtype);
    // Copying attribute values for passthrough mode is redundant, since the
    // format is kept unchanged, and causes AddStream error MF_E_INVALIDMEDIATYPE.
    if (FAILED(hr) || passthrough)
        return hr;

    hr = CopyAttribute(source_media_type, sink_media_type, MF_MT_FRAME_SIZE);
    if (FAILED(hr))
        return hr;

    hr = CopyAttribute(source_media_type, sink_media_type, MF_MT_FRAME_RATE);
    if (FAILED(hr))
        return hr;

    hr = CopyAttribute(source_media_type, sink_media_type,
        MF_MT_PIXEL_ASPECT_RATIO);
    if (FAILED(hr))
        return hr;

    return CopyAttribute(source_media_type, sink_media_type,
        MF_MT_INTERLACE_MODE);
}

HRESULT MFCaptureManager::CopyAttribute(IMFAttributes* source_attributes,
    IMFAttributes* destination_attributes,
    const GUID& key) {
    PROPVARIANT var;
    PropVariantInit(&var);
    HRESULT hr = source_attributes->GetItem(key, &var);
    if (FAILED(hr))
        return hr;

    hr = destination_attributes->SetItem(key, var);
    PropVariantClear(&var);
    return hr;
}

HRESULT MFCaptureManager::GetMFSinkMediaSubtype(IMFMediaType* source_media_type,
    bool use_hardware_format,
    GUID* mf_sink_media_subtype,
    bool* passthrough) {
    GUID source_subtype;
    HRESULT hr = source_media_type->GetGUID(MF_MT_SUBTYPE, &source_subtype);
    if (FAILED(hr))
        return hr;
    MediaFormatConfiguration media_format_configuration;
    if (!GetMediaFormatConfigurationFromMFSourceMediaSubtype(
        source_subtype, use_hardware_format, &media_format_configuration))
        return E_FAIL;
    *mf_sink_media_subtype = media_format_configuration.mf_sink_media_subtype;
    *passthrough =
        (media_format_configuration.mf_sink_media_subtype == source_subtype);
    return S_OK;
}

bool MFCaptureManager::GetMediaFormatConfigurationFromMFSourceMediaSubtype(
    const GUID& mf_source_media_subtype,
    bool use_hardware_format,
    MediaFormatConfiguration* media_format_configuration) {
    static const MediaFormatConfiguration kMediaFormatConfigurationMap[] = {
        // IMFCaptureEngine inevitably performs the video frame decoding itself.
        // This means that the sink must always be set to an uncompressed video
        // format.

        // Since chromium uses I420 at the other end of the pipe, MF known video
        // output formats are always set to I420.
        {false, MFVideoFormat_I420, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_YUY2, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_UYVY, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_RGB24, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_RGB32, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_ARGB32, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_MJPG, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_NV12, MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {false, MFVideoFormat_YV12, MFVideoFormat_I420, PIXEL_FORMAT_I420},

        // Depth cameras use 16-bit uncompressed video formats.
        // We ask IMFCaptureEngine to let the frame pass through, without
        // transcoding, since transcoding would lead to precision loss.
        {false, kMediaSubTypeY16, kMediaSubTypeY16, PIXEL_FORMAT_Y16},
        {false, kMediaSubTypeZ16, kMediaSubTypeZ16, PIXEL_FORMAT_Y16},
        {false, kMediaSubTypeINVZ, kMediaSubTypeINVZ, PIXEL_FORMAT_Y16},
        {false, MFVideoFormat_D16, MFVideoFormat_D16, PIXEL_FORMAT_Y16},

        // Photo type
        {false, GUID_ContainerFormatJpeg, GUID_ContainerFormatJpeg,
            PIXEL_FORMAT_MJPEG},

            // For hardware path we always convert to NV12, since it's the only
            // supported by GMBs format.
            {true, MFVideoFormat_I420, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_YUY2, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_UYVY, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_RGB24, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_RGB32, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_ARGB32, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_MJPG, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_NV12, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
            {true, MFVideoFormat_YV12, MFVideoFormat_NV12, PIXEL_FORMAT_NV12},

            // 16-bit formats can't be converted without loss of precision,
            // so if leave an option to get Y16 pixel format even though the
            // HW path won't be used for it.
            {true, kMediaSubTypeY16, kMediaSubTypeY16, PIXEL_FORMAT_Y16},
            {true, kMediaSubTypeZ16, kMediaSubTypeZ16, PIXEL_FORMAT_Y16},
            {true, kMediaSubTypeINVZ, kMediaSubTypeINVZ, PIXEL_FORMAT_Y16},
            {true, MFVideoFormat_D16, MFVideoFormat_D16, PIXEL_FORMAT_Y16},

            // Photo type
            {true, GUID_ContainerFormatJpeg, GUID_ContainerFormatJpeg,
            PIXEL_FORMAT_MJPEG} };

    for (const auto& kMediaFormatConfiguration : kMediaFormatConfigurationMap) {
        if (kMediaFormatConfiguration.is_hardware_format == use_hardware_format &&
            kMediaFormatConfiguration.mf_source_media_subtype ==
            mf_source_media_subtype) {
            *media_format_configuration = kMediaFormatConfiguration;
            return true;
        }
    }

    return false;
}

HRESULT MFCaptureManager::FillCapabilities(IMFCaptureSource* capture_source, bool photo, std::list<CapabilityWin>* capabilities) {

    DWORD stream_count = 0;
    capture_source->GetDeviceStreamCount(&stream_count);

    for (DWORD stream_index = 0; stream_index < stream_count; stream_index++) {
        MF_CAPTURE_ENGINE_STREAM_CATEGORY stream_category;
        DX::ThrowIfFailed(capture_source->GetDeviceStreamCategory(stream_index, &stream_category));

        if ((photo && stream_category !=
            MF_CAPTURE_ENGINE_STREAM_CATEGORY_PHOTO_INDEPENDENT) ||
            (!photo &&
                stream_category != MF_CAPTURE_ENGINE_STREAM_CATEGORY_VIDEO_PREVIEW &&
                stream_category != MF_CAPTURE_ENGINE_STREAM_CATEGORY_VIDEO_CAPTURE)) {
            continue;
        }

        DWORD media_type_index = 0;
        ComPtr<IMFMediaType> type;

        HRESULT hr;
        while (SUCCEEDED(hr = capture_source->GetAvailableDeviceMediaType(
            stream_index, media_type_index, &type))) {
            VideoCaptureFormat format;
            VideoPixelFormat source_pixel_format;
            if (GetFormatFromSourceMediaType(
                type.Get(), photo,
                /*use_hardware_format=*/!photo &&
                true, // static_cast<bool>(mf_dxgi_device_manager_),
                &format, &source_pixel_format))
                capabilities->emplace_back(media_type_index, format, stream_index,
                    source_pixel_format);
            type.Reset();
            ++media_type_index;
        }
        if (hr == MF_E_NO_MORE_TYPES) {
            hr = S_OK;
        }

        if (FAILED(hr)) {
            return hr;
        }
    }

    return S_OK;
}

bool MFCaptureManager::GetFormatFromSourceMediaType(IMFMediaType* source_media_type,
    bool photo,
    bool use_hardware_format,
    VideoCaptureFormat* format,
    VideoPixelFormat* source_pixel_format) {
    GUID major_type_guid;
    if (FAILED(source_media_type->GetGUID(MF_MT_MAJOR_TYPE, &major_type_guid)) ||
        (major_type_guid != MFMediaType_Image &&
            (photo ||
                !GetFrameRateFromMediaType(source_media_type, &format->frame_rate)))) {
        return false;
    }

    GUID sub_type_guid;
    if (FAILED(source_media_type->GetGUID(MF_MT_SUBTYPE, &sub_type_guid)) ||
        !GetFrameSizeFromMediaType(source_media_type, &format->frame_size) ||
        !GetPixelFormatFromMFSourceMediaSubtype(
            sub_type_guid, use_hardware_format, &format->pixel_format)) {
        return false;
    }

    *source_pixel_format = MfSubTypeToSourcePixelFormat(sub_type_guid);
    return true;
}

VideoPixelFormat MFCaptureManager::MfSubTypeToSourcePixelFormat(
    const GUID& mf_source_media_subtype) {
    static const PixelFormatMap kPixelFormatMap[] = {

        {MFVideoFormat_I420, PIXEL_FORMAT_I420},
        {MFVideoFormat_YUY2, PIXEL_FORMAT_YUY2},
        {MFVideoFormat_UYVY, PIXEL_FORMAT_UYVY},
        {MFVideoFormat_RGB24, PIXEL_FORMAT_RGB24},
        {MFVideoFormat_RGB32, PIXEL_FORMAT_XRGB},
        {MFVideoFormat_ARGB32, PIXEL_FORMAT_ARGB},
        {MFVideoFormat_MJPG, PIXEL_FORMAT_MJPEG},
        {MFVideoFormat_NV12, PIXEL_FORMAT_NV12},
        {MFVideoFormat_YV12, PIXEL_FORMAT_YV12},
        {GUID_ContainerFormatJpeg, PIXEL_FORMAT_MJPEG} };

    for (const auto& kEntry : kPixelFormatMap) {
        if (kEntry.mf_source_media_subtype == mf_source_media_subtype) {
            return kEntry.pixel_format;
        }
    }
    return PIXEL_FORMAT_UNKNOWN;
}

bool MFCaptureManager::GetPixelFormatFromMFSourceMediaSubtype(
    const GUID& mf_source_media_subtype,
    bool use_hardware_format,
    VideoPixelFormat* pixel_format) {
    MediaFormatConfiguration media_format_configuration;
    if (!GetMediaFormatConfigurationFromMFSourceMediaSubtype(
        mf_source_media_subtype, use_hardware_format,
        &media_format_configuration))
        return false;

    *pixel_format = media_format_configuration.pixel_format;
    return true;
}

bool MFCaptureManager::GetFrameSizeFromMediaType(IMFMediaType* type, Capture_Size* frame_size) {
    UINT32 width32, height32;
    if (FAILED(MFGetAttributeSize(type, MF_MT_FRAME_SIZE, &width32, &height32)))
        return false;
    frame_size->width = width32;
    frame_size->height = height32;
    // frame_size->SetSize(width32, height32);
    return true;
}

bool MFCaptureManager::GetFrameRateFromMediaType(IMFMediaType* type, float* frame_rate) {
    UINT32 numerator, denominator;
    if (FAILED(MFGetAttributeRatio(type, MF_MT_FRAME_RATE, &numerator,
        &denominator)) ||
        !denominator) {
        return false;
    }
    *frame_rate = static_cast<float>(numerator) / denominator;
    return true;
}

const CapabilityWin& MFCaptureManager::GetBestMatchedCapability(
    const VideoCaptureFormat& requested,
    std::list<CapabilityWin>& capabilities) {

    const CapabilityWin* best_match = &(*capabilities.begin());
    for (const CapabilityWin& capability : capabilities) {
        if (CompareCapability(requested, capability, *best_match)) {
            best_match = &capability;
        }
    }
    return *best_match;
}

bool MFCaptureManager::CompareCapability(const VideoCaptureFormat& requested, const CapabilityWin& lhs, const CapabilityWin& rhs) {
    // When 16-bit format or NV12 is requested and available, avoid other formats.
    // If both lhs and rhs are 16-bit, we still need to compare them based on
    // height, width and frame rate.
    const bool use_requested =
        (requested.pixel_format == PIXEL_FORMAT_Y16) ||
        (requested.pixel_format == PIXEL_FORMAT_NV12);
    if (use_requested &&
        lhs.supported_format.pixel_format != rhs.supported_format.pixel_format) {
        if (lhs.supported_format.pixel_format == requested.pixel_format)
            return true;
        if (rhs.supported_format.pixel_format == requested.pixel_format)
            return false;
    }

    const int diff_height_lhs = std::abs(lhs.supported_format.frame_size.height - requested.frame_size.height);
    const int diff_height_rhs = std::abs(rhs.supported_format.frame_size.height - requested.frame_size.height);
    if (diff_height_lhs != diff_height_rhs)
        return diff_height_lhs < diff_height_rhs;

    const int diff_width_lhs = std::abs(lhs.supported_format.frame_size.width - requested.frame_size.width);
    const int diff_width_rhs = std::abs(rhs.supported_format.frame_size.width - requested.frame_size.width);
    if (diff_width_lhs != diff_width_rhs)
        return diff_width_lhs < diff_width_rhs;

    const float diff_fps_lhs = std::fabs(lhs.supported_format.frame_rate - requested.frame_rate);
    const float diff_fps_rhs = std::fabs(rhs.supported_format.frame_rate - requested.frame_rate);
    if (diff_fps_lhs != diff_fps_rhs)
        return diff_fps_lhs < diff_fps_rhs;

    // Compare by internal pixel format to avoid conversions when possible.
    if (lhs.source_pixel_format != rhs.source_pixel_format) {
        // Choose the format with no conversion if possible.
        if (lhs.source_pixel_format == requested.pixel_format)
            return true;
        if (rhs.source_pixel_format == requested.pixel_format)
            return false;
        // Prefer I420<->NV12 conversion over all.
        if ((lhs.source_pixel_format == PIXEL_FORMAT_NV12 &&
            requested.pixel_format == PIXEL_FORMAT_I420) ||
            (lhs.source_pixel_format == PIXEL_FORMAT_I420 &&
                requested.pixel_format == PIXEL_FORMAT_NV12)) {
            return true;
        }
        if ((rhs.source_pixel_format == PIXEL_FORMAT_NV12 &&
            requested.pixel_format == PIXEL_FORMAT_I420) ||
            (rhs.source_pixel_format == PIXEL_FORMAT_I420 &&
                requested.pixel_format == PIXEL_FORMAT_NV12)) {
            return false;
        }
        // YUY2<->NV12 is the next best.
        if ((lhs.source_pixel_format == PIXEL_FORMAT_NV12 &&
            requested.pixel_format == PIXEL_FORMAT_YUY2) ||
            (lhs.source_pixel_format == PIXEL_FORMAT_YUY2 &&
                requested.pixel_format == PIXEL_FORMAT_NV12)) {
            return true;
        }
        if ((rhs.source_pixel_format == PIXEL_FORMAT_NV12 &&
            requested.pixel_format == PIXEL_FORMAT_YUY2) ||
            (rhs.source_pixel_format == PIXEL_FORMAT_YUY2 &&
                requested.pixel_format == PIXEL_FORMAT_NV12)) {
            return false;
        }
    }

    return VideoCaptureFormat::ComparePixelFormatPreference(
        lhs.supported_format.pixel_format, rhs.supported_format.pixel_format);
}
HRESULT MFCaptureManager::RegisterWithMediaSource(
    Microsoft::WRL::ComPtr<IMFMediaSource> media_source) {
    Microsoft::WRL::ComPtr<IMFMediaSourceEx> source_ext;
    DX::ThrowIfFailed(media_source.As(&source_ext));
    DX::ThrowIfFailed(source_ext->SetD3DManager(mf_dxgi_device_manager_.Get()));
    return S_OK;
}

HRESULT MFCaptureManager::RegisterInCaptureEngineAttributes(
    IMFAttributes* attributes) {
    DX::ThrowIfFailed(attributes->SetUnknown(MF_CAPTURE_ENGINE_D3D_MANAGER,
        mf_dxgi_device_manager_.Get()));
    return S_OK;
}

HRESULT MFCaptureManager::CreateCaptureEngine(IMFCaptureEngine** engine) {
    ComPtr<IMFCaptureEngineClassFactory> capture_engine_class_factory;
    HRESULT hr = CoCreateInstance(CLSID_MFCaptureEngineClassFactory, nullptr,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&capture_engine_class_factory));

    return capture_engine_class_factory->CreateInstance(CLSID_MFCaptureEngine,
        IID_PPV_ARGS(engine));
}
