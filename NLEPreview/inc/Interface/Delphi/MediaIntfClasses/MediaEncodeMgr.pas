unit MediaEncodeMgr;

interface
uses
  Windows, MediaCommon;

const
  CLSID_CFileFormatInfos: TGUID = '{f1eb87e5-6940-42b6-b4ce-208aa7695819}';
  IID_IFileFormatInfos: TGUID = '{5C9908D7-FDCD-4827-BC0B-94CB3ECCF8BD}';
  IID_IFileFormatInfo: TGUID = '{72BE4AD5-A6B3-4c75-92E2-15BEACE01F72}';
  IID_IEncoderInfos: TGUID = '{A6F06C44-8115-47c5-A98A-F2E44744B378}';
  IID_IEncoderInfo: TGUID = '{D5B71CE2-3957-413c-9DF4-2587CBD20BE4}';
  SEncMgrAPI = 'WS_EncMgr.dll';
type

  IEncoderInfo = interface(IUnknown)
    ['{D5B71CE2-3957-413c-9DF4-2587CBD20BE4}']
    function GetFourCC(): UINT; stdcall;
    function GetName(var pName: WideString): HRESULT; stdcall;
    function GetDescription(var pDescription: WideString): HRESULT; stdcall;
  end;
  
  IEncoderInfos = interface(IUnknown)
    ['{A6F06C44-8115-47c5-A98A-F2E44744B378}']
    function GetCount(): Integer; stdcall;
    function GetItem(nIndex: Integer; var pEncoderInfo: IEncoderInfo): HRESULT; stdcall;
  end;

  IFileFormatInfo = interface(IUnknown)
    ['{72BE4AD5-A6B3-4c75-92E2-15BEACE01F72}']
    function GetFourCC(): UINT; stdcall;
    function GetExName(var pName: UnicodeString): HRESULT; stdcall;
    function GetFormatName(var pFormatName: UnicodeString): HRESULT; stdcall;
    function GetDescription(var pDescription: UnicodeString): HRESULT; stdcall;
    function GetAudioEncoderInfos(var pEncoderInfos: IEncoderInfos): HRESULT; stdcall;
    function GetVideoEncoderInfos(var pEncoderInfos: IEncoderInfos): HRESULT; stdcall;
  end;
  
  IFileFormatInfos = interface(IUnknown)
    ['{5C9908D7-FDCD-4827-BC0B-94CB3ECCF8BD}']
    function GetCount(): Integer; stdcall;
    function GetItem(nIndex: Integer; var pFileFormatInfo: IFileFormatInfo): HRESULT; stdcall;
  end;
const
  RESERVEDSIZE = 1024;

type
  //WMV��ʽ����չ����
  WMV_VideoParamEx = record
    Quality: Longint;            // �����ȼ�   0-4 4Ϊ��� Ĭ��Ϊ0
    VBRType: Longint;            // �ɱ䳤�������� m_VBRType 0 1 Ĭ��Ϊ0 ��̬����VBR 0 ƽ������ABR 1(��ʱ��֧��)
    MaxBuffer: Longint;          // �����С   0~10�� Ĭ��Ϊ0
    IFrameInterval: Longint;     // Ĭ��Ϊ25
  end;

  VC1_VideoParamEx = record
    dwProfile: Cardinal;
	  dwComplexityLevel: Cardinal;
	  dwQP: Cardinal;
	  dwMaxKeyFrameDistance: Cardinal;
	  dwNumOfBFrames: Cardinal;
	  dwRateControlMode: Cardinal;
	  dwVBVBufferInBytes: Cardinal;
    dPeakBitRate: Double;
  end;

  Xvid_EncodeParamEx = record
    Quality: Integer;
    VHQMODE: Integer;
  end;

  TVideoParamEx = record
    dwFourCC: DWORD; // ��Ƶ������ FourCC �� '1VMW'/'2VMW'/'3VMW' /'DIVX'/'462H'
    case Integer of
      0: (wmvParamEx: WMV_VideoParamEx);
      1: (vc1ParamEx: VC1_VideoParamEx);
      2: (xvidParamEx: Xvid_EncodeParamEx);
      3: (reserved : array[0..RESERVEDSIZE-1] of Longint); //�����ֶ� Ϊ�˷���̶���С�ṹ
  end;

  TAudioParamEx = record
    dwFourCC: DWORD; // ��Ƶ������ FourCC �� '1AMW'/'2AMW'/'3AMW' /' 3PM'
    case Integer of
      0: (reserved : array[0..RESERVEDSIZE div 2-1] of Longint); //�����ֶ� Ϊ�˷���̶���С�ṹ
  end;

  PEncodeParamEx = ^TEncodeParamEx;
  TEncodeParamEx = record
    dwFourCC: DWORD;             // �ļ���ʽFourCC
    useflg: Longint;             // ��Ч��־  0  δʹ�� 1 ��Ƶ��չ����  2��Ƶ��չ���� 3 ����Ƶ��չ����
    m_TwoPass: Longint;          // ���α����־  0 һ�α���; 1 ���α���ֻ��һ������; 2 ���α����Ͷ�������      Ĭ��Ϊ0
    videoEx: TVideoParamEx;       // ��Ƶ��չ����
    audioEx: TAudioParamEx;       // ��Ƶ��չ����
  end;

 // ��Ƶ����
  PVideoParam = ^TVideoParam;
  TVideoParam = record
    dwFourCC : DWORD;    // ��Ƶ������ FourCC �� 'V2PM'
    nWidth : Longint;    // �ֱ��ʿ��    720
    nHeight : Longint;    // �ֱ��ʸ߶�   480��576�����ڣ�
    dFrameRate : double;  // ֡�� 0��ʾ�Զ�ѡ��  30000.0 / 1001 ��25�����ڣ�
    nBitrate : Longint;    // ���� bps ���㶨���ʡ��ɱ���С���ʣ� 9800��000��4000��000
    bIsVBR : BOOL;      // �Ƿ�ʹ�ñ�����
    nMaxBitrate : Longint;  // �������
    nResizeStyle : IMAGE_RESIZE_METHOD; // ͼ�����ŷ�ʽ
    nInterpolation : IMAGE_INTERPOLATION;  // ͼ���ֵ�㷨
    dwCompression : DWORD;        // ͼ���ʽ  ��21VY��
    nBitsDepth : Longint;          // ͼ��λ���  12
    
    //=============== MPEG ���������� ===========================//
    // ʹ��Mpeg������ο�     mpeg_param.pas                     // 
    dwFormat   : DWORD;   // �����ʽ                            //
    dwNorm     : DWORD;     // ������ʽ                          //
    dwAspect   : DWORD;   // ����                                //
    bFieldEnc  : BOOL;  // �Ƿ�ʹ�ý���ģʽ                      //
    //=============== MPEG ���������� ===========================//

    VideoParamEx: TEncodeParamEx;
  end;

// ��Ƶ����
  PAudioParam = ^TAudioParam;
  TAudioParam = record
    dwFourCC : DWORD;    // ��Ƶ������ FourCC �� ' 3CA'
    nSampleRate : Longint;  // ������ Hz  DVDĬ��48000
    nChannels : Longint;  // ��������    2
    nBitrate : Longint;    // ���� bps ���㶨���ʡ��ɱ���С���ʣ�128��000
    bIsVBR : BOOL;      // �Ƿ�ʹ�ñ�����
    nMaxBitrate : Longint;  // �������
    nBitsPerSample : Longint;  // Number of bits per sample of mono data 16
  end;  

// �������
  PEncodeParam  = ^TEncodeParam;
  TEncodeParam = record
    Video : TVideoParam;      // ��Ƶ����
    Audio : TAudioParam;      // ��Ƶ����
    bVideoDisable : BOOL;    // ������Ƶ
    bAudioDisable : BOOL;    // ������Ƶ
//    case Longint of
//      0: (format : EncoderFormat);    // �ļ���ʽ
//      1: (dwFourCC: DWORD);           //��Ƶ������
    dwFourCC: DWORD;        // �ļ���ʽFourCC��' 4PM' ��2gpm'
  end;

  PEncoderInfo = ^TEncoderInfo;
  TEncoderInfo = record
    dwFourCC      : DWORD;
    szEncName     : array [0..63] of WideChar;
    szDescription : array [0..127] of WideChar;
  end;

  PPEncoderInfo = ^PEncoderInfo;

  PFileFormatInfo = ^TFileFormatInfo;
  TFileFormatInfo = record
    dwFourCC      : DWORD;
    szExtName     : array [0..9] of WideChar;
    szFormatName  : array [0..63] of WideChar;
    szDescription : array [0..127] of WideChar;
    nAudioEncs    : Longint;
    nVideoEncs    : Longint;
    ppAudioEncInfos  : PPEncoderInfo;
    ppVideoEncInfos  : PPEncoderInfo;
  end;


// Ӧ�ó�������ʱ����
  TFCInitPlugins = function () : BOOL; stdcall;
// Ӧ�ó����˳�ʱ����
  TFCUninitPlugins = procedure (); stdcall;
// ��ȡ�Ѽ���֧�ֵ������ļ���ʽ������FCInitPlugins()���óɹ���ſɵ���
  TFCGetFileFormatInfos = function () : PFILEFORMATINFO; stdcall;
  
  TMediaEncodeMgrAPI = record
  private
    FAPIHandle: THandle;
    FFCInitPlugins: TFCInitPlugins;
    FFCUninitPlugins: TFCUninitPlugins;
    FPluginsInited: BOOL;
    FFileFormatInfoHead: PFileFormatInfo;
  public
    function Init: Boolean;
    procedure Free;

    function FCInitPlugins() : BOOL;
    procedure FCUninitPlugins();
    function FCGetFileFormatInfos() : PFILEFORMATINFO;
  end;
  
var
  MediaEncodeMgrAPI: TMediaEncodeMgrAPI;
  
implementation

uses
  MediaEncode;
  
const
  SFCInitPlugins =  PAnsiChar(5);
  SFCUninitPlugins =  PAnsiChar(6);

{ TMediaEncodeMgrAPI }

function TMediaEncodeMgrAPI.FCGetFileFormatInfos: PFILEFORMATINFO;
begin

end;

function TMediaEncodeMgrAPI.FCInitPlugins: BOOL;
var
  pFileFormatInfos: IFileFormatInfos;
  pFileFormatInfo: IFileFormatInfo;
  pVidEncoderInfos: IEncoderInfos;
  pVidEncoderInfo: IEncoderInfo;
  pAudEncoderInfos: IEncoderInfos;
  pAudEncoderInfo: IEncoderInfo;
  pEncInfo: PEncoderInfo;
  pEnc: PPEncoderInfo;
  I, J: Integer;
  pStr: UnicodeString;
begin
  Result:=FPluginsInited;
  if not FPluginsInited then
  begin
    if Init then
    begin
      if Assigned(FFCInitPlugins) then
      begin
        InterlockedExchange(Longint(FPluginsInited), Ord(FFCInitPlugins()));
        Result := FPluginsInited;
        if Result then
        begin
          pFileFormatInfos := nil;
          WSCoCreateInstance(CLSID_CFileFormatInfos,
            nil, 0, IID_IFileFormatInfos, pFileFormatInfos);
          if Assigned(pFileFormatInfos) then
          begin
            FFileFormatInfoHead := GetMemory((pFileFormatInfos.GetCount + 1) * SizeOf(TFileFormatInfo));
            for I := 0 to pFileFormatInfos.GetCount - 1 do
            begin
              pFileFormatInfo := nil;
              pFileFormatInfos.GetItem(I, pFileFormatInfo);
              if Assigned(pFileFormatInfo) then
              begin
                with FFileFormatInfoHead^ do
                begin
                  dwFourCC := pFileFormatInfo.GetFourCC;
                  pFileFormatInfo.GetExName(pStr);
                  StringToWideChar(pStr, szExtName, length(pStr));
                  pFileFormatInfo.GetFormatName(pStr);
                  StringToWideChar(pStr, szFormatName, Length(pStr));
                  pFileFormatInfo.GetDescription(pStr);
                  StringToWideChar(pStr, szDescription, Length(pStr));
                  pVidEncoderInfos := nil;
                  pFileFormatInfo.GetVideoEncoderInfos(pVidEncoderInfos);
                  if Assigned(pVidEncoderInfos) then
                  begin
                    nVideoEncs := pVidEncoderInfos.GetCount;
                    if nVideoEncs > 0 then
                    begin

                      ppVideoEncInfos := GetMemory(nVideoEncs * SizeOf(PEncoderInfo));
                      pEnc := ppVideoEncInfos;
                      for J := 0 to nVideoEncs - 1 do
                      begin
                        pVidEncoderInfo := nil;
                        pVidEncoderInfos.GetItem(J, pVidEncoderInfo);
                        if Assigned(pVidEncoderInfo) then
                        begin
                          pEncInfo := pEnc^;
                          pEncInfo := GetMemory(SizeOf(TEncoderInfo));
                          with pEncInfo^ do
                          begin
                            dwFourCC := pVidEncoderInfo.GetFourCC;
                            pVidEncoderInfo.GetName(pStr);
                            StringToWideChar(pStr, szEncName, Length(pStr));
                            pVidEncoderInfo.GetDescription(pStr);
                            StringToWideChar(pStr, szDescription, Length(pStr));
                          end;  
                          Inc(pEnc);
                          pVidEncoderInfo._Release;
                        end;  
                      end;

                      ppAudioEncInfos := GetMemory(nAudioEncs * SizeOf(PEncoderInfo));
                      pEnc := ppAudioEncInfos;
                      for J := 0 to nAudioEncs - 1 do
                      begin
                        pAudEncoderInfo := nil;
                        pAudEncoderInfos.GetItem(J, pAudEncoderInfo);
                        if Assigned(pAudEncoderInfo) then
                        begin
                          pEncInfo := pEnc^;
                          pEncInfo := GetMemory(SizeOf(TEncoderInfo));
                          with pEncInfo^ do
                          begin
                            dwFourCC := pAudEncoderInfo.GetFourCC;
                            pAudEncoderInfo.GetName(pStr);
                            StringToWideChar(pStr, szEncName, Length(pStr));
                            pAudEncoderInfo.GetDescription(pStr);
                            StringToWideChar(pStr, szDescription, Length(pStr));
                          end;
                          Inc(pEnc);
                          pAudEncoderInfo._Release;
                        end;  
                      end;  
                    end;
                    pVidEncoderInfos._Release;  
                  end;  
                end;  
                Inc(FFileFormatInfoHead);
              end;  
            end;  
          end;
        end;
      end;
    end;
  end;
end;

procedure TMediaEncodeMgrAPI.FCUninitPlugins;
begin
  if FPluginsInited then
  begin
    if Assigned(FFCUninitPlugins) then
      FFCUninitPlugins;
    InterlockedExchange(Longint(FPluginsInited), 0);
  end;
end;

procedure TMediaEncodeMgrAPI.Free;
begin
  if FAPIHandle <> 0 then
  begin
    FCUninitPlugins;      // ж�ز��
    FreeLibrary(FAPIHandle);
    FAPIHandle := 0;
    FillChar(Self, SizeOf(Self), 0);
  end;
end;

function TMediaEncodeMgrAPI.Init: Boolean;
begin
  if FAPIHandle=0 then
  begin
    FAPIHandle := LoadLibrary(SEncMgrAPI);
    if FAPIHandle <> 0 then
    begin
      FFCInitPlugins := GetProcAddress(FAPIHandle, (SFCInitPlugins));
      FFCUninitPlugins := GetProcAddress(FAPIHandle, (SFCUninitPlugins));
    end else
      RaiseLoadLibError(SEncMgrAPI);
  end;
  Result := FAPIHandle<>0;
end;

end.
