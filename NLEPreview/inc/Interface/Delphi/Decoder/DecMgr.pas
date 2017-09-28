unit
	DecMgr;

{$WARNINGS OFF}
    
interface

uses
    windows, VideoInfo, AudioInfo, DecoderParam, CodecDefine, FileInfo;

type      
  PVIDEODECODER  = pointer;	// Video�������������
  PAUDIODECODER  = pointer;	// Video�������������

//void __stdcall DecMgrInit(); // �������
procedure DecMgrInit(); stdcall;

//void __stdcall DecMgrUninit(); //
procedure DecMgrUninit(); stdcall;

// ȡ��Media��Ϣ
//MEDIA_FILE_INFO* __stdcall WSGetMediaFileInfo(const wchar_t* pFileName, DEC_MODEL DecMod = AUTO_MODEL);
function WSGetMediaFileInfo(const pFileName : PWideChar; DecMod : DEC_MODEL = AUTO_MODEL) : PMEDIA_FILE_INFO; stdcall;

//void __stdcall WSReleaseMediaFileInfo(MEDIA_FILE_INFO* pMediaInfo);
procedure WSReleaseMediaFileInfo(pMediaInfo : PMEDIA_FILE_INFO); stdcall;



// ����PVIDEODECODER��� ����0Ϊ���ļ�ʧ��
// PVIDEODECODER __stdcall WVDCreate(const wchar_t * pFileName, const VideoDecParam* pVidParam = 0);
function WVDCreate(const pFileName : PWideChar; pDecParam : PDecParam = nil; pError : PInteger = nil; DecMod : DEC_MODEL = AUTO_MODEL) : PVIDEODECODER; stdcall;


// ȡ����Ƶ��Ϣ ����0�ɹ� ����ʧ��
//const VideoInfo* __stdcall WVDGetVideoInfo(PVIDEODECODER pVidDecoder);
function WVDGetVideoInfo(pVidDecoder : PVIDEODECODER) : PWSVideoInfo; stdcall;


// ����VideoDecoder������
//void __stdcall WVDDestroy(PVIDEODECODER pVidDecoder);
procedure WVDDestroy(pVidDecoder : PVIDEODECODER); stdcall;


// ����PVIDEODECODER��� ����0Ϊ���ļ�ʧ��
// PAUDIODECODER __stdcall WADCreate(const wchar_t * pFileName, const AudioDecParam* pAudParam = 0);  
function WADCreate(const pFileName : PWideChar; pDecParam : PDecParam = nil; pError : PInteger = nil; DecMod : DEC_MODEL = AUTO_MODEL) : PAUDIODECODER; stdcall;

// ȡ����Ƶ��Ϣ ����0�ɹ� ����ʧ��
//const AudioInfo* __stdcall WADGetAudioInfo(PAUDIODECODER pAudDecoder);
function WADGetAudioInfo(pAudDecoder : PAUDIODECODER) : PWSAudioInfo; stdcall;

// ����VideoDecoder������
//void __stdcall WADDestroy(PAUDIODECODER pAudDecoder)
procedure WADDestroy(pAudDecoder : PAUDIODECODER); stdcall;



implementation

const
    DLLNAME = 'WS_DecMgr.dll';

procedure DecMgrInit            ; external DLLNAME index 30;
procedure DecMgrUninit          ; external DLLNAME index 31;

function  WSGetMediaFileInfo					; external DLLNAME index 1;
procedure WSReleaseMediaFileInfo			; external DLLNAME index 2;

function  WVDCreate						  ; external DLLNAME index 10;
procedure WVDDestroy					  ; external DLLNAME index 11;
function  WVDGetVideoInfo				; external DLLNAME index 12;

function  WADCreate						  ; external DLLNAME index 20;
procedure WADDestroy					  ; external DLLNAME index 21;
function  WADGetAudioInfo				; external DLLNAME index 22;

end.
