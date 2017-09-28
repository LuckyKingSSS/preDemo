// ���ܣ� ʵ��ý���ļ��Ĵ���������
unit
	EncMgr; 
    
interface

uses
    Windows, EncParam, AudioInfo, VideoInfo;

type
	HMEDIAFILE  = pointer;	// ý���ļ��������
	
//BOOL __stdcall FCInitPlugins();		// Ӧ�ó�������ʱ����
function FCInitPlugins() : BOOL; stdcall;

//void __stdcall FCUninitPlugins();	// Ӧ�ó����˳�ʱ����
procedure FCUninitPlugins(); stdcall;

// FileFormatInfo*  __stdcall FCGetFileFormatInfos(); // ��ȡ�Ѽ���֧�ֵ������ļ���ʽ������FCInitPlugins()���óɹ���ſɵ���
function FCGetFileFormatInfos() : PFILEFORMATINFO; stdcall;

// ����ý���ļ� ĿǰpVidInfo->dwFourCC = '21VY' pVidInfo->nBitsDepth = 12���������� 
//HMEDIAFILE __stdcall FCCreateMediaFile(onst wchar_t* pFileName, const EncodeParam* pEncParam,
//				  const VideoInfo* pVidInfo, const AudioInfo* pAudInfo);
function FCCreateFile(const pFileName: PWideChar; const pEncParam: PENCODEPARAM; 
						const pVidInfo: PWSVideoInfo; const pAudInfo: PWSAudioInfo) : HMEDIAFILE; stdcall;

// �ر�ý���ļ�
//void __stdcall FCDestroyMediaFile(HMEDIAFILE hFileEnc, ENCODE_CALLBACK pCallBack = 0, void* pUserObj = 0);
procedure FCCloseMediaFile(hFileEnc : HMEDIAFILE; pCallBack : ENCODE_CALLBACK = nil; pUserObj : Pointer = nil); stdcall;


// д����Ƶ���ݣ���ѹ��PCM���ݣ�
//int __stdcall FCWriteAudioData(HMEDIAFILE hFileEnc, BYTE* pData, int nLen);
//�ɵĴ����:function FCWriteAudioData(hFileEnc : HMEDIAFILE; nType : Integer; pData : PBYTE; nLen : Integer) : BOOL; stdcall;
//function FCWriteAudioData(hFileEnc : HMEDIAFILE; pData : PBYTE; nLen : Integer) : BOOL; stdcall;
// �ӿ��Ѿ��޸�

// д��һ֡ͼ������ Ŀǰֻ֧��YV12ͼ��
//int __stdcall FCWriteVideoFrame(HMEDIAFILE hFileEnc, BYTE* pBits, int nLen = 0);
//�ɵĴ����:function FCWriteVideoFrame(hFileEnc : HMEDIAFILE; nType : Integer; pBits : PBYTE; nLen : Integer = 0) : BOOL; stdcall;
//function FCWriteVideoFrame(hFileEnc : HMEDIAFILE; pBits : PBYTE; nLen : Integer = 0) : BOOL; stdcall;


implementation

const
    DLLNAME = 'WS_EncMgr.dll';

function FCCreateFile						; external DLLNAME index 1;
procedure FCCloseMediaFile				; external DLLNAME index 2;

//function FCWriteAudioData					; external DLLNAME index 3;
//function FCWriteVideoFrame					; external DLLNAME index 4;

function FCInitPlugins					; external DLLNAME index 5;
procedure FCUninitPlugins					; external DLLNAME index 6;
function FCGetFileFormatInfos			; external DLLNAME index 7;

end.


