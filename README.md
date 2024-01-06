---
description: "Use Windows WebView2 TextureStream API"
languages: 
  - cpp
page_type: sample
products: 
  - microsoft-edge
---
# Sample for WebView2 TextureStream API

This sample is associated with the TextureStream API of Microsoft Edge's WebView2.

The TextureStream API empowers the WebView2 host to transmit video frames to the WebView2 engine, also known as the Edge Engine. 
This enables the stream to be played in Javascript, or alternatively, Javascript can modify the stream and return it to the WebView2 host.

The WebView2 host can persist in using its current video capture and editing code, and it can be utilized to play the video 
within the Javascript in the WebView2 content.

# The Visual Studio Sample

This includes two distinct sample sites, one at `https://sungook.github.io/get-ts` and the other at `https://sungook.github.io/register-ts`. 
These samples are modifications of the samples found at `https://webrtc.github.io/samples/`.

The site `https://sungook.github.io/get-ts` supports only the `chrome.webview.getTextureStream` API, 
while `https://sungook.github.io/register-ts` supports both `chrome.webview.getTextureStream` and `chrome.webview.registerTextureStream` APIs.

# Features
* We can specify the private WebView2 binary.
  - See 'kPrivateBinaryFolder'
    
* We can enable software rendering mode in machine that GPU is not available, post Edge v121.
  - See 'g_warp_mode'.
