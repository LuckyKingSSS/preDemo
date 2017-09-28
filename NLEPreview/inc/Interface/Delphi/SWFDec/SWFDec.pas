unit
	SWFDec;

{$WARNINGS OFF}
    
interface

uses
    windows, VidInfo, AudInfo, DecoderParam;


type
    PVIDEODECODER  = pointer;	// Video�������������
    PAUDIODECODER  = pointer;	// Video�������������
    PSHORT         = ^SHORT;



// ȡ����Ƶ��Ϣ ����0�ɹ� ����ʧ��
//int __stdcall WGetVideoInfo(const wchar_t * pFileName, VideoInfo* pVInfo);
function WGetVideoInfo(const pFileName : PWideChar; pVInfo : PVideoInfo) : Integer; stdcall;

// ȡ����Ƶ��Ϣ ����0�ɹ� ����ʧ��
//int __stdcall WGetAudioInfo(const wchar_t * pFileName, AudioInfo* pAInfo);
function WGetAudioInfo(const pFileName : PWideChar; pAInfo : PAudioInfo) : Integer; stdcall;


// ����PVIDEODECODER��� ����0Ϊ���ļ�ʧ��
//PVIDEODECODER __stdcall WVDCreate(const wchar_t * pFileName, const VideoDecParam* pVidParam = 0);
function WVDCreate(const pFileName : PWideChar; const pVidParam : PVideoDecParam = nil) : PVIDEODECODER; stdcall;

// ����VideoDecoder������
//void __stdcall WVDDestroy(PVIDEODECODER pVidDecoder);	
procedure WVDDestroy(pVidDecoder : PVIDEODECODER); stdcall;


//const VideoInfo* __stdcall WVDGetVideoInfo(PVIDEODECODER pVidDecoder); // ȡ����Ƶ��Ϣ
function WVDGetVideoInfo(pVidDecoder : PVIDEODECODER) : PVideoInfo; stdcall;

//LPBITMAPINFO __stdcall WVDGetFormat(PVIDEODECODER pVidDecoder); // ȡ��ͼ���ʽ
function WVDGetFormat(pVidDecoder : PVIDEODECODER) : PBITMAPINFO; stdcall;


//double __stdcall WVDSeekTime(PVIDEODECODER pVidDecoder, double dTime, BOOL accurate = TRUE); // ��λ��ָ��ʱ�� dTime - ��
function WVDSeekTime(pVidDecoder: PVIDEODECODER; dTime: Double; accurate : BOOL = TRUE): Double; stdcall;

//int __stdcall WVDSeek(PVIDEODECODER pVidDecoder, int frame, BOOL accurate = TRUE); // ��λ��ָ��֡
function WVDSeek(pVidDecoder: PVIDEODECODER; frame: Integer; accurate : BOOL = TRUE): Integer; stdcall;

//LPBITMAPINFO __stdcall WVDGetFrame(PVIDEODECODER pVidDecoder); // ȡ�õ�ǰ֡ͼ��
function WVDGetFrame(pVidDecoder : PVIDEODECODER) : PBITMAPINFO; stdcall;

//int __stdcall WVDGetFrameOffset(PVIDEODECODER pVidDecoder); // ���ص�ǰ֡������
function WVDGetFrameOffset(pVidDecoder : PVIDEODECODER) : Integer; stdcall;

//int __stdcall WVDNext(PVIDEODECODER pVidDecoder); // ��λ����һ֡
function WVDNext(pVidDecoder : PVIDEODECODER) : Integer; stdcall;



// ����PAUDIODECODER��� ����0Ϊ���ļ�ʧ��
// hMsgWnd - ������Ϣ���մ���
//       ������Ϣ Msg: 9000
//                          wParam: 0 ������Ϣ  lParam: 0 - 100
//                                  1 ���     ����δʹ�ã�
//                                  2 �������� ����δʹ�ã�
// ����PVIDEODECODER��� ����0Ϊ���ļ�ʧ��
//PAUDIODECODER __stdcall WADCreate(const wchar_t * pFileName, const AudioDecParam* pAudParam = 0);
function WADCreate(const pFileName : PWideChar; const pAudParam : PAudioDecParam = nil) : PAUDIODECODER; stdcall;

// ����VideoDecoder������
//void __stdcall WADDestroy(PAUDIODECODER pAudDecoder)
procedure WADDestroy(pAudDecoder : PAUDIODECODER); stdcall;


//double __stdcall WADSeek(PAUDIODECODER pAudDecoder, double time); // ��λ��ָ��ʱ��
function WADSeek(pAudDecoder : PAUDIODECODER; time : double) : double; stdcall;

//int __stdcall WADGetNextSamples(PAUDIODECODER pAudDecoder, short * buffer, int n_samples); // ȡ����n_samples��sample���� n_samplesӦ��Ϊ����������������
function WADGetNextSamples(pAudDecoder : PAUDIODECODER; buffer : PSHORT; n_samples : Integer) : Integer; stdcall;

//double __stdcall WADGetOffset(PAUDIODECODER pAudDecoder); // ���ص�ǰʱ��
function WADGetOffset(pAudDecoder : PAUDIODECODER) : double; stdcall;

//const AudioInfo* __stdcall WADGetAudioInfo(PAUDIODECODER pAudDecoder); // ȡ����Ƶ��Ϣ
function WADGetAudioInfo(pAudDecoder : PAUDIODECODER) : PAudioInfo; stdcall;




implementation

const
    DLLNAME = 'WS_VideoSrc.dll';

function WVDCreate						; external DLLNAME Name 'WVDCreate';
procedure WVDDestroy					; external DLLNAME Name 'WVDDestroy';
																
function WADCreate						; external DLLNAME Name 'WADCreate';
procedure WADDestroy					; external DLLNAME Name 'WADDestroy';
																
function WGetVideoInfo					; external DLLNAME Name 'WGetVideoInfo';
function WGetAudioInfo					; external DLLNAME Name 'WGetAudioInfo';
																
																
function WVDGetVideoInfo				; external DLLNAME Name 'WVDGetVideoInfo'; 				
function WVDGetFormat					; external DLLNAME Name 'WVDGetFormat'; 			
function WVDSeekTime					; external DLLNAME Name 'WVDSeekTime'; 			
function WVDSeek						; external DLLNAME Name 'WVDSeek'; 			
function WVDGetFrame					; external DLLNAME Name 'WVDGetFrame'; 			
function WVDGetFrameOffset				; external DLLNAME Name 'WVDGetFrameOffset'; 			
function WVDNext						; external DLLNAME Name 'WVDNext'; 			
																
																
function WADSeek						; external DLLNAME Name 'WADSeek'; 			
function WADGetNextSamples				; external DLLNAME Name 'WADGetNextSamples'; 			
function WADGetOffset					; external DLLNAME Name 'WADGetOffset'; 			
function WADGetAudioInfo				; external DLLNAME Name 'WADGetAudioInfo'; 	
		

end.

