///////////////////////////////////////////////////////////////////////////
// Log.h
//==========================================================================
// ����    �� ������д��־
// ģ��	   �� PSB��ĿWSLibrary.dllģ�� 
// ����ʱ�䣺 2005-08-01 
// ������  �� ����
// �޶�    �� 
//==========================================================================

#pragma once


#ifdef __cplusplus
extern "C"
{
#endif


void __stdcall SetAppPath(const wchar_t* pAppPath); //  ����Ӧ�ó���·�� ���һ���ַ���б��

void __stdcall GetAppPath(wchar_t* pAppPath, int len); 

void __stdcall SetAppResourcePath(const wchar_t* pAppResourcePath,int len);//  ����Ӧ�ó�����Դ���·������XML.ͼƬ��
void __stdcall GetAppResourcePath(wchar_t* pAppResourcePath,int len);

void __stdcall SetFontCachePath(const wchar_t* pFontCachePath); // �������建��·��

void __stdcall GetFontCachePath(wchar_t* pFontCachePath, int len);

void __stdcall  SetDocumentPath(const wchar_t* path);

void __stdcall  GetDocumentPath(wchar_t* path, int len);

void __stdcall SetAppTmpPath(const wchar_t* pAppTempPath,int len); //  ����Ӧ�ó�����ʱ·�� ���һ���ַ���б�� ��󳤶�1024 mac��
void __stdcall GetAppTmpPath(wchar_t* pAppTempPath); 
void __stdcall SetWinAtiVideoCardType(int ntype);
int __stdcall GetWinAtiVideoCardType(void);
void __stdcall SetVideoCardType(int ntype); //
void __stdcall GetVideoCardType(int* nType); 

// ������־�ļ�����������·�� Ĭ��Ϊ"log.txt" ȫ����־��д�뵽{app}\logĿ¼
// bUseHDInfo - �Ƿ����Ӳ����Ϣ
// bClearLog - �Ƿ���վ���Ϣ
// WSLogInit�Ǳ�����õ�
void __stdcall WSLogInit(const wchar_t* pFileName = 0, int bUseHDInfo = TRUE, int bClearLog = FALSE, DWORD dwReserved = 0);

#ifndef WIN32
void __stdcall WSLogInitEx(const wchar_t* pFilePath,const wchar_t* pFileName, int bUseHDInfo, int bClearLog, DWORD dwReserved);
#endif
	
void __stdcall WSLogUninit();

void __stdcall WSLog(const wchar_t* pText);//�����д��־����(C++��Delphi)

void __cdecl WSLogEx(const wchar_t* lpszFormat, ...);//�����д�ɱ��������־����(��C++����)

void __stdcall WSOutput(const wchar_t* lpszFormat); // ���������Ϣ ʹ��XTraceMonitor.exe�鿴

void __stdcall WSOutputEx(COLORREF crText, const wchar_t* lpszFormat); // ���������Ϣ crTextΪ�ı���ɫ

void __stdcall WSOutputImg(LPBITMAPINFO lpbi, LPVOID lpBits); //���ͼ��


// ���º�������ʹ�� LogFile�����
typedef void* HLOGFILE;
//����Log�ļ� pPathName��־�ļ�·���� bUseHDInfoΪ�Ƿ���Ҫ����Ӳ����Ϣ bClearLog�Ƿ�Ҫ���ԭ����Log�ļ� dwReserveΪ������
HLOGFILE __stdcall LogFileCreate(const wchar_t* pPathName, int bUseHDInfo, int bClearLog, DWORD dwReserve);

void __stdcall LogFileDestroy(HLOGFILE hLog);//����Log�ļ�

void __stdcall LogFileLog(HLOGFILE hLog, const wchar_t* pText);//д��־�ļ�

const wchar_t* __stdcall ReadLogFileBuffer(const wchar_t* pFileName); //��ȡ�ļ��������ַ���ָ�� 

void __stdcall ReleaseLogFileBuffer(const wchar_t* pLogBuffer);//�ͷ��������ַ���ָ��

#ifdef WIN32
LONG __stdcall SEHExceptionFilter(LPEXCEPTION_POINTERS lpEr);
#endif

void __stdcall CreateReportWithoutCrash();

typedef LONG  (__stdcall *MULTI_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);

void __stdcall SetErrorCallBack(MULTI_CALLBACK fnCallback);

void __stdcall WS_Log_Error_CallBackToUser();

#define TRY_BEGIN  try{         


#define TRY_END(return_value)   }		\
	catch(...)                          \
{                               \
	CreateReportWithoutCrash();	\
	WS_Log_Error_CallBackToUser();\
	return return_value;        \
}                              \

#ifdef __cplusplus
}
#endif



#ifdef NO_LOG

#define WSLOG
#define WSLOGEX

#else

#define WSLOG WSLog
#define WSLOGEX WSLogEx

#endif






