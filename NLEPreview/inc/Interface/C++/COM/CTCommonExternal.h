/* ### WS@H Project:Multimedia_Platform ### */

#pragma once
#include <typedef.hpp>
#include <vector>
using namespace std;

#define AV_TIME_BASE            1000000

enum E_AV_SEEK_TYPE
{
	E_AV_SEEK_KEYFRAME, 
	E_AV_SEEK_FILEPOS, 
	E_AV_SEEK_TIMEPOS,	
	E_AV_SEEK_FRAMEPOS	
};

enum E_AV_SCAN_TYPE
{
	E_AV_SCAN_TYPE_PROGRESSIVE, ///< ����ģʽ

	E_AV_SCAN_TYPE_INTERLACED, ///< ��֯ģʽ

	E_AV_SCAN_TYPE_UNKNOWN,	///< ģʽδ֪

	E_AV_SCAN_TYPE_RESERVED	///< �����ֶ�

};

enum E_AV_STREAM_TYPE
{
	/*!��ý����*/
	E_ST_NONE,

	/*! ��ƵStream*/
	E_ST_VIDEO,		// 

	/*! ��ƵStream*/
	E_ST_AUDIO,	

	E_ST_SUBPIC_Internal,
	/*! ��ĻStream*/
	E_ST_SUBPIC_External,

	/*! ͼ��Stream*/
	E_ST_IMAGE,
};


enum E_DEMUXDATA_TYPE
{
	E_DEMUXDATA_COMPRESS,
	E_DEMUXDATA_UNCOMPRESS
};

enum E_DEMUXWE_TYPE
{
	E_DEMUXWE_SINGLE,
	E_DEMUXWE_MULTI
};

enum SEEK_CAPACITY
{
	SEEK_CAPACITY_UNKNOW    =    0 ,
	SEEK_CAPACITY_NONE      =    1 ,
	SEEK_CAPACITY_TIME      =    2 ,
	SEEK_CAPACITY_FILEPOS   =    4 ,

};

typedef struct _ST_AVRational{
	int num; ///< numerator
	int den; ///< denominator
} ST_AVRational;

struct ST_AudioInfo
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


// ��Ƶ��Ϣ
struct ST_VideoInfo
{
	/*! ���*/
	int width;

	/*! �߶� */
	int height;

	/*! ֡�� */
	double frame_rate;	

	/*! x������� */
	int xratio;	

	/*! y������� */
	int yratio;	

	/*! ���֡�� */
	double frame_rate_max;

	/*! ֡��ģ�� */
	int nIsVBR;

	UINT            nVideoProfile;

	UINT            nVideoLevel;

	UINT            nMaxBFrames;
};

struct ST_StreamInfo
{
	/*! ������*/
	E_AV_STREAM_TYPE	uStreamType;

	UINT			uStreamIndex;

	/*! ��ID*/
	UINT			uStreamID;

	/*! ��CodecID*/
	DWORD			dwCodecID;

	wchar_t	szDescription[128];

	/*! ����ʱ�䳤��*/
	double			dStreamLength;

	/*! ��������*/
	int				nBitrate;

	/*! ������Ƶ��Ϣ�� ��uStreamTypeΪST_VIDEOʱ��Ч*/
	ST_VideoInfo 	vidInfo;

	/*! ������Ƶ��Ϣ�� ��uStreamTypeΪST_AUDIOʱ��Ч*/
	ST_AudioInfo 	audInfo;	

	/*! ��ǰ���ĵ�һ��ʱ���*/
	__int64			ptsStart;	

	/*! ��ǰ���ĵ�һ��ʱ����͸�·��Ŀ��������ptsStart��С���Ǹ�ptsStart�Ĳ�ֵ*/
	__int64			ptsOffset;	

	/*! ��ǰ���ĸ��л�����ɨ�� */
	E_AV_SCAN_TYPE	scanType;

	/*! ��ǰ��������Ӧ��ExtraData�ĳ���*/
	UINT            nExtraDataLength;
	/*! ��ǰ��������Ӧ��ExtraData�ĵ�ַ*/
	unsigned char   *pExtraDataBuffer;

	ST_AVRational    sample_ratio_video;




	ST_StreamInfo()
	{
		memset(this,0,sizeof(ST_StreamInfo));
		uStreamType = E_ST_NONE;
		uStreamID   = 0xFFFFFFFF;
		dwCodecID    = 0;
		dStreamLength = 0.0;
		nBitrate    = 0;
		ptsOffset   = 0;
		ptsStart    = 0;
		scanType    = E_AV_SCAN_TYPE_UNKNOWN;
		nExtraDataLength = 0;
		pExtraDataBuffer = 0;
	}
};


struct ST_ProgramInfo
{
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

	/*! ��Ŀ������Ļ������Ŀ*/
	int					nSubPicStreamCount;

	/*! ��Ŀ������Ƶ��Ϣ*/
	ST_StreamInfo*			pVidStreamInfos;

	/*! ��Ŀ������Ƶ��Ϣ*/
	ST_StreamInfo*			pAudStreamInfos;

	/*! ��Ŀ������Ļ����Ϣ*/
	ST_StreamInfo*	pSubPicInfos;
};


struct ST_MEDIA_FILE_INFO
{
	/*! �ļ���*/
	wchar_t			szName[512];

	/*! ý���ļ�ʱ�䳤��(ȡ������Ŀ���У������·)*/
	double			dMediaLength;

	/*! ý���ļ������ʣ�(��·��Ŀ������֮��)*/
	int				nBitrate;

	/*! ý���ļ��Ľ�Ŀ��*/
	int				nProgramCount;

	BOOL            HaveNoProgram;

	/*! ý���ļ��Ľ�Ŀ��Ϣ*/
	ST_ProgramInfo*	pProgramInfos;

};

struct KeyFrameIndex
{
	int index;
	LONGLONG pts;
	LONGLONG offset;
};

struct KeyFrameIndexArr
{
	__int64 nCount;
	vector<KeyFrameIndex> keyFrameIdArr;
};


struct ST_VideoFrame 
{
	int width;
	int height;
	BYTE *y;
	BYTE *u;
	BYTE *v;
	int y_pitch;
	int u_pitch;
	int v_pitch;

};

struct ST_AudioFrame 
{
	int samplerate;
	int bitdepth;
	int channel;
	BYTE *pdata;
	int pdatasize;
	int maxlen;

};

struct ST_MediaFrame
{
	E_AV_STREAM_TYPE type;
	long long pts;
	long long dts;
	long duration;
	union
	{
		ST_VideoFrame video;
		ST_AudioFrame audio;

	};


};

ST_MediaFrame* CreateVideoFrame(int width,int height);
void ReleaseVideoFrame(ST_MediaFrame* frame);
ST_MediaFrame* CreateAudioFrame(int samplerate,int channel);
void ReleaseAudioFrame(ST_MediaFrame* frame);


BOOL __stdcall IsCodecSupport(DWORD id);
UINT UnFixtMediaStreamID(UINT id);