{
	���ܣ� ��Ƶ����
}

unit VideoSlideDecoder;

interface

uses
  Windows, VideoSlideParams, DecoderParam;

type
    HVIDEODECODER = pointer;

// ����SlideShow��Ƶ������
// HVIDEODECODER __stdcall SDVideoCreate(const VideoSlideParam* pParam);
function SDVideoCreate(const pParam : PVideoProcessParam) : HVIDEODECODER; stdcall;

// ����SlideShow��Ƶ������
// void __stdcall SDVideoDestroy(HVIDEODECODER hVideo);
procedure SDVideoDestroy(hVideo : HVIDEODECODER); stdcall;

// ����һ����ƵƵԴ���䴦������������á����ȶԱȶȵ��ڡ���Ч���õȣ�����ε��ü�����������ƵԴ
// BOOL __stdcall SDAddVideoSource(HVIDEODECODER hVideo, const wchar_t* szSrcVideoFile, const VideoProcessParam* pParam);
function SDAddVideoSource(hVideo : HVIDEODECODER; const szSrcVideoFile : PWideChar; const pParam : PVideoProcessParam) : BOOL; stdcall;


implementation

const
    DLLNAME = 'WS_SlideDecoder.dll';

function  SDVideoCreate              ; external DLLNAME Name 'SDVideoCreate';
procedure SDVideoDestroy             ; external DLLNAME Name 'SDVideoDestroy';
function  SDAddVideoSource           ; external DLLNAME Name 'SDAddVideoSource';

end.


