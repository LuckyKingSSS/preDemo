// VideoLibrary.pas
unit
  VideoLibrary;

interface

uses
  windows, WSVideoInfo, WSAudioInfo;

type
  VL_SORT_TYPE =
  (
    VLST_FILENAME,      // ���ļ�������
	  VLST_VIDEO_LENGTH   // ����Ƶ�ļ����ȣ�ʱ�䣩����
  );

type
  HVIDEOLIBRARY = Pointer;

// ����һ��VideoLibrary
// HVIDEOLIBRARY __stdcall VLCreateVideoLibrary();
function VLCreateVideoLibrary() : HVIDEOLIBRARY; stdcall;

// void __stdcall VLDestroyVideoLibrary(HVIDEOLIBRARY hVidLibrary);
procedure VLDestroyVideoLibrary(hVidLibrary : HVIDEOLIBRARY); stdcall;

// ��xml�ĵ�����ȡxml�ļ����ݶ�VideoLibrary���г�ʼ������ɺ󼴹رո�xml�ĵ���
// BOOL __stdcall VLLoadXml(HVIDEOLIBRARY hVidLibrary, const wchar_t* pXmlPath);
function VLLoadXml(hVidLibrary : HVIDEOLIBRARY; const pXmlPath : PWideChar) : BOOL; stdcall;

// ��VideoLibrary������ָ��xml�ĵ�����ͬ���ļ�ʱ����ԭ�ļ�����ͬ���ļ�ʱ�������ļ���
// BOOL __stdcall VLSaveXml(HVIDEOLIBRARY hVidLibrary, const wchar_t* pXmlPath);
function VLSaveXml(hVidLibrary : HVIDEOLIBRARY; const pXmlPath : PWideChar) : BOOL; stdcall;

// ȡVideoLibrary����Ƶ����������-1Ϊ����ʧ��
// int __stdcall VLGetVideoCount(HVIDEOLIBRARY hVidLibrary);
function VLGetVideoCount(hVidLibrary : HVIDEOLIBRARY) : Integer; stdcall;

// ��VideoLibraryָ��λ��nIndex����һ����ƵԪ�أ���nIndexΪ-1�������ĩβ������ֵΪ����ƵԪ���ڵ�λ��ID��ʧ�ܷ��� -1
// int  __stdcall VLInsertVideoItem(HVIDEOLIBRARY hVidLibrary, const wchar_t* pFilePath, int nIndex);
function VLInsertVideoItem(hVidLibrary : HVIDEOLIBRARY; const pFilePath : PWideChar; nIndex: Integer) : Integer; stdcall;

// ��VideoLibrary���Ƴ�IDΪnIndex��VideoItem��nIndexΪ-1ʱ���Ƴ�����VideoItem
// BOOL __stdcall VLRemoveVideoItem(HVIDEOLIBRARY hVidLibrary, int nIndex);
function VLRemoveVideoItem(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer) : BOOL; stdcall;

// ��ID�Ŵ�nSrcIndex���nCount��VideoItem����nDstIndex�����ƶ�ǰIDΪ׼
// BOOL __stdcall VLMoveVideoItem(HVIDEOLIBRARY hVidLibrary, int nDstIndex, int nSrcIndex, int nCount);
function VLMoveVideoItem(hVidLibrary : HVIDEOLIBRARY; nDstIndex : Integer; nSrcIndex : Integer; nCount : Integer) : BOOL; stdcall;

// ��eSortTypeָ��key���ͽ�������bAscendΪTRUEʱΪ����FALSEΪ����
function VLSort(hVidLibrary : HVIDEOLIBRARY; eSortType : VL_SORT_TYPE; bAscend : BOOL) : BOOL; stdcall;

// ����IDΪnIndex����Ƶ�ļ���·����ȫ·����
// int __stdcall VLGetFilePath(HVIDEOLIBRARY hVidLibrary, int nIndex, wchar_t* szFilePath, int nFilePathLength);
function VLGetFilePath(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; szFilePath : PWideChar; nFilePathLength : Integer) : Integer; stdcall;

//
// BOOL __stdcall VLGetVideoInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, VideoInfo* pInfo);
// BOOL __stdcall VLSetVideoInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, const VideoInfo* pInfo);
function VLGetVideoInfo(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; pInfo : PVideoInfo) : BOOL; stdcall;
function VLSetVideoInfo(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; const pInfo : PVideoInfo) : BOOL; stdcall;

// BOOL __stdcall VLGetAudioInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, AudioInfo* pInfo);
// BOOL __stdcall VLSetAudioInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, const AudioInfo* pInfo);
function VLGetAudioInfo(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; pInfo : PAudioInfo) : BOOL; stdcall;
function VLSetAudioInfo(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; const pInfo : PAudioInfo) : BOOL; stdcall;

// szFileNameΪ����ͼ�ļ���������·����
// int __stdcall VLGetThumbnailName(HVIDEOLIBRARY hVidLibrary, int nIndex, wchar_t* szFileName, int nFileNameLength);
// BOOL __stdcall VLSetThumbnailName(HVIDEOLIBRARY hVidLibrary, int nIndex, const wchar_t* szFileName);
function VLGetThumbnailName(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; szFileName : PWideChar; nFileNameLength : Integer) : Integer; stdcall;
function VLSetThumbnailName(hVidLibrary : HVIDEOLIBRARY; nIndex: Integer; const pFileName : PWideChar) : BOOL; stdcall;

// �ж��ļ��Ƿ��޸�
//BOOL __stdcall VLGetVideoChangeTime(HVIDEOLIBRARY hVidLibrary, int nIndex, FILETIME* pFileTime);
//BOOL __stdcall VLSetVideoChangeTime(HVIDEOLIBRARY hVidLibrary, int nIndex, FILETIME* pFileTime);

function VLGetVideoChangeTime(hVidLibrary : HVIDEOLIBRARY; nIndex : integer; pTime : pFILETIME) : BOOL; stdcall;
function VLSetVideoChangeTime(hVidLibrary : HVIDEOLIBRARY; nIndex : integer; pTime : pFILETIME) : BOOL; stdcall;

implementation

const
    DLLNAME = 'WS_VideoLibrary.dll';

function  VLCreateVideoLibrary    ; external DLLNAME Name 'VLCreateVideoLibrary';
procedure VLDestroyVideoLibrary   ; external DLLNAME Name 'VLDestroyVideoLibrary';
function  VLLoadXml               ; external DLLNAME Name 'VLLoadXml';
function  VLSaveXml               ; external DLLNAME Name 'VLSaveXml';
function  VLGetVideoCount         ; external DLLNAME Name 'VLGetVideoCount';
function  VLInsertVideoItem       ; external DLLNAME Name 'VLInsertVideoItem';
function  VLRemoveVideoItem       ; external DLLNAME Name 'VLRemoveVideoItem';
function  VLMoveVideoItem         ; external DLLNAME Name 'VLMoveVideoItem';
function  VLSort                  ; external DLLNAME Name 'VLSort';

function  VLGetFilePath           ; external DLLNAME Name 'VLGetFilePath';
function  VLGetVideoInfo          ; external DLLNAME Name 'VLGetVideoInfo';
function  VLSetVideoInfo          ; external DLLNAME Name 'VLSetVideoInfo';
function  VLGetAudioInfo          ; external DLLNAME Name 'VLGetAudioInfo';
function  VLSetAudioInfo          ; external DLLNAME Name 'VLSetAudioInfo';
function  VLGetThumbnailName      ; external DLLNAME Name 'VLGetThumbnailName';
function  VLSetThumbnailName      ; external DLLNAME Name 'VLSetThumbnailName';
function  VLGetVideoChangeTime    ; external DLLNAME Name 'VLGetVideoChangeTime';
function  VLSetVideoChangeTime    ; external DLLNAME Name 'VLSetVideoChangeTime';

end.
