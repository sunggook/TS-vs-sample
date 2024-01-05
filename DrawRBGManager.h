// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "common.h"

#include <map>

class DrawRBGManager {
public:
    DrawRBGManager();
    ~DrawRBGManager();
    void Init(HWND hWnd, Microsoft::WRL::ComPtr<ID3D11Device> device);
    HRESULT DrawTextureWithWICBitmap(HANDLE shared_handle, Microsoft::WRL::ComPtr<IUnknown> texture_2d);

private:
    Microsoft::WRL::ComPtr<IDXGIFactory2> dxgi_factory_;
    Microsoft::WRL::ComPtr<ID3D11Device> d3d_device_;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> device_context_;
    Microsoft::WRL::ComPtr<IDXGISwapChain1> swap_chain_;
    uint32_t width_;
    uint32_t height_;
    HWND window_handle_ = nullptr;

    std::map<ULONGLONG, Microsoft::WRL::ComPtr<ID3D11Texture2D>> handle_to_texture_;
};
