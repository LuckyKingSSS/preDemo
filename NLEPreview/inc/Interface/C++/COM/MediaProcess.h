/**
@file   MediaProcess.h
@brief  Ч������ӿ�

	-# IVideoInput��IAudioInput��IVideoOutput��IAudioOutput�ӿ�����������Ƶ������Ƶ���ӿ�IMediaStream�������Լ���ȡ�����
	-# ��IVideoComposition�ӿ��⣬�����ӿڶ�����ͨ��QueryInterface��������ѯ��Щ�ӿڡ�
	-# ��ĳ�ӿ�֧����Ƶ�Ĵ�����ô���Բ�ѯ��IAudioInput�ӿڣ��ýӿڵ�SetAudioInput����������������Ƶ���ӿ�IMediaStream�����룬 
		��Ӧ�Ŀ��Բ�ѯ��IAudioOutput�ӿڣ��ýӿڵ�GetAudioOutput���������ڻ�ȡ��Ƶ���ӿ�IMediaStream�������
	-# ��֧����Ƶ���ݴ�����ô���Բ�ѯ��IVideoInput�ӿڣ�	�ýӿڵ�SetVideoInput�ķ���������������Ƶ���ӿڵ����롣��Ӧ�Ŀ��Բ�ѯ��IVideoOutput�ӿڣ�
		�ýӿ��ṩ��GetVideoOutput������	���ڻ�ȡ��Ƶ���ӿ�IMediaStream�������
*/

#pragma once
#include <scombase.h>
#include "CommonInterface.h"
#include "COMMacro.h"
#include "CodecDefine.h"
#include "DecodeParam.h"


/** 
@class 	 IAudioProcess 
@brief	 �������Լ�������ת���ӿ��Լ����
*/
// {CDC6C251-70B0-42d0-B800-978AC93428A7}
DEFINE_GUID(IID_IAudioProcess,0xcdc6c251, 0x70b0, 0x42d0, 0xb8, 0x0, 0x97, 0x8a, 0xc9, 0x34, 0x28, 0xa7);
EXTERN_C const IID IID_IAudioProcess;
MACRO_MIDL_INTERFACE(IAudioProcess, "CDC6C251-70B0-42d0-B800-978AC93428A7")
: public IUnknown
{
public:

	/**
	@brief			���ò�����ֵ
	@param nSampleRate [in] :  ������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetSampleRate(int nSampleRate) = 0;

	/**
	@brief			��ȡ������ֵ
	@return		int : ���ز�����ֵ
	*/
	virtual STDMETHODIMP_(int) GetSampleRate(void) = 0;

	/**
	@brief			����������ֵ
	@param nChannels [in] :  ������
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetChannels(int nChannels) = 0;

	/**
	@brief			��ȡ��������ֵ
	@return		int : ����������ֵ
	*/
	virtual STDMETHODIMP_(int) GetChannels(void) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CAudioProcess, 0xc1242906, 0x5995, 0x4ed4, 0xb1, 0xab, 0x9f, 0xae, 0xe1, 0xcf, 0xcc, 0xe7);
EXTERN_C const CLSID CLSID_CAudioProcess;

/** 
@class 	 IVolumeSetting 
@brief	 �������ýӿ��Լ����
*/

// {742F6246-6D45-4d96-9032-463749B59F67}
DEFINE_GUID(IID_IVolumeSetting,0x742f6246, 0x6d45, 0x4d96, 0x90, 0x32, 0x46, 0x37, 0x49, 0xb5, 0x9f, 0x67);
EXTERN_C const IID IID_IVolumeSetting;
MACRO_MIDL_INTERFACE(IVolumeSetting, "742F6246-6D45-4d96-9032-463749B59F67")
: public IUnknown
{
public:

	/**
	@brief			����������С
	@param nVolume [in] :  ����ֵ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetVolume(int nVolume)=0;

	/**
	@brief			��ȡ������С
	@return		int : ��������ֵ
	*/
	virtual STDMETHODIMP_(int) GetVolume(void)=0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVolumeSetting, 0xe2737827, 0xe04a, 0x4969, 0xaa, 0xbb, 0xba, 0xdb, 0xd0, 0xcf, 0xe4, 0xf);
EXTERN_C const CLSID CLSID_CVolumeSetting;

												
/** 
@class 	 IAudioFade 
@brief	 ���뵭���ӿ��Լ����
*/

// {E2EA8730-B88E-48a9-AE1E-09E9A5ECC99C}
DEFINE_GUID(IID_IAudioFade,0xe2ea8730, 0xb88e, 0x48a9, 0xae, 0x1e, 0x9, 0xe9, 0xa5, 0xec, 0xc9, 0x9c);
EXTERN_C const IID IID_IAudioFade;
MACRO_MIDL_INTERFACE(IAudioFade, "E2EA8730-B88E-48a9-AE1E-09E9A5ECC99C")
: public IUnknown
{
public:

	/**
	@brief			���� ���뵭�� ʱ��
	@param dFadeInStartTime [in] :  ̸�뿪ʼʱ��
	@param dFadeInLength [in] : ����ʱ�䳤��
	@param dFadeOutStartTime [in] :  ̸����ʼʱ��
	@param dFadeOutLength [in] : ����ʱ�䳤��
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetFadeInOutTime(double dFadeInStartTime, double dFadeInLength, double dFadeOutStartTime, double dFadeOutLength) = 0;

	/**
	@brief			��� ���뵭�� ʱ��
	@param pFadeInStartTime [in] :  ̸�뿪ʼʱ��
	@param pFadeInLength [in] : ����ʱ�䳤��
	@param pFadeOutStartTime [in] :  ̸����ʼʱ��
	@param pFadeOutLength [in] : ����ʱ�䳤��
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetFadeInOutTime(double *pFadeInStartTime, double *pFadeInLength, double *pFadeOutStartTime, double *pFadeOutLength) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CAudioFade, 0x68cce4e2, 0xe906, 0x47a8, 0x98, 0x20, 0xf7, 0x10, 0x89, 0xd, 0xa, 0x2a);
EXTERN_C const CLSID CLSID_CAudioFade;


/** 
@class 	 IAudioSlider 
@brief	 ƽ����Ƶ����ӿ��Լ����   
*/
// {F7591170-F4C6-46ea-BA3B-6FF1C8942EEC}
DEFINE_GUID(IID_IAudioSlider,0xf7591170, 0xf4c6, 0x46ea, 0xba, 0x3b, 0x6f, 0xf1, 0xc8, 0x94, 0x2e, 0xec);
EXTERN_C const IID IID_IAudioSlider;
MACRO_MIDL_INTERFACE(IAudioSlider, "F7591170-F4C6-46ea-BA3B-6FF1C8942EEC")
: public IUnknown
{
public:

	/**
	@brief			������Ƶ����ͷ
	@param bAlignHead [in] :  ��Ƶ�Ƿ����ͷ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@note	�ú���û�б�ʹ��
	*/
	virtual STDMETHODIMP SetAlignHead(int bAlignHead) = 0;

	/**
	@brief			��ȡ��Ƶ����ͷ
	@return		int : ������Ƶ����ͷ
	@note	�ú���û�б�ʹ��
	*/
	virtual STDMETHODIMP_(int) GetAlignHead(void) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CAudioSlider, 0x911b921b, 0xb28a, 0x44d1, 0xa0, 0xed, 0x4b, 0xde, 0xcf, 0x18, 0xa3, 0xbc);
EXTERN_C const CLSID CLSID_CAudioSlider;


/** 
@class 	 IVideoSlider 
@brief	 ƽ����Ƶ����ӿ��Լ����
*/
// {52752A39-9BD7-4333-BA14-6982882255FB}
DEFINE_GUID(IID_IVideoSlider,0x52752a39, 0x9bd7, 0x4333, 0xba, 0x14, 0x69, 0x82, 0x88, 0x22, 0x55, 0xfb);
EXTERN_C const IID IID_IVideoSlider;
MACRO_MIDL_INTERFACE(IVideoSlider, "52752A39-9BD7-4333-BA14-6982882255FB")
: public IUnknown
{
public:

	/**
	@brief			������Ƶ���֡��
	@param dFrameRate [in] :  ��Ƶ���֡��
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetOutputFrameRate(double dFrameRate) = 0;

	/**
	@brief			��ȡ��Ƶ���֡��
	@return		int : ������Ƶ���֡��
	*/
	virtual STDMETHODIMP_(double) GetOutputFrameRate(void) = 0;

	/**
	@brief			������Ƶ����ͷ
	@param bAlignHead [in] :  ��Ƶ�Ƿ����ͷ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@note	�ú���û�б�ʹ��
	*/
	virtual STDMETHODIMP SetAlignHead(int bAlignHead) = 0;
	
	/**
	@brief			��ȡ��Ƶ����ͷ
	@return		int : ������Ƶ����ͷ
	@note	�ú���û�б�ʹ��
	*/
	virtual STDMETHODIMP_(int) GetAlignHead(void) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoSlider, 0x315ab12e, 0xabfb, 0x4327, 0xa3, 0x8a, 0x2b, 0xb, 0x88, 0x6d, 0xf8, 0x49);
EXTERN_C const CLSID CLSID_CVideoSlider;


/** 
@class 	 IVideoCrop 
@brief	 Crop����ӿ��Լ���� 
*/
// {2081D016-BF75-4029-8E17-49A53C2F3541}
DEFINE_GUID(IID_IVideoCrop,0x2081d016, 0xbf75, 0x4029, 0x8e, 0x17, 0x49, 0xa5, 0x3c, 0x2f, 0x35, 0x41);
EXTERN_C const IID IID_IVideoCrop;
MACRO_MIDL_INTERFACE(IVideoCrop, "2081D016-BF75-4029-8E17-49A53C2F3541")
: public IUnknown
{
public:
	
	/**
	@brief			������ƵCrop��Χ
	@param cropRect [in] :  ��ƵCrop��Χ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetCropRect(const RECT cropRect) = 0;

	/**
	@brief			��ȡ��ƵCrop��Χ
	@return		int : ������ƵCrop��Χ
	*/
	virtual STDMETHODIMP_(RECT) GetCropRect(void) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoCrop, 0x465a9d1d, 0x55d6, 0x4bdd, 0x92, 0x32, 0x9b, 0x3, 0x5e, 0x79, 0x66, 0x67);
EXTERN_C const CLSID CLSID_CVideoCrop;


/** 
@class 	 IVideoEffect 
@brief	 �����ȶԱȶȵ�Ч������ӿ��Լ����
*/
// {AC3DDFA6-1974-42d5-880E-C0CEAA194D93}
DEFINE_GUID(IID_IVideoEffect,0xac3ddfa6, 0x1974, 0x42d5, 0x88, 0xe, 0xc0, 0xce, 0xaa, 0x19, 0x4d, 0x93);
EXTERN_C const IID  IID_IVideoEffect;
MACRO_MIDL_INTERFACE(IVideoEffect, "AC3DDFA6-1974-42d5-880E-C0CEAA194D93")
: public IUnknown
{
public:

	/**
	@brief			������ƵFilterʹ������
	@param uFlag [in] :  Filterʹ�����ͣ���flag�����ֵ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@note
		- ##define EX_FILTER_GRAY			0x0001	��ɫ
		- ##define EX_FILTER_EMBOSS			0x0002	����
		- ##define EX_FILTER_NEGATIVE		0x0004	��Ƭ
		- ##define EX_FILTER_BLACK_WHITE		0x0008	�ڰ�
		- ##define EX_FILTER_WHITE_BLACK		0x0010	�׺�
		- ##define EX_FILTER_OLD_PHOTO		0x0020	����Ƭ
	*/
    virtual STDMETHODIMP SetFilterFlag(UINT uFlag) = 0;

	/**
	@brief			��ȡ��ƵFilterʹ������
	@return		UINT : ������ƵFilterʹ������
	*/
    virtual STDMETHODIMP_(UINT) GetFilterFlag(void) = 0;

	/**
	@brief			������Ƶ����
	@param nValue [in] :  ��Ƶ����  [-100,100]
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetBrightness(int nValue) = 0;

	/**
	@brief			��ȡ��Ƶ���� 
	@return		int : ������Ƶ����
	*/
	virtual STDMETHODIMP_(int) GetBrightness(void) = 0;
	
	/**
	@brief			������Ƶ���Ͷ�
	@param nValue [in] :  ��Ƶ���Ͷ� [-100,100]
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetSaturation(int nValue) = 0;

	/**
	@brief			��ȡ��Ƶ���Ͷ� 
	@return		int : ������Ƶ���Ͷ�
	*/
	virtual STDMETHODIMP_(int) GetSaturation(void) = 0;
	
	/**
	@brief			������Ƶ��֯��ʽ
	@param uDeintelace [in] :  ��Ƶ��֯��ʽ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@note
	enum DEINTERLACE_STYLE \n
	{\n
		DIS_NONE,				��������\n
		DIS_ODD,				�ظ�������\n	
		DIS_EVEN,				�ظ�ż����	\n
		DIS_ODD_INTERPOLATE,	ʹ�������в�ֵ\n
		DIS_EVEN_INTERPOLATE,	ʹ��ż���в�ֵ\n
		DIS_AUTO,				�Զ������ݲ�֧�֣�\n
	}\n
};
	
	*/
	virtual STDMETHODIMP SetDeintelace(DEINTERLACE_STYLE uDeintelace) = 0;

	/**
	@brief			��ȡ��Ƶ��֯��ʽ
	@return		DEINTERLACE_STYLE : ������Ƶ��֯��ʽ
	*/
	virtual STDMETHODIMP_(DEINTERLACE_STYLE) GetDeintelace(void) = 0;
	
	/**
	@brief			������Ƶ�Աȶ�
	@param nValue [in] :  ��Ƶ�Աȶ� [-100,100]
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	
	virtual STDMETHODIMP SetContrast(int nValue) = 0;

	/**
	@brief			��ȡ��Ƶ�Աȶ�
	@return		DEINTERLACE_STYLE : ������Ƶ�Աȶ�
	*/
	virtual STDMETHODIMP_(int) GetContrast(void) = 0;
	
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoEffect, 0x9f97a1bf, 0x884d, 0x4c14, 0xb9, 0xcc, 0x4d, 0xa7, 0xcd, 0xf3, 0x5b, 0xc7);
EXTERN_C const CLSID CLSID_CVideoEffect;

/** 
@class 	 IVideoCopy 
@brief	 ���ݿ����Ľӿ�
*/
// {C2B0EEA2-6E70-45df-A06B-B096146EFB56}
DEFINE_GUID(IID_IVideoCopy,0xc2b0eea2, 0x6e70, 0x45df, 0xa0, 0x6b, 0xb0, 0x96, 0x14, 0x6e, 0xfb, 0x56);
EXTERN_C const IID  IID_IVideoCopy;
MACRO_MIDL_INTERFACE(IVideoCopy, "C2B0EEA2-6E70-45df-A06B-B096146EFB56")
: public IUnknown
{
public:

	/**
	@brief			������Ƶ֡�Ƿ���ҪCOPY
	@param bNeed [in] :  �Ƿ���Ҫcopy��Ƶ֡��־
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetNeedCopyFrame(int bNeed) = 0;

	/**
	@brief			��ȡ��Ƶ֡�Ƿ���ҪCOPY
	@return		int : �����Ƿ���Ҫcopy��Ƶ֡��־
	*/
	virtual STDMETHODIMP_(int) GetNeedCopyFrame() = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoCopy, 0xc2aa0e9e, 0x3e1a, 0x48a9, 0xb2, 0x88, 0x99, 0xa5, 0x9d, 0xa0, 0xcb, 0x9d);
EXTERN_C const CLSID CLSID_CVideoCopy;

/** 
@class 	 IVideoRotation 
@brief	 ��Ƶ��ת��Ч������ӿ��Լ���� 
*/

// {37300932-932C-42a6-852F-B3C9CFD84C83}
DEFINE_GUID(IID_IVideoRotation,0x37300932, 0x932c, 0x42a6, 0x85, 0x2f, 0xb3, 0xc9, 0xcf, 0xd8, 0x4c, 0x83);
EXTERN_C const IID IID_IVideoRotation;
MACRO_MIDL_INTERFACE(IVideoRotation, "37300932-932C-42a6-852F-B3C9CFD84C83")
: public IUnknown
{
public:

	/**
	@brief			ͼ��ת����
	@param uFlag [in] :  �Ƿ�ͼ��ת,һ��flag�������ֵ
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@note :
			 - ##define FLIP_HORIZONTAL			0x0001  ˮƽ��ת
			 - ##define FLIP_VERTICAL			0x0002	��ֱ��ת
	*/
	virtual STDMETHODIMP SetFlipFlag(UINT uFlag)=0;

	/**
	@brief			��ȡͼ��ת����
	@return		UINT : ����ͼ��ת����
	*/
	virtual STDMETHODIMP_(UINT) GetFlipFlag()=0;


	/**
	@brief			ͼ����ת����
	@param nRotation [in] :  ͼ��ת�Ƕȣ�����90��������
	@param nDrag [in] :  δʹ�ã��� 0
	@param flg [in] :  δʹ�ã��� 0
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetRotation(int nRotation, int nDrag, int flg) = 0;

	/**
	@brief			��ȡͼ����ת����
	@param pRotation [in] :  ͼ��ת�Ƕ�
	@param pDrag [in] :  δʹ�ã��� 0
	@param pFlg [in] :	δʹ�ã��� 0
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetRotation(int *pRotation, int *pDrag, int *pFlg) = 0;
};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoRotation, 0x807dea6d, 0x2e28, 0x41b4, 0x89, 0xa8, 0x2d, 0x33, 0xc, 0xba, 0x4d, 0xfc);
EXTERN_C const CLSID CLSID_CVideoRotation;

/** 
@class 	 IVideoResizer 
@brief	 ��Ƶ���Ŵ���ӿ��Լ���� 
*/

// {D7F70D4F-AAD6-4d92-9CE4-B95641E2D865}
DEFINE_GUID(IID_IVideoResizer,0xd7f70d4f, 0xaad6, 0x4d92, 0x9c, 0xe4, 0xb9, 0x56, 0x41, 0xe2, 0xd8, 0x65);
EXTERN_C const IID IID_IVideoResizer;
MACRO_MIDL_INTERFACE(IVideoResizer, "D7F70D4F-AAD6-4d92-9CE4-B95641E2D865")
: public IUnknown
{
public:
	
	/**
	@brief			�������ͼ���С
	@param nWidth [in] :  ͼ���
	@param nHeight [in] : ͼ���
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP SetOutputSize(int nWidth, int nHeight) = 0;
	
	/**
	@brief			��ȡ���ͼ���С
	@param pWidth [in] :  ͼ���
	@param pHeight [in] : ͼ���
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	*/
	virtual STDMETHODIMP GetOutputSize(int *pWidth, int *pHeight) = 0;

	/**
	@brief			����ͼ������ʱ����ֵ�㷨
	@param interpolationMode [in] :  ͼ���ֵ�㷨
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@see	#IMAGE_INTERPOLATION	
	*/
	virtual STDMETHODIMP SetInterpolationMode(IMAGE_INTERPOLATION interpolationMode) = 0;
	
	/**
	@brief			��ȡͼ������ʱ����ֵ�㷨
	@return IMAGE_INTERPOLATION :  ͼ���ֵ�㷨
	*/
	virtual STDMETHODIMP_(IMAGE_INTERPOLATION) GetInterpolationMode(void) = 0;

	/**
	@brief			����ͼ������ʱ��ʹ��ģ��
	@param resizeMode [in] :  ����ʱ��ʹ��ģ��
	@return		HRESULT : ��������״̬
	- 1.S_OK    : ���óɹ�;
	- 2.S_FALSE : ����ʧ��;
	@see	#IMAGE_RESIZE_METHOD
	*/
	virtual STDMETHODIMP SetResizeMode(IMAGE_RESIZE_METHOD resizeMode) = 0;

	/**
	@brief			��ȡͼ������ʱ��ʹ��ģ��
	@return IMAGE_RESIZE_METHOD :  ͼ������ʱ��ʹ��ģ��
	*/
	virtual STDMETHODIMP_(IMAGE_RESIZE_METHOD) GetResizeMode(void) = 0;
};


//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoResizer, 0xfc2c8098, 0x6c82, 0x492a, 0x92, 0x6c, 0xcb, 0xb9, 0x64, 0xd1, 0x2d, 0x3f);
EXTERN_C const CLSID CLSID_CVideoResizer;




/************************************************************************/
/*						��Ƶ���ӽӿ��Լ����						    */
/************************************************************************/

/*!
* \class IVideoCompositonItem
* \brief ��Ƶ�������ýӿڡ� 
*/

// {7060C309-9996-49ff-B5E3-74093A6ABB98}
DEFINE_GUID(IID_IVideoCompositonItem,0x7060c309, 0x9996, 0x49ff, 0xb5, 0xe3, 0x74, 0x9, 0x3a, 0x6a, 0xbb, 0x98);
EXTERN_C const IID IID_IVideoCompositonItem;
MACRO_MIDL_INTERFACE(IVideoCompositonItem, "7060C309-9996-49ff-B5E3-74093A6ABB98")
: public IUnknown
{
public:

	/*! \fn  virtual STDMETHODIMP SetRect(const FRECT Rect))
	* \brief  ���õ�������
	* \FRECT [in] ��������
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetRect(const FRECT Rect) = 0;

	/*! \fn  virtual STDMETHODIMP_(FRECT) GetRect(void)
	* \brief  ��ȡ��ǰ��������
	* \retval ��ǰ��������
	*/
	virtual STDMETHODIMP_(FRECT) GetRect(void) = 0;

	/*! \fn  virtual STDMETHODIMP SetOpacity(int nOpacity)
	* \brief  ����͸����
	* \param nOpacity [in] ͸����
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetOpacity(int nOpacity) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetOpacity(void)
	* \brief  ��ȡ��ǰ��͸��������
	* \retval ��ǰ��͸��������
	*/
	virtual STDMETHODIMP_(int) GetOpacity(void) = 0;

	/*! \fn  virtual STDMETHODIMP SetStartTime(__int64 startTime)
	* \brief ���õ��ӵĿ�ʼʱ��
	* \param startTime [in] ���ӵĿ�ʼʱ��
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetStartTime(__int64 startTime) = 0;

	/*! \fn  virtual STDMETHODIMP_(__int64) GetStartTime(void)
	* \brief ��ȡ���ӵĿ�ʼʱ��
	* \retval ���ӵĿ�ʼʱ��
	*/
	virtual STDMETHODIMP_(__int64) GetStartTime(void) = 0;

	/*! \fn  virtual STDMETHODIMP SetDuration(__int64 duration)
	* \brief ��ȡ���ӵĳ���ʱ��
	* \param duration [in] ���ӵĳ���ʱ��
	* \retval ���ý��
	*/
	virtual STDMETHODIMP SetDuration(__int64 duration) = 0;

	/*! \fn  virtual STDMETHODIMP_(__int64) GetDuration(void)
	* \brief ��ȡ��ǰ���õĵ��ӳ���ʱ��
	* \retval ���ӳ���ʱ��
	*/
	virtual STDMETHODIMP_(__int64) GetDuration(void) = 0;
};

/*!
* \class IVideoCompositor
* \brief ��Ƶ���ӽӿڣ�ͨ���ýӿڣ����Ե�����Ƶ�������֣��Լ�ͼ�� 
*/

// {A32480A3-582E-4785-AA98-B46B2C317252}
DEFINE_GUID(IID_IVideoCompositor,0xa32480a3, 0x582e, 0x4785, 0xaa, 0x98, 0xb4, 0x6b, 0x2c, 0x31, 0x72, 0x52);
EXTERN_C const IID IID_IVideoCompositor;
MACRO_MIDL_INTERFACE(IVideoCompositor, "A32480A3-582E-4785-AA98-B46B2C317252")
: public IUnknown
{
public:

	/*! \fn  virtual STDMETHODIMP_(IVideoCompositonItem *) AddByMediaStream(IMediaStream * pMediaStream)
	* \brief  ���һ·��Ƶ���� ���ڵ���ͨ��IVideoInput ���ý�����Ƶ����
	* \pMediaStream [in] ��Ƶ��
	* \retval �������ýӿ�
	* \see IVideoCompositonItem IMediaStream
	*/
	virtual STDMETHODIMP_(IVideoCompositonItem *) AddByMediaStream(IMediaStream * pMediaStream) = 0;

	/*! \fn  virtual STDMETHODIMP_(IVideoCompositonItem *) AddByFileName(const BSTR pFileName)
	* \brief  ���һ�������Ļ��·���� ���ڵ���ͨ��IVideoInput ���ý�����Ƶ����
	* \pFileName [in] �����Ļ��·��
	* \retval �������ýӿ�
	* \see IVideoCompositonItem
	*/
	virtual STDMETHODIMP_(IVideoCompositonItem *) AddByFileName(const BSTR pFileName) = 0;

	/*! \fn  virtual STDMETHODIMP_(IVideoCompositonItem *) AddByBitmap(IDibImage * pDIBImage)
	* \brief  ���λͼ�ӿڣ� ���ڵ���ͨ��IVideoInput ���ý�����Ƶ����
	* \pDIBImage [in] λͼ�ӿ�
	* \retval �������ýӿ�
	* \see IVideoCompositonItem IDibImage
	*/
	virtual STDMETHODIMP_(IVideoCompositonItem *) AddByBitmap(IDibImage * pDIBImage) = 0;

	/*! \fn  virtual STDMETHODIMP_(int) GetCount(void)
	* \brief  ��ȡ��ӵĵ����������
	* \retval ��ӵĵ����������
	*/
	virtual STDMETHODIMP_(int) GetCount(void) = 0;

	/*! \fn  virtual STDMETHODIMP GetItem(int nIndex, IVideoCompositonItem **ppVideoCompositonItem)
	* \brief  ��ȡָ���ĵ�����ӿڣ�
    * \param nIndex [in] ����������
	* \param ppVideoCompositonItem [in / out] ������ӿ�ָ��
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP GetItem(int nIndex, IVideoCompositonItem **ppVideoCompositonItem) = 0;

	/*! \fn  virtual STDMETHODIMP Remove(IVideoCompositonItem* pVideoCompositonItem, int * pIndex)
	* \brief  �Ƴ�һ��������ӿڣ������ظ����������
	* \param pVideoCompositonItem [in] ������ӿ�
	* \param pIndex [in / out] �ýӿ����б��е�������
	* \retval ��ȡ���
	*/
	virtual STDMETHODIMP Remove(IVideoCompositonItem* pVideoCompositonItem, int * pIndex) = 0;
};

//�������
// {375DAF31-A4B7-40b0-9F2B-3B90AC944536}
MIDL_DEFINE_GUID(CLSID, CLSID_CVideoCompositor, 0x375daf31, 0xa4b7, 0x40b0, 0x9f, 0x2b, 0x3b, 0x90, 0xac, 0x94, 0x45, 0x36);
EXTERN_C const CLSID CLSID_CVideoCompositor;


/** 
@class 	 IAudioPackFrame 
@brief	 ��Ƶ��֡����ӿ��Լ���� 
*/
// {F289BB70-0986-4b23-8F34-A870F1F83D0F}
DEFINE_GUID(IID_IAudioPackFrame, 0xf289bb70, 0x986, 0x4b23, 0x8f, 0x34, 0xa8, 0x70, 0xf1, 0xf8, 0x3d, 0xf);
EXTERN_C const IID IID_IAudioPackFrame;
MACRO_MIDL_INTERFACE(IAudioPackFrame, "F289BB70-0986-4b23-8F34-A870F1F83D0F")
: public IUnknown
{
public:

	/*
	���� Forward() ��Ƶ�������������Ժ���Ϊ��λ
	*/
	virtual STDMETHODIMP SetOutPutInterval( double millisecond ) = 0;

};

//�������
MIDL_DEFINE_GUID(CLSID, CLSID_CAudioPackFrame, 0xb26ee074, 0xd0fc, 0x41d9, 0x9b, 0x63, 0xb2, 0xda, 0xa8, 0x4b, 0x80, 0x58);
EXTERN_C const CLSID CLSID_CAudioPackFrame;