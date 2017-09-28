unit
	TextDef;
    
interface

{$MINENUMSIZE 4}

uses
    Windows;


const TEXT_BUF_MAX_LEN			=	1024;
const EFFECT_NAME_BUF_LEN		=	64;


// �����ֲ����ṹ����
type ARTTEXTPARAM = record

	strArtID : Array[0..63] of WideChar;		// ����������ID
	nParam1 : Integer;	
	nParam2 : Integer;	
	nParam3 : Integer;	
	nParam4 : Integer;	
	nParam5 : Integer;
	dParam6 : double;	
	dParam7 : double;	// 1-7�Ų���������ݾ�������������Ͷ���
end;

// ������Ӱ�ṹ����
type SHADOWPARAM = record

	crColor : COLORREF;	// ��Ӱ��ɫ
	nXOffset : Integer;	// ��ӰX����ƫ��
	nYOffset : Integer;	// ��ӰY����ƫ��
	nOpacity : Integer;	// ��Ӱ��͸����
	nBlurSize : Integer;// ��Ӱģ���̶�
end;

  LPSHADOWPARAM = ^SHADOWPARAM;


// TEXT_STYLE
const PCSFontStyleRegular		= 0;		// ����
const PCSFontStyleBold			= $0001;	// ����
const PCSFontStyleItalic		= $0002;	// б��
const PCSFontStyleUnderline		= $0004;	// �»���
const PCSFontStyleStrikeout		= $0008;	// ɾ����


// �ı����ݽṹ����
type TEXTITEM = record

	strText : Array[0..1023] of WideChar;		// �ı�����
	strFontName : Array[0..127] of WideChar;	// ��������
	crFont : COLORREF;			// ������ɫ
	nFontSize : Integer;		// �ֺ�
	uStyle : UINT;			// TEXT_STYLE �ɸ�style���������

	bShadow : BOOL;		// �Ƿ�ʹ����Ӱ
	paramShadow : SHADOWPARAM;	// ������Ӱ��bShadowΪ��ʱ��Ч�� �����ֲ�ʹ�øò��� 
	nHalation : Integer;		// ����ֵ 0Ϊ�޹���Ч��
	crHalation : COLORREF;		// ������ɫֵ
	nAngle : Integer;			// ��ת�Ƕ� ˳ʱ�루0-360��

	xScale : Integer;			// ������������ ��δʹ��
	yScale : Integer;			// ������������ ��δʹ��

	dwReserved : DWORD;		// ����ʹ��
	dwReserved2 : DWORD;	// ����ʹ��
end;

  LPTEXTITEM = ^TEXTITEM;

// ���������ݽṹ����
type ARTTEXTITEM = record

	txtBase : TEXTITEM;		// ������������
	artTxtParam : ARTTEXTPARAM;	// �����ֲ���
end;

  LPARTTEXTITEM = ^ARTTEXTITEM;
 
implementation

end.


