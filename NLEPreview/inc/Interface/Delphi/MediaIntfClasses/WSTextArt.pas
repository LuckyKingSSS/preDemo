unit WSTextArt;

interface
uses
  Windows, MediaCommon, MediaDibImage, Graphics;

const
  TEXT_BUF_MAX_LEN   = 1024;
  EFFECT_NAME_BUF_LEN  = 64;
  FONT_BUF_MAX_LEN      = 128;
  
// TEXT_STYLE
  PCSFontStyleRegular  = 0;  // ����
  PCSFontStyleBold   = $0001; // ����
  PCSFontStyleItalic  = $0002; // б��
  PCSFontStyleUnderline  = $0004; // �»���
  PCSFontStyleStrikeout  = $0008; // ɾ����

// �����ֲ����ṹ����

type
  SHADOWPARAM = record
    crColor: COLORREF;
    nXOffset: Integer;
    nYOffset: Integer;
    nOpacity: Integer;
    nBlurSize: Integer;
  end;
  TShadowParam = SHADOWPARAM;
  
  PTEXTITEM = ^TTEXTITEM;
  TTEXTITEM = record
    strText : array[0..TEXT_BUF_MAX_LEN-1] of WideChar;  // �ı�����
    strFontName : array[0..TEXT_FONT_NAME_LEN-1] of WideChar; // ��������
    crFont : COLORREF;   // ������ɫ
    nFontSize : Longint;  // �ֺ�
    uStyle : UINT;       // TEXT_STYLE �ɸ�style���������
    bShadow : BOOL;        // �Ƿ�ʹ����Ӱ
    paramShadow : SHADOWPARAM; // ������Ӱ��bShadowΪ��ʱ��Ч�� �����ֲ�ʹ�øò���
    nHalation : Longint;  // ����ֵ 0Ϊ�޹���Ч��
    crHalation : COLORREF; // ������ɫֵ
    nAngle : Longint;   // ��ת�Ƕ� ˳ʱ�루0-360��
    xScale : Longint;   // ������������ ��δʹ��
    yScale : Longint;   // ������������ ��δʹ��
    dwReserved : DWORD;  // ����ʹ��
    dwReserved2 : DWORD; // ����ʹ��  
  end;

  // ���������ݽṹ����
  PARTTEXTITEM = ^TARTTEXTITEM;
  TARTTEXTITEM = record
   txtBase     : TTextItem;  // ������������
   artTxtParam : TArtTextParam; // �����ֲ���
  end;
  
  ITextItem = interface(IUnknown)
    ['{EDA25D65-A4EE-4d00-B2D0-B37DB619F145}']
    function SetContent(const textContent: WideString): HRESULT; stdcall;
    function GetContent(var pContent: WideString): HRESULT; stdcall;
    function SetFontName(strFontName: WideString): HRESULT; stdcall;
    function GetFontName(var strFontName: WideString): HRESULT; stdcall;
    function SetFontColor(crFont: COLORREF): HRESULT; stdcall;
    function GetFontColor(): COLORREF; stdcall;
    function SetFontSize(nFontSize: Integer): HRESULT; stdcall;
    function GetFontSize(): Integer; stdcall;
    function SetStyle(uStyle: UINT): HRESULT; stdcall;
    function GetStyle(): UINT; stdcall;
    function SetUseShadow(bShadow: Integer): HRESULT; stdcall;
    function GetUseShadow(): Integer; stdcall;
    function SetShadowParam(paramShadow: SHADOWPARAM): HRESULT; stdcall;
    function GetShadowParam(): SHADOWPARAM; stdcall;
    function SetHalation(nHalation: Integer; halationColor: COLORREF): HRESULT; stdcall;
    function GetHalation(var pHalation: Integer; var pHalationColor: COLORREF): HRESULT; stdcall;
    function SetAngle(nAngle: Integer): HRESULT; stdcall;
    function GetAngle(): Integer; stdcall;
    function SetScale(xScale: Integer; yScale: Integer): HRESULT; stdcall;
    function GetScale(var pXScale: Integer; var pYScale: Integer): HRESULT; stdcall;
  end;
  
  IPCText = interface(IUnknown)
    ['{E8E0B4CB-9E9A-46f6-AA7D-FA547A3EA1F4}']
    function LoadImage32B(picName: WideString): Pointer; stdcall;
    function CreateTextSetting(): Pointer; stdcall;
    function GetSupportFontCount(): Integer; stdcall;
    function GetSupportFontName(nIndex: Integer; var pFontName: WideString): HRESULT; stdcall;
    function CreateNormalTextByTrans(const pItem: ITextItem; const lpTextTransform: PTEXTTRANSFORM; pImageTexture: IDibImage): Pointer; stdcall;
    function CreateNormalTextBySize(const pItem: ITextItem; width: Integer; height: Integer; pImageTexture: IDibImage): Pointer; stdcall;
    function GetArtTextCount(): Integer; stdcall;
    function GetArtTextInfo(nIndex: Integer): PARTTEXTINFO; stdcall;
    function GetIndexFromID(var pArtID: WideString): Integer; stdcall;
    function GenerateArtTextByTrans(const pArtItem: PARTTEXTITEM; const lpTextTransform: PTEXTTRANSFORM): Pointer; stdcall;
    function GenerateArtTextBySize(const pArtItem: PARTTEXTITEM; width: Integer; height: Integer): Pointer; stdcall;
  end;

  TWSTextArtAPI = record
    function GenerateNormalTextEx(const pItem: TTextItem; width: Integer; height: Integer; hImageTexture: HDIBIMAGE = nil): HDIBIMAGE;
  end;
  
  function VCLFontStyleToTextStyle(AFontStyle: TFontStyles): DWORD;
  function TextStyleToVCLFontStyle(Value: DWORD): TFontStyles;

var
  WSTextArtAPI: TWSTextArtAPI;

implementation

function VCLFontStyleToTextStyle(AFontStyle: TFontStyles): DWORD;
begin
  Result:=PCSFontStyleRegular;
  if fsBold in AFontStyle then
    Result:=Result or PCSFontStyleBold;
  if fsItalic in AFontStyle then
    Result:=Result or PCSFontStyleItalic;
  if fsUnderline in AFontStyle then
    Result:=Result or PCSFontStyleUnderline;
  if fsStrikeOut in AFontStyle then
    Result:=Result or PCSFontStyleStrikeout;
end;

function TextStyleToVCLFontStyle(Value: DWORD): TFontStyles;
begin
  Result:=[];
  if Value and PCSFontStyleBold<>0 then
    Include(Result, fsBold);
  if Value and PCSFontStyleItalic<>0 then
    Include(Result, fsItalic);
  if Value and PCSFontStyleUnderline<>0 then
    Include(Result, fsUnderline);
  if Value and PCSFontStyleStrikeout<>0 then
    Include(Result, fsStrikeOut);
end;

{ TWSTextArtAPI }

function TWSTextArtAPI.GenerateNormalTextEx(const pItem: TTextItem; width,
  height: Integer; hImageTexture: HDIBIMAGE): HDIBIMAGE;
var
  pPCText: IPCText;
  pTextItem: ITextItem;
begin
  Result := nil;
  WSCoCreateInstance(CLSID_CPCSText, nil, 0, IID_IPCText, pPCText);
  if not Assigned(pPCText) then Exit;
  pTextItem := ITextItem(pPCText.CreateTextSetting);
  if Assigned(pTextItem) then
  begin
    pTextItem.SetContent(pItem.strText);
    pTextItem.SetFontName(pItem.strFontName);
    pTextItem.SetFontColor(pItem.crFont);
    pTextItem.SetFontSize(pItem.nFontSize);
    pTextItem.SetStyle(pItem.uStyle);
    pTextItem.SetUseShadow(Integer(pItem.bShadow));
    pTextItem.SetShadowParam(pItem.paramShadow);
    pTextItem.SetHalation(pItem.nHalation, pItem.crHalation);
    pTextItem.SetAngle(pItem.nAngle);
    pTextItem.SetScale(pItem.xScale, pItem.yScale);
    Result := IDibImage(pPCText.CreateNormalTextBySize(pTextItem, width, height, hImageTexture));
    pTextItem._Release;
  end;
  pPCText._Release;
end;

end.
