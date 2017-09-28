#pragma once
#include "..\\Type\Image.h"

#ifndef MAX_COMMENT
#define MAX_COMMENT 1000
#endif

struct NleExifInfo 
{
	char  Version      [5];
	char  CameraMake   [32];
	char  CameraModel  [40];
	char  DateTime     [20];
	int   Height, Width;
	int   Orientation;
	int   IsColor;
	int   Process;
	int   FlashUsed;
	float FocalLength;
	float ExposureTime;
	float ApertureFNumber;
	float Distance;
	float CCDWidth;
	float ExposureBias;
	int   Whitebalance;
	int   MeteringMode;
	int   ExposureProgram;
	int   ISOequivalent;
	int   CompressionLevel;
	float FocalplaneXRes;
	float FocalplaneYRes;
	float FocalplaneUnits;
	float Xresolution;
	float Yresolution;
	float ResolutionUnit;
	float Brightness;
	char  Comments[MAX_COMMENT];
};

struct NLERGB{
	int r;
	int g;
	int b;
	int nReserve;

	NLERGB()
	{
		r = 255;
		g = 255;
		b = 255;
		nReserve = 255;
	}
};

//
extern "C" HDIBIMAGE __stdcall ConvertImgTo32B(HDIBIMAGE hSrc);

// ��ת
extern "C" HDIBIMAGE __stdcall ippRotate(HDIBIMAGE hImage, double dAngle);

// ��ָ����������
// xFactor��yFactor��X��Y�������ű���
extern "C" HDIBIMAGE __stdcall ippResizeScale(HDIBIMAGE hImage, double xFactor, double yFactor); 

//���ŵ�ָ����С
//nMode:0��ֱ������ 1���ȱ�����
extern "C" BOOL      __stdcall ippResize(HDIBIMAGE hSrc, HDIBIMAGE hDst, int nMode);


// AlphaBlend
extern "C" int __stdcall ImageAlphaComp(HDIBIMAGE pBackImg, HDIBIMAGE pOverImg, int xPos, int yPos);

//alphaType See IppiAlphaType
extern "C" int __stdcall ImageAlphaCompEx(HDIBIMAGE pBackImg, HDIBIMAGE pOverImg, int xPos, int yPos, int alphaType);

//0-ˮƽ��ת��1-��ֱ��ת��2-ˮƽ����ֱͬʱ��ת
extern "C" HDIBIMAGE __stdcall ippMirror(HDIBIMAGE hImage, int nMode);

//0-ˮƽ��ת��1-��ֱ��ת��2-ˮƽ����ֱͬʱ��ת��ͼƬ��С��һʱ����FALSE
extern "C" BOOL __stdcall ippMirrorEx(HDIBIMAGE hDstImage, HDIBIMAGE hSrcImage, int nMode);

// ��ȡJPEG�ļ��е�Exif��Ϣ
extern "C" BOOL      __stdcall GetExifInfo(const wchar_t* wszPath, NleExifInfo* pExifInfo, HDIBIMAGE* hImage);

//�򿪡�ɾ���ļ�
extern "C" FILE*     __stdcall VanOpenFile(const wchar_t *wszPath, const wchar_t *wszMode);
extern "C" BOOL      __stdcall VanRemoveFile(const wchar_t *wszPath);

extern "C" int __stdcall UPathToAPath(const wchar_t* pwszSrc, char* pszDst, int nDstLen);
extern "C" int __stdcall APathToUPath(const char* pszSrc, wchar_t* pwszDst, int nDstLen);

//���α任
//dAngle���Ƕȣ�˳ʱ�뷽�� 
//dMoveX/dMoveY :���ĵ�ƫ����
//dScaleX/dScaleY:x��y�������ű���
extern "C" int __stdcall ImageGeometry(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dAngle, double dMoveX, double dMoveY, double dScaleX, double dScaleY);

//����任
//dstQuad[4][2]���Ķ����������ֵ��˳������->����->����->����
extern "C" int __stdcall ImageWarpAffineQuad(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dstQuad[4][2]);

//͸��任
//dstQuad[4][2]���Ķ����������ֵ��˳������->����->����->����
extern "C" int __stdcall ImageWarpPerspectQuad(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dstQuad[4][2]);

//�ӱ߿�
extern "C" int __stdcall MakeBorder(HDIBIMAGE pDst, HDIBIMAGE pSrc, int cx = -1, int cy = -1, int nTopBorderHeight = 0, int nLeftBorderWidth = 0);

//��ɫ�ռ�ת��
extern "C" int __stdcall RGBToHLS(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall HLSToRGB(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall RGBToHSV(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall HSVToRGB(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall YUV420ToRGB(HDIBIMAGE pDst, LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV);
//����pDst��alpha��Ϣ
extern "C" int __stdcall YUV420ToARGB(HDIBIMAGE pDst, LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV);


extern "C" int __stdcall RGBToYUV420(LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV, HDIBIMAGE pSrc);

extern "C" int __stdcall RGBToYUV420Ex(LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV, const LPBITMAPINFOHEADER lpSrcBmi, const LPBYTE lpSrcBits);

extern "C" HDIBIMAGE __stdcall RGBToGray(HDIBIMAGE hSrc);
extern "C" int __stdcall RGB32ToGrayEx(LPBYTE lpDst, LPBYTE lpSrc, int width, int height);

//ֱ��ͼ���⣨����ʹ��HistogramStretch��
extern "C" int __stdcall HistEqualization(HDIBIMAGE pDst, HDIBIMAGE pSrc);
extern "C" int __stdcall HistogramStretch(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//gammaУ��
extern "C" int __stdcall GammaCorrect(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//ģ��������ͼ���С��
extern "C" int __stdcall BlurImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

extern "C" int __stdcall BlurImageEx(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//Filter ƽ�� nlevs��ƽ���̶ȣ�0-10��
extern "C" int __stdcall SmoothImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nMode = 5, int nLevs = 1);

//Filter �� nlevs���񻯳̶ȣ�0-10��
extern "C" int __stdcall FilterSharpen(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//����ָ����ɫ�߿�
extern "C" int __stdcall MakeImageFrame(HDIBIMAGE pDst, HDIBIMAGE pSrc, NLERGB colr, int nLevs = 1);

//���� nlevs�����ͳ̶ȣ�0-10��
extern "C" int __stdcall DilateImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//���� nlevs>=1
extern "C" int __stdcall DilateImageI(HDIBIMAGE hImage, int nLevs = 1);

//��ʴ nlevs����ʴ�̶ȣ�0-10��
extern "C" int __stdcall ErodeImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//��̬ѧ������
//nMode��0�������� 1�������� 2���ݶ�
extern "C" int __stdcall MorphImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nMode);   //

//�Զ���ƽ��
extern "C" int __stdcall AutoWhiteBalance(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//��ƽ�� color������ɫ��ɫֵ
extern "C" int __stdcall WhiteBalance(HDIBIMAGE pDst, HDIBIMAGE pSrc, NLERGB colr);