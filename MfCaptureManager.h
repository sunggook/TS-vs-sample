
#pragma once

#include "common.h"

#include <list>

#include "MFVideoCallback.h"

// Define GUID for I420. This is the color format we would like to support but
// it is not defined in the DirectShow SDK.
// http://msdn.microsoft.com/en-us/library/dd757532.aspx
// 30323449-0000-0010-8000-00AA00389B71.
const GUID kMediaSubTypeI420 = {
    0x30323449,
    0x0000,
    0x0010,
    {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71} };

// UYVY synonym with BT709 color components, used in HD video. This variation
// might appear in non-USB capture cards and it's implemented as a normal YUV
// pixel format with the characters HDYC encoded in the first array word.
const GUID kMediaSubTypeHDYC = {
    0x43594448,
    0x0000,
    0x0010,
    {0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71} };

// 16-bit grey-scale single plane formats provided by some depth cameras.
const GUID kMediaSubTypeZ16 = {
    0x2036315a,
    0x0000,
    0x0010,
    {0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71} };
const GUID kMediaSubTypeINVZ = {
    0x5a564e49,
    0x2d90,
    0x4a58,
    {0x92, 0x0b, 0x77, 0x3f, 0x1f, 0x2c, 0x55, 0x6b} };
const GUID kMediaSubTypeY16 = {
    0x20363159,
    0x0000,
    0x0010,
    {0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71} };

const GUID GUID_ContainerFormatJpeg = { 0x19e4a5aa, 0x5662, 0x4fc5, 0xa0, 0xc0, 0x17, 0x58, 0x02, 0x8e, 0x10, 0x57 };

// Missing MF error.
#define MF_E_NO_MORE_TYPES 0xC00D36B9L

enum VideoPixelFormat {
    PIXEL_FORMAT_UNKNOWN = 0,  // Unknown or unspecified format value.
    PIXEL_FORMAT_I420 = 1,  // 12bpp YUV planar 1x1 Y, 2x2 UV samples, a.k.a. YU12.

    // Note: Chrome does not actually support YVU compositing, so you probably
    // don't actually want to use this. See http://crbug.com/784627.
    PIXEL_FORMAT_YV12 = 2,  // 12bpp YVU planar 1x1 Y, 2x2 VU samples.

    PIXEL_FORMAT_I422 = 3,   // 16bpp YUV planar 1x1 Y, 2x1 UV samples.
    PIXEL_FORMAT_I420A = 4,  // 20bpp YUVA planar 1x1 Y, 2x2 UV, 1x1 A samples.
    PIXEL_FORMAT_I444 = 5,   // 24bpp YUV planar, no subsampling.
    PIXEL_FORMAT_NV12 =
    6,  // 12bpp with Y plane followed by a 2x2 interleaved UV plane.
    PIXEL_FORMAT_NV21 =
    7,  // 12bpp with Y plane followed by a 2x2 interleaved VU plane.
    PIXEL_FORMAT_UYVY =
    8,  // 16bpp interleaved 2x1 U, 1x1 Y, 2x1 V, 1x1 Y samples.
    PIXEL_FORMAT_YUY2 =
    9,  // 16bpp interleaved 1x1 Y, 2x1 U, 1x1 Y, 2x1 V samples.
    PIXEL_FORMAT_ARGB = 10,   // 32bpp BGRA (byte-order), 1 plane.
    PIXEL_FORMAT_XRGB = 11,   // 24bpp BGRX (byte-order), 1 plane.
    PIXEL_FORMAT_RGB24 = 12,  // 24bpp BGR (byte-order), 1 plane.

    /* PIXEL_FORMAT_RGB32 = 13,  Deprecated */
    PIXEL_FORMAT_MJPEG = 14,  // MJPEG compressed.
    /* PIXEL_FORMAT_MT21 = 15,  Deprecated */

    // The P* in the formats below designates the number of bits per pixel
    // component. I.e. P9 is 9-bits per pixel component, P10 is 10-bits per pixel
    // component, etc.
    PIXEL_FORMAT_YUV420P9 = 16,
    PIXEL_FORMAT_YUV420P10 = 17,
    PIXEL_FORMAT_YUV422P9 = 18,
    PIXEL_FORMAT_YUV422P10 = 19,
    PIXEL_FORMAT_YUV444P9 = 20,
    PIXEL_FORMAT_YUV444P10 = 21,
    PIXEL_FORMAT_YUV420P12 = 22,
    PIXEL_FORMAT_YUV422P12 = 23,
    PIXEL_FORMAT_YUV444P12 = 24,

    /* PIXEL_FORMAT_Y8 = 25, Deprecated */
    PIXEL_FORMAT_Y16 = 26,  // single 16bpp plane.

    PIXEL_FORMAT_ABGR = 27,  // 32bpp RGBA (byte-order), 1 plane.
    PIXEL_FORMAT_XBGR = 28,  // 24bpp RGBX (byte-order), 1 plane.

    PIXEL_FORMAT_P016LE = 29,  // 24bpp NV12, 16 bits per channel

    PIXEL_FORMAT_XR30 =
    30,  // 32bpp BGRX, 10 bits per channel, 2 bits ignored, 1 plane
    PIXEL_FORMAT_XB30 =
    31,  // 32bpp RGBX, 10 bits per channel, 2 bits ignored, 1 plane

    PIXEL_FORMAT_BGRA = 32,  // 32bpp ARGB (byte-order), 1 plane.

    PIXEL_FORMAT_RGBAF16 = 33,  // Half float RGBA, 1 plane.

    // Please update UMA histogram enumeration when adding new formats here.
    PIXEL_FORMAT_MAX =
    PIXEL_FORMAT_RGBAF16,  // Must always be equal to largest entry logged.
};

enum class ReserveResult {
    kSucceeded,
    kMaxBufferCountExceeded,
    kAllocationFailed
};

struct Capture_Size {
    int width;
    int height;
};

struct PixelFormatMap {
    GUID mf_source_media_subtype;
    VideoPixelFormat pixel_format;
};

struct MediaFormatConfiguration {
    bool is_hardware_format;
    GUID mf_source_media_subtype;
    GUID mf_sink_media_subtype;
    VideoPixelFormat pixel_format;
};

// This list is ordered by precedence of use.
static VideoPixelFormat const kSupportedCapturePixelFormats[] = {
    PIXEL_FORMAT_I420,  PIXEL_FORMAT_YV12, PIXEL_FORMAT_NV12,
    PIXEL_FORMAT_NV21,  PIXEL_FORMAT_UYVY, PIXEL_FORMAT_YUY2,
    PIXEL_FORMAT_RGB24, PIXEL_FORMAT_ARGB, PIXEL_FORMAT_MJPEG,
};

struct VideoCaptureFormat {
    VideoCaptureFormat() {}
    VideoCaptureFormat(const Capture_Size& frame_size,
        float frame_rate,
        VideoPixelFormat pixel_format) {}

    // static std::string ToString(const VideoCaptureFormat& format);

    // Compares the priority of the pixel formats. Returns true if |lhs| is the
    // preferred pixel format in comparison with |rhs|. Returns false otherwise.
    static bool ComparePixelFormatPreference(const VideoPixelFormat& lhs, const VideoPixelFormat& rhs) {
        
        auto* format_lhs = std::find(kSupportedCapturePixelFormats,
            kSupportedCapturePixelFormats + ARRAYSIZE(kSupportedCapturePixelFormats), lhs);

        auto* format_rhs = std::find(
            kSupportedCapturePixelFormats,
            kSupportedCapturePixelFormats + ARRAYSIZE(kSupportedCapturePixelFormats), rhs);
        return format_lhs < format_rhs;
    }

    // Checks that all values are in the expected range. All limits are specified
    // in media::Limits.
    // bool IsValid() const;

    bool operator==(const VideoCaptureFormat& other) const {
        return frame_size.height == other.frame_size.height && frame_size.width == other.frame_size.width &&
            frame_rate == other.frame_rate && pixel_format == other.pixel_format;
    }

    Capture_Size frame_size;
    float frame_rate;
    VideoPixelFormat pixel_format;
};

struct CapabilityWin {
    CapabilityWin() {}
    CapabilityWin(int media_type_index, const VideoCaptureFormat& format)
        : media_type_index(media_type_index),
        supported_format(format),
        info_header(),
        stream_index(0),
        source_pixel_format(format.pixel_format) {}

    // Used by VideoCaptureDeviceWin.
    CapabilityWin(int media_type_index,
        const VideoCaptureFormat& format,
        const BITMAPINFOHEADER& info_header)
        : media_type_index(media_type_index),
        supported_format(format),
        info_header(info_header),
        stream_index(0),
        source_pixel_format(format.pixel_format) {}

    // Used by VideoCaptureDeviceMFWin.
    CapabilityWin(int media_type_index,
        const VideoCaptureFormat& format,
        int stream_index,
        VideoPixelFormat source_format)
        : media_type_index(media_type_index),
        supported_format(format),
        info_header(),
        stream_index(stream_index),
        source_pixel_format(source_format) {}

    int media_type_index;
    VideoCaptureFormat supported_format;

    // |info_header| is only valid if DirectShow is used.
    BITMAPINFOHEADER info_header;

    // |stream_index| is only valid if MediaFoundation is used.
    int stream_index;

    // |source_pixel_format| may differ from |supported_format|
    // if MediaFoundation is used.
    VideoPixelFormat source_pixel_format;
};

class MFCaptureManager {
public:
    MFCaptureManager(HWND hwnd);

    ~MFCaptureManager();

    HRESULT CreateMFDevice(LUID luid, bool warp_mode, ID3D11Device** device);

    HRESULT InitMF();
    HRESULT AllocateAndStartLocked();
    void DeallocateAndStop();
    void CreateDeviceForWindow();

 private:
     HRESULT CreateDeviceSourceMediaFoundation();
     std::wstring GetDeviceModelId(const std::wstring& device_id);

     HRESULT EnumerateDeviceSourcesMediaFoundation(Microsoft::WRL::ComPtr<IMFAttributes> attributes, IMFActivate*** devices, UINT32* count);

     HRESULT WaitOnCaptureEvent(GUID capture_event_guid);
     HRESULT ConvertToVideoSinkMediaType(IMFMediaType* source_media_type,
         bool use_hardware_format,
         IMFMediaType* sink_media_type);

     HRESULT CopyAttribute(IMFAttributes* source_attributes,
         IMFAttributes* destination_attributes,
         const GUID& key);

     HRESULT GetMFSinkMediaSubtype(IMFMediaType* source_media_type,
         bool use_hardware_format,
         GUID* mf_sink_media_subtype,
         bool* passthrough);

     bool GetMediaFormatConfigurationFromMFSourceMediaSubtype(
         const GUID& mf_source_media_subtype,
         bool use_hardware_format,
         MediaFormatConfiguration* media_format_configuration);

     HRESULT FillCapabilities(IMFCaptureSource* capture_source, bool photo, std::list<CapabilityWin>* capabilities);
     bool GetFormatFromSourceMediaType(IMFMediaType* source_media_type,
         bool photo,
         bool use_hardware_format,
         VideoCaptureFormat* format,
         VideoPixelFormat* source_pixel_format);

     VideoPixelFormat MfSubTypeToSourcePixelFormat(
         const GUID& mf_source_media_subtype);

     bool GetPixelFormatFromMFSourceMediaSubtype(
         const GUID& mf_source_media_subtype,
         bool use_hardware_format,
         VideoPixelFormat* pixel_format);

     bool GetFrameSizeFromMediaType(IMFMediaType* type, Capture_Size* frame_size);

     bool GetFrameRateFromMediaType(IMFMediaType* type, float* frame_rate);

     const CapabilityWin& GetBestMatchedCapability(
         const VideoCaptureFormat& requested,
         std::list<CapabilityWin>& capabilities);

     bool CompareCapability(const VideoCaptureFormat& requested, const CapabilityWin& lhs, const CapabilityWin& rhs);
     HRESULT RegisterWithMediaSource(
         Microsoft::WRL::ComPtr<IMFMediaSource> media_source);

     HRESULT RegisterInCaptureEngineAttributes(
         IMFAttributes* attributes);
     HRESULT CreateCaptureEngine(IMFCaptureEngine** engine);
     void CreateSwapChain();


	Microsoft::WRL::ComPtr<IMFDXGIDeviceManager> mf_dxgi_device_manager_;
	Microsoft::WRL::ComPtr<IMFCaptureEngine> mf_engine_;
    Microsoft::WRL::ComPtr<MFVideoCallback> video_callback_;
    Microsoft::WRL::ComPtr<IMFMediaSource> mf_source_;
    Microsoft::WRL::ComPtr<ID3D11Device> d3d_device_;
    HANDLE capture_error_;
    HANDLE capture_initialize_;
    std::wstring mf_device_id;
    bool has_sent_on_started_to_client_ = false;
    std::unique_ptr<CapabilityWin> selected_video_capability_;
    bool is_started_ = false;
    HWND hwnd_;
    uint32_t window_width_;
    uint32_t window_height_;
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain_;
    Microsoft::WRL::ComPtr<IDXGIAdapter> dxgi_adapter_;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3d_context_;
};
