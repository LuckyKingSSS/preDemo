/////////////////////////////////////////////
// Image.h
// �ṩ�豸�޹�λͼ���ݽӿ�


#pragma once


typedef void* HDIBIMAGE;

#ifndef WIN32
#include "Linux32_Typedef.h"

typedef HANDLE HBITMAP;
#endif

#ifdef WIN32
void __stdcall ImageInit();

// �ر�GDI+
void __stdcall ImageUninit();
#endif

extern "C" HDIBIMAGE __stdcall DICreate();	// �����豸�޹�λͼ���
extern "C" void __stdcall DIDestroy(HDIBIMAGE hImage);	// �����豸�޹�λͼ���
extern "C" HDIBIMAGE __stdcall DICreateIndirect(LPBYTE lpInfo, LPBYTE lpBits = 0); // ����Bitmap�ڴ����ݴ���Image

// mac��ֻ�ܼ��أ�bmp��jpg��gif��png��tif��ico�ļ�
extern "C" int __stdcall DILoadImage(HDIBIMAGE hImage, const wchar_t* pFileName); // ����ͼ���ļ�
#ifdef WIN32
int __stdcall DILoadImageFromResource(HDIBIMAGE hImage, UINT nID, HMODULE hResModule = 0); // ����Դ�м���Bitmapλͼ����
#endif
extern "C" int __stdcall DILoadImage32B(HDIBIMAGE hImage, const wchar_t* pFileName); // ����ͼ���ļ���ת��Ϊ32λ����
extern "C" int __stdcall DISave(HDIBIMAGE hImage, const wchar_t* pFileName); // �洢ΪBitmap�ļ�
extern "C" int __stdcall DISaveEx(HDIBIMAGE hImage, const wchar_t* pFileName, const wchar_t* pClsName = L"image/bmp"); // �洢Ϊͼ���ļ���֧�ֶ��ָ�ʽ��
// windows��pClsName ȡ����ֵ��
// L"image/bmp"
// L"image/emf"
// L"image/wmf"
// L"image/jpeg"
// L"image/png"
// L"image/gif"
// L"image/tiff"
// L"image/exif"
// L"image/icon"
// mac��pClsName ȡ����ֵ��
// L"image/bmp"
// L"image/jpeg"
// L"image/png"
// L"image/gif"
// L"image/tiff"
// L"image/pdf"

extern "C" int __stdcall DISetContent(HDIBIMAGE hImage, int width, int height, int nBitCount = 32); // ���·����ڴ�ռ�
extern "C" int __stdcall DISetContentEx(HDIBIMAGE hImage, int width, int height, void* addr,int nBitCount = 32); //ȷ���ڴ�ռ� 

extern "C" LPBITMAPINFO __stdcall DIGetBitmapInfo(HDIBIMAGE hImage); // ȡ��λͼ��Ϣͷָ��
extern "C" LPBYTE __stdcall DIGetBits(HDIBIMAGE hImage); // ȡ��ͼ���������ڴ�ָ��
extern "C" int __stdcall DIGetPitch(HDIBIMAGE hImage); // ȡ��ͼ��ÿ����ռ�ֽ���
extern "C" int __stdcall DIGetBitCount(HDIBIMAGE hImage); // ȡ��ͼ��λ���
extern "C" int __stdcall DIGetWidth(HDIBIMAGE hImage); // ȡ��ͼ����
extern "C" int __stdcall DIGetHeight(HDIBIMAGE hImage); // ȡ��ͼ��߶�
extern "C" int __stdcall DIGetBitmapInfoSize(HDIBIMAGE hImage); // ȡ��ͼ����Ϣ�ߴ�
extern "C" int __stdcall DIGetDataSize(HDIBIMAGE hImage); // ȡ��ͼ�����ݳߴ�

extern "C" int __stdcall DISetBitmapInfo(HDIBIMAGE hImage, int newWidht, int newHeight, BYTE* pBase = NULL);

// ͼ�����ظ�ʽת�� Ŀǰֻ֧��תΪ32λ
int __stdcall DIConvertFormat(HDIBIMAGE hImage, int nBitCount); 
int __stdcall DICopyImage(HDIBIMAGE hImage, HDIBIMAGE hImageSrc); // ����ͼ������

#ifdef WIN32
int __stdcall DIBltDraw(HDIBIMAGE hImage, HDC hDC, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0); // ���ٻ���ͼ�� ��֧������
#else
#endif

///////////////////////////////////////////////////////////////////////////////////////////
// ͼ������

// Alpha���� ��ͼ��͸�����ӣ�
int __stdcall DIAlphaBlend(HDIBIMAGE hBackImage, HDIBIMAGE hOverImage, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0, int nOpacity = 100);

// Alpha���� ��ͼ��͸�����ӣ����Ӻ�����hBackImage�����ص�͸���ȣ�Alphaֵ�� ֧��͸��ͼ��ĺϲ�
int __stdcall DIAlphaBlendEx(HDIBIMAGE hBackImage, HDIBIMAGE hOverImage, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0, int nOpacity = 100, int nOpacityBk = 100);


// ͼ�����Ŵ���

#ifndef IMAGE_INTERPOLATION_DEFINE
#define IMAGE_INTERPOLATION_DEFINE
// ͼ���ֵ�㷨
enum IMAGE_INTERPOLATION
{
	IIN_AUTO,
	IIN_FAST,			// Nearest value (�ڽ���ֵ)
	IIN_BI_LINER,		// Bi-Liner Interpolation (˫���Բ�ֵ)
	IIN_TRI_CONVOLUTE	// Tri-Convolute Interpolation (�����ֵ)
};

#endif

// ֻ�ʺ�32λͼ������ ��hImgSrc���ŵ�hImgDst��

int __stdcall DIImageResize(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER);
int __stdcall DIImageResizeEx(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER); 




// ͼ����ת ��������ת�Ƕ�����ΪhImgDst�����ڴ�ռ�
int __stdcall DIRotate(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int iRotateAngle);
int __stdcall DIRotateSmooth(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int iRotateAngle);

int __stdcall DIFillColor32(HDIBIMAGE hImage, DWORD argbColor); // �����ɫ ֻ������32λλͼ

HBITMAP __stdcall DICreateHBitmap(HDIBIMAGE hImage); // ʹ��hImageת��ΪHBITMAP��һ��WindowsӦ�� ���صľ������ʹ��DeleteObject����



// λ���ݴ��� 
int __stdcall DIBltImage(HDIBIMAGE hImage, HDIBIMAGE hImageSrc, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);

struct TRANSFORM_POINTS
{
	POINT ptLeftTop;		// ���Ͻ�����
	POINT ptRightTop;		// ���Ͻ�����
	POINT ptRightBottom;	// ���½�����
	POINT ptLeftBottom;		// ���½�����
};

typedef TRANSFORM_POINTS* LPTRANSFORM_POINTS;

#ifdef USE_OLD_IMAGE_OPERATION

// ����Mask���ݣ�Alpha���ݣ� ֻ������32λλͼ 
int __stdcall DIBltMask(HDIBIMAGE hImage, HDIBIMAGE hImageMask, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);

// ����Mask���ݣ�Alpha���ݣ�����ȫ͸��������0 ֻ������32λλͼ 
int __stdcall DIBltMaskEx(HDIBIMAGE hImage, HDIBIMAGE hImageMask, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);

int __stdcall DIFillColor32Ex(HDIBIMAGE hImage, DWORD argbColor, int x, int y, int cx = -1, int cy = -1); // ���������ɫ ֻ������32λλͼ
int __stdcall DIFillPatchColor32(HDIBIMAGE hImage, int cx, int cy, DWORD argbColor, DWORD argbColor2); // ���ƴ����ɫ ֻ������32λλͼ
int __stdcall DIFillPatchColor32Ex(HDIBIMAGE hImage, int cx, int cy, DWORD argbColor, DWORD argbColor2, int x_off, int y_off); // ���ƴ����ɫ ֻ������32λλͼ ֧��ƫ��

HDIBIMAGE __stdcall DICreateThumbnail(HDIBIMAGE hImage, int width, int height); // ΪhImage��������ͼ ���ص�����ͼ����ʹ��DIDestroy���� Ŀǰֻ������32λλͼ


// ֧��Alpha��������Ų��� Ŀǰֻ֧��IIN_BI_LINER��ʽ 
int __stdcall DIImageAlphaResize(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER); 
// ͬDIImageAlphaResize���� ����������ͼ��Χ�� 
int __stdcall DIImageAlphaResizeEx(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER); 
 
// ֧�����ŵ�Mask���� Ŀǰֻ֧��8λ�Ҷ�Mask ��ɫΪ͸�� 
int __stdcall DIImageStretchMask(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc);
// ͬDIImageStretchMask���� ����������ͼ��Χ�� 
int __stdcall DIImageStretchMaskEx(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc);





// ͼ��任 ��pImageSrc����ӳ�䵽pImage��trPoints�ĸ�����Χ�ɵ������� 
int __stdcall DITransform(HDIBIMAGE hImage, HDIBIMAGE hImageSrc, LPTRANSFORM_POINTS pTrPoints, int xSrc = 0, int ySrc = 0, int cxSrc = -1, int cySrc = -1, IMAGE_INTERPOLATION iin = IIN_BI_LINER);

// ��ͼ����������һ����ɫ
int __stdcall DIMaskImage(HDIBIMAGE hImage, LPRECT pRect, DWORD dwArgbColor = 0x80000000); // pRect - ������ɰ������

#endif

// ͼ��ϲ�Alpha���� ��ͼ��͸�����ӣ�֧��ͼ�㲻͸����
int __stdcall DIMergeImage(HDIBIMAGE hBackImage, HDIBIMAGE hOverImage, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0, int nOpacity = 100, int nOpacityBk = 100);

