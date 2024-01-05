#pragma once

#include "common.h"

#include <map>
#include <memory>

class DrawRBGManager;
class HostTextureStream {
public:
    HostTextureStream(
        const wchar_t* stream_id,
        ID3D11Device* d3d_device,
        ICoreWebView2ExperimentalEnvironment12* webview2_environment,
        HWND window_handle);
    ~HostTextureStream();
    HRESULT SendTexture(int buffer_resource_id, ULONGLONG timestamp);
    HRESULT GetAvailableBuffer();
    HRESULT CreateNewBuffer(uint32_t width, uint32_t height);

private:
    void RegisterTextureStreamEvent();

private:
    Microsoft::WRL::ComPtr<ICoreWebView2ExperimentalTextureStream> texture_stream_;
    Microsoft::WRL::ComPtr<ID3D11Device> d3d_device_;
    HWND window_handle_ = nullptr;
    HWND web_texture_window_handle_ = nullptr;
    DWORD thread_id_ = 0;
    std::unique_ptr<DrawRBGManager> draw_rgb_manager_;
    std::map<int, Microsoft::WRL::ComPtr<ICoreWebView2ExperimentalTexture>> buffer_resource_id_to_texture_buffer_;
    bool posted_window_visible_ = false;
    uint32_t width_;
    uint32_t height_;
};
