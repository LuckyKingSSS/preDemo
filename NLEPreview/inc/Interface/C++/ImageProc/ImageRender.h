/////////////////////////////////////////////
// ImageRender.h
// �ṩ�豸�޹�λͼ���ݽӿ�


#pragma once

#include "Image.h"

#ifndef IMAGE_FILTER_DEFINE
#define IMAGE_FILTER_DEFINE

// ͼ���˾�ID
enum IMAGE_FILTER_ID
{
	IFI_NONE,		
	IFI_ZOOM_BLUR,				// Zoomģ�� nRadius - ģ�����
	IFI_MOTION_BLUR,			// �˶�ģ�� nRadius - ģ���뾶  nParam1 - ģ������0 - ���� 1 - ���ң�
	IFI_GAUSS_BLUR,				// ��˹ģ�� nRadius - ģ���뾶 
	IFI_SHADOW,					// �����Ӱ nRadius - ��͸����  nParam1 - ��Ӱ��ɫ��COLORREF�� nParam2 - ƽ���̶� nParam3 - X����ƫ�� nParam4 - Y����ƫ��
//	IFI_SOLIDFRAME,				// �߿�

	IFI_INVERT			= 300,	// ͼ��ɫ
	IFI_GRAY_SCALE,				// �Ҷ�ͼ��
	IFI_THRESHOLD,				// ��ֵ nRadius (0 - 255)
	IFI_FLIP,					// ��ֱ��ת
	IFI_FLIP_HORZ,				// ˮƽ��ת
	IFI_EMBOSS,					// ���� nRadius (0 - 100)
	IFI_SPLASH,					// �ߵ� nRadius (0 - 255)
	IFI_MOSAIC,					// ������ nRadius (0 - 255)
	IFI_OIL_PAINT,				// �ͻ� nRadius (0 - 10)
	IFI_3DGRID,					// 3D���� nParam1 - ����ߴ磨1 - �� nParam2 - ������ȣ�1 - �� 
	IFI_WHIRL_PINCH,			// ��ת��ѹ nParam1 - ��ת��0 - 360�� nParam2 - ��ѹ��0 - 100�� 
	IFI_GRADIENT_RADIAL,		// �����ͽ��� �ݲ�ʹ��
	IFI_GAMMA,					// gamma���� nRadius (0 - 255)
	IFI_ROTATE90,				// ˳ʱ����ת90��/rotate 90'
	IFI_RIBBON,					// ���� nParam1 : ���[0..100]����ֵΪһ�ٷֱ�  nParam2 : Ƶ��>=0��ÿ10Ϊһ��pi
	IFI_HALFTONE_M3,			// ��Ӱ�� �޲���
	IFI_BRIGHTNESS,				// �������� ʹ��nParam1������0 - 200�� 
	IFI_CONTRAST,				// ���ڶԱȶ� ʹ��nParam1������0 - 200�� 
	IFI_COLORTONE,				// ��ɫ�� nParam1 - R���� nParam2 - G���� nParam3 - B����
	IFI_HUE_SATURATION,			// ɫ�����Ͷ�/hue saturation  nParam1 - ɫ��(-180, 180) nParam2 - ���Ͷ�(-100, 100) 
	IFI_CREATEHALO,				// ��������
	IFI_OLD_PHOTO,				// ����Ƭ nRadius (0 - 10) ��ʱδʹ���κβ���
	IFI_SOLIDFRAME,				// �߿�

	IFI_STRETCH = 500,			// nQuality ȡֵ��IMAGE_INTERPOLATION���� nParam1 - ���ź�ͼ��Ŀ�� nParam2 - ���ź�ͼ��ĸ߶�
	IFI_ROTATE,					// ��ת nAngle - (0 - 360)

	IFI_COUNT
};

// Image Filter Parameter structure
struct IMAGE_FILTER_PARAM
{
	IMAGE_FILTER_ID	uFilterID;		// �˾�ID
	int				nRadius;		// �뾶
	int				nAngle;			// �Ƕ�
	int				nQuality;		// Ʒ��
	int				nParam1;
	int				nParam2;
	int				nParam3;
	int				nParam4;
};

typedef IMAGE_FILTER_PARAM* LPIMAGE_FILTER_PARAM;

 

struct FILTERPARAM 
{
	IMAGE_FILTER_ID uFilterID;
    wchar_t szIDCaption[64];  //��ʾ�ı���
    int bRadius ;  wchar_t RadiusText[32]; int RadiusMax, RadiusMin;
    int bAngle ;   wchar_t AngleText[32];  int AngleMax,  AngleMin;
    int bQuality;  wchar_t QualityText[32];int QualityMax, QualityMin;
    int bParam1;   wchar_t Param1Text[32]; int Param1Max, Param1Min;
    int bParam2;   wchar_t Param2Text[32]; int Param2Max, Param2Min;
    int bParam3;   wchar_t Param3Text[32]; int Param3Max, Param3Min;
    int bParam4;   wchar_t Param4Text[32]; int Param4Max, Param4Min;
};

typedef FILTERPARAM* LPFILTERPARAM;

#endif

// ͼ���˾��ص���������
typedef int (__stdcall * IMAGE_FILTER_CALLBACK)(void* pUserObj, UINT uMesg, WPARAM wParam, LPARAM lParam);

// ͼ���˾�����
int __stdcall IRImageFitler(HDIBIMAGE hImageDst, HDIBIMAGE hImageSrc, LPIMAGE_FILTER_PARAM pParam, IMAGE_FILTER_CALLBACK fnCallback = 0, void* pUserObj = 0);

int __stdcall IRGetFilterParam(IMAGE_FILTER_ID uFilterID, LPFILTERPARAM pParam); // ȡ��Filter����

int  __stdcall IRGetFilterCount();   //ȡ�ãƣ������ĸ�����

int __stdcall IRGetFilterItem(int Index , LPFILTERPARAM pParam);  //ȡ�õڡ��ɣ������

