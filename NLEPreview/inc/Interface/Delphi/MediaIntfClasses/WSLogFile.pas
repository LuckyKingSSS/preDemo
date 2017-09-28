unit WSLogFile; // �ṩ��־��¼ ����

interface

uses Windows, SysUtils;

{$IFNDEF UNICODE}
type
  UnicodeString = WideString;
{$ENDIF}

{$WARN SYMBOL_PLATFORM OFF}

type
  HLOGFILE = pointer;

// ���Ĭ�ϵ���־�Ѿ���ʹ�ã����޸��ļ�ָ���µ���־������������ͬʱдһ����־
procedure WSLogInitUnUse(const AFileName: UnicodeString; bUseHDInfo : BOOL = TRUE; bClearLog : BOOL = FALSE; dwReserved : DWORD = 0); overload;
// ������־�ļ�����������·�� Ĭ��Ϊ"log.txt" ȫ����־��д�뵽{app}\logĿ¼
// bUseHDInfo - �Ƿ����Ӳ����Ϣ
// bClearLog - �Ƿ���վ���Ϣ
// WSLogInit���Ǳ�����õ�
procedure WSLogInit(const pFileName: PWideChar; bUseHDInfo : BOOL = TRUE; bClearLog : BOOL = FALSE; dwReserved : DWORD = 0); stdcall;
// ���ܣ� ��¼�����־
// ����:  �޷���ֵ
procedure WSLog(const pText: PWideChar); stdcall; overload;
procedure WSLog(const pText: WideString); overload;
procedure WSLog(const pText: string); overload;
// ���������Ϣ ʹ��XTraceMonitor.exe�鿴
procedure WSOutput(const lpszFormat: PWideChar); stdcall;
// ���������Ϣ crTextΪ�ı���ɫ
procedure WSOutputEx(crText : COLORREF; const lpszFormat: PWideChar); stdcall;
// ���ͼ��
procedure WSOutputImg(lpbi: PBitmapInfo; lpBits: Pointer); stdcall;
//����Log�ļ� pFileNameΪ����λ�� bUseHDInfoΪ�Ƿ���Ҫ����Ӳ����Ϣ bClearLog�Ƿ�Ҫ���ԭ����Log�ļ� dwReserveΪ������
function LogFileCreate(const pFileName : PWideChar; bUseHDInfo : BOOL; bClearLog : BOOL; dwReserve : DWORD) : HLOGFILE; stdcall;
//����Log�ļ�
procedure LogFileDestroy(hLog : HLOGFILE); stdcall;
// д��־�ļ�
procedure LogFileLog(hLog : HLOGFILE; const pText : PWideChar); stdcall;
// ��ȡ�ļ��������ַ���ָ��
function ReadLogFileBuffer(const pFileName: PWideChar): PWideChar; stdcall;
// �ͷ��������ַ���ָ��
procedure ReleaseLogFileBuffer(const pLogBuffer: PWideChar); stdcall;
// Base64 �����
// �����ĳ���һ���ԭ�Ķ�ռ��1/3�Ĵ洢�ռ䣬�뱣֤base64code���㹻�Ŀռ�
//int __stdcall WSBase64Encode(char * base64code, const unsigned char * src, int src_len);
function WSBase64Encode(base64code : PAnsiChar; const src : Pointer; src_len : Integer) : Integer; stdcall;

//int __stdcall WSBase64Decode(unsigned char * buf, const char * base64code, int src_len = -1);
function WSBase64Decode(buf : Pointer; const base64code : PAnsiChar; src_len : Integer = -1) : Integer; stdcall;

function StartCheckMD5(const pFileName: PWideChar; const pMD5: PChar): BOOL; stdcall;

implementation

uses WideFileUtils;

const
  DLLNAME = 'WS_Log.dll';
  SLogFileDir = 'Log';

procedure WSLogInit             ; external DLLNAME Name 'WSLogInit';
procedure WSLog(const pText: PWideChar); stdcall;               external DLLNAME Name 'WSLog';
procedure WSOutput              ; external DLLNAME Name 'WSOutput';
procedure WSOutputEx            ; external DLLNAME Name 'WSOutputEx';
procedure WSOutputImg           ; external DLLNAME Name 'WSOutputImg';

function LogFileCreate          ; external DLLNAME Name 'LogFileCreate';
procedure LogFileDestroy        ; external DLLNAME Name 'LogFileDestroy';
procedure LogFileLog            ; external DLLNAME Name 'LogFileLog';

function ReadLogFileBuffer      ; external DLLNAME Name 'ReadLogFileBuffer';
procedure ReleaseLogFileBuffer  ; external DLLNAME Name 'ReleaseLogFileBuffer';
function  WSBase64Encode        ; external DLLNAME Name 'WSBase64Encode';
function  WSBase64Decode        ; external DLLNAME Name 'WSBase64Decode';

function StartCheckMD5          ; external DLLNAME Index 111;

procedure WSLogInitUnUse(const AFileName: UnicodeString; bUseHDInfo : BOOL = TRUE; bClearLog : BOOL = FALSE; dwReserved : DWORD = 0); overload;
var
  n: Integer;
  szLogExt,
  szLogFile, szNewFile, szFullLogDir: UnicodeString;
begin
  n:=0;
  szLogFile:=AFileName;
  if szNewFile='' then
    szNewFile:='Log.txt';
  szLogFile:=WideChangeFileExt(szNewFile, '');
  szLogExt:=WideExtractFileExt(szNewFile);
  if szLogExt='' then
    szLogExt:='.txt';
  while WideIsFileLocked(WideExpandAppDirFileName(SLogFileDir, szNewFile, szFullLogDir)) do
  begin
    Inc(n);
    szNewFile:=WideFormat('%s(%d)%s', [szLogFile, n, szLogExt]);
  end;
  WSLogInit(PWideChar(szNewFile), bUseHDInfo, bClearLog, dwReserved);
end;

procedure WSLog(const pText: WideString); overload;
begin
  WSLog(PWideChar(pText));
end;

procedure WSLog(const pText: string); overload;
begin
  WSLog(PWideChar(WideString(pText)));
end;

end.
