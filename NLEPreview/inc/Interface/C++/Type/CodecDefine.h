// CodecDefine.h

//DecodeParam.h
/*! \file CodecDefine.h
* \brief							���붨����Ϣ
*/

#pragma once

#ifndef _DEC_MODEL_DEFINE
#define _DEC_MODEL_DEFINE
/*!
* \enum DEC_MODEL
* \brief ������뷽ʽ
*/
enum DEC_MODEL		// ������뷽ʽ
{
	/*! �Զ�����*/
	AUTO_MODEL = 0,	
	
	/*! DShow����������WINDOWS��Ч*/
	DSHOW_MODEL,

	/*! FFMPEG���룬 �Բ�ʹ��*/
	FFDEC_MODEL,

	/*! DVD������*/
	DVD_MODEL,	

	/*! AVDec������ WS_AVDec.dll ����WS Video Decoder Platform*/
	AVDEC_MODEL,

	/*! Flash�������� �Բ���ʹ��*/
	SWF_MODEL,		

	/*!  mtx�ļ�������*/
	MTXML_MODEL,

	/*! ͼƬ������*/
	IMAGE_MODEL,  

	/*! QuickTime������*/
	QTML_MODEL,	

	/*! �����Ļ������*/
	SUBPIC_MODEL,	

	/*! ���ڳ�ʼ������Ƶģʽ��*/
	NO_SET_MODEL,  
	MPDEC_MODEL,	//MPlayer������
};

#endif	// _DEC_MODEL_DEFINE


#ifndef _AUDIO_INTERPOLATION_DEFINE
#define _AUDIO_INTERPOLATION_DEFINE

/*!
* \enum AUDIO_INTERPOLATION
* \brief ��Ƶ������ת����ֵ�㷨
*/
enum AUDIO_INTERPOLATION	// ��Ƶ������ת����ֵ�㷨
{
	/*! һ�����Բ�ֵ*/
	SIMPLE_LINEAR = 0,

	/*! �������Բ�ֵ(��δʵ��)*/
	QUADRATIC_LINEAR,
};

#endif // _AUDIO_INTERPOLATION_DEFINE


#ifndef IMAGE_INTERPOLATION_DEFINE
#define IMAGE_INTERPOLATION_DEFINE
/*!
* \enum IMAGE_INTERPOLATION
* \brief ͼ���ֵ�㷨
*/
enum IMAGE_INTERPOLATION	// ͼ���ֵ�㷨
{
	/*! �Զ�ѡ���ֵ�㷨*/
	IIN_AUTO,			

	/*! Nearest value (�ڽ���ֵ)*/
	IIN_FAST,			

	/*! Bi-Liner Interpolation (˫���Բ�ֵ)*/
	IIN_BI_LINER,		

	/*! Tri-Convolute Interpolation (�����ֵ)*/
	IIN_TRI_CONVOLUTE	
};

#endif	// IMAGE_INTERPOLATION_DEFINE


#ifndef IMAGE_RESIZE_METHOD_DEFINE
#define IMAGE_RESIZE_METHOD_DEFINE
/*!
* \enum IMAGE_RESIZE_METHOD
* \brief ͼ��scale����
*/
enum IMAGE_RESIZE_METHOD
{
	/*! stretch to full screen*/
	IRM_FULLSCREEN,		

	/*! keep scale, fit to size of output*/
	IRM_ORIGINAL_SCALE, 

	/*! resize to 16:9, fit to size of output*/
	IRM_16_9,			

	/*! resize to 4:3, fit to size of output*/
	IRM_4_3,			

	/*! resize to LETTERBOX, fit to size of output*/
	IRM_LETTERBOX,

	/*! resize to PAN_SCAN, fit to size of output*/
	IRM_PAN_SCAN
};
#endif

#ifndef DEINTERLACE_INTERPOLATION_DEF
#define DEINTERLACE_INTERPOLATION_DEF

/*!
* \enum DEINTERLACE_STYLE
* \brief ��ȥ����ɨ�跽��
*/
enum DEINTERLACE_STYLE
{
	/*! ��������*/
	DIS_NONE,	

	/*! �ظ�������*/
	DIS_ODD,				

	/*! �ظ�ż����*/
	DIS_EVEN,			

	/*! ʹ�������в�ֵ*/
	DIS_ODD_INTERPOLATE,

	/*! ʹ��ż���в�ֵ*/
	DIS_EVEN_INTERPOLATE,	

	/*! �Զ������ݲ�֧�֣�*/
	DIS_AUTO,
};

#endif // DEINTERLACE_INTERPOLATION_DEF


#ifndef _DOUBLE_RECT_DEFINE
#define _DOUBLE_RECT_DEFINE

struct D_RECT				// ����λ��������꣬�ο�ֵΪ���ͼ��ֱ���
{
	double		dTop;		// �������꣬Ϊ������꣬ȡֵ 0.0��1.0����ͬ
	double		dBottom;
	double		dLeft;
	double		dRight;
};

#endif // _DOUBLE_RECT_DEFINE

#ifndef _CLIP_TIME_DEFINE
#define _CLIP_TIME_DEFINE

/*!
* \struct CLIP_TIME
* \brief ���������Ϣ
*/
struct CLIP_TIME
{
	/*! ��������������Ƶ����ֹʱ�䣬��λ���룬�� ���г��� != ������ȣ�����������Ч��*/
	double		dStart;		

	/*! ��ֵΪ����������Ч��*/
	double		dEnd;		 

	/*! ����ʱ���֮��㣬��λ���룬��ͬ*/
	double		dTrimFrom;	 

	/*!  ����ʱ���֮�յ㣬0ֵ��ʾβ�˲����м���*/
	double		dTrimTo;	
};

#endif // _CLIP_TIME_DEFINE

/*!
* \enum EncMediaType
* \brief ����������Ϣ
*/
enum EncMediaType
{
	/*! ������Ƶ*/
	ENC_AUDIO_TYPE,

	/*! ������Ƶ*/
	ENC_VIDEO_TYPE,
};
