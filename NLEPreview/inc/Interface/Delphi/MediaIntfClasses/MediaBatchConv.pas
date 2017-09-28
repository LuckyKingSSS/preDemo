{*******************************************************}
{       Wondershare������������ת���ӿ�                 }
{       ������:�� ����⡡�� ��������������   ��������  }
{       ��������: 2009/07/07                            }
{       �޶���:                                         }
{       �޶�����:                                       }
{*******************************************************}
{$Z4}  // 4�ֽ�ö��

unit MediaBatchConv;

interface

uses Windows, Messages, SysUtils, Classes, MediaCommon, MediaDecode, MediaProcess,
  MediaEncodeMgr, MediaPlay, MediaEncode, WSSubPic;

const
  WSBatchConvDLL = 'WS_BatchConvProc.dll';

//�ָ�ģʽ����
  SPLIT_BASE_ON_NONE = 0;
  SPLIT_BASE_ON_TIME = 1;
  SPLIT_BASE_ON_SIZE = 2;

  USEData_Buffer_SUBSTYLE = $A1;

//------------------------------------------------------------------------------
  UM_CONVERT_PROGRESS_WRAP = (WM_APP + 930);
// HIWORD(wParam) 
// LOWROD(wParam) -  0 ����  lParam - ����(LOWORD:�ܽ��� HIWORD:��ǰ������� 0-100)  ��ϸ��Ϣ��ʹ�� BCGetProgressInfo	
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ 
//           101 ������Ϣ  lParam - ����(0-100)
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
//   1000 ��ʼ������

  UM_CONVERT_END_WRAP    = (WM_APP + 931);
  UM_CONVERT_ERROR_WRAP  = (WM_APP + 932);

type
// Effect����
  TEffectData = record
    nVolume: Longint;               // 0 - 200
    nBrightness: Longint;           // -100��100
    nContrast: Longint;             // -100��100
    nSaturation: Longint;           // -100��100
    uExFilterID: DWORD;             // �˾�ID
    uFlipID: DWORD;                 // ��תID
    uDeintelace: DEINTERLACE_STYLE; // ȥ������ɨ�跽ʽ
  end;

  TUserWatermarkParam = MediaProcess.TUserWatermarkParam;

  BATCHCONVERTER = record end;
  HBATCHCONVERTER = ^BATCHCONVERTER;

  TConvertState = ( // ת��״̬
    CS_NONE,      //
    CS_RUNNING,   // ����ת��
    CS_COMPLETE,  // �ɹ�ת��
    CS_ERROR      // ��������
  );

  // ����ת��ר�������Ļ��ʽ�ṹ
  TUserSubPicForBC = packed record
    nDummy1: Byte;                 // Ϊ�˼��ݱ�����һ���ֽ� nDummy1 = A1
    uSubPicID: UINT;               // ��ĻID
    Style: TSubPicStyle;           // ��Ļ��ʽ
    nOpacity: UINT;                // ͸���� 0--100, 0=��ȫ͸��,100��ʾ��ȫ��͸��
    pSubPicPath: array[0..MAX_PATH-1] of WideChar; // ��Ļ·��,��ID=0ʱ,ָ����Ļ·��
    nDummy2: array[0..2] of Byte;  // Ϊ�˶��뱣���������ֽ�, SizeOf(nDummy1)+SizeOf(nDummy2)=SizeOf(DWORD)
  end;
  PUserSubPicForBC = ^TUserSubPicForBC;

  PTaskItem = ^TTaskItem;
  TTaskItem = record
    szInputFile: array [0..511] of WideChar;   //�����ļ���
    VidDecParam : TVideoDecParam;    // ��Ƶ�������
    AudDecParam : TAudioDecParam;    // ��Ƶ�������
    Effect : TEffectData;       // ��Ч����
    crCrop : TRECT;             // ��Ƶ��������
    Watermark : TWatermarkParam;// ˮӡ
    UserWatermark: TUserWatermarkParam; // �û��Զ���ˮӡ
    // Slide Time Ƭ����ʱ�����ϵ�ʱ��
    dStart : double;            // ��������������Ƶ����ֹʱ�䣬��λ���룬�� ���г��� != ������ȣ�����������Ч��
    dEnd : double;              // ��ֵΪ����������Ч��
    // Slide Time Ϊʱ�����ϵ�ʱ��
    dTrimStart : double;        // ���п�ʼʱ�䣨�ļ�����ʱ�䣩
    dTrimEnd : double;          // ���н���ʱ�䣨�ļ�����ʱ�䣩��Ƶ����ʱ������д��ȷ��ʱ��

    uDecMode : DEC_MODEL;
    EncParam : TEncodeParam;
    szOutputFile : array [0..511] of WideChar;  // ����ļ���, ·��ȫ��
    nConvState : TConvertState;
    dwUserData : DWORD;          // �û�����
    dwSplitMode: DWORD;          // �ָ�ģʽ ���ָ�ģʽ����
    dwSplitSize: DWORD;          // �ָ�ģʽ�µĴ�С��SPLIT_BASE_ON_TIMEʱ��λ�����룬SPLIT_BASE_ON_SIZEʱ��λ��kb
    UserSubPic: TUserSubPicForBC; // �����Ļ
    nAngle     : UINT;           // ��ת�Ƕ� 0-270, ��ʱ�뷽��
    bDrag      : BOOL;           // ��ת���Ƿ����� Ĭ��False
    pUseData: array[0..1023-SizeOf(UINT)-SizeOf(BOOL)-SizeOf(TUserSubPicForBC)] of Byte;       // �������ݣ�ΪӦ����չ��Ҫ��ʹ�ø��ֶ�ʱ��Ҫ�����һ���ֽ�����
  end;

  TConvertProgressInfo = packed record
    dTotalLength        : double;   // ӰƬ��ʱ�䳤��
    dTotalTransedLength : double;   // ��������ת��ӰƬʱ��
    dCurrTime           : double;   // ��ǰʱ��
    nPercent            : Longint;  // ������ٷֱȣ�0 - 100��
    nCurrentTaskPercent : Longint;  // ��ǰ������Ȱٷֱ�
    nPercentPercent     : Longint;  // ��������ֱȣ�0 - 10000��
    nCurrentTaskPercentPercent : Longint; // ��ǰ���������ֱ�
    nCurrentTaskIndex   : Longint;  // ��ǰ����������, �ӣ���ʼ
    nTaskCount          : Longint;  // ��������?
    tmPrepaid           : DWORD;    // ����ʱ�� ��λ����
    tmRemain            : DWORD;    // ʣ��ʱ�� ��λ����
    dCurrTransedTime    : double;   // ��ǰ������ת��ӰƬʱ��
    dCurrLength         : double;   // ��ǰ����ӰƬ����
    dTransRate          : double;   // ת�����ʣ���λ��ÿ��ת����Ƭ�ϳ���
    nFramesPerSecond    : Longint;  // ת�����ʣ���λ��ÿ�봦���֡��
    nEnocdeFramesPerSecond : Longint; // ÿ���ӱ������Ƶ֡����
    dwConvState         : TConvertState; // ת��״̬
  end;

  PConvertProgressInfo = ^TConvertProgressInfo;

  TInitTaskItem = procedure (const pTask: TTaskItem); stdcall;
  TInitEncParam = procedure (const pEncParam: TEncodeParam); stdcall;

  TBCCreate = function (): HBATCHCONVERTER; stdcall;
  TBCDestroy = procedure (hBatchConv: HBATCHCONVERTER); stdcall;
  TBCAddTaskItem = procedure (hBatchConv: HBATCHCONVERTER; const pTask: TTaskItem); stdcall;
  TBCGetTaskCount = function (hBatchConv: HBATCHCONVERTER): Integer; stdcall;
  TBCGetTaskItem = function (hBatchConv: HBATCHCONVERTER; nIndex: Integer; var pTask: TTaskItem): BOOL; stdcall;
  TBCSetAudioLimitLength = procedure (hBatchConv: HBATCHCONVERTER; nLimitLength: Integer); stdcall;
  TBCSetWatermarkImage = procedure (hBatchConv: HBATCHCONVERTER; lpbi: PBITMAPINFO;
    lpBits: PBYTE; pRect: PRECT = nil; nOpacity: Integer = 100); stdcall;
  // ��ʼת��, ���ؽ���ID
  TBCRun = function (hBatchConv: HBATCHCONVERTER; hWnd: HWND = 0; bMerge: BOOL = False): Integer; stdcall;
  TBCPause = function (hBatchConv: HBATCHCONVERTER): Integer; stdcall;
  TBCResume = function (hBatchConv: HBATCHCONVERTER): Integer; stdcall;
  TBCWait = function (hBatchConv: HBATCHCONVERTER; uMilliSecondsTimeOut: UINT = $FFFFFFFF): DWORD; stdcall;
  TBCAbort = function (hBatchConv: HBATCHCONVERTER; wParam: WPARAM = 0; lParam: LPARAM = 0): Integer; stdcall;
  // ��ʼ��Ԥ�������صľ���� HBATCHCONVERTER˽��,����Ҫ�ֹ��ͷ�
  TBCInitPreview = function (hBatchConv: HBATCHCONVERTER; hParentWnd: HWND; const pRcPos: TRECT): HEXPORTVIEWER; stdcall;
  TBCShowPreview = procedure (hBatchConv: HBATCHCONVERTER; bShow: BOOL = True); stdcall;
  TBCEnablePreview = procedure (hBatchConv: HBATCHCONVERTER; bEnable: BOOL = True); stdcall;
  TBCGetProgressInfo = procedure (hBatchConv: HBATCHCONVERTER; const AProgressInfo: TConvertProgressInfo); stdcall;

  TBatchConvAPI = record
  private
    FHandle: THandle;
    FInitTaskItem: TInitTaskItem;
    FInitEncParam: TInitEncParam;
    FBCCreate: TBCCreate;
    FBCDestroy: TBCDestroy;
    FBCAddTaskItem: TBCAddTaskItem;
    FBCGetTaskCount: TBCGetTaskCount;
    FBCGetTaskItem: TBCGetTaskItem;
    FBCSetAudioLimitLength: TBCSetAudioLimitLength;
//    FBCSetWatermarkImage: TBCSetWatermarkImage;
    FBCRun: TBCRun;
    FBCPause: TBCPause;
    FBCResume: TBCResume;
    FBCWait: TBCWait;
    FBCAbort: TBCAbort;
    FBCInitPreview: TBCInitPreview;
    FBCShowPreview: TBCShowPreview;
//    FBCEnablePreview: TBCEnablePreview;
    FBCGetProgressInfo: TBCGetProgressInfo;
  public
    function Init: Boolean;
    procedure Free;

    procedure InitTaskItem(var pTask: TTaskItem);
    procedure InitEncParam(var pEncParam: TEncodeParam);

    function BCCreate(): HBATCHCONVERTER;
    procedure BCDestroy(hBatchConv: HBATCHCONVERTER);
    // �������
    procedure BCAddTaskItem(hBatchConv: HBATCHCONVERTER; const pTask: TTaskItem);
    function BCGetTaskItem(hBatchConv: HBATCHCONVERTER; nIndex: Integer; var pTask: TTaskItem): BOOL;
    function BCGetTaskCount(hBatchConv: HBATCHCONVERTER): Integer;
    procedure BCSetAudioLimitLength(hBatchConv: HBATCHCONVERTER; nLimitLength: Integer);
//    procedure BCSetWatermarkImage(hBatchConv: HBATCHCONVERTER; lpbi: PBITMAPINFO;
//      lpBits: PBYTE; pRect: PRECT = nil; nOpacity: Integer = 100);      ������
    // ת��״̬����
    function BCRun(hBatchConv: HBATCHCONVERTER; hWnd: HWND = 0; bMerge: BOOL = False): Integer;
    function BCPause(hBatchConv: HBATCHCONVERTER): Integer;
    function BCResume(hBatchConv: HBATCHCONVERTER): Integer;
    function BCWait(hBatchConv: HBATCHCONVERTER; uMilliSecondsTimeOut: UINT = $FFFFFFFF): DWORD;
    function BCAbort(hBatchConv: HBATCHCONVERTER; wParam: WPARAM = 0; lParam: LPARAM = 0): Integer;
    procedure BCGetProgressInfo(hBatchConv: HBATCHCONVERTER; var ProgressInfo: TConvertProgressInfo);
    // Ԥ������
    function BCInitPreview(hBatchConv: HBATCHCONVERTER; hParentWnd: HWND; const pRcPos: TRECT): HEXPORTVIEWER;
    procedure BCShowPreview(hBatchConv: HBATCHCONVERTER; bShow: BOOL = TRUE);
//    procedure BCEnablePreview(hBatchConv: HBATCHCONVERTER; bEnable: BOOL = True);   ������

    property Handle: THandle read FHandle;
  end;

  TMediaBatchEncoder = class;

  TBatchEncodeProgressEvent = function (Sender: TMediaBatchEncoder; EncodingState: TMediaEncodingState;
    AProgress, AProgressMax: Integer; AProgressInfo: PMediaProgressInfo): Boolean of object;

  TMediaBatchEncoder = class
  private
    FHandle: HBATCHCONVERTER;
    FMsgWnd: HWnd;
    FProcessId: Integer;
    FOnEncodeProgress: TBatchEncodeProgressEvent;
    FCallBackWnd: HWND;
    procedure InitCallBackWnd;
    procedure ReleaseCallBackWnd;
    procedure CallBackWndProc(var Message: TMessage);
  public
    constructor Create;
    destructor Destroy; override;

    class procedure InitTaskItem(var pTask: TTaskItem);
    class procedure InitEncParam(var pEncParam: TEncodeParam);
    // �������
    procedure AddTaskItem(const pTask: TTaskItem);
    function GetTaskItem(nIndex: Integer; var pTask: TTaskItem): BOOL;
    function GetTaskCount(): Integer;
    procedure SetAudioLimitLength(nLimitLength: Integer);
//    procedure SetWatermarkImage(lpbi: PBITMAPINFO;
//      lpBits: PBYTE; pRect: PRECT = nil; nOpacity: Integer = 100);   ������
    // ת��״̬����
    function Run(hMsgWnd: HWND = 0; bMerge: BOOL = False): BOOL;
    function Pause(): Integer;
    function Resume(): Integer;
    function Wait(uMilliSecondsTimeOut: UINT = $FFFFFFFF): DWORD;
    function Abort(wParam: WPARAM = 0; lParam: LPARAM = 0): Integer;
    procedure GetProgressInfo(var ProgressInfo: TConvertProgressInfo);
    // Ԥ������
    function InitPreview(hParentWnd: HWND; const pRcPos: TRECT): HEXPORTVIEWER;
    procedure ShowPreview(bShow: BOOL = True);
//    procedure EnablePreview(bEnable: BOOL = True);    ������

    property Handle: HBATCHCONVERTER read FHandle;
    property TaskCount: Integer read GetTaskCount;
    property OnEncodeProgress: TBatchEncodeProgressEvent read FOnEncodeProgress write FOnEncodeProgress;
  end;

var
  BatchConvAPI: TBatchConvAPI;

implementation

const
  sInitTaskItem = 'InitTaskItem';
  sInitEncParam = 'InitEncParam';
  sBCCreate = 'BCCreate';
  sBCDestroy = 'BCDestroy';
  sBCInitPreview = 'BCInitPreview';
  sBCAddTaskItem = 'BCAddTaskItem';
  sBCGetTaskCount = 'BCGetTaskCount';
  sBCGetTaskItem = 'BCGetTaskItem';
  sBCSetAudioLimitLength = 'BCSetAudioLimitLength';
  sBCSetWatermarkImage = 'BCSetWatermarkImage';
  sBCRun = 'BCRun';
  sBCPause = 'BCPause';
  sBCResume = 'BCResume';
  sBCWait = 'BCWait';
  sBCAbort = 'BCAbort';
  sBCShowPreview = 'BCShowPreview';
  sBCEnablePreview = 'BCEnablePreview';
  sBCGetProgressInfo = 'BCGetProgressInfo';

{ TBatchConvAPI }

function TBatchConvAPI.BCAbort(hBatchConv: HBATCHCONVERTER; wParam: WPARAM;
  lParam: LPARAM): Integer;
begin
  if Assigned(FBCAbort) then
    Result:=FBCAbort(hBatchConv, wParam, lParam)
  else
    Result:=0;
end;

procedure TBatchConvAPI.BCAddTaskItem(hBatchConv: HBATCHCONVERTER;
  const pTask: TTaskItem);
begin
  if Assigned(FBCAddTaskItem) then
    FBCAddTaskItem(hBatchConv, pTask);
end;

function TBatchConvAPI.BCCreate: HBATCHCONVERTER;
begin
  if Assigned(FBCCreate) then
    Result:=FBCCreate()
  else
    Result:=nil;
end;

procedure TBatchConvAPI.BCDestroy(hBatchConv: HBATCHCONVERTER);
begin
  if Assigned(FBCDestroy) then
    FBCDestroy(hBatchConv);
end;

//procedure TBatchConvAPI.BCEnablePreview(hBatchConv: HBATCHCONVERTER;
//  bEnable: BOOL);
//begin
//  if Assigned(FBCEnablePreview) then
//    BCEnablePreview(hBatchConv, bEnable);
//end;

procedure TBatchConvAPI.BCGetProgressInfo(hBatchConv: HBATCHCONVERTER;
  var ProgressInfo: TConvertProgressInfo);
begin
  if Assigned(FBCGetProgressInfo) then
    FBCGetProgressInfo(hBatchConv, ProgressInfo);
end;

function TBatchConvAPI.BCGetTaskCount(hBatchConv: HBATCHCONVERTER): Integer;
begin
  if Assigned(FBCGetTaskCount) then
    Result:=FBCGetTaskCount(hBatchConv)
  else
    Result:=0;
end;

function TBatchConvAPI.BCGetTaskItem(hBatchConv: HBATCHCONVERTER;
  nIndex: Integer; var pTask: TTaskItem): BOOL;
begin
  if Assigned(FBCGetTaskItem) then
    Result:=FBCGetTaskItem(hBatchConv, nIndex, pTask)
  else
    Result:=False;
end;

function TBatchConvAPI.BCInitPreview(hBatchConv: HBATCHCONVERTER;
  hParentWnd: HWND; const pRcPos: TRECT): HEXPORTVIEWER;
begin
  if Assigned(FBCInitPreview) then
    Result:=FBCInitPreview(hBatchConv, hParentWnd, pRcPos)
  else
    Result:=nil;
end;

function TBatchConvAPI.BCPause(hBatchConv: HBATCHCONVERTER): Integer;
begin
  if Assigned(FBCPause) then
    Result:=FBCPause(hBatchConv)
  else
    Result:=0;
end;

function TBatchConvAPI.BCResume(hBatchConv: HBATCHCONVERTER): Integer;
begin
  if Assigned(FBCResume) then
    Result:=FBCResume(hBatchConv)
  else
    Result:=0;
end;

function TBatchConvAPI.BCRun(hBatchConv: HBATCHCONVERTER; hWnd: HWND;
  bMerge: BOOL): Integer;
begin
  if Assigned(FBCRun) then
    Result:=FBCRun(hBatchConv, hWnd, bMerge)
  else
    Result:=0;
end;

procedure TBatchConvAPI.BCSetAudioLimitLength(hBatchConv: HBATCHCONVERTER;
  nLimitLength: Integer);
begin
  if Assigned(FBCSetAudioLimitLength) then
    FBCSetAudioLimitLength(hBatchConv, nLimitLength);
end;

//procedure TBatchConvAPI.BCSetWatermarkImage(hBatchConv: HBATCHCONVERTER;
//  lpbi: PBITMAPINFO; lpBits: PBYTE; pRect: PRECT; nOpacity: Integer);
//begin
//  if Assigned(FBCSetWatermarkImage) then
//    FBCSetWatermarkImage(hBatchConv, lpbi, lpBits, pRect, nOpacity);
//end;

procedure TBatchConvAPI.BCShowPreview(hBatchConv: HBATCHCONVERTER; bShow: BOOL);
begin
  if Assigned(FBCShowPreview) then
    FBCShowPreview(hBatchConv, bShow);
end;

function TBatchConvAPI.BCWait(hBatchConv: HBATCHCONVERTER;
  uMilliSecondsTimeOut: UINT): DWORD;
begin
  if Assigned(FBCWait) then
    Result:=FBCWait(hBatchConv, uMilliSecondsTimeOut)
  else
    Result:=0;
end;

procedure TBatchConvAPI.Free;
begin
  if FHandle <> 0 then
  begin
    FreeLibrary(FHandle);
    FHandle := 0;
    FillChar(Self, SizeOf(Self), 0);
  end;
end;

function TBatchConvAPI.Init: Boolean;
begin
  if FHandle=0 then
  begin
    FHandle := LoadLibrary(WSBatchConvDLL);
    if FHandle <> 0 then
    begin
      FInitTaskItem := GetProcAddress(FHandle, (sInitTaskItem));
      FInitEncParam := GetProcAddress(FHandle, (sInitEncParam));
      FBCCreate := GetProcAddress(FHandle, (sBCCreate));
      FBCDestroy := GetProcAddress(FHandle, (sBCDestroy));
      FBCInitPreview := GetProcAddress(FHandle, (sBCInitPreview));
      FBCAddTaskItem := GetProcAddress(FHandle, (sBCAddTaskItem));
      FBCGetTaskCount := GetProcAddress(FHandle, (sBCGetTaskCount));
      FBCGetTaskItem := GetProcAddress(FHandle, (sBCGetTaskItem));
      FBCSetAudioLimitLength := GetProcAddress(FHandle, (sBCSetAudioLimitLength));
//      FBCSetWatermarkImage := GetProcAddress(FHandle, (sBCSetWatermarkImage));
      FBCRun := GetProcAddress(FHandle, (sBCRun));
      FBCPause := GetProcAddress(FHandle, (sBCPause));
      FBCResume := GetProcAddress(FHandle, (sBCResume));
      FBCWait := GetProcAddress(FHandle, (sBCWait));
      FBCAbort := GetProcAddress(FHandle, (sBCAbort));
      FBCShowPreview := GetProcAddress(FHandle, (sBCShowPreview));
//      FBCEnablePreview := GetProcAddress(FHandle, (sBCEnablePreview));
      FBCGetProgressInfo := GetProcAddress(FHandle, (sBCGetProgressInfo));
    end else
      RaiseLoadLibError(SEncMgrAPI);
  end;
  Result:=FHandle<>0;
end;

procedure TBatchConvAPI.InitEncParam(var pEncParam: TEncodeParam);
begin
  if Assigned(FInitEncParam) then
    FInitEncParam(pEncParam);
end;

procedure TBatchConvAPI.InitTaskItem(var pTask: TTaskItem);
begin
  if Assigned(FInitTaskItem) then
    FInitTaskItem(pTask);
end;

{ TBatchConv }

function TMediaBatchEncoder.Abort(wParam: WPARAM; lParam: LPARAM): Integer;
begin
  Result:=BatchConvAPI.BCAbort(FHandle, wParam, lParam);
  FProcessId:=0;
end;

procedure TMediaBatchEncoder.AddTaskItem(const pTask: TTaskItem);
begin
  BatchConvAPI.BCAddTaskItem(FHandle, pTask);
end;

procedure TMediaBatchEncoder.CallBackWndProc(var Message: TMessage);
// wParam -  0 ����  lParam - ����(LOWORD:�ܽ��� HIWORD:��ǰ������� 0-100)  ��ϸ��Ϣ��ʹ�� BCGetProgressInfo
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ
//           101 ������Ϣ  lParam - ����(0-100)
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
//    1000 ��ʼ������
var
  nProg, nProgMax: Integer;
  EncodingState: TMediaEncodingState;

  procedure SendCallBack;
//  var
//    ProgressInfo: TConvertProgressInfo;
  begin
    if Assigned(FOnEncodeProgress) then
    begin
//      FillChar(ProgressInfo, SizeOf(ProgressInfo), 0);
//      GetProgressInfo(ProgressInfo); // ���ں�������Ҫ����
      FOnEncodeProgress(Self, EncodingState, nProg, nProgMax, nil);
    end;
    if FMsgWnd<>0 then
    with Message do
      SendMessage(FMsgWnd, Msg, WParam, LParam);
  end;

begin
  with Message do
  begin
    nProg:=0;
    nProgMax:=0;
    case Msg of
      UM_CONVERT_PROGRESS_WRAP:
        begin
          EncodingState := mesEncoding;
          nProg:=LParamLo;
          nProgMax:=10000;
          SendCallBack;
        end;
      UM_CONVERT_END_WRAP:  // ת������
        begin
          EncodingState := mesFinished;
          SendCallBack;
        end;
      UM_CONVERT_ERROR_WRAP:  // ת������
        begin
          EncodingState := mesError;
          SendCallBack;
        end
    else
      Result := DefWindowProc(FCallBackWnd, Msg, wParam, lParam);
    end;
  end;
end;

constructor TMediaBatchEncoder.Create;
begin
  inherited Create;
  BatchConvAPI.Init;
  FHandle:=BatchConvAPI.BCCreate();
end;

destructor TMediaBatchEncoder.Destroy;
begin
  BatchConvAPI.BCDestroy(FHandle);
  ReleaseCallBackWnd;
  inherited;
end;

//procedure TMediaBatchEncoder.EnablePreview(bEnable: BOOL);
//begin
//  BatchConvAPI.BCEnablePreview(FHandle, bEnable);
//end;

procedure TMediaBatchEncoder.GetProgressInfo(var ProgressInfo: TConvertProgressInfo);
begin
  BatchConvAPI.BCGetProgressInfo(FHandle, ProgressInfo);
end;

function TMediaBatchEncoder.GetTaskCount: Integer;
begin
  Result:=BatchConvAPI.BCGetTaskCount(FHandle);
end;

function TMediaBatchEncoder.GetTaskItem(nIndex: Integer; var pTask: TTaskItem): BOOL;
begin
  Result:=BatchConvAPI.BCGetTaskItem(FHandle, nIndex, pTask);
end;

procedure TMediaBatchEncoder.InitCallBackWnd;
begin
  if FCallBackWnd=0 then
  begin
    FCallBackWnd:=Classes.AllocateHWnd(CallBackWndProc);
  end;
end;

class procedure TMediaBatchEncoder.InitEncParam(var pEncParam: TEncodeParam);
begin
  BatchConvAPI.Init;
  BatchConvAPI.InitEncParam(pEncParam);
end;

function TMediaBatchEncoder.InitPreview(hParentWnd: HWND;
  const pRcPos: TRECT): HEXPORTVIEWER;
begin
  Result:=BatchConvAPI.BCInitPreview(FHandle, hParentWnd, pRcPos);
end;

class procedure TMediaBatchEncoder.InitTaskItem(var pTask: TTaskItem);
begin
  BatchConvAPI.Init;
  BatchConvAPI.InitTaskItem(pTask);
end;

function TMediaBatchEncoder.Pause: Integer;
begin
  Result:=BatchConvAPI.BCPause(FHandle);
end;

procedure TMediaBatchEncoder.ReleaseCallBackWnd;
begin
  if FCallBackWnd<>0 then
  begin
    Classes.DeallocateHWnd(FCallBackWnd);
    FCallBackWnd:=0;
  end;
end;

function TMediaBatchEncoder.Resume: Integer;
begin
  Result:=BatchConvAPI.BCResume(FHandle);
end;

function TMediaBatchEncoder.Run(hMsgWnd: HWnd; bMerge: BOOL): BOOL;
begin
  InitCallBackWnd;
  FProcessId:=BatchConvAPI.BCRun(FHandle, FCallBackWnd, bMerge);
  Result:=FProcessId<>0;
end;

procedure TMediaBatchEncoder.SetAudioLimitLength(nLimitLength: Integer);
begin
  BatchConvAPI.BCSetAudioLimitLength(FHandle, nLimitLength);
end;

//procedure TMediaBatchEncoder.SetWatermarkImage(lpbi: PBITMAPINFO; lpBits: PBYTE;
//  pRect: PRECT; nOpacity: Integer);
//begin
//  BatchConvAPI.BCSetWatermarkImage(FHandle, lpbi, lpBits, pRect, nOpacity);
//end;

procedure TMediaBatchEncoder.ShowPreview(bShow: BOOL);
begin
  BatchConvAPI.BCShowPreview(FHandle, bShow);
end;

function TMediaBatchEncoder.Wait(uMilliSecondsTimeOut: UINT): DWORD;
begin
  Result:=BatchConvAPI.BCWait(FHandle, uMilliSecondsTimeOut);
end;

initialization
finalization
  BatchConvAPI.Free;

end.
