// YUVImage.h
//
//

#pragma once

#ifndef _YUVIMAGE_DEF
#define _YUVIMAGE_DEF

// YUVͼ���ʽ����
enum YUV_IMAGE_FORMAT
{
	YIF_444,
	YIF_422,
	YIF_YV12 // 420
};

// YUVͼ�����ݽṹ����
struct tagYUVImage
{
#ifdef __cplusplus
	YUV_IMAGE_FORMAT format;
#else
	unsigned int format;
#endif

	unsigned char*	y;	 // Y����ָ��
	unsigned char*	u;	 // U����ָ��
	unsigned char*	v;	 // V����ָ��
	unsigned char*	a;	 // Alpha ͨ������͸���ȣ� 

	int width;   // ͼ����
	int height;  // ͼ��߶�

	int y_pitch; // Y����ÿ����ռ�ֽ���
	int u_pitch; // U����ÿ����ռ�ֽ���
	int v_pitch; // V����ÿ����ռ�ֽ���
} ;

typedef struct tagYUVImage YUVImage;

#endif


