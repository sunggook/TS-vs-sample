// Copyright (c) Microsoft Corporation. All rights reserved

#include "DrawRBGManager.h"

#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using Microsoft::WRL::ComPtr;

DrawRBGManager::DrawRBGManager() = default;
DrawRBGManager::~DrawRBGManager() = default;

void DrawRBGManager::Init(HWND hwnd, ComPtr<ID3D11Device> device) {
        
    HRESULT hr = S_OK;

    // Store window handle
    window_handle_ = hwnd;
    if (!device) {
        // Driver types supported
        D3D_DRIVER_TYPE kDriveTypes[] =
        {
            D3D_DRIVER_TYPE_HARDWARE,
            D3D_DRIVER_TYPE_WARP,
            D3D_DRIVER_TYPE_REFERENCE,
        };
        UINT number_of_drive_types = ARRAYSIZE(kDriveTypes);

        // Feature levels supported
        D3D_FEATURE_LEVEL kFeatureLevels[] =
        {
            D3D_FEATURE_LEVEL_12_1,
            D3D_FEATURE_LEVEL_12_0,
            D3D_FEATURE_LEVEL_11_1,
            D3D_FEATURE_LEVEL_11_0,
            D3D_FEATURE_LEVEL_10_1,
            D3D_FEATURE_LEVEL_10_0,
            D3D_FEATURE_LEVEL_9_1
        };
        UINT number_of_feature_levels = ARRAYSIZE(kFeatureLevels);
        D3D_FEATURE_LEVEL feature_level;
        // This flag adds support for surfaces with a different color channel
        // ordering than the default. It is required for compatibility with
        // Direct2D.
        UINT creation_flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

        // Create device
        hr = S_OK;
        for (UINT driver_type_index = 0; driver_type_index < number_of_drive_types; ++driver_type_index)
        {
            hr = D3D11CreateDevice(nullptr, kDriveTypes[driver_type_index], nullptr, creation_flags, kFeatureLevels, number_of_feature_levels,
                D3D11_SDK_VERSION, &d3d_device_, &feature_level, &device_context_);
            if (SUCCEEDED(hr))
            {
                // Device creation succeeded, no need to loop anymore
                break;
            }
        }
    }
    else {
        d3d_device_ = device;
        d3d_device_->GetImmediateContext(&device_context_);
    }

    DX::ThrowIfFailed(hr);

    // Get DXGI factory
    ComPtr<IDXGIDevice> dxgi_device;
    DX::ThrowIfFailed(d3d_device_.As(&dxgi_device));

    ComPtr<IDXGIAdapter> dxgi_adapter = nullptr;
    DX::ThrowIfFailed(dxgi_device->GetParent(__uuidof(IDXGIAdapter), &dxgi_adapter));
    DX::ThrowIfFailed(dxgi_adapter->GetParent(__uuidof(IDXGIFactory2), &dxgi_factory_));

    // Get window size
    RECT window_rect;
    GetClientRect(window_handle_, &window_rect);

    // Big size of width and height failed CreateTexture2D somehow.
    width_ = (window_rect.right - window_rect.left)  / 2;
    height_ = (window_rect.bottom - window_rect.top) / 2;

    // Create swapchain for window
    DXGI_SWAP_CHAIN_DESC1 swap_chain_desc = {};
    swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
    swap_chain_desc.BufferCount = 2;
    swap_chain_desc.Width = width_;
    swap_chain_desc.Height = height_;
    swap_chain_desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    swap_chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swap_chain_desc.SampleDesc.Count = 1;
    swap_chain_desc.SampleDesc.Quality = 0;
    swap_chain_desc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;


    swap_chain_desc.Scaling = DXGI_SCALING_STRETCH; //  DXGI_SCALING_NONE;
    swap_chain_desc.Stereo = false;
    swap_chain_desc.Flags = D3D11_RESOURCE_MISC_SHARED;

    DX::ThrowIfFailed(dxgi_factory_->CreateSwapChainForHwnd(d3d_device_.Get(), hwnd, &swap_chain_desc, nullptr, nullptr, &swap_chain_));

    // Disable the ALT-ENTER shortcut for entering full-screen mode
    DX::ThrowIfFailed(dxgi_factory_->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER));
}

HRESULT DrawRBGManager::DrawTextureWithWICBitmap(HANDLE shared_handle, ComPtr<IUnknown> texture_2d) {
    HRESULT hr = S_OK;
    ComPtr<ID3D11Texture2D> source_texture_by_size;
    static ComPtr<ID2D1RenderTarget> d2d_render_target_from_back_buffer_by_size;
    auto it = handle_to_texture_.find(ULONGLONG(shared_handle ? shared_handle : texture_2d.Get()));

    if (it == handle_to_texture_.end()) {
        // SwapChain's backbuffer would be render target of the bitmap drawing (Draw 2d on the 3d surface).
        ComPtr<ID3D11Texture2D> back_buffer;
        DX::ThrowIfFailed(swap_chain_->GetBuffer(0, __uuidof(ID3D11Texture2D), &back_buffer));
        ID2D1Factory* d2d_factory;
        D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &d2d_factory);
        //FLOAT dpiX;
        //FLOAT dpiY;
        //d2d_factory->GetDesktopDpi(&dpiX, &dpiY);
        D2D1_RENDER_TARGET_PROPERTIES props =
            D2D1::RenderTargetProperties(
                D2D1_RENDER_TARGET_TYPE_DEFAULT,
                D2D1::PixelFormat(DXGI_FORMAT_R8G8B8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
                96,
                96
            );
        props.pixelFormat.format = DXGI_FORMAT_UNKNOWN;  // or DXGI_FORMAT_B8G8R8A8_UNORM, https://docs.microsoft.com/en-us/windows/win32/Direct2D/supported-pixel-formats-and-alpha-modes
        props.pixelFormat.alphaMode = D2D1_ALPHA_MODE_IGNORE;
        ComPtr<ID2D1RenderTarget> d2d_render_target_from_back_buffer;
        ComPtr<IDXGISurface> dxgi_surface;
        DX::ThrowIfFailed(back_buffer.As(&dxgi_surface));
        DX::ThrowIfFailed(d2d_factory->CreateDxgiSurfaceRenderTarget(
            dxgi_surface.Get(),
            &props,
            &d2d_render_target_from_back_buffer
        ));
        d2d_render_target_from_back_buffer_by_size = d2d_render_target_from_back_buffer;


        // Open texture
        ComPtr<ID3D11Texture2D> source_texture;
        if (shared_handle) {
            ComPtr<ID3D11Device3> d3d_device3;
            DX::ThrowIfFailed(d3d_device_.As(&d3d_device3));
            DX::ThrowIfFailed(d3d_device3->OpenSharedResource1(shared_handle, IID_PPV_ARGS(&source_texture)));
        }
        else {
            DX::ThrowIfFailed(texture_2d.As(&source_texture));
        }

        source_texture_by_size = source_texture;
        handle_to_texture_.insert(std::pair<ULONGLONG, ComPtr<ID3D11Texture2D>>(
            shared_handle ? (ULONGLONG)shared_handle : (ULONGLONG)texture_2d.Get(), std::move(source_texture)));
    }
    else {
        source_texture_by_size = it->second.Get();
    }

    // source_texture_by_size = source_texture;
    // Create bitmap from the texture.
    // Create CPU accessible texture and copy the input texture to it.
    D3D11_TEXTURE2D_DESC texture_2d_desc;
    source_texture_by_size->GetDesc(&texture_2d_desc);
    texture_2d_desc.Usage = D3D11_USAGE_STAGING;
    texture_2d_desc.BindFlags = 0;
    texture_2d_desc.MiscFlags = 0;
    texture_2d_desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;

    ComPtr<ID3D11Texture2D> copied_cpu_access_texture;
    DX::ThrowIfFailed(d3d_device_->CreateTexture2D(&texture_2d_desc, NULL, &(copied_cpu_access_texture)));

    Microsoft::WRL::ComPtr<IDXGIKeyedMutex> keyed_mutex;
    source_texture_by_size->QueryInterface(IID_PPV_ARGS(&keyed_mutex));
    if (keyed_mutex) {
        keyed_mutex->AcquireSync(0, INFINITE);
    }

    device_context_->CopySubresourceRegion(
        copied_cpu_access_texture.Get(),
        0,
        0,
        0,
        0,
        source_texture_by_size.Get(),
        0,
        nullptr);

    if (keyed_mutex) {
        keyed_mutex->ReleaseSync(0);
    }

    ComPtr<IDXGISurface> dxgi_surface;
    copied_cpu_access_texture.As(&dxgi_surface);
    
    DXGI_MAPPED_RECT dxgi_bitmap_rect;
    DX::ThrowIfFailed(dxgi_surface->Map(&dxgi_bitmap_rect, DXGI_MAP_READ));
    D2D1_PIXEL_FORMAT d2d_pixel_format = {};
    D2D1_BITMAP_PROPERTIES bitmap_properties = {};

    d2d_pixel_format.format = DXGI_FORMAT_R8G8B8A8_UNORM;
    d2d_pixel_format.alphaMode = D2D1_ALPHA_MODE_IGNORE;
    bitmap_properties.dpiX = 96.0f;
    bitmap_properties.dpiY = 96.0f;
    bitmap_properties.pixelFormat = d2d_pixel_format;
    D2D1_SIZE_U size = D2D1::SizeU(texture_2d_desc.Width, texture_2d_desc.Height);

    ComPtr<ID2D1Bitmap> d2d_bitmap;
    
    DX::ThrowIfFailed(d2d_render_target_from_back_buffer_by_size->CreateBitmap(size, (void*)dxgi_bitmap_rect.pBits, dxgi_bitmap_rect.Pitch, bitmap_properties, &d2d_bitmap));
    DX::ThrowIfFailed(dxgi_surface->Unmap());

    // Begin draw.
    d2d_render_target_from_back_buffer_by_size->BeginDraw();

    D2D1_RECT_F textRect = { 0, 0, static_cast<FLOAT>(width_), static_cast<FLOAT>(height_) };
    d2d_render_target_from_back_buffer_by_size->DrawBitmap(d2d_bitmap.Get(), textRect);

    DX::ThrowIfFailed(d2d_render_target_from_back_buffer_by_size->EndDraw());
    DX::ThrowIfFailed(swap_chain_->Present(1, 0));

    return S_OK;
}

