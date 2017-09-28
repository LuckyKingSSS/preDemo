{
	���ܣ�	��Ƶ����
			   ��Ƶ�ϳ�
}

unit AudioSlideDecoder;

interface

uses
  Windows, DecoderParam, AudioSlideParams;


type
    HAUDIODECODER = pointer;
    PSHORT = ^SHORT;

// ����SlideShow��Ƶ������
// HAUDIODECODER __stdcall SDAudioCreate(const AudioSlideParam* );
function SDAudioCreate(const pParam : PAudioSlideParam) : HAUDIODECODER; stdcall;

// ����SlideShow��Ƶ������
// void __stdcall SDAudioDestroy(HAUDIODECODER hAudio);
procedure SDAudioDestroy(hAudio : HAUDIODECODER); stdcall;

// ����һ����ƵԴ���䴦���������ε��ü�����������ƵԴ��szSrcAudioΪ��ƵԴ�ļ�·��
// BOOL __stdcall SDAddAudioSource(HAUDIODECODER hAudio, const wchar_t* szSrcAudioFile, const AudioProcessParam* pParam);
function SDAddAudioSource(hAudio : HAUDIODECODER; const szSrcAudioFile : PWideChar; const pParam : PAudioProcessParam) : BOOL; stdcall;

//double __stdcall SDSeek(HAUDIODECODER hAudio, double time); // ��λ��ָ��ʱ��
//function SDSeek(hAudio: HAUDIODECODER; time: double): double; stdcall;

//int __stdcall SDGetNextSamples(HAUDIODECODER hAudio, short * buffer, int n_samples); // ȡ����n_samples��sample���� n_samplesӦ��Ϊ����������������
//function SDGetNextSamples(hAudio: HAUDIODECODER; buffer: PSHORT; n_samples: Integer): Integer; stdcall;

//double __stdcall SDGetOffset(HAUDIODECODER hAudio); // ���ص�ǰʱ��
//function SDGetOffset(hAudio: HAUDIODECODER): double; stdcall;

//const AudioInfo* __stdcall SDGetAudioInfo(HAUDIODECODER hAudio); // ȡ����Ƶ��Ϣ
//function SDGetAudioInfo(hAudio: HAUDIODECODER): PAudioInfo; stdcall;

implementation

const
    DLLNAME = 'WS_SlideDecoder.dll';

function  SDAudioCreate              ; external DLLNAME Name 'SDAudioCreate';
procedure SDAudioDestroy             ; external DLLNAME Name 'SDAudioDestroy';
function  SDAddAudioSource           ; external DLLNAME Name 'SDAddAudioSource';
//�µĽӿ�û���ṩ��Щ����
//function  SDSeek                     ; external DLLNAME Name 'SDSeek';
//function  SDGetNextSamples           ; external DLLNAME Name 'SDGetNextSamples';
//function  SDGetOffset                ; external DLLNAME Name 'SDGetOffset';
//function  SDGetAudioInfo             ; external DLLNAME Name 'SDGetAudioInfo';

end.
