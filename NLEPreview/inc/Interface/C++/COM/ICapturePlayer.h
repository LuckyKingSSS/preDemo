#pragma once
#include <EncodeParam.h>
#include "COMMacro.h"
#include "ICaptureSource.h"

/*!
* \class ICaptureEngineEx
* \brief ��ȡý���ļ���Ϣ�ӿ� 
*/
// {0E42BEE0-1BC3-492f-838E-F42437BFE463}
DEFINE_GUID(IID_ICapturePlayer, 
			0xe42bee0, 0x1bc3, 0x492f, 0x83, 0x8e, 0xf4, 0x24, 0x37, 0xbf, 0xe4, 0x63);
EXTERN_C const IID IID_ICapturePlayer;
MACRO_MIDL_INTERFACE(ICapturePlayer, "0E42BEE0-1BC3-492f-838E-F42437BFE463")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP Init(void)
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP Init() = 0;

	/*! \fn virtual STDMETHODIMP SetCaptureStream(void)
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP SetCaptureStream(IUnknown *pCaptureStream) = 0;

	/*! \fn virtual STDMETHODIMP SetDisplayWindow(void *pWnd)
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP SetDisplayWindow(HVIEW pWnd, int *pViewID) = 0;

	/*! \fn virtual STDMETHODIMP Start()
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP Start() = 0;

	/*! \fn virtual Stop Start()
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP Stop() = 0;

	/*! \fn virtual Stop ClearView()
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP ClearView(int nViewID) = 0;

	/*! \fn virtual Stop ClearAllViews()
	* \brief ¼�������ʼ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP ClearAllViews() = 0;
};

// {07E89C72-9CBD-4e02-852A-ABC44C74FDDA}
//�����������DecMgr
MIDL_DEFINE_GUID(CLSID, CLSID_CCapturePlayer, 0x7e89c72, 0x9cbd, 0x4e02, 0x85, 0x2a, 0xab, 0xc4, 0x4c, 0x74, 0xfd, 0xda);

EXTERN_C const CLSID CLSID_CCapturePlayer;

#ifdef __cplusplus
extern "C" {
#endif
void CaptureInit(int isAppStore);
#ifdef __cplusplus
};
#endif