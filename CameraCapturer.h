#pragma once
#include "common.h"

#include <memory>

class MFCaptureManager;

class CameraCapturer {
public:
    static CameraCapturer* GetInstance();
    CameraCapturer();
    ~CameraCapturer();

    void CreateD3DDeviceAndMFCamera(HWND window_handle, LUID browser_luid, bool warp_mode);
    HRESULT InitializeRenderCameraView(HWND window_handle, LUID luid, bool warp_mode);
    HRESULT StartMediaFoundationCapture(HWND window_handle);
    void StopMediaFoundationCapture();
    LUID GetBrowserAdapterLuid();
    ID3D11Device* GetD3DDevice();
    ID3D11DeviceContext* GetDeviceContext();
private:
    LUID browser_adapter_luid_;
    Microsoft::WRL::ComPtr<ID3D11Device> d3d_device_;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> device_context_;
    // Pointer to WebView window
    std::unique_ptr<MFCaptureManager> mf_capture_manager_;
    bool use_swap_chain_buffer_ = true;
};
