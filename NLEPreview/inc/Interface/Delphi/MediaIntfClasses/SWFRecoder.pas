unit SWFRecoder;

interface

uses
  Windows, Messages, SysUtils, MediaCommon, MediaEncodeMgr;

const
  SFlashRecord_API = 'WS_FlashRecoder.dll';
const
  CM_RECORDEND = WM_USER + 777;

type
  PSWFRecThreadData = ^TSWFRecThreadData;
  TSWFRecThreadData = record
    FilePath      : WideString; //Դ�ļ�·��
    TotalFrame    : Integer;    //Դ�ļ���֡��
    hMainHand     : HWND;       //�����ھ��
    hParent       : HWND;       //�����������ھ��
    hViewer       : HWND;
    Rect          : TRect;      //���Ŵ���RECT
    ViewerRect    : TRect;
    FlashScript   : WideString; //����ű�·��
    IsAutoRecord  : Boolean;    //�Ƿ��Զ�¼��
  end;

  TSWFRecData = TSWFRecThreadData;
  PSWFRecData = PSWFRecThreadData;

  TFSCommandEvent = procedure (const cmd: WideString; const args: WideString) of object;
  
  //��ʼ������
  TFRCreate = procedure (const SWFRecData : TSWFRecData); stdcall;
  //��������
  TFRDestroy = procedure (); stdcall;
  //������Ƶ�ļ����·��
  TFRSetVideoFileName = procedure (const pVFilePath: PWideChar); stdcall;
  //������Ƶ�ļ����·��
  TFRSetAudioFileName = procedure (const pAFilePath: PWideChar); stdcall;
  //�����ļ����·��
  TFRSetOutputFileName = procedure (const pOutputFilePath: PWideChar); stdcall;
  //���ñ������
  TFRSetEncParam = procedure (const pEncParam: PENCODEPARAM); stdcall;
  //���ý������
  TFRSetDecParam = procedure (VideoInfo: PWSVideoInfo; AudioInfo: PWSAudioInfo); stdcall;
  //�����Ƿ�Ϊ�Զ�¼��
  TFRSetAutoRecord = procedure (IsAutoRecord : Boolean); stdcall;
  TFRSetFSCommand = procedure (value: TFSCommandEvent); stdcall;
  TFRSetIsDVD = procedure (Value: Boolean); stdcall;

type
  TFlashRecorderAPI = record
  private
    FHandle: THandle;
    FFRCreate: TFRCreate;
    FFRDestroy: TFRDestroy;
    FFRSetVideoFileName: TFRSetVideoFileName;
    FFRSetAudioFileName: TFRSetAudioFileName;
    FFRSetOutputFileName: TFRSetOutputFileName;
    FFRSetEncParam: TFRSetEncParam;
    FFRSetDecParam: TFRSetDecParam;
    FFRSetAutoRecord: TFRSetAutoRecord;
    FFRSetFSCommand: TFRSetFSCommand;
    FFRSetIsDVD: TFRSetIsDVD;
  public
    function Init(): Boolean;
    procedure Free;

    procedure FRCreate(const SWFRecData : TSWFRecData);
    procedure FRDestroy();
    procedure FRSetVideoFileName(const pVFilePath: PWideChar);
    procedure FRSetAudioFileName(const pAFilePath: PWideChar);
    procedure FRSetOutputFileName(const pOutputFilePath: PWideChar);
    procedure FRSetEncParam(const pEncParam: PENCODEPARAM);
    procedure FRSetDecParam(VideoInfo: PWSVideoInfo; AudioInfo: PWSAudioInfo);
    procedure FRSetAutoRecord(IsAutoRecord : Boolean);
    procedure FRSetFSCommand(Value: TFSCommandEvent);
    procedure FRSetIsDVD(Value: Boolean);

    property Handle: THandle read FHandle;
  end;

var
  FlashRecorderAPI: TFlashRecorderAPI;

implementation

const
  sFRCreate = 'FRCreate';
  sFRDestroy = 'FRDestroy';
  sFRSetVideoFileName = 'FRSetVideoFileName';
  sFRSetAudioFileName = 'FRSetAudioFileName';
  sFRSetOutputFileName = 'FRSetOutputFileName';
  sFRSetEncParam = 'FRSetEncParam';
  sFRSetDecParam = 'FRSetDecParam';
  sFRSetAutoRecord = 'FRSetAutoRecord';
  sFRSetFSCommand = 'FRSetFSCommand';
  sFRSetIsDVD = 'FRSetIsDVD';

procedure CleanupProc;
begin
  FlashRecorderAPI.Free;
end;

{ TFlashRecorderAPI }

procedure TFlashRecorderAPI.FRCreate(const SWFRecData: TSWFRecData);
begin
  Init;
  if Assigned(FFRCreate) then
    FFRCreate(SWFRecData);
end;

procedure TFlashRecorderAPI.FRDestroy;
begin
  if Assigned(FFRDestroy) then
    FFRDestroy();
end;

procedure TFlashRecorderAPI.Free;
begin
  if FHandle <> 0 then
  begin
    FreeLibrary(FHandle);
    FHandle:=0;
    FillChar(Self, SizeOf(Self), 0);
  end;
end;

procedure TFlashRecorderAPI.FRSetAudioFileName(const pAFilePath: PWideChar);
begin
  if Assigned(FFRSetAudioFileName) then
    FRSetAudioFileName(pAFilePath);
end;

procedure TFlashRecorderAPI.FRSetAutoRecord(IsAutoRecord: Boolean);
begin
  if Assigned(FFRSetAutoRecord) then
    FFRSetAutoRecord(IsAutoRecord);
end;

procedure TFlashRecorderAPI.FRSetDecParam(VideoInfo: PWSVideoInfo;
  AudioInfo: PWSAudioInfo);
begin
  if Assigned(FFRSetDecParam) then
    FFRSetDecParam(VideoInfo, AudioInfo);
end;

procedure TFlashRecorderAPI.FRSetEncParam(const pEncParam: PENCODEPARAM);
begin
  if Assigned(FFRSetEncParam) then
    FFRSetEncParam(pEncParam);
end;

procedure TFlashRecorderAPI.FRSetFSCommand(Value: TFSCommandEvent);
begin
  if Assigned(FFRSetFSCommand) then
    FFRSetFSCommand(Value);
end;

procedure TFlashRecorderAPI.FRSetIsDVD(Value: Boolean);
begin
  if Assigned(FFRSetIsDVD) then
    FFRSetIsDVD(Value);
end;

procedure TFlashRecorderAPI.FRSetOutputFileName(
  const pOutputFilePath: PWideChar);
begin
  if Assigned(FFRSetOutputFileName) then
    FFRSetOutputFileName(pOutputFilePath);
end;

procedure TFlashRecorderAPI.FRSetVideoFileName(const pVFilePath: PWideChar);
begin
  if Assigned(FFRSetVideoFileName) then
    FFRSetVideoFileName(pVFilePath);
end;

function TFlashRecorderAPI.Init: Boolean;
begin
  if FHandle = 0 then
  begin
    FHandle := LoadLibrary(SFlashRecord_API);
    if FHandle <> 0 then
    begin
      AddExitProc(CleanupProc);
      FFRCreate := GetProcAddress(FHandle, (sFRCreate));
      FFRDestroy := GetProcAddress(FHandle, (sFRDestroy));
      FFRSetVideoFileName := GetProcAddress(FHandle, (sFRSetVideoFileName));
      FFRSetAudioFileName := GetProcAddress(FHandle, (sFRSetAudioFileName));
      FFRSetOutputFileName := GetProcAddress(FHandle, (sFRSetOutputFileName));
      FFRSetEncParam := GetProcAddress(FHandle, (sFRSetEncParam));
      FFRSetDecParam := GetProcAddress(FHandle, (sFRSetDecParam));
      FFRSetAutoRecord := GetProcAddress(FHandle, (sFRSetAutoRecord));
      FFRSetFSCommand := GetProcAddress(FHandle, (sFRSetFSCommand));
      FFRSetIsDVD := GetProcAddress(FHandle, (sFRSetIsDVD));
    end else
      RaiseLoadLibError(SFlashRecord_API);
  end;
  Result := FHandle <> 0;
end;

end.
