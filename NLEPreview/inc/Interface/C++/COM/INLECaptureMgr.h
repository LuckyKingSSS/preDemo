#pragma once
#include <EncodeParam.h>
#include "COMMacro.h"
#include "ICaptureSource.h"

#define	CAPTURESTREAM_CONTROL_STOP 0x00000001 //ֹͣԴ
/*!
* \class ICaptureStreamControl
* \brief ¼��Դ���ƽӿڽӿ� 
*/
// {5CA5D651-E880-471e-A553-2C36A5982933}
DEFINE_GUID(IID_ICaptureStreamControl, 
			0x5ca5d651, 0xe880, 0x471e, 0xa5, 0x53, 0x2c, 0x36, 0xa5, 0x98, 0x29, 0x33);
EXTERN_C const IID IID_ICaptureStreamControl;
MACRO_MIDL_INTERFACE(ICaptureStreamControl, "5CA5D651-E880-471e-A553-2C36A5982933")
: public IUnknown
{
	virtual STDMETHODIMP					Control(int cmd, void *arg) = 0;
};

typedef 
enum Capture_Type
    {
        CaptureType_Mic	= 0,
        CaptureType_Camera	= ( CaptureType_Mic + 1 ) ,
        CaptureType_Desktop	= ( CaptureType_Camera + 1 ) ,
        CaptureType_Game	= ( CaptureType_Desktop + 1 ) ,
        CaptureType_Keyb	= ( CaptureType_Game + 1 ) ,
        CaptureType_Mark	= ( CaptureType_Keyb + 1 ) ,
        CaptureType_Mouse	= ( CaptureType_Mark + 1 ) 
    } 	Capture_Type;

typedef struct Capture_Info
    {
    Capture_Type type;
    int32_t idx;
    wchar_t displayName[ 256 ];
    wchar_t description[ 256 ];
    } 	Capture_Info;

typedef 
enum Capture_MSG
    {
        CaptureMSG_DeviceLost	= 0,
        CaptureMSG_DeviceFound	= ( CaptureMSG_DeviceLost + 1 ) 
    } 	Capture_MSG;

typedef HRESULT (__stdcall *CB_CaptureMgr )( 
    void *userData,
    int32_t msg,
    int32_t wparam,
    int32_t lparam);

/*!
* \class ICaptureEngineEx
* \brief ��ȡý���ļ���Ϣ�ӿ� 
*/
// {0E42BEE0-1BC3-492f-838E-F42437BFE463}
DEFINE_GUID(IID_INLECaptureMgr, 
			0x89d138bb, 0xaf5, 0x44ae, 0xa2, 0x9e, 0x8a, 0x6d, 0xe4, 0xa7, 0x3b, 0x8c);
EXTERN_C const IID IID_INLECaptureMgr;
MACRO_MIDL_INTERFACE(INLECaptureMgr, "89D138BB-0AF5-44AE-A29E-8A6DE4A73B8C")
: public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE InitInstance( void) = 0;
	
	virtual HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
	
	virtual HRESULT STDMETHODCALLTYPE GetCaptureCount( 
		/* [out][in] */ int32_t *pv) = 0;
	
	virtual HRESULT STDMETHODCALLTYPE GetCaptureInfo( 
		/* [in] */ int32_t streamIdx,
		/* [out][in] */ Capture_Info *pci) = 0;
	
	virtual HRESULT STDMETHODCALLTYPE CreateCaptureStream( 
		/* [in] */ int32_t streamIdx,
		/* [out][in] */ IUnknown **ppv) = 0;
	
	virtual HRESULT STDMETHODCALLTYPE SetCallback( 
		/* [in] */ int32_t *userData,
		/* [in] */ int32_t *cb) = 0;
};

// {E7C2FB23-A71C-4AE0-8186-6B469731E52E}
//�����������DecMgr
MIDL_DEFINE_GUID(CLSID, CLSID_NLECaptureMgr, 0xe7c2fb23, 0xa71c, 0x4ae0, 0x81, 0x86, 0x6b, 0x46, 0x97, 0x31, 0xe5, 0x2e);

EXTERN_C const CLSID CLSID_NLECaptureMgr;

#ifdef __cplusplus
extern "C" {
#endif
void CaptureInit(int isAppStore);
#ifdef __cplusplus
};
#endif