// VideoSlideParam.h

/*
	   ��Ƶ�ϳɵĴ������
*/

#pragma once

#include "DecodeParam.h"
#include "CodecDefine.h"


#ifndef WATERMARK_PARAM
#define WATERMARK_PARAM

struct WatermarkParam
{
	HMODULE			hModule;
	wchar_t			szID[512];				// ˮӡ��ԴID
	RECT			Rect;					// ˮӡλ��
	int				nOpacity;				// ˮӡ��͸���� (0 - 100)  0 - ��ȫ͸��  100 - ��ȫ��͸��
	LPBITMAPINFO	lpbi;					// lpbi ��0��ʹ��hModule��֧��32λ͸��ͼ���Լ�Y41A�Զ����ʽ
	LPBYTE			lpBits;					// lpbi��lpBits��ҪӦ�ó�������������
	int             nAlign;                 // ˮӡ����(nAlign > 0ʱ ����ˮӡ����(nAlign), ��������ˮӡλ��(Rect))
};

#endif

#ifndef FLOAT_RECT_DEF
#define FLOAT_RECT_DEF
typedef struct tagFRECT
{
	float   left;
	float   top;
	float   right;
	float   bottom;
} FRECT, *PFRECT;
#endif

#ifndef USERWATERMARK_PARAM
#define USERWATERMARK_PARAM
struct UserWatermarkParam
{
	LPBITMAPINFO lpbi;
	LPBYTE       lpBits;
	FRECT        fRect;
	int          nOpacity;
};
#endif

struct VideoSlideParam
{
	int						nWidth;			// �ֱ��ʿ��
	int						nHeight;		// �ֱ��ʸ߶�
	double					dFrameRate;		// ֡�� 0��ʾ�Զ�ѡ��
	DWORD					dwCompression;	// ͼ���ʽ��Ŀǰֻ֧��'21VY'
	int						nBitsDepth;		// ͼ��λ���
	WatermarkParam			Watermark;		// ˮӡ����
};

struct VideoProcessParam
{
	CLIP_TIME		Time;				// ʱ������
	RECT			CropRect;			// ��������Ϊ�������������
	int				nBrightness;		// ���ȣ�-100��100��0����ԭ����
	int				nContrast;			// �Աȶȣ�-100��100��0����ԭ�Աȶ�
	int				nSaturation;		// ���Ͷ�,-100��100��0����ԭ���Ͷ�
	UINT			uExFilterID;		// ��չ�˾�ID
	UINT			uFlipFlag;			// ͼ��ת����
	DEC_MODEL		DecMod;				// ���뷽ʽ
	DecParam		decParam;			// �������
	DEINTERLACE_STYLE uDeintelace;		// ȥ������ɨ�跽ʽ
	IMAGE_RESIZE_METHOD		nResizeStyle;	// ͼ�����ŷ�ʽ
	IMAGE_INTERPOLATION		nInterpolation;	// ͼ���ֵ�㷨
};

