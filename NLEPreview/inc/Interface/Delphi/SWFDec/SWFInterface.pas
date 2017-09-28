unit SWFInterface;

{$MINENUMSIZE 4}

interface

uses
  Windows, VidInfo, AudInfo;

const
  WM_ACREATEPROGRESS = 9000;  //��Ƶ����������������Ϣ

type
  HVIDEODEC = Pointer;
  HAUDIODEC = Pointer;

  //��ͼ�ص�
  //pUserObj������ָ�� lpbi���豸�޹�λͼָ�룬nOffset��֡�ţ�lpbi��nOffsetͬʱΪ0����
  CAPTURECALLBACK = procedure (pUserObj: Pointer; lpbi: PBITMAPINFO; nOffset: Integer); stdcall;

  //������Ƶ������
  //pPathFiel:flash�ļ��������ؽ��������
  FUNCreateVideoDec = function (pPathFile: PWideChar): HVIDEODEC; stdcall;

  //������Ƶ������
  FUNDestroyVideoDec = procedure (hVideo: HVIDEODEC); stdcall;

  //ȡ��Ƶ��Ϣ
  FUNGetVideoInfo = function (hVideo: HVIDEODEC): PVideoInfo; stdcall;

  //���ûص�����
  FUNSetCaptureCallback = procedure (hVideo: HVIDEODEC; pUserObj: Pointer; fnCallback: CAPTURECALLBACK); stdcall;

  //������Ƶ������, hParent���������ھ����rc�������� , bVisable�����Ƿ�ɼ�
  FUNVideoRun = procedure (hVideo: HVIDEODEC; hParent: HWND; rc: TRect; bVisable: BOOL); stdcall;

  //��Ƶseek������nFrame�� ֡�ţ� ����seek��֡��
  FUNVideoSeek = function (hVideo: HVIDEODEC; nFrame: Integer): Integer; stdcall;

  //������Ƶ���룬hMsgWnd����������Ϣ���մ���
  //       ������Ϣ Msg: WM_ACREATEPROCESS
  //                          wParam: 0 ������Ϣ  lParam: 0 - 100
  //                                  1 ���     ����δʹ�ã�
  //                                  2 �������� ����δʹ�ã�
  FUNCreateAudioDec = function (pPathFile: PWideChar; hMsgWnd: HWND ): HAUDIODEC; stdcall;

  //������Ƶ����
  FUNDestroyAudioDec = procedure (hAudio: HAUDIODEC); stdcall;

  //ȡ��Ƶ��Ϣ
  FUNGetAudioInfo = function (hAudio: HAUDIODEC): PAudioInfo; stdcall;

  //ȡ��Ƶ����, pBuffer�������ݻ�����, nSample������������С������ȡ��Sample��С
  FUNGetNextSamples = function (hAudio: HAUDIODEC; pBuffer: PSmallInt; nSample: Integer): Integer; stdcall;

  //��Ƶseek����,dTime����ʱ�䣬�ɹ�����seekʱ��
  FUNAudioSeek = function (hAudio: HAUDIODEC; dTime: Double): Double; stdcall;

  //����ָ��ṹ��
  SWFFunc = record
    fnCreateVideoDec:       FUNCreateVideoDec;
    fnDestroyVideoDec:      FUNDestroyVideoDec;
    fnGetVideoInfo:         FUNGetVideoInfo;
    fnSetCaptureCallback:   FUNSetCaptureCallback;
    fnVideoRun:             FUNVideoRun;
    fnVideoSeek:            FUNVideoSeek;
    fnCreateAudioDec:       FUNCreateAudioDec;
    fnDestroyAudioDec:      FUNDestroyAudioDec;
    fnGetAudioInfo:         FUNGetAudioInfo;
    fnGetNextSamples:       FUNGetNextSamples;
    fnAudioSeek:            FUNAudioSeek;
  end;
  PSWFFunc = ^SWFFunc;



  //ȡ������ַ
  function  SWFGetFuncAddress(pFuncs: PSWFFunc):BOOL; stdcall;
  //ȡswf��Ƶ��Ϣ��pPathFile�����ļ����� pVInfo������Ƶ��Ϣ������swf�ļ��汾������0ʧ��
  function  SWFGetVideoInfo(pPathFile: PWideChar; pVInfo: PVideoInfo): WORD; stdcall;



implementation

const
  DLLNAME = 'WS_FlashDecoder.dll';

function SWFGetFuncAddress; external DLLNAME Name 'SWFGetFuncAddress';
function  SWFGetVideoInfo; external DLLNAME Name 'SWFGetVideoInfo';

end.
