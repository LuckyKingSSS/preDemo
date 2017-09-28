unit
  DVDBurnerParam;

interface

uses
  Windows, Messages;

type
  BURNER_ID =
  (
	  USR_STAR_BURN =	0,
	  USR_NERO_BURN
  );

const
   WM_PROGRESS_PERCNET	= WM_USER + 1800;	// ������Ϣ
   WM_DVD_BURNER			  = WM_USER + 1701;	// DVDBurner��Ϣ

{****************************************************************
    uMsg	  : WM_DVD_BURNER;
    wParam	: DVDBURNER_EVENT
    lParam	: BOOL bSuccessful �Ƿ�ɹ�
****************************************************************}
type
  DVDBURNER_EVENT =
  (
	DBE_GETDRIVER_END,			// ȡ��¼����Ϣ����
	DBE_PREPAREBURN_END,        // ׼����¼����
	DBE_GETNEROVERSION_END,		// ȡNero�汾����
	DBE_CREATEISO_END,			// ����ISO�ļ�����
	DEE_BURNDVD_END,			// ��¼DVD����
	DBE_ISOTODVD_END,           // ISO��¼ΪDVD����
	DBE_ERASE_END,              // ��������
	DBE_SPACE_NOT_ENOUGH,       // �����������㣬����ʾ������
	DBE_GETDISKINFO_END,		// ȡ������Ϣ����
	DBE_ERROR                   // ��������
  );

type
  TDiskInfo = record
    m_DiskType: DWORD;			        //  ��Ƭ����
    m_szDiskType: array[0..63] of AnsiChar;	//	��Ƭ��������
    m_bIsEmpty: BOOL;			        //	�Ƿ�Ϊ�յ�
    m_bIsErasable:BOOL;		            //	�Ƿ���Բ���
    m_bWritable: BOOL;		            //	�Ƿ������д
    m_ullFreeSpace : int64;		            //	��Ƭ�ϵĿռ�
    //unsigned __int64	m_ullTotalFileSize;	//	��¼����ļ�����Ŀռ�
  end;
  pCDiskInfo = ^TDiskInfo;

implementation

end.
