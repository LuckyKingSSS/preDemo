unit
	BatchConvProc; 

{$MINENUMSIZE 4}
    
interface

uses
    Windows, Messages, EncParam, ConvTaskInfo;



type
	HSUBVIEW = HWND;
	HVIEW = HWND;

	
{$IFNDEF EVENT_WAIT_STATE}
{$DEFINE EVENT_WAIT_STATE}

const
 EWS_OK			= (0);
 EWS_TIMEOUT	= ($0102);
 EWS_ERROR		= (-1);


{$IFNDEF WAIT_OBJECT_0}
{$DEFINE WAIT_OBJECT_0}
const
 WAIT_OBJECT_0	= 0;
{$ENDIF}  //  WAIT_OBJECT_0

{$ENDIF}  //  EVENT_WAIT_STATE



const
 UM_CONVERT_PROGRESS   = (WM_USER + 3000);
	// wParam -  0 ����  lParam - ����(LOWORD:�ܽ��� HIWORD:��ǰ������� 0-100)  ��ϸ��Ϣ��ʹ�� BCGetProgressInfo	
	//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
	//         100 �ڶ��ν��ȿ�ʼ 
	//           101 ������Ϣ  lParam - ����(0-100)
	//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
	// 	  1000 ��ʼ������
			

const
 UM_CONVERT_END        = (WM_USER + 3001);
 UM_CONVERT_ERROR      = (WM_USER + 3002);


type
 ConvertProgressInfo = record

	 nTotalFrames       	: Integer; // ӰƬ��֡����
	 dTotalLength     		: double; // ӰƬ��ʱ�䳤��
	 dTotalTransedLength	: double; // ��������ת��ӰƬʱ��

	 nCurrFrame          	: Integer; // ��ǰ֡
  	 nPercent            	: Integer; // ������ٷֱȣ�0 - 100��
  	 nCurrentTaskPercent 	: Integer; // ��ǰ������Ȱٷֱ�
  	 nCurrentTaskIndex   	: Integer; // ��ǰ����������, �ӣ���ʼ
	 nTaskCount				: Integer; // ��������?		


	 tmPrepaid				: DWORD; // ����ʱ�� ��λ����
	 tmRemain				: DWORD; // ʣ��ʱ�� ��λ����

	 dCurrTransedTime		: double; // ��ǰ������ת��ӰƬʱ��
	 dCurrLength			: double; // ��ǰ����ӰƬ����
	 dTransRate				: double; // ת�����ʣ���λ��ÿ��ת����Ƭ�ϳ���
	 nFramesPerSecond		: Integer; // ת�����ʣ���λ��ÿ�봦���֡��
  	 nEnocdeFramesPerSecond	: Integer; // ÿ���ӱ������Ƶ֡����

	 dwConvState			: ConvertState; // ת��״̬		

end; 
  PConvertProgressInfo = ^ConvertProgressInfo;


//void __stdcall InitTaskItem(TaskItem* pTask);
procedure InitTaskItem(pTask : PTaskItem); stdcall;

//void __stdcall InitEncParam(EncodeParam* pEncParam);
procedure InitEncParam(pEncParam : PEncodeParam); stdcall;


type HBATCHCONVERTER = pointer;
type HEXPORTVIEWER = pointer;


//HBATCHCONVERTER __stdcall BCCreate();
function BCCreate() : HBATCHCONVERTER; stdcall;

//void __stdcall BCDestroy(HBATCHCONVERTER hBatchConv);
procedure BCDestroy(hBatchConv : HBATCHCONVERTER); stdcall;



//HEXPORTVIEWER __stdcall BCInitPreview(HBATCHCONVERTER hBatchConv, HVIEW hParentWnd, LPRECT pRcPos);
function BCInitPreview(hBatchConv : HBATCHCONVERTER; hParentWnd : HVIEW; pRcPos : PRECT) : HEXPORTVIEWER; stdcall;
 

//void __stdcall BCAddTaskItem(HBATCHCONVERTER hBatchConv, const TaskItem* pTask);
procedure BCAddTaskItem(hBatchConv : HBATCHCONVERTER; const pTask : PTaskItem); stdcall;

//int __stdcall BCGetTaskCount(HBATCHCONVERTER hBatchConv);
function BCGetTaskCount(hBatchConv : HBATCHCONVERTER) : Integer; stdcall;

//BOOL __stdcall BCGetTaskItem(HBATCHCONVERTER hBatchConv, int nIndex, TaskItem* pTask);
function BCGetTaskItem(hBatchConv : HBATCHCONVERTER; nIndex : Integer; const pTask : PTaskItem) : BOOL; stdcall;

//void __stdcall BCSetAudioLimitLength(HBATCHCONVERTER hBatchConv, int nLimitLength);
procedure BCSetAudioLimitLength(hBatchConv : HBATCHCONVERTER; nLimitLength : Integer); stdcall;

//void __stdcall BCSetWatermarkImage(HVIDEODECODER hVideo, LPBITMAPINFO lpbi, LPBYTE lpBits, const LPRECT pRect = 0, int nOpacity = 100); // ֧��32λ͸��ͼ�� pRect - ����ڼ��ú��ͼ��ֱ����е�λ��
//procedure BCSetWatermarkImage(hBatchConv : HBATCHCONVERTER; lpbi : PBITMAPINFO; lpBits : PBYTE; const pRect : PRECT = nil; nOpacity : Integer = 100); stdcall;



// ��ʼת��
//BOOL __stdcall BCRun(HBATCHCONVERTER hBatchConv, HVIEW hWnd = 0, BOOL bMerge = FALSE);
function BCRun(hBatchConv : HBATCHCONVERTER; hWnd : HVIEW = 0; bMerge : BOOL = FALSE) : BOOL; stdcall;

//int __stdcall BCPause(HBATCHCONVERTER hBatchConv);
function BCPause(hBatchConv : HBATCHCONVERTER) : Integer; stdcall;

//int __stdcall BCResume(HBATCHCONVERTER hBatchConv);
function BCResume(hBatchConv : HBATCHCONVERTER) : Integer; stdcall;

//DWORD __stdcall BCWait(HBATCHCONVERTER hBatchConv, UINT uMilliSecondsTimeOut = 0xFFFFFFFF);
function BCWait(hBatchConv : HBATCHCONVERTER; uMilliSecondsTimeOut : UINT = $FFFFFFFF) : DWORD; stdcall;

//int __stdcall BCAbort(HBATCHCONVERTER hBatchConv, WPARAM wParam = 0, LPARAM lParam = 0);
function BCAbort(hBatchConv : HBATCHCONVERTER; wParam : WPARAM = 0; lParam : LPARAM = 0) : Integer; stdcall;

//void __stdcall BCShowPreview(HBATCHCONVERTER hBatchConv, BOOL bShow = TRUE);
procedure BCShowPreview(hBatchConv : HBATCHCONVERTER; bShow : BOOL = TRUE); stdcall;


//void __stdcall BCGetProgressInfo(HBATCHCONVERTER hBatchConv, ConvertProgressInfo* pProgressInfo);
procedure BCGetProgressInfo(hBatchConv : HBATCHCONVERTER; pProgressInfo : PConvertProgressInfo); stdcall;



implementation

const
    DLLNAME = 'WS_BatchConvProc.dll';

procedure InitTaskItem				; external DLLNAME Name 'InitTaskItem';
procedure InitEncParam				; external DLLNAME Name 'InitEncParam';

function BCCreate					; external DLLNAME Name 'BCCreate';
procedure BCDestroy					; external DLLNAME Name 'BCDestroy';
function BCInitPreview				; external DLLNAME Name 'BCInitPreview';
procedure BCAddTaskItem				; external DLLNAME Name 'BCAddTaskItem';

function BCGetTaskCount				; external DLLNAME Name 'BCGetTaskCount';
function BCGetTaskItem				; external DLLNAME Name 'BCGetTaskItem';

procedure BCSetAudioLimitLength				; external DLLNAME Name 'BCSetAudioLimitLength';
//procedure BCSetWatermarkImage				; external DLLNAME Name 'BCSetWatermarkImage';

function BCRun						; external DLLNAME Name 'BCRun';
function BCPause					; external DLLNAME Name 'BCPause';
function BCResume					; external DLLNAME Name 'BCResume';
function BCWait						; external DLLNAME Name 'BCWait';
function BCAbort					; external DLLNAME Name 'BCAbort';

procedure BCShowPreview				; external DLLNAME Name 'BCShowPreview';
procedure BCGetProgressInfo			; external DLLNAME Name 'BCGetProgressInfo';



end.




