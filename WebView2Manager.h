#pragma once

#include "common.h"

#include <memory>

class HostTextureStream;
class WebView2Manager {
public:
    WebView2Manager(HWND hwnd, bool warp_mode, bool software_rendering);
    ~WebView2Manager();

    HRESULT CreateCoreWebView2(const wchar_t* site_url);
    HRESULT InitializeDevice();
    ID3D11Device* GetD3DDevice() const;
    ICoreWebView2Controller* GetController() const;

    std::unique_ptr<HostTextureStream> CreateTextureStreamFromWebView2Window(const wchar_t* stream_id);

private:
    void ListenToNewWebViewWindowRequest();

    HWND window_handle_ = nullptr;
    bool warp_mode_ = false;
    bool software_rendering_ = false;
    bool initialized_ = false;
    bool d3d_device_created_ = false;
    std::wstring site_url_;

    Microsoft::WRL::ComPtr<ICoreWebView2Environment> webview_environment_;
    Microsoft::WRL::ComPtr<ICoreWebView2ExperimentalEnvironment12> webview_environment12_;
    Microsoft::WRL::ComPtr<ICoreWebView2> webview2_;
    Microsoft::WRL::ComPtr<ICoreWebView2Controller> webview_controller_;
    Microsoft::WRL::ComPtr<ICoreWebView2Controller> webview_controller_for_second_window_;
    Microsoft::WRL::ComPtr<ICoreWebView2> webview_2_second_window_;    
};