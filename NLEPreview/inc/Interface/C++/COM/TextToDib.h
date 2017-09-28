/**
@file TextToDib.h
@brief ��������ˮӡ
*/
#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "CommonInterface.h"
#include "TextDef.h"


/** 
@class 	 ITextItem 
@brief	 �ı�������.
*/

// {EDA25D65-A4EE-4d00-B2D0-B37DB619F145}
DEFINE_GUID(IID_ITextItem,0xeda25d65, 0xa4ee, 0x4d00, 0xb2, 0xd0, 0xb3, 0x7d, 0xb6, 0x19, 0xf1, 0x45);
EXTERN_C const IID IID_ITextItem;
MACRO_MIDL_INTERFACE(ITextItem, "EDA25D65-A4EE-4d00-B2D0-B37DB619F145")
: public IUnknown
{
public:

	/**
	@brief			�����ı�����
	@param textContent [in] :  �ı�����
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetContent(const BSTR textContent) = 0;

	/**
	@brief			��ȡ�ı�����
	@param pContent [out] :  ��ȡ�ı�����
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetContent(BSTR *pContent) const = 0;
	
	/**
	@brief			�����ı�������
	@param strFontName [in] :  ������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetFontName(BSTR strFontName) = 0;

	/**
	@brief			��ȡ�ı�������
	@param strFontName [out] :  ��ȡ������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetFontName(BSTR *strFontName) const = 0;
	
	/**
	@brief			�����ı���ɫ
	@param crFont [in] :  ������ɫ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetFontColor(COLORREF crFont) = 0;

	/**
	@brief			��ȡ�ı���ɫ
	@return		COLORREF : ������ɫֵ
	*/
	virtual STDMETHODIMP_(COLORREF) GetFontColor(void) const = 0;
	
	/**
	@brief			�����ı������С
	@param nFontSize [in] :  �����С
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetFontSize(int nFontSize) = 0;

	/**
	@brief			��ȡ�ı������С
	@return		int : ���������С
	*/
	virtual STDMETHODIMP_(int) GetFontSize(void)const = 0;
	
	/**
	@brief			�����ı�������ʽֵ
	@param uStyle [in] :  ��������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetStyle(UINT uStyle) = 0;

	/**
	@brief			��ȡ�ı�������ʽֵ
	@return		UINT : ����������ʽֵ

	*/
	virtual STDMETHODIMP_(UINT) GetStyle(void) const = 0;
	
	/**
	@brief			�����ı������Ƿ�ʹ����Ӱ
	@param bShadow [in] :  �Ƿ�ʹ����Ӱ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetUseShadow(int bShadow) = 0;

	/**
	@brief			��ȡ�ı������Ƿ�ʹ����Ӱ
	@return		int : �����Ƿ�ʹ����Ӱ
	*/
	virtual STDMETHODIMP_(int) GetUseShadow() const = 0;
	
	/**
	@brief			�����ı�������Ӱ��ʽ
	@param paramShadow [in] :  ��Ӱ��ʽ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetShadowParam(SHADOWPARAM	paramShadow) = 0;

	/**
	@brief			��ȡ�ı������Ƿ�ʹ����Ӱ
	@return		int : ������Ӱ��ʽ
	*/
	virtual STDMETHODIMP_(SHADOWPARAM) GetShadowParam(void) const = 0;
	
	/**
	@brief			�����ı��������ֵ �� ������ɫ
	@param nHalation [in] :  ����ֵ
	@param halationColor [in] :  ������ɫ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetHalation(int nHalation, COLORREF halationColor) = 0;

	/**
	@brief			��ȡ�ı��������ֵ �� ������ɫ
	@param pHalation [out] :  ����ֵ
	@param pHalationColor [out] :  ������ɫ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetHalation(int *pHalation, COLORREF *pHalationColor) const = 0;
	
	/**
	@brief			�����ı�������ת�Ƕ�
	@param nAngle [in] :  ��ת�Ƕ�
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetAngle(int nAngle)=0;


	/**
	@brief			��ȡ�ı�������ת�Ƕ�
	@return		int : �����ı�������ת�Ƕ�
	*/
	virtual STDMETHODIMP_(int) GetAngle() const = 0;
	
	/**
	@brief			�����ı�������X��Y��������ű���
	@param xScale [in] :  X�������ű���
	@param yScale [in] :  Y�������ű���
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetScale(int xScale, int yScale) = 0;

	/**
	@brief			��ȡ�ı�������X��Y��������ű���
	@param pXScale [out] :  X�������ű���
	@param pYScale [out] :  Y�������ű���
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetScale(int *pXScale, int *pYScale) const = 0;
};

/** 
@class 	 IPCText 
@brief	 ����ˮӡ������ص���.
*/

// {E8E0B4CB-9E9A-46f6-AA7D-FA547A3EA1F4}
DEFINE_GUID(IID_IPCText,0xe8e0b4cb, 0x9e9a, 0x46f6, 0xaa, 0x7d, 0xfa, 0x54, 0x7a, 0x3e, 0xa1, 0xf4);
EXTERN_C const IID IID_IPCText;
MACRO_MIDL_INTERFACE(IPCText, "E8E0B4CB-9E9A-46f6-AA7D-FA547A3EA1F4")
: public IUnknown
{
public:

	/**
	@brief			����ͼ���ļ�,��ת��Ϊ32λ��dibimage
	@param picName [in] : ͼ���ļ���
	@return		IDibImage * : ���� ��ɫλ��Ϊ32λ��IDibImageָ��
	*/
	virtual STDMETHODIMP_(IDibImage *) LoadImage32B(BSTR picName) = 0;

	/**
	@brief			���� ITextItem ����ռ�
	@return		ITextItem * : ���� ITextItem��ָ��
	*/
	virtual STDMETHODIMP_(ITextItem *) CreateTextSetting(void) = 0;

	/**
	@brief			��ȡϵͳ��֧�ֵ�������
	@return		int : ���� ϵͳ��֧�ֵ�������
	*/
	virtual STDMETHODIMP_(int) GetSupportFontCount(void) = 0;

	/**
	@brief			��ȡ����nIndex ��Ӧ��������
	@param nIndex [in]: ��������ֵ
	@param pFontName [out]: ������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP	   GetSupportFontName(int nIndex, BSTR *pFontName) = 0;

	/**
	@brief			���� LPTEXTTRANSFORM �ṹ����Ϣ�������� һ��ͼƬ
	@param pItem [in]: �ı�������ָ��
	@param lpTextTransform [in]: LPTEXTTRANSFORM�ṹ�壬��������λ�õ������Ϣ
	@param pImageTexture [in]: IDibImageָ�룬���ڵ���
	@return		IDibImage : ָ�򴴽���ͼƬ��ָ��
	*/
	virtual STDMETHODIMP_(IDibImage *) CreateNormalTextByTrans(const ITextItem *pItem,const LPTEXTTRANSFORM lpTextTransform ,IDibImage *pImageTexture = NULL) = 0;

	/**
	@brief			���� ����ͼƬ �߿����Ϣ�������� һ��ͼƬ
	@param pItem [in]: �ı�������ָ��
	@param width [in]: ͼƬ��
	@param height [in]: ͼƬ��
	@param pImageTexture [in]: IDibImageָ�룬���ڵ���
	@return		IDibImage : ָ�򴴽���ͼƬ��ָ��
	*/
	virtual STDMETHODIMP_(IDibImage *) CreateNormalTextBySize(const ITextItem *pItem,int width = 0, int height = 0, IDibImage *pImageTexture = NULL) = 0;

	/**
	@brief			��ȡϵͳ��֧�ֵ�����������
	@return		int : ���� ϵͳ��֧�ֵ�����������
	*/
	virtual STDMETHODIMP_(int) GetArtTextCount(void) = 0;

	/**
	@brief			��ȡnIndex��Ӧ�����������Ϣ
	@param nIndex [in]: ����ֵ
	@return		const LPARTTEXTINFO : ������������Ϣ�Ľṹ��ָ��
	*/
	virtual STDMETHODIMP_(const LPARTTEXTINFO) GetArtTextInfo(int nIndex) = 0;

	/**
	@brief			��ȡpArtID��Ӧ�����ֵ�����ֵ
	@param pArtID [in]: ������ID
	@return		int : ��������������ֵ
	*/
	virtual STDMETHODIMP_(int) GetIndexFromID(const BSTR * pArtID) = 0;
	
	/**
	@brief			���� LPTEXTTRANSFORM �ṹ����Ϣ�������� һ��������ͼƬ
	@param pArtItem [in]: �����ֽṹ��ָ��
	@param lpTextTransform [in]: LPTEXTTRANSFORM�ṹ�壬��������λ�õ������Ϣ
	@return		IDibImage : ָ�򴴽���ͼƬ��ָ��
	*/
	virtual STDMETHODIMP_(IDibImage *) GenerateArtTextByTrans(const LPARTTEXTITEM pArtItem, const LPTEXTTRANSFORM lpTextTransform) = 0; 

	/**
	@brief			���� ����ͼƬ �߿����Ϣ�������� һ��ͼƬ
	@param pArtItem [in]: �����ֽṹ��ָ��
	@param width [in]: ͼƬ��
	@param height [in]: ͼƬ��
	@return		IDibImage : ָ�򴴽���ͼƬ��ָ��
	*/
	virtual STDMETHODIMP_(IDibImage *) GenerateArtTextBySize(const  LPARTTEXTITEM pArtItem, int width, int height)=0;

};

//�����������
MIDL_DEFINE_GUID(CLSID, CLSID_CPCSText, 0xc3297339, 0x6fc4, 0x4b45, 0x81, 0xcc, 0x57, 0x8b, 0x39, 0xbf, 0xac, 0x45 );
EXTERN_C const CLSID CLSID_CPCSText;
// {c3297339-6fc4-4b45-81cc-578b39bfac45}
	
