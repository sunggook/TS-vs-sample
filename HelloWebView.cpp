#include "common.h"

#include <intsafe.h>
#include <memory>
#include <vector>

#include "resource.h"
#include "CameraCapturer.h"
#include "DrawRBGManager.h"
#include "HostTextureStream.h"
#include "WebView2Manager.h"

using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Callback;

namespace {
    // Global variables
    bool g_warp_mode = false;

    // PostTextureStream variables
    HWND main_window_handle_ = nullptr;

    // chrome.webview.getTextureStream API sample.
    constexpr wchar_t kSampleSite[] = L"https://sunggook.github.io/get-ts/";

    // chrome.webview.registerTextureStream API sample.
    // constexpr wchar_t kSampleSite[] = L"https://sunggook.github.io/register-ts";

    // The main window class name.
    constexpr wchar_t kWindowClassName[] = L"DesktopApp";

    // The string that appears in the application's title bar.
    constexpr wchar_t kWindowTitle[] = L"WebView2 TextureStream API sample";

    std::unique_ptr<WebView2Manager> webview2_window_;
    std::unique_ptr<HostTextureStream> host_texture_stream_;

    struct BufferData {
        HANDLE sharedHandle;
        int buffer_id;
    };

    static volatile TextureBufferInfo* mapped_texture_info_ = nullptr;
    static HANDLE frog_webviewWindow_process_to_slimcore = nullptr;
    static HANDLE from_slimcore_to_webview_process = nullptr;
}

void EnsureMemoryMappedSection() {
if (!mapped_texture_info_) {
    HANDLE mapping_handle =
    ::CreateFileMapping(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0,
        sizeof(TextureBufferInfo), L"Local\\webview2-abcd1234");

    mapped_texture_info_ = reinterpret_cast<TextureBufferInfo*>(
    ::MapViewOfFile(mapping_handle, FILE_MAP_ALL_ACCESS, 0, 0,
        sizeof(TextureBufferInfo)));
}

if (!frog_webviewWindow_process_to_slimcore) {
    from_slimcore_to_webview_process = CreateEvent(nullptr, FALSE, FALSE, L"Local\\RequestFromSlimCore1");
}
}

void SendToSlimCore(bool createdBufer, HANDLE source_handle, UINT64 buffer_id) {
EnsureMemoryMappedSection();

mapped_texture_info_->command = SharedBufferCommand::ResponseBufferAvailableRequest;
mapped_texture_info_->buffer_id = buffer_id;
if (source_handle) {
    mapped_texture_info_->command = SharedBufferCommand::ResponseBufferCreated;

    HANDLE slim_core_handle;
    ::DuplicateHandle(GetCurrentProcess(), source_handle, GetCurrentProcess(), &slim_core_handle, 0, FALSE, DUPLICATE_SAME_ACCESS);

    mapped_texture_info_->handle = static_cast<uint32_t>(reinterpret_cast<intptr_t>(slim_core_handle));
}

// Notify SlimCore process of buffer available whether it is newly created or just already used one.
if (!frog_webviewWindow_process_to_slimcore) {
    // Opened event can change state, not waiting and it needs to be called after its creation on the SlimCore.
    frog_webviewWindow_process_to_slimcore = OpenEvent(EVENT_MODIFY_STATE, FALSE, L"Local\\SendToSimCore");
}
// FlushViewOfFile((PVOID)mapped_texture_info_, sizeof(*mapped_texture_info_));
::SetEvent(frog_webviewWindow_process_to_slimcore);
}

void SendToSlimCoreWithResource(bool createdBufer, IUnknown* resource, UINT64 buffer_id) {
EnsureMemoryMappedSection();

HANDLE source_handle = nullptr;

if (resource) {
    ComPtr<IDXGIResource1> dxgi_resource;
    HRESULT hr = resource->QueryInterface(IID_PPV_ARGS(&dxgi_resource));
    assert(SUCCEEDED(hr));

    hr = dxgi_resource->CreateSharedHandle(
    nullptr, DXGI_SHARED_RESOURCE_READ | DXGI_SHARED_RESOURCE_WRITE, nullptr,
    &source_handle);
    assert(SUCCEEDED(hr));
}

mapped_texture_info_->command = SharedBufferCommand::ResponseBufferAvailableRequest;
mapped_texture_info_->buffer_id = buffer_id;
if (source_handle) {
    mapped_texture_info_->command = SharedBufferCommand::ResponseBufferCreated;

    HANDLE slim_core_handle;
    ::DuplicateHandle(GetCurrentProcess(), source_handle, GetCurrentProcess(), &slim_core_handle, 0, FALSE, DUPLICATE_SAME_ACCESS);

    mapped_texture_info_->handle = static_cast<uint32_t>(reinterpret_cast<intptr_t>(slim_core_handle));
}

// Notify SlimCore process of buffer available whether it is newly created or just already used one.
if (!frog_webviewWindow_process_to_slimcore) {
    // Opened event can change state, not waiting and it needs to be called after its creation on the SlimCore.
    frog_webviewWindow_process_to_slimcore = OpenEvent(EVENT_MODIFY_STATE, FALSE, L"Local\\SendToSimCore");
}
// FlushViewOfFile((PVOID)mapped_texture_info_, sizeof(*mapped_texture_info_));
::SetEvent(frog_webviewWindow_process_to_slimcore);
}

DWORD ThreadProcForStreamId(PVOID param) {
// Wait request from the SlimCore.
HWND window_handle = reinterpret_cast<HWND>(param);

EnsureMemoryMappedSection();
HRESULT hr = S_OK;
int buffer_resource_id = -1; // -1 is regardes as failed operation of the API so the SlimCore will request new buffer after this.

while (true) {
    // Wait 20s and terminate if no message from SlimCore.
    constexpr int kMaxIPCMessageTimeout = 20 * 100000;  // 200s.
    DWORD result = WaitForSingleObject(from_slimcore_to_webview_process, kMaxIPCMessageTimeout);

    ComPtr<ICoreWebView2ExperimentalTexture> texture_buffer;
    std::map<int, ComPtr<ICoreWebView2ExperimentalTexture>>::const_iterator it;
    if (result == WAIT_OBJECT_0) {
    switch (mapped_texture_info_->command) {
    case SharedBufferCommand::RequestCreateNewBuffer:
        SendMessage(window_handle, IDC_TEST_CREATE_NEW_BUFFER, mapped_texture_info_->width, mapped_texture_info_->height);
        break;
    case SharedBufferCommand::RequestBuffer:
        SendMessage(window_handle, IDC_TEST_REQUEST_BUFFER, 0, 0);
        break;
    case SharedBufferCommand::RequestSetBuferAndPresent:
        // Sets ICoreWebView2ExperimentalTexture on any thread, but Present shoud be in UI thrad.
        SendMessage(window_handle, IDC_TEST_SEND_TEXTURE, mapped_texture_info_->buffer_id, mapped_texture_info_->timestamp);
        break;

    default:
        break;
    }
    }
    else {
    // Terminate thread for any other result other than valie one.
    break;
    }
}

return 0;
}

LRESULT CALLBACK WndProc(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param) {

    RECT right_pane = {};
    RECT bounds = {};
    switch (message)
    {
    case WM_SIZE:

        GetClientRect(window_handle, &bounds);
        if (webview2_window_ && webview2_window_->GetController()) {
            right_pane.left = (bounds.right - bounds.left);
            right_pane.top = bounds.top;
            right_pane.right = bounds.right / 2;
            right_pane.bottom = bounds.bottom;
            webview2_window_->GetController()->put_Bounds(right_pane);
        };
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SHOWWINDOW:
        break;
    case WM_TIMER:
        break;

    case IDC_TEST_SEND_TEXTURE:
        if (host_texture_stream_) {
            host_texture_stream_->SendTexture((int)w_param, mapped_texture_info_->timestamp);
        }
        break;

    case IDC_TEST_REQUEST_BUFFER:
        if (host_texture_stream_) {
            host_texture_stream_->GetAvailableBuffer();
        }
        break;

    case IDC_TEST_CREATE_NEW_BUFFER:
        if (host_texture_stream_) {
            host_texture_stream_->CreateNewBuffer((UINT32)w_param, (UINT32)l_param);
        }
        break;

    case IDC_WEBVIEW2_NAVIGATION_COMPLETE:
        // navigation completed, so we can create CreateTextureStream now.

        // We will create 2 texture stream with different names.
        host_texture_stream_ = webview2_window_->CreateTextureStreamFromWebView2Window(L"webview2-abcd1234");
        assert(host_texture_stream_);
        break;

    default:
        return DefWindowProc(window_handle, message, w_param, l_param);
        break;
    }

    return 0;
}

LRESULT CALLBACK WndChildProc(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param) {
    return DefWindowProc(window_handle, message, w_param, l_param);
}

int CALLBACK WinMain(
  _In_ HINSTANCE instance,
  _In_ HINSTANCE hPrevInstance,
  _In_ LPSTR     lpCmdLine,
  _In_ int       cmd_show
)
{
  if (!webview2_window_) {
    HWND window_handle = CreateSubWindow(instance, cmd_show, kWindowClassName, kWindowTitle);
    main_window_handle_ = window_handle;

    webview2_window_ = std::make_unique<WebView2Manager>(window_handle, g_warp_mode);

    // It is a simplied WebView2 creation with single site.
    // Once navigation done in the WebView2, it will send a message
    // to the WinpProc.
    DX::ThrowIfFailed(webview2_window_->CreateCoreWebView2(kSampleSite));
  }

  // Main message loop:
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return (int)msg.wParam;
}

HWND CreateSubWindow(HINSTANCE instance, int cmd_show, PCWSTR class_name, PCWSTR window_title) {

  bool bMainWindow = (kWindowClassName == class_name);

  WNDCLASSEX wcex = {};
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = bMainWindow ? (CS_HREDRAW | CS_VREDRAW) : 0; //  (WS_CHILD); //  | WS_BORDER);
  wcex.lpfnWndProc = bMainWindow ? WndProc : WndChildProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = instance;
  wcex.hIcon = LoadIcon(instance, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = nullptr;
  wcex.lpszClassName = class_name;
  wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

  if (!RegisterClassEx(&wcex))
  {
    return nullptr;
  }

  // sunggch. g_hInstance = instance;

  HWND window_handle = CreateWindow(
    class_name,
    window_title,
    bMainWindow ? WS_OVERLAPPEDWINDOW : WS_OVERLAPPED,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    1200, 900,
    bMainWindow ? NULL : main_window_handle_,
    NULL,
    instance,
    NULL
  );

  if (!window_handle)
  {
    return nullptr;
  }

  ShowWindow(window_handle, cmd_show);
  UpdateWindow(window_handle);

  return window_handle;
}

