unit
	Image;
    
interface

{$MINENUMSIZE 4}

uses
    Windows;

type
	HDIBIMAGE = Pointer;	// �豸�޹�λͼ�������

// void __stdcall ImageInit();
procedure ImageInit(); stdcall;

// �ر�GDI+
// void __stdcall ImageUninit();
procedure ImageUninit(); stdcall;

//
//HDIBIMAGE __stdcall DICreate();	// �����豸�޹�λͼ���
function DICreate() : HDIBIMAGE; stdcall;

//void __stdcall DIDestroy(HDIBIMAGE hImage);	// �����豸�޹�λͼ���
procedure DIDestroy(hImage : HDIBIMAGE); stdcall;

//
//BOOL __stdcall DILoadImage(HDIBIMAGE hImage, const wchar_t* pFileName); // ����ͼ���ļ�
function DILoadImage(hImage : HDIBIMAGE; const pFileName : PWideChar) : BOOL; stdcall;

//BOOL __stdcall DILoadImageFromResource(HDIBIMAGE hImage, UINT nID, HMODULE hResModule = 0); // ����Դ�м���Bitmapλͼ����
function DILoadImageFromResource(hImage : HDIBIMAGE; nID : UINT; hResModule : HMODULE = 0) : BOOL; stdcall;

//BOOL __stdcall DILoadImage32B(HDIBIMAGE hImage, const wchar_t* pFileName); // ����ͼ���ļ���ת��Ϊ32λ����
function DILoadImage32B(hImage : HDIBIMAGE; const pFileName : PWideChar) : BOOL; stdcall;

//BOOL __stdcall DISave(HDIBIMAGE hImage, const wchar_t* pFileName); // �洢ΪBitmap�ļ�
function DISave(hImage : HDIBIMAGE; const pFileName : PWideChar) : BOOL; stdcall;

//BOOL __stdcall DISaveEx(HDIBIMAGE hImage, const wchar_t* pFileName, const wchar_t* pClsName = L"image/bmp"); // �洢Ϊͼ���ļ���֧�ֶ��ָ�ʽ��
function DISaveEx(hImage : HDIBIMAGE; const pFileName : PWideChar; const pClsName : PWideChar) : BOOL; stdcall;
// pClsName ȡ����ֵ��
// L"image/bmp"
// L"image/emf"
// L"image/wmf"
// L"image/jpeg"
// L"image/png"
// L"image/gif"
// L"image/tiff"
// L"image/exif"
// L"image/icon"


//BOOL __stdcall DISetContent(HDIBIMAGE hImage, int width, int height, int nBitCount = 32); // ���·����ڴ�ռ�
function DISetContent(hImage : HDIBIMAGE; width : Integer; height : Integer; nBitCount : Integer) : BOOL; stdcall;

//LPBITMAPINFO __stdcall DIGetBitmapInfo(HDIBIMAGE hImage); // ȡ��λͼ��Ϣͷָ��
function DIGetBitmapInfo(hImage : HDIBIMAGE) : PBITMAPINFO; stdcall;

//LPBYTE __stdcall DIGetBits(HDIBIMAGE hImage); // ȡ��ͼ���������ڴ�ָ��
function DIGetBits(hImage : HDIBIMAGE) : PBYTE; stdcall;

//int __stdcall DIGetPitch(HDIBIMAGE hImage); // ȡ��ͼ��ÿ����ռ�ֽ���
function DIGetPitch(hImage : HDIBIMAGE) : Integer; stdcall;

//int __stdcall DIGetBitCount(HDIBIMAGE hImage); // ȡ��ͼ��λ���
function DIGetBitCount(hImage : HDIBIMAGE) : Integer; stdcall;

//int __stdcall DIGetWidth(HDIBIMAGE hImage); // ȡ��ͼ����
function DIGetWidth(hImage : HDIBIMAGE) : Integer; stdcall;

//int __stdcall DIGetHeight(HDIBIMAGE hImage); // ȡ��ͼ��߶�
function DIGetHeight(hImage : HDIBIMAGE) : Integer; stdcall;


// BOOL __stdcall DIConvertFormat(HDIBIMAGE hImage, int nBitCount); // ת�����ظ�ʽ �ݲ�֧��
function DIConvertFormat(hImage : HDIBIMAGE; nBitCount : Integer) : BOOL; stdcall;

//BOOL __stdcall DICopyImage(HDIBIMAGE hImage, HDIBIMAGE hImageSrc); // ����ͼ������
function DICopyImage(hImage : HDIBIMAGE; hImageSrc : HDIBIMAGE) : BOOL; stdcall;

//BOOL __stdcall DIBltDraw(HDIBIMAGE hImage, HDC hDC, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0); // ���ٻ���ͼ�� ��֧������
function DIBltDraw(hImage : HDIBIMAGE; hDC : HDC; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0) : BOOL; stdcall;


///////////////////////////////////////////////////////////////////////////////////////////
// ͼ������

// Alpha���� ��ͼ��͸�����ӣ�
//BOOL __stdcall DIAlphaBlend(HDIBIMAGE hBackImage, HDIBIMAGE hOverImage, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0, int nOpacity = 100);
function DIAlphaBlend(hBackImage : HDIBIMAGE; hOverImage : HDIBIMAGE; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0; nOpacity : Integer = 100) : BOOL; stdcall;

// Alpha���� ��ͼ��͸�����ӣ����Ӻ�����hBackImage�����ص�͸���ȣ�Alphaֵ�� ֧��͸��ͼ��ĺϲ�
//BOOL __stdcall DIAlphaBlendEx(HDIBIMAGE hBackImage, HDIBIMAGE hOverImage, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0, int nOpacity = 100, int nOpacityBk = 100);
function DIAlphaBlendEx(hBackImage : HDIBIMAGE; hOverImage : HDIBIMAGE; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0; nOpacity : Integer = 100; nOpacityBk : Integer = 100) : BOOL; stdcall;


// ͼ�����Ŵ���

// ͼ���ֵ�㷨
type
IMAGE_INTERPOLATION =
(
    IIN_FAST,			// Nearest value (�ڽ���ֵ)
    IIN_BI_LINER,		// Bi-Liner Interpolation (˫���Բ�ֵ)
    IIN_TRI_CONVOLUTE	// Tri-Convolute Interpolation (�����ֵ)
);


// ֻ֧��32λͼ������ ��hImgSrc���ŵ�hImgDst��
//BOOL __stdcall DIImageResize(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER);
function DIImageResize(hImgDst : HDIBIMAGE; hImgSrc : HDIBIMAGE; iin : IMAGE_INTERPOLATION = IIN_BI_LINER) : BOOL; stdcall;

//BOOL __stdcall DIImageResizeEx(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int xDst, int yDst, int cxDst, int cyDst, int xSrc, int ySrc, int cxSrc, int cySrc, IMAGE_INTERPOLATION iin = IIN_BI_LINER); 
function DIImageResizeEx(hImgDst : HDIBIMAGE; hImgSrc : HDIBIMAGE; xDst : Integer; yDst : Integer; cxDst : Integer; cyDst : Integer; xSrc : Integer; ySrc : Integer; cxSrc : Integer; cySrc : Integer; iin : IMAGE_INTERPOLATION = IIN_BI_LINER) : BOOL; stdcall;


// ͼ����ת ��������ת�Ƕ�����ΪhImgDst�����ڴ�ռ�
// ֻ֧��32λͼ��
//BOOL __stdcall DIRotate(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int iRotateAngle);
function DIRotate(hImgDst : HDIBIMAGE; hImgSrc : HDIBIMAGE; iRotateAngle : Integer) : BOOL; stdcall;

//BOOL __stdcall DIRotateSmooth(HDIBIMAGE hImgDst, HDIBIMAGE hImgSrc, int iRotateAngle);
function DIRotateSmooth(hImgDst : HDIBIMAGE; hImgSrc : HDIBIMAGE; iRotateAngle : Integer) : BOOL; stdcall;

//BOOL __stdcall DIFillColor32(HDIBIMAGE hImage, ARGB argbColor); // �����ɫ ֻ������32λλͼ
function DIFillColor32(hImage : HDIBIMAGE; argbColor : DWORD) : BOOL; stdcall;


// λ���ݴ���
//BOOL __stdcall DIBltImage(HDIBIMAGE hImage, HDIBIMAGE hImageSrc, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);
function DIBltImage(hImage : HDIBIMAGE; hImageSrc : HDIBIMAGE; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0) : BOOL; stdcall;

// ����Mask���ݣ�Alpha���ݣ� ֻ������32λλͼ
//BOOL __stdcall DIBltMask(HDIBIMAGE hImage, HDIBIMAGE hImageMask, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);
function DIBltMask(hBackImage : HDIBIMAGE; hImageMask : HDIBIMAGE; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0) : BOOL; stdcall;

// ����Mask���ݣ�Alpha���ݣ�����ȫ͸��������0 ֻ������32λλͼ
//BOOL __stdcall DIBltMaskEx(HDIBIMAGE hImage, HDIBIMAGE hImageMask, int x, int y, int cx = -1, int cy = -1, int xSrc = 0, int ySrc = 0);
function DIBltMaskEx(hBackImage : HDIBIMAGE; hImageMask : HDIBIMAGE; x : Integer; y : Integer; cx : Integer = -1; cy : Integer = -1; xSrc : Integer = 0; ySrc : Integer = 0) : BOOL; stdcall;


//HDIBIMAGE __stdcall DICreateThumbnail(HDIBIMAGE hImage, int width, int height); // ΪhImage��������ͼ ���ص�����ͼ����ʹ��DIDestroy���� Ŀǰֻ������32λλͼ
function DICreateThumbnail(hImage : HDIBIMAGE; width : Integer; height : Integer) : HDIBIMAGE; stdcall;

//HBITMAP __stdcall DICreateHBitmap(HDIBIMAGE hImage); // ʹ��hImageת��ΪHBITMAP��һ��WindowsӦ�� ���صľ������ʹ��DeleteObject����
function DICreateHBitmap(hImage : HDIBIMAGE) : HBITMAP; stdcall;


implementation

const
    DLLNAME = 'WS_ImageProc.dll';

procedure ImageInit          ;external DLLNAME name 'ImageInit';
procedure ImageUninit        ;external DLLNAME name 'ImageUninit';

function DICreate						; external DLLNAME Name 'DICreate';
procedure DIDestroy						; external DLLNAME Name 'DIDestroy';

function DILoadImage					; external DLLNAME Name 'DILoadImage';
function DILoadImageFromResource		; external DLLNAME Name 'DILoadImageFromResource';
function DILoadImage32B					; external DLLNAME Name 'DILoadImage32B';
function DISave							; external DLLNAME Name 'DISave';
function DISaveEx						; external DLLNAME Name 'DISaveEx';

function DISetContent					; external DLLNAME Name 'DISetContent';
function DIGetBitmapInfo				; external DLLNAME Name 'DIGetBitmapInfo';
function DIGetBits						; external DLLNAME Name 'DIGetBits';
function DIGetPitch						; external DLLNAME Name 'DIGetPitch';
function DIGetBitCount					; external DLLNAME Name 'DIGetBitCount';
function DIGetWidth						; external DLLNAME Name 'DIGetWidth';
function DIGetHeight					; external DLLNAME Name 'DIGetHeight';
function DIConvertFormat				; external DLLNAME Name 'DIConvertFormat';
function DICopyImage					; external DLLNAME Name 'DICopyImage';
function DIBltDraw						; external DLLNAME Name 'DIBltDraw';
function DIAlphaBlend					; external DLLNAME Name 'DIAlphaBlend';
function DIAlphaBlendEx					; external DLLNAME Name 'DIAlphaBlendEx';
function DIImageResize					; external DLLNAME Name 'DIImageResize';
function DIImageResizeEx				; external DLLNAME Name 'DIImageResizeEx';
function DIRotate						; external DLLNAME Name 'DIRotate';
function DIRotateSmooth					; external DLLNAME Name 'DIRotateSmooth';
function DIFillColor32					; external DLLNAME Name 'DIFillColor32';
function DIBltImage						; external DLLNAME Name 'DIBltImage';
function DIBltMask						; external DLLNAME Name 'DIBltMask';
function DIBltMaskEx					; external DLLNAME Name 'DIBltMaskEx';
function DICreateThumbnail				; external DLLNAME Name 'DICreateThumbnail';
function DICreateHBitmap				; external DLLNAME Name 'DICreateHBitmap';


end.

