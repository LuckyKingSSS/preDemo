
/*! \file VideoPreview.h
* \brief	ת��Ԥ���ӿ�
*/

#pragma once
#include "CommonInterface.h"
#include <scombase.h>
#include "COMMacro.h"

/*!
* \class IVideoPreview
* \brief ��ȡת��Ԥ������Ƶͼ��
*/

// {A91C9247-7AEF-4774-A96E-BEA4F550C61E}
DEFINE_GUID(IID_IVideoPreview, 
			0xa91c9247, 0x7aef, 0x4774, 0xa9, 0x6e, 0xbe, 0xa4, 0xf5, 0x50, 0xc6, 0x1e);
EXTERN_C const IID IID_IVideoPreview;
MACRO_MIDL_INTERFACE(IVideoPreview, "A91C9247-7AEF-4774-A96E-BEA4F550C61E")
 : public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP GetFrame(IDibImage ** pDIBImage)
	* \brief  ��ȡ�ϴε���GetFrame����ʱ����ǰ����ͼ�����ݵĽӿ�ָ��
	* \param pDIBImage [in / out] ��Ƶͼ��λͼ�ӿ�ָ��
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetFrame(IDibImage ** pDIBImage) = 0;
};

// {F590E2B0-C009-4baa-8293-6838D8A6B63E}
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoPreview, 0xf590e2b0, 0xc009, 0x4baa, 0x82, 0x93, 0x68, 0x38, 0xd8, 0xa6, 0xb6, 0x3e);

EXTERN_C const CLSID CLSID_CVideoPreview;