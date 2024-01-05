#pragma once

// Use the C++ standard templated min/max
#define NOMINMAX

#include <windows.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>

#pragma warning(push)
#pragma warning(disable : 4467)
#include <wrl.h>
#pragma warning(pop)

#include <d3d11_3.h>
#include <d3d10.h>

#if defined(NTDDI_WIN10_RS2)
#include <dxgi1_6.h>
#else
#include <dxgi1_5.h>
#endif

#include <DirectXMath.h>
#include <DirectXColors.h>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include <mfapi.h>
#include <mfmediaengine.h>

// include WebView2 header
#include "WebView2.h"
#include "webview2experimental.h"

#include <d2d1.h>
#include <windows.h>
#include <d3d11.h>
#include <d3d11_3.h>

#include <dxgi1_2.h>
#include <new>
#include <warning.h>
#include <DirectXMath.h>

#define IDC_TEST_SEND_TEXTURE             WM_USER + 1000
#define IDC_TEST_CREATE_NEW_BUFFER        WM_USER + 1001
#define IDC_TEST_REQUEST_BUFFER           WM_USER + 1002
#define IDC_WEBVIEW2_NAVIGATION_COMPLETE  WM_USER + 1003

// IPC Message between SlimCore and WebViewProcess.
enum class SharedBufferCommand {
    Unknown,  // ensure that 0 has no meaning.
    RequestCreateNewBuffer,
    RequestBuffer,
    RequestSetBuferAndPresent,
    ResponseBufferCreated,
    ResponseBufferAvailableRequest,
};

struct TextureBufferInfo {
    SharedBufferCommand command;
    int64_t buffer_id;
    uint32_t handle;
    uint32_t width;
    uint32_t height;
    ULONGLONG timestamp;
};

namespace DX
{
    // Helper class for COM exceptions
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) noexcept : result(hr) {}

        const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X", static_cast<unsigned int>(result));
            return s_str;
        }

    private:
        HRESULT result;
    };

    // Helper utility converts D3D API failures into exceptions.
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }
}

void SendToSlimCoreWithResource(bool createdBufer, IUnknown* resource, UINT64 buffer_id);
HWND CreateSubWindow(HINSTANCE instance, int cmd_show, PCWSTR class_name, PCWSTR window_title);
DWORD ThreadProcForStreamId(PVOID param);
