
/*! \file WSAudioInfo.h
* \brief							��Ƶ��Ϣ�ṹ��
*/

#pragma once

/*!
* \def MEDIA_CAPABILITIES
* \brief ����ý��seek�Լ�ʱ����Ϣ
*/

// MEDIA_CAPABILITIES
#ifndef  MEDIA_CAPABILITIES
	#define MEDIA_CAPABILITIES

	#define MCAPS_CANT_SEEK			0x0001	// ��֧��Seek����
	#define MCAPS_UNKNOWN_LENGTH	0x0002	// ý�岥��ʱ��δ֪
#endif //  MEDIA_CAPABILITIES

// ��Ƶ��Ϣ

/*!
* \struct WSAudioInfo
* \brief ��Ƶ��Ϣ
*/
struct WSAudioInfo
{
	/*! ������ */
	int sample_rate;

	/*! ������ */
	int channels;

	/*! ÿ��sampleռ��λ�� */
	int bitspersample;	

	/*! ÿ���ֽ��� */
	int bytespersecond;	

	/*! ʱ�䳤�� */
	double length;	

	/*! ý�����ԣ���MEDIA_CAPABILITIES��ֵ��������ɣ���MEDIA_CAPABILITIES���� */
	DWORD dwCapsFlag;		
};

