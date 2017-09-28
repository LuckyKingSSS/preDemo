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

// 旋转
extern "C" HDIBIMAGE __stdcall ippRotate(HDIBIMAGE hImage, double dAngle);

// 按指定比例缩放
// xFactor、yFactor：X、Y方向缩放比例
extern "C" HDIBIMAGE __stdcall ippResizeScale(HDIBIMAGE hImage, double xFactor, double yFactor); 

//缩放到指定大小
//nMode:0：直接拉伸 1：等比缩放
extern "C" BOOL      __stdcall ippResize(HDIBIMAGE hSrc, HDIBIMAGE hDst, int nMode);


// AlphaBlend
extern "C" int __stdcall ImageAlphaComp(HDIBIMAGE pBackImg, HDIBIMAGE pOverImg, int xPos, int yPos);

//alphaType See IppiAlphaType
extern "C" int __stdcall ImageAlphaCompEx(HDIBIMAGE pBackImg, HDIBIMAGE pOverImg, int xPos, int yPos, int alphaType);

//0-水平翻转，1-垂直翻转，2-水平、垂直同时翻转
extern "C" HDIBIMAGE __stdcall ippMirror(HDIBIMAGE hImage, int nMode);

//0-水平翻转，1-垂直翻转，2-水平、垂直同时翻转，图片大小不一时返回FALSE
extern "C" BOOL __stdcall ippMirrorEx(HDIBIMAGE hDstImage, HDIBIMAGE hSrcImage, int nMode);

// 获取JPEG文件中的Exif信息
extern "C" BOOL      __stdcall GetExifInfo(const wchar_t* wszPath, NleExifInfo* pExifInfo, HDIBIMAGE* hImage);

//打开、删除文件
extern "C" FILE*     __stdcall VanOpenFile(const wchar_t *wszPath, const wchar_t *wszMode);
extern "C" BOOL      __stdcall VanRemoveFile(const wchar_t *wszPath);

extern "C" int __stdcall UPathToAPath(const wchar_t* pwszSrc, char* pszDst, int nDstLen);
extern "C" int __stdcall APathToUPath(const char* pszSrc, wchar_t* pwszDst, int nDstLen);

//几何变换
//dAngle：角度（顺时针方向） 
//dMoveX/dMoveY :中心点偏移量
//dScaleX/dScaleY:x，y方向缩放比例
extern "C" int __stdcall ImageGeometry(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dAngle, double dMoveX, double dMoveY, double dScaleX, double dScaleY);

//仿射变换
//dstQuad[4][2]：四顶点绝对坐标值，顺序：左下->右下->右上->左上
extern "C" int __stdcall ImageWarpAffineQuad(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dstQuad[4][2]);

//透射变换
//dstQuad[4][2]：四顶点绝对坐标值，顺序：左下->右下->右上->左上
extern "C" int __stdcall ImageWarpPerspectQuad(HDIBIMAGE pDst, HDIBIMAGE pSrc, double dstQuad[4][2]);

//加边框
extern "C" int __stdcall MakeBorder(HDIBIMAGE pDst, HDIBIMAGE pSrc, int cx = -1, int cy = -1, int nTopBorderHeight = 0, int nLeftBorderWidth = 0);

//颜色空间转换
extern "C" int __stdcall RGBToHLS(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall HLSToRGB(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall RGBToHSV(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall HSVToRGB(HDIBIMAGE pDst, HDIBIMAGE pSrc);

extern "C" int __stdcall YUV420ToRGB(HDIBIMAGE pDst, LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV);
//保留pDst的alpha信息
extern "C" int __stdcall YUV420ToARGB(HDIBIMAGE pDst, LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV);


extern "C" int __stdcall RGBToYUV420(LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV, HDIBIMAGE pSrc);

extern "C" int __stdcall RGBToYUV420Ex(LPBYTE lpY, int nPtY, LPBYTE lpU, int nPtU, LPBYTE lpV, int nPtV, const LPBITMAPINFOHEADER lpSrcBmi, const LPBYTE lpSrcBits);

extern "C" HDIBIMAGE __stdcall RGBToGray(HDIBIMAGE hSrc);
extern "C" int __stdcall RGB32ToGrayEx(LPBYTE lpDst, LPBYTE lpSrc, int width, int height);

//直方图均衡（建议使用HistogramStretch）
extern "C" int __stdcall HistEqualization(HDIBIMAGE pDst, HDIBIMAGE pSrc);
extern "C" int __stdcall HistogramStretch(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//gamma校正
extern "C" int __stdcall GammaCorrect(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//模糊（更改图像大小）
extern "C" int __stdcall BlurImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

extern "C" int __stdcall BlurImageEx(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//Filter 平滑 nlevs：平滑程度（0-10）
extern "C" int __stdcall SmoothImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nMode = 5, int nLevs = 1);

//Filter 锐化 nlevs：锐化程度（0-10）
extern "C" int __stdcall FilterSharpen(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//制作指定颜色边框
extern "C" int __stdcall MakeImageFrame(HDIBIMAGE pDst, HDIBIMAGE pSrc, NLERGB colr, int nLevs = 1);

//膨胀 nlevs：膨胀程度（0-10）
extern "C" int __stdcall DilateImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//膨胀 nlevs>=1
extern "C" int __stdcall DilateImageI(HDIBIMAGE hImage, int nLevs = 1);

//腐蚀 nlevs：腐蚀程度（0-10）
extern "C" int __stdcall ErodeImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nLevs = 1);

//形态学操作；
//nMode：0：开运算 1：闭运算 2：梯度
extern "C" int __stdcall MorphImage(HDIBIMAGE pDst, HDIBIMAGE pSrc, int nMode);   //

//自动白平衡
extern "C" int __stdcall AutoWhiteBalance(HDIBIMAGE pDst, HDIBIMAGE pSrc);

//白平衡 color：纯白色颜色值
extern "C" int __stdcall WhiteBalance(HDIBIMAGE pDst, HDIBIMAGE pSrc, NLERGB colr);