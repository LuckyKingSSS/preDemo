///////////////////////////////////////////////////////////////////////////
// Md5.h
//==========================================================================
// ����    �� Md5
// ģ��	   �� PSB��ĿWS_Log.dllģ�� 
// ����ʱ�䣺 2006-08-23
// ������  �� 
// �޶�    �� 
//==========================================================================

#pragma once

int __stdcall GetDataMD5(const BYTE* pBuf, UINT nLength, char szBuf[64]);
int __stdcall GetFileMD5(const char* pFileName, char szBuf[64]);
const char* __stdcall GetFileMD5Ex(const char* pFileName);

// ����У��ͼ��
// ���سɹ���ʾ�Ѿ��������
// ��ȷ��pFileNameָ��һֱ��Ч
int __stdcall StartCheckSum(const wchar_t* pFileName); 

int __stdcall StartCheckMD5(const wchar_t* pFileName, const char* pMD5); 

