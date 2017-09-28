/*! \file SlideDecoder.h
* \brief							��Ƶ���ӽӿڵ���˵��
* Detailed
* ��Ƶ���ӵ���Ҫ�����ǣ�������Ķ���ļ�������ʱ������ۼӣ�ͬʱ��������Ƶ��ʹ�����������Ƶʱ����������ģ�ͬ���ġ�
* ��Ƶ���ӽӿڷ�Ϊ������ISlideDecoder���ϸ���TrimFrom, TrimeTo��ʱ����л����ݣ�ʵ������Ƶ�Ķ��룬�Լ�ʱ������ۼӣ�
* ��������ʵ�ַ�ʽ�и�ȱ���ǣ����ʱ���ȡ������ô�ᶪʧ���ݣ��򲹺�֡��
* Ϊ�˽��������⣬ʵ����ISlideDecoderEX�ӿڣ��ýӿ�ʵ��������Ƶ�໥�ο�������������TrimFrom, TrimeTo��ʱ�䣬���������ʱ�䲻
* ׼ȷ�����µ����⡣ 
* ����ʹ��ISlideDecoderEX�ӿ�
*/

#pragma once
#include "CommonInterface.h"
#include "scombase.h"
#include "COMMacro.h"
#include "VideoSlideParam.h"
#include "AudioSlideParam.h"
#include "WSVideoInfo.h"
#include "WSAudioInfo.h"


//////////////////////////////////////////////////////////////////////////
//2009-03-02 Add Begin
//�ڶ��ν����ļ��ϲ����Ż�
/************************************************************************
���ܣ���Ƶ�ص�����
������pUserObj [OUT]���ûص�������ʹ��ָ���ķ��ض���ָ��
pUserClipObj [OUT]��Ӧ��Clip����ָ��
nOptFlag [OUT]������־��nOptFlag=1��Ҫ�򿪣�nOptFlag=0��Ҫ�ر�	
���أ�����VideoProcess������
˵��������ص������ӿڣ����ϲ��ļ���ʱ�������������Ҫ�򿪺͹رյ�ʱ�����
�������������Ч�ʡ���Ҫע����Ƿ��ص�VideoProcess���ⲿά��������
************************************************************************/
typedef IMediaStream *(__stdcall * SDEXVideoCallBack)(LPVOID pUserObj, LPVOID pUserClipObj, UINT nOptFlag);

/************************************************************************
���ܣ���Ƶ�ص�����
������ͬ����Ƶ����
���أ�����AudioProcess������
˵��������ص������ӿڣ����ϲ��ļ���ʱ�������������Ҫ�򿪺͹رյ�ʱ�����
�������������Ч�ʡ���Ҫע����Ƿ��ص�AudioProcess���ⲿά��������
************************************************************************/
typedef IMediaStream *(__stdcall * SDEXAudioCallBack)(LPVOID pUserObj, LPVOID pUserClipObj, UINT nOptFlag);


/*!
* \class ISlideDecoder
* \brief ��Ƶ���ӽӿ� 
*/

// {3DDBBF17-D26F-4fd5-90B4-347C519C3A0D}
DEFINE_GUID(IID_ISlideDecoder, 
			0x3ddbbf17, 0xd26f, 0x4fd5, 0x90, 0xb4, 0x34, 0x7c, 0x51, 0x9c, 0x3a, 0xd);
EXTERN_C const IID IID_ISlideDecoder;
MACRO_MIDL_INTERFACE(ISlideDecoder, "3DDBBF17-D26F-4fd5-90B4-347C519C3A0D")
: public IUnknown
{
public:
	
	/*! \fn virtual STDMETHODIMP SetVideoParam(const VideoSlideParam * pParam, LPVOID pUserObj, SDEXVideoCallBack fnCBVideo)
	* \brief ������Ƶ�������Լ��ص��������ûص��������ڣ�Ӧ�ò㴴����Ƶ�������������ײ�
	* \param pParam [in] ��Ƶ������Ϊ�������Ƶ���ݵĲ�����Ϣ
	* \param pUserObj [in] �ص�������ʹ���߲���
	* \param fnCBVideo [in] �ص���������ָ��
	* \retval HRESULT ���õĽ��
	* \warning Ҫ����Ƶ�����ͼ����������VideoSlideParam�������ã��������������Ƶ��ͬ������������
	*/
	virtual STDMETHODIMP SetVideoParam(const VideoSlideParam * pParam, LPVOID pUserObj, SDEXVideoCallBack fnCBVideo) = 0;

	/*! \fn virtual STDMETHODIMP_(const VideoSlideParam *) GetVideoParam(void)
	* \brief ��ȡ���ý�����Ƶ����
	* \retval ���ý�����Ƶ����
	*/
	virtual STDMETHODIMP_(const VideoSlideParam *) GetVideoParam(void) = 0;

	/*! \fn virtual STDMETHODIMP AddVideoClip(IMediaStream *pMediaStream, const WSVideoInfo * pVideoInfo, const CLIP_TIME * pClipTime, LPVOID pUserClipObj)
	* \brief ����һ����ƵƵԴ���䴦������������á����ȶԱȶȵ��ڡ���Ч���õȣ�����ε��ü�����������ƵԴ
	* \param pMediaStream [in] Slide��������Ƶ�������ӿ�
	* \param pVideoInfo [in] ������Ƶ���ݲ���
	* \param pClipTime [in] ������Ϣ
	* \param pUserClipObj [in] ���б�ʶ
	* \retval HRESULT ���õĽ��
	*/
	virtual STDMETHODIMP AddVideoClip(IMediaStream *pMediaStream, const WSVideoInfo * pVideoInfo, const CLIP_TIME * pClipTime, LPVOID pUserClipObj) = 0;

	/*! \fn virtual STDMETHODIMP SetAudioParam(const AudioSlideParam * pParam, LPVOID pUserObj, SDEXAudioCallBack fnCBAudio)
	* \brief ������Ƶ�������Լ��ص��������ûص��������ڣ�Ӧ�ò㴴����Ƶ�������������ײ�
	* \param pParam [in] ��Ƶ������Ϊ�������Ƶ���ݵĲ�����Ϣ
	* \param pUserObj [in] �ص�������ʹ���߲���
	* \param fnCBAudio [in] �ص���������ָ��
	* \retval HRESULT ���õĽ��
	* \warning Ҫ����Ƶ�������Ƶ��������AudioSlideParam�������ã��������������Ƶ��ͬ������������
	*/
	virtual STDMETHODIMP SetAudioParam(const AudioSlideParam * pParam, LPVOID pUserObj, SDEXAudioCallBack fnCBAudio) = 0; 

	/*! \fn virtual STDMETHODIMP_(const AudioSlideParam *) GetAudioParam(void)
	* \brief ��ȡ���ý�����Ƶ����
	* \retval ���ý�����Ƶ����
	*/
	virtual STDMETHODIMP_(const AudioSlideParam *) GetAudioParam(void) = 0;

	/*! \fn virtual STDMETHODIMP AddAudioClip(IMediaStream *pMediaStream, const WSAudioInfo * pAudioInfo, const CLIP_TIME * pClipTime, LPVOID pUserClipObj)
	* \brief ����һ����ƵԴ���䴦������������á����ȶԱȶȵ��ڡ���Ч���õȣ�����ε��ü�����������ƵԴ
	* \param pMediaStream [in] Slide��������Ƶ�������ӿ�
	* \param pAudioInfo [in] ������Ƶ���ݲ���
	* \param pClipTime [in] ������Ϣ
	* \param pUserClipObj [in] ���б�ʶ
	* \retval HRESULT ���õĽ��
	*/
	virtual STDMETHODIMP AddAudioClip(IMediaStream *pMediaStream, const WSAudioInfo * pAudioInfo, const CLIP_TIME * pClipTime, LPVOID pUserClipObj) = 0;
};


/*!
* \class IClipTimeItem
* \brief ���ü�����Ϣ 
*/
DEFINE_GUID(IID_IClipTimeItem, 
					0x390235be, 0xc389, 0x4d58, 0xb1, 0x4b, 0x72, 0x47, 0x4d, 0x96, 0xe7, 0x58);
EXTERN_C const IID IID_IClipTimeItem;
MACRO_MIDL_INTERFACE(IClipTimeItem, "390235BE-C389-4d58-B14B-72474D96E758") 
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP SetClipTime(const CLIP_TIME * pClipTime)
	* \brief ���ü�����Ϣ
	* \param pClipTime [in] ���в���
	* \retval ���ý��
	* \see CLIP_TIME
	*/
	virtual STDMETHODIMP SetClipTime(const CLIP_TIME * pClipTime) = 0;

	/*! \fn virtual STDMETHODIMP_(const CLIP_TIME *) GetClipTime()
	* \brief ��ȡ��ǰ���õļ�����Ϣ
	* \retval ���в���
	* \see CLIP_TIME
	*/
	virtual STDMETHODIMP_(const CLIP_TIME *) GetClipTime() = 0;

	/*! \fn virtual STDMETHODIMP SetFileLength(const double dFileLength)
	* \brief ������Ƶ�ļ���ԭʼ��ʱ����
	* \param dFileLength [in] �ļ�ʱ��
	* \retval ���ý��
	* \note ��TrimTo ���� dFileLengthʱ������û�ж��ļ�β���м��У���ô���ο�TrimTo��ʱ�䣬
	*       ���TrimTo < dFileLength���������ļ�β�����˼��У���ô������Ƶ����ʱ���ݣ�����TrimTo����Ϣ���м���
	* \warning �ǳ���Ҫ����������ã����ʱ����ȡ��ʵ�ʵ�С����ô����TrimTo���������ᵼ�¶�ʧ����
	*/
	virtual STDMETHODIMP SetFileLength(const double dFileLength) = 0;
	
	/*! \fn virtual STDMETHODIMP_(double) GetFileLength()
	* \brief ��ȡ��ǰ���õ��ļ�ʱ��
	* \retval ��ǰ���õ��ļ�ʱ��
	*/
	virtual STDMETHODIMP_(double) GetFileLength() = 0;

	/*! \fn virtual STDMETHODIMP SetUserClipObject(LPVOID pUserObj)
	* \brief ����Clip�û����
	* \param pUserObj [in] Clip�û����
	* \retval ���õĽ��
	*/
	virtual STDMETHODIMP SetUserClipObject(LPVOID pUserObj) = 0;

	/*! \fn virtual STDMETHODIMP_(LPVOID) GetUserClipObject()
	* \brief ��ȡ��ǰ���õ�Clip�û����
	* \retval ��ǰ���õ�Clip�û����
	*/
	virtual STDMETHODIMP_(LPVOID) GetUserClipObject() = 0;
};

/*!
* \class IClipTime
* \brief IClipTimeItemö����
*/
// {8088E13D-9B88-4f48-86C6-1F0A83AA0FE0}
DEFINE_GUID(IID_IClipTime, 
					0x8088e13d, 0x9b88, 0x4f48, 0x86, 0xc6, 0x1f, 0xa, 0x83, 0xaa, 0xf, 0xe0);
EXTERN_C const IID IID_IClipTime;
MACRO_MIDL_INTERFACE(IClipTime, "8088E13D-9B88-4f48-86C6-1F0A83AA0FE0")
:public IUnknown
{
	public:

	/*! \fn virtual STDMETHODIMP Add(IClipTimeItem **ppClipTimetem)
	* \brief ���һ��Clip��Ϣ��
	* \param ppClipTimetem [in /out] ����һ��IClipTimeItem�ӿ�ʵ�����
	* \retval ��ȡ���
	* \warning ʹ����Ϻ���ص���release�����ͷ���Դ
	* \see IClipTimeItem
	*/
	virtual STDMETHODIMP Add(IClipTimeItem **ppClipTimetem) = 0;

	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ��ȡ��ӽ���Clip�������
	* \retval ��ӽ���Clip�������
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;

	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IClipTimeItem **ppClipTimetem)
	* \brief ��ȡһ��ָ����Clip��Ϣ��
	* \param nIndex [in] ָ������Ϣ�������
	* \param ppClipTimetem [in /out] ��ȡ��nIndex��Ӧ��IClipTimeItem�ӿ�ʵ�����
	* \retval ��ȡ���
	* \note ��ȡʧ�ܣ���ô���*ppClipTimetemΪNULL 
	* \warning ʹ����Ϻ���ص���release�����ͷ���Դ
	* \see IClipTimeItem
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IClipTimeItem **ppClipTimetem) = 0;

	/*! \fn virtual STDMETHODIMP Remove(IClipTimeItem* pClipTimetem, int *pIndex)
	* \brief �Ƴ�һ��ָ����Clip��Ϣ��
	* \param pClipTimeItem [in] Ҫ�Ƴ���Clip��Ϣ��ӿ�ʵ��ָ��
	* \param pIndex [in /out] ���ظ�ʵ��ָ�����б��е�������
	* \retval �Ƴ����
	*/
	virtual STDMETHODIMP Remove(IClipTimeItem *pClipTimeItem, int *pIndex) = 0;

	/*! \fn virtual STDMETHODIMP Clear()
	* \brief �Ƴ����е�Clip��Ϣ��
	* \retval �Ƴ����
	*/
	virtual STDMETHODIMP Clear() = 0;
};

/*!
* \class ISlideDecoderEX
* \brief �Ľ������Ƶ���ӽӿ�
* Detailed ���������Ƶ���������ɻص�����������ͨ��QueryInerface��ѯIVideoOutput, IAudioOutput�ӿڣ���ȡ����Ƶ���ӿ�IMediaStream�������
* ��ģ��ӿ�ֻ���Convertģ��ʹ�ã� ����������;�������з�������ϵ����ģ���������Ƶ��Ƶ����Ӧ����DataProcessģ�飬����ͼ�����ţ��ز����������任��ƽ��ʱ�������
* ������ܵ����������Ƶ��ͬ����
*/
DEFINE_GUID(IID_ISlideDecoderEX, 
			0xafd00486, 0x9c35, 0x4e93, 0x80, 0x87, 0xa7, 0x3e, 0x78, 0x34, 0x53, 0xe7);
EXTERN_C const IID IID_ISlideDecoderEX;
MACRO_MIDL_INTERFACE(ISlideDecoderEX, "AFD00486-9C35-4e93-8087-A73E783453E7")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP SetParam(const VideoSlideParam * pVideoParam, const AudioSlideParam * pAudioParam)
	* \brief ��������Ƶ����
	* \param pVideoParam [in] ��Ƶ����
	* \param pAudioParam [in] ��Ƶ����
	* \retval ���ý��
	* \note ����Ƶ��������ͬʱΪ�գ� ��pVideoParamΪ����ô�����������Ƶ���� ��pAudioParamΪ�գ���ô�������Ƶ��
	* \see VideoSlideParam AudioSlideParam 
	*/
	virtual STDMETHODIMP SetParam(const VideoSlideParam * pVideoParam, const AudioSlideParam * pAudioParam) = 0;

	/*! \fn virtual STDMETHODIMP GetClipTimeSetting(IClipTime **ppClipTime)
	* \brief ��ȡClip��Ϣ����ö����
	* \param ppClipTime [in / Out] Clip��Ϣö�����ӿ�ʵ��
	* \retval ��ȡ���
	* \warning ʹ����Ϻ������Release�������ͷŽӿ�
	* \see IClipTime 
	*/
	virtual STDMETHODIMP GetClipTimeSetting(IClipTime **ppClipTime) = 0;

	/*! \fn virtual STDMETHODIMP SetVideoCallBack(SDEXVideoCallBack fnCBVideo, LPVOID pUserObj)
	* \brief ���ô�����Ƶ��IMediaStream�ӿڵĻص���������ָ�룬�Լ������߾��
	* \param fnCBVideo [in] ������Ƶ��IMediaStream�ӿڵĻص���������ָ��
	* \param pUserObj [in] �����߾��
	* \retval ���ý��e 
	*/
	virtual STDMETHODIMP SetVideoCallBack(SDEXVideoCallBack fnCBVideo, LPVOID pUserObj) = 0;

	/*! \fn virtual STDMETHODIMP_(const VideoSlideParam *) GetVideoParam(void)
	* \brief ��ȡ��ǰ����Ƶ����
	* \retval ��Ƶ����e
	* \see VideoSlideParam
	*/
	virtual STDMETHODIMP_(const VideoSlideParam *) GetVideoParam(void) = 0;

	/*! \fn virtual STDMETHODIMP SetAudioCallBack(SDEXAudioCallBack fnCBAudio, LPVOID pUserObj)
	* \brief ���ô�����Ƶ��IMediaStream�ӿڵĻص���������ָ�룬�Լ������߾��
	* \param fnCBAudio [in] ������Ƶ��IMediaStream�ӿڵĻص���������ָ��
	* \param pUserObj [in] �����߾��
	* \retval ���ý��e 
	*/
	virtual STDMETHODIMP SetAudioCallBack(SDEXAudioCallBack fnCBAudio, LPVOID pUserObj) = 0;

	/*! \fn virtual STDMETHODIMP_(const AudioSlideParam *) GetAudioParam(void)
	* \brief ��ȡ��ǰ����Ƶ����
	* \retval ��Ƶ����e
	* \see AudioSlideParam
	*/
	virtual STDMETHODIMP_(const AudioSlideParam *) GetAudioParam(void) = 0;
};

//�����������MediaPlayer
MIDL_DEFINE_GUID(CLSID, CLSID_CSlideDecode, 0x21c7bb8b, 0x657a, 0x46fb, 0x86, 0xe5, 0xa4, 0x39, 0x96, 0xa, 0xd0, 0x4);

EXTERN_C const CLSID CLSID_CSlideDecode;