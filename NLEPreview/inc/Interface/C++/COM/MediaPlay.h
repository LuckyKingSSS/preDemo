
/*! \file MediaPlay.h
* \brief							���������ֽӿ�˵��
* Detailed
*�������ӿ��ṩ�˲��ſ��ƹ��ܣ��Լ����ö����Ƶ��ʾView�� Ϊ��������Ƶ�����룬ͨ����ѯ�ӿ�IAudioInputʵ�֡�
*Ϊ��ʵ��˫��������ͨ��IMediaPlay�ӿڵ�GetPlayerViewMgr������ȡIPlayViewMgr�ӿڣ�ͨ����CreatePlayView������
*��Ӷ��View������ÿ��View��ͨ��IPlayerView�ӿڵ�SetVideoInput��ʽ�����ø�View����Ƶ������ӿڣ���ָ�������Ƿ���ԭʼ����
*ͨ��SetParentWND������������Ƶ��ʾ���ڡ�SetRect������Ƶ��ʾ����
*/
#pragma once
#include <scombase.h>
#include "COMMacro.h"
#include "CommonInterface.h"
#include "CallBack.h"
#include "WSPlayer.h"

/*!
* \class IPlayerView
* \brief PlayerView�ӿ� 
*/

// {8E7CE0D9-BF91-4e4f-AF9A-E25C6D9A2C12}
DEFINE_GUID(IID_IPlayerView, 
			0x8e7ce0d9, 0xbf91, 0x4e4f, 0xaf, 0x9a, 0xe2, 0x5c, 0x6d, 0x9a, 0x2c, 0x12);
EXTERN_C const IID IID_IPlayerView;
MACRO_MIDL_INTERFACE(IPlayerView, "8E7CE0D9-BF91-4e4f-AF9A-E25C6D9A2C12")
: public IUnknown
{
public:
	/*! \fn STDMETHODIMP SetVideoInput(int bSource, IMediaStream* pMediaStream)
	* \brief ������Ƶ������
	* \param bSource [in] ���õ�Դ���� 0 ��Դ��Ƶ�� 1 Դ��Ƶ�� 
	* \param pMediaStream [in] ���õ���Ƶ��
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetVideoInput(int bSource, IMediaStream* pMediaStream) = 0;
	/*! \fn STDMETHODIMP SetParentWND(HVIEW parent)
	* \brief ������Ƶ��ʾ���ڸ��ŵĸ�����
	* \param parent [in] ������Ƶ��ʾ���ڸ��ŵĸ�����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetParentWND(HVIEW parent) = 0;
	/*! \fn virtual STDMETHODIMP_(HVIEW) GetParentWND(void)
	* \brief �õ���Ƶ��ʾ���ڸ��ŵĸ�����
	* \retval  ��Ƶ��ʾ���ڸ��ŵĸ�����
	*/
	virtual STDMETHODIMP_(HVIEW) GetParentWND(void) = 0;
	/*! \fn STDMETHODIMP SetParentWND(HVIEW parent)
	* \brief ������Ƶ��ʾ����
	* \param rect [in] ���õ���Ƶ����ʾ����
	* \retval  ���ý��
	*/
	virtual STDMETHODIMP SetRect(const RECT & rect) = 0;
	/*! \fn virtual STDMETHODIMP_(RECT) GetRect(void)
	* \brief �õ���Ƶ��ʾ����
	* \retval  ��Ƶ��ʾ����
	*/
	virtual STDMETHODIMP_(RECT) GetRect(void) = 0;
	/*! \fn virtual STDMETHODIMP_(int)	GetIndex() 
	* \brief �õ�playview������
	* \retval  playview������
	*/
	virtual STDMETHODIMP_(int)	GetIndex() = 0;
	/*! \fn virtual STDMETHODIMP_(HSUBVIEW) GetWND(void)
	* \brief �õ���Ƶ��ʾ����
	* \retval  ��Ƶ��ʾ���� 
	*/
	virtual STDMETHODIMP_(HSUBVIEW) GetWND(void) = 0;
};

/*!
* \class IPlayerViewMgr
* \brief PlayerView�������ӿ� 
*/

// {08E9EED2-63E7-4895-9C46-8577AD7745CC}
DEFINE_GUID(IID_IPlayerViewMgr, 
			0x8e9eed2, 0x63e7, 0x4895, 0x9c, 0x46, 0x85, 0x77, 0xad, 0x77, 0x45, 0xcc);
EXTERN_C const IID IID_IPlayerViewMgr;
MACRO_MIDL_INTERFACE(IPlayerViewMgr, "08E9EED2-63E7-4895-9C46-8577AD7745CC")
: public IUnknown
{
public:
	/*! \fn virtual STDMETHODIMP_(IPlayerView *) CreatePlayView(HVIEW parentWND, const RECT & rect)
	* \brief ����һ���µ�playview
	* \param parentWND [in] ��Ƶ��ʾ���ڸ��ŵĸ�����
	* \param rect [in] ��Ƶ����ʾ����
	* \retval  playview�ӿ� 
	*/
	virtual STDMETHODIMP_(IPlayerView *) CreatePlayView(HVIEW parentWND, const RECT & rect) = 0;
	/*! \fn virtual STDMETHODIMP_(int) GetCount(void)
	* \brief ���playview����Ŀ
	* \retval  playview����Ŀ 
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;
	/*! \fn virtual STDMETHODIMP Remove(int nIndex)
	* \brief �Ƴ�ָ������ֵ��playview
	* \param nIndex [in] ���Ƴ�playview������
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Remove(int nIndex) = 0;
	/*! \fn virtual STDMETHODIMP GetItem(int nIndex, IPlayerView** ppPlayerView)
	* \brief �õ�ָ������ֵ��playview�ӿ�
	* \param nIndex [in] playview��ָ������
	* \param ppPlayerView [out] playview�Ľӿ�
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IPlayerView** ppPlayerView) = 0;
};


/*!
* \class IMediaPlayer
* \brief �������ӿ� 
*/

struct CaptureImageInfo ;
// {05A20FDC-2032-4c70-9134-AE340D8FC36F}
DEFINE_GUID(IID_IMediaPlayer, 
			0x5a20fdc, 0x2032, 0x4c70, 0x91, 0x34, 0xae, 0x34, 0xd, 0x8f, 0xc3, 0x6f);
EXTERN_C const IID IID_IMediaPlayer;
MACRO_MIDL_INTERFACE(IMediaPlayer, "05A20FDC-2032-4c70-9134-AE340D8FC36F")
: public IUnknown
{
public:
	typedef HRESULT (__stdcall *MULTI_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);
	/*! \fn virtual STDMETHODIMP_(double) GetMovieLength(void)
	* \brief �õ�ӰƬ����
	* \retval  ����ӰƬ���� 
	*/
	virtual STDMETHODIMP_(double) GetMovieLength(void) = 0;
	/*! \fn virtual STDMETHODIMP  SetPlayTime(double dBegin, double dLength)
	* \brief ���ò���ʱ��
	* \param dBegin [in] ���ſ�ʼʱ��
	* \param dLength [in] ���ų���
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SetPlayTime(double dBegin, double dLength) = 0;
	/*! \fn virtual SetCallBack(MULTI_CALLBACK pCallBack, void *pUserObject)
	* \brief ���ûص�����
	* \param pCallBack   [in]  �ص�����
	* \param pUserObject [in]  ���ܻص��Ķ���
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SetCallBack(MULTI_CALLBACK pCallBack, void *pUserObject) = 0;
	/*! \fn virtual STDMETHODIMP GetPlayerViewMgr(IPlayerViewMgr** ppIViewMgr)
	* \brief �õ�playview�������ӿ�
	* \param ppIViewMgr   [out] playview�������ӿ�
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP GetPlayerViewMgr(IPlayerViewMgr** ppIViewMgr) = 0;
	/*! \fn virtual STDMETHODIMP_(int) IsActivate(void)
	* \brief �������Ƿ��ڻ״̬
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP_(int) IsActivate(void) = 0;
	/*! \fn virtual STDMETHODIMP Stop(void) 
	* \brief ������ֹͣ����
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Stop(void) = 0;
	/*! \fn virtual STDMETHODIMP Play(void) 
	* \brief ��������ʼ����
	* \retval  ����״̬ 
	*/

	virtual STDMETHODIMP Play(void) = 0;
	/*! \fn virtual STDMETHODIMP Pause(void) 
	* \brief ��������ͣ
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Pause(void) = 0;
	/*! \fn virtual STDMETHODIMP Resume(void) 
	* \brief �������ָ�����
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Resume(void) = 0;
	/*! \fn virtual STDMETHODIMP Seek(double dTime, int accurate) 
	* \brief seek��ָ��ʱ��
	* \param dTime      [in] ָ��ʱ���
    * \param accurate   [in] ��ȷseek��־
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Seek(double dTime, int accurate) = 0;
	/*! \fn virtual STDMETHODIMP SyncSeek(double dTime, int accurate) 
	* \brief ͬ����ʽseek��ָ��ʱ��
	* \param dTime      [in] ָ��ʱ���
	* \param accurate   [in] ��ȷseek��־
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SyncSeek(double dTime, int accurate) = 0;
	/*! \fn virtual STDMETHODIMP Forward(void)
	* \brief ǰ��һ֡����
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Forward(void) = 0;
	/*! \fn virtual STDMETHODIMP SyncForward(void)
	* \brief ͬ����ʽǰ��һ֡����
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP SyncForward(void) = 0;
	/*! \fn virtual STDMETHODIMP Update(int bForce)
	* \brief ǿ��ˢ����Ƶ����
	* \param bForce [in] ǿ��ˢ�´��ڱ�־
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP Update(int bForce)=0;
	/*! \fn virtual STDMETHODIMP CaptureCurrentImage(const CaptureImageInfo* pImageInfo, const wchar_t* pszFile)
	* \brief ��ȡ��ǰ��Ƶͼ�񱣴�Ϊָ���ļ�
	* \retval  ����״̬ 
	*/
	virtual STDMETHODIMP CaptureCurrentImage(const CaptureImageInfo* pImageInfo, const wchar_t* pszFile)=0;
	/*! \fn virtual STDMETHODIMP_(const MEDIA_FRAME*) CaptureCurrentImageEx() 
	* \brief ��ȡ��ǰ��Ƶͼ��YUV���ݣ�
	* \retval  MEDIA_FRAME�ṹ���� 
	*/
	virtual STDMETHODIMP_(const MEDIA_FRAME*) CaptureCurrentImageEx() =0;

    virtual STDMETHODIMP Load() = 0;

	virtual STDMETHODIMP_(bool) IsSeeking() = 0;

	virtual STDMETHODIMP_(bool) IsPaused() = 0;

	/*virtual STDMETHODIMP SyncBackForward(void) = 0;

	virtual STDMETHODIMP SetAudioVolumeCallBack(MULTI_CALLBACK pCallBack, void *pUserObject)=0;

	//1:ǰһ֡��һ֡������
	//0:û������
	virtual STDMETHODIMP SetAudioPlayType(int nAudioType = 1) = 0;*/
};

//�����������MediaPlayer
// {6487969C-8280-4371-B037-6FDD91321A3E}
MIDL_DEFINE_GUID(CLSID, CLSID_CMediaPlayer, 0x6487969c, 0x8280, 0x4371, 0xb0, 0x37, 0x6f, 0xdd, 0x91, 0x32, 0x1a, 0x3e);

EXTERN_C const CLSID CLSID_CMediaPlayer;