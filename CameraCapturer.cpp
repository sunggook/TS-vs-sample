#include "CameraCapturer.h"

#include "MfCaptureManager.h"

// static 
CameraCapturer* CameraCapturer::GetInstance() {
    static std::unique_ptr<CameraCapturer> instance = nullptr;
    if (!instance) {
        instance = std::make_unique< CameraCapturer>();
    }
    return instance.get();
}

CameraCapturer::CameraCapturer() {
}

CameraCapturer::~CameraCapturer() {
    StopMediaFoundationCapture();
}

void CameraCapturer::CreateD3DDeviceAndMFCamera(HWND window_handle, LUID browser_luid) {
    // Create D3D device with browser_luid
    DX::ThrowIfFailed(InitializeRenderCameraView(window_handle, browser_luid));

    browser_adapter_luid_ = browser_luid;
}

HRESULT CameraCapturer::InitializeRenderCameraView(HWND window_handle, LUID luid) {
    if (mf_capture_manager_)
        return S_OK;

    mf_capture_manager_ = std::make_unique<MFCaptureManager>(window_handle);
    DX::ThrowIfFailed(mf_capture_manager_->CreateMFDevice(luid, &d3d_device_));
    DX::ThrowIfFailed(mf_capture_manager_->InitMF());

    d3d_device_->GetImmediateContext(&device_context_);
    return S_OK;
}

HRESULT CameraCapturer::StartMediaFoundationCapture(HWND window_handle) {
    if (!mf_capture_manager_) {
        return HRESULT_FROM_WIN32(ERROR_INVALID_STATE);
    }

    // Draw camera or edited image to the window_handle.
    if (use_swap_chain_buffer_) {
        mf_capture_manager_->CreateDeviceForWindow();
    }

    mf_capture_manager_->AllocateAndStartLocked();
    return S_OK;
}

void CameraCapturer::StopMediaFoundationCapture() {
    if (mf_capture_manager_) {
        mf_capture_manager_->DeallocateAndStop();
        mf_capture_manager_ = nullptr;
    }
}

LUID CameraCapturer::GetBrowserAdapterLuid() {
    return browser_adapter_luid_;
}

ID3D11Device* CameraCapturer::GetD3DDevice() {
    return d3d_device_.Get();
}

ID3D11DeviceContext* CameraCapturer::GetDeviceContext() {
    return device_context_.Get();
}
