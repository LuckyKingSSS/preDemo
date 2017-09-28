// VideoLibrary.h

#pragma once

#include "WSAudioInfo.h"
#include "WSVideoInfo.h"


typedef void* HVIDEOLIBRARY;

enum VL_SORT_TYPE
{
	VLST_FILENAME,			// ���ļ�������
	VLST_VIDEO_LENGTH,		// ����Ƶ�ļ����ȣ�ʱ�䣩����
};

// ����һ��VideoLibrary
HVIDEOLIBRARY __stdcall VLCreateVideoLibrary();

void __stdcall VLDestroyVideoLibrary(HVIDEOLIBRARY hVidLibrary);

// ��xml�ĵ�����ȡxml�ļ����ݶ�VideoLibrary���г�ʼ������ɺ󼴹رո�xml�ĵ���
int __stdcall VLLoadXml(HVIDEOLIBRARY hVidLibrary, const wchar_t* pXmlPath);

// ��VideoLibrary������ָ��xml�ĵ�����ͬ���ļ�ʱ����ԭ�ļ�����ͬ���ļ�ʱ�������ļ���
int __stdcall VLSaveXml(HVIDEOLIBRARY hVidLibrary, const wchar_t* pXmlPath);

// ȡVideoLibrary����Ƶ����������-1Ϊ����ʧ��
int __stdcall VLGetVideoCount(HVIDEOLIBRARY hVidLibrary);

// ��VideoLibraryָ��λ��nIndex����һ����ƵԪ�أ���nIndexΪ-1�������ĩβ������ֵΪ����ƵԪ���ڵ�λ��ID��ʧ�ܷ��� -1
int  __stdcall VLInsertVideoItem(HVIDEOLIBRARY hVidLibrary, const wchar_t* pFilePath, int nIndex);

// ��VideoLibrary���Ƴ�IDΪnIndex��VideoItem��nIndexΪ-1ʱ���Ƴ�����VideoItem
int __stdcall VLRemoveVideoItem(HVIDEOLIBRARY hVidLibrary, int nIndex);

// ��ID�Ŵ�nSrcIndex���nCount��VideoItem����nDstIndex�����ƶ�ǰIDΪ׼
int __stdcall VLMoveVideoItem(HVIDEOLIBRARY hVidLibrary, int nDstIndex, int nSrcIndex, int nCount);

// ��eSortTypeָ��key���ͽ�������bAscendΪTRUEʱΪ����FALSEΪ����
int __stdcall VLSort(HVIDEOLIBRARY hVidLibrary, enum VL_SORT_TYPE eSortType, int bAscend);


// ����IDΪnIndex����Ƶ�ļ���·����ȫ·����nFilePathLength��szFilePath������Ԫ����������������ռ�Ĵ�С
int __stdcall VLGetFilePath(HVIDEOLIBRARY hVidLibrary, int nIndex, wchar_t* szFilePath, int nFilePathLength);

int __stdcall VLGetVideoInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, WSVideoInfo* pInfo);
int __stdcall VLSetVideoInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, const WSVideoInfo* pInfo);

int __stdcall VLGetAudioInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, WSAudioInfo* pInfo);
int __stdcall VLSetAudioInfo(HVIDEOLIBRARY hVidLibrary, int nIndex, const WSAudioInfo* pInfo);

// szFileNameΪ����ͼ�ļ���������·����nFileNameLength��szFileName������Ԫ�ظ�������������ռ�Ĵ�С
int __stdcall VLGetThumbnailName(HVIDEOLIBRARY hVidLibrary, int nIndex, wchar_t* szFileName, int nFileNameLength);
int __stdcall VLSetThumbnailName(HVIDEOLIBRARY hVidLibrary, int nIndex, const wchar_t* szFileName);

int __stdcall VLGetVideoChangeTime(HVIDEOLIBRARY hVidLibrary, int nIndex, FILETIME* pFileTime);
int __stdcall VLSetVideoChangeTime(HVIDEOLIBRARY hVidLibrary, int nIndex, FILETIME* pFileTime);
