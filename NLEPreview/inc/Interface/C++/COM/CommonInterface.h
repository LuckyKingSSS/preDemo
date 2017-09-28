
/*! \file CommonInterface.h
* \brief							������һЩ�ӿ��ļ����ܶ�ģ�鶼���õ���
* Detailed
* IVideoInput��IAudioInput��IVideoOutput��IAudioOutput�ӿ�����������Ƶ������Ƶ���ӿ�IMediaStream�������Լ���ȡ�����
* ��IVideoComposition�ӿ��⣬�����ӿڶ�����ͨ��QueryInterface��������ѯ��Щ�ӿڡ���ĳ�ӿ�֧����Ƶ�Ĵ�����ô���Բ�ѯ��IAudioInput�ӿڣ�
* �ýӿڵ�SetAudioInput����������������Ƶ���ӿ�IMediaStream�����룬 ��Ӧ�Ŀ��Բ�ѯ��IAudioOutput�ӿڣ��ýӿڵ�GetAudioOutput������
* ���ڻ�ȡ��Ƶ���ӿ�IMediaStream���������֧����Ƶ���ݴ�����ô���Բ�ѯ��IVideoInput�ӿڣ��ýӿڵ�SetVideoInput�ķ�����
* ����������Ƶ���ӿڵ����롣��Ӧ�Ŀ��Բ�ѯ��IVideoOutput�ӿڣ��ýӿ��ṩ��GetVideoOutput���������ڻ�ȡ��Ƶ���ӿ�IMediaStream�����
*/


#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "FileInfo.h"
#include "CodecFrame.h"

/*!
* \class IStreamInfo
* \brief ��ȡ����Ϣ 
*/

// {58FE100C-DCD4-49db-9930-326174CC0ECC}
DEFINE_GUID(IID_IStreamInfo, 
			0x58fe100c, 0xdcd4, 0x49db, 0x99, 0x30, 0x32, 0x61, 0x74, 0xcc, 0xe, 0xcc);
EXTERN_C const IID IID_IID_IStreamInfo;
MACRO_MIDL_INTERFACE(IStreamInfo, "58FE100C-DCD4-49db-9930-326174CC0ECC")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP_(AV_STREAM_TYPE) GetType(void)
	* \brief ��ȡ������
	* \retval ������
	* \see AV_STREAM_TYPE
	*/
	virtual STDMETHODIMP_(AV_STREAM_TYPE) GetType(void) = 0;

	/*! \fn virtual STDMETHODIMP_(UINT) GetID(void)
	* \brief ��ȡ��ID
	* \retval ��ID
	*/
	virtual STDMETHODIMP_(UINT) GetID(void) = 0;

	/*! \fn virtual STDMETHODIMP_(UINT) GetFourCC(void)
	* \brief ��ȡ��FourCC
	* \retval ��FourCC
	*/
	virtual STDMETHODIMP_(UINT) GetFourCC(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetState(void)
	* \brief  0 - ����  -1 �Ҳ���dwFourCC��Ӧ�Ľ�����
	* \retval ������״̬
	*/
	virtual STDMETHODIMP_(int) GetState(void) = 0;

	/*! \fn virtual STDMETHODIMP GetName(BSTR * ppStreamName)
	* \brief  ��ȡ��������
	* \param  ppStreamName [in / out] ��������
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetName(BSTR * ppStreamName) = 0;

	/*! \fn virtual STDMETHODIMP GetDescription(BSTR * ppDescription)
	* \brief  ��ȡ����������Ϣ
	* \param  ppDescription [in / out] ����������Ϣ
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetDescription(BSTR * ppDescription) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetLength(void)
	* \brief  ��ȡ���Ĳ���ʱ��
	* \retval ���Ĳ���ʱ��
	*/
	virtual STDMETHODIMP_(double) GetLength(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetBitRate(void)
	* \brief  ��ȡ��������
	* \retval ��������
	*/
	virtual STDMETHODIMP_(int) GetBitRate(void) = 0;

	/*! \fn virtual STDMETHODIMP_(const WSAudioInfo *) GetAudioInfo(void)
	* \brief  ��ȡ������Ƶ��Ϣ
	* \retval ������Ƶ��Ϣ
	* \see WSAudioInfo
	*/
	virtual STDMETHODIMP_(const WSAudioInfo *) GetAudioInfo(void) = 0;

	/*! \fn virtual STDMETHODIMP_(const WSVideoInfo *) GetVideoInfo(void)
	* \brief  ��ȡ������Ƶ��Ϣ
	* \retval ������Ƶ��Ϣ
	* \see WSVideoInfo
	*/
	virtual STDMETHODIMP_(const WSVideoInfo *) GetVideoInfo(void) = 0;

	/*! \fn virtual STDMETHODIMP_(__int64) GetStartPTS(void)
	* \brief  ��ȡ���Ŀ�ʼʱ���
	* \retval ���Ŀ�ʼʱ���
	*/
	virtual STDMETHODIMP_(__int64) GetStartPTS(void) = 0;

	/*! \fn virtual STDMETHODIMP_(__int64) GetPTSOffset(void)
	* \brief  ��ȡ��ǰ�����Ŀ�Ŀ�ʼʱ���֮��
	* \retval ��ǰ�����Ŀ�Ŀ�ʼʱ���֮��
	*/
	virtual STDMETHODIMP_(__int64) GetPTSOffset(void) = 0;
};

/*!
* \class IStreamInfoSrc
* \brief ��ȡ����Ϣԭʼ��Ϣ 
*/

// {A9AF814A-6F97-4a81-9453-4070EEC761BB}
DEFINE_GUID(IID_IStreamInfoSrc, 
			0xa9af814a, 0x6f97, 0x4a81, 0x94, 0x53, 0x40, 0x70, 0xee, 0xc7, 0x61, 0xbb);
EXTERN_C const IID IID_IID_IStreamInfoSrc;
MACRO_MIDL_INTERFACE(IStreamInfoSrc, "A9AF814A-6F97-4a81-9453-4070EEC761BB")
: public IUnknown
{
	/*! \fn virtual STDMETHODIMP_(const WSVideoInfo *) GetVideoSrcInfo(void)
	* \brief  ��ȡ����ԭʼ��Ƶ��Ϣ
	* \retval ������Ƶ��Ϣ
	* \see WSVideoInfo
	*/
	virtual STDMETHODIMP_(const WSVideoInfo *) GetVideoSrcInfo(void) = 0;

	/*! \fn virtual STDMETHODIMP GetIPrograms(IProgramInfos **ppProgramInfos)
	* \brief ��ȡ��������ɨ����Ϣ
	* \retval ��ȡ���
	* \see IProgramInfos
	*/
	virtual STDMETHODIMP_(AV_SCAN_TYPE) GetScanType() = 0;

	/*! \fn virtual STDMETHODIMP GetIPrograms(IProgramInfos **ppProgramInfos)
	* \brief ��ȡ��������ɨ���ԭʼ��Ϣ
	* \retval ��ȡ���
	* \see IProgramInfos
	*/
	virtual STDMETHODIMP_(AV_SCAN_TYPE) GetSrcScanType() = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetSrcRotate() = 0;
	* \brief ��ȡɨ���ԭʼ��Ƶ��ת��Ϣ
	* \retval ��ȡ���
	* \see IProgramInfos
	*/
	virtual STDMETHODIMP_(int) GetSrcRotate() = 0;

};
/*!
* \class IMediaStream
* \brief ��ȡ����Ϣ 
*/
// {E6C172B0-6D74-438f-81E0-433D92B2A627}
DEFINE_GUID(IID_IMediaStream, 
			0xe6c172b0, 0x6d74, 0x438f, 0x81, 0xe0, 0x43, 0x3d, 0x92, 0xb2, 0xa6, 0x27);
EXTERN_C const IID IID_IMediaStream;
MACRO_MIDL_INTERFACE(IMediaStream, "E6C172B0-6D74-438f-81E0-433D92B2A627")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP GetStreamInfo(IStreamInfo** ppStreamInfo)
	* \brief  ��ȡ��ǰ������Ϣ
	* \param ppStreamInfo [in / out] �������Ϣ�ӿ�
	* \retval ��ȡ���
	* \see IStreamInfo 
	*/
	virtual STDMETHODIMP GetStreamInfo(IStreamInfo** ppStreamInfo) = 0;

	/*! \fn virtual STDMETHODIMP ChangeStream(int nStreamID)
	* \brief  �任һ·��
	* \param nStreamID [in] ����ID
	* \retval �任���
	*/
	virtual STDMETHODIMP ChangeStream(int nStreamID) = 0;

	/*! \fn virtual STDMETHODIMP_(double) Seek(double dTime, int accurate)
	* \brief  ��������Seek
	* \param dTime [in] seek��ʱ���
	* \param accurate [in] �Ƿ�ȷseek
	* \retval seek�Ľ��
	*/
	virtual STDMETHODIMP_(double) Seek(double dTime, int accurate) = 0;

	/*! \fn virtual STDMETHODIMP_(MEDIA_FRAME *) GetSample(void)
	* \brief  ��ȡ��ǰ��֡(��Ƶ) �� Sample(��Ƶ)
	* \retval ��ȡ�Ľ��
	* \see MEDIA_FRAME
	* \note ������ΪNULL����ô�����ļ��������
	*/
	virtual STDMETHODIMP_(MEDIA_FRAME *) GetSample(void) = 0;

	/*! \fn virtual STDMETHODIMP_(int) Forward(void)
	* \brief  ǰ����һ֡(��Ƶ) �� ��һ��Sample (��Ƶ)
	* \retval 1 ��ʾ��ǰ��һ֡��0��ʾ�������
	*/
	virtual STDMETHODIMP_(int) Forward(void) = 0;

	/*! \fn virtual STDMETHODIMP_(double) GetOffset(void)
	* \brief  ��ȡ��ǰ������ȡ�
	* \retval �������(��ǰ����ʱ��)
	*/
	virtual STDMETHODIMP_(double) GetOffset(void) = 0;
};

/*!
* \class IVideoInput
* \brief ������Ƶ��������
*/
// {8F310739-7304-4fb9-B4C4-FF7B3B48D98E}
DEFINE_GUID(IID_IVideoInput, 
			0x8f310739, 0x7304, 0x4fb9, 0xb4, 0xc4, 0xff, 0x7b, 0x3b, 0x48, 0xd9, 0x8e);
EXTERN_C const IID IID_IVideoInput;
MACRO_MIDL_INTERFACE(IVideoInput, "8F310739-7304-4fb9-B4C4-FF7B3B48D98E")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP SetVideoInput(IMediaStream* pMediaStream) 
	* \brief  ������Ƶ�������롤
	* \param pMediaStream [in] ��Ƶ��
	* \retval ���ý��
	* \see IMediaStream
	*/
	virtual STDMETHODIMP SetVideoInput(IMediaStream* pMediaStream) = 0;
};

/*!
* \class IVideoOutput
* \brief ��ȡ��Ƶ�������
*/
// {30D4D994-A15B-4c2e-8277-66D0A8AA1B4F}
DEFINE_GUID(IID_IVideoOutput, 
			0x30d4d994, 0xa15b, 0x4c2e, 0x82, 0x77, 0x66, 0xd0, 0xa8, 0xaa, 0x1b, 0x4f);
EXTERN_C const IID IID_IVideoOutput;
MACRO_MIDL_INTERFACE(IVideoOutput, "30D4D994-A15B-4c2e-8277-66D0A8AA1B4F")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP GetVideoOutput(IMediaStream** ppMediaStream)
	* \brief  ��ȡ��Ƶ���������
	* \param ppMediaStream [in / out] ��Ƶ��
	* \retval ��ȡ���
	* \see IMediaStream
	*/
   virtual STDMETHODIMP GetVideoOutput(IMediaStream** ppMediaStream) = 0;
};

/*!
* \class IAudioInput
* \brief ������Ƶ��������
*/
// {89314327-F161-4483-A0EE-AFA455E825EA}
DEFINE_GUID(IID_IAudioInput, 
			0x89314327, 0xf161, 0x4483, 0xa0, 0xee, 0xaf, 0xa4, 0x55, 0xe8, 0x25, 0xea);
EXTERN_C const IID  IID_IAudioInput;
MACRO_MIDL_INTERFACE(IAudioInput, "89314327-F161-4483-A0EE-AFA455E825EA")
: public IUnknown
{
public:

	/*! \fn virtual STDMETHODIMP SetAudioInput(IMediaStream* pMediaStream)
	* \brief  ������Ƶ�������롤
	* \param pMediaStream [in] ��Ƶ��
	* \retval ���ý��
	* \see IMediaStream
	*/
	virtual STDMETHODIMP SetAudioInput(IMediaStream* pMediaStream) = 0;
};

/*!
* \class IAudioOutput
* \brief ��ȡ��Ƶ�������
*/
// {29B857F5-9C9F-4586-85EA-BDE2F1F178F1}
DEFINE_GUID(IID_IAudioOutput, 
			0x29b857f5, 0x9c9f, 0x4586, 0x85, 0xea, 0xbd, 0xe2, 0xf1, 0xf1, 0x78, 0xf1);
EXTERN_C const IID IID_IAudioOutput;
MACRO_MIDL_INTERFACE(IAudioOutput, "29B857F5-9C9F-4586-85EA-BDE2F1F178F1")
: public IUnknown
{
public:

	/*! \fn  virtual STDMETHODIMP GetAudioOutput(IMediaStream** ppMediaStream)
	* \brief  ��ȡ��Ƶ���������
	* \param ppMediaStream [in / out] ��Ƶ��
	* \retval ��ȡ���
	* \see IMediaStream
	*/
   virtual STDMETHODIMP GetAudioOutput(IMediaStream** ppMediaStream) = 0;	
};


/************************************************************************/
/*						DIBImage�ӿ��Լ����						    */
/************************************************************************/
// {2E1ADF80-6F97-47f5-A3AA-9EB80EE12D3F}

/*!
* \class IDibImage
* \brief ��ȡλͼ��Ϣ
*/
DEFINE_GUID(IID_IDibImage, 
			0x2e1adf80, 0x6f97, 0x47f5, 0xa3, 0xaa, 0x9e, 0xb8, 0xe, 0xe1, 0x2d, 0x3f);
EXTERN_C const IID IID_IDibImage;
MACRO_MIDL_INTERFACE(IDibImage, "2E1ADF80-6F97-47f5-A3AA-9EB80EE12D3F")
: public IUnknown
{
public:

	/*! \fn  virtual STDMETHODIMP_(int) GetWidth(void)
	* \brief  ��ȡλͼ��ȡ�
	* \retval λͼ���
	*/
	virtual STDMETHODIMP_(int) GetWidth(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetHeight(void)
	* \brief  ��ȡλͼ�߶ȡ�
	* \retval λͼ�߶�
	*/
	virtual STDMETHODIMP_(int) GetHeight(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetBitCount(void) = 0
	* \brief  Get the number of bits that define each pixel and the maximum number of colors in the bitmap��
	* \retval bits count
	*/
	virtual STDMETHODIMP_(int) GetBitCount(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetImageSize(void)
	* \brief ��ȡλͼ�Ĵ�С
	* \retval λͼ�Ĵ�С
	*/
	virtual STDMETHODIMP_(int) GetImageSize(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetPitch(void)
	* \brief ��ȡλͼ��ÿһ�е�������
	* \retval λͼ��ÿһ�е�������
	*/
	virtual STDMETHODIMP_(int) GetPitch(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(const LPBITMAPINFO) GetBitmapInfo(void)
	* \brief ��ȡλͼ��Ϣ
	* \retval λͼ��Ϣ
	*/
	virtual STDMETHODIMP_(const LPBITMAPINFO) GetBitmapInfo(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(const LPBYTE) GetBits(void)
	* \brief ��ȡλͼ���ݵ��׵�ַ
	* \retval λͼ���ݵ��׵�ַ
	*/
	virtual STDMETHODIMP_(const LPBYTE) GetBits(void) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetHeaderSize(void)
	* \brief ��ȡλͼ��Ϣ�Ľṹ���С
	* \retval λͼ��Ϣ�Ľṹ���С
	*/
	virtual STDMETHODIMP_(int) GetHeaderSize(void) = 0;
};