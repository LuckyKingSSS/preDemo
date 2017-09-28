
/*! \file WSVideoInfo.h
* \brief							��Ƶ��Ϣ�ṹ��
*/

#pragma once

/*!
* \def MEDIA_CAPABILITIES
* \brief ����ý��seek�Լ�ʱ����Ϣ
*/

// MEDIA_Capabilities
#ifndef  MEDIA_CAPABILITIES
	#define MEDIA_CAPABILITIES

	#define MCAPS_CANT_SEEK			0x0001	// ��֧��Seek����
	#define MCAPS_UNKNOWN_LENGTH	0x0002	// ý�岥��ʱ��δ֪
#define    MCAPS_SUPPORT_MOV_QUICKTIME_SPRITE 0x04 //ȷ���Ƿ�֧��
#endif //  MEDIA_Capabilities

/*!
* \struct WSVideoInfo
* \brief ��Ƶ��Ϣ
*/

// ��Ƶ��Ϣ
struct WSVideoInfo
{
	/*! ���*/
	int width;

	/*! �߶� */
	int height;

	/*! ֡�� */
	double frame_rate;	

	/*! ��֡�� */
	int total_frames;

	/*! x������� */
	int xratio;	

	/*! y������� */
	int yratio;	

	/*! ͼ���ʽ */
	DWORD dwCompression;

	/*! ͼ��λ��� */
	int nBitsDepth;			

	/*! ý�����ԣ���MEDIA_CAPABILITIES��ֵ��������ɣ���MEDIA_CAPABILITIES���� */
	DWORD dwCapsFlag;		
};

//if (MCAPS_CANT_SEEK == (dwCapsFlag & MCAPS_CANT_SEEK))
//{
//	// ��֧��Seek����
//}

