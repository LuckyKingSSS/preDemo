unit
	Log;
    // �ṩ��־��¼ ����
    
interface

uses
    Windows;

type
   HLOGFILE = pointer;
   
// ������־�ļ�����������·�� Ĭ��Ϊ"log.txt" ȫ����־��д�뵽{app}\logĿ¼
// bUseHDInfo - �Ƿ����Ӳ����Ϣ
// bClearLog - �Ƿ���վ���Ϣ
// WSLogInit�Ǳ�����õ�
//void __stdcall WSLogInit(const wchar_t* pFileName, BOOL bUseHDInfo = TRUE, BOOL bClearLog = FALSE, DWORD dwReserved = 0);
procedure WSLogInit(const pFileName: PWideChar; bUseHDInfo : BOOL = TRUE; bClearLog : BOOL = FALSE; dwReserved : DWORD = 0); stdcall;

//void __stdcall WSLogUninit();
procedure WSLogUninit(); stdcall;
// ���ܣ� ��¼�����־
// ����:  �޷���ֵ
//void WSLog(const wchar_t* pText);
procedure WSLog(const pText: PWideChar); stdcall;

//void __stdcall WSOutput(const wchar_t* lpszFormat); // ���������Ϣ ʹ��XTraceMonitor.exe�鿴
procedure WSOutput(const lpszFormat: PWideChar); stdcall;

//void __stdcall WSOutputEx(COLORREF crText, const wchar_t* lpszFormat); // ���������Ϣ crTextΪ�ı���ɫ
procedure WSOutputEx(crText : COLORREF; const lpszFormat: PWideChar); stdcall;

//void __stdcall WSOutputImg(LPBITMAPINFO lpbi, LPVOID lpBits); //���ͼ��
procedure WSOutputImg(lpbi: PBitmapInfo; lpBits: Pointer); stdcall;

//����Log�ļ� pFileNameΪ����λ�� bUseHDInfoΪ�Ƿ���Ҫ����Ӳ����Ϣ bClearLog�Ƿ�Ҫ���ԭ����Log�ļ� dwReserveΪ������
//HLOGFILE __stdcall LogFileCreate(const wchar_t* pFileName, BOOL bUseHDInfo, BOOL bClearLog, DWORD dwReserve);
function LogFileCreate(const pFileName : PWideChar; bUseHDInfo : BOOL; bClearLog : BOOL; dwReserve : DWORD) : HLOGFILE; stdcall;

//void __stdcall LogFileDestroy(HLOG hLog);//����Log�ļ�
procedure LogFileDestroy(hLog : HLOGFILE); stdcall;

//void __stdcall LogFileLog(HLOG hLog, const wchar_t* pText);//д��־�ļ�
procedure LogFileLog(hLog : HLOGFILE; const pText : PWideChar); stdcall;

//const wchar_t* __stdcall ReadLogFileBuffer(const wchar_t* pFileName); //��ȡ�ļ��������ַ���ָ��
function ReadLogFileBuffer(const pFileName: PWideChar): PWideChar; stdcall;

//void __stdcall ReleaseLogFileBuffer(const wchar_t* pLogBuffer);//�ͷ��������ַ���ָ��
procedure ReleaseLogFileBuffer(const pLogBuffer: PWideChar); stdcall;


implementation

const
    DLLNAME = 'WS_Log.dll';

procedure WSLogInit						  ; external DLLNAME Name 'WSLogInit';
procedure WSLogUninit           ; external DLLNAME Name 'WSLogUninit';
procedure WSLog						      ; external DLLNAME Name 'WSLog';
procedure WSOutput				      ; external DLLNAME Name 'WSOutput';
procedure WSOutputEx			      ; external DLLNAME Name 'WSOutputEx';
procedure WSOutputImg           ; external DLLNAME Name 'WSOutputImg';

function LogFileCreate		      ; external DLLNAME Name 'LogFileCreate';
procedure LogFileDestroy	      ; external DLLNAME Name 'LogFileDestroy';
procedure LogFileLog			      ; external DLLNAME Name 'LogFileLog';

function ReadLogFileBuffer      ; external DLLNAME Name 'ReadLogFileBuffer';
procedure ReleaseLogFileBuffer  ; external DLLNAME Name 'ReleaseLogFileBuffer';

end.