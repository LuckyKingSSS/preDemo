unit
	Config;
    // �ṩ���ü�¼ ����

//ע��:
// 1.ȫ�������ļ���һ��Ҫ�Ƚ���,��ʹ��,���Ҫ�ǵ��ͷ�;
//   Ŀǰֻ�ܳ�ʼ��һ�Σ�
// 2.���������ļ��ཨ��ʱ����ļ����к˶�,���ڸ��ļ��ʹ�,�������򴴽�;
//   ���ļ�ʱҲ������,���Զ�ʱ���Ҫע��򿪵��ļ����Ƿ���ȷ,����һ������;
// 3.�ͷ�ʱ���Զ�����,��ҿ��Է���ʹ���ͷŹ���.
// 4.���ע��д�ļ�ʱ�д�Сд֮��Ŷ!
    
interface

uses
    Windows;
type
   HCONFIGFILE = pointer;

// ��ʼ��ȫ�����ã�Ӧ�ó����ʼ��ʱ����
// pFileName - ȫ�������ļ�����������·�� Ĭ��Ϊ"Config.xml" ȫ�����þ�д�뵽{app}Ŀ¼
//BOOL __stdcall InitGlobalConfig(const wchar_t* pFileName = L"Config.xml", const wchar_t* pRootNode = L"config_root", const wchar_t* pVersion = L"1.0", DWORD dwResered = 0);
function InitGlobalConfig(pFileName : PWideChar = nil; pRootNode: PWideChar = nil; pVersion: PWideChar = nil; dwReserved : DWORD = 0) : BOOL; stdcall;

//void __stdcall ShutdownGlobalConfig();	// �ر�ȫ�����ã�Ӧ�ó����˳�ʱ�����Զ�Flush
procedure ShutdownGlobalConfig(); stdcall;

//void __stdcall WSSetConfigStr(const wchar_t*, const wchar_t*);//�������� �����ַ���
procedure WSSetConfigStr(const pNodeName : PWideChar; const pContent : PWideChar); stdcall;

//void __stdcall WSSetConfigInt(const wchar_t*, int);//��������  ������������ֵ
procedure WSSetConfigInt(const pNodeName : PWideChar; nValue : Integer); stdcall;

//void __stdcall WSSetConfigDbl(const wchar_t*, double);//��������  ���븡������ֵ
procedure WSSetConfigDbl(const pNodeName : PWideChar; dValue : Double); stdcall;

//void __stdcall WSSetAttribute(const wchar_t* , const wchar_t* lpAttribName, const wchar_t* lpAttribValue);
procedure WSSetConfigAttribute(const pNodeName : PWideChar; const lpAttribName : PWideChar; const lpAttribValue : PWideChar); stdcall;

//BOOL __stdcall WSConfigFlush();//д�����ļ�
function WSConfigFlush() : BOOL; stdcall;

//BOOL __stdcall WSGetConfigStrEx(const wchar_t*, const wchar_t*, int);//�������ļ�������Ϊ�ַ��� ,Delphiʹ��
function WSGetConfigStrEx(const pNodeName : PWideChar; pstrValue : PWideChar; nBufLen : Integer) : BOOL; stdcall;

//const wchar_t* __stdcall WSGetConfigStrPtr(const wchar_t*);//�������ļ��� ����Ϊ�ַ���  ������ò������򷵻�0
function WSGetConfigStrPtr(const pNodeName : PWideChar) : PWideChar; stdcall;


//BOOL __stdcall WSGetConfigInt(const wchar_t*, int&);//�������ļ�  ��������ֵ
function WSGetConfigInt(const pNdeName : PWideChar; pnValue : PInteger) : BOOL; stdcall;

//BOOL __stdcall WSGetConfigDbl(const wchar_t*, double&);//�������ļ�  ��������ֵ
function WSGetConfigDbl(const pNodeName : PWideChar; pdValue : PDouble) : BOOL; stdcall;

//const wchar_t* WSGetConfigAttribute(const wchar_t*, const wchar_t* lpAttribName);
function WSGetConfigAttribute(const pNodeName : PWideChar; const lpAttribName : PWideChar) : PWideChar; stdcall;


//������������ļ���pFileNameΪ��������ļ�·���� �����Զ�Flush
//HCONFIGFILE __stdcall ConfigFileInit(const wchar_t* pPathName, const wchar_t* pRootNode = L"config_root", const wchar_t* pVersion = L"1.0", DWORD dwResered = 0);
function ConfigFileInit(const pFileName : PWideChar; pRootNode: PWideChar = nil; pVersion: PWideChar = nil; dwReserved : DWORD = 0) : HCONFIGFILE; stdcall;

//void __stdcall ConfigFileDestroy(HCONFIGFILE hconfig);//�ر�Config�ļ� �����Զ�Flush
procedure ConfigFileDestroy(hconfig : HCONFIGFILE); stdcall;

//void __stdcall ConfigSetStr(HCONFIGFILE hconfig, const wchar_t*, const wchar_t*);//�������ã� ����Ϊ�ַ���
procedure ConfigSetStr(hconfig : HCONFIGFILE; const pNodeName : PWideChar; const pValue : PWideChar); stdcall;

//const wchar_t* __stdcall ConfigGetStrPtr(HCONFIGFILE hconfig, const wchar_t*);//�������ļ��� ����Ϊ�ַ���  ������ò������򷵻�0
function ConfigGetStrPtr(hconfig : HCONFIGFILE; const pNodeName : PWideChar) : PWideChar; stdcall;


//void __stdcall ConfigSetInt(HCONFIGFILE hconfig, const wchar_t*, int);//�������ã�����Ϊ����
procedure ConfigSetInt(hconfig : HCONFIGFILE; const pNodeName : PWideChar; nValue : Integer); stdcall;

//void __stdcall ConfigSetDbl(HCONFIGFILE hconfig, const wchar_t*, double);//�������ã�  ����Ϊ������
procedure ConfigSetDbl(hconfig : HCONFIGFILE; const pNodeName : PWideChar; dValue : Double); stdcall;

//void __stdcall ConfigSetAttribute(HCONFIGFILE hconfig, const wchar_t* , const wchar_t* lpAttribName, const wchar_t* lpAttribValue);
procedure ConfigSetAttribute(hconfig : HCONFIGFILE; const pNodeName : PWideChar; const lpAttribName : PWideChar; const lpAttribValue : PWideChar); stdcall;

//BOOL __stdcall ConfigFlush(HCONFIGFILE hconfig);//д�����ļ�
function ConfigFlush(hconfig : HCONFIGFILE) : BOOL; stdcall;

//BOOL __stdcall ConfigGetStrEx(HCONFIGFILE hconfig, const wchar_t*, const wchar_t*, int)��//�������ļ��� ����Ϊ�ַ���,Delphiʹ��
function ConfigGetStrEx(hconfig : HCONFIGFILE; const pNodeName : PWideChar; const pValue : PWideChar; nBufLen : Integer) : BOOL; stdcall;

//BOOL __stdcall ConfigGetInt(HCONFIGFILE hconfig, const wchar_t*, int*);//�������ļ��� ����Ϊ����
function ConfigGetInt(hconfig : HCONFIGFILE; const pNodeName : PWideChar; pnValue : PInteger) : BOOL; stdcall;

//BOOL __stdcall ConfigGetDbl(HCONFIGFILE hconfig, const wchar_t*, double*);//�������ļ���  ����Ϊ������
function ConfigGetDbl(hconfig : HCONFIGFILE; const pNodeName : PWideChar; pdValue : PDouble) : BOOL; stdcall;

//const wchar_t* ConfigGetAttribute(HCONFIGFILE hconfig, const wchar_t*, const wchar_t* lpAttribName);
function ConfigGetAttribute(hconfig : HCONFIGFILE; const pNodeName : PWideChar; const lpAttribName : PWideChar) : PWideChar; stdcall;


// Base64 �����
// �����ĳ���һ���ԭ�Ķ�ռ��1/3�Ĵ洢�ռ䣬�뱣֤base64code���㹻�Ŀռ�
//int __stdcall WSBase64Encode(char * base64code, const unsigned char * src, int src_len); 
function WSBase64Encode(base64code : PChar; const src : Pointer; src_len : Integer) : Integer; stdcall;

//int __stdcall WSBase64Decode(unsigned char * buf, const char * base64code, int src_len = -1);
function WSBase64Decode(buf : Pointer; const base64code : PChar; src_len : Integer = -1) : Integer; stdcall;



implementation

const
    DLLNAME = 'WS_Log.dll';

function  InitGlobalConfig	    ; external DLLNAME Name 'InitGlobalConfig';
procedure ShutdownGlobalConfig	; external DLLNAME Name 'ShutdownGlobalConfig';
procedure WSSetConfigStr        ; external DLLNAME Name 'WSSetConfigStr';
procedure WSSetConfigInt	      ; external DLLNAME Name 'WSSetConfigInt';
procedure WSSetConfigDbl	      ; external DLLNAME Name 'WSSetConfigDbl';
function  WSConfigFlush		      ; external DLLNAME Name 'WSConfigFlush';
function  WSGetConfigStrEx		  ; external DLLNAME Name 'WSGetConfigStrEx';
function  WSGetConfigInt		    ; external DLLNAME Name 'WSGetConfigInt';
function  WSGetConfigDbl		    ; external DLLNAME Name 'WSGetConfigDbl';
function  WSGetConfigStrPtr     ; external DLLNAME Name 'WSGetConfigStrPtr';
function  ConfigFileInit		    ; external DLLNAME Name 'ConfigFileInit';
procedure ConfigFileDestroy		  ; external DLLNAME Name 'ConfigFileDestroy';
procedure ConfigSetStr	        ; external DLLNAME Name 'ConfigSetStr';
procedure ConfigSetInt	        ; external DLLNAME Name 'ConfigSetInt';
procedure ConfigSetDbl	        ; external DLLNAME Name 'ConfigSetDbl';
function  ConfigGetStrEx		    ; external DLLNAME Name 'ConfigGetStrEx';
function  ConfigGetInt		      ; external DLLNAME Name 'ConfigGetInt';
function  ConfigGetDbl		      ; external DLLNAME Name 'ConfigGetDbl';
function  ConfigFlush           ; external DLLNAME Name 'ConfigFlush';
function  ConfigGetStrPtr       ; external DLLNAME Name 'ConfigGetStrPtr';

function  WSBase64Encode		    ; external DLLNAME Name 'WSBase64Encode';
function  WSBase64Decode        ; external DLLNAME Name 'WSBase64Decode';

function  WSGetConfigAttribute     ; external DLLNAME Name 'WSGetConfigAttribute';
function  ConfigGetAttribute       ; external DLLNAME Name 'ConfigGetAttribute';
procedure  WSSetConfigAttribute     ; external DLLNAME Name 'WSSetConfigAttribute';
procedure  ConfigSetAttribute       ; external DLLNAME Name 'ConfigSetAttribute';

end.