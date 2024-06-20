#include "WebView2Manager.h"

#include "CameraCapturer.h"
#include "HostTextureStream.h"
#include "WebView2EnvironmentOptions.h"

using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Callback;
using Microsoft::WRL::Make;

// The machine does not have GPU.
bool g_warp_mode = false;

// The application renderer does not use GPU regardless of GPU availability.
bool g_disable_gpu_on_renderer = false;

// The application renderer does not use software rendering regardless of GPU disablement.
bool g_disable_software_renderer = false;

// Custom user directory. Any folder that WebView2 user data directory.
constexpr wchar_t kCustomUserDir[] = L"D:\\Temp\\UserData-1";

// WebView2 Beta.
// Please find out the private binary folder, for example if it is Edge (Beta/Dev/Canary), the location is 
// c:\program files (x86) or c:\users\{account}\AppData\Local\Microsoft or c:\Program Files (x86)\Microsoft.
// constexpr wchar_t kPrivateBinaryFolder[] = L"c:\\Program Files (x86)\\Microsoft\\Edge Beta\\Application\\121.0.2277.4";

// WebView2 Stable.
constexpr wchar_t kPrivateBinaryFolder[] = L"";

WebView2Manager::WebView2Manager(HWND hwnd) 
        : window_handle_(hwnd) {}
WebView2Manager::~WebView2Manager() = default;

HRESULT WebView2Manager::CreateCoreWebView2(const wchar_t* site_url) {
    site_url_ = site_url;

    auto options =
        Microsoft::WRL::Make<CoreWebView2EnvironmentOptions>();

    std::wstring arguments = L"--enable-features=msWebView2TextureStream";

    if (g_disable_gpu_on_renderer) {
        arguments += L"  --disable-gpu";
    }

    if (g_disable_software_renderer) {
        arguments += L"  --disable-features=msEdgeTextureStreamSoftwareRenderingWhenGpuDisabled";
    }

    options->put_AdditionalBrowserArguments(arguments.c_str());

    CreateCoreWebView2EnvironmentWithOptions(/*edge sub folder=*/kPrivateBinaryFolder, /*custom user directory=*/kCustomUserDir, options.Get(),
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [this](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
                webview_environment_ = env;
                DX::ThrowIfFailed(webview_environment_.As(&webview_environment12_));

                // Create a CoreWebView2Controller and get the associated CoreWebView2 whose parent is the main window window_handle_
                webview_environment_->CreateCoreWebView2Controller(window_handle_, Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                    [this](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {

                        webview_controller_ = controller;
                        webview_controller_->get_CoreWebView2(&webview2_);

                        // Add a few settings for the webview
                        // The demo step is redundant since the values are the default settings
                        ICoreWebView2Settings* webview2_settings;
                        webview2_->get_Settings(&webview2_settings);
                        webview2_settings->put_IsScriptEnabled(TRUE);
                        webview2_settings->put_AreDefaultScriptDialogsEnabled(TRUE);
                        webview2_settings->put_IsWebMessageEnabled(TRUE);

                        // Resize WebView to fit the bounds of the parent window
                        RECT bounds;
                        GetClientRect(window_handle_, &bounds);

                        RECT right_pane;
                        right_pane.left = bounds.left; // (bounds.right - bounds.left) / 2; //
                        right_pane.top = bounds.top;
                        right_pane.right = bounds.right; //  / 2;
                        right_pane.bottom = bounds.bottom;
                        webview_controller_->put_Bounds(right_pane);

                        webview2_->add_NavigationCompleted(
                            Microsoft::WRL::Callback<ICoreWebView2NavigationCompletedEventHandler>(
                                [this](
                                    ICoreWebView2* sender,
                                    ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
                                        InitializeDevice();
                                        return S_OK;
                                }).Get(), nullptr);

                        ListenToNewWebViewWindowRequest();

                        EventRegistrationToken token;
                        webview2_->add_WebMessageReceived(Callback<ICoreWebView2WebMessageReceivedEventHandler>(
                            [](ICoreWebView2* webview, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
                                // TODO: Do something with the message.
                                return S_OK;
                            }).Get(), &token);

                        webview2_->Navigate(site_url_.c_str());

                        ComPtr< ICoreWebView2_4> coreWebView2_4;
                        webview2_.As(&coreWebView2_4);

                        EventRegistrationToken frame_token;
                        coreWebView2_4->add_FrameCreated(
                            Callback<ICoreWebView2FrameCreatedEventHandler>(
                                [&](
                                    ICoreWebView2* sender, ICoreWebView2FrameCreatedEventArgs* args) -> HRESULT
                                {
                                    // ComPtr<ICoreWebView2Frame> webviewFrame;
                                    ComPtr<ICoreWebView2Frame> webview_frame;
                                    DX::ThrowIfFailed(args->get_Frame(&webview_frame));

                                    // TODO: Do something with the frame.
                                    return S_OK;
                                }).Get(), &frame_token);
                        return S_OK;
                    }).Get());
                return S_OK;
            }).Get());

    return S_OK;
}

HRESULT WebView2Manager::InitializeDevice() {
    // Get the LUDI of the browser/renderer.
    UINT64 browser_luid_value;
    webview_environment12_->get_RenderAdapterLUID(&browser_luid_value);

    EventRegistrationToken luid_token;
    webview_environment12_->add_RenderAdapterLUIDChanged(Callback<ICoreWebView2ExperimentalRenderAdapterLUIDChangedEventHandler>(
        [&, this](ICoreWebView2ExperimentalEnvironment12* sender, IUnknown*) {

            sender->get_RenderAdapterLUID(&browser_luid_value);

            // Update the D3D device again with the updated LUID.
            LUID browser_luid = {};
            browser_luid.LowPart = browser_luid_value & 0xFFFFFFFF;
            browser_luid.HighPart = (browser_luid_value >> 32) & 0xFFFFFFFF;

            CameraCapturer::GetInstance()->CreateD3DDeviceAndMFCamera(window_handle_, browser_luid, g_warp_mode);

            return S_OK;
        }).Get(), &luid_token);

    LUID browser_luid;
    browser_luid.LowPart = browser_luid_value & 0xFFFFFFFF;
    browser_luid.HighPart = (browser_luid_value >> 32) & 0xFFFFFFFF;
    CameraCapturer::GetInstance()->CreateD3DDeviceAndMFCamera(window_handle_, browser_luid, g_warp_mode);

    d3d_device_created_ = true;

    ::SendMessage(window_handle_, IDC_WEBVIEW2_NAVIGATION_COMPLETE, 0, 0);

    return S_OK;
}

ID3D11Device* WebView2Manager::GetD3DDevice() const {
    return CameraCapturer::GetInstance()->GetD3DDevice();
}

ICoreWebView2Controller* WebView2Manager::GetController() const {
    return webview_controller_.Get();
}

std::unique_ptr<HostTextureStream> WebView2Manager::CreateTextureStreamFromWebView2Window(const wchar_t* stream_id) {
    if (!d3d_device_created_) {
        return nullptr;
    }

    // Texture
    auto host_text_stream = std::make_unique<HostTextureStream>(stream_id,
        CameraCapturer::GetInstance()->GetD3DDevice(), webview_environment12_.Get(), window_handle_);

    return host_text_stream;
}

void WebView2Manager::ListenToNewWebViewWindowRequest() {
    webview2_->add_NewWindowRequested(Callback<ICoreWebView2NewWindowRequestedEventHandler>(
        [&](ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args) {
            ComPtr<ICoreWebView2Deferral> deferral;
            args->GetDeferral(&deferral);

            ComPtr<ICoreWebView2WindowFeatures> windowFeatures;
            args->get_WindowFeatures(&windowFeatures);

            UINT32 left = 0;
            UINT32 top = 0;
            UINT32 height = 0;
            UINT32 width = 0;
            BOOL shouldHaveToolbar = true;

            BOOL hasPosition = FALSE;
            BOOL hasSize = FALSE;
            windowFeatures->get_HasPosition(&hasPosition);
            windowFeatures->get_HasSize(&hasSize);

            if (!!hasPosition && !!hasSize)
            {
                windowFeatures->get_Left(&left);
                windowFeatures->get_Top(&top);
                windowFeatures->get_Height(&height);
                windowFeatures->get_Width(&width);
            }
            windowFeatures->get_ShouldDisplayToolbar(&shouldHaveToolbar);


            HWND second_webview2_window = CreateSubWindow(nullptr, SW_SHOW, L"OpenWindowClass", L"SecondWindow");

            webview_environment_->CreateCoreWebView2Controller(second_webview2_window,
                Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                    [second_webview2_window, args, deferral, this](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {
                        if (controller != nullptr) {
                            webview_controller_for_second_window_ = controller;
                            webview_controller_for_second_window_->get_CoreWebView2(&webview_2_second_window_);
                        }

                        // Add a few settings for the webview
                        // The demo step is redundant since the values are the default settings
                        ICoreWebView2Settings* webview2_settings;
                        webview_2_second_window_->get_Settings(&webview2_settings);
                        webview2_settings->put_IsScriptEnabled(TRUE);
                        webview2_settings->put_AreDefaultScriptDialogsEnabled(TRUE);
                        webview2_settings->put_IsWebMessageEnabled(TRUE);

                        // Resize WebView to fit the bounds of the parent window
                        RECT bounds = {};
                        ::GetClientRect(second_webview2_window, &bounds);

                        RECT right_pane2 = {};
                        right_pane2.left = bounds.left; // (bounds.right - bounds.left) / 2; //
                        right_pane2.top = bounds.top;
                        right_pane2.right = bounds.right; //  / 2;
                        right_pane2.bottom = bounds.bottom;

                        webview_controller_for_second_window_->put_Bounds(right_pane2);

                        webview_2_second_window_->add_NavigationCompleted(
                            Microsoft::WRL::Callback<ICoreWebView2NavigationCompletedEventHandler>(
                                [second_webview2_window](
                                    ICoreWebView2* sender,
                                    ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
                                        return S_OK;
                                })
                            .Get(), nullptr);

                        args->put_NewWindow(webview_2_second_window_.Get());
                        args->put_Handled(TRUE);

                        deferral->Complete();

                        // TODO: Navigate to an another page.
                        return S_OK;
                    }).Get());
            return S_OK;
        })
        .Get(), nullptr);
}
