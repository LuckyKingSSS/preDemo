///////////////////////////////////////////////////////////////////////////
// ConfigFile.h
//==========================================================================
// ����    �� ���˴�������д�����ļ�
// ģ��	   �� PSB��ĿWSLibrary.dllģ�� 
// ����ʱ�䣺 2005-08-10 
// ������  �� ����
// �޶�    �� 
//==========================================================================

//ע��:
// 1.���������ļ��ཨ��ʱ����ļ����к˶�,���ڸ��ļ��ʹ�,�������򴴽�;
//   ���ļ�ʱҲ������,���Զ�ʱ���Ҫע��򿪵��ļ����Ƿ���ȷ,����һ������;
// 2.�ͷ�ʱ���Զ�����,��ҿ��Է���ʹ���ͷŹ���.
// 3.���ע��д�ļ�ʱ�д�Сд֮��Ŷ!

#pragma once

#ifdef WIN32

#ifdef WSCONFIG_EXPORTS
#define WSCONFIG_API __declspec(dllexport)
#else
#define WSCONFIG_API __declspec(dllimport)
#endif

#else

#define WSCONFIG_API

#endif

#include <string>
using namespace std;


//class ConfigFileImpl;
class XMLConfig;
class WSCONFIG_API ConfigFile
{
public:
	ConfigFile(const wchar_t*, const wchar_t* pRootNode = L"config_root");//���캯��
	virtual ~ConfigFile();//��������


	void SetConfigStr(const wchar_t* , const wchar_t*);//д����,string����
	void SetConfigInt(const wchar_t* , int);//д����,int����
	void SetConfigDbl(const wchar_t* , double);//д����,double����

	void SetAttribute(const wchar_t* , const wchar_t* lpAttribName, const wchar_t* lpAttribValue);

	int GetConfigStr(const wchar_t*, wstring&);//��������Ϣ,string����
	const wchar_t* GetConfigStrPtr(const wchar_t*);//��������Ϣ,string����
	int GetConfigInt(const wchar_t*, int*);//��������Ϣ,int����
	int GetConfigDbl(const wchar_t*, double*);//��������Ϣ,double����

	const wchar_t* GetAttribute(const wchar_t*, const wchar_t* lpAttribName);

	int Flush();//����

private:
	//ConfigFileImpl* m_pzImpl;

	XMLConfig*	m_pzImpl;
	wchar_t *			m_pszFileName; //���������ļ�·��
	
};
