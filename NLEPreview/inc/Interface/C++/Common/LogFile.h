///////////////////////////////////////////////////////////////////////////
// LogFile.h
//==========================================================================
// ����    �� ���˴�����д��־�ļ�
// ģ��	   �� PSB��ĿWSLibrary.dllģ�� 
// ����ʱ�䣺 2005-08-01 
// ������  �� ����
// �޶�    �� 
//==========================================================================


#ifndef _LOGFILE_H
#define _LOGFILE_H


#ifdef WIN32

#ifdef LOG_EXPORTS
	#define LOG_API __declspec(dllexport)
#else
	#define LOG_API __declspec(dllimport)
#endif

#else

#define LOG_API

#endif

class LogFileImpl;
class LOG_API LogFile
{
public:
	//�趨��־�ļ���szFileName ���Ƿ�Ҫ���ԭ����Log�ļ�bClearLog���Ƿ���Ҫ����Ӳ����ϢbUseHDInfo �ͱ�����dwReserve��
	LogFile(const wchar_t *szFileName = 0, int bUseHDInfo = TRUE, int bClearLog = FALSE, DWORD dwReserve = 0);
	virtual ~LogFile();//��������

	int Open(const wchar_t *szFileName = 0, int bUseHDInfo = TRUE, int bClearLog = FALSE, DWORD dwReserve = 0); //�趨��־�ļ���
	int IsOpen() const; // �Ƿ�ɹ������ļ�

	void Log(const wchar_t *szText);//����д��־,֧�ֶ��߳�

	void Close();

private:

	LogFileImpl*	m_pImpl;

};


#endif
