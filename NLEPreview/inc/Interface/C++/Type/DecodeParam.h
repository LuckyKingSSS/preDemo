//DecodeParam.h
/*! \file DecodeParam.h
* \brief							������������Ϣ
*/

#pragma once
#include "CodecDefine.h"
#ifndef MEDIA_FILE_TYPE
#define MEDIA_FILE_TYPE

/*!
*\enum FILE_TYPE
*\ brief ý���ļ����ͣ�ý���ļ����������Ļ
*/
enum FILE_TYPE 
{
	/*! ý���ļ�*/
	MEDIA_FILE,		

	/*! �����Ļ*/
	SUB_PIC,
};
#endif 

// DECODE_EX_PARAM_MESSAGE
// SetExDecodeParam����ʹ�õ�uMsg
#define DEM_DEINTERLACE			1000	// ����ɨ���ֵ�㷨�� wParam - DEINTERLACE_STYLE
#define CHANGE_AUIDO_STREAM		1010	//��̬�ı���Ƶ������wParam������Ƶ����Stream ID
#define CHANGE_SUBTITLE_STREAM	1011	//��̬�ı���Ļ���� wParam ����Ļ����Stream ID
#define CHANGE_VIDEO_STREAM		10012	//��̬�ı���Ƶ��Ļ���� wParam ����Ļ����Stream ID

#ifndef VIDEO_DEC_PARAM
#define VIDEO_DEC_PARAM

/*! 
* \struct DecParam
* \brief  �������
*/
struct DecParam
{
	/*! �ṹ��Ĵ�С�������汾����*/
	int					nSize;

	/*! ý���ļ���FourCC*/
	UINT				uMediaType;			

	/*! ��Ŀ��ID*/
	UINT				uProgramID;			

	/*! ��Ƶ��ID*/
	int					nTrack;				

	/*! ��Ļ��ID*/
	int					nSubTrack;			

	/*! ֱ�Ӷ�ȡ������*/
	int					bDirectCopy;		

	/*! ��ʹ�õĸ���ɨ���ֵ�㷨*/
	DEINTERLACE_STYLE	uDeintelace;	

	/*! �������*/
	WPARAM				wParam;

	/*! �������*/
	LPARAM				lParam;				

	/*! �Ƿ�ʹ�ý�����̣߳�1��ʾʹ�ã� 0��ʾ��ʹ��*/
	int					bUseThreadDecode;	
	    				                 	

	/*! �����Ļ�Ŀ�*/
	int					nWidth;			

	/*! �����Ļ�ĸ�*/
	int					nHeight;
};

#endif

#ifndef FLOAT_RECT_DEF
#define FLOAT_RECT_DEF
typedef struct tagFRECT
{
	float   left;
	float   top;
	float   right;
	float   bottom;
} FRECT, *PFRECT;
#endif