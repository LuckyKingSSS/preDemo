{*******************************************************}
{       Wondershare������������ת���������             }
{       ������:�� ����⡡�� ��������������   ��������  }
{       ��������: 2009/07/07                            }
{       �޶���:                                         }
{       �޶�����:                                       }
{*******************************************************}
{$Z4}  // 4�ֽ�ö��

unit MediaTaskParaConv;

interface

uses Windows, Messages, SysUtils, Classes, Contnrs, MediaCommon, MediaEncode,
  MediaEncodeMgr, MediaBatchConv, MediaTaskPro, MediaDibImage, MediaProcess,
  WSSubPic;

type
  TMediaParallelEncodeTaskList = class;

  TMediaParallelEncodeTask = class(TMediaEncodeTask)
  private
    FEncoder: TMediaBatchEncoder;
    FEncodedLength: Double;
    function GetOwner: TMediaParallelEncodeTaskList;
    function InitEncoder: Boolean;
    function DoEncodeProgress(Sender: TMediaBatchEncoder; EncodingState: TMediaEncodingState;
      AProgress, AProgressMax: Integer; AProgressInfo: PMediaProgressInfo): Boolean;
  public
    constructor Create(AOwner: TMediaParallelEncodeTaskList; ATask: TMediaTask);
    destructor Destroy; override;

    function Start(hMsgWnd: HWnd): Boolean; override;
    function Pause: Boolean; override;
    function Resume: Boolean; override;
    function Stop: Boolean; override;

    property Owner: TMediaParallelEncodeTaskList read GetOwner;
    property Encoder: TMediaBatchEncoder read FEncoder;
  end;

  // ��������ת����ͬһʱ������ж��ת�������У�
  TMediaParallelEncodeTaskList = class(TMediaEncodeTaskList)
  private
    FParallelNum: Integer;
    FEncodingTaskOrd: Integer;     // ����������ת������
    FOnEncodeProgress: TMediaTaskEncodeProgressEvent;
    FActiveTaskCount: Integer;
    function GetEncodedLength: Double;
    procedure TasksToEncodeList;
    function DoEncodeProgress(Sender: TMediaParallelEncodeTask; EncodingState: TMediaEncodingState;
      AProgress, AProgressMax: Integer; AProgressInfo: PMediaProgressInfo): Boolean;
  public
    constructor Create(AOwner: TMediaTaskMgr);
    destructor Destroy; override;

    function EncodeNext(hMsgWnd: HWnd=0): Boolean;
    function Pause: Boolean;
    function Resume: Boolean;
    function Stop: Boolean;

    property EncodingTaskOrd: Integer read FEncodingTaskOrd;              // ����ת�����������
    property ParallelNum: Integer read FParallelNum write FParallelNum;   // ������������
    property ActiveTaskCount: Integer read FActiveTaskCount;              // ����ת����������
    property EncodedLength: Double read GetEncodedLength;                 // ��ǰ�����Ѿ�ת���ĳ���
    property OnEncodeProgress: TMediaTaskEncodeProgressEvent read FOnEncodeProgress write FOnEncodeProgress; // ת������
  end;

implementation

uses WideStrUtils;

{ TMediaParallelEncodeTask }

constructor TMediaParallelEncodeTask.Create(
  AOwner: TMediaParallelEncodeTaskList; ATask: TMediaTask);
begin
  inherited Create(AOwner, ATask);
end;

destructor TMediaParallelEncodeTask.Destroy;
begin
  FEncoder.Free;
  inherited;
end;

function TMediaParallelEncodeTask.DoEncodeProgress(Sender: TMediaBatchEncoder;
  EncodingState: TMediaEncodingState; AProgress, AProgressMax: Integer;
  AProgressInfo: PMediaProgressInfo): Boolean;
begin
  case EncodingState of
    mesEncoding:
      if AProgressMax>0 then
        FEncodedLength:=(Task.OutputLength*AProgress/AProgressMax);
    mesFinished, mesUserAbort,
      mesCallBackAbort, mesError:
      begin
        FEncodedLength:=Task.OutputLength;
      end;
  end;
  Result:=Owner.DoEncodeProgress(Self, EncodingState, AProgress, AProgressMax, AProgressInfo);
end;

function TMediaParallelEncodeTask.GetOwner: TMediaParallelEncodeTaskList;
begin
  Result:=TMediaParallelEncodeTaskList(inherited Owner);
end;

function TMediaParallelEncodeTask.InitEncoder: Boolean;

  // ����û�ˮӡ
  procedure InitTaskUserWatermarkParams(pEditParams: TMediaTaskEditParams; var pTaskItem: TTaskItem);
  begin
    if pEditParams.WaterMark then // �û���ӵ�ˮӡ
      pTaskItem.UserWatermark:=pEditParams.GetUserWaterMarkParam();
  end;

  // ��Ӱ�Ȩˮӡ
  procedure InitCopyrightWatermark(pEncodeParams: TMediaTaskEncodeParams; var pTaskItem: TTaskItem);
  begin
    if not Owner.Owner.Registered then// ���û��ע��, ��Ӱ�Ȩˮӡ
    begin
      if pEncodeParams.IsOutputAudio then // ����Ƶ����ʱ�����ƣ�һ�㣳���ӣ�180�룩
      begin
        FEncoder.SetAudioLimitLength(Round(Owner.Owner.MaxAudioLen));
      end;
      // ��Ȩˮӡ
      pTaskItem.Watermark:=Owner.Owner.Watermark^;
    end;
  end;

  // ��������Ļ
  procedure InitTaskSubPicParams(pEditParams: TMediaTaskEditParams;var pTaskItem: TTaskItem);
  var
    pUserSubPic: TUserSubPicRec;
  begin
    if pEditParams.SubTitle then
    begin
      pUserSubPic:=pEditParams.GetUserSubTitleParams();
      pTaskItem.UserSubPic.nDummy1:=USEData_Buffer_SUBSTYLE;
      pTaskItem.UserSubPic.uSubPicID:=pUserSubPic.uSubPicID;
      pTaskItem.UserSubPic.Style:=pUserSubPic.Style;
      pTaskItem.UserSubPic.nOpacity:=pUserSubPic.nOpacity;
      WStrPLCopy(pTaskItem.UserSubPic.pSubPicPath, pEditParams.SubTitleFile, SizeOf(pTaskItem.UserSubPic.pSubPicPath)-1);
    end;
  end;

  procedure InitTaskItem(ATask: TMediaTask; var pTaskItem: TTaskItem);
  var
    pEditParams: TMediaTaskEditParams;
  begin
    FillChar(pTaskItem, SizeOf(pTaskItem), 0);
    with ATask.MediaSource do
    begin
      WStrPLCopy(pTaskItem.szInputFile, FileName, Length(pTaskItem.szInputFile)-1);
      pTaskItem.VidDecParam := VideoDecParam^;
      pTaskItem.AudDecParam := AudioDecParam^;
      pTaskItem.uDecMode := DecModel;
    end;
    // �ü�����
    pTaskItem.dTrimStart := ATask.OutputStart;
    pTaskItem.dTrimEnd := ATask.OutputStart+ATask.OutputLength;
    pTaskItem.dStart := pTaskItem.dTrimStart;
    pTaskItem.dEnd := pTaskItem.dTrimEnd;

    // �༭����
    pEditParams:=ATask.EditParams;
    if Assigned(pEditParams) then
    with pEditParams do
    begin
      pTaskItem.Effect.nVolume := Volume;
      pTaskItem.Effect.nBrightness := Brightness;
      pTaskItem.Effect.nContrast := Contrast;
      pTaskItem.Effect.nSaturation := Saturation;
      pTaskItem.Effect.uExFilterID := FilterID;
      pTaskItem.Effect.uFlipID := FlipFlag;
      pTaskItem.Effect.uDeintelace := DeInterlacing;
      pTaskItem.crCrop := CropRect;
      pTaskItem.nAngle := Round(pEditParams.Rotation); // ��ת
      pTaskItem.bDrag := False;    // ������
      if Mute then // ����,������������С
        pTaskItem.Effect.nVolume:=0;
    end;
    // ���ˮӡ����
    InitTaskUserWatermarkParams(pEditParams, pTaskItem);

    // ��������Ļ����
    InitTaskSubPicParams(pEditParams, pTaskItem);
  end;

  procedure InitMainTaskItem(ATask: TMediaTask; var pTaskItem: TTaskItem);
  var
    pEncodeParams: TMediaTaskEncodeParams;
    pEditParams: TMediaTaskEditParams;
  begin
    // ����ļ���, �Ե�һ����Ϊ׼
    WStrPLCopy(pTaskItem.szOutputFile, ATask.FullOutFileName, Length(pTaskItem.szOutputFile)-1);
    // ��������
    pEncodeParams:=ATask.EncodeParams;
    if Assigned(pEncodeParams) then
    with pEncodeParams do
    begin
      pTaskItem.EncParam:=EncParam^;
      // ��Ӱ�Ȩˮӡ
      InitCopyrightWatermark(pEncodeParams, pTaskItem);
    end;
    pEditParams:=ATask.EditParams;
    if Assigned(pEditParams) then
      pTaskItem.EncParam.Video.nResizeStyle:=pEditParams.ResizeStyle;
  end;

  procedure AddMergeSource(ATask: TMediaTask; ASource: TMediaTaskMergeSource);
  var
    pChildTask: TMediaTask;
    pTaskItem: TTaskItem;
  begin
    for pChildTask in ASource.TaskList do
    begin
      InitTaskItem(pChildTask, pTaskItem);
      InitMainTaskItem(ATask, pTaskItem); // ����ͱ��������������Ϊ׼
      // ������һ�б���������, ʹ���������Լ������ŷ�ʽ
      pTaskItem.EncParam.Video.nResizeStyle:=pChildTask.EditParams.ResizeStyle;// ÿ��������ʹ���Լ������ŷ�ʽ
      FEncoder.AddTaskItem(pTaskItem);
    end;
  end;

  procedure AddNormalTaskItem(ATask: TMediaTask);
  var
    pTaskItem: TTaskItem;
    pSource: TMediaTaskMediaSource;
  begin
    pSource:=ATask.MediaSource;
    if pSource is TMediaTaskMergeSource then
      AddMergeSource(ATask, TMediaTaskMergeSource(pSource))
    else
    begin
      InitTaskItem(ATask, pTaskItem);
      InitMainTaskItem(ATask, pTaskItem); // ����ͱ��������������Ϊ׼
      FEncoder.AddTaskItem(pTaskItem);
    end;
  end;

begin
  FreeAndNil(FEncoder);
  FEncoder:=TMediaBatchEncoder.Create;
  FEncoder.OnEncodeProgress:=DoEncodeProgress;
  AddNormalTaskItem(Task);
  Result:=True;
end;

function TMediaParallelEncodeTask.Pause: Boolean;
begin
  if Assigned(FEncoder) then
  begin
    FEncoder.Pause;
    Result:=True;
  end else
    Result:=False;
end;

function TMediaParallelEncodeTask.Resume: Boolean;
begin
  if Assigned(FEncoder) then
  begin
    FEncoder.Resume;
    Result:=True;
  end else
    Result:=False;
end;

function TMediaParallelEncodeTask.Start(hMsgWnd: HWnd): Boolean;
begin
  Result:=False;
  FEncodedLength:=0;
  if InitEncoder then
  begin
    Result:=FEncoder.Run(hMsgWnd, FEncoder.GetTaskCount>1);
  end;
end;

function TMediaParallelEncodeTask.Stop: Boolean;
begin
  if Assigned(FEncoder) then
  begin
    FEncoder.Abort();
    Result:=True;
  end else
    Result:=False;
end;

{ TMediaParallelEncodeTaskList }

constructor TMediaParallelEncodeTaskList.Create(AOwner: TMediaTaskMgr);
begin
  inherited Create(AOwner);
  TasksToEncodeList;
end;

destructor TMediaParallelEncodeTaskList.Destroy;
begin
  Stop;
  inherited;
end;

function TMediaParallelEncodeTaskList.DoEncodeProgress(Sender: TMediaParallelEncodeTask;
  EncodingState: TMediaEncodingState;
  AProgress, AProgressMax: Integer; AProgressInfo: PMediaProgressInfo): Boolean;
begin
  case EncodingState of
    mesFinished, mesUserAbort,
    mesCallBackAbort, mesError: Dec(FActiveTaskCount);  // ���ٻ�������
  end;
  if Assigned(FOnEncodeProgress) then
    Result:=FOnEncodeProgress(Sender, EncodingState, AProgress, AProgressMax,
      AProgressInfo)
  else
    Result:=False;
end;

function TMediaParallelEncodeTaskList.EncodeNext(hMsgWnd: HWnd): Boolean;
var
  i: Integer;
  pTask: TMediaParallelEncodeTask;
begin
  Result:=False;
  if FActiveTaskCount<FParallelNum then
  for i:=FEncodingTaskOrd to Count-1 do
  begin
    pTask:=TMediaParallelEncodeTask(Items[i]);
    Result:=pTask.Start(hMsgWnd);
    if Result then
    begin
      Inc(FEncodingTaskOrd);
      Inc(FActiveTaskCount);  // ���ӻ�������
      if FActiveTaskCount>=FParallelNum then
        Exit;
    end;
  end;
end;

function TMediaParallelEncodeTaskList.GetEncodedLength: Double;
var
  pTask: TMediaEncodeTask;
begin
  Result:=0;
  for pTask in Self do
  begin
    Result:=Result+TMediaParallelEncodeTask(pTask).FEncodedLength;
  end;
end;

function TMediaParallelEncodeTaskList.Pause: Boolean;
var
  pTask: TMediaEncodeTask;
begin
  for pTask in Self do
  begin
    pTask.Pause;
  end;
  Result:=True;
end;

function TMediaParallelEncodeTaskList.Resume: Boolean;
var
  pTask: TMediaEncodeTask;
begin
  for pTask in Self do
  begin
    pTask.Resume;
  end;
  Result:=True;
end;

function TMediaParallelEncodeTaskList.Stop: Boolean;
var
  pTask: TMediaEncodeTask;
begin
  for pTask in Self do
  begin
    pTask.Stop;
  end;
  Result:=True;
  FEncodingTaskOrd:=0;
  FActiveTaskCount:=0;
end;

procedure TMediaParallelEncodeTaskList.TasksToEncodeList;

  procedure AddTaskToEncodeList(ATask: TMediaTask);
  var
    pChildTask: TMediaTask;
    pEncodeTask: TMediaEncodeTask;
  begin
    if not ATask.SkipEncode then
    begin
      pEncodeTask:=TMediaParallelEncodeTask.Create(Self, ATask);
      Self.Add(pEncodeTask);
    end;
    for pChildTask in ATask.GetChildTasks do
    begin
      AddTaskToEncodeList(pChildTask);
    end;
  end;

var
  pTask: TMediaTask;
begin
  for pTask in Owner.Tasks do
  begin
    AddTaskToEncodeList(pTask);
  end;
end;

end.
