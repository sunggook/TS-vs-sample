

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.xx.xxxx */
/* at a redacted point in time
 */
/* Compiler settings for ../../edge_embedded_browser/client/win/current/webview2staging.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.xx.xxxx 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __webview2staging_h__
#define __webview2staging_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __ICoreWebView2StagingEnvironmentOptions2_FWD_DEFINED__
#define __ICoreWebView2StagingEnvironmentOptions2_FWD_DEFINED__
typedef interface ICoreWebView2StagingEnvironmentOptions2 ICoreWebView2StagingEnvironmentOptions2;

#endif 	/* __ICoreWebView2StagingEnvironmentOptions2_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingFrame_FWD_DEFINED__
#define __ICoreWebView2StagingFrame_FWD_DEFINED__
typedef interface ICoreWebView2StagingFrame ICoreWebView2StagingFrame;

#endif 	/* __ICoreWebView2StagingFrame_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingFrameInfoCollection_FWD_DEFINED__
#define __ICoreWebView2StagingFrameInfoCollection_FWD_DEFINED__
typedef interface ICoreWebView2StagingFrameInfoCollection ICoreWebView2StagingFrameInfoCollection;

#endif 	/* __ICoreWebView2StagingFrameInfoCollection_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingFrameSourceChangedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingFrameSourceChangedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingFrameSourceChangedEventHandler ICoreWebView2StagingFrameSourceChangedEventHandler;

#endif 	/* __ICoreWebView2StagingFrameSourceChangedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile2_FWD_DEFINED__
#define __ICoreWebView2StagingProfile2_FWD_DEFINED__
typedef interface ICoreWebView2StagingProfile2 ICoreWebView2StagingProfile2;

#endif 	/* __ICoreWebView2StagingProfile2_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile3_FWD_DEFINED__
#define __ICoreWebView2StagingProfile3_FWD_DEFINED__
typedef interface ICoreWebView2StagingProfile3 ICoreWebView2StagingProfile3;

#endif 	/* __ICoreWebView2StagingProfile3_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile4_FWD_DEFINED__
#define __ICoreWebView2StagingProfile4_FWD_DEFINED__
typedef interface ICoreWebView2StagingProfile4 ICoreWebView2StagingProfile4;

#endif 	/* __ICoreWebView2StagingProfile4_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler;

#endif 	/* __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTexture_FWD_DEFINED__
#define __ICoreWebView2StagingTexture_FWD_DEFINED__
typedef interface ICoreWebView2StagingTexture ICoreWebView2StagingTexture;

#endif 	/* __ICoreWebView2StagingTexture_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStream_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStream_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStream ICoreWebView2StagingTextureStream;

#endif 	/* __ICoreWebView2StagingTextureStream_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamStartRequestedEventHandler ICoreWebView2StagingTextureStreamStartRequestedEventHandler;

#endif 	/* __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamStopRequestedEventHandler ICoreWebView2StagingTextureStreamStopRequestedEventHandler;

#endif 	/* __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler;

#endif 	/* __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamTextureErrorEventHandler ICoreWebView2StagingTextureStreamTextureErrorEventHandler;

#endif 	/* __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamTextureErrorEventArgs ICoreWebView2StagingTextureStreamTextureErrorEventArgs;

#endif 	/* __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureReceived_FWD_DEFINED__
#define __ICoreWebView2StagingTextureReceived_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureReceived ICoreWebView2StagingTextureReceived;

#endif 	/* __ICoreWebView2StagingTextureReceived_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamTextureReceivedEventHandler ICoreWebView2StagingTextureStreamTextureReceivedEventHandler;

#endif 	/* __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_FWD_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_FWD_DEFINED__
typedef interface ICoreWebView2StagingTextureStreamTextureReceivedEventArgs ICoreWebView2StagingTextureStreamTextureReceivedEventArgs;

#endif 	/* __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingRemoveCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2StagingRemoveCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingRemoveCompletedHandler ICoreWebView2StagingRemoveCompletedHandler;

#endif 	/* __ICoreWebView2StagingRemoveCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingSetEnabledCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2StagingSetEnabledCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingSetEnabledCompletedHandler ICoreWebView2StagingSetEnabledCompletedHandler;

#endif 	/* __ICoreWebView2StagingSetEnabledCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingExtension_FWD_DEFINED__
#define __ICoreWebView2StagingExtension_FWD_DEFINED__
typedef interface ICoreWebView2StagingExtension ICoreWebView2StagingExtension;

#endif 	/* __ICoreWebView2StagingExtension_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingExtensionList_FWD_DEFINED__
#define __ICoreWebView2StagingExtensionList_FWD_DEFINED__
typedef interface ICoreWebView2StagingExtensionList ICoreWebView2StagingExtensionList;

#endif 	/* __ICoreWebView2StagingExtensionList_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingAddExtensionCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2StagingAddExtensionCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingAddExtensionCompletedHandler ICoreWebView2StagingAddExtensionCompletedHandler;

#endif 	/* __ICoreWebView2StagingAddExtensionCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2StagingGetExtensionsCompletedHandler_FWD_DEFINED__
#define __ICoreWebView2StagingGetExtensionsCompletedHandler_FWD_DEFINED__
typedef interface ICoreWebView2StagingGetExtensionsCompletedHandler ICoreWebView2StagingGetExtensionsCompletedHandler;

#endif 	/* __ICoreWebView2StagingGetExtensionsCompletedHandler_FWD_DEFINED__ */


#ifndef __ICoreWebView2Staging3_FWD_DEFINED__
#define __ICoreWebView2Staging3_FWD_DEFINED__
typedef interface ICoreWebView2Staging3 ICoreWebView2Staging3;

#endif 	/* __ICoreWebView2Staging3_FWD_DEFINED__ */


/* header files for imported files */
#include "webview2experimental.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __WebView2Staging_LIBRARY_DEFINED__
#define __WebView2Staging_LIBRARY_DEFINED__

/* library WebView2Staging */
/* [version][uuid] */ 





























typedef /* [v1_enum] */ 
enum COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND
    {
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_STREAM_ID_ALREADY_REGISTERED	= 0,
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_NO_VIDEO_TRACK_STARTED	= ( COREWEBVIEW2_TEXTURE_STREAM_ERROR_STREAM_ID_ALREADY_REGISTERED + 1 ) ,
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_BUFFER_NOT_FOUND	= ( COREWEBVIEW2_TEXTURE_STREAM_ERROR_NO_VIDEO_TRACK_STARTED + 1 ) ,
        COREWEBVIEW2_TEXTURE_STREAM_ERROR_BUFFER_IN_USE	= ( COREWEBVIEW2_TEXTURE_STREAM_ERROR_BUFFER_NOT_FOUND + 1 ) 
    } 	COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND;


EXTERN_C const IID LIBID_WebView2Staging;

#ifndef __ICoreWebView2StagingEnvironmentOptions2_INTERFACE_DEFINED__
#define __ICoreWebView2StagingEnvironmentOptions2_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingEnvironmentOptions2 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingEnvironmentOptions2 = {0x1821A568,0xA141,0x4D77,{0xB3,0xD8,0x28,0x78,0xE3,0x83,0xD8,0xDD}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1821A568-A141-4D77-B3D8-2878E383D8DD")
    ICoreWebView2StagingEnvironmentOptions2 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_EnableWebLayer( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_EnableWebLayer( 
            /* [in] */ BOOL value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingEnvironmentOptions2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingEnvironmentOptions2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingEnvironmentOptions2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingEnvironmentOptions2 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingEnvironmentOptions2, get_EnableWebLayer)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableWebLayer )( 
            ICoreWebView2StagingEnvironmentOptions2 * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingEnvironmentOptions2, put_EnableWebLayer)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableWebLayer )( 
            ICoreWebView2StagingEnvironmentOptions2 * This,
            /* [in] */ BOOL value);
        
        END_INTERFACE
    } ICoreWebView2StagingEnvironmentOptions2Vtbl;

    interface ICoreWebView2StagingEnvironmentOptions2
    {
        CONST_VTBL struct ICoreWebView2StagingEnvironmentOptions2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingEnvironmentOptions2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingEnvironmentOptions2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingEnvironmentOptions2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingEnvironmentOptions2_get_EnableWebLayer(This,value)	\
    ( (This)->lpVtbl -> get_EnableWebLayer(This,value) ) 

#define ICoreWebView2StagingEnvironmentOptions2_put_EnableWebLayer(This,value)	\
    ( (This)->lpVtbl -> put_EnableWebLayer(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingEnvironmentOptions2_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingFrame_INTERFACE_DEFINED__
#define __ICoreWebView2StagingFrame_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingFrame */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingFrame = {0x1a8a1f7f,0x6545,0x44b2,{0x8e,0x93,0x71,0xbd,0x4d,0x2b,0x85,0x69}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1a8a1f7f-6545-44b2-8e93-71bd4d2b8569")
    ICoreWebView2StagingFrame : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ LPWSTR *uri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_SourceChanged( 
            /* [in] */ ICoreWebView2StagingFrameSourceChangedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_SourceChanged( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingFrameVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingFrame * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingFrame * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingFrame * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrame, get_Source)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Source )( 
            ICoreWebView2StagingFrame * This,
            /* [retval][out] */ LPWSTR *uri);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrame, add_SourceChanged)
        HRESULT ( STDMETHODCALLTYPE *add_SourceChanged )( 
            ICoreWebView2StagingFrame * This,
            /* [in] */ ICoreWebView2StagingFrameSourceChangedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrame, remove_SourceChanged)
        HRESULT ( STDMETHODCALLTYPE *remove_SourceChanged )( 
            ICoreWebView2StagingFrame * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2StagingFrameVtbl;

    interface ICoreWebView2StagingFrame
    {
        CONST_VTBL struct ICoreWebView2StagingFrameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingFrame_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingFrame_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingFrame_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingFrame_get_Source(This,uri)	\
    ( (This)->lpVtbl -> get_Source(This,uri) ) 

#define ICoreWebView2StagingFrame_add_SourceChanged(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_SourceChanged(This,eventHandler,token) ) 

#define ICoreWebView2StagingFrame_remove_SourceChanged(This,token)	\
    ( (This)->lpVtbl -> remove_SourceChanged(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingFrame_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingFrameInfoCollection_INTERFACE_DEFINED__
#define __ICoreWebView2StagingFrameInfoCollection_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingFrameInfoCollection */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingFrameInfoCollection = {0x5390db97,0x326b,0x48d8,{0x94,0x1d,0x68,0x6a,0xeb,0x17,0xe7,0x03}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5390db97-326b-48d8-941d-686aeb17e703")
    ICoreWebView2StagingFrameInfoCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetValueAtIndex( 
            /* [in] */ UINT32 index,
            /* [retval][out] */ ICoreWebView2FrameInfo **frameInfo) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ UINT32 *count) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingFrameInfoCollectionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingFrameInfoCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingFrameInfoCollection * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingFrameInfoCollection * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrameInfoCollection, GetValueAtIndex)
        HRESULT ( STDMETHODCALLTYPE *GetValueAtIndex )( 
            ICoreWebView2StagingFrameInfoCollection * This,
            /* [in] */ UINT32 index,
            /* [retval][out] */ ICoreWebView2FrameInfo **frameInfo);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrameInfoCollection, get_Count)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreWebView2StagingFrameInfoCollection * This,
            /* [retval][out] */ UINT32 *count);
        
        END_INTERFACE
    } ICoreWebView2StagingFrameInfoCollectionVtbl;

    interface ICoreWebView2StagingFrameInfoCollection
    {
        CONST_VTBL struct ICoreWebView2StagingFrameInfoCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingFrameInfoCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingFrameInfoCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingFrameInfoCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingFrameInfoCollection_GetValueAtIndex(This,index,frameInfo)	\
    ( (This)->lpVtbl -> GetValueAtIndex(This,index,frameInfo) ) 

#define ICoreWebView2StagingFrameInfoCollection_get_Count(This,count)	\
    ( (This)->lpVtbl -> get_Count(This,count) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingFrameInfoCollection_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingFrameSourceChangedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingFrameSourceChangedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingFrameSourceChangedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingFrameSourceChangedEventHandler = {0x05783d3d,0x1576,0x4254,{0xbd,0x8c,0x2d,0x66,0x0c,0x0d,0x91,0x5d}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05783d3d-1576-4254-bd8c-2d660c0d915d")
    ICoreWebView2StagingFrameSourceChangedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2Frame *sender,
            /* [in] */ ICoreWebView2SourceChangedEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingFrameSourceChangedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingFrameSourceChangedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingFrameSourceChangedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingFrameSourceChangedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingFrameSourceChangedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingFrameSourceChangedEventHandler * This,
            /* [in] */ ICoreWebView2Frame *sender,
            /* [in] */ ICoreWebView2SourceChangedEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2StagingFrameSourceChangedEventHandlerVtbl;

    interface ICoreWebView2StagingFrameSourceChangedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingFrameSourceChangedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingFrameSourceChangedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingFrameSourceChangedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingFrameSourceChangedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingFrameSourceChangedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingFrameSourceChangedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile2_INTERFACE_DEFINED__
#define __ICoreWebView2StagingProfile2_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingProfile2 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingProfile2 = {0xC0BE7F98,0x990A,0x479F,{0x99,0x1E,0xD4,0x12,0x2B,0x81,0x81,0xEB}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0BE7F98-990A-479F-991E-D4122B8181EB")
    ICoreWebView2StagingProfile2 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CookieManager( 
            /* [retval][out] */ ICoreWebView2CookieManager **cookieManager) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingProfile2Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingProfile2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingProfile2 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingProfile2 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile2, get_CookieManager)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CookieManager )( 
            ICoreWebView2StagingProfile2 * This,
            /* [retval][out] */ ICoreWebView2CookieManager **cookieManager);
        
        END_INTERFACE
    } ICoreWebView2StagingProfile2Vtbl;

    interface ICoreWebView2StagingProfile2
    {
        CONST_VTBL struct ICoreWebView2StagingProfile2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingProfile2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingProfile2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingProfile2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingProfile2_get_CookieManager(This,cookieManager)	\
    ( (This)->lpVtbl -> get_CookieManager(This,cookieManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingProfile2_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile3_INTERFACE_DEFINED__
#define __ICoreWebView2StagingProfile3_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingProfile3 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingProfile3 = {0x79f76b49,0x7d07,0x4a7e,{0x83,0xec,0x11,0x56,0xf9,0xc2,0xab,0x7e}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79f76b49-7d07-4a7e-83ec-1156f9c2ab7e")
    ICoreWebView2StagingProfile3 : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsPasswordAutosaveEnabled( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsPasswordAutosaveEnabled( 
            /* [in] */ BOOL value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsGeneralAutofillEnabled( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_IsGeneralAutofillEnabled( 
            /* [in] */ BOOL value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingProfile3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingProfile3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingProfile3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingProfile3 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile3, get_IsPasswordAutosaveEnabled)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsPasswordAutosaveEnabled )( 
            ICoreWebView2StagingProfile3 * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile3, put_IsPasswordAutosaveEnabled)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsPasswordAutosaveEnabled )( 
            ICoreWebView2StagingProfile3 * This,
            /* [in] */ BOOL value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile3, get_IsGeneralAutofillEnabled)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsGeneralAutofillEnabled )( 
            ICoreWebView2StagingProfile3 * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile3, put_IsGeneralAutofillEnabled)
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsGeneralAutofillEnabled )( 
            ICoreWebView2StagingProfile3 * This,
            /* [in] */ BOOL value);
        
        END_INTERFACE
    } ICoreWebView2StagingProfile3Vtbl;

    interface ICoreWebView2StagingProfile3
    {
        CONST_VTBL struct ICoreWebView2StagingProfile3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingProfile3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingProfile3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingProfile3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingProfile3_get_IsPasswordAutosaveEnabled(This,value)	\
    ( (This)->lpVtbl -> get_IsPasswordAutosaveEnabled(This,value) ) 

#define ICoreWebView2StagingProfile3_put_IsPasswordAutosaveEnabled(This,value)	\
    ( (This)->lpVtbl -> put_IsPasswordAutosaveEnabled(This,value) ) 

#define ICoreWebView2StagingProfile3_get_IsGeneralAutofillEnabled(This,value)	\
    ( (This)->lpVtbl -> get_IsGeneralAutofillEnabled(This,value) ) 

#define ICoreWebView2StagingProfile3_put_IsGeneralAutofillEnabled(This,value)	\
    ( (This)->lpVtbl -> put_IsGeneralAutofillEnabled(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingProfile3_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingProfile4_INTERFACE_DEFINED__
#define __ICoreWebView2StagingProfile4_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingProfile4 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingProfile4 = {0x2765B8BD,0x7C57,0x4B76,{0xB8,0xAA,0x1E,0xC9,0x40,0xFE,0x92,0xCC}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2765B8BD-7C57-4B76-B8AA-1EC940FE92CC")
    ICoreWebView2StagingProfile4 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddExtension( 
            /* [in] */ LPCWSTR extensionPath,
            /* [in] */ ICoreWebView2StagingAddExtensionCompletedHandler *handler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtensions( 
            /* [in] */ ICoreWebView2StagingGetExtensionsCompletedHandler *handler) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingProfile4Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingProfile4 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingProfile4 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingProfile4 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile4, AddExtension)
        HRESULT ( STDMETHODCALLTYPE *AddExtension )( 
            ICoreWebView2StagingProfile4 * This,
            /* [in] */ LPCWSTR extensionPath,
            /* [in] */ ICoreWebView2StagingAddExtensionCompletedHandler *handler);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile4, GetExtensions)
        HRESULT ( STDMETHODCALLTYPE *GetExtensions )( 
            ICoreWebView2StagingProfile4 * This,
            /* [in] */ ICoreWebView2StagingGetExtensionsCompletedHandler *handler);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingProfile4, Delete)
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ICoreWebView2StagingProfile4 * This);
        
        END_INTERFACE
    } ICoreWebView2StagingProfile4Vtbl;

    interface ICoreWebView2StagingProfile4
    {
        CONST_VTBL struct ICoreWebView2StagingProfile4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingProfile4_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingProfile4_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingProfile4_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingProfile4_AddExtension(This,extensionPath,handler)	\
    ( (This)->lpVtbl -> AddExtension(This,extensionPath,handler) ) 

#define ICoreWebView2StagingProfile4_GetExtensions(This,handler)	\
    ( (This)->lpVtbl -> GetExtensions(This,handler) ) 

#define ICoreWebView2StagingProfile4_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingProfile4_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler = {0x431721e0,0x0f18,0x4d7b,{0xbd,0x4d,0xe5,0xb1,0x52,0x2b,0xb1,0x10}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("431721e0-0f18-4d7b-bd4d-e5b1522bb110")
    ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2Staging3 *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler * This,
            /* [in] */ ICoreWebView2Staging3 *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandlerVtbl;

    interface ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTexture_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTexture_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTexture */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTexture = {0xc6a73462,0x2e60,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c6a73462-2e60-11ed-a261-0242ac120002")
    ICoreWebView2StagingTexture : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Resource( 
            /* [retval][out] */ IUnknown **resource) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ HANDLE *handle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTexture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTexture * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTexture * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTexture, get_Resource)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resource )( 
            ICoreWebView2StagingTexture * This,
            /* [retval][out] */ IUnknown **resource);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTexture, get_Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICoreWebView2StagingTexture * This,
            /* [retval][out] */ HANDLE *handle);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureVtbl;

    interface ICoreWebView2StagingTexture
    {
        CONST_VTBL struct ICoreWebView2StagingTextureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTexture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTexture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTexture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTexture_get_Resource(This,resource)	\
    ( (This)->lpVtbl -> get_Resource(This,resource) ) 

#define ICoreWebView2StagingTexture_get_Handle(This,handle)	\
    ( (This)->lpVtbl -> get_Handle(This,handle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTexture_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStream_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStream_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStream */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStream = {0x4150c99e,0x3479,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4150c99e-3479-11ed-a261-0242ac120002")
    ICoreWebView2StagingTextureStream : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_StreamId( 
            /* [retval][out] */ LPWSTR *id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddRequestedFilter( 
            /* [in] */ LPCWSTR origin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveRequestedFilter( 
            /* [in] */ LPCWSTR origin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_StartRequested( 
            /* [in] */ ICoreWebView2StagingTextureStreamStartRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_StartRequested( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_StopRequested( 
            /* [in] */ ICoreWebView2StagingTextureStreamStopRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_StopRequested( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBuffer( 
            /* [in] */ UINT32 width,
            /* [in] */ UINT32 height,
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAvailableBuffer( 
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveBuffer( 
            /* [in] */ ICoreWebView2StagingTexture *buffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBuffer( 
            /* [in] */ ICoreWebView2StagingTexture *buffer,
            /* [in] */ ULONGLONG timestamp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Present( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_TextureError( 
            /* [in] */ ICoreWebView2StagingTextureStreamTextureErrorEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_TextureError( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateD3DDevice( 
            /* [in] */ IUnknown *d3dDevice) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_TextureReceived( 
            /* [in] */ ICoreWebView2StagingTextureStreamTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_TextureReceived( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_StopTextureReceived( 
            /* [in] */ ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_StopTextureReceived( 
            /* [in] */ EventRegistrationToken token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTextureReceivedRequestedFilter( 
            /* [in] */ LPCWSTR origin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveTextureReceivedRequestedFilter( 
            /* [in] */ LPCWSTR origin) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStream * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStream * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, get_StreamId)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_StreamId )( 
            ICoreWebView2StagingTextureStream * This,
            /* [retval][out] */ LPWSTR *id);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, AddRequestedFilter)
        HRESULT ( STDMETHODCALLTYPE *AddRequestedFilter )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ LPCWSTR origin);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, RemoveRequestedFilter)
        HRESULT ( STDMETHODCALLTYPE *RemoveRequestedFilter )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ LPCWSTR origin);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, add_StartRequested)
        HRESULT ( STDMETHODCALLTYPE *add_StartRequested )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTextureStreamStartRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, remove_StartRequested)
        HRESULT ( STDMETHODCALLTYPE *remove_StartRequested )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, add_StopRequested)
        HRESULT ( STDMETHODCALLTYPE *add_StopRequested )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTextureStreamStopRequestedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, remove_StopRequested)
        HRESULT ( STDMETHODCALLTYPE *remove_StopRequested )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, CreateBuffer)
        HRESULT ( STDMETHODCALLTYPE *CreateBuffer )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ UINT32 width,
            /* [in] */ UINT32 height,
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, GetAvailableBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetAvailableBuffer )( 
            ICoreWebView2StagingTextureStream * This,
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, RemoveBuffer)
        HRESULT ( STDMETHODCALLTYPE *RemoveBuffer )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTexture *buffer);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, SetBuffer)
        HRESULT ( STDMETHODCALLTYPE *SetBuffer )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTexture *buffer,
            /* [in] */ ULONGLONG timestamp);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, Present)
        HRESULT ( STDMETHODCALLTYPE *Present )( 
            ICoreWebView2StagingTextureStream * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, Stop)
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            ICoreWebView2StagingTextureStream * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, add_TextureError)
        HRESULT ( STDMETHODCALLTYPE *add_TextureError )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureErrorEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, remove_TextureError)
        HRESULT ( STDMETHODCALLTYPE *remove_TextureError )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, UpdateD3DDevice)
        HRESULT ( STDMETHODCALLTYPE *UpdateD3DDevice )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ IUnknown *d3dDevice);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, add_TextureReceived)
        HRESULT ( STDMETHODCALLTYPE *add_TextureReceived )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, remove_TextureReceived)
        HRESULT ( STDMETHODCALLTYPE *remove_TextureReceived )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, add_StopTextureReceived)
        HRESULT ( STDMETHODCALLTYPE *add_StopTextureReceived )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, remove_StopTextureReceived)
        HRESULT ( STDMETHODCALLTYPE *remove_StopTextureReceived )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ EventRegistrationToken token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, AddTextureReceivedRequestedFilter)
        HRESULT ( STDMETHODCALLTYPE *AddTextureReceivedRequestedFilter )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ LPCWSTR origin);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStream, RemoveTextureReceivedRequestedFilter)
        HRESULT ( STDMETHODCALLTYPE *RemoveTextureReceivedRequestedFilter )( 
            ICoreWebView2StagingTextureStream * This,
            /* [in] */ LPCWSTR origin);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamVtbl;

    interface ICoreWebView2StagingTextureStream
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStream_get_StreamId(This,id)	\
    ( (This)->lpVtbl -> get_StreamId(This,id) ) 

#define ICoreWebView2StagingTextureStream_AddRequestedFilter(This,origin)	\
    ( (This)->lpVtbl -> AddRequestedFilter(This,origin) ) 

#define ICoreWebView2StagingTextureStream_RemoveRequestedFilter(This,origin)	\
    ( (This)->lpVtbl -> RemoveRequestedFilter(This,origin) ) 

#define ICoreWebView2StagingTextureStream_add_StartRequested(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_StartRequested(This,eventHandler,token) ) 

#define ICoreWebView2StagingTextureStream_remove_StartRequested(This,token)	\
    ( (This)->lpVtbl -> remove_StartRequested(This,token) ) 

#define ICoreWebView2StagingTextureStream_add_StopRequested(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_StopRequested(This,eventHandler,token) ) 

#define ICoreWebView2StagingTextureStream_remove_StopRequested(This,token)	\
    ( (This)->lpVtbl -> remove_StopRequested(This,token) ) 

#define ICoreWebView2StagingTextureStream_CreateBuffer(This,width,height,buffer)	\
    ( (This)->lpVtbl -> CreateBuffer(This,width,height,buffer) ) 

#define ICoreWebView2StagingTextureStream_GetAvailableBuffer(This,buffer)	\
    ( (This)->lpVtbl -> GetAvailableBuffer(This,buffer) ) 

#define ICoreWebView2StagingTextureStream_RemoveBuffer(This,buffer)	\
    ( (This)->lpVtbl -> RemoveBuffer(This,buffer) ) 

#define ICoreWebView2StagingTextureStream_SetBuffer(This,buffer,timestamp)	\
    ( (This)->lpVtbl -> SetBuffer(This,buffer,timestamp) ) 

#define ICoreWebView2StagingTextureStream_Present(This)	\
    ( (This)->lpVtbl -> Present(This) ) 

#define ICoreWebView2StagingTextureStream_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define ICoreWebView2StagingTextureStream_add_TextureError(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_TextureError(This,eventHandler,token) ) 

#define ICoreWebView2StagingTextureStream_remove_TextureError(This,token)	\
    ( (This)->lpVtbl -> remove_TextureError(This,token) ) 

#define ICoreWebView2StagingTextureStream_UpdateD3DDevice(This,d3dDevice)	\
    ( (This)->lpVtbl -> UpdateD3DDevice(This,d3dDevice) ) 

#define ICoreWebView2StagingTextureStream_add_TextureReceived(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_TextureReceived(This,eventHandler,token) ) 

#define ICoreWebView2StagingTextureStream_remove_TextureReceived(This,token)	\
    ( (This)->lpVtbl -> remove_TextureReceived(This,token) ) 

#define ICoreWebView2StagingTextureStream_add_StopTextureReceived(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_StopTextureReceived(This,eventHandler,token) ) 

#define ICoreWebView2StagingTextureStream_remove_StopTextureReceived(This,token)	\
    ( (This)->lpVtbl -> remove_StopTextureReceived(This,token) ) 

#define ICoreWebView2StagingTextureStream_AddTextureReceivedRequestedFilter(This,origin)	\
    ( (This)->lpVtbl -> AddTextureReceivedRequestedFilter(This,origin) ) 

#define ICoreWebView2StagingTextureStream_RemoveTextureReceivedRequestedFilter(This,origin)	\
    ( (This)->lpVtbl -> RemoveTextureReceivedRequestedFilter(This,origin) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStream_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamStartRequestedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamStartRequestedEventHandler = {0x62d09330,0x00a9,0x41bf,{0xa9,0xae,0x55,0xaa,0xef,0x8b,0x3c,0x44}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62d09330-00a9-41bf-a9ae-55aaef8b3c44")
    ICoreWebView2StagingTextureStreamStartRequestedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamStartRequestedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamStartRequestedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamStartRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamStartRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamStartRequestedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingTextureStreamStartRequestedEventHandler * This,
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamStartRequestedEventHandlerVtbl;

    interface ICoreWebView2StagingTextureStreamStartRequestedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamStartRequestedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamStartRequestedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamStartRequestedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamStartRequestedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamStartRequestedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamStartRequestedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamStopRequestedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamStopRequestedEventHandler = {0x4111102a,0xd19f,0x4438,{0xaf,0x46,0xef,0xc5,0x63,0xb2,0xb9,0xcf}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4111102a-d19f-4438-af46-efc563b2b9cf")
    ICoreWebView2StagingTextureStreamStopRequestedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamStopRequestedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamStopRequestedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamStopRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamStopRequestedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamStopRequestedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingTextureStreamStopRequestedEventHandler * This,
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamStopRequestedEventHandlerVtbl;

    interface ICoreWebView2StagingTextureStreamStopRequestedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamStopRequestedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamStopRequestedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamStopRequestedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamStopRequestedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamStopRequestedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamStopRequestedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler = {0x77eb4638,0x2f05,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77eb4638-2f05-11ed-a261-0242ac120002")
    ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler * This,
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ IUnknown *args);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandlerVtbl;

    interface ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamStopTextureReceivedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamTextureErrorEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamTextureErrorEventHandler = {0x52cb8898,0xc711,0x401a,{0x8f,0x97,0x36,0x46,0x83,0x1b,0xa7,0x2d}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52cb8898-c711-401a-8f97-3646831ba72d")
    ICoreWebView2StagingTextureStreamTextureErrorEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureErrorEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamTextureErrorEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamTextureErrorEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventHandler * This,
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureErrorEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamTextureErrorEventHandlerVtbl;

    interface ICoreWebView2StagingTextureStreamTextureErrorEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamTextureErrorEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamTextureErrorEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamTextureErrorEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamTextureErrorEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamTextureErrorEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamTextureErrorEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamTextureErrorEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamTextureErrorEventArgs = {0x0e1730c1,0x03df,0x4ad2,{0xb8,0x47,0xbe,0x4d,0x63,0xad,0xf7,0x00}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0e1730c1-03df-4ad2-b847-be4d63adf700")
    ICoreWebView2StagingTextureStreamTextureErrorEventArgs : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Kind( 
            /* [retval][out] */ COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuffer( 
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamTextureErrorEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamTextureErrorEventArgs, get_Kind)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Kind )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventArgs * This,
            /* [retval][out] */ COREWEBVIEW2_TEXTURE_STREAM_ERROR_KIND *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamTextureErrorEventArgs, GetBuffer)
        HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            ICoreWebView2StagingTextureStreamTextureErrorEventArgs * This,
            /* [retval][out] */ ICoreWebView2StagingTexture **buffer);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamTextureErrorEventArgsVtbl;

    interface ICoreWebView2StagingTextureStreamTextureErrorEventArgs
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamTextureErrorEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamTextureErrorEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamTextureErrorEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamTextureErrorEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamTextureErrorEventArgs_get_Kind(This,value)	\
    ( (This)->lpVtbl -> get_Kind(This,value) ) 

#define ICoreWebView2StagingTextureStreamTextureErrorEventArgs_GetBuffer(This,buffer)	\
    ( (This)->lpVtbl -> GetBuffer(This,buffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamTextureErrorEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureReceived_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureReceived_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureReceived */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureReceived = {0xb94265ae,0x4c1e,0x11ed,{0xbd,0xc3,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b94265ae-4c1e-11ed-bdc3-0242ac120002")
    ICoreWebView2StagingTextureReceived : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ HANDLE *handle) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Resource( 
            /* [retval][out] */ IUnknown **resource) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Timestamp( 
            /* [retval][out] */ ULONGLONG *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FinishUsingBuffer( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureReceivedVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureReceived * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureReceived * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureReceived * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureReceived, get_Handle)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            ICoreWebView2StagingTextureReceived * This,
            /* [retval][out] */ HANDLE *handle);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureReceived, get_Resource)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Resource )( 
            ICoreWebView2StagingTextureReceived * This,
            /* [retval][out] */ IUnknown **resource);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureReceived, get_Timestamp)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Timestamp )( 
            ICoreWebView2StagingTextureReceived * This,
            /* [retval][out] */ ULONGLONG *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureReceived, FinishUsingBuffer)
        HRESULT ( STDMETHODCALLTYPE *FinishUsingBuffer )( 
            ICoreWebView2StagingTextureReceived * This);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureReceivedVtbl;

    interface ICoreWebView2StagingTextureReceived
    {
        CONST_VTBL struct ICoreWebView2StagingTextureReceivedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureReceived_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureReceived_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureReceived_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureReceived_get_Handle(This,handle)	\
    ( (This)->lpVtbl -> get_Handle(This,handle) ) 

#define ICoreWebView2StagingTextureReceived_get_Resource(This,resource)	\
    ( (This)->lpVtbl -> get_Resource(This,resource) ) 

#define ICoreWebView2StagingTextureReceived_get_Timestamp(This,value)	\
    ( (This)->lpVtbl -> get_Timestamp(This,value) ) 

#define ICoreWebView2StagingTextureReceived_FinishUsingBuffer(This)	\
    ( (This)->lpVtbl -> FinishUsingBuffer(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureReceived_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamTextureReceivedEventHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamTextureReceivedEventHandler = {0x9ea4228c,0x295a,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9ea4228c-295a-11ed-a261-0242ac120002")
    ICoreWebView2StagingTextureStreamTextureReceivedEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureReceivedEventArgs *args) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamTextureReceivedEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamTextureReceivedEventHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventHandler * This,
            /* [in] */ ICoreWebView2StagingTextureStream *sender,
            /* [in] */ ICoreWebView2StagingTextureStreamTextureReceivedEventArgs *args);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamTextureReceivedEventHandlerVtbl;

    interface ICoreWebView2StagingTextureStreamTextureReceivedEventHandler
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamTextureReceivedEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_Invoke(This,sender,args)	\
    ( (This)->lpVtbl -> Invoke(This,sender,args) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamTextureReceivedEventHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_INTERFACE_DEFINED__
#define __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingTextureStreamTextureReceivedEventArgs */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingTextureStreamTextureReceivedEventArgs = {0xa4c2fa3a,0x295a,0x11ed,{0xa2,0x61,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a4c2fa3a-295a-11ed-a261-0242ac120002")
    ICoreWebView2StagingTextureStreamTextureReceivedEventArgs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTextureReceived( 
            /* [retval][out] */ ICoreWebView2StagingTextureReceived **value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingTextureStreamTextureReceivedEventArgsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventArgs * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventArgs * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingTextureStreamTextureReceivedEventArgs, GetTextureReceived)
        HRESULT ( STDMETHODCALLTYPE *GetTextureReceived )( 
            ICoreWebView2StagingTextureStreamTextureReceivedEventArgs * This,
            /* [retval][out] */ ICoreWebView2StagingTextureReceived **value);
        
        END_INTERFACE
    } ICoreWebView2StagingTextureStreamTextureReceivedEventArgsVtbl;

    interface ICoreWebView2StagingTextureStreamTextureReceivedEventArgs
    {
        CONST_VTBL struct ICoreWebView2StagingTextureStreamTextureReceivedEventArgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_GetTextureReceived(This,value)	\
    ( (This)->lpVtbl -> GetTextureReceived(This,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingTextureStreamTextureReceivedEventArgs_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingRemoveCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingRemoveCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingRemoveCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingRemoveCompletedHandler = {0xBD73ED6B,0x08A3,0x4A57,{0x9D,0xD0,0x29,0x03,0x06,0x76,0x32,0xB4}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD73ED6B-08A3-4A57-9DD0-2903067632B4")
    ICoreWebView2StagingRemoveCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingRemoveCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingRemoveCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingRemoveCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingRemoveCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingRemoveCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingRemoveCompletedHandler * This,
            /* [in] */ HRESULT errorCode);
        
        END_INTERFACE
    } ICoreWebView2StagingRemoveCompletedHandlerVtbl;

    interface ICoreWebView2StagingRemoveCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2StagingRemoveCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingRemoveCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingRemoveCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingRemoveCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingRemoveCompletedHandler_Invoke(This,errorCode)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingRemoveCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingSetEnabledCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingSetEnabledCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingSetEnabledCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingSetEnabledCompletedHandler = {0x0A5F7098,0x2265,0x49C7,{0xBA,0x60,0x5A,0x51,0x1E,0x80,0x80,0x5A}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A5F7098-2265-49C7-BA60-5A511E80805A")
    ICoreWebView2StagingSetEnabledCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingSetEnabledCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingSetEnabledCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingSetEnabledCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingSetEnabledCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingSetEnabledCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingSetEnabledCompletedHandler * This,
            /* [in] */ HRESULT errorCode);
        
        END_INTERFACE
    } ICoreWebView2StagingSetEnabledCompletedHandlerVtbl;

    interface ICoreWebView2StagingSetEnabledCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2StagingSetEnabledCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingSetEnabledCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingSetEnabledCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingSetEnabledCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingSetEnabledCompletedHandler_Invoke(This,errorCode)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingSetEnabledCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingExtension_INTERFACE_DEFINED__
#define __ICoreWebView2StagingExtension_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingExtension */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingExtension = {0xBCFC3E36,0x1BAD,0x4009,{0xBF,0xFC,0xA3,0x72,0xC4,0x69,0xF6,0xBA}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BCFC3E36-1BAD-4009-BFFC-A372C469F6BA")
    ICoreWebView2StagingExtension : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ LPWSTR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ ICoreWebView2StagingRemoveCompletedHandler *handler) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsEnabled( 
            /* [retval][out] */ BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnabled( 
            /* [in] */ BOOL isEnabled,
            /* [in] */ ICoreWebView2StagingSetEnabledCompletedHandler *handler) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingExtensionVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingExtension * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingExtension * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingExtension * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtension, get_Id)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            ICoreWebView2StagingExtension * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtension, get_Name)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoreWebView2StagingExtension * This,
            /* [retval][out] */ LPWSTR *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtension, Remove)
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICoreWebView2StagingExtension * This,
            /* [in] */ ICoreWebView2StagingRemoveCompletedHandler *handler);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtension, get_IsEnabled)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsEnabled )( 
            ICoreWebView2StagingExtension * This,
            /* [retval][out] */ BOOL *value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtension, SetEnabled)
        HRESULT ( STDMETHODCALLTYPE *SetEnabled )( 
            ICoreWebView2StagingExtension * This,
            /* [in] */ BOOL isEnabled,
            /* [in] */ ICoreWebView2StagingSetEnabledCompletedHandler *handler);
        
        END_INTERFACE
    } ICoreWebView2StagingExtensionVtbl;

    interface ICoreWebView2StagingExtension
    {
        CONST_VTBL struct ICoreWebView2StagingExtensionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingExtension_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingExtension_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingExtension_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingExtension_get_Id(This,value)	\
    ( (This)->lpVtbl -> get_Id(This,value) ) 

#define ICoreWebView2StagingExtension_get_Name(This,value)	\
    ( (This)->lpVtbl -> get_Name(This,value) ) 

#define ICoreWebView2StagingExtension_Remove(This,handler)	\
    ( (This)->lpVtbl -> Remove(This,handler) ) 

#define ICoreWebView2StagingExtension_get_IsEnabled(This,value)	\
    ( (This)->lpVtbl -> get_IsEnabled(This,value) ) 

#define ICoreWebView2StagingExtension_SetEnabled(This,isEnabled,handler)	\
    ( (This)->lpVtbl -> SetEnabled(This,isEnabled,handler) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingExtension_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingExtensionList_INTERFACE_DEFINED__
#define __ICoreWebView2StagingExtensionList_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingExtensionList */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingExtensionList = {0x59251055,0xF2F1,0x448F,{0xA0,0x96,0xF9,0x96,0xFB,0x9A,0xCB,0xE2}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59251055-F2F1-448F-A096-F996FB9ACBE2")
    ICoreWebView2StagingExtensionList : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ UINT *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValueAtIndex( 
            /* [in] */ UINT index,
            /* [retval][out] */ ICoreWebView2StagingExtension **extension) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingExtensionListVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingExtensionList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingExtensionList * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingExtensionList * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtensionList, get_Count)
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICoreWebView2StagingExtensionList * This,
            /* [retval][out] */ UINT *count);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingExtensionList, GetValueAtIndex)
        HRESULT ( STDMETHODCALLTYPE *GetValueAtIndex )( 
            ICoreWebView2StagingExtensionList * This,
            /* [in] */ UINT index,
            /* [retval][out] */ ICoreWebView2StagingExtension **extension);
        
        END_INTERFACE
    } ICoreWebView2StagingExtensionListVtbl;

    interface ICoreWebView2StagingExtensionList
    {
        CONST_VTBL struct ICoreWebView2StagingExtensionListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingExtensionList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingExtensionList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingExtensionList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingExtensionList_get_Count(This,count)	\
    ( (This)->lpVtbl -> get_Count(This,count) ) 

#define ICoreWebView2StagingExtensionList_GetValueAtIndex(This,index,extension)	\
    ( (This)->lpVtbl -> GetValueAtIndex(This,index,extension) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingExtensionList_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingAddExtensionCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingAddExtensionCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingAddExtensionCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingAddExtensionCompletedHandler = {0xE81499FE,0x8BC6,0x4BA6,{0xBA,0xD7,0xD2,0x1F,0xFA,0x4C,0x32,0x66}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E81499FE-8BC6-4BA6-BAD7-D21FFA4C3266")
    ICoreWebView2StagingAddExtensionCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2StagingExtension *extension) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingAddExtensionCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingAddExtensionCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingAddExtensionCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingAddExtensionCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingAddExtensionCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingAddExtensionCompletedHandler * This,
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2StagingExtension *extension);
        
        END_INTERFACE
    } ICoreWebView2StagingAddExtensionCompletedHandlerVtbl;

    interface ICoreWebView2StagingAddExtensionCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2StagingAddExtensionCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingAddExtensionCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingAddExtensionCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingAddExtensionCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingAddExtensionCompletedHandler_Invoke(This,errorCode,extension)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode,extension) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingAddExtensionCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2StagingGetExtensionsCompletedHandler_INTERFACE_DEFINED__
#define __ICoreWebView2StagingGetExtensionsCompletedHandler_INTERFACE_DEFINED__

/* interface ICoreWebView2StagingGetExtensionsCompletedHandler */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2StagingGetExtensionsCompletedHandler = {0x2A05565F,0xDE9D,0x46E3,{0xAA,0xF7,0xB8,0x66,0x96,0x68,0x28,0xF4}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A05565F-DE9D-46E3-AAF7-B866966828F4")
    ICoreWebView2StagingGetExtensionsCompletedHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( 
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2StagingExtensionList *extensionList) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2StagingGetExtensionsCompletedHandlerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2StagingGetExtensionsCompletedHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2StagingGetExtensionsCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2StagingGetExtensionsCompletedHandler * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2StagingGetExtensionsCompletedHandler, Invoke)
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoreWebView2StagingGetExtensionsCompletedHandler * This,
            /* [in] */ HRESULT errorCode,
            /* [in] */ ICoreWebView2StagingExtensionList *extensionList);
        
        END_INTERFACE
    } ICoreWebView2StagingGetExtensionsCompletedHandlerVtbl;

    interface ICoreWebView2StagingGetExtensionsCompletedHandler
    {
        CONST_VTBL struct ICoreWebView2StagingGetExtensionsCompletedHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2StagingGetExtensionsCompletedHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2StagingGetExtensionsCompletedHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2StagingGetExtensionsCompletedHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2StagingGetExtensionsCompletedHandler_Invoke(This,errorCode,extensionList)	\
    ( (This)->lpVtbl -> Invoke(This,errorCode,extensionList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2StagingGetExtensionsCompletedHandler_INTERFACE_DEFINED__ */


#ifndef __ICoreWebView2Staging3_INTERFACE_DEFINED__
#define __ICoreWebView2Staging3_INTERFACE_DEFINED__

/* interface ICoreWebView2Staging3 */
/* [unique][object][uuid] */ 


EXTERN_C __declspec(selectany) const IID IID_ICoreWebView2Staging3 = {0xd5655d4e,0x23ed,0x11ed,{0x86,0x1d,0x02,0x42,0xac,0x12,0x00,0x02}};

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d5655d4e-23ed-11ed-861d-0242ac120002")
    ICoreWebView2Staging3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateTextureStream( 
            /* [in] */ LPCWSTR streamId,
            /* [in] */ IUnknown *d3dDevice,
            /* [retval][out] */ ICoreWebView2StagingTextureStream **value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRenderAdapterLUID( 
            /* [retval][out] */ UINT64 *luid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add_RenderAdapterLUIDUpdated( 
            /* [in] */ ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE remove_RenderAdapterLUIDUpdated( 
            /* [in] */ EventRegistrationToken token) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICoreWebView2Staging3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoreWebView2Staging3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoreWebView2Staging3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoreWebView2Staging3 * This);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Staging3, CreateTextureStream)
        HRESULT ( STDMETHODCALLTYPE *CreateTextureStream )( 
            ICoreWebView2Staging3 * This,
            /* [in] */ LPCWSTR streamId,
            /* [in] */ IUnknown *d3dDevice,
            /* [retval][out] */ ICoreWebView2StagingTextureStream **value);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Staging3, GetRenderAdapterLUID)
        HRESULT ( STDMETHODCALLTYPE *GetRenderAdapterLUID )( 
            ICoreWebView2Staging3 * This,
            /* [retval][out] */ UINT64 *luid);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Staging3, add_RenderAdapterLUIDUpdated)
        HRESULT ( STDMETHODCALLTYPE *add_RenderAdapterLUIDUpdated )( 
            ICoreWebView2Staging3 * This,
            /* [in] */ ICoreWebView2StagingRenderAdapterLUIDUpdatedEventHandler *eventHandler,
            /* [out] */ EventRegistrationToken *token);
        
        DECLSPEC_XFGVIRT(ICoreWebView2Staging3, remove_RenderAdapterLUIDUpdated)
        HRESULT ( STDMETHODCALLTYPE *remove_RenderAdapterLUIDUpdated )( 
            ICoreWebView2Staging3 * This,
            /* [in] */ EventRegistrationToken token);
        
        END_INTERFACE
    } ICoreWebView2Staging3Vtbl;

    interface ICoreWebView2Staging3
    {
        CONST_VTBL struct ICoreWebView2Staging3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoreWebView2Staging3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICoreWebView2Staging3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICoreWebView2Staging3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICoreWebView2Staging3_CreateTextureStream(This,streamId,d3dDevice,value)	\
    ( (This)->lpVtbl -> CreateTextureStream(This,streamId,d3dDevice,value) ) 

#define ICoreWebView2Staging3_GetRenderAdapterLUID(This,luid)	\
    ( (This)->lpVtbl -> GetRenderAdapterLUID(This,luid) ) 

#define ICoreWebView2Staging3_add_RenderAdapterLUIDUpdated(This,eventHandler,token)	\
    ( (This)->lpVtbl -> add_RenderAdapterLUIDUpdated(This,eventHandler,token) ) 

#define ICoreWebView2Staging3_remove_RenderAdapterLUIDUpdated(This,token)	\
    ( (This)->lpVtbl -> remove_RenderAdapterLUIDUpdated(This,token) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICoreWebView2Staging3_INTERFACE_DEFINED__ */

#endif /* __WebView2Staging_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


