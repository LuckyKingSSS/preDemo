unit
	Converter;
    
interface

uses
    Windows, Messages, EncParam;


//#ifndef EVENT_WAIT_STATE
{$ifndef  EVENT_WAIT_STATE}
//#define EVENT_WAIT_STATE
  {$define EVENT_WAIT_STATE}

//#define EWS_OK			(0)
//#define EWS_TIMEOUT		(0x0102L)
//#define EWS_ERROR		(-1)
  {$define EWS_OK			(0)}
  {$define EWS_TIMEOUT		($0102)}
  {$define EWS_ERROR		(-1)}


//#ifndef WAIT_OBJECT_0
//#define WAIT_OBJECT_0	0
//#endif
  {$ifndef WAIT_OBJECT_0}
    {$define WAIT_OBJECT_0	0}
  {$endif}


//#endif // EVENT_WAIT_STATE
{$endif}


//#ifndef WIN32
//	typedef HIViewRef HSUBVIEW;
//	typedef WindowRef HVIEW;
//#else
//	typedef HWND HSUBVIEW;
//	typedef HWND HVIEW;

//#endif


type
	HCONVERTER    = pointer;	// ת�����������
	HVIDEODECODER = pointer;	// VideoDecoder�������
	HAUDIODECODER = pointer;	// AudioDecoder�������
	

type
  TimeData = record
    hour      : Integer;
	  minute    : Integer;
	  second    : Integer;
	  millisec  : Integer;
  end;

type
  PMEDIA_FRAME = pointer;
  ProgressInfo = record
  	  dTotalLength  : double;		  // ��֡����
	  dCurrTime     : double;		  // ��ǰ֡
	  nPercent      : Integer;			// �ٷֱȣ�0 -100��
	  nPercentPercent : Integer;		// ��ֱȣ�0 - 10000��
	  pImageFrame    : PMEDIA_FRAME;	// ͼ������

	  tmPrepaid     : TimeData;		  // ��ǰ��������ʱ�� (ϵͳʱ��)
	  tmRemain      : TimeData;		  // ��ǰ����ʣ��ʱ�� (ϵͳʱ��)
	  dTransedTime  : Double;		    //��ǰ������ת��Ƭ��ʱ��
	  dTransRate    : Double;			  //ת�����ʣ���λ��ÿ��ת����Ƭ�ϳ���
  end;
 
	PProgressInfo = ^ProgressInfo;	// AudioDecoder�������

// ����֪ͨʹ��Windows��Ϣ
const
  WM_ENCODE_PROGRESS = (WM_USER + 3000);    // ������Ϣ֪ͨ wParam: 0   ���ڴ���  lParam: 0 - 100
                                                //                      100 �������  lParam : 0 �������
                                                //                                             1 �û���ֹ
                                                //                                             2 �ⲿ�ص���ֹ
                                                //                                             3 ��������
  WM_ENCODE_ERROR = (WM_USER + 3001);       // ������Ϣ֪ͨ wParam: �����루��δʹ�ã�

  WM_COPY_PROGRESS = (WM_USER + 3002);    // �ļ�����������Ϣ֪ͨ wParam: 0   ���ڴ���  lParam: 0 - 100
                                                //                      100 �������  lParam : 0 �������
                                                //                                             1 �û���ֹ 
                                                //                                             2 �ⲿ�ص���ֹ 
                                                //                                             3 ��������      
      


// ����ʱ��Ԥ��ʹ�ûص�����
//typedef BOOL (__stdcall * ENCODE_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);
// uMsg -    0 ������Ϣ  wParam - ����(0-100)  lParam - ProgressInfo*
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ 
//           101 ������Ϣ  wParam - ����(0-100)  lParam - 0
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
// ����FALSE ��ֹͣת��
//type
//  ENCODE_CALLBACK = function(pUserObj: Pointer; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): BOOL; stdcall; 


//HCONVERTER __stdcall WECreate(HVIDEODECODER hVideoDecoder, HAUDIODECODER hAudioDecoder); // ����������
function WECreate(hVideoDecoder: HVIDEODECODER; hAudioDecoder: HAUDIODECODER) : HCONVERTER; stdcall;

//void __stdcall WEDestroy(HCONVERTER hEncoder); // ���ٱ�����
procedure WEDestroy(hEncoder : HCONVERTER); stdcall;


//BOOL __stdcall WESetOutputFile(HCONVERTER hEncoder, const wchar_t* pOutFileName);
function WESetOutputFile(hEncoder : HCONVERTER; const pOutFileName : PWideChar) : BOOL; stdcall;

//BOOL __stdcall WESetEncodeParam(HCONVERTER hEncoder, const EncodeParam* pParam);
function WESetEncodeParam(hEncoder : HCONVERTER; const pParam : PENCODEPARAM) : BOOL; stdcall;

//BOOL __stdcall WEGetEncodeParam(HCONVERTER hEncoder, EncodeParam* pParam);
function WEGetEncodeParam(hEncoder : HCONVERTER; pParam : PENCODEPARAM) : BOOL; stdcall;

//
//__int64 __stdcall WEGetEstimateDiskSpace(HCONVERTER hEncoder);
function WEGetEstimateDiskSpace(hEncoder : HCONVERTER) : INT64; stdcall;

//__int64 __stdcall WEGetDiskFreeSpace(const wchar_t* pFileName);
function WEGetDiskFreeSpace(const pFileName : PWideChar) : INT64; stdcall;


//int __stdcall WEStart(HCONVERTER hEncoder, HWND hMsgReceiverWnd, ENCODE_CALLBACK fnCallback, void* pUserObj);
// 0 - �ɹ��� ��0ʧ�� 1 - �Ҳ���������Ƶ��ʽ�ı������� 2 - �Ҳ���FourCC��Ӧ����Ƶ������, 3 - ����Ƶ�ļ�ʧ��
//4- ��Ƶ����ʧ�ܣ��޷�������Ƶ�ļ�
function WEStart(hEncoder : HCONVERTER; dBeginTime: Double; dLength: Double;
                 hMsgReceiverWnd : HWND; fnCallback : ENCODE_CALLBACK; pUserObj : Pointer) : Integer; stdcall;

//int __stdcall WEPause(HCONVERTER hEncoder);
function WEPause(hEncoder : HCONVERTER) : Integer; stdcall;

//int __stdcall WEResume(HCONVERTER hEncoder);
function WEResume(hEncoder : HCONVERTER) : Integer; stdcall;

//int __stdcall WEStop(HCONVERTER hEncoder, WPARAM wParam = 0, LPARAM lParam = 0); // ������ֹ��Ϣ ���ȴ�ת������
function WEStop(hEncoder : HCONVERTER; wParam : WPARAM = 0; lParam : LPARAM = 0) : Integer; stdcall;

//int __stdcall WEAbort(HCONVERTER hEncoder, WPARAM wParam = 0, LPARAM lParam = 0); // ������ֹ��Ϣ��Ӧ�ó���Ӧ�õ���WEWait�����ȴ�ת������
function WEAbort(hEncoder : HCONVERTER; wParam : WPARAM = 0; lParam : LPARAM = 0) : Integer; stdcall;

//DWORD __stdcall WEWait(HCONVERTER hEncoder, UINT uMilliSecondsTimeOut = 0xFFFFFFFF); // �ȴ�ת�����
function WEWait(hEncoder : HCONVERTER; uMilliSecondsTimeOut : UINT = $FFFFFFFF) : DWORD; stdcall;


//BOOL __stdcall WEEnablePreview(HCONVERTER hEncoder, BOOL bEnable);
function WEEnablePreview(hEncoder : HCONVERTER; bEnable : BOOL) : BOOL; stdcall;


//__int64 __stdcall WEGetEstimateDiskSpaceEx(const EncodeParam* pParam, double dLength); // ȡ�ù���������̿ռ�
function WEGetEstimateDiskSpaceEx(pParam : PENCODEPARAM; dLength : double) : INT64; stdcall;

const
  SPLIT_BASE_ON_TIME	=	1;
  SPLIT_BASE_ON_SIZE	=	2;
// �����ļ��ָ�Ĳ���
// nStyle - SPLIT_BASE_ON_TIME ��ʱ��ָdwLimit��λΪ����(ms)��
//        - SPLIT_BASE_ON_SIZE ���ļ���С�ָdwLimit��λΪ�ֽ�(Byte)�� ���ݲ�֧�ִ��ַ�ʽ��
//BOOL __stdcall WESetSplitParam(HCONVERTER hConverter, int nStyle, DWORD dwLimit);
function WESetSplitParam(hEncoder : HCONVERTER; nStyle : Integer; dwLimit : DWORD) : BOOL ; stdcall;
// ��ȡ���������ļ���
//int  __stdcall WEGetTargetCount(HCONVERTER hConverter);
function WEGetTargetCount(hEncoder : HCONVERTER) : Integer; stdcall;
// �����ȡ�ļ���
//BOOL __stdcall WEGetTargetFileName(HCONVERTER hConverter, wchar_t pFileName[MAX_PATH], int nIndex);
function WEGetTargetFileName(hEncoder : HCONVERTER; pFileName : PWideChar; nIndex : integer): BOOL; stdcall;

implementation

const
    DLLNAME = 'WS_Converter.dll';

function WECreate						      ; external DLLNAME index 1;
procedure WEDestroy						    ; external DLLNAME index 2;

function WESetOutputFile				  ; external DLLNAME Name 'WESetOutputFile';
function WESetEncodeParam				  ; external DLLNAME Name 'WESetEncodeParam';
function WEGetEncodeParam				  ; external DLLNAME Name 'WEGetEncodeParam';

function WEGetEstimateDiskSpace	  ; external DLLNAME Name 'WEGetEstimateDiskSpace';
function WEGetDiskFreeSpace			  ; external DLLNAME Name 'WEGetDiskFreeSpace';

function WEStart						      ; external DLLNAME Name 'WEStart';
function WEPause						      ; external DLLNAME Name 'WEPause';
function WEResume						      ; external DLLNAME Name 'WEResume';
function WEStop							      ; external DLLNAME Name 'WEStop';
function WEAbort                  ; external DLLNAME Name 'WEAbort';
function WEWait							      ; external DLLNAME Name 'WEWait';
function WEEnablePreview				  ; external DLLNAME Name 'WEEnablePreview';


function WEGetEstimateDiskSpaceEx	; external DLLNAME Name 'WEGetEstimateDiskSpaceEx';

function WESetSplitParam; external DLLNAME Name  'WESetSplitParam';
function WEGetTargetCount; external DLLNAME Name 'WEGetTargetCount';
function WEGetTargetFileName; external DLLNAME Name 'WEGetTargetFileName';


end.


