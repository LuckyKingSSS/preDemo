unit
	TracksDecoder;

{$WARNINGS OFF}
    
interface

uses
    windows, TDoc;

type
  HVIDEODECODER = Pointer;
  HAUDIODECODER = Pointer;

//����������Ƶ������
//HVIDEODECODER __stdcall MTDVideoCreate(HTLDOC hDoc, int width, int height, double frame_rate);
function MTDVideoCreate(hDoc : HTLDOC; width, height : integer; frame_rate : Double) : HVIDEODECODER; stdcall;

//���ٶ�����Ƶ������
//void __stdcall MTDVideoDestroy(HVIDEODECODER hVideo);
procedure MTDVideoDestroy(hVideo : HVIDEODECODER); stdcall;

//����������Ƶ������
//HAUDIODECODER __stdcall MTDAudioCreate(HTLDOC hDoc, int sample_rate, int channels);
function MTDAudioCreate(hDoc : HTLDOC; sample_rate, channels : integer) : HAUDIODECODER; stdcall;

//���ٶ�����Ƶ������
//void __stdcall MTDAudioDestroy(HAUDIODECODER hAudio);
procedure MTDAudioDestroy(hAudio : HAUDIODECODER); stdcall;

implementation

const
    DLLNAME = 'TracksDecoder.dll';

function  MTDVideoCreate;  external DLLNAME Name 'MTDVideoCreate';
procedure MTDVideoDestroy; external DLLNAME Name 'MTDVideoDestroy';
function  MTDAudioCreate;  external DLLNAME Name 'MTDAudioCreate';
procedure MTDAudioDestroy; external DLLNAME Name 'MTDAudioDestroy';


end.




