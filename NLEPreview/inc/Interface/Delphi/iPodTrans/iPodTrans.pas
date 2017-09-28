unit
	iPodTrans;

interface

uses
    Windows, Messages;

type

MusicItem = record 
	dwID        : DWORD ;                         //MusicΨһ��ʶ
	dwFileSize  : DWORD;                          //Music�ļ��Ĵ�С����
	stTitle     : array[0..255] of widechar;      //Music���⣬����չ��
	stFileDir   : array[0..255] of widechar;      //Music�ļ��Ĵ��·��
end;
PMUSICITEM = ^MusicItem;

iPodDiskInfo = record
   TotalSize  : DWORD;
	 FreeSize   : DWORD;
end;
PDISKINFO = ^iPoddiskInfo;

VideoItem = record
  dwWidth         : DWORD      ;		//��Ƶ�ֱ���
  dwHeight        : DWORD      ;		//
  dwCompression   : DWORD      ;		//ѹ����ʽFourCC����'462H'ΪH.264ѹ����ʽ
  dwBitrate       : DWORD      ;		//��Ƶ���ʣ���λbps
  dwTotalFrames   : DWORD      ;		//��֡��
  dFrameRate      : Double     ;		//��Ƶ֡�ʣ���λfps
  dwLength        : DWORD      ;		//��Ƶ���ȣ���λ������
end;
PVideoItem = ^VideoItem;

AudioItem = record
  dwSampleRate    : DWORD      ;		//��Ƶ�����ʣ���λHz
  dwChannels      : DWORD      ;		//������
  dwCompression   : DWORD      ;		//��Ƶѹ����ʽFourCC����' CAA'ΪAACѹ����ʽ
  bIsVBR          : BOOL       ;		//�Ƿ�̬����
  dwBitrate       : DWORD      ;		//��Ƶ���ʣ���ΪVBR���ʾƽ�����ʣ���λbps
  dwMaxBitrate    : DWORD      ;		//������ʣ�bIsVBRΪFALSEʱ��ֵӦ����
  dwLength        : DWORD      ;		//��Ƶ����

end;
PAudioItem = ^AudioItem;

MediaFileInfo = record
  dwFormat        : DWORD      ;		//�ļ���ʽFourCC����' 4PM'��ʾ�ļ���ʽΪmp4
  dwFileSize      : DWORD      ;		//�ļ���С
  dwLength        : DWORD      ;		//�ļ����ȣ�����ʱ�䣬��λ��ms��
  dwBitrate       : DWORD      ;    //���ʣ���Ƶ����Ƶ֮�ͣ���λbps��
  bHaveAudio      : BOOL       ;		//�Ƿ�����Ƶ
  bHaveVideo      : BOOL       ;		//�Ƿ�����Ƶ
  Audio           : AudioItem  ;
  Video           : VideoItem  ;
end;
PMediaFileInfo = ^MediaFileInfo;

// ��iPod�����ļ�����ķ���ֵ
 ManageFailure =
  (
	SUCCESS = 0,							// ����ɹ�
	OPEN_MEDIA_FILE_FAILURE,	//��ý���ļ�ʧ��
	NOT_ENOUGH_DISK_SPACE, 		//���̿ռ䲻��
	COPY_MEAIA_FILE_FAILURE,	//����ʧ��	
	OPEM_IPOD_FAILURE,				//��iPodʧ��
	WRITE_IPOD_FAILURE,				//д��iPodʧ��
	READ_DATA_FAILURE,				//��ȡ�����ļ�ʧ��
  CREATE_DB_FAILURE
  );

 const
    WM_COPY_PROGRESS = (WM_USER + 3002);        // �ļ�����������Ϣ֪ͨ wParam: 0   ���ڴ���  lParam: 0 - 100
                                                //                      100 �������  lParam : 0 �������
                                                //                                             1 �û���ֹ
                                                //                                             2 �ⲿ�ص���ֹ
                                                //                                             3 ��������


const
    WM_COPY_I2P_PROGRESS = (WM_USER + 3003);    // �ļ�����������Ϣ֪ͨ wParam: 0   ���ڴ���  lParam: 0 - 100
                                                //                      100 �������  lParam : 0 �������
                                                //                                             1 �û���ֹ
                                                //                                             2 �ⲿ�ص���ֹ
                                                //
//�����ļ���iPod�У� 0Ϊ�ɹ�����0Ϊʧ�� 
//int __stdcall WEWriteFileToIpod(const wchar_t* pFileName);	
//ManageFailure __stdcall WEWriteFileToIpodEx(const wchar_t* pFileName, const wchar_t* pTitle, int nTimeLength, 
								//const wchar_t* pDiskSymbol, MusicItem* pMusicItem, HWND hMsgReceiverWnd);		//����DiskSymbol��ΪNULL��pParam��δʹ��	
function WTWriteFileToIpodEx(const pFileName : PWideChar; const pTitle : PWideChar; nTimeLength : Integer;		 //����DiskSymbol��ΪNULL��pParam��δʹ��
                             const pDiskSymbol : PWideChar;  pMI : PMUSICITEM; hMsgReceiverWnd : HWND; piPodDiskInfo:PDISKINFO) : ManageFailure; stdcall;




//1.������ֵΪ-1ʱ�������Ϣʧ��
//pdisk_symbolΪ�̷�����ָ��ʱ���գ�
//2.pMusicInfo���յ�ʱ�򣬸ú�������ֵΪ���ݿ��ļ���¼��������Ŀ��
//3.pMusicInfo��Ϊ�յ�ʱ�򣬴�����iMIContentΪ����Ĵ�С��FileNameΪҪ���ҵ��ļ��У���������ֵ��-1��ʱ��ΪpMusicInfo��ʵ����Ϣ������
//int __stdcall WTGetMusicInfo( wchar_t* pdisk_symbol, MusicItem* pMusicInfo, int ArraySize);
function WTGetMusicInfoEx(pDiskSymbol : PWideChar; pMI : PMUSICITEM; ArraySize: Integer; piPodDiskInfo:PDISKINFO ): Integer; stdcall;

//pdisk_symbolΪNULL, MusicIDΪ����Ψһ��ʶ��FileNameΪ��������·����
//ManageFailure __stdcall WTDeleteMusic(wchar_t* pdisk_symbol, DWORD MusicID, const wchar_t* FileName);
function WTDeleteMusicEx(pDiskSymbol : PWideChar; MusicID: DWORD; const FileName: PWideChar; piPodDiskInfo:PDISKINFO): ManageFailure; stdcall;


// ��ȡ��ý���ļ��Ĳ���ʱ�䣬��λ�룬Ŀǰֻ֧��MP4, M4V, M4A��MP3��ʽ����ȡʧ�ܷ���-1
// �����в��Բ����Ϸ��Խ��м�飬�ɵ����߱�֤.
function  WTGetTimeLengthEx(const lpFile: PWideChar): integer; stdcall;


//BOOL WTCopyFileEx(LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName, HWND hMsgReceiverWnd);
function WTCopyFileEx(lpExistingFileName, lpNewFileName : PWideChar;  hMsgReceiverWnd: HWND): Boolean; stdcall;

// ��ȡ��ý���ļ���Ϣ
//BOOL __stdcall WTGetFileInfo(const wchar_t* pFileName, MediaFileInfo* pInfo);
function WTGetFileInfo(pFileName : PWideChar; pInfo :  PMediaFileInfo):BOOL;stdcall;

//��ȡiPod�Ĵ���, ��������µ���������1, С������Ϊ0, ��ȡiPod�����أ�1
//int __stdcall WTGetIpodGeneration(wchar_t* pdisk_symbol);
function WTGetIpodGeneration(): Integer; stdcall;

implementation

const
    DLLNAME = 'WS_iPodTrans.dll';

    function WTWriteFileToIpodEx			  ; external DLLNAME index 3;
    function WTGetMusicInfoEx           ; external DLLNAME index 1;
    function WTDeleteMusicEx            ; external DLLNAME index 2;
    function WTGetTimeLengthEx          ; external DLLNAME index 4;
    function WTCopyFileEx               ; external DLLNAME index 5;
    function WTGetFileInfo              ; external DLLNAME index 6;
    function WTGetIpodGeneration        ; external DLLNAME index 7;

end.
