
/*! \file IFOInterface.h
* \brief	IFO��ISO��Ϣ��ȡ�ӿ�
*/

#pragma once
#include <scombase.h>
#include "COMMacro.h"

/*!
* \class IIFOInfo
* \brief ��ȡIFO��Ϣ���ýӿ�ͨ����ѯIMediaInfo�ӿڻ�ȡ�� 
*/


// {5D71E358-66C1-4248-BB77-EB39F910E1FC}
DEFINE_GUID(IID_IIFOInfo, 
			0x5d71e358, 0x66c1, 0x4248, 0xbb, 0x77, 0xeb, 0x39, 0xf9, 0x10, 0xe1, 0xfc);
EXTERN_C const IID IID_IIFOInfo;
MACRO_MIDL_INTERFACE(IIFOInfo, "5D71E358-66C1-4248-BB77-EB39F910E1FC")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(int)    GetHaveCSSProtect()
	* \brief ��ȡӰ���Ƿ���CSS����
	* \retval  -1 ��ʾ ��ȷ��, 0 ��ʾ û��, 1 ��ʾ ��
	*/
	virtual STDMETHODIMP_(int) GetHaveCSSProtect() = 0;

	/*! \fn virtual STDMETHODIMP_(int)    GetTitleCount()
	* \brief ��ȡIFO��Title����Ŀ
	* \retval Title����Ŀ
	*/
	virtual STDMETHODIMP_(int) GetTitleCount() = 0;

	/*! \fn virtual STDMETHODIMP_(int)    GetChapterCount(int nTitleIndex)
	* \brief ��ȡָ����Title�½���
	* \retval Title���½���
	*/
	virtual STDMETHODIMP_(int) GetChapterCount(int nTitleIndex) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetTitleBeginTime(int nTitleIndex)
	* \brief ��ȡָ����Title��ʼʱ��
	* \param nTitleIndex [in] Title��������
	* \retval Title����ʼʱ��
	*/
	virtual STDMETHODIMP_(double) GetTitleBeginTime(int nTitleIndex) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetTitleLength(int nTitleIndex)
	* \brief ��ȡָ����Title����ʱ��
	* \param nTitleIndex [in] Title��������
	* \retval Title�Ĳ���ʱ��
	*/
	virtual STDMETHODIMP_(double) GetTitleLength(int nTitleIndex) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetChapterBeginTime(int nTitleIndex, int nChapterIndex)
	* \brief ��ȡָ�����½���ʼʱ��
	* \param nTitleIndex [in] Title��������
	* \param nChapterIndex [in] �½ڵ�������
	* \retval �½���ʼʱ��
	*/
	virtual STDMETHODIMP_(double) GetChapterBeginTime(int nTitleIndex, int nChapterIndex) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetChapterLength(int nTitleIndex, int nChapterIndex)
	* \brief ��ȡָ�����½ڲ���ʱ��
	* \param nTitleIndex [in] Title��������
	* \param nChapterIndex [in] �½ڵ�������
	* \retval �½ڵĲ���ʱ��
	*/
	virtual STDMETHODIMP_(double) GetChapterLength(int nTitleIndex, int nChapterIndex) = 0;

	/*! \fn virtual STDMETHODIMP_(int)    GetTitleAudioTrackCount(int nTitleIndex)
	* \brief ��ȡָ����Title������
	* \param nTitleIndex [in] Title��������
	* \retval Title��������
	*/
	virtual STDMETHODIMP_(int) GetTitleAudioTrackCount(int nTitleIndex) = 0;

	/*! \fn virtual STDMETHODIMP		  GetAudioTrackDesc(int nTitleIndex, int nAudioTrackidx, BSTR *ppDescription)
	* \brief ��ȡָ�������������Ϣ
	* \param nTitleIndex [in] Title��������
	* \param nAudioTrackidx [in] �����������
	* \param ppDescription [in / out] �����������Ϣ
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetAudioTrackDesc(int nTitleIndex, int nAudioTrackidx, BSTR *ppDescription) = 0;

	/*! \fn virtual STDMETHODIMP_(int)    GetTitleSubTitleCount(int nTitleIndex)
	* \brief ��ȡָ����Title��Ļ��
	* \param nTitleIndex [in] Title��������
	* \retval Title����Ļ��
	*/
	virtual STDMETHODIMP_(int) GetTitleSubTitleCount(int nTitleIndex) = 0;

	/*! \fn virtual STDMETHODIMP		  GetSubTitleDesc(int nTitleIndex, int nSubTitleidx, BSTR *ppDescription)
	* \brief ��ȡָ����Ļ��������Ϣ
	* \param nTitleIndex [in] Title��������
	* \param nSubTitleidx [in] ��Ļ��������
	* \param ppDescription [in / out] ��Ļ��������Ϣ
	* \retval ��ȡ�Ľ��
	*/
	virtual STDMETHODIMP GetSubTitleDesc(int nTitleIndex, int nSubTitleidx, BSTR *ppDescription) = 0;

	/*! \fn virtual STDMETHODIMP_(WORD)   GetAudioTrackLang(int nTitleIndex, int nAudioTrackidx)
	* \brief ��ȡָ����������Ա��(ISO 639 language codes.)
	* \param nTitleIndex [in] Title��������
	* \param nAudioTrackidx [in] �����������
	* \retval ���Ա��
	*/
	virtual STDMETHODIMP_(WORD) GetAudioTrackLang(int nTitleIndex, int nAudioTrackidx) = 0;

	/*! \fn virtual STDMETHODIMP          GetAudioFormatDesc(int nTitleIndex, int nAudioTrackidx, BSTR *ppDescription)
	* \brief ��ȡָ���������Ƶ����("AC3", "MPEG1", "MPEG2x", "LPCM", "DTS")
	* \param nTitleIndex [in] Title��������
	* \param nAudioTrackidx [in] �����������
	* \param ppDescription [in / out] ��Ƶ����
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetAudioFormatDesc(int nTitleIndex, int nAudioTrackidx, BSTR *ppDescription) = 0;

	/*! \fn virtual STDMETHODIMP_(int)    GetAudioTrackID(int nTitleIndex, int nAudioTrackidx)
	* \brief ��ȡָ�������ID��(AC3 [0x80, 0x87]��  DTS [0x88, 0x8F]�� MPEG Audio [0xC0, 0xCF], LPCM [0xA0, 0xAF])
	* \param nTitleIndex [in] Title��������
	* \param nAudioTrackidx [in] �����������
	* \retval �����ID��
	*/
	virtual STDMETHODIMP_(int) GetAudioTrackID(int nTitleIndex, int nAudioTrackidx) = 0;

	/*! \fn virtual STDMETHODIMP_(int)     GetAudioChannel(int nTitleIndex, int nAudioTrackidx)
	* \brief ��ȡָ�������������
	* \param nTitleIndex [in] Title��������
	* \param nAudioTrackidx [in] �����������
	* \retval �����������
	*/
	virtual STDMETHODIMP_(int) GetAudioChannel(int nTitleIndex, int nAudioTrackidx) = 0;

	/*! \fn virtual STDMETHODIMP_(WORD)	  GetSubLangCode(int nTitleIndex, int nSubTitleidx)
	* \brief ��ȡָ����Ļ�����Ա��(ISO 639 language codes)
	* \param nTitleIndex [in] Title��������
	* \param nSubTitleidx [in] ��Ļ��������
	* \retval ��Ļ�����Ա��
	*/
	virtual STDMETHODIMP_(WORD) GetSubLangCode(int nTitleIndex, int nSubTitleidx) = 0;

	/*! \fn virtual STDMETHODIMP_(int)	  GetSubTitleTrackID(int nTitleIndex, int nSubTitleidx)
	* \brief ��ȡָ����Ļ��ID��([0x20, 0x3F])
	* \param nTitleIndex [in] Title��������
	* \param nSubTitleidx [in] ��Ļ��������
	* \retval ��Ļ��ID��
	*/
	virtual STDMETHODIMP_(int) GetSubTitleTrackID(int nTitleIndex, int nSubTitleidx) = 0;

	/*! \fn virtual STDMETHODIMP_(int)     GetTitleAvailable(int nTitleIndex)
	* \brief ��ȡָ����Title�Ƿ�����Ч��
	* \param nTitleIndex [in] Title��������
	* \retval 0��ʾ��Ч��1��ʾ��Ч
	*/
	virtual STDMETHODIMP_(int) GetTitleAvailable(int nTitleIndex) = 0;
};

/*!
* \class IISOInfo
* \brief ��ȡISO�ļ��еľ�������Լ�IFO����Ŀ 
*/

// {490F7DE8-FC4E-42af-9570-1433DB5FA847}
DEFINE_GUID(IID_ISOInfo, 
			0x490f7de8, 0xfc4e, 0x42af, 0x95, 0x70, 0x14, 0x33, 0xdb, 0x5f, 0xa8, 0x47);
EXTERN_C const IID IID_ISOInfo;
MACRO_MIDL_INTERFACE(IISOInfo, "490F7DE8-FC4E-42af-9570-1433DB5FA847")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(int) GetIFOCount()
	* \brief ��ȡISO��IFO�ļ�����Ŀ
	* \retval IFO�ļ�����Ŀ
	*/
	virtual STDMETHODIMP_(int) GetIFOCount() = 0;

	/*! \fn virtual STDMETHODIMP	   GetISOVolumeName(BSTR *ppVolumeName)
	* \brief ��ȡISO�ľ��
	* \param ppVolumeName [in / out] ISO�ľ��
	* \retval ISO�ľ��
	*/
	virtual STDMETHODIMP	   GetISOVolumeName(BSTR *ppVolumeName) = 0;	
};

/*!
* \class ICreateISOInfo
* \brief ͨ��ISO���ļ���,����IISOInfo�ӿ�ʵ��
*/

// {B66AB703-15E7-4e39-94E9-CEA64BBD5534}
DEFINE_GUID(IID_ICreateISOInfo, 
			0xb66ab703, 0x15e7, 0x4e39, 0x94, 0xe9, 0xce, 0xa6, 0x4b, 0xbd, 0x55, 0x34);
EXTERN_C const IID IID_ICreateISOInfo;
MACRO_MIDL_INTERFACE(ICreateISOInfo, "B66AB703-15E7-4e39-94E9-CEA64BBD5534")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(IISOInfo *) CreateISOInfo(const BSTR pISOPath)
	* \brief ͨ��ISO���ļ���,����IISOInfo�ӿ�ʵ��
	* \param pISOPath [in] ISO�ļ�·��
	* \retval IISOInfo�ӿ�ʵ��
	* \see IISOInfo
	*/
	virtual STDMETHODIMP_(IISOInfo *) CreateISOInfo(const BSTR pISOPath) = 0;	
};

// {A13F85D0-420C-4cf0-BD56-B6C1F101A99F}
MIDL_DEFINE_GUID(CLSID, CLSID_CCreateISOInfo, 0xa13f85d0, 0x420c, 0x4cf0, 0xbd, 0x56, 0xb6, 0xc1, 0xf1, 0x1, 0xa9, 0x9f);
EXTERN_C const CLSID CLSID_CCreateISOInfo;