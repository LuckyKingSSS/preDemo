unit DataProcess;

{
���ܣ�
֧��ͼ�����ȡ��Աȶȡ����Ͷȣ��������ڣ� 
֧�ֻҶȡ���Ƭ���������Ч�� 
֧��֧��ͼ����ã�ȥ�����ܺڱߣ��� 
֧��ͼ��ת���ܣ�
֧��BMP��JPGץͼ�� 

֧��ˮӡ������λ�ã�֧��ˮӡ͸���ȵ��ڡ�
}

{$WARNINGS OFF}
{$Z4}

interface

uses
  Windows, EncParam, CodecDefine;

// ��չ�˾�ID���� 
// EX_FILTER_ID
const 
	EX_FILTER_GRAY			  = $0001;
	EX_FILTER_EMBOSS		  = $0002;
	EX_FILTER_NEGATIVE		= $0004;
	EX_FILTER_BLACK_WHITE	= $0008;
	EX_FILTER_WHITE_BLACK	= $0010;
	EX_FILTER_OLD_PHOTO		= $0020;

// FLIP_FLAG
const
	FLIP_HORIZONTAL			  = $0001;
	FLIP_VERTICAL			    = $0002;


//typedef void * HVIDEODECODER;
//typedef void * HAUDIODECODER;
type
  HVIDEODECODER = Pointer;
  HAUDIODECODER = Pointer;
  
  RESIZE_PARAM = record
    width           :Integer;
    height          :Integer;
    uInterpolation  :IMAGE_INTERPOLATION;
    uStyle          :IMAGE_RESIZE_METHOD;
  end;
  PRESIZE_PARAM = ^RESIZE_PARAM;

// liuqi 2008/7/24
// �����ݽṹ��CodecDefine���Ѿ����塣����Ҫ����CodecDefineͷ�ļ���
/////////////////////////////////////////////
//{$IFNDEF DEINTERLACE_INTERPOLATION_DEF}
//{$DEFINE DEINTERLACE_INTERPOLATION_DEF}
// DEINTERLACE_STYLE =
//(
//	DIS_NONE,
//	DIS_ODD,				// �ظ�������
//	DIS_EVEN,				// �ظ�ż����
//	DIS_ODD_INTERPOLATE,	// ʹ�������в�ֵ
//	DIS_EVEN_INTERPOLATE,	// ʹ��ż���в�ֵ
//	DIS_AUTO				// �Զ������ݲ�֧�֣�
//);
//{$ENDIF}  //  DEINTERLACE_INTERPOLATION_DEF
//////////////////////////////////////////////

//�������ݴ�����Ƶ����������Դ��Ƶ������
// dFrameRate - >= 0 ʹ��֡��ת����ʱ���У�����ܣ�ͬʱʱ�����0����   = 0 ʹ��ԭʼ֡��     < 0 ��ʹ��֡��ת����ʱ���У������ 
//HVIDEODECODER PCVideoCreate(HVIDEODECODER hSrcVideo, const RESIZE_PARAM* pResizeParam = 0, double dFrameRate = -1);
function PCVideoCreate(hSrcVideo: HVIDEODECODER; const pResizeParam : PRESIZE_PARAM = nil; dFrameRate : double = -1): HVIDEODECODER; stdcall;

//�������ݴ�����Ƶ������
//void PCVideoDestroy(HVIDEODECODER hVideo);
procedure PCVideoDestroy(hVideo: HVIDEODECODER); stdcall;

//�������ݴ�����Ƶ����������Դ��Ƶ������
// bEvenFlag - TRUE ʹ��ʱ���У�����ܣ�ͬʱʱ�����0����
//HAUDIODECODER PCAudioCreate(HAUDIODECODER hSrcAudio, int nSampleRate = 0, int nChannels = 0, int nBitsPerSample = 0, BOOL bEvenFlag = FALSE);
function PCAudioCreate(hSrcAudio: HAUDIODECODER; nSampleRate : Integer = 0; nChannels : Integer = 0; nBitsPerSample : Integer = 0; bEvenFlag : BOOL = FALSE): HAUDIODECODER; stdcall;

//�������ݴ�����Ƶ������
//void PCAudioDestroy(HAUDIODECODER hAudio);
procedure PCAudioDestroy(hAudio: HAUDIODECODER); stdcall;

//���ü�������,rc������������,ȫ0Ϊ�����м��ò���
//void PCSetCropRect(HVIDEODECODER hVideo, const RECT* pCropRect);
procedure PCSetCropRect(hVideo: HVIDEODECODER; const pCropRect: PRect); stdcall;

//���ù����ȣ�-100��100�� 0����ԭ����
//void PCSetVideoBrightness(HVIDEODECODER pVideo, int nValue);
procedure PCSetVideoBrightness(hVideo: HVIDEODECODER; nValue: Integer); stdcall;

//���öԱȶȣ�-100��100�� 0����ԭ�Աȶ�
//void __stdcall PCSetContrast(HVIDEODECODER hVideo, int nValue);
procedure PCSetContrast(hVideo: HVIDEODECODER; nValue: Integer); stdcall;

//���ñ��Ͷ�,-100~100, 0����ԭ���Ͷ�
//void PCSetVideoSaturation(HVIDEODECODER pVideo, int nValue);
procedure PCSetVideoSaturation(hVideo: HVIDEODECODER; nValue: Integer); stdcall;

// ָ��ˮӡ��ԴID
// pRect - ����ڼ��ú��ͼ��ֱ����е�λ��
// nOpacity - ˮӡ��͸���� (0 - 100)  0 - ��ȫ͸��  100 - ��ȫ��͸��
//void __stdcall PCSetWatermarkSrcID(HVIDEODECODER hVideo, HMODULE hModule, const wchar_t * pID, const LPRECT pRect = 0, int nOpacity = 100);
procedure PCSetWatermarkSrcID(hVideo: HVIDEODECODER; hModule: Cardinal; const pID: PWideChar; const pRect: PRECT = nil; nOpacity: Integer = 100); stdcall;

//void __stdcall PCSetWatermarkSrcIDAlign(HVIDEODECODER hVideo, HMODULE hModule, const wchar_t * pID, int nPos = 0, int nOpacity = 100);
procedure PCSetWatermarkSrcIDAlign(hVideo: HVIDEODECODER; hModule: Cardinal; const pID: pWideChar; nPos: Integer = 0; nOpacity: Integer = 100); stdcall;
//void __stdcall PCDisableWatermark(HVIDEODECODER hVideo, BOOL bDisable);
procedure PCDisableWatermark(hVideo: HVIDEODECODER; bDisable: BOOL); stdcall;

//void __stdcall PCSetWatermarkImage(HVIDEODECODER hVideo, LPBITMAPINFO lpbi, LPBYTE lpBits, const LPRECT pRect = 0, int nOpacity = 100); // ֧��32λ͸��ͼ�� pRect - ����ڼ��ú��ͼ��ֱ����е�λ��
procedure PCSetWatermarkImage(hVideo: HVIDEODECODER; lpbi: PBITMAPINFO; lpBits: PBYTE; const pRect: PRECT = nil; nOpacity: Integer = 100); stdcall;

//void __stdcall PCSetWatermarkImageAlign(HVIDEODECODER hVideo, LPBITMAPINFO lpbi, LPBYTE lpBits, int nPos = 0, int nOpacity = 100); // ֧��32λ͸��ͼ�� nPos - ����ڼ��ú��ͼ��ֱ����е�λ��
procedure PCSetWatermarkImageAlign(hVideo: HVIDEODECODER; lpbi: PBITMAPINFO; lpBits: PBYTE; nPos: Integer = 0; nOpacity: Integer = 100); stdcall;


{$IFNDEF FLOAT_RECT_DEF}
{$DEFINE FLOAT_RECT_DEF}
type
  FRECT = record
    left    :Double;
    top     :Double;
    right   :Double;
    bottom  :Double;
  end;
  PFRECT = ^FRECT;
{$ENDIF}

// ֧��32λ͸��ͼ�� pFRect - ����ڼ������ź��ͼ��ֱ����еİٷֱ�λ��  1��ʾ100%
// ����lpbi��lpBitsΪ0����ʾȡ��ˮӡͼƬ
// ����lpbi��lpBitsΪ0xFFFFFFFF����ʾ����ԭ����ˮӡͼƬ��ֻ�ı�ˮӡλ�á�
//void __stdcall PCSetUserWatermarkImage(HVIDEODECODER hVideo, LPBITMAPINFO lpbi, LPBYTE lpBits, const PFRECT pFRect = 0, int nOpacity = 100);
procedure PCSetUserWatermarkImage(hVideo: HVIDEODECODER; lpbi: PBITMAPINFO; lpBits: PBYTE; const pFRect: PFRECT = 0; nOpacity: Integer = 100); stdcall;

//����,0~200, 100����ԭ����
//void PCSetVolum(HAUDIODECODER pAudio, int nValue);
procedure PCSetVolum(hAudio: HAUDIODECODER; nValue: Integer); stdcall;

// ץͼ 
// pFileName�� �ļ���
// nFormat�� �ļ���ʽ 0 - BMP  1 - JPG 
//BOOL __stdcall PCCaptureImage(HVIDEODECODER hVideo, wchar_t * pFileName, int nFormat, bWaterMark);
function PCCaptureImage(hSrcVideo: HVIDEODECODER; pFileName: PWideChar; nFormat : Integer; bWaterMark : BOOL): BOOL; stdcall;

	
// ������չ�˾����� uFlagȡEX_FILTER_ID��ֵ������ �Ƽ�ʹ�õ�һFilter
//void __stdcall PCSetExFilterFlag(HVIDEODECODER hVideo, UINT uFlag);
procedure PCSetExFilterFlag(hVideo: HVIDEODECODER; uFlag: UINT); stdcall;

// FLIP_FLAG
//#define FLIP_HORIZONTAL		0x0001
//#define FLIP_VERTICAL			0x0002
// ͼ��ת����
// uFlag - ��FLIP_FLAG���������
//void __stdcall PCSetFlipFlag(HVIDEODECODER hVideo, UINT uFlag);
procedure PCSetFlipFlag(hVideo: HVIDEODECODER; uFlag: UINT); stdcall;

// ȥ������ɨ�蹦��
// �����DecParam������ָ����Deintelace���ܣ����ﲻӦ�����ظ�����
//void __stdcall PCSetVideoDeintelace(HVIDEODECODER hVideo, DEINTERLACE_STYLE uDeintelace);
procedure PCSetVideoDeintelace(hVideo: HVIDEODECODER; uDeintelace: DEINTERLACE_STYLE); stdcall;

//��λ��dTime 
//void __stdcall PCVideoSeek(HVIDEODECODER hVideo, double dTime, BOOL accurate = TRUE);
procedure PCVideoSeek(hVideo: HVIDEODECODER; dTime: double; accurate : BOOL = TRUE); stdcall;

//void __stdcall PCAudioSeek(HAUDIODECODER hAudio, double dTime);
procedure PCAudioSeek(hAudio: HAUDIODECODER; dTime: double); stdcall;


implementation

const
  DLLNAME = 'WS_DataProcess.dll';

function  PCVideoCreate; external DLLNAME  index 1;
procedure PCVideoDestroy; external DLLNAME index 2;
function  PCAudioCreate; external DLLNAME  index 3;
procedure PCAudioDestroy; external DLLNAME index 4;
procedure PCSetCropRect; external DLLNAME  index 5;
procedure PCSetVideoBrightness; external DLLNAME Name 'PCSetVideoBrightness';
procedure PCSetContrast; external DLLNAME Name 'PCSetContrast';
procedure PCSetVideoSaturation; external DLLNAME Name 'PCSetVideoSaturation';
procedure PCSetWatermarkSrcID; external DLLNAME index 9;
procedure PCSetWatermarkSrcIDAlign; external DLLNAME Name 'PCSetWatermarkSrcIDAlign';
procedure PCSetVolum; external DLLNAME Name 'PCSetVolum';
procedure PCDisableWatermark; external DLLNAME index 11;
function  PCCaptureImage; external DLLNAME index 12;
procedure PCSetExFilterFlag; external DLLNAME Name 'PCSetExFilterFlag';
procedure PCSetFlipFlag; external DLLNAME Name 'PCSetFlipFlag';
procedure PCSetWatermarkImage; external DLLNAME Name 'PCSetWatermarkImage';
procedure PCSetWatermarkImageAlign; external DLLNAME Name 'PCSetWatermarkImageAlign';
Procedure PCSetUserWatermarkImage; external DLLNAME Name 'PCSetUserWatermarkImage';
procedure PCSetVideoDeintelace; external DLLNAME Name 'PCSetVideoDeintelace';
procedure PCVideoSeek; external DLLNAME Name 'PCVideoSeek';
procedure PCAudioSeek; external DLLNAME Name 'PCAudioSeek';

end.
 