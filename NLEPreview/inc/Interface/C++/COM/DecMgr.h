/*! \file DecMgr.h
 * \brief							�������ӿڵ���˵��
 * Detailed
 *Ӧ�ò����ͨ������DecMgrģ���ȡIDecMgr�Ľӿڣ�ͨ���ýӿڵ�GetMediaInfo������ȡý����Ϣ�ӿ�IMediaInfo��
 *�ýӿ��ṩ�˻�ȡý����Ϣ�ķ�����Ϊ�˻�ȡID3��ý���������Ϣ����ô���Ե���IMediaInfo�ӿ��е�QueryInerface��������ѯ�Ƿ�֧�ָýӿڡ�
 *Ϊ�˻�ȡ����Ƶ���ӿ�IMediaStream��ʹ��IDecMgr�ӿڵ�CreateMediaDecoder����������ý�������IMediaDecoder�ӿڣ�
 *ͨ��QueryInterface������ѯIVideoOutput, IAudioOutput�ӿڣ������ṩ�˻�ȡ����Ƶ�������ӿ�IMediaStream�ķ���GetVideoOutput�� GetAudioOutput��
 *IMediaDecoder�ӿ��ṩ�˶�̬�л����ķ���ChangeStream������������Ļ��ͨ��IMediaStream�ӿڵ�QueryInterface������
 *��ȡ�����Ļ�������ýӿ�ISubPicSetting��ͨ���ýӿڻ�ȡ�������õķ�����
 */


#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "TextDef.h"
#include "DecodeParam.h"
#include "CodecDefine.h"
#include "CommonInterface.h"

/*!
 * \class ISubPicStreamInfo
 * \brief ��ȡ��Ļ����Ϣ�ӿ� 
 */

// {FB73C029-B0BD-4cbb-A0CE-971E64D4BDD4}
DEFINE_GUID(IID_ISubPicStreamInfo, 
			0xfb73c029, 0xb0bd, 0x4cbb, 0xa0, 0xce, 0x97, 0x1e, 0x64, 0xd4, 0xbd, 0xd4);
EXTERN_C const IID IID_ISubPicStreamInfo;
MACRO_MIDL_INTERFACE(ISubPicStreamInfo, "FB73C029-B0BD-4cbb-A0CE-971E64D4BDD4")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(SUPPIC_TYPE) GetType(void)
	* \brief ��ȡ��Ļ�����ͣ� ��һ�����Ƕ
	* \retval ��Ļ������
	*/
	virtual STDMETHODIMP_(SUPPIC_TYPE) GetType(void) = 0;

	/*! \fn virtual STDMETHODIMP_(UINT) GetID(void)
	* \brief ��ȡ��Ļ��ID
	* \retval ��Ļ��ID
	*/
	virtual STDMETHODIMP_(UINT) GetID(void) = 0;

	/*! \fn virtual STDMETHODIMP_(UINT) GetFourCC(void)
	* \brief ��ȡ��Ļ��FourCC
	* \retval ��Ļ��FourCC
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC(void) = 0;

	/*! \fn virtual STDMETHODIMP GetLanguage(BSTR * ppLanguage)
	* \brief ��ȡ��Ļ������
	* \param ppLanguage [int/out] ��Ļ������
	* \retval HRESULT ��ȡ���
	*\ \warning �����ppLanguage������ʹ��SysFreeString�ͷţ����������ڴ�й¶ 
	*/
	virtual STDMETHODIMP GetLanguage(BSTR * ppLanguage) = 0;

	/*! \fn virtual STDMETHODIMP GetDescription(BSTR * ppDescription)
	* \brief ��ȡ��Ļ������
	* \param ppDescription [int/out] ��Ļ������
	* \retval HRESULT ��ȡ���
	* \warning �����ppDescription������ʹ��SysFreeString�ͷţ����������ڴ�й¶ 
	*/
	virtual STDMETHODIMP GetDescription(BSTR * ppDescription) = 0;
};

/*!
* \class ISubPicStreamInfos
* \brief ��Ļ��Ϣö�ٽӿ� 
*/

// {4291F08A-95C4-45c3-AF5B-1CC55A3F2CF7}
DEFINE_GUID(IID_ISubPicStreamInfos, 
			0x4291f08a, 0x95c4, 0x45c3, 0xaf, 0x5b, 0x1c, 0xc5, 0x5a, 0x3f, 0x2c, 0xf7);
EXTERN_C const IID IID_ISubPicStreamInfos;
MACRO_MIDL_INTERFACE(ISubPicStreamInfos, "4291F08A-95C4-45c3-AF5B-1CC55A3F2CF7")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ��Ļ������
	* \retval ��Ļ������
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;

	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, ISubPicStreamInfo** ppItem)
	* \brief ��ȡָ������Ļ��Ϣ�ӿ�
    * \param nIndex [in] ��Ļ��������
	* \param ppItem [out] ��Ļ��Ϣ�ӿ� 
	* \retval ��ȡ�Ľ��
	* \see ISubPicStreamInfo
	* \warning ppItemʹ����Ϻ�һ��Ҫ����Release�����ͷţ������ڴ�й¶��
	*/
	virtual STDMETHODIMP GetItem(int nIndex, ISubPicStreamInfo** ppItem) = 0;
};


/*!
* \class IStreamInfos
* \brief ����Ϣö�ٽӿ� 
*/

// {5DD650C8-40A3-4d0d-B460-0BA5804A1AAD}
DEFINE_GUID(IID_IStreamInfos, 
			0x5dd650c8, 0x40a3, 0x4d0d, 0xb4, 0x60, 0xb, 0xa5, 0x80, 0x4a, 0x1a, 0xad);
EXTERN_C const IID IID_IStreamInfos;
MACRO_MIDL_INTERFACE(IStreamInfos, "5DD650C8-40A3-4d0d-B460-0BA5804A1AAD")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ��������
	* \retval ��������
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;

	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IStreamInfo** ppItem)
	* \brief ��ȡָ��������Ϣ�ӿ�
	* \param nIndex [in] ����������
	* \param ppItem [out] ����Ϣ�ӿ� 
	* \retval ��ȡ�Ľ��
	* \see IStreamInfo
	* \warning ppItemʹ����Ϻ�һ��Ҫ����Release�����ͷţ������ڴ�й¶��
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IStreamInfo** ppItem) = 0;
};

/*!
* \class IProgramInfo
* \brief ��Ŀ��Ϣ�ӿڣ����ڻ�ȡý���ļ��еĽ�Ŀ��Ϣ 
*/

// {F5FA588B-55AF-4fa9-8913-323CFF39C231}
DEFINE_GUID(IID_IProgramInfo, 
			0xf5fa588b, 0x55af, 0x4fa9, 0x89, 0x13, 0x32, 0x3c, 0xff, 0x39, 0xc2, 0x31);
EXTERN_C const IID IID_IProgramInfo;
MACRO_MIDL_INTERFACE(IProgramInfo, "F5FA588B-55AF-4fa9-8913-323CFF39C231")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(UINT) GetNumber(void)
	* \brief ��ȡ��Ŀ��Number,����ʵ������
	* \retval ��Ŀ��Number
	*/
	virtual STDMETHODIMP_(UINT) GetNumber(void) = 0;

	/*! \fn virtual STDMETHODIMP_(UINT) GetID(void)
	* \brief ��ȡ��Ŀ��ID��ID�ǽ�Ŀ��Ψһ��ʾ
	* \retval ��Ŀ��ID
	*/
	virtual STDMETHODIMP_(UINT) GetID(void) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetMediaLength(void)
	* \brief ��ȡ��Ŀ��ʱ�䳤�ȣ���λ����
	* \retval ��Ŀ��ʱ��
	* \note   ȡ��Ŀ�и�·����ʱ�������ֵ
	*/
	virtual STDMETHODIMP_(double) GetMediaLength(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int)	  GetBitrate()
	* \brief ��ȡ��Ŀ������
	* \retval ��Ŀ������
	* \note ȡ��·������֮��
	*/
	virtual STDMETHODIMP_(int)	  GetBitrate() = 0;	
	
	/*! \fn virtual STDMETHODIMP_(UINT) GetTimeStampReferenceStreamID(void)
	* \brief ��ȡ��Ŀʱ����ο���ID��
	* \retval ʱ����ο���ID
	*/
	virtual STDMETHODIMP_(UINT) GetTimeStampReferenceStreamID(void) = 0;

	/*! \fn virtual STDMETHODIMP GetVideoStreamInfos(IStreamInfos** ppVideoStreamInfos)
	* \brief ��ȡ��Ƶ����Ϣö�����ӿڣ�
	* \param ppVideoStreamInfos [out] ��Ƶ��ö�����ӿ�
	* \retval ��ȡ���
	* \see IStreamInfos
	*/
	virtual STDMETHODIMP GetVideoStreamInfos(IStreamInfos** ppVideoStreamInfos) = 0;

	/*! \fn virtual STDMETHODIMP GetAudioStreamInfos(IStreamInfos** ppAudioStreamInfos)
	* \brief ��ȡ��Ƶ����Ϣö�����ӿڣ�
	* \param ppAudioStreamInfos [out] ��Ƶ����Ϣö�����ӿ�
	* \retval ��ȡ���
	* \see IStreamInfos
	*/
	virtual STDMETHODIMP GetAudioStreamInfos(IStreamInfos** ppAudioStreamInfos) = 0;

	/*! \fn virtual STDMETHODIMP GetSubPicStreamInfos(ISubPicStreamInfos** ppSubPicStreamInfos)
	* \brief ��ȡ��Ļ����Ϣö�����ӿڣ�
	* \param ppSubPicStreamInfos [out] ��Ļ����Ϣö�����ӿ�
	* \retval ��ȡ���
	* \see ISubPicStreamInfos
	*/
	virtual STDMETHODIMP GetSubPicStreamInfos(ISubPicStreamInfos** ppSubPicStreamInfos) = 0;
};

/*!
* \class IProgramInfos
* \brief ��Ŀ��Ϣö�����ӿ� 
*/

// {E04C85FD-D887-4716-8D7A-D18A17CE60EC}
DEFINE_GUID(IID_IProgramInfos, 
			0xe04c85fd, 0xd887, 0x4716, 0x8d, 0x7a, 0xd1, 0x8a, 0x17, 0xce, 0x60, 0xec);
EXTERN_C const IID IID_IProgramInfos;
MACRO_MIDL_INTERFACE(IProgramInfos, "E04C85FD-D887-4716-8D7A-D18A17CE60EC")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ��Ŀ������
	* \retval ��Ŀ������
	*/
	virtual STDMETHODIMP_(int) GetCount() = 0;

	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IProgramInfo** ppItem)
	* \brief ��ȡָ���Ľ�Ŀ��Ϣ�ӿ�
	* \param nIndex [in] ��Ŀ��������
	* \param ppItem [out] ��Ŀ��Ϣ�ӿ� 
	* \retval ��ȡ�Ľ��
	* \see IProgramInfo
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IProgramInfo** ppItem) = 0;	
};

/*!
* \class IMetaDataInfo
* \brief ��ȡMetaData��Ϣ�ӿ� 
*/

// {80DEF872-887D-4426-B31B-771011CF3427}
DEFINE_GUID(IID_IMetaDataInfo, 
            0x80def872, 0x887d, 0x4426, 0xb3, 0x1b, 0x77, 0x10, 0x11, 0xcf, 0x34, 0x27);
EXTERN_C const IID IID_IMetaDataInfo;
MACRO_MIDL_INTERFACE(IMetaDataInfo, "80DEF872-887D-4426-B31B-771011CF3427")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP GetArtist(BSTR *pArtist)
	* \brief ��ȡ��������Ϣ
	* \param pArtist [out] ��������Ϣ 
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetArtist(BSTR *pArtist) = 0;

	/*! \fn virtual STDMETHODIMP GetTitle(BSTR *pTitle)
	* \brief ��ȡ������Ϣ
	* \param pTitle [out] ������Ϣ 
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetTitle(BSTR *pTitle) = 0;

	/*! \fn virtual STDMETHODIMP GetTrackNumber(BSTR *pTrackNumber)
	* \brief ��ȡ�����
	* \param pTrackNumber [out] �����
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetTrackNumber(BSTR *pTrackNumber) = 0;

	/*! \fn virtual STDMETHODIMP GetAlbum(BSTR *pAlbum)
	* \brief ��ȡר������
	* \param pAlbum [out] ר������
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetAlbum(BSTR *pAlbum) = 0;

	/*! \fn virtual STDMETHODIMP GetDate(BSTR *pDate)
	* \brief ��ȡ���
	* \param pDate [out] ���
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetDate(BSTR *pDate) = 0;

	/*! \fn virtual STDMETHODIMP GetGenre(BSTR *pGenre)
	* \brief ��ȡ���
	* \param pGenre [out] ���
	* \retval ��ȡ�Ľ��
	*/
    virtual STDMETHODIMP GetGenre(BSTR *pGenre) = 0;
   
	/*! \fn virtual STDMETHODIMP GetPublisher(BSTR *pPublisher)
	* \brief ��ȡ������
	* \param pPublisher [out] ������
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetPublisher(BSTR *pPublisher) = 0;
};


/*!
* \class ICaptureMediaInfo
* \brief ��ȡ¼���ļ���Ϣ�ӿڣ�ͨ��IMediaInfo��ѯ�õ� 
*/

// {8C376301-E8AD-4037-A9FB-5C73C290AB9E}
DEFINE_GUID(IID_ICaptureMediaInfo, 
			0x8c376301, 0xe8ad, 0x4037, 0xa9, 0xfb, 0x5c, 0x73, 0xc2, 0x90, 0xab, 0x9e);
EXTERN_C const IID IID_ICaptureMediaInfo;
MACRO_MIDL_INTERFACE(ICaptureMediaInfo, "8C376301-E8AD-4037-A9FB-5C73C290AB9E")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(UINT) GetFourCC()
	* \brief ��ȡ������
	* \param nStreamID [in] ��ID
	* \param pType [out] �����ͣ��ο�NLEScreenRecordingStreamType
	* \retval �ļ�FourCC
	*/
	virtual STDMETHODIMP GetStreamType(int nStreamID, unsigned int *pType) = 0;
};

/*!
* \class IMediaInfo
* \brief ��ȡý���ļ���Ϣ�ӿ� 
*/

// {10CA4A98-A525-42a5-9282-DD64406261B2}
DEFINE_GUID(IID_IMediaInfo, 
			0x10ca4a98, 0xa525, 0x42a5, 0x92, 0x82, 0xdd, 0x64, 0x40, 0x62, 0x61, 0xb2);
EXTERN_C const IID IID_IMediaInfo;
MACRO_MIDL_INTERFACE(IMediaInfo, "10CA4A98-A525-42a5-9282-DD64406261B2")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(UINT) GetFourCC()
	* \brief ��ȡ�ļ�FourCC
	* \retval �ļ�FourCC
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC() = 0;

	/*! \fn virtual STDMETHODIMP GetFileName(BSTR * pFileName)
	* \brief ��ȡ�ļ���
	* \param pFileName [out] �ļ���
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetFileName(BSTR * pFileName) = 0;

	/*! \fn virtual STDMETHODIMP GetDescription(BSTR * ppDescription)
	* \brief ��ȡ�ļ���������Ϣ
	* \param ppDescription [out] �ļ���������Ϣ
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetDescription(BSTR * ppDescription) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetMediaLength(void)
	* \brief ��ȡý���ļ��Ĳ���ʱ��
	* \retval ý���ļ��Ĳ���ʱ��
	* \note ý���ļ�����ʱ����ȡý���ļ��а����ĸ�·��Ŀ��ʱ�������ֵ
	*/
	virtual STDMETHODIMP_(double) GetMediaLength(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetBitrate(void)
	* \brief ��ȡý���ļ�������
	* \retval ý���ļ�������
	* \note ý���ļ������ʣ�ȡ��·��Ŀ����֮��
	*/
	virtual STDMETHODIMP_(int) GetBitrate(void) = 0;

	/*! \fn virtual STDMETHODIMP GetIPrograms(IProgramInfos **ppProgramInfos)
	* \brief ��ȡ��Ŀ��Ϣö�����ӿ�
	* \retval ��ȡ���
	* \see IProgramInfos
	*/
	virtual STDMETHODIMP GetIPrograms(IProgramInfos **ppProgramInfos) = 0;

	/*! \fn virtual STDMETHODIMP GetIPrograms(IProgramInfos **ppProgramInfos)
	* \brief ��ȡ��������ɨ����Ϣ
	* \retval ��ȡ���
	* \see IProgramInfos
	*/
	virtual STDMETHODIMP_(AV_SCAN_TYPE) GetScanType() = 0;

};

// {89D89E0A-02F1-47a1-8756-323A9098937E}
DEFINE_GUID(IID_ISubPicSetting, 
			0x89d89e0a, 0x2f1, 0x47a1, 0x87, 0x56, 0x32, 0x3a, 0x90, 0x98, 0x93, 0x7e);
EXTERN_C const IID IID_ISubPicSetting;

/*!
* \class ISubPicSetting
* \brief ��Ļ��ʾ���ýӿ�
*/

MACRO_MIDL_INTERFACE(ISubPicSetting, "89D89E0A-02F1-47a1-8756-323A9098937E")
: public IUnknown
{
public:

	/*! \brief ������Ļ��ʾͼ��Ĵ�С
	* \param nWidth [in] ��Ļ�Ŀ�
	* \param nHeight [in] ��Ļ�ĸ�
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetRect(int nWidth, int nHeight) = 0;

	/*! \brief ��ȡ��Ļͼ��Ĵ�С
	* \param pWidth [out] ��Ļ�Ŀ�
	* \param pHeight [out] ��Ļ�ĸ�
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetRect(int * pWidth, int * pHeight) = 0;

	/*! \brief ������Ļ��ʾЧ�����Ƿ�ʹ��ȱʡģʽ
	* \param bUse [int] 1��ʾʹ�ã�0��ʾ��ʹ��
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetUseDefaultStyle(int bUse) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾЧ�����Ƿ����ȱʡģʽ
	* \retval 1��ʾ���ã�0��ʾδ����
	*/
	virtual STDMETHODIMP_(int) GetUseDefaultStyle(void) = 0;

	/*! \brief ������Ļ��ʾ������
	* \param fontName [int] ��������
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetFontName(const BSTR fontName) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾ������
	* \param pFontName [out] ��������
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetFontName(BSTR * pFontName) = 0;

	/*! \brief ������Ļ��ʾ���ֺ�
	* \param nFontSize [int] �ֺ�
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetFontSize(int nFontSize) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾ���ֺ�
	* \retval �ֺ�
	*/
	virtual STDMETHODIMP_(int) GetFontSize(void) = 0;

	/*! \brief ���õ�ǰ��Ļ��ʾ��������ʽ
	* \param nStyle  [in] ������ʽ,ȡֵ��ΧPCSFontStyleRegular | PCSFontStyleBold | PCSFontStyleItalic | PCSFontStyleUnderline
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetStyle(UINT nStyle) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾ��������ʽ
	* \retval ������ʽ
	*/
	virtual STDMETHODIMP_(UINT) GetStyle(void) = 0;

	/*! \brief ���õ�ǰ��Ļ��ʾ��������ɫ
	* \param fontColor  [in] ������ɫ
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetFontColor(COLORREF fontColor) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾ��������ɫ
	* \retval ������ɫ
	*/
	virtual STDMETHODIMP_(COLORREF) GetFontColor(void) = 0;

	/*! \brief ������Ļ��ʾ�������Ƿ�ʹ����Ӱ
	* \param bUse  [in] 1��ʾʹ�ã�0��ʾ��ʹ��
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetUseShadow(int bUse) = 0;

	/*! \brief ��ȡ��Ļ��ʾ�������Ƿ�ʹ����Ӱ
	* \retval 1��ʾʹ�ã�0��ʾδʹ��
	*/
	virtual STDMETHODIMP_(int) GetUseShadow(void) = 0;

	/*! \brief ����������Ӱ�Ĳ���
	* \param paramShadow [in] ������Ӱ�Ĳ���
	* \retval ���ý��
	* \note ֻ�е�����ʹ��������Ӱ�󣬲���Ч
	*/
	virtual STDMETHODIMP_(int) SetParamShadow(SHADOWPARAM paramShadow) = 0;

	/*! \brief ��ȡ��ǰ��Ļ��ʾ��������Ӱ����
	* \retval ������Ӱ�Ĳ���
	* \see SHADOWPARAM
	*/
	virtual STDMETHODIMP_(SHADOWPARAM) GetParamShadow(void) = 0;

	/*! \brief ���ù���Ч��
	* \param nValue [in] ����ֵ��0Ϊ�޹���Ч��
	* \param dwColor [int] ������ɫֵ
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetHalation(int nValue, COLORREF dwColor) = 0;

	/*! \brief ��ȡ��ǰ���õĹ���Ч��
	* \param pValue [out] ����ֵ
	* \param pColor [out] ������ɫֵ
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetHalation(int *pValue, COLORREF * pColor) = 0;

	/*! \brief ������ת�Ƕ�
	* \param nAngle [in] ��ת�Ƕ�
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetAngle(int nAngle) = 0;

	/*! \brief ��ȡ��ת�Ƕ�
	* \retval ��ת�Ƕ�
	*/
	virtual STDMETHODIMP_(int) GetAngle(void) = 0;

	/*! \brief ������ĻͼƬ��ƵͼƬ�ϵ�λ��
	* \param nXCoordinate [in] ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�X����
	* \param nYCoordinate [in] ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�Y����
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetLeftTopPos(int nXCoordinate, int nYCoordinate) = 0;

	/*! \brief ��ȡ��ǰ��ĻͼƬ��ƵͼƬ�ϵ�λ��
	* \param pXCoordinate [out] ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�X����
	* \param pYCoordinate [out] ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�Y����
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetLeftTopPos(int * pXCoordinate, int * pYCoordinate) = 0;
};

/*!
* \class IMediaDecoder
* \brief ý��������ӿڣ�ͨ��QueryInterface������ѯIVideoOutput, IAudioOutput�ӿڣ������ṩ�˻�ȡ����Ƶ��(IMediaStream)���������
* \see IVideoOutput IAudioOutput �ӿ�
*/

// {C8BD5D61-172A-4ca2-98B7-DE5F1E995D72}
DEFINE_GUID(IID_IMediaDecoder, 
			0xc8bd5d61, 0x172a, 0x4ca2, 0x98, 0xb7, 0xde, 0x5f, 0x1e, 0x99, 0x5d, 0x72);
EXTERN_C const IID IID_IMediaDecoder;
MACRO_MIDL_INTERFACE(IMediaDecoder, "C8BD5D61-172A-4ca2-98B7-DE5F1E995D72")
: public IUnknown
{
public:
};


/*!
* \class IDecMgr
* \brief ����������ӿڣ�ͨ�������Ի�ȡ�������ӿ�IMediaDecoder���Լ��ļ���Ϣ�ӿ�IMediaInfo
* \see IMediaDecoder IMediaInfo
*/

// {5AD2BE35-3038-4c6a-8C7F-3698526A898F}
DEFINE_GUID(IID_IDecMgr, 
			0x5ad2be35, 0x3038, 0x4c6a, 0x8c, 0x7f, 0x36, 0x98, 0x52, 0x6a, 0x89, 0x8f);
EXTERN_C const IID IID_IDecMgr;
MACRO_MIDL_INTERFACE(IDecMgr, "5AD2BE35-3038-4c6a-8C7F-3698526A898F")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(IMediaDecoder *) CreateMediaDecoder(const BSTR pMediaPath, FILE_TYPE fileType, const DecParam * pVideoDecParam, const DecParam * pAudioDecParam, DEC_MODEL DecMod)
	* \brief ����ý���ļ�·�������������������������ӿ�IMediaDecoder
	* \param pMediaPath [int] ý���ļ�·��
	* \param fileType [int] ý���ļ����� ��Ϊ����Ƶ�ļ����������Ļ
	* \param pVideoDecParam [in] ��Ƶ�������
	* \param pAudioDecParam [in] ��Ƶ�������
	* \param DecMod [in] ���뷽ʽѡ��
	* \retval �������ӿ� IMediaDecoder
	* \see FILE_TYPE DecParam DEC_MODEL IMediaDecoder
	*/
	virtual STDMETHODIMP_(IMediaDecoder *) CreateMediaDecoder(const BSTR pMediaPath, FILE_TYPE fileType, const DecParam * pVideoDecParam, const DecParam * pAudioDecParam, DEC_MODEL DecMod) = 0;


	/*! \fn virtual STDMETHODIMP GetMediaInfo(const BSTR pMediaPath, FILE_TYPE fileType, DEC_MODEL DecMod, IMediaInfo** ppIMediaInfo)
	* \brief ����ý���ļ�·������������ȡý���ļ���Ϣ�ӿ�IMediaInfo
	* \param pMediaPath [int] ý���ļ�·��
	* \param fileType [int] ý���ļ����� ��Ϊ����Ƶ�ļ����������Ļ
	* \param DecMod [in] ���뷽ʽѡ��
	* \param ppIMediaInfo ý����Ϣ�ӿ�
	* \retval ��ȡ���
	* \see FILE_TYPE  DEC_MODEL IMediaInfo
	*/
	virtual STDMETHODIMP GetMediaInfo(const BSTR pMediaPath, FILE_TYPE fileType, DEC_MODEL DecMod, IMediaInfo** ppIMediaInfo) = 0;


	virtual STDMETHODIMP_(IMediaDecoder *) CreateMediaDecoder(const BSTR pMediaPath, FILE_TYPE fileType, const DecParam * pVideoDecParam, const DecParam * pAudioDecParam, DEC_MODEL DecMod,IMediaInfo* pIMediaInfo) = 0;
	
};



// {E71EAD89-1CCD-4c34-97A8-7D45B5F16613}
//�����������DecMgr
MIDL_DEFINE_GUID(CLSID, CLSID_CDecMgr, 0xe71ead89, 0x1ccd, 0x4c34, 0x97, 0xa8, 0x7d, 0x45, 0xb5, 0xf1, 0x66, 0x13);

EXTERN_C const CLSID CLSID_CDecMgr;
