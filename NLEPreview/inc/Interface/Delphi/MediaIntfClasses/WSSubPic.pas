unit WSSubPic;

interface
uses
  Windows, WSTextArt;
type
  // �û��Զ������Ļ��ʽ
  TSubPicStyle = record
    bUseDefaultStyle: BOOL;       // �Ƿ�ʹ��Ĭ����ʽ
    szFontName: array[0..127] of WideChar;  // ������
    nFontSize: Longint;           // �����С
    uStyle: UINT;                 // ������ʽ PCSFontStyleRegular | PCSFontStyleBold | PCSFontStyleItalic | PCSFontStyleUnderline
    Color: COLORREF;              // ������ɫ
    bShadow: BOOL;                // �Ƿ�ʹ����Ӱ
    paramShadow: TShadowParam;    // ������Ӱ��bShadowΪ��ʱ��Ч��
{$IFDEF WIN32}
    nHalation: Longint;           // ����ֵ 0Ϊ�޹���Ч��
    crHalation: COLORREF;         // ������ɫֵ
{$ENDIF}
    nAngle: Longint;              // ��ת�Ƕ� ˳ʱ�루0-360��
    nLeftTopX: Longint;           // ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�X����
    nLeftTopY: Longint;           // ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�Y����
  end;

  PUserSubPicRec = ^TUserSubPicRec;
  TUserSubPicRec = record
    uSubPicID: UINT;              // ��ĻID
    Style: TSubPicStyle;          // ��Ļ��ʽ
    nOpacity: Longint;            // ͸���� Add by LSG
  end;

  TUserSubPicEx = record
    pSubPicPath: PWideChar;        // ��Ļ��
    Style: TSubPicStyle;            // ��Ļ��ʽ
  end;
  PUserSubPicEx = ^TUserSubPicEx;

implementation

end.
