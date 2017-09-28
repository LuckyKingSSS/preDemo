unit
	TClip;

{$MINENUMSIZE 4}
    
interface

uses
    Windows;

type
	HCLIP	   = Pointer; 	// BaseClip���������塣
	HIMAGECLIP = Pointer; 	// ImageClip���������塣
	HTITLECLIP = Pointer; 	// TitleClip���������塣
	HVIDEOCLIP = Pointer; 	// VideoClip���������塣
	HAUDIOCLIP = Pointer; 	// AudioClip���������塣
	HTRANSCLIP = Pointer; 	// TransClip���������塣
	
	
{$IFNDEF CLIP_PARAM_DEF}
{$DEFINE CLIP_PARAM_DEF}

// Clip���Ͷ���
type
ClipType = 
(
	CT_NONE,
	CT_VIDEO,		// ��Ƶ 
	CT_IMAGE,		// ͼ�� 
	CT_TITLE,		// ��Ļ 
	CT_AUDIO,		// ��Ƶ 
	CT_TRANSITION	// ת�� 
);

// ����״̬
type
ClipWorkState =
(
	CWS_NORMAL		= $0001,		// ����
	CWS_SELECTED	= $0002,		// ѡ��״̬
	CWS_FOCUS		= $0004		// ӵ�н���
);

// ����״̬
type
ClipAttributeState =
(
	CAS_NORMAL		= $0001,		// ����
	CAS_LOCKED		= $0002,		// ����״̬
	CAS_FROZEN		= $0004		// ����״̬
);

{$ENDIF}  //  CLIP_PARAM_DEF

{$IFNDEF IMAGE_RESIZE_METHOD_DEFINE}
{$DEFINE IMAGE_RESIZE_METHOD_DEFINE}
  IMAGE_RESIZE_METHOD =
  (
    IRM_FULLSCREEN,		        // stretch to full screen
    IRM_ORIGINAL_SCALE,			// keep scale, fit to size of output
    IRM_16_9,					// resize to 16:9, fit to size of output
    IRM_4_3,					// resize to 4:3, fit to size of output
 	IRM_LETTERBOX,
	IRM_PAN_SCAN
 );
{$ENDIF}  //  IMAGE_RESIZE_METHOD_DEFINE


//HCLIP __stdcall TCClone(HCLIP hClip);		// ����Clip
function TCClone(hClip: HCLIP) : HCLIP; stdcall;

//HCLIP __stdcall TCCreate(ClipType nType);	// ����Clip
function TCCreate(nType: ClipType) : HCLIP; stdcall;

//int __stdcall TCRelease(HCLIP hClip);		// �ͷ�Clip
function TCRelease(hClip: HCLIP) : Integer; stdcall;

//int __stdcall TCAddRef(HCLIP hClip);		// ������ü���
function TCAddRef(hClip: HCLIP) : Integer; stdcall;


//ClipType __stdcall TCGetType(HCLIP hClip);
function TCGetType(hClip: HCLIP) : ClipType; stdcall;

//void __stdcall TCSetBeginTime(HCLIP hClip, double dBeginTime, double dLength = -1); 
procedure TCSetBeginTime(hClip: HCLIP; dBeginTime : double; dLength : double = -1); stdcall;

//double __stdcall TCGetBeginTime(HCLIP hClip);
function TCGetBeginTime(hClip: HCLIP) : double; stdcall;

//double __stdcall TCGetEndTime(HCLIP hClip);
function TCGetEndTime(hClip: HCLIP) : double; stdcall;

//double __stdcall TCGetLength(HCLIP hClip);// ��ȡ��ǰ����
function TCGetLength(hClip: HCLIP) : double; stdcall;

//void __stdcall TCSetLength(HCLIP hClip, double dLength);
procedure TCSetLength(hClip: HCLIP; dLength : double); stdcall;

//DWORD __stdcall TCGetUserData(HCLIP hClip);
function TCGetUserData(hClip: HCLIP) : DWORD; stdcall;

//DWORD __stdcall TCSetUserData(HCLIP hClip, DWORD dwUserData); // ������ǰ��UserData
function TCSetUserData(hClip: HCLIP; dwUserData : DWORD) : DWORD; stdcall;


//double __stdcall TCGetPhysicalLength(HCLIP hClip); // ����Clip�����ȣ�������Ƶ����ƵClip��Ч
function TCGetPhysicalLength(hClip: HCLIP) : double; stdcall;

//double __stdcall TCGetPhysicalBegin(HCLIP hClip); // ����Clip��������ʼλ��
function TCGetPhysicalBegin(hClip: HCLIP) : double; stdcall;

//void __stdcall TCSetPhysicalBegin(HCLIP hClip, double dBegin); // ����Clip��������ʼλ��
procedure TCSetPhysicalBegin(hClip: HCLIP; dBegin : double); stdcall;

//void __stdcall TCSetPhysicalLength(HCLIP hClip, double dLength); // ����Clip��������
procedure TCSetPhysicalLength(hClip: HCLIP; dLength : double); stdcall;


//extern "C" void __stdcall TCSetLabel(HCLIP hClip, const wchar_t* lpLabel); // Ĭ������£�Video��Audio��Image Clip�����ļ���Title��ΪLabel��ת������ID
procedure TCSetLabel(hClip: HCLIP; const lpLabel : PWideChar); stdcall;

//extern "C" const wchar_t* __stdcall TCGetLabel(HCLIP hClip);
function TCGetLabel(hClip: HCLIP) : PWideChar; stdcall;

//extern "C" void __stdcall TCSetFileName(HCLIP hClip, const wchar_t* lpFileName); // ����Video��Audio��Image Clip��Ч
procedure TCSetFileName(hClip: HCLIP; const lpFileName : PWideChar); stdcall;

//extern "C" const wchar_t* __stdcall TCGetFileName(HCLIP hClip);
function TCGetFileName(hClip: HCLIP) : PWideChar; stdcall;


//BOOL __stdcall TCSetBitmap(HCLIP hClip, UINT nID, HINSTANCE hInstance);  // ����ͼ
function TCSetBitmap(hClip: HCLIP; nID : UINT; hModule : HMODULE) : BOOL; stdcall;

//BOOL __stdcall TCSetDib(HCLIP hClip, LPBITMAPINFO lpbi, void* pBits); // ����ͼ Clip�´��hBitmap���ݣ�Ӧ�ó���Ӧ���Զ��ͷ�λͼ����
function TCSetDib(hClip: HCLIP; lpbi : PBITMAPINFO; pBits : pointer) : BOOL; stdcall;

//BOOL __stdcall TCSetHBitmap(HCLIP hClip, HBITMAP hBitmap); // ����ͼ Clip�´��hBitmap���ݣ�Ӧ�ó���Ӧ���Զ��ͷ�hBitmap
function TCSetHBitmap(hClip: HCLIP; hBitmap : HBITMAP) : BOOL; stdcall;

//BOOL __stdcall TCAutoLoadThumbnail(HCLIP hClip); // �Զ���������ͼ ����TIMELINE_QUERY_API�ص����� �ص�����Ӧ�õ���������������֮һ�����ã�����ص�ʧ�� Timeline�����м�������ͼ ������CT_IMAGE��clip
function TCAutoLoadThumbnail(hClip: HCLIP) : BOOL; stdcall;

//DWORD __stdcall TCGetAttribState(HCLIP hClip);
function TCGetAttribState(hClip: HCLIP) : DWORD; stdcall;

//DWORD __stdcall TCGetWorkState(HCLIP hClip);
function TCGetWorkState(hClip: HCLIP) : DWORD; stdcall;

//int	__stdcall TCGetIndex(HCLIP hClip); // ������Track�е�����ֵ
function TCGetIndex(hClip: HCLIP) : Integer; stdcall;

//HCLIP __stdcall TCGetNext(HCLIP hClip);
function TCGetNext(hClip: HCLIP) : HCLIP; stdcall;

//HCLIP __stdcall TCGetPrev(HCLIP hClip);
function TCGetPrev(hClip: HCLIP) : HCLIP; stdcall;


// Title Clip
//extern "C" void __stdcall TTSetText(HTITLECLIP hClip, const wchar_t* lpText);
procedure TTSetText(hClip: HTITLECLIP; const lpText : PWideChar); stdcall;

//extern "C" const wchar_t* __stdcall TTGetText(HTITLECLIP hClip);
function TTGetText(hClip: HTITLECLIP) : PWideChar; stdcall;

// Transition Clip
//extern "C" void __stdcall TRSetTransID(HTRANSCLIP hClip, const wchar_t* lpTransID);
procedure TRSetTransID(hClip: HTRANSCLIP; const lpTransID : PWideChar); stdcall;

//extern "C" const wchar_t* __stdcall TRGetTransID(HTRANSCLIP hClip);
function TRGetTransID(hClip: HTRANSCLIP) : PWideChar; stdcall;



//HTRANSCLIP __stdcall TCGetClipTailTrans(HCLIP hClip); // ȡ��β��ת��
function TCGetClipTailTrans(hClip: HCLIP) : HTRANSCLIP; stdcall;

//HCLIP __stdcall TCGetTransBeginClip(HTRANSCLIP hTrClip); // ȡ��ת��hTrClipǰ���clip
function TCGetTransBeginClip(hTrClip: HTRANSCLIP) : HCLIP; stdcall;

//HTRANSCLIP __stdcall TCGetClipHeadTrans(HCLIP hClip); // ȡ��ͷ��ת��
function TCGetClipHeadTrans(hClip: HCLIP) : HTRANSCLIP; stdcall;

//HCLIP __stdcall TCGetTransEndClip(HTRANSCLIP hTrClip); // ȡ��ת��hTrClip�����clip
function TCGetTransEndClip(hTrClip: HTRANSCLIP) : HCLIP; stdcall;


//BOOL __stdcall TCSetDubbingFlag(HCLIP hClip, BOOL bHasDubbing);
function TCSetDubbingFlag(hClip: HCLIP; bHasDubbing : BOOL) : BOOL; stdcall;

//BOOL __stdcall TCHasDubbing(HCLIP hClip);
function TCHasDubbing(hClip: HCLIP) : BOOL; stdcall;

//void __stdcall TCSetMinLength(HCLIP hClip, double dMinLen);
procedure TCSetMinLength(hClip: HCLIP; dMinLen : double); stdcall;

//double __stdcall TCGetMinLength(HCLIP hClip);
function TCGetMinLength(hClip: HCLIP) : double; stdcall;

//void __stdcall TCSetAudioFadeIn(HCLIP hClip, double dFadeIn);
procedure TCSetAudioFadeIn(hClip: HCLIP; dFadeIn : double); stdcall;

//double __stdcall TCGetAudioFadeIn(HCLIP hClip);
function TCGetAudioFadeIn(hClip: HCLIP) : double; stdcall;

//void __stdcall TCSetAudioFadeOut(HCLIP hClip, double dFadeOut);
procedure TCSetAudioFadeOut(hClip: HCLIP; dFadeOut : double); stdcall;

//double __stdcall TCGetAudioFadeOut(HCLIP hClip);
function TCGetAudioFadeOut(hClip: HCLIP) : double; stdcall;

//void __stdcall TCSetVolume(HCLIP hClip, int nVolume);
procedure TCSetVolume(hClip: HCLIP; nVolume : Integer); stdcall;

//int __stdcall TCGetVolume(HCLIP hClip);
function TCGetVolume(hClip: HCLIP) : Integer; stdcall;

//void __stdcall TCSetVideoOnly(HCLIP hClip, BOOL bVideoOnly = TRUE);
procedure TCSetVideoOnly(hClip: HCLIP; bVideoOnly : BOOL = TRUE); stdcall;

//BOOL __stdcall TCIsVideoOnly(HCLIP hClip)
function TCIsVideoOnly(hClip: HCLIP) : BOOL; stdcall;

//void __stdcall TCSetAudioMute(HCLIP hClip, BOOL bAudioMute = TRUE);
procedure TCSetAudioMute(hClip: HCLIP; bAudioMute : BOOL = TRUE); stdcall;

//BOOL __stdcall TCIsAudioMute(HCLIP hClip)
function TCIsAudioMute(hClip: HCLIP) : BOOL; stdcall;

//void __stdcall TCSetResizeStyle(HCLIP hClip, IMAGE_RESIZE_METHOD uResizeStyle);
procedure TCSetResizeStyle(hClip: HCLIP; uResizeStyle : IMAGE_RESIZE_METHOD); stdcall;

//���ü�������, pCropRect������������, 0 Ϊȡ�����ò���
//void __stdcall TCSetCropRect(HCLIP hClip, RECT* pCropRect);
procedure TCSetCropRect(hClip: HCLIP; pCropRect : PRECT); stdcall;

//�������ȣ�-100��100��0����ԭ����
//void __stdcall TCSetBrightness(HCLIP hClip, int nValue);
procedure TCSetBrightness(hClip: HCLIP; nValue : Integer); stdcall;

//���öԱȶȣ�-100��100��0����ԭ�Աȶ�
//void __stdcall TCSetContrast(HCLIP hClip, int nValue);
procedure TCSetContrast(hClip: HCLIP; nValue : Integer); stdcall;

//���ñ��Ͷ�,-100��100��0����ԭ���Ͷ�
//void __stdcall TCSetSaturation(HCLIP hClip, int nValue); 
procedure TCSetSaturation(hClip: HCLIP; nValue : Integer); stdcall;


//IMAGE_RESIZE_METHOD __stdcall TCGetResizeStyle(HCLIP hClip);
function TCGetResizeStyle(hClip: HCLIP) : IMAGE_RESIZE_METHOD; stdcall;

//���ؼ�������, 0 Ϊ��ʹ�ü���
//const RECT* __stdcall TCGetCropRect(HCLIP hClip);
function TCGetCropRect(hClip: HCLIP) : PRECT; stdcall;

//int __stdcall TCGetBrightness(HCLIP hClip);
function TCGetBrightness(hClip: HCLIP) : Integer; stdcall;

//int __stdcall TCGetContrast(HCLIP hClip);
function TCGetContrast(hClip: HCLIP) : Integer; stdcall;

//int __stdcall TCGetSaturation(HCLIP hClip); 
function TCGetSaturation(hClip: HCLIP) : Integer; stdcall;


implementation


const
    DLLNAME = 'WS_Timeline.dll';

function TCClone; external DLLNAME Name 'TCClone';
function TCCreate; external DLLNAME Name 'TCCreate';
function TCRelease; external DLLNAME Name 'TCRelease';
function TCAddRef; external DLLNAME Name 'TCAddRef';
function TCGetType; external DLLNAME Name 'TCGetType';
procedure TCSetBeginTime; external DLLNAME Name 'TCSetBeginTime';
function TCGetBeginTime; external DLLNAME Name 'TCGetBeginTime';
function TCGetEndTime; external DLLNAME Name 'TCGetEndTime';
function TCGetLength; external DLLNAME Name 'TCGetLength';
procedure TCSetLength; external DLLNAME Name 'TCSetLength';
function TCGetUserData; external DLLNAME Name 'TCGetUserData';
function TCSetUserData; external DLLNAME Name 'TCSetUserData';
function TCGetPhysicalLength; external DLLNAME Name 'TCGetPhysicalLength';
function TCGetPhysicalBegin; external DLLNAME Name 'TCGetPhysicalBegin';
procedure TCSetPhysicalBegin; external DLLNAME Name 'TCSetPhysicalBegin';
procedure TCSetPhysicalLength; external DLLNAME Name 'TCSetPhysicalLength';
procedure TCSetLabel; external DLLNAME Name 'TCSetLabel';
function TCGetLabel; external DLLNAME Name 'TCGetLabel';
procedure TCSetFileName; external DLLNAME Name 'TCSetFileName';
function TCGetFileName; external DLLNAME Name 'TCGetFileName';
function TCSetBitmap; external DLLNAME Name 'TCSetBitmap';
function TCSetDib; external DLLNAME Name 'TCSetDib';
function TCSetHBitmap; external DLLNAME Name 'TCSetHBitmap';
function TCAutoLoadThumbnail; external DLLNAME Name 'TCAutoLoadThumbnail';
function TCGetAttribState; external DLLNAME Name 'TCGetAttribState';
function TCGetWorkState; external DLLNAME Name 'TCGetWorkState';
function TCGetIndex; external DLLNAME Name 'TCGetIndex';
function TCGetNext; external DLLNAME Name 'TCGetNext';
function TCGetPrev; external DLLNAME Name 'TCGetPrev';
procedure TTSetText; external DLLNAME Name 'TTSetText';
function TTGetText; external DLLNAME Name 'TTGetText';
procedure TRSetTransID; external DLLNAME Name 'TRSetTransID';
function TRGetTransID; external DLLNAME Name 'TRGetTransID';
function TCGetClipTailTrans; external DLLNAME Name 'TCGetClipTailTrans';
function TCGetTransBeginClip; external DLLNAME Name 'TCGetTransBeginClip';
function TCGetClipHeadTrans; external DLLNAME Name 'TCGetClipHeadTrans';
function TCGetTransEndClip; external DLLNAME Name 'TCGetTransEndClip';
function TCSetDubbingFlag; external DLLNAME Name 'TCSetDubbingFlag';
function TCHasDubbing; external DLLNAME Name 'TCHasDubbing';
procedure TCSetMinLength; external DLLNAME Name 'TCSetMinLength';
function TCGetMinLength; external DLLNAME Name 'TCGetMinLength';

procedure TCSetAudioFadeIn; external DLLNAME Name 'TCSetAudioFadeIn';
function TCGetAudioFadeIn; external DLLNAME Name 'TCGetAudioFadeIn';
procedure TCSetAudioFadeOut; external DLLNAME Name 'TCSetAudioFadeOut';
function TCGetAudioFadeOut; external DLLNAME Name 'TCGetAudioFadeOut';
procedure TCSetVolume; external DLLNAME Name 'TCSetVolume';
function TCGetVolume; external DLLNAME Name 'TCGetVolume';
procedure TCSetVideoOnly; external DLLNAME Name 'TCSetVideoOnly';
function TCIsVideoOnly; external DLLNAME Name 'TCIsVideoOnly';
procedure TCSetAudioMute; external DLLNAME Name 'TCSetAudioMute';
function TCIsAudioMute; external DLLNAME Name 'TCIsAudioMute';

function TCGetResizeStyle; external DLLNAME Name 'TCGetResizeStyle';
function TCGetCropRect; external DLLNAME Name 'TCGetCropRect';
function TCGetBrightness; external DLLNAME Name 'TCGetBrightness';
function TCGetContrast; external DLLNAME Name 'TCGetContrast';
function TCGetSaturation; external DLLNAME Name 'TCGetSaturation';

procedure TCSetResizeStyle; external DLLNAME Name 'TCSetResizeStyle';
procedure TCSetCropRect; external DLLNAME Name 'TCSetCropRect';
procedure TCSetBrightness; external DLLNAME Name 'TCSetBrightness';
procedure TCSetContrast; external DLLNAME Name 'TCSetContrast';
procedure TCSetSaturation; external DLLNAME Name 'TCSetSaturation';


end.

