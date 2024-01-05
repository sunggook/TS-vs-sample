#pragma once

#include "common.h"

#include <Mfcaptureengine.h>

#include <queue>
#include <vector>
#include <mutex>
#include <map>

class MFVideoCallback final
    : public IMFCaptureEngineOnSampleCallback,
    public IMFCaptureEngineOnEventCallback {
public:
    MFVideoCallback(HWND hWnd);
    void Init(ID3D11Device* d3d_device, IDXGISwapChain* swapChain);
    ~MFVideoCallback();

    IFACEMETHODIMP QueryInterface(REFIID riid, void** object) override;

    IFACEMETHODIMP_(ULONG) AddRef() override;

    IFACEMETHODIMP_(ULONG) Release() override;

    HRESULT SetCaptureErrorEvent(HANDLE capture_error, HANDLE capture_initialize);

    IFACEMETHODIMP OnEvent(IMFMediaEvent* media_event) override;

    IFACEMETHODIMP OnSample(IMFSample* sample) override;

private:
    HRESULT GetTextureFromMFBuffer(IMFMediaBuffer* mf_buffer, ID3D11Texture2D** texture_out);
    // HANDLE DeliverTextureToWebView2(ID3D11Texture2D* source_texture, ULONGLONG raw_time_stamp);
    void DeliverTextureToWebView2ByBuffer(ID3D11Texture2D* source_texture, ULONGLONG raw_time_stamp);
    HANDLE CreateNewBuffer(UINT width, UINT height, int& index);
    void NotifyToBrowser(bool addBuffer, HANDLE sharedHandle, int buffer_id);
    void EnsureMemoryMappedSection();
    void RequestToWebViewProcess(ID3D11Texture2D* source_texture, ULONGLONG raw_time_stamp);
    bool SendToWebViewProcess(bool buffer_create_request, bool avaialable_buffer_request, UINT32 width, UINT32 height, int buffer_id, ULONGLONG timestamp);
    bool WaitFromWebViewProcess(bool buffer_create_request, bool avaialable_buffer_request, int64_t& out_buffer_i);


    std::map<int64_t, Microsoft::WRL::ComPtr<ID3D11Texture2D>> buffer_id_to_texture_2ds_;
    Microsoft::WRL::ComPtr<ID3D11Device> d3d_device_;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> device_context_;
    std::mutex mutex_;
    UINT32 m_iRefCount;
    HANDLE capture_error_;
    HANDLE capture_initialize_;
    DWORD ui_thread_id_ = 0;
    HWND hwnd_ = nullptr;
    std::vector< Microsoft::WRL::ComPtr<ID3D11Texture2D>> buffer_textures_;
    std::queue<int> buffer_available_index_;
    std::vector<HANDLE> buffer_shared_handles_;
    volatile TextureBufferInfo* texture_buffer_info_on_slimcore_ = nullptr;
    HANDLE mapping_handle_;
    HANDLE from_webview_process_to_slimcore_ = INVALID_HANDLE_VALUE;
    HANDLE from_slimcore_to_webview_process_ = INVALID_HANDLE_VALUE;

    Microsoft::WRL::ComPtr<ID3D11Texture2D> shared_surface_;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> render_target_view_;
    Microsoft::WRL::ComPtr<ID3D11VertexShader> vertex_shader_;
    Microsoft::WRL::ComPtr<IDXGISwapChain> swap_chain_;
};
