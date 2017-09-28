#pragma once

#include "wstypedef.h"
//WMV��ʽ����չ����
struct WMV_VideoParamEx
{
   int m_Quality ;                //�����ȼ�   0-4 4Ϊ��� Ĭ��Ϊ0
   int m_VBRType;                  // �ɱ䳤�������� m_VBRType 0 1 Ĭ��Ϊ0 ��̬����VBR 0 ƽ������ABR 1(��ʱ��֧��) 
   int m_MaxBuffer;               //�����С   0~10�� Ĭ��Ϊ0
   int m_IFrameInterval;          //Ĭ��Ϊ25
};
//AVC Profiles 
enum WS_CodeID_H264_PROFILE 
{
	WS_CodeID_H264_PROFILE_UNKNOWN		 =0,
	WS_CodeID_H264_PROFILE_AVC_BASELINE    =66,
	WS_CodeID_H264_PROFILE_AVC_MAIN        =77,
	WS_CodeID_H264_PROFILE_AVC_HIGH        =100,
};

enum WS_CodeID_H264_LEVEL 
{
	WS_CodeID_H264_LEVEL_UNKNOWN			 =0,
	WS_CodeID_H264_LEVEL_AVC_1             =10,
	WS_CodeID_H264_LEVEL_AVC_1b            =9,
	WS_CodeID_H264_LEVEL_AVC_11            =11,
	WS_CodeID_H264_LEVEL_AVC_12            =12,
	WS_CodeID_H264_LEVEL_AVC_13            =13,
	WS_CodeID_H264_LEVEL_AVC_2             =20,
	WS_CodeID_H264_LEVEL_AVC_21            =21,
	WS_CodeID_H264_LEVEL_AVC_22            =22,
	WS_CodeID_H264_LEVEL_AVC_3             =30,
	WS_CodeID_H264_LEVEL_AVC_31            =31,
	WS_CodeID_H264_LEVEL_AVC_32            =32,
	WS_CodeID_H264_LEVEL_AVC_4             =40,
	WS_CodeID_H264_LEVEL_AVC_41            =41,
	WS_CodeID_H264_LEVEL_AVC_42            =42,
	WS_CodeID_H264_LEVEL_AVC_5             =50,
	WS_CodeID_H264_LEVEL_AVC_51            =51,
};
struct H264_VideoParamEx
{
	WS_CodeID_H264_PROFILE   dwProfile;        //0��ʾ�������ⲿ���ã�
	WS_CodeID_H264_LEVEL   dwComplexityLevel;//0��ʾ�������ⲿ���ã�
	bool   bLosslessMode;// use lossless mode[using sps and pps to init x264] if true
};

struct VC1_VideoParamEx
{
	unsigned int   dwProfile;
	unsigned int   dwComplexityLevel;
	unsigned int   dwQP;
	unsigned int   dwMaxKeyFrameDistance;
	unsigned int   dwNumOfBFrames;
	unsigned int   dwRateControlMode;
	unsigned int   dwVBVBufferInBytes;
	double          dPeakBitRate;
};

/* XVID�߼��������� */
struct Xvid_EncodeParamEx
{
    int Quality;
    int VHQMODE;
};

enum WS_CodecID_ProRes_PROFILE
{
	WS_CodecID_ProRes_PROFILE_PROXY = 0,
	WS_CodecID_ProRes_PROFILE_422LT = 1,
	WS_CodecID_ProRes_PROFILE_422 = 2,
	WS_CodecID_ProRes_PROFILE_422HQ = 3,
	WS_CodecID_ProRes_PROFILE_4444 = 4,
};

struct AppleProRes_EncodeParamEx
{
	enum WS_CodecID_ProRes_PROFILE eProfile;
};