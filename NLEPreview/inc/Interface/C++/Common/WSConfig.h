///////////////////////////////////////////////////////////////////////////
// Config.h
//==========================================================================
// ����    �� ��������д�����ļ�
// ģ��	   �� PSB��ĿWSLibrary.dllģ�� 
// ����ʱ�䣺 2005-08-10 
// ������  �� ����
// �޶�    �� 
//==========================================================================

///////////////////////////////////////////////////////////////////////////
//ע��:
// 1.ȫ�������ļ���һ��Ҫ�ȳ�ʼ��,��ʹ��,���Ҫ�ǵ��ͷ�;
//   Ŀǰֻ�ܳ�ʼ��һ��
// 2.�ͷ�ʱ���Զ�����,��ҿ��Է���ʹ���ͷŹ���;
// 3.���ע��д�ļ�ʱ�д�Сд֮��Ŷ!


#pragma once

#include <string>
using namespace std;

#ifdef WIN32
#ifdef __cplusplus
extern "C"
{
#endif
#endif

// ��ʼ��ȫ�����ã�Ӧ�ó����ʼ��ʱ����
// pFileName - ȫ�������ļ�����������·�� Ĭ��Ϊ"Config.xml" ȫ�����þ�д�뵽{app}Ŀ¼
int __stdcall InitGlobalConfig(const wchar_t* pFileName = L"Config.xml", const wchar_t* pRootNode = L"config_root", const wchar_t* pVersion = L"1.0", DWORD dwResered = 0);		
void __stdcall ShutdownGlobalConfig();	// �ر�ȫ�����ã�Ӧ�ó����˳�ʱ���� �Զ�Flush


void __stdcall WSSetConfigStr(const wchar_t*, const wchar_t*);//��������, ����Ϊ�ַ���

void __stdcall WSSetConfigInt(const wchar_t*, int);//�������ã� ����Ϊ����

void __stdcall WSSetConfigDbl(const wchar_t*, double);//�������ã� ����Ϊ������

void __stdcall WSSetAttribute(const wchar_t* , const wchar_t* lpAttribName, const wchar_t* lpAttribValue);

int __stdcall WSConfigFlush();//д�����ļ�


int __stdcall WSGetConfigStr(const wchar_t*, wstring&);//�������ļ��� ����Ϊ�ַ���

const wchar_t* __stdcall WSGetConfigStrPtr(const wchar_t*);//�������ļ��� ����Ϊ�ַ��� ������ò������򷵻�0

int __stdcall WSGetConfigStrEx(const wchar_t*, const wchar_t*, int);//�������ļ��� ����Ϊ�ַ���

int __stdcall WSGetConfigInt(const wchar_t*, int*);//�������ļ��� ����Ϊ����

int __stdcall WSGetConfigDbl(const wchar_t*, double*);//�������ļ��� ����Ϊ������

const wchar_t* __stdcall WSGetConfigAttribute(const wchar_t*, const wchar_t* lpAttribName);

// ���º�������ʹ�� ConfigFile�����
typedef void* HCONFIGFILE;
HCONFIGFILE __stdcall ConfigFileInit(const wchar_t* pPathName, const wchar_t* pRootNode = L"config_root", const wchar_t* pVersion = L"1.0", DWORD dwResered = 0);//������������ļ���pFileNameΪ��������ļ�·���� �����Զ�Flush

void __stdcall ConfigFileDestroy(HCONFIGFILE hconfig);//�ر�Config�ļ�


void __stdcall ConfigSetStr(HCONFIGFILE hconfig, const wchar_t*, const wchar_t*);//�������ã� ����Ϊ�ַ���

void __stdcall ConfigSetInt(HCONFIGFILE hconfig, const wchar_t*, int);//�������ã�����Ϊ����

void __stdcall ConfigSetDbl(HCONFIGFILE hconfig, const wchar_t*, double);//�������ã�  ����Ϊ������

void __stdcall ConfigSetAttribute(HCONFIGFILE hconfig, const wchar_t* , const wchar_t* lpAttribName, const wchar_t* lpAttribValue);

int __stdcall ConfigFlush(HCONFIGFILE hconfig);//д�����ļ�


int __stdcall ConfigGetStr(HCONFIGFILE hconfig, const wchar_t*, wstring&);//�������ļ��� ����Ϊ�ַ���

int __stdcall ConfigGetStrEx(HCONFIGFILE hconfig, const wchar_t*, wchar_t*, int);//�������ļ��� ����Ϊ�ַ���,Delphiʹ��

const wchar_t* __stdcall ConfigGetStrPtr(HCONFIGFILE hconfig, const wchar_t*);//�������ļ��� ����Ϊ�ַ��� ������ò������򷵻�0

int __stdcall ConfigGetInt(HCONFIGFILE hconfig, const wchar_t*, int*);//�������ļ��� ����Ϊ����

int __stdcall ConfigGetDbl(HCONFIGFILE hconfig, const wchar_t*, double*);//�������ļ���  ����Ϊ������
	
const wchar_t* __stdcall ConfigGetAttribute(HCONFIGFILE hconfig, const wchar_t*, const wchar_t* lpAttribName);


// �����ĳ���һ���ԭ�Ķ�ռ��1/3�Ĵ洢�ռ䣬�뱣֤base64code���㹻�Ŀռ�
int __stdcall WSBase64Encode(char * base64code, const unsigned char * src, int src_len); 
int __stdcall WSBase64Decode(unsigned char * buf, const char * base64code, int src_len = -1);


#ifdef WIN32
#ifdef __cplusplus
}
#endif
#endif
