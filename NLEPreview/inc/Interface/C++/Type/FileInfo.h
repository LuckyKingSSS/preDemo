// FileInfo.h 

/*! \file FileInfo.h
* \brief	�ļ���Ϣ
*/
#pragma once

#include "MetaDataInfo.h"
#include "WSVideoInfo.h"
#include "WSAudioInfo.h"


#ifndef STREAM_TYPE_DEF
#define STREAM_TYPE_DEF

/*!
* \enum AV_STREAM_TYPE
* \brief �������� 
*/
// Stream���Ͷ���
enum AV_STREAM_TYPE
{
	/*!��ý����*/
	ST_NONE,
	
	/*! DVD��������*/
	ST_NAV,			 
	
	/*! ��ƵStream*/
	ST_VIDEO,		// 
	
	/*! ��ƵStream*/
	ST_AUDIO,	
	
	/*! ��ĻStream*/
	ST_SUBPIC,
	
	/*! ͼ��Stream*/
	ST_IMAGE,
};

enum AV_SCAN_TYPE
{
	AV_SCAN_TYPE_PROGRESSIVE, ///< ����ģʽ
	AV_SCAN_TYPE_INTERLACED, ///< ��֯ģʽ
	AV_SCAN_TYPE_UNKNOWN,	///< ģʽδ֪
	AV_SCAN_TYPE_RESERVED	///< �����ֶ�

};
#endif

/*!
* \struct StreamInfo
* \brief ������Ϣ
* \see WSVideoInfo WSAudioInfo AV_STREAM_TYPE
*/
struct StreamInfo
{
	/*! ������*/
	AV_STREAM_TYPE	uStreamType;

	/*! ��ID*/
	UINT			uStreamID;

	/*! ��FourCC*/
	DWORD			dwFourCC;

	/*! 0 - ����  -1 �Ҳ���dwFourCC��Ӧ�Ľ�����*/
	int				nState;	

	/*! ������*/
	wchar_t			szName[64];

	/*! ����������Ϣ*/
	wchar_t			szDescription[128];

	/*! ����ʱ�䳤��*/
	double			dStreamLength;

	/*! ��������*/
	int				nBitrate;

	/*! ������Ƶ��Ϣ�� ��uStreamTypeΪST_VIDEOʱ��Ч*/
	WSVideoInfo 	vidInfo;


	/*! ������Ƶԭʼ��Ϣ�� ��uStreamTypeΪST_VIDEOʱ��Ч*/
	WSVideoInfo 	vidInfoSrc;

	/*! ������Ƶ��Ϣ�� ��uStreamTypeΪST_AUDIOʱ��Ч*/
	WSAudioInfo 	audInfo;	

	/*! ��ǰ���ĵ�һ��ʱ���*/
	__int64			ptsStart;	

	/*! ��ǰ���ĵ�һ��ʱ����͸�·��Ŀ��������ptsStart��С���Ǹ�ptsStart�Ĳ�ֵ*/
	__int64			ptsOffset;	

	/*! ��ǰ���ĸ��л�����ɨ�� */
	AV_SCAN_TYPE	scanType;

	/*! ��ǰ����ԭʼ���л�����ɨ�� */
	AV_SCAN_TYPE	scanTypeSrc;

	/*! �����ֶ� ��ʱ���� mov sprite ��roate */
	DWORD			dwReserved1;

	/*! �����ֶ�*/
	DWORD			dwReserved2;
	
};

/*!
* \enum SUPPIC_TYPE
* \brief  ��Ļ�����ͣ���Ƕ�������
*/
enum SUPPIC_TYPE
{
	/*! ��Ƕ��Ļ*/
	SPT_Internal,
	
	/*! ������Ļ*/
	SPT_External,
};

/*!
* \struct SubPicStreamInfo
* \brief  ��Ļ����Ϣ
* \see SUPPIC_TYPE
*/
struct SubPicStreamInfo
{
	/*! ��Ļ������*/
	SUPPIC_TYPE		uSPType;

	/*! ��Ļ����ID*/
	UINT			uStreamID;

	/*! ��Ļ���� FourCC*/
	DWORD			dwFourCC;

	/*! ��Ļ��������*/
	wchar_t			szLang[64];

	/*! ��Ļ��������*/
	wchar_t			szDescription[128];
};


/*!
* \struct ProgramInfo
* \brief  ��Ŀ��Ϣ
* \see StreamInfo SubPicStreamInfo
*/
struct ProgramInfo
{
	/*! ��Ļ��Numer ��������*/
	DWORD				dwNumber;

	/*! ��Ŀ��ID*/
	UINT				uPID;

	/*! ��Ŀ��ʱ��*/
	double				dMediaLength;

	/*! ��Ŀ��������*/
	int					nBitrate;

	/*! ��Ŀ������Ƶ������Ŀ*/
	int					nVideoStreamCount;

	/*! ��Ŀ������Ƶ������Ŀ*/
	int					nAudioStreamCount;

	/*! ��Ŀ������Ƶ��Ϣ*/
	StreamInfo*			pVidStreamInfos;

	/*! ��Ŀ������Ƶ��Ϣ*/
	StreamInfo*			pAudStreamInfos;

	/*! ʱ����ο���Ƶ��ID*/
	UINT				uTimeStampReferenceStreamID;

	/*! ��Ŀ������Ļ������Ŀ*/
	int					nSubPicStreamCount;

	/*! ��Ŀ������Ļ����Ϣ*/
	SubPicStreamInfo*	pSubPicInfos;
};

struct MEDIA_FILE_INFO;
typedef void (__stdcall* MEDIA_INFO_RELEASE_API)(MEDIA_FILE_INFO* pMediaFileInfo);

/*!
* \struct 	MEDIA_FILE_INFO
* \brief ý���ļ���Ϣ
*  һ��ý���ļ��д���1·���·��Ŀ��һ����Ŀ�д���1·���·��Ҳ���ܲ��棩����Ƶ����Ļ��
* \see MetaDataInfo ProgramInfo
*/
struct MEDIA_FILE_INFO
{
	/*! ý���ļ�FourCC*/
	DWORD			dwFourCC;

	/*! �ļ���*/
	wchar_t			szName[512];

	/*! �ļ���������Ϣ*/
	wchar_t			szDescription[128];

	/*! MetaData ��Ϣ��(ID3��Ϣ)*/
    MetaDataInfo    metaDataInfo;

	/*! ý���ļ�ʱ�䳤��(ȡ������Ŀ���У������·)*/
	double			dMediaLength;

	/*! ý���ļ������ʣ�(��·��Ŀ������֮��)*/
	int				nBitrate;

	/*! ý���ļ��Ľ�Ŀ��*/
	int				nProgramCount;
	/*! ý���ļ��Ľ�Ŀ��Ϣ*/
	ProgramInfo*	pProgramInfos;

	/*! ���л�����ɨ�� */
	AV_SCAN_TYPE	scanType;

	/*! �ͷ�MediaInfo�����ڴ�ĺ���ָ��*/
	MEDIA_INFO_RELEASE_API	fnRelease;
};


// MediaInfo.dll
MEDIA_FILE_INFO* __stdcall MFICreate();
ProgramInfo* __stdcall MFIAddProgram(MEDIA_FILE_INFO* pMediaFileInfo, DWORD dwNumber, UINT uPID);
StreamInfo* __stdcall MFIAddStream(ProgramInfo*, AV_STREAM_TYPE uStreamType, UINT uStreamID, DWORD dwFourCC);
SubPicStreamInfo* __stdcall MFIAddSubPicStream(ProgramInfo*, SUPPIC_TYPE uStreamType, UINT uStreamID, DWORD dwFourCC);
int __stdcall MFIEraseStream(ProgramInfo* pProgram, AV_STREAM_TYPE uStreamType, UINT uStreamID);
void __stdcall MFIRelease(MEDIA_FILE_INFO* pMediaFileInfo);

MEDIA_FILE_INFO* __stdcall MFIClone(const MEDIA_FILE_INFO *pMediaInfoSrc);


#ifdef __cplusplus

/*!
* \fn __inline ProgramInfo* FindProgram(MEDIA_FILE_INFO* pMediaInfo, UINT uProgramID)
* \brief ��MEDIA_FILE_INFO�У��ҵ�ָ����Ŀ��ID�ģ���Ŀ����Ϣָ�롣
* \param pMediaInfo [in] ý���ļ���Ϣ
* \param uProgramID [in] ��Ŀ��ID
* \retval ��Ŀ��ָ��
* \see  MEDIA_FILE_INFO ProgramInfo
* \note ���û���ҵ�����ô���ص�һ·��Ŀ��
*/
__inline ProgramInfo* FindProgram(MEDIA_FILE_INFO* pMediaInfo, UINT uProgramID)
{
	// ����Ҳ�����ȡ��һ��Program
	ProgramInfo* pProgram = pMediaInfo->pProgramInfos;

	for (int i = 0; i < pMediaInfo->nProgramCount; ++i)
	{
		if (pMediaInfo->pProgramInfos[i].uPID == uProgramID)
		{
			pProgram = &pMediaInfo->pProgramInfos[i];
			break;
		}
	}

	return pProgram;
}


/*!
* \fn __inline StreamInfo* FindVideoStream(ProgramInfo* pProgram, UINT uStreamID)
* \brief ��ProgramInfo�У��ҵ�ָ����Ƶ��ID�ģ���Ƶ����Ϣָ�롣
* \param pProgram [in] ��Ŀ����Ϣ
* \param uStreamID [in] ��Ƶ��ID
* \retval ��Ƶ��ָ��
* \see  ProgramInfo StreamInfo
* \note ���û���ҵ�����ô���ص�һ·��Ƶ��
*/
__inline StreamInfo* FindVideoStream(ProgramInfo* pProgram, UINT uStreamID)
{
	// ����Ҳ�����ȡ��һ��Program
	StreamInfo* pStream = pProgram->pVidStreamInfos;

	for (int i = 0; i < pProgram->nVideoStreamCount; ++i)
	{
		if (pProgram->pVidStreamInfos[i].uStreamID == uStreamID)
		{
			pStream = &pProgram->pVidStreamInfos[i];
			break;
		}
	}

	return pStream;
}

/*!
* \fn __inline StreamInfo* FindAudioStream(ProgramInfo* pProgram, UINT uStreamID)
* \brief ��ProgramInfo�У��ҵ�ָ����Ƶ��ID�ģ���Ƶ����Ϣָ�롣
* \param pProgram [in] ��Ŀ����Ϣ
* \param uStreamID [in] ��Ƶ��ID
* \retval ��Ƶ��ָ��
* \see  ProgramInfo StreamInfo
* \note ���û���ҵ�����ô���ص�һ·��Ƶ��
*/
__inline StreamInfo* FindAudioStream(ProgramInfo* pProgram, UINT uStreamID)
{
	// ����Ҳ�����ȡ��һ��Program
	StreamInfo* pStream = pProgram->pAudStreamInfos;

	for (int i = 0; i < pProgram->nAudioStreamCount; ++i)
	{
		if (pProgram->pAudStreamInfos[i].uStreamID == uStreamID)
		{
			pStream = &pProgram->pAudStreamInfos[i];
			break;
		}
	}

	return pStream;
}

/*!
* \fn __inline SubPicStreamInfo* FindSubPicStream(ProgramInfo* pProgram, UINT uStreamID)
* \brief ��ProgramInfo�У��ҵ�ָ����Ļ��ID�ģ���Ļ����Ϣָ�롣
* \param pProgram [in] ��Ŀ����Ϣ
* \param uStreamID [in] ��Ļ��ID
* \retval ��Ļ��ָ��
* \see  ProgramInfo StreamInfo
* \note ���û���ҵ�����ô���ص�һ·��Ļ��
*/
__inline SubPicStreamInfo* FindSubPicStream(ProgramInfo* pProgram, UINT uStreamID)
{
	SubPicStreamInfo* pStream = 0;
	for (int i = 0; i <  pProgram->nSubPicStreamCount; i++)
	{
		if (pProgram->pSubPicInfos[i].uStreamID == uStreamID)
		{
			pStream = &pProgram->pSubPicInfos[i];
			break;
		}
	}
	return pStream;
}

#endif
