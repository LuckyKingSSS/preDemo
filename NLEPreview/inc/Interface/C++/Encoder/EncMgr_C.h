// ���ܣ� ʵ��ý���ļ��Ĵ���������

#pragma once

#include "EncodeParam.h"
#include "WSAudioInfo.h"
#include "WSVideoInfo.h"
#include "CodecFrame.h"
//#include "EncMgr.h"
#ifdef __cplusplus
extern "C" {
#endif


#ifdef USE_MUTEX_LOCK
	#define _USE_SINGLE_LOCK	// ʹ���߳���
#endif

typedef void* HMEDIAFILE; // ý���ļ��������

int __stdcall FCInitPlugins();		// Ӧ�ó�������ʱ����
void __stdcall FCUninitPlugins();	// Ӧ�ó����˳�ʱ����
FileFormatInfo*  __stdcall FCGetFileFormatInfos(); // ��ȡ�Ѽ���֧�ֵ������ļ���ʽ������FCInitPlugins()���óɹ���ſɵ���
//IFileFormatInfos*  __stdcall FCGetFileFormatInfosImp();

// ����ý���ļ� ĿǰpVidInfo->dwFourCC = '21VY' pVidInfo->nBitsDepth = 12���������� 
HMEDIAFILE __stdcall FCCreateMediaFile(const wchar_t* pFileName, const EncodeParam* pEncParam, 
				  const WSVideoInfo* pVidInfo, const WSAudioInfo* pAudInfo,const EncodeParamEx* pEncParamEx=NULL);


// �ر�ý���ļ�
void __stdcall FCCloseMediaFile(HMEDIAFILE hFileEnc, ENCODE_CALLBACK pCallBack = 0, void* pUserObj = 0);

// д����Ƶ���ݣ���ѹ��PCM���ݣ�
int __stdcall FCWriteAudioData(HMEDIAFILE hFileEnc, const MEDIA_FRAME* pFrame);

// д��һ֡ͼ������ Ŀǰֻ֧��YV12ͼ��
int __stdcall FCWriteVideoFrame(HMEDIAFILE hFileEnc, const MEDIA_FRAME* pFrame);

// ֪ͨ���α���ĵ�һ�����ݴ������
int __stdcall FCEncodeFirstEnd(HMEDIAFILE hFileEnc,EncodeParam* pEncParam);

//������չ�������
//int __stdcall FCSetEncParamEx(HMEDIAFILE hFileEnc,EncodeParamEx* pEncParamEx);

int __stdcall FCGetEncodeParam(HMEDIAFILE hFileEnc,EncodeParam* pEncParam) ;

#ifdef __cplusplus
}
#endif

