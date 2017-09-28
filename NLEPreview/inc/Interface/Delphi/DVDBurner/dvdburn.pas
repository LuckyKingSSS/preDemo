unit dvdburner;

interface

uses Windows, Messages;

const
  dvdburner = 'dvdburner.dll';
const
  WM_BURNER_UPDATE = WM_USER + 300;  // wParam ΪBURN_PROGRESS�ȣ�lParamΪ���涨���ֵ

// wParam
  BURN_PROGRESS = 0;// lParamΪ���Ȱٷֱȣ�0-100
  BURN_FINISH = 1;// �ɹ�����
  BURN_ERROR = 2;// ����
  BURN_STATUS = 3;// �ı�״̬��Ϣ��lParamΪwchar_tָ��
  BURN_START = 4;   // ��ʼ

  BURN_FIND_BEGIN = 5;   // 5  find begin
  BURN_FIND_ONE = 6;   // 6 find one  lParamΪDISC_INFO�ṹ
  BURN_FIND_END = 7;   // 7 find ends
  BURN_STATUS_FROMISODATA_START = 8;  //��ʼ��ȡDISC����Ϣ
  BURN_STATUS_FROMISODATA_STOP = 9;  //���DISC����Ϣ

// status
  BURN_STATUS_IDLE = 0;
  BURN_STATUS_FIND = 1; // find device
  BURN_STATUS_TOUDFISO = 2;// to iso
  BURN_STATUS_TOISO9006 = 3;// to iso
  BURN_STATUS_TODVD = 4;  // to dvd
  BURN_STATUS_BLANK = 5;  // to dvd
  BURN_STATUS_TOVIDEOISO = 6;  // to video iso
  BURN_STATUS_TOVIDEODVD = 7;  // to video dvd
  BURN_STATUS_FROMISODATA = 8;  // FROM ISO data

//type
//  DISC_INFO = record
//    string szVolumeName; // G:
//    string szProductId;  // DVD_ROM
//    BOOL bDvdReadSupported;
//    BOOL bDvdWriteSupported;
//    BOOL bCdReadSupported;
//    BOOL bCdWriteSupported;
//    int nIndex;
//  end;

  DVD_INFO = record
    bInsertDVD: Boolean;
    szDVDType: array [0..256] of Char;;
    bNewDVD: Boolean;
    
    bCanWrite: Boolean;
    bCanErase: Boolean;
    bEmpty: Boolean;
    nCurrentSize: int64;
  end;

type
  HQDBURNER = type pointer;


// ������
function AllocBurnCtl(nBurnerId: Integer): HQDBURNER; stdcall; external dvdburner;
procedure FreeBurnCtl(pBurner: HQDBURNER); stdcall; external dvdburner;

function __stdcall InitBurnCtl(pCtl: HQDBURNER); stdcall; 

// ����DVD����
function qBeginFindDisc(pCtl: HQDBURNER; hNotifyWnd: HWnd): Integer; stdcall; external dvdburner;
function qGetDiscCount(pCtl: HQDBURNER): Integer; stdcall; external dvdburner;


// ��¼ISO�ļ�
function qBurnIsoToDvd(pCtl: HQDBURNER; nDiscIndex: Integer; szIsoFile: PWideChar): Integer; stdcall; external dvdburner;

// ��ȡ��ǰ��״̬��0Ϊ����
function qGetStatus(pCtl: HQDBURNER): Integer; stdcall; external dvdburner;

// ���ûص����
procedure qSetWndHandle(pBurner: HQDBURNER;  hNotifyWnd: HWnd); stdcall; external dvdburner;

// ���þ��
procedure qSetVolumeName(pBurner: HQDBURNER;  szVolumeName: PWideChar); stdcall; external dvdburner;

function qBlankDisc(pCtl: HQDBURNER; nDiscIndex: Integer): Integer; stdcall;  //����DVD
function qGetDiscStatus(pCtl: HQDBURNER; nDriverIndex: Integer): Integer; stdcall; //��ȡĳ�������й��̵���Ϣ��
implementation

end.
