
unit
	ProjectDoc;

{$MINENUMSIZE 4}

interface

uses
    Windows, DVDMenuItem, EncParam, TClip;

type
  TClipInfo = record
    uType         :	ClipType;		// Clip����
    dBeginTime    :	double;			// ��Timeline�ϵ���ʼʱ��
    dLength       :	double;			// ��Timeline�ϳ���ʱ�䳤��
    dTrimFrom     :	double;

    szFileName    : array[0..512 - 1] of WideChar;	//
    szTransID     :	array[0..64 - 1] of WideChar;	// β��ת��ID

    dAudioFadeIn  :	double;			// ��Ƶ���루�룩
    dAudioFadeOut :	double;			// ��Ƶ����

    nVolume       :	integer;		// ����,0~200, 100����ԭ����
    bAudioMute    :	BOOL;
    nBrightness   :	integer;		// ���ȣ�-100��100��0����ԭ����
    nContrast     :	integer;		// �Աȶȣ�-100��100��0����ԭ�Աȶ�
    nSaturation   :	integer;		// ���Ͷ�,-100��100��0����ԭ���Ͷ�
    bUseCropRect  :	BOOL;
    rcCrop        :	TRECT;

    uResizeStyle  :	IMAGE_RESIZE_METHOD;
    dwTransLength : DWORD;
	end;
type
  PTClipInfo = ^TClipInfo;
type
  HPROJDOC = pointer;

type
  DvdBurnerParam = record
	szTempPath		: array[0..512-1] of WideChar;
	szDVDFolder		: array[0..512-1] of WideChar;
	szIsoFileName	: array[0..512-1] of WideChar;
	szVolumeLabel	: array[0..64-1] of WideChar;
	bBurnToIso		: BOOL;
	bSaveDVDFolder	: BOOL;
	nBurnDriver		: integer;
	nBurnEngine		: integer;
	dwNorm			: DWORD;     // ������ʽ                            
	dwAspect		: DWORD;   // ����     
	dwDiskType		: DWORD;	// ��������
	dwQuality		: DWORD;
	end;
	
type PDvdBurnerParam = ^DvdBurnerParam;

//��ʼ��TClipInfo�ṹ��
//void __stdcall PDInitClipInfo(TClipInfo* pClipInfo);
procedure PDInitClipInfo(pClipInfo: PTClipInfo); stdcall;

//HPROJDOC __stdcall PDCreateProjDoc();
function PDCreateProjDoc(): HPROJDOC ; stdcall;

//void __stdcall PDDestroyProjDoc(HPROJDOC hProjDoc);
procedure PDDestroyProjDoc(hProjDoc: HPROJDOC); stdcall;

//���һ��Slideshow
//int __stdcall PDAddSlideshow(HPROJDOC hProjDoc, const EncodeParam* pEncParam);
function PDAddSlideshow(hProjDoc: HPROJDOC; pEncParam: PEncodeParam): integer; stdcall;

//����ClipInfo
//int __stdcall PDAddClip(HPROJDOC hProjDoc, int nSlideIndex, const TClipInfo* pClipInfo);
function PDAddClip(hProjDoc: HPROJDOC; nSlideIndex: integer; pClipInfo: PTClipInfo): integer; stdcall;

//��ȡSlideshow����
//int __stdcall PDGetSlideshowCount(HPROJDOC hProjDoc);
function PDGetSlideshowCount(hProjDoc: HPROJDOC): integer; stdcall;

//��ȡSlideshow��Ϣ
//BOOL __stdcall PDGetSlideshowInfo(HPROJDOC hProjDoc, int nSlideIndex, EncodeParam* pEncParam);
function PDGetSlideshowInfo(hProjDoc: HPROJDOC; nSlideIndex: integer; pEncParam: PENCODEPARAM): BOOL; stdcall;

//��ȡSlideshow������Clip����
//int __stdcall PDGetClipCount(HPROJDOC hProjDoc, int nSlideIndex);
function PDGetClipCount(hProjDoc: hProjDoc; nSlideIndex: Integer): integer; stdcall;

//��ȡClipInfo
//BOOL __stdcall PDGetClipInfo(HPROJDOC hProjDoc, int nSlideIndex, int nClipIndex, TClipInfo* pClipInfo);
function PDGetClipInfo(hProjDoc: HPROJDOC; nSlideIndex: integer; nClipIndex: integer; pClipInfo: PTClipInfo): BOOL; stdcall;

//---
//BOOL __stdcall PDSaveToFile(HPROJDOC hProjDoc, LPCWSTR pszFilePath);
function PDSaveToFile(hProjDoc: HPROJDOC; pszFile: PWideChar): BOOL; stdcall;

//BOOL __stdcall PDLoadFromFile(HPROJDOC hProjDoc, LPCWSTR pszFilePath);
function PDLoadFromFile(hProjDoc: HPROJDOC; pszFilePath: PWideChar): BOOL; stdcall;

//BOOL __stdcall PDSetMenuXml(HPROJDOC hProjDoc, LPCWSTR pszXml);
function PDSetMenuXml(hProjDoc: HPROJDOC; const pszXml: PWideChar): BOOL; stdcall;

//int __stdcall PDGetMenuXml(HPROJDOC hProjDoc, LPWSTR pszXml, int nLen);
function PDGetMenuXml(hProjDoc: HPROJDOC; pszXml: PWideChar; nLen: integer): integer; stdcall;

//BOOL __stdcall PDSetProjSettingXml(HPROJDOC hProjDoc, LPCWSTR pszXml);
function PDSetProjSettingXml(hProjDoc: HPROJDOC; pszXml: PWideChar): BOOL; stdcall;

//int __stdcall PDGetProjSettingXml(HPROJDOC hProjDoc, LPWSTR pszXml, int nLen);
function PDGetProjSettingXml(hProjDoc: HPROJDOC; pszXml: PWideChar; nLen: integer): integer; stdcall;

//BOOL __stdcall PDSetDvdBurnerParam(HPROJDOC hProjDoc, const DvdBurnParam* pBurnerParam);
function PDSetDvdBurnerParam(hPD: HPROJDOC; const pBurnerParam: PDvdBurnerParam): BOOL; stdcall;

//BOOL __stdcall PDGetDvdBurnerParam(HPROJDOC hProjDoc, DvdBurnParam* pBurnerParam);
function PDGetDvdBurnerParam(hPD: HPROJDOC; pBurnerParam: PDvdBurnerParam): BOOL; stdcall;

const
    DLLNAME = 'WS_ProjectDoc.dll';

implementation

procedure	PDInitClipInfo			; external DLLNAME Name 'PDInitClipInfo';
function	PDCreateProjDoc			; external DLLNAME Name 'PDCreateProjDoc';
procedure	PDDestroyProjDoc		; external DLLNAME Name 'PDDestroyProjDoc';
function	PDAddSlideshow			; external DLLNAME Name 'PDAddSlideshow';
function	PDAddClip				    ; external DLLNAME Name 'PDAddClip';
function	PDGetSlideshowCount	; external DLLNAME Name 'PDGetSlideshowCount';
function	PDGetSlideshowInfo	; external DLLNAME Name 'PDGetSlideshowInfo';
function	PDGetClipCount			; external DLLNAME Name 'PDGetClipCount';
function	PDGetClipInfo			  ; external DLLNAME Name 'PDGetClipInfo';
function	PDSaveToFile			  ; external DLLNAME Name 'PDSaveToFile';
function	PDLoadFromFile			; external DLLNAME Name 'PDLoadFromFile';
function	PDSetMenuXml			; external DLLNAME Name 'PDSetMenuXml';
function	PDGetMenuXml			; external DLLNAME Name 'PDGetMenuXml';
function	PDSetProjSettingXml		; external DLLNAME Name 'PDSetProjSettingXml';
function	PDGetProjSettingXml		; external DLLNAME Name 'PDGetProjSettingXml';
function	PDSetDvdBurnerParam		; external DLLNAME Name 'PDSetDvdBurnerParam';
function	PDGetDvdBurnerParam		; external DLLNAME Name 'PDGetDvdBurnerParam';
end.