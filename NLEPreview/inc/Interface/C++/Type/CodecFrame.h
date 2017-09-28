// CodecFrame.h

//DecodeParam.h
/*! \file CodecFrame.h
* \brief	��������Ƶ���ݲ���
*/


#pragma once
#include <string.h> // memset
#include "FileInfo.h"

#ifndef _YUVIMAGE_DEF
#define _YUVIMAGE_DEF

/*!
* \enum YUV_IMAGE_FORMAT
* \brief  YUVͼ���ʽ���� 
*/
// YUVͼ���ʽ����
enum YUV_IMAGE_FORMAT
{
	YIF_444,
	YIF_422,
	YIF_YV12 // 420
};

/*!
* \struct YUVImage
* \brief  YUVͼ���ʽ���� 
* \see YUV_IMAGE_FORMAT
*/

// YUVͼ�����ݽṹ����
struct YUVImage
{
	/*! YUV �ĸ�ʽ*/
	YUV_IMAGE_FORMAT format;

/*! Y����ָ��*/
	LPBYTE	y;

	/*! U����ָ��*/
	LPBYTE	u;

	/*! V����ָ��*/
	LPBYTE	v;

	/*! Alpha ͨ������͸���ȣ� */
	LPBYTE	a;

	/*! ͼ����*/
	int width;  

	/*! ͼ��߶�*/
	int height; 

	/*! Y����ÿ����ռ�ֽ���*/
	int y_pitch;

	/*! U����ÿ����ռ�ֽ���*/
	int u_pitch; // 

	/*! V����ÿ����ռ�ֽ���*/
	int v_pitch;
};
#endif

// ͼ���ʽ����
#ifndef IMAGEFORMAT
#define IMAGEFORMAT
/*!
* \enum IMAGE_FORMAT
* \brief  ��Ƶͼ��ĸ�ʽ 
*/
enum IMAGE_FORMAT
{
	/*! RGB����*/
	IF_RGB,

	/*! YUV����*/
	IF_YUV,

	/*! ѹ������*/
	IF_COMPRESSED,
};
#endif

enum  FRAME_DATA_TYPE
{
	DATA_COMPRESS =0,
	DATA_UNCOMPRESS,
	DATA_CONTROL
};

// ͼ�����ݽṹ����
//JYY CHANGE ����Ľṹ�嶼����C++��ʽ���壬������Щ���MPEGϵ�ж�����C�ķ�ʽ�����벻����
//��ֻ����C�ķ�ʽ�ض����˸�ͷ�ļ�MediaType,��ֹ�ظ������������Щ��
#ifndef MEDIAFRAME  
#define MEDIAFRAME
/*!
* \struct VideoImage
* \brief  ��Ƶͼ�����
* \see IMAGE_FORMAT
*/

struct VideoImage
{
	/*! ͼ���ʽ*/
	IMAGE_FORMAT	format;

	/*!
	* \union 
	* \brief ��ʽ����
	*/
	union
	{
		/*!
		* \brief IF_YUV���Ͳ���
		* \see YUV_IMAGE_FORMAT
		*/
		struct
		{
			/*! YUV��ʽ����*/
			YUV_IMAGE_FORMAT yuv_format;

			/*! Y����ָ��*/
			LPBYTE	y;

			/*! U����ָ��*/
			LPBYTE	u;	 

			/*! V����ָ��*/
			LPBYTE	v;	

			/*! Alpha ͨ������͸���ȣ� */
			LPBYTE	a;	
			
			/*! ͼ����*/
			int width;  
			
			/*! ͼ��߶�*/
			int height; 

			/*! Y����ÿ����ռ�ֽ���*/
			int y_pitch; 

			/*! U����ÿ����ռ�ֽ���*/
			int u_pitch;

			/*! V����ÿ����ռ�ֽ���*/
			int v_pitch; 

			int a_pitch;
		};

		/*!
		* \brief IF_RBG���Ͳ���
		*/
		struct
		{
			/*! λͼ��Ϣ*/
			BITMAPINFOHEADER	biHeader;

			/*! λͼ����*/
			LPBYTE				lpBits;
		};

		/*!
		* \brief ѹ������
		*/
		struct // ѹ������
		{
			/*! ѹ�������׵�ַ*/
			BYTE*	pData;

			/*! ѹ�����ݴ�С*/
			int		nBytes;

			/*! ��������С*/
			int		nBufSize; // pData ��������С
		};
	};

	/*! ָʾ��־ ��λΪ1��ʾ�ؼ�֡*/
	int	flag;//
};

#ifndef SUBPICFRAME  
#define SUBPICFRAME

/*!
* \struct SubPicFrame
* \brief  ��Ļ���ݲ���
* \see YUV_IMAGE_FORMAT
*/
struct SubPicFrame
{
	/*! ��Ļ����*/
	YUV_IMAGE_FORMAT format;

	/*! Y����ָ��*/
	LPBYTE	y;				

	/*! U����ָ��*/
	LPBYTE	u;	 			

	/*! V����ָ��*/
	LPBYTE	v;	 			

	/*! Alpha ͨ������͸���ȣ�*/
	LPBYTE	a;	 			 

	/*! ��Ӧ����Ƶ����ʼ����*/
	int dx;		 			

	/*! ��Ӧ����Ƶ����ʼ����*/
	int dy;

	/*! ��Ļͼ����*/
	int width;   			

	/*! ��Ļͼ��߶�*/
	int height;  			

	/*! ��Ļ����Ч��ʼ����*/
	int sx;					

	/*! ��Ļ����Ч��ʼ����*/
	int sy;

	/*! ��Ļ����Чͼ���С����Ӧ��sx��sy*/
	int validwidth;			

	/*! validwidth <= width   validheight <= height*/
	int validheight;			

	/*! Y����ÿ����ռ�ֽ���*/
	int y_pitch; 			

	/*! U����ÿ����ռ�ֽ���*/
	int u_pitch; 			

	/*! V����ÿ����ռ�ֽ���*/
	int v_pitch; 			

	/*! ��ʼʱ�������λ1/10000000 second*/
	__int64	StartPts;	

	/*! ��ʾ����ʱ�� 1/10000000 second*/
	int		duration;	
};
#endif

/*!
* \struct AudioFrame
* \brief  ��Ƶ���ݲ���
*/
struct AudioFrame 
{
	/*! ������*/
	int		nSampleRate;

	/*! ������*/
	int		nChannels;

	/*! һ�β�����ʹ�õ�BIT*/
	int		nBitsPerSample;

	/*! ��Ƶ����ָ��*/
	BYTE*	pData;

	/*! ��Ƶ������*/
	int		nBytes;

	/*! pData ��������С*/
	int		nBufSize; 
};

/*!
* \struct MEDIA_FRAME
* \brief  Frame��Ϣ
* \see AV_STREAM_TYPE VideoImage AudioFrame SubPicFrame
*/
struct MEDIA_FRAME 
{
	/*! ��������*/
	AV_STREAM_TYPE dwType;
	union
	{
		/*! ��Ƶ����*/
		VideoImage	video;

		/*! ��Ƶ����*/
		AudioFrame	audio;

		/*! ��Ļ����*/
		SubPicFrame subPic;
	};

	/*! Frame����ʾʱ��� ��λ1/10000000 second*/
	__int64	pts;		

	/*! Frame����ʾ����� ��λ1/10000000 second*/
	__int64 dts;		

	/*! Frame�ĳ���ʱ�� ��λ1/10000000 second*/
	int		duration;	

};
#endif


#ifdef __cplusplus

/*!
* \fn __inline const YUVImage* VideoImage_2_YUVImage(const VideoImage* pVidImage)
* \brief VideoImage��ʽת����YUVImage��ʽ���
* \param pVidImage [in] ���� VideoImage��ʽ
* \reval ���YUVImage��ʽ
* \see VideoImage YUVImage
*/
__inline const YUVImage* VideoImage_2_YUVImage(const VideoImage* pVidImage)
{
	if ((0 == pVidImage) || (IF_YUV != pVidImage->format))
		return 0;

	return (const YUVImage*)&pVidImage->yuv_format;
}

/*!
* \fn __inline const YUVImage* MediaFrame_2_YUVImage(const MEDIA_FRAME* frame)
* \brief MEDIA_FRAME��ʽת����YUVImage��ʽ���
* \param frame [in] ���� MEDIA_FRAME��ʽ
* \reval ���YUVImage��ʽ
* \see MEDIA_FRAME YUVImage
*/
__inline const YUVImage* MediaFrame_2_YUVImage(const MEDIA_FRAME* frame)
{
	if ((0 == frame) || (IF_YUV != frame->video.format))
		return 0;

	return (const YUVImage*)&frame->video.yuv_format;
}

__inline void ReleaseRGBAFrame(MEDIA_FRAME* frame)
{
	if (0 == frame)
		return;

	delete[] frame->video.lpBits;

	delete frame;

}

__inline MEDIA_FRAME* CreateRGBAFrame(int width, int height, int bAlpha = true, int bBlackImage = true)
{
	MEDIA_FRAME* frame = new MEDIA_FRAME;

	memset(frame, 0, sizeof(MEDIA_FRAME));
	frame->pts = -1;
	frame->dts = -1;
	frame->duration = 0;
	frame->dwType = ST_VIDEO;
	frame->video.format = IF_RGB;
	frame->video.biHeader.biBitCount = 32;
	frame->video.biHeader.biHeight = height;
	frame->video.biHeader.biWidth = width;
	frame->video.biHeader.biSizeImage = frame->video.biHeader.biHeight * frame->video.biHeader.biWidth * frame->video.biHeader.biBitCount / 8;

	if (bAlpha)
	{
		int nsize = frame->video.biHeader.biSizeImage *1.2;

		frame->video.lpBits = new BYTE[nsize];
		memset(frame->video.lpBits, 0xFF, nsize);
	}
	return frame;
}


/*!
* \fn __inline MEDIA_FRAME* CreateYV12Frame(int width, int height, int bAlpha = false, int bBlackImage = true)
* \brief ����ͼ���With, height����YIF_YV12��ʽ��MEDIA_FRAME
* \param width [in] ͼ��Ŀ�
* \param height [in] ͼ��ĸ� 
* \param bAlpha [in] ͸����
* \bBlackImage [in] true������ʼ������ͼ��Ϊ��ɫ
* \reval ���MEDIA_FRAME��ʽ
* \see MEDIA_FRAME
*/
__inline MEDIA_FRAME* CreateYV12Frame(int width, int height, int bAlpha = true, int bBlackImage = true)
{
	MEDIA_FRAME* frame = new MEDIA_FRAME;

	memset(frame, 0, sizeof(MEDIA_FRAME));
	frame->pts = -1;
	frame->dts = -1;
	frame->duration = 0;
	frame->dwType = ST_VIDEO;
	frame->video.format = IF_YUV;
	frame->video.yuv_format = YIF_YV12;
	frame->video.width = width;
	frame->video.height = height;
	frame->video.y_pitch = width;
	frame->video.u_pitch = (width + 1) / 2;
	frame->video.v_pitch = (width + 1) / 2;
	if (bAlpha)
	{
		frame->video.a_pitch = width;
	}
	

	int y_sz = width * height;
	int u_sz = ((width + 1) / 2) * ((height + 1) / 2);

	int size = y_sz + u_sz * 2;

//	frame->video.y = new BYTE[y_sz + 128];
//	frame->video.u = new BYTE[u_sz + 128];
//	frame->video.v = new BYTE[u_sz + 128];
//	if (bAlpha)
//	{
//		frame->video.a = new BYTE[y_sz + 128];
//	}

	if (bAlpha)
		size += y_sz;

	frame->video.y = new BYTE[size + 512];
	frame->video.v = frame->video.y + y_sz; 
	frame->video.u = frame->video.v + u_sz; 
	if (bAlpha)
		frame->video.a = frame->video.u + u_sz; 

	if (bBlackImage)
	{
		memset(frame->video.y, 16, y_sz);
		memset(frame->video.u, 128, u_sz);
		memset(frame->video.v, 128, u_sz);
		if (bAlpha)
		{
			memset(frame->video.a, 255, y_sz);
		}
	}

	return frame;
}

/*!
* \fn __inline void ReleaseYV12Frame(MEDIA_FRAME* frame)
* \brief �ͷ�YIF_YV12��ʽ��MEDIA_FRAME
* \param frame [in] YIF_YV12��ʽ��MEDIA_FRAME
*/
__inline void ReleaseYV12Frame(MEDIA_FRAME* frame)
{
	if (0 == frame)
		return;

	delete [] frame->video.y;

	delete frame;

}

/*!
* \fn __inline MEDIA_FRAME* CreateAudioFrame(int sample_rate, int channels, int bits_per_sample, int nFrameSize = (32 * 1024))
* \brief ������Ƶ���ݵĲ�����, ���������Լ�����λ���� ������ƵMEDIA_FRAME
* \param sample_rate [in] ��Ƶ�Ĳ�����
* \param channels [in] ������ 
* \param bits_per_sample [in] ����λ��
* \param nFrameSize [in] ��ʼ����������С
* \reval �����Ƶ MEDIA_FRAME��ʽ
*/
__inline MEDIA_FRAME* CreateAudioFrame(int sample_rate, int channels, int bits_per_sample, int nFrameSize = (32 * 1024))
{
	MEDIA_FRAME* frame = new MEDIA_FRAME;

	memset(frame, 0, sizeof(MEDIA_FRAME));

	frame->pts = -1;
	frame->dts = -1;
	frame->duration = 0;
	frame->dwType = ST_AUDIO;

	frame->audio.pData = new BYTE[nFrameSize];
	memset(frame->audio.pData, 0, nFrameSize);
	frame->audio.nBufSize = nFrameSize;
	frame->audio.nSampleRate = sample_rate;
	frame->audio.nChannels = channels;
	frame->audio.nBitsPerSample = bits_per_sample;

	return frame;
}

/*!
* \fn __inline void ReleaseAudioFrame(MEDIA_FRAME* frame)
* \brief �ͷ���Ƶ MEDIA_FRAME
* \param frame [in] ��ƵFrame
*/
__inline void ReleaseAudioFrame(MEDIA_FRAME* frame)
{
	if (0 == frame)
		return;

	delete [] frame->audio.pData;

	delete frame;

}

/*!
* \fn __inline void CopyVideoFrame(MEDIA_FRAME* pDst, const MEDIA_FRAME* pSrc, int bCopyTimeStamp = true,int bAlpha = true )
* \brief ������ƵMediaFrame
* \param pDst [in] Ŀ����ƵMEDIA_FRAME
* \param pSrc [in] Դ��ƵMEDIA_FRAME 
* \param bCopyTimeStamp [in] �Ƿ񿽱�ʱ���
* \warning ������YIF_YV12��ʽ����Ƶ���ݡ� Ŀ����ƵMEDIA_FRAME�Ŀ��Ҫ����Դ��ƵMEDIA_FRAME�Ŀ�ߣ�����ᵼ���ڴ�Խ��
*/
__inline void CopyVideoFrame(MEDIA_FRAME* pDst, const MEDIA_FRAME* pSrc, int bCopyTimeStamp = true,int bAlpha = true)
{
	if (0 == pDst || 0 == pSrc)
		return;

	if (bCopyTimeStamp)
	{
		pDst->pts = pSrc->pts;
		pDst->dts = pSrc->dts;
		pDst->duration = pSrc->duration;
	}

	int y_pitch = pDst->video.y_pitch;
	int u_pitch = pDst->video.u_pitch;
	int v_pitch = pDst->video.v_pitch;
	int a_pitch = pDst->video.a_pitch;

	int y_pitch_src = pSrc->video.y_pitch;
	int u_pitch_src = pSrc->video.u_pitch;
	int v_pitch_src = pSrc->video.v_pitch;
	int a_pitch_src = pSrc->video.a_pitch;

	int width = pDst->video.width;
	int height = pDst->video.height;

	if (y_pitch != y_pitch_src)
	{
		for (int i = 0; i < height; ++i)
		{
			memcpy(pDst->video.y + y_pitch * i, pSrc->video.y + y_pitch_src * i, y_pitch);
			if(pSrc->video.a != NULL  && pDst->video.a != NULL)
			{
				memcpy(pDst->video.a + a_pitch * i, pSrc->video.a + a_pitch_src * i, a_pitch);
			}
		}
	}
	else
	{
		memcpy(pDst->video.y, pSrc->video.y, y_pitch * height);
		if(pSrc->video.a  != NULL && pDst->video.a != NULL)
		{
			memcpy(pDst->video.a, pSrc->video.a, a_pitch * height);
		}
	}
	

	if ( (u_pitch != u_pitch_src) || (v_pitch != v_pitch_src))
	{
		for (int i = 0; i < (height + 1) / 2; ++i)
		{
			memcpy(pDst->video.u + u_pitch * i, pSrc->video.u + u_pitch_src * i, u_pitch);
			memcpy(pDst->video.v + v_pitch * i, pSrc->video.v + v_pitch_src * i, v_pitch);
		}
	}
	else
	{
		memcpy(pDst->video.u, pSrc->video.u, u_pitch * ((height + 1) / 2) );
		memcpy(pDst->video.v, pSrc->video.v, v_pitch * ((height + 1) / 2) );
	}	


}

__inline void CopyAudioFrame(MEDIA_FRAME* pDst, const MEDIA_FRAME* pSrc, int bCopyTimeStamp = true)
{
	if (0 == pDst || 0 == pSrc)
		return;
	
	if (bCopyTimeStamp)
	{
		pDst->pts = pSrc->pts;
		pDst->dts = pSrc->dts;
		pDst->duration = pSrc->duration;
	}
	
	pDst->audio.nBitsPerSample = pSrc->audio.nBitsPerSample;
	pDst->audio.nChannels = pSrc->audio.nChannels;
	pDst->audio.nSampleRate = pSrc->audio.nSampleRate;
	
	if (pSrc->audio.nBytes > pDst->audio.nBufSize)
	{
		delete[] pDst->audio.pData;
		
		pDst->audio.pData = new BYTE[pSrc->audio.nBytes + 1024];
		pDst->audio.nBufSize = pSrc->audio.nBytes + 1024;
	}
	
	memcpy(pDst->audio.pData, pSrc->audio.pData, pSrc->audio.nBytes);
	pDst->audio.nBytes = pSrc->audio.nBytes;
}


#endif
