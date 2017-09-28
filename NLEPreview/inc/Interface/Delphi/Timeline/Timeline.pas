unit TimeLine;

{$MINENUMSIZE 4}

interface

uses
    Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
    Dialogs, TDoc, TMsg, TClip;

type
    HTIMELINE = Pointer;
    LPVOID = Pointer;

    TRACKCONFIG = record			// ������ò����ṹ
        nVideoTrackCount: UINT;		// ��Ƶ�������
        nAudioTrackCount: UINT;		// ��Ƶ�������
        nOverlapTrackCount: UINT;	// ���ӹ������
 		bUseSubAudio: BOOL;			// �Ƿ�ʹ�ø�����Ƶ���
		bUseSubTrans: BOOL;			// �Ƿ�ʹ�ø���ת�����
    end;
    LPTRACKCONFIG = ^TRACKCONFIG;

	TRANSIMAGE = record							// ת��ͼ������ṹ
		szTransID : Array[0..63] of WideChar;	// ת��ID
		uBmpID : UINT;							// ��ԴID
		hInst : HMODULE;						// ��Դģ����
    end;
    LPTRANSIMAGE = ^TRANSIMAGE;


//DWORD __stdcall InitTimeline(LPVOID pvReserved); // ��ʼ��Timeline Ӧ�ó�������ʱ����
function InitTimeline(pvReserved: LPVOID) : DWORD; stdcall;

//void __stdcall UninitTimeline(); // ж��Timeline Ӧ�ó������ʱ����
procedure UninitTimeline(); stdcall;

procedure DestroyTimeline(hTimeline: HTIMELINE); stdcall; // ����Timeline����

function CreateTimeline(hParentWnd: HWND; // ������
    lpRect: PRECT; // ����λ��ָ��
    lpTrackConfig: LPTRACKCONFIG; // �����������ָ��
    lpReserved: LPVOID // ���������Ժ���չ��
    ): HTIMELINE; stdcall;
    

// ȡ��Timeline HWND���
//HWND __stdcall GetTimelineHwnd(HTIMELINE hTimeline);
function GetTimelineHwnd(hTimeline: HTIMELINE) : HWND; stdcall;


// ����Timeline������ɫ���ò���  
// nID     - ��ɫID
// dwColor - ��ɫֵ�Ӹ��ֽڵ����ֽڷֱ��ʾA��R��G��B��ȡֵ������A������ɫ�Ĳ�͸���ȣ�0xFF��ʾȫ��͸����0x00��ʾȫ͸����
//BOOL __stdcall SetColors (UINT nID, DWORD dwColor);
function SetColors(nID : UINT; dwColor: DWORD) : BOOL; stdcall;


// ����Timeline���������ı�
// nID    - �ı�ID ��TIMELINE_TEXT_ID
// lpText - ָ�������ı���UNICODE���ַ���ָ�롣
// ���IDΪ0����lpTextΪNULL����ԭȫ��ϵͳĬ�������ı���
//extern "C" BOOL __stdcall SetLanguageText (UINT nID, const wchar_t* lpText);
function SetLanguageText(nID : UINT; lpText: pWideChar) : BOOL; stdcall;

// TIMELINE_TEXT_ID
const
TTI_CLOSE					= 1;	// Close
TTI_HIDE					= 2;	// Hide
TTI_SHOW					= 3;	// Show
TTI_VIDEO					= 4;	// Video
TTI_AUDIO					= 5;	// Audio
TTI_SUBAUDIO				= 6;	// SubAudio
TTI_SUBTRANS				= 7;	// SubTrans
TTI_OVERLAP					= 8;	// Title Overlap
TTI_STORYBOARD_LOGO			= 100;	// Story Board



// ˢ��Timeline���棨ǿ���ػ���
//void __stdcall UpdateTimeline(HTIMELINE hTimeline);
procedure UpdateTimeline(hTimeline: HTIMELINE); stdcall;

//DWORD __stdcall SendTimelineCommand(HTIMELINE hTimeline, UINT uMsgCode, WPARAM wParam, LPARAM lParam); // uMsgCode �� "TimelineMsg.h" �ж���
function SendTimelineCommand(hTimeline: HTIMELINE; uMsgCode : UINT; wParam: WPARAM; lParam: LPARAM) : DWORD; stdcall; // uMsgCode �� "TimelineMsg.pas" �ж���

//typedef DWORD(__stdcall * TIMELINE_EVENT_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam); // nMsgID ��"TimelineMsg"��Callback��Ϣ����
type
  TIMELINE_EVENT_CALLBACK = function(pUserObj: Pointer; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): DWORD; stdcall; 

// �����¼��ص��ӿں���
//void __stdcall SetTimelineEventCallback(HTIMELINE hTimeline, TIMELINE_EVENT_CALLBACK fnEventCallback, void* pUserObj);
procedure SetTimelineEventCallback(hTimeline : HTIMELINE; fnEventCallback: TIMELINE_EVENT_CALLBACK; pUserObj: Pointer); stdcall; 

//typedef DWORD(__stdcall * TIMELINE_QUERY_API)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam); // ��ʱ���ڲ�ѯת��Сͼ����ļ���Ϣ 
type
  TIMELINE_QUERY_API = function(pUserObj: Pointer; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): DWORD; stdcall; // ��ʱ���ڲ�ѯת��Сͼ����ļ���Ϣ
// uMsg: 0 - ��ѯ����ͼ  ����0Ϊʧ�� Ӧ�ó���Ӧ�õ���TCSetDib��TCSetBitmap��TCSetHBitmap������������ͼ ��������ת�� �����TCSetLabel��������Label
//              lParam - HCLIP���
//       1 - ��ѯ�����ЧID  ����0Ϊʧ��       
//              lParam - pointer of wchar_t[64]
//		 2 - ��ѯý���ʽ�������ݸ�ʽ����HCLIP�� ����HCLIP��� 0Ϊʧ�� ������HCLIP�����Ҫʹ��TCRelease�ͷ� �������Ƶ��ʹ��TCSetPhysicalLength������Ƶ����
//              lParam - ָ���ļ�����wchar_tָ�� ��'\0'����
// ���ò�ѯ�ص��ӿں���
//void __stdcall SetTimelineQueryCallback(TIMELINE_QUERY_API fnQueryCallback, void* pUserObj); // ���ò�ѯ�ӿ�
procedure SetTimelineQueryCallback(fnQueryCallback: TIMELINE_QUERY_API; pUserObj: Pointer); stdcall; // ���ò�ѯ�ӿ�

//typedef DWORD(__stdcall * TIMELINE_LOG_API)(void* pUserObj, const wchar_t* pLogText, DWORD dwReserved); // ��־�ص�����
type
  TIMELINE_LOG_API = function(pUserObj: Pointer; const pLogText: PWideChar; dwReserved: DWORD): DWORD; stdcall; 
// ������־�ص��ӿں���
//void __stdcall SetTimelineLogCallback(TIMELINE_LOG_API fnLogCallback, void* pUserObj); 
procedure SetTimelineLogCallback(fnLogCallback: TIMELINE_LOG_API; pUserObj: Pointer); stdcall; 
// ��־�Ͳ�ѯ�ص�����ȫ�ֻص�

type
	DRAW_CLIP_ITEM = record
		uViewMode : UINT;		// ��ͼ 0 - ���°�
		nItem : Integer;		// Item ����
		nViewIndex : Integer;		// ����ͼ�ϵĿɼ�Item����
		hClip : HCLIP;
		hDC : HDC;
		rcItem : TRECT;
		bTransArea : BOOL;	// �Ƿ�ת������
	end;
    LPDRAW_CLIP_ITEM = ^DRAW_CLIP_ITEM;

//typedef DWORD(__stdcall * TIMELINE_DRAWITEM_API)(void* pUserObj, WPARAM wParam, LPARAM lParam); // Clip���ƻص����� lParam - pointer of DRAW_CLIP_ITEM
type
  TIMELINE_DRAWITEM_API = function(pUserObj: Pointer; wParam: WPARAM; lParam: LPARAM): DWORD; stdcall;
// Clip���ƻص��ӿں���
//void __stdcall SetTimelineDrawCallback(HTIMELINE hTimeline, TIMELINE_DRAWITEM_API fnDrawCallback, void* pUserObj); 
procedure SetTimelineDrawCallback(hTimeline : HTIMELINE; fnDrawCallback: TIMELINE_DRAWITEM_API; pUserObj: Pointer); stdcall; 


// �����Ƿ��Զ��ػ�����ͨ���ӿ���ӡ�ɾ�����޸�Ԫ��ʱ�Ƿ��Զ��ػ��� Ĭ��Ϊ�Զ��ػ�
//void __stdcall SetAutoRedraw(HTIMELINE hTimeline, BOOL bFlag); 
procedure SetAutoRedraw(hTimeline : HTIMELINE; bFlag : BOOL); stdcall;

// �򿪡������¼��ص�
//void __stdcall EnableEventCallback(HTIMELINE hTimeline, BOOL bEnable);
procedure EnableEventCallback(hTimeline : HTIMELINE; bEnable: BOOL); stdcall; 

// ȡ��Timeline�ĵ�������
//HTLDOC __stdcall GetTimelineDoc(HTIMELINE hTimeline);
function GetTimelineDoc(hTimeline: HTIMELINE) : HTLDOC; stdcall; 


//==========================================================
// Timeline OleDragDrop ý������ӿ�
// CLIPFORMAT Name�������£�
const
 TIMELINE_MEDIA_FORAMT_NAME	= ('Timeline Media File');
 TIMELINE_IMAGE_FORAMT_NAME	= ('Timeline Image File');
 TIMELINE_VIDEO_FORAMT_NAME	= ('Timeline Video File');
 TIMELINE_AUDIO_FORAMT_NAME	= ('Timeline Audio File');
 TIMELINE_TRANS_FORAMT_NAME	= ('Timeline Transition');
 TIMELINE_TITLE_FORAMT_NAME	= ('Timeline Title');

// ��Ole���ݽṹͬDROPFILES�ӿ���ȫһ�� ͷ������ΪһDROPFILES�ṹ������ ������������ļ������ļ���֮����'\0'�ָ���
// tymed ��Ϊ TYMED_HGLOBAL
// cfFormat Ϊ����CLIPFORMAT Nameע�����

// ʾ�����磺
//HGLOBAL MakeMediaClips()
//{
//	HGLOBAL hBuffer = GlobalAlloc(GPTR, sizeof(DROPFILES) + 1024 * 2 + 4 + 2);
//	LPDROPFILES pDropFiles = (LPDROPFILES)GlobalLock(hBuffer);
//
//	pDropFiles->pFiles = sizeof(DROPFILES);
//	pDropFiles->fWide=TRUE;
//
//	wchar_t* pName = (wchar_t*)((BYTE*)pDropFiles + sizeof(DROPFILES));
//	wcscpy(pName, L"G:\\beautifull.jpg");
//	pName += lstrlen(pName) + 1;
//	wcscpy(pName, L"G:\\Demo.jpg");
//
//	GlobalUnlock(hBuffer);
//
//	return hBuffer;
//}

//	DWORD cfTimelineImageFile = RegisterClipboardFormat(TIMELINE_IMAGE_FORAMT_NAME);
//	FORMATETC cImageFileFmt = {(CLIPFORMAT) cfTimelineImageFile, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL};
//	
//	IDataObjectImpl	DragData;
//	IDropSourceImpl DropSource;
//
//	STGMEDIUM medium = { 0 }; 
//	medium.tymed = TYMED_HGLOBAL;
//	medium.hGlobal = MakeMediaClips();
//	DragData.SetData(&cImageFileFmt, &medium, TRUE);
//
//	DWORD dwEffect = (DWORD)-1;
//	HRESULT hr = ::DoDragDrop(&DragData, &DropSource, DROPEFFECT_COPY, &dwEffect);
//

//==========================================================================================================
// PhotoViewer����ӿ�
// TPhoto�ṹ�� dwReserved ʹ������ֵ��
const
 DRAG_TRANS_ID		= 1000;  // strReserved - ת��ID��Unicode�ַ�����
 DRAG_VIDEO_FILE	= 1001;  // FilePath - �ļ�����Unicode�ַ�����
 DRAG_AUDIO_FILE	= 1002;  // FilePath - �ļ�����Unicode�ַ�����
 DRAG_IMAGE_FILE	= 0;     // FilePath - �ļ�����Unicode�ַ�����


implementation

const
    DLLNAME = 'WS_Timeline.dll';

function InitTimeline; external DLLNAME Name 'InitTimeline';
procedure UninitTimeline; external DLLNAME Name 'UninitTimeline';
procedure DestroyTimeline; external DLLNAME Name 'DestroyTimeline';
function CreateTimeline; external DLLNAME Name 'CreateTimeline';
function GetTimelineHwnd; external DLLNAME Name 'GetTimelineHwnd';
function SetColors; external DLLNAME Name 'SetColors';
function SetLanguageText; external DLLNAME Name 'SetLanguageText';
procedure UpdateTimeline; external DLLNAME Name 'UpdateTimeline';
function SendTimelineCommand; external DLLNAME Name 'SendTimelineCommand';
procedure SetTimelineEventCallback; external DLLNAME Name 'SetTimelineEventCallback';
procedure SetTimelineQueryCallback; external DLLNAME Name 'SetTimelineQueryCallback';
procedure SetTimelineLogCallback; external DLLNAME Name 'SetTimelineLogCallback';
procedure SetTimelineDrawCallback; external DLLNAME Name 'SetTimelineDrawCallback';
procedure SetAutoRedraw; external DLLNAME Name 'SetAutoRedraw';
procedure EnableEventCallback; external DLLNAME Name 'EnableEventCallback';
function GetTimelineDoc; external DLLNAME Name 'GetTimelineDoc';

end.

 