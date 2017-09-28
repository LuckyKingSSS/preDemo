/*! \file EncMgr.h.h
* \brief	��������Ϣ���ļ���ʽ��Ϣ�ӿ�
*/
#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "ConverterType.h"


/*!
* \class IEncoderInfo
* \brief ��������Ϣ�ӿ� 
*/

// {D5B71CE2-3957-413c-9DF4-2587CBD20BE4}
DEFINE_GUID(IID_IEncoderInfo, 
			0xd5b71ce2, 0x3957, 0x413c, 0x9d, 0xf4, 0x25, 0x87, 0xcb, 0xd2, 0xb, 0xe4);
EXTERN_C const IID IID_IEncoderInfo;
MACRO_MIDL_INTERFACE(IEncoderInfo, "D5B71CE2-3957-413c-9DF4-2587CBD20BE4")
: public IUnknown
{
public:
	/*! \fn STDMETHODIMP_(UINT) GetFourCC(void)
	* \brief ��ȡ����forcc
	* \retval ����forcc
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC(void)=0;
	/*! \fn STDMETHODIMP GetName(BSTR * ppName)
	* \brief ��ȡ����������
	* \param ppName [out] ���������� 
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetName(BSTR * ppName)=0;
	/*! \fn STDMETHODIMP GetDescription(BSTR * ppName)
	* \brief ��ȡ����������
	* \param ppDescription [out] ���������� 
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetDescription(BSTR * ppDescription)=0;
};

/*!
* \class IEncoderInfos
* \brief ��������Ϣö�ٽӿ� 
*/

// {A6F06C44-8115-47c5-A98A-F2E44744B378}
DEFINE_GUID(IID_IEncoderInfos, 
			0xa6f06c44, 0x8115, 0x47c5, 0xa9, 0x8a, 0xf2, 0xe4, 0x47, 0x44, 0xb3, 0x78);
EXTERN_C const IID IID_IEncoderInfos;
MACRO_MIDL_INTERFACE(IEncoderInfos, "A6F06C44-8115-47c5-A98A-F2E44744B378")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ������������
	* \retval ������������
	*/
	virtual STDMETHODIMP_(int) GetCount(void)=0;
	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IEncoderInfo** ppEncoderInfo)
	* \brief ��ȡָ���ı�������Ϣ�ӿ�
	* \param nIndex [in] ��������������
	* \param ppItem [out] ��������Ϣ�ӿ� 
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IEncoderInfo** ppEncoderInfo)=0;
};


/*!
* \class IFileFormatInfo
* \brief �ļ���ʽ��Ϣ�ӿ� 
*/
// {72BE4AD5-A6B3-4c75-92E2-15BEACE01F72}
DEFINE_GUID(IID_IFileFormatInfo, 
			0x72be4ad5, 0xa6b3, 0x4c75, 0x92, 0xe2, 0x15, 0xbe, 0xac, 0xe0, 0x1f, 0x72);
EXTERN_C const IID IID_IFileFormatInfo;
MACRO_MIDL_INTERFACE(IFileFormatInfo, "72BE4AD5-A6B3-4c75-92E2-15BEACE01F72")
: public IUnknown
{
public:
	/*! \fn STDMETHODIMP_(UINT) GetFourCC(void)
	* \brief ��ȡ�ļ�forcc
	* \retval �ļ�forcc
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC(void) = 0;
	/*! \fn virtual STDMETHODIMP GetExtName(BSTR * ppName)
	* \brief ��ȡ�ļ���չ��
    * \param ppName [out] ��չ�� 
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetExtName(BSTR * ppName) = 0;
	/*! \fn virtual STDMETHODIMP GetFormatName(BSTR * ppFormatName)
	* \brief ��ȡ�ļ���ʽ��
	* \param ppFormatName [out] �ļ�������
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetFormatName(BSTR * ppFormatName) = 0;
	/*! \fn virtual STDMETHODIMP GetDescription(BSTR * ppDescription)
	* \brief ��ȡ�ļ���ʽ����
	* \param ppDescription [out] �ļ���ʽ����
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetDescription(BSTR * ppDescription) = 0;
	/*! \fn virtual GetAudioEncoderInfos(IEncoderInfos** ppEncoderInfos) = 0;
	* \brief ��ȡ��Ƶ��������Ϣö�ٽӿ�
	* \param ppEncoderInfos [out] ��������Ϣö�ٽӿ�
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetAudioEncoderInfos(IEncoderInfos** ppEncoderInfos) = 0;
	/*! \fn virtual GetVideoEncoderInfos(IEncoderInfos** ppEncoderInfos) = 0;
	* \brief ��ȡ��Ƶ��������Ϣö�ٽӿ�
	* \param ppEncoderInfos [out] ��������Ϣö�ٽӿ�
	* \retval  ��ȡ���
	*/
	virtual STDMETHODIMP GetVideoEncoderInfos(IEncoderInfos** ppEncoderInfos) = 0;
};

/*!
* \class IEncoderInfos
* \brief �ļ���ʽ��Ϣö�ٽӿ� 
*/

// {5C9908D7-FDCD-4827-BC0B-94CB3ECCF8BD}
DEFINE_GUID(IID_IFileFormatInfos, 
			0x5c9908d7, 0xfdcd, 0x4827, 0xbc, 0xb, 0x94, 0xcb, 0x3e, 0xcc, 0xf8, 0xbd);
EXTERN_C const IID IID_IFileFormatInfos;
MACRO_MIDL_INTERFACE(IFileFormatInfos, "5C9908D7-FDCD-4827-BC0B-94CB3ECCF8BD")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ�ļ���ʽ������
	* \retval �ļ���ʽ������
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;
	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IFileFormatInfo** ppFileFormatInfo)
	* \brief ��ȡָ�����ļ���ʽ��Ϣ�ӿ�
	* \param nIndex [in] �ļ���ʽ��������
	* \param ppItem [out] �ļ���ʽ��Ϣ�ӿ� 
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IFileFormatInfo** ppFileFormatInfo) = 0;
};


//�����������
MIDL_DEFINE_GUID(CLSID, CLSID_CFileFormatInfos, 0xf1eb87e5, 0x6940, 0x42b6, 0xb4, 0xce, 0x20, 0x8a, 0xa7, 0x69, 0x58, 0x19);

EXTERN_C const CLSID CLSID_CFileFormatInfos;




/*!
* \class IEncMgr
* \brief ���������أ�ж�ؽӿ� 
*/
// {35C227E3-C3AE-466b-8535-D10BC155B45F}
DEFINE_GUID(IID_IEncMgr, 
		0x35c227e3, 0xc3ae, 0x466b, 0x85, 0x35, 0xd1, 0xb, 0xc1, 0x55, 0xb4, 0x5f);
EXTERN_C const IID IID_IEncMgr;
MACRO_MIDL_INTERFACE(IEncMgr,"35C227E3-C3AE-466b-8535-D10BC155B45F")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(int) FCInitPlugins()
	* \brief ��ʼ���������ӿ�
	* \param isWMV [in] ��ǰת���Ƿ���WMV��ʽ������win��֧�� ��
	* \retval ��ȡ��ʼ����������״��
	*/
	virtual STDMETHODIMP_(int) FCInitPlugins() = 0;

	/*! \fn virtual STDMETHODIMP  FCUninitPlugins()
	* \brief ж�ر������ӿ�
	*/
	virtual STDMETHODIMP  FCUninitPlugins()= 0;

};

//�����齨����
// {9415EA92-D975-4c82-9787-AE99313BA350}
MIDL_DEFINE_GUID(CLSID,CLSID_CEncMgr,0x9415ea92, 0xd975, 0x4c82, 0x97, 0x87, 0xae, 0x99, 0x31, 0x3b, 0xa3, 0x50);
EXTERN_C const CLSID CLSID_CEncMgr;


