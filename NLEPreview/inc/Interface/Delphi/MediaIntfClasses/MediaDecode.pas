{$Z4}
unit MediaDecode;

interface
uses
  Windows, Classes, MediaCommon;

const
  CLSID_CDecMgr: TGUID = '{e71ead89-1ccd-4c34-97a8-7d45b5f16613}';
  CLSID_CSlideDecode: TGUID = '{21c7bb8b-657a-46fb-86e5-a439960ad004}';
  IID_ISlideDecoder: TGUID = '{3DDBBF17-D26F-4fd5-90B4-347C519C3A0D}';
  IID_IDecMgr: TGUID = '{5AD2BE35-3038-4c6a-8C7F-3698526A898F}';
  IID_IMediaDecoder: TGUID = '{C8BD5D61-172A-4ca2-98B7-DE5F1E995D72}';
  IID_ISubPicSetting: TGUID = '{89D89E0A-02F1-47a1-8756-323A9098937E}';
  IID_IMediaInfo: TGUID = '{10CA4A98-A525-42a5-9282-DD64406261B2}';
  IID_IMetaDataInfo: TGUID = '{80DEF872-887D-4426-B31B-771011CF3427}';
  IID_IProgramInfos: TGUID = '{E04C85FD-D887-4716-8D7A-D18A17CE60EC}';
  IID_IProgramInfo: TGUID = '{F5FA588B-55AF-4fa9-8913-323CFF39C231}';
  IID_ISubPicStreamInfos: TGUID = '{4291F08A-95C4-45c3-AF5B-1CC55A3F2CF7}';
  IID_ISubPicStreamInfo: TGUID = '{FB73C029-B0BD-4cbb-A0CE-971E64D4BDD4}';
  
//  MEDIA_CAPABILITIES
const
  MCAPS_CANT_SEEK = $0001;        // ��֧��Seek����
  MCAPS_UNKNOWN_LENGTH = $0002;   // ý�岥��ʱ��δ֪

const
  SD_OPTFLAG_CLIP_START = 1;
  SD_OPTFLAG_CLIP_END = 0;
// DECODE_EX_PARAM_MESSAGE
// SetExDecodeParam����ʹ�õ�uMsg
const
// DECODE_EX_PARAM_MESSAGE
// SetExDecodeParam����ʹ�õ�uMsg
  DEM_DEINTERLACE = 1000;          // ����ɨ���ֵ�㷨�� wParam - DEINTERLACE_STYLE
  CHANGE_AUIDO_STREAM = 1010;      // ��̬�ı���Ƶ������wParam������Ƶ����Stream ID
  CHANGE_SUBTITLE_STREAM = 1011;   // ��̬�ı���Ļ���� wParam ����Ļ����Stream ID
  CHANGE_VIDEO_STREAM = 10012;     // ��̬�ı���Ƶ��Ļ���� wParam ����Ļ����Stream ID

  KEEP_ORIGINAL_VOLUME = 100;  

type
  HVIDEODECODER  = IMediaStream;  // Video�������������
  HAUDIODECODER  = IMediaStream;  // Audio�������������

  FILE_TYPE =
  (
    MEDIA_FILE,
    SUB_PIC
  );

  SUPPIC_TYPE =
  (
	  SPT_Internal,		//��Ƕ��Ļ
	  SPT_External		//������Ļ
  );
  
  DEINTERLACE_STYLE =
  (
    DIS_NONE,
    DIS_ODD,                // �ظ�������
    DIS_EVEN,               // �ظ�ż����
    DIS_ODD_INTERPOLATE,    // ʹ�������в�ֵ
    DIS_EVEN_INTERPOLATE,   // ʹ��ż���в�ֵ
    DIS_AUTO                // �Զ������ݲ�֧�֣�
  );

  DEC_MODEL =                 // ������뷽ʽ
  (
    AUTO_MODEL,       // �Զ�����
    DSHOW_MODEL,      // DShow������
    FFDEC_MODEL,      // FFMPEG����
    DVD_MODEL,        // DVD������
    AVDEC_MODEL,      // AVDec������ WS_AVDec.dll ����WS Video Decoder Platform
    SWF_MODEL,        // Flash������
    MTXML_MODEL,      // mtx�ļ�������
    IMAGE_MODEL       // ͼƬ������
  );


  PDecParam = ^TDecParam;
  TDecParam = record
    uMediaType          : UINT;             // ' FWS'  ' BOV'  ' GPM'
    uProgramID          : UINT;             // uPID of ProgramInfo
    nTrack              : Longint;          // ��Ƶ������ StreamID
    nSubTrack           : Longint;          // ��Ļ��� StreamID��������Video��������
    bDirectCopy         : BOOL;             // ֱ�Ӷ�ȡ������
    uDeintelace         : DEINTERLACE_STYLE;// ����ɨ���ֵ�㷨
    wParam              : WPARAM;
    lParam              : LPARAM;
    bUseThreadDecode    : BOOL; // ʹ���߳̽��뻺�� ����������������ʱ��Ҫ���ò�����FALSE��������ʵʱDeintelace
                                // ���CPUϵͳ�ϴ��߳̿�������CPUʹ����
  end;

  PVideoDecParam = PDecParam;
  TVideoDecParam = TDecParam;
  TAudioDecParam = TDecParam;
  PAudioDecParam = PDecParam;

  PWatermarkParam = ^TWatermarkParam;
  TWatermarkParam = record
    hModule       : HMODULE;
    szID          : array [0..511] of WideChar;  // ˮӡ��ԴID
    Rect          : TRect;                       // ����ڼ��ú��ͼ��ֱ����е�λ��
    nOpacity      : Longint;                     // ˮӡ��͸���� (0 - 100)  0 - ��ȫ͸��  100 - ��ȫ��͸��
    lpbi          : PBITMAPINFO;                 // lpbi ��0��ʹ��hModule��֧��32λ͸��ͼ���Լ�Y41A�Զ����ʽ
    lpBits        : PBYTE;                       // lpbi��lpBits��ҪӦ�ó�������������
    nAlign        : Longint;                     // ˮӡ����(nAlign > 0ʱ ����ˮӡ����(nAlign), ��������ˮӡλ��(Rect))
    // nPos 1 LeftTop, 2 MiddleTop, 3 RightTop, 4 Left, 5 Middle, 6 Right,  7 LeftBottom, 8 MiddleBottom, 9 RightBottom
  end;

  TSDVideoCallBack = function (pUserObj: Pointer; pClipObj: Pointer; nOptFlag: UINT): HVIDEODECODER; stdcall;
  TSDAudioCallBack = function (pUserObj: Pointer; pClipObj: Pointer; nOptFlag: UINT): HAUDIODECODER; stdcall;

  PVideoSlideParam = ^TVideoSlideParam;
  TVideoSlideParam = record
    nWidth          : Longint;                // �ֱ��ʿ��
    nHeight         : Longint;
    dFrameRate      : Double;                 // ֡�� -1��ʾ�Զ�ѡ��
    dwCompression   : DWORD;                  // ͼ���ʽ��Ŀǰֻ֧��'21VY'
    nBitsDepth      : Longint;                // ͼ��λ��� YV12Ϊ12λ
    Watermark       : TWatermarkParam;        // ˮӡ����
  end;

  PVideoProcessParam = ^TVideoProcessParam;
  TVideoProcessParam = record
    Time          : CLIP_TIME;     // ʱ������
    CropRect      : TRect;         // ��������Ϊ�������������
    nBrightness   : Longint;       // ���ȣ�-100��100��0����ԭ����
    nContrast     : Longint;       // �Աȶȣ�-100��100��0����ԭ�Աȶ�
    nSaturation   : Longint;       // ���Ͷ�,-100��100��0����ԭ���Ͷ�
    uExFilterID   : UINT;          // ��չ�˾�ID
    uFlipFlag     : UINT;          // ͼ��ת����
    DecMod        : DEC_MODEL;     // ���뷽ʽ
    vidDecParam   : TDecParam;     // �������
    uDeintelace   : DEINTERLACE_STYLE;    // ȥ������ɨ�跽ʽ
    nResizeStyle  : IMAGE_RESIZE_METHOD;  // ͼ�����ŷ�ʽ
    nInterpolation: IMAGE_INTERPOLATION;  // ͼ���ֵ�㷨
  end;

  TAudioSlideParam = record
    nSampleRate       : Longint;
    nChannels         : Longint;
    nBitsPerSample    : Longint;              // ������ȣ�Ŀǰ��֧��16λ
    nInterpolation    : AUDIO_INTERPOLATION;  // ������ת����ֵ�㷨
  end;
  PAudioSlideParam = ^TAudioSlideParam;

  PVolumEffect = ^TVolumEffect;
  TVolumEffect = record           // ������Ч
    bUseEffect    : BOOL;         // �Ƿ�ʹ����Ч
    dStartTime    : Double;       // ��Ч��ֹʱ�䣬��λ���룬�����ʱ��߶�ΪΪ׼�������¹�ϵ��
    dEndTime      : Double;       //  0.0 <= dStartTime < dEndTime <= dTimeEnd - dTimeStart
    nStartVoulm   : Longint;      // ��ʼ����
    nEndVoulm     : Longint;      // ��������
    nEffectID     : Longint;      // �����㷨ID
  end;

  PAudioProcessParam = ^TAudioProcessParam;
  TAudioProcessParam = record     // ��Ƶ���������ע�⣺nVolum��Start/EndEffectЧ���е��ӣ�����nVolum = 90,
                                  // StartEffect.nStartVoulm = 80,�����տ�ʼ����Ϊ  ԭ������90%��80% �� ԭ������72%
    Time          : CLIP_TIME;    // ʱ������
    nVolum        : Longint;      // ����,0��200, 100����ԭ����
    StartEffect   : TVolumEffect; // ��Ƶ��ʼ���ֹ���Ч�����ݲ�ʹ�ã�
    EndEffect     : TVolumEffect; // ��Ƶ��β���ֹ���Ч�����ݲ�ʹ�ã�
    DecMod        : DEC_MODEL;    // ���뷽ʽ
    audDecParam   : TDecParam;    // ��Ƶ�������
  end;
  
  IMediaDecoder = interface(IUnknown)
    ['{C8BD5D61-172A-4ca2-98B7-DE5F1E995D72}']
  end;
  
  HMEDIADECODER  = IMediaDecoder;  // ý���ļ��������������

  ISubPicStreamInfo = interface(IUnknown)
    ['{FB73C029-B0BD-4cbb-A0CE-971E64D4BDD4}']
    function GetType(): SUPPIC_TYPE; stdcall;
    function GetID(): UINT; stdcall;
    function GetFourCC(): UINT; stdcall;
    function GetLanguage(var ppLanguage: WideString): HRESULT; stdcall;
    function GetDescription(var ppDescription: WideString): HRESULT; stdcall;
  end;
  
  ISubPicStreamInfos = interface(IUnknown)
    ['{4291F08A-95C4-45c3-AF5B-1CC55A3F2CF7}']
    function GetCount(): Integer; stdcall;
    function GetItem(nIndex: Integer; var pSubPicStreamInfo: ISubPicStreamInfo): HRESULT; stdcall;
  end;
  

  IStreamInfos = interface(IUnknown)
    ['{5DD650C8-40A3-4d0d-B460-0BA5804A1AAD}']
    function GetCount(): Integer; stdcall;
    function GetItem(nIndex: Integer; var ppItem: IStreamInfo): HRESULT; stdcall;
  end;
  
  IProgramInfo = interface(IUnknown)
    ['{F5FA588B-55AF-4fa9-8913-323CFF39C231}']
    function GetNumber(): UINT; stdcall;
    function GetID(): UINT; stdcall;
    function GetMediaLength(): Double; stdcall;
    function GetBitrate(): Integer; stdcall;
    function GetTimeStampReferenceStreamID(): UINT; stdcall;
    function GetVideoStreamInfos(var ppVideoStreamInfos: IStreamInfos): HRESULT; stdcall;
    function GetAudioStreamInfos(var ppAudioStreamInfos: IStreamInfos): HRESULT; stdcall;
    function GetSubPicStreamInfos(var pSubPicStreamInfos: ISubPicStreamInfos): HRESULT; stdcall;
  end;
  
  IProgramInfos = interface(IUnknown)
    ['{E04C85FD-D887-4716-8D7A-D18A17CE60EC}']
    function GetCount(): Integer; stdcall;
    function GetItem(nIndex: Integer; var pProgramInfo: IProgramInfo): HRESULT; stdcall;
  end;

  IMetaDataInfo = interface(IUnknown)
    ['{80DEF872-887D-4426-B31B-771011CF3427}']
    function GetArtist(var pArtist: WideString): HRESULT; stdcall;
    function GetTitle(var pTitle: WideString): HRESULT; stdcall;
    function GetTrackNumber(var pTrackNumber: WideString): HRESULT; stdcall;
    function GetAlbum(var pAlbum: WideString): HRESULT; stdcall;
    function GetDate(var pDate: WideString): HRESULT; stdcall;
    function GetGenre(var pGenre: WideString): HRESULT; stdcall;
    function GetPublisher(var pPublisher: WideString): HRESULT; stdcall;
  end;
  
  IMediaInfo = interface(IUnknown)
    ['{10CA4A98-A525-42a5-9282-DD64406261B2}']
    function GetFourCC(): UINT; stdcall;
    function GetFileName(pFileName: PWideString): HRESULT; stdcall;
    function GetDescription(var ppDescription: WideString): HRESULT; stdcall;
    function GetMediaLength(): Double; stdcall;
    function GetBitrate(): Integer; stdcall;
    function GetIPrograms(var pProgramInfos: IProgramInfos): HRESULT; stdcall;
  end;

  IDecMgr = interface(IUnknown)
    ['{5AD2BE35-3038-4c6a-8C7F-3698526A898F}']
    function CreateMediaDecoder(const pMediaPath: WideString; fileType: FILE_TYPE;
      const pVidParam : TVideoDecParam; const pAudParam : TAudioDecParam;
      DecMod: DEC_MODEL): Pointer; stdcall;
    function GetMediaInfo(const pMediaPath: WideString; fileType: FILE_TYPE;
      DecMod: DEC_MODEL; var pIMediaInfo: IMediaInfo): HRESULT; stdcall;
  end;

  ISlideDecoder = interface(IUnknown)
    ['{3DDBBF17-D26F-4fd5-90B4-347C519C3A0D}']
    function SetVideoParam(const pParam: TVideoSlideParam; pUserObj: Pointer; fnCBVideo: TSDVideoCallBack): HRESULT; stdcall;
    function GetVideoParam(): PVideoSlideParam;
    function AddVideoClip(pMediaStream: IMediaStream; const pVideoInfo: TWSVideoInfo; const pClipTime: CLIP_TIME; pUserClipObj: Pointer): HRESULT; stdcall;
    function SetAudioParam(const pParam: TAudioSlideParam; pUserObj: Pointer; fnCBAudio: TSDAudioCallBack): HRESULT; stdcall;
    function GetAudioParam(): PAudioSlideParam; stdcall;
    function AddAudioClip(pMediaStream: IMediaStream; const pAudioInfo: TWSAudioInfo; const pClipTime: CLIP_TIME; pUserClipObj: Pointer): HRESULT; stdcall;
  end;

  IVideoDecoder = interface
    function GetVideoDecoder: HVIDEODECODER;
    function GetVideoInfo: PWSVideoInfo;

    property VideoDecoder: HVIDEODECODER read GetVideoDecoder;
    property VideoInfo: PWSVideoInfo read GetVideoInfo;
  end;

  IAudioDecoder = interface
    function GetAudioDecoder: HAUDIODECODER;
    function GetAudioInfo: PWSAudioInfo;

    property AudioDecoder: HAUDIODECODER read GetAudioDecoder;
    property AudioInfo: PWSAudioInfo read GetAudioInfo;
  end;

  PMediaDecodeAPI = ^TMediaDecodeAPI;
  TMediaDecodeAPI = record
  private
    
  public
    function DecMgrInit(): BOOL;
    procedure DecMgrUninit();
    function WSGetMediaFileInfo(const pFileName : UnicodeString; DecMod : DEC_MODEL = AUTO_MODEL) : IMediaInfo;
    procedure WSReleaseMediaFileInfo(pMediaInfo: IMediaInfo);
  end;
  TMediaDecodeReason = (mdrForPlay, mdrForPreview, mdrForEncode);

  TMediaDecoder = class(TInterfacedObject, IVideoDecoder, IAudioDecoder)
  private
    FMediaDecoder: IMediaDecoder;
    FError: Integer;
    FVideoInfo: TWSVideoInfo;
    FAudioInfo: TWSAudioInfo;
    FDecodeReason: TMediaDecodeReason;
    FOnRelease: TNotifyEvent;
  protected
    function GetMediaDecoder(): HMEDIADECODER;
  public
    constructor Create(const FileName: WideString; const pVidParam: TVideoDecParam; const pAudParam: TAudioDecParam; ADecModel: DEC_MODEL = AUTO_MODEL);
    destructor Destroy; override;

    function GetVideoDecoder: HVIDEODECODER;
    function GetVideoInfo: PWSVideoInfo;

    function GetAudioDecoder: HAUDIODECODER;
    function GetAudioInfo() : PWSAudioInfo;

    procedure ChangeAudioTrack(ATrackId: Integer);
    procedure ChangeSubtitle(ATrackId: Integer);

    property Handle: HMEDIADECODER read GetMediaDecoder;
    property VideoDecoder: HVIDEODECODER read GetVideoDecoder;
    property VideoInfo: PWSVideoInfo read GetVideoInfo;
    property AudioDecoder: HAUDIODECODER read GetAudioDecoder;
    property AudioInfo: PWSAudioInfo read GetAudioInfo;
    property Error: Integer read FError;
    property DecodeReason: TMediaDecodeReason read FDecodeReason write FDecodeReason;
    property OnRelease: TNotifyEvent read FOnRelease write FOnRelease; 

  end;
  
  TSlideDecoderEx = class;

  TVideoSlideClipEvent = function (Sender: TSlideDecoderEx; nOptFlag: UINT): HVIDEODECODER of object;
  TVideoSlideClipProc = function (Sender: TSlideDecoderEx; nOptFlag: UINT): HVIDEODECODER;

  TAudioSlideClipEvent = function (Sender: TSlideDecoderEx; nOptFlag: UINT): HAUDIODECODER of object;
  TAudioSlideClipProc = function (Sender: TSlideDecoderEx; nOptFlag: UINT): HAUDIODECODER;

  TSlideDecoderEx = class(TInterfacedObject, IVideoDecoder, IAudioDecoder)
  private
    FSlideDecoder: ISlideDecoder;
    FVideoSlideParam: TVideoSlideParam;
    FAudioSlideParam: TAudioSlideParam;
    FDecoderList: TInterfaceList;
    FFileList: TStringList;
    FVideoClipEvent: TVideoSlideClipProc;
    FAudioClipEvent: TAudioSlideClipProc;
    FDecodeReason: TMediaDecodeReason;
    function DoVideoCallback(pClipObj: Pointer; nOptFlag: UINT): HVIDEODECODER;
    function DoAudioCallback(pClipObj: Pointer; nOptFlag: UINT): HAUDIODECODER;
  public
    constructor Create(const pVidParam : TVideoSlideParam; const pAudParam: TAudioSlideParam); overload;
    constructor Create(const pVidParam : TVideoSlideParam; AVideoClipEvent: TVideoSlideClipProc;
      const pAudParam: TAudioSlideParam; AAudioClipEvent: TAudioSlideClipProc); overload;
    constructor Create(const pVidParam : TVideoSlideParam; AVideoClipEvent: TVideoSlideClipEvent;
      const pAudParam: TAudioSlideParam; AAudioClipEvent: TAudioSlideClipEvent); overload;
    destructor Destroy; override;

    function AddVideoSource(const AVideo: IVideoDecoder; const pClipTime: CLIP_TIME): BOOL; overload;
    function AddVideoDecoder(hVideoProcess: HVIDEODECODER; const pClipTime: CLIP_TIME): BOOL; overload;
    // �����Ƶ������ʹ�ûص���ʽ����Լ�ڴ棬�Ƽ���
    function AddVideoClip(const pVideoInfo: TWSVideoInfo; const pClipTime: CLIP_TIME; pClipObj: Pointer): Pointer;
    // ����ӿ���Ҫ��Ϊ�˼����Զ���
    function AddVideoSource(const FileName: UnicodeString; const pParam : TVideoProcessParam): BOOL; overload;

    function AddAudioSource(const AAudio: IAudioDecoder; const pClipTime: CLIP_TIME): BOOL; overload;
    function AddAudioDecoder(hAudioProcess: HAUDIODECODER; const pClipTime: CLIP_TIME): BOOL; overload;
    // �����Ƶ������ʹ�ûص���ʽ����Լ�ڴ棬�Ƽ���
    function AddAudioClip(const pAudioInfo: TWSAudioInfo; const pClipTime: CLIP_TIME; pClipObj: Pointer): Pointer;
    // ����ӿ���Ҫ��Ϊ�˼����Զ���
    function AddAudioSource(const FileName: UnicodeString; const pParam : TAudioProcessParam): BOOL; overload;

    function GetVideoDecoder: HVIDEODECODER;
    function GetVideoInfo: PWSVideoInfo;

    function GetAudioDecoder: HAUDIODECODER;
    function GetAudioInfo: PWSAudioInfo;

    property VideoSlideParam: TVideoSlideParam read FVideoSlideParam;
    property AudioSlideParam: TAudioSlideParam read FAudioSlideParam;
    property VideoClipEvent: TVideoSlideClipProc read FVideoClipEvent;
    property AudioClipEvent: TAudioSlideClipProc read FAudioClipEvent;
    property DecodeReason: TMediaDecodeReason read FDecodeReason write FDecodeReason;
  end;
var
  gDecMgr: IDecMgr;
  VADecoderAPI: TMediaDecodeAPI;

implementation
{ TMediaDecoder }

procedure TMediaDecoder.ChangeAudioTrack(ATrackId: Integer);
var
  pAudStream: IMediaStream;
begin
  pAudStream := GetAudioDecoder;
  if Assigned(pAudStream) then
  begin
    pAudStream.ChangeStream(ATrackId);
    pAudStream._Release;
  end;
end;

procedure TMediaDecoder.ChangeSubtitle(ATrackId: Integer);
var
  pVidStream: IMediaStream;
begin
  pVidStream := GetVideoDecoder;
  if Assigned(pVidStream) then
  begin
    pVidStream.ChangeStream(ATrackId);
    pVidStream._Release;
  end;
end;

constructor TMediaDecoder.Create(const FileName: WideString;
  const pVidParam: TVideoDecParam; const pAudParam: TAudioDecParam; ADecModel: DEC_MODEL);
begin
  if not Assigned(gDecMgr) then
  begin
    WSCoCreateInstance(CLSID_CDecMgr, nil, 0, IID_IDecMgr, gDecMgr);
  end;
  if Assigned(gDecMgr) then
  begin
    FMediaDecoder := IMediaDecoder(gDecMgr.CreateMediaDecoder(FileName, MEDIA_FILE, pVidParam, pAudParam, ADecModel));
  end;
end;

destructor TMediaDecoder.Destroy;
begin
  if Assigned(FMediaDecoder) then
    FMediaDecoder._Release;
  inherited;
end;

function TMediaDecoder.GetAudioDecoder: HAUDIODECODER;
var
  pAudOutput: IAudioOutput;
begin
  FMediaDecoder.QueryInterface(IID_IAudioOutput, pAudOutput);
  if Assigned(pAudOutput) then
  begin
    pAudOutput.GetAudioOutput(Result);
    pAudOutput._Release;
  end;
end;

function TMediaDecoder.GetAudioInfo: PWSAudioInfo;
var
  pAudStream: IMediaStream;
  pStreamInfo: IStreamInfo;
begin
  pAudStream := GetAudioDecoder;
  if Assigned(pAudStream) then
  begin
    pAudStream.GetStreamInfo(pStreamInfo);
    Result := pStreamInfo.GetAudioInfo;
    pAudStream._Release;
  end;
end;

function TMediaDecoder.GetMediaDecoder: HMEDIADECODER;
begin
  Result := FMediaDecoder;
  Result._AddRef;
end;

function TMediaDecoder.GetVideoDecoder: HVIDEODECODER;
var
  pVidOutput: IVideoOutput;
begin
  FMediaDecoder.QueryInterface(IID_IVideoOutput, pVidOutput);
  if Assigned(pVidOutput) then
  begin
    pVidOutput.GetVideoOutput(Result);
    pVidOutput._Release;
  end;
end;

function TMediaDecoder.GetVideoInfo: PWSVideoInfo;
var
  pVidStream: IMediaStream;
  pStreamInfo: IStreamInfo;
begin
  pVidStream := GetVideoDecoder;
  if Assigned(pVidStream) then
  begin
    pVidStream.GetStreamInfo(pStreamInfo);
    Result := pStreamInfo.GetVideoInfo;
    pVidStream._Release;
  end;
  
end;
function DefaultSDVideoCallBackProc(pUserObj: Pointer; pClipObj: Pointer; nOptFlag: UINT): HVIDEODECODER; stdcall;
begin
  Result:=TSlideDecoderEx(pUserObj).DoVideoCallback(pClipObj, nOptFlag);
end;

function DefaultSDAudioCallBackProc(pUserObj: Pointer; pClipObj: Pointer; nOptFlag: UINT): HAUDIODECODER; stdcall;
begin
  Result:=TSlideDecoderEx(pUserObj).DoAudioCallback(pClipObj, nOptFlag);
end;

{ TVideoSlideDecoderEx }

function TSlideDecoderEx.AddAudioClip(const pAudioInfo: TWSAudioInfo;
  const pClipTime: CLIP_TIME; pClipObj: Pointer): Pointer;
var
  pAudOut: IAudioOutput;
  pAudStream: IMediaStream;
begin
  pAudOut := nil;
  pAudStream := nil;
  if Assigned(FSlideDecoder) then
  begin
    FSlideDecoder.QueryInterface(IID_IAudioOutput, pAudOut);
    if Assigned(pAudOut) then
    begin
      pAudOut.GetAudioOutput(pAudStream);
      if Assigned(pAudStream) then
        FSlideDecoder.AddAudioClip(pAudStream, pAudioInfo, pClipTime, pClipObj);
      pAudOut._Release;
    end;  
  end;
end;

function TSlideDecoderEx.AddAudioDecoder(hAudioProcess: HAUDIODECODER;
  const pClipTime: CLIP_TIME): BOOL;
begin

end;

function TSlideDecoderEx.AddAudioSource(const FileName: UnicodeString;
  const pParam: TAudioProcessParam): BOOL;
begin

end;

function TSlideDecoderEx.AddAudioSource(const AAudio: IAudioDecoder;
  const pClipTime: CLIP_TIME): BOOL;
begin

end;

function TSlideDecoderEx.AddVideoClip(const pVideoInfo: TWSVideoInfo;
  const pClipTime: CLIP_TIME; pClipObj: Pointer): Pointer;
var
  pVidOut: IVideoOutput;
  pVidStream: IMediaStream;
begin
  pVidOut := nil;
  pVidStream := nil;
  FSlideDecoder.QueryInterface(IID_IVideoOutput, pVidOut);
  if Assigned(pVidOut) then
  begin
    pVidOut.GetVideoOutput(pVidStream);
    if Assigned(pVidStream) then
    begin
      FSlideDecoder.AddVideoClip(pVidStream, pVideoInfo, pClipTime, pClipObj);
      pVidStream._Release;
    end;
    pVidOut._Release;
  end;
end;

function TSlideDecoderEx.AddVideoDecoder(hVideoProcess: HVIDEODECODER;
  const pClipTime: CLIP_TIME): BOOL;
begin

end;

function TSlideDecoderEx.AddVideoSource(const FileName: UnicodeString;
  const pParam: TVideoProcessParam): BOOL;
begin

end;

constructor TSlideDecoderEx.Create(const pVidParam: TVideoSlideParam;
  const pAudParam: TAudioSlideParam);
begin
  Create(pVidParam, TVideoSlideClipProc(nil), pAudParam, TAudioSlideClipProc(nil));
end;

constructor TSlideDecoderEx.Create(const pVidParam: TVideoSlideParam;
  AVideoClipEvent: TVideoSlideClipProc; const pAudParam: TAudioSlideParam;
  AAudioClipEvent: TAudioSlideClipProc);
begin
  inherited Create;
  FVideoSlideParam := pVidParam;
  FAudioSlideParam := pAudParam;
  FSlideDecoder := nil;
  WSCoCreateInstance(CLSID_CSlideDecode, nil, 0, IID_ISlideDecoder, FSlideDecoder);
  FDecoderList:=TInterfaceList.Create;
  FVideoClipEvent := AVideoClipEvent;
  FAudioClipEvent := AAudioClipEvent;
end;

constructor TSlideDecoderEx.Create(const pVidParam: TVideoSlideParam;
  AVideoClipEvent: TVideoSlideClipEvent; const pAudParam: TAudioSlideParam;
  AAudioClipEvent: TAudioSlideClipEvent);
begin
  inherited Create;
  FVideoSlideParam := pVidParam;
  FAudioSlideParam := pAudParam;
  FSlideDecoder := nil;
  WSCoCreateInstance(CLSID_CSlideDecode, nil, 0, IID_ISlideDecoder, FSlideDecoder);
  FDecoderList := TInterfaceList.Create;
  @FVideoClipEvent := @AVideoClipEvent;
  @FAudioClipEvent := @AAudioClipEvent;
end;

function TSlideDecoderEx.AddVideoSource(const AVideo: IVideoDecoder;
  const pClipTime: CLIP_TIME): BOOL;
begin

end;

destructor TSlideDecoderEx.Destroy;
begin
  if Assigned(FSlideDecoder) then
    FSlideDecoder._Release;
  inherited;
end;

function TSlideDecoderEx.DoAudioCallback(pClipObj: Pointer;
  nOptFlag: UINT): HAUDIODECODER;
var
  pEvent: TMethod;
begin
  if Assigned(FAudioClipEvent) then
  begin
    pEvent.Code := @FAudioClipEvent;
    pEvent.Data := pClipObj;
    Result := TAudioSlideClipEvent(pEvent)(Self, nOptFlag);
  end else
    Result := nil;
end;

function TSlideDecoderEx.DoVideoCallback(pClipObj: Pointer;
  nOptFlag: UINT): HVIDEODECODER;
var
  pEvent: TMethod;
begin
  if Assigned(FVideoClipEvent) then
  begin
    pEvent.Code := @FVideoClipEvent;
    pEvent.Data := pClipObj;
    Result := TVideoSlideClipEvent(pEvent)(Self, nOptFlag);
  end else
    Result := nil;
end;

function TSlideDecoderEx.GetAudioDecoder: HAUDIODECODER;
var
  pAudOut: IAudioOutput;
  pAudStream: IMediaStream;
begin
  pAudOut := nil;
  pAudStream := nil;
  Result := nil;
  if Assigned(FSlideDecoder) then
  begin
    FSlideDecoder.QueryInterface(IID_IAudioOutput, pAudOut);
    if Assigned(pAudOut) then
    begin
      pAudOut.GetAudioOutput(Result);
      pAudOut._Release;
    end;
  end;
end;

function TSlideDecoderEx.GetAudioInfo: PWSAudioInfo;
var
  pAudStream: IMediaStream;
  pStreamInfo: IStreamInfo;
begin
  pAudStream := GetAudioDecoder;
  pStreamInfo := nil;
  if Assigned(pAudStream) then
  begin
    pAudStream.GetStreamInfo(pStreamInfo);
    if Assigned(pStreamInfo) then
    begin
      Result := pStreamInfo.GetAudioInfo;
      pStreamInfo._Release;
    end;
    pAudStream._Release;
  end;
end;

function TSlideDecoderEx.GetVideoDecoder: HVIDEODECODER;
var
  pVidOut: IVideoOutput;
  pVidStream: IMediaStream;
begin
  pVidOut := nil;
  pVidStream := nil;
  Result := nil;
  if Assigned(FSlideDecoder) then
  begin
    FSlideDecoder.QueryInterface(IID_IVideoOutput, pVidOut);
    if Assigned(pVidOut) then
    begin
      pVidOut.GetVideoOutput(Result);
      pVidOut._Release;
    end;
  end;
end;

function TSlideDecoderEx.GetVideoInfo: PWSVideoInfo;
var
  pVidStream: IMediaStream;
  pStreamInfo: IStreamInfo;
begin
  pVidStream := GetVideoDecoder;
  pStreamInfo := nil;
  if Assigned(pVidStream) then
  begin
    pVidStream.GetStreamInfo(pStreamInfo);
    if Assigned(pStreamInfo) then
    begin
      Result := pStreamInfo.GetVideoInfo;
      pStreamInfo._Release;
    end; 
  end;
end;

{ TMediaDecodeAPI }

function TMediaDecodeAPI.DecMgrInit: BOOL;
begin
  Result := True;
  if not Assigned(gDecMgr) then
    WSCoCreateInstance(CLSID_CDecMgr, nil, 0, IID_IDecMgr, gDecMgr);
  if not Assigned(gDecMgr) then
    Result := False;
end;

procedure TMediaDecodeAPI.DecMgrUninit;
begin
  if Assigned(gDecMgr) then
    gDecMgr._Release;
  gDecMgr := nil;
end;

function TMediaDecodeAPI.WSGetMediaFileInfo(const pFileName: UnicodeString;
  DecMod: DEC_MODEL): IMediaInfo;
begin
  if Assigned(gDecMgr) then
    gDecMgr.GetMediaInfo(pFileName, MEDIA_FILE, DecMod, Result);
end;

procedure TMediaDecodeAPI.WSReleaseMediaFileInfo(pMediaInfo: IMediaInfo);
begin
  if Assigned(pMediaInfo) then
    pMediaInfo._Release;
end;

end.
