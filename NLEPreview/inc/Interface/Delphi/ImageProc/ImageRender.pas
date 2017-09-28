unit
	ImageRender;
    
interface

{$MINENUMSIZE 4}

uses
    Windows, Image;


// ͼ���˾�ID
type
IMAGE_FILTER_ID =
(
	IFI_NONE,		
	IFI_ZOOM_BLUR,				// Zoomģ�� nRadius - ģ�����
	IFI_GAUSS_BLUR,				// ��˹ģ�� nRadius - ģ���뾶 
	IFI_SHADOW,					// �����Ӱ nRadius - ��͸����  nParam1 - ��Ӱ��ɫ��COLORREF�� nParam2 - ƽ���̶� nParam3 - X����ƫ�� nParam4 - Y����ƫ��

	IFI_INVERT			= 300,	// ͼ��ɫ
	IFI_GRAY_SCALE,				// �Ҷ�ͼ��
	IFI_THRESHOLD,				// ��ֵ nRadius (0 - 255)
	IFI_FLIP,					// ��ֱ��ת
	IFI_FLIP_HORZ,				// ˮƽ��ת
	IFI_EMBOSS,					// ���� nRadius (0 - 100)
	IFI_SPLASH,					// �ߵ� nRadius (0 - 255)
	IFI_MOSAIC,					// ������ nRadius (0 - 255)
	IFI_OIL_PAINT,				// �ͻ� nRadius (0 - 10)
	IFI_3DGRID,					// 3D���� nParam1 - ����ߴ磨1 - �� nParam2 - ������ȣ�1 - �� 
	IFI_WHIRL_PINCH,			// ��ת��ѹ nParam1 - ��ת��0 - 360�� nParam2 - ��ѹ��0 - 100�� 
	IFI_GRADIENT_RADIAL,		// �����ͽ��� �ݲ�ʹ��
	IFI_GAMMA,					// gamma���� nRadius (0 - 255)
	IFI_ROTATE90,				// ˳ʱ����ת90��/rotate 90'
	IFI_RIBBON,					// ���� nParam1 : ���[0..100]����ֵΪһ�ٷֱ�  nParam2 : Ƶ��>=0��ÿ10Ϊһ��pi
	IFI_HALFTONE_M3,			// ��Ӱ�� �޲���
	IFI_BRIGHTNESS,				// �������� ʹ��nParam1������0 - 200�� 
	IFI_CONTRAST,				// ���ڶԱȶ� ʹ��nParam1������0 - 200�� 
	IFI_COLORTONE,				// ��ɫ�� nParam1 - R���� nParam2 - G���� nParam3 - B����
	IFI_HUE_SATURATION,			// ɫ�����Ͷ�/hue saturation  nParam1 - ɫ��(-180, 180) nParam2 - ���Ͷ�(-100, 100) 
	IFI_CREATEHALO,				// ��������
	IFI_OLD_PHOTO,				// ����Ƭ nRadius (0 - 10) ��ʱδʹ���κβ���

	IFI_STRETCH = 500,			// nQuality ȡֵ��IMAGE_INTERPOLATION���� nParam1 - ���ź�ͼ��Ŀ�� nParam2 - ���ź�ͼ��ĸ߶�
	IFI_ROTATE,					// ��ת nAngle - (0 - 360)
	
	IFI_COUNT
);								
	
// Image Filter Parameter structure
type
  IMAGE_FILTER_PARAM = record
   
	uFilterID : IMAGE_FILTER_ID;	// �˾�ID
	nRadius : Integer;				// �뾶
	nAngle : Integer;				// �Ƕ�
	nQuality : Integer;				// Ʒ��
	nParam1 : Integer;
	nParam2 : Integer;
	nParam3 : Integer;
	nParam4 : Integer;

end;




type
    FILTERPARAM = record
    uFilterID : IMAGE_FILTER_ID;
    IDCaption :  Array[0..63] of WideChar;  //��ʾ�ı���
    bRadius : BOOL;  RadiusText:  Array[0..31] of WideChar; RadiusMax, RadiusMin: integer;
    bAngle : BOOL;   AngleText:   Array[0..31] of WideChar;  AngleMax, AngleMin: integer;
    bQuality: BOOL;  QualityText: Array[0..31] of WideChar; QualityMax, QualityMin: integer;
    bParam1: BOOL;   Param1Text:  Array[0..31] of WideChar; Param1Max, Param1Min :integer;
    bParam2: BOOL;   Param2Text:  Array[0..31] of WideChar; Param2Max, Param2Min :integer;
    bParam3: BOOL;   Param3Text:  Array[0..31] of WideChar; Param3Max, Param3Min :integer;
    bParam4: BOOL;   Param4Text:  Array[0..31] of WideChar; Param4Max, Param4Min :integer;
 end;
   LPFILTERPARAM = ^FILTERPARAM;
  LPIMAGE_FILTER_PARAM = ^IMAGE_FILTER_PARAM;

 	LPVOID = Pointer;	//


// ͼ���˾��ص���������
//typedef BOOL (__stdcall * IMAGE_FILTER_CALLBACK)(void* pUserObj, UINT uMesg, WPARAM wParam, LPARAM lParam);
type
  IMAGE_FILTER_CALLBACK = function(pUserObj: Pointer; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): DWORD; stdcall; 

// ͼ���˾����� �ݲ�֧�ֻص�
//BOOL __stdcall IRImageFitler(HDIBIMAGE hImageDst, HDIBIMAGE hImageSrc, LPIMAGE_FILTER_PARAM pParam, IMAGE_FILTER_CALLBACK fnCallback = 0, void* pUserObj = 0);
function IRImageFitler(hImageDst : HDIBIMAGE; hImageSrc : HDIBIMAGE; pParam : LPIMAGE_FILTER_PARAM; fnCallback : IMAGE_FILTER_CALLBACK = nil; pUserObj : LPVOID = nil) : BOOL; stdcall;


//BOOL __stdcall IRGetFilterParam(IMAGE_FILTER_ID uFilterID, LPFILTERPARAM pParam); // ȡ��Filter����
function IRGetFilterParam(uFilterID : IMAGE_FILTER_ID; pParam : LPFILTERPARAM) : BOOL; stdcall;

//int __stdcall IRGetFilterCount()  //ȡ�ãƣ������ĸ�����
function IRGetFilterCount(): integer;  stdcall;

//BOOL __stdcall IRGetFilterItem(int Index , LPFILTERPARAM pParam) //ȡ�õڡ�index��
function IRGetFilterItem(Index: integer; pParam: LPFILTERPARAM): BOOL; stdcall;

implementation

const
    DLLNAME = 'WS_ImageProc.dll';

function IRImageFitler					; external DLLNAME Name 'IRImageFitler';
function IRGetFilterParam				; external DLLNAME Name 'IRGetFilterParam';
function IRGetFilterCount				; external DLLNAME Name 'IRGetFilterCount';
function IRGetFilterItem				; external DLLNAME Name 'IRGetFilterItem';

end.

