#pragma once

#include "MetaDataInfo.h"
#include "CodecDefine.h"
#include "EncodeParamEx.h"

//��չ�������
#define RESERVEDSIZE 1024
struct VideoParamEx
{
    DWORD	dwFourCC;	// ��Ƶ������ FourCC �� '1VMW'/'2VMW'/'3VMW' /'DIVX'/'462H'
    union 
    {
        WMV_VideoParamEx m_wmvParamEx;
        VC1_VideoParamEx m_vc1ParamEx;
        Xvid_EncodeParamEx m_xvidParamEx;
		H264_VideoParamEx m_h264ParamEx;
		AppleProRes_EncodeParamEx m_proresParamEx;
        int reserved[RESERVEDSIZE]; //�����ֶ� Ϊ�˷���̶���С�ṹ
    };
};

struct AudioParamEx
{ 
    DWORD	dwFourCC;	// ��Ƶ������ FourCC �� '1AMW'/'2AMW'/'3AMW' /' 3PM'  
    union 
    {
        int reserved[RESERVEDSIZE/2]; //�����ֶ� Ϊ�˷���̶���С�ṹ
    };
};

struct EncodeParamEx
{
    DWORD dwFourCC;			    // �ļ���ʽFourCC
    int     useflg;             //��Ч��־  0  δʹ�� 1 ��Ƶ��չ����  2��Ƶ��չ���� 3 ����Ƶ��չ����
    int m_TwoPass;              //���α����־  0 һ�α���; 1 ���α���ֻ��һ������; 2 ���α����Ͷ�������      Ĭ��Ϊ0 
    VideoParamEx videoEx;		// ��Ƶ��չ����
    AudioParamEx audioEx;		// ��Ƶ��չ����
};

struct VideoParam
{
	DWORD	dwFourCC;	// ��Ƶ������ FourCC �� '1VMW'/'2VMW'/'3VMW' /'DIVX'/'462H'
	int		nWidth;		// �ֱ��ʿ��
	int		nHeight;	// �ֱ��ʸ߶�
	double  dFrameRate;	// ֡�� 0��ʾ�Զ�ѡ��
	int		nBitrate;	// ���� bps ���㶨���ʡ��ɱ���С���ʣ�
	int	bIsVBR;		// �Ƿ�ʹ�ñ�����
	int		nMaxBitrate;// �������
	IMAGE_RESIZE_METHOD nResizeStyle;	// ͼ�����ŷ�ʽ
	IMAGE_INTERPOLATION nInterpolation;	// ͼ���ֵ�㷨
	DWORD	dwCompression;				// ͼ���ʽ
	int		nBitsDepth;					// ͼ��λ���

	//=============== MPEG ���������� ===========================//
	// ʹ��Mpeg������ο� #include "mpeg_param.h"                // 
	DWORD   dwFormat;   // �����ʽ                              // 
	DWORD   dwNorm;     // ������ʽ                              //  
	DWORD   dwAspect;   // ����                                  // 
	int    bFieldEnc;  // �Ƿ�ʹ�ý���ģʽ                      //  
	//=============== MPEG ���������� ===========================//

    // ��Ƶ��չ����
    EncodeParamEx VideoParamEx;
};

struct AudioParam
{
	DWORD	dwFourCC;	// ��Ƶ������ FourCC �� '1AMW'/'2AMW'/'3AMW' /' 3PM'
	int		nSampleRate;// ������ Hz
	int		nChannels;	// ��������
	int		nBitrate;	// ���� bps ���㶨���ʡ��ɱ���С���ʣ�
	int	bIsVBR;		// �Ƿ�ʹ�ñ�����
	int		nMaxBitrate;// �������
	int		nBitsPerSample;	// Number of bits per sample of mono data

    // ��Ƶ��չ����
    EncodeParamEx AudioParamEx;
};

// �������
struct EncodeParam
{
	VideoParam video;		    // ��Ƶ����
	AudioParam audio;		    // ��Ƶ����
	int bVideoDisable;		    // ������Ƶ
	int bAudioDisable;		    // ������Ƶ

	DWORD dwFourCC;			    // �ļ���ʽFourCC
    MetaDataInfo metaDataInfo;  // ID3���ļ���Ϣ
};

struct EncoderInfo
{
	DWORD		dwFourCC;
	wchar_t		szEncName[64];
	wchar_t		szDescription[128];
};

struct FileFormatInfo
{
	DWORD			dwFourCC;
	wchar_t			szExtName[10];
	wchar_t			szFormatName[64];
	wchar_t			szDescription[128];
	int				nAudioEncs;
	int				nVideoEncs;
	EncoderInfo**	ppAudioEncInfos;
	EncoderInfo**	ppVideoEncInfos;
};

// ����ʱ��Ԥ��ʹ�ûص�����
typedef BOOL (__stdcall * ENCODE_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);
// uMsg -    0 ������Ϣ  wParam - ����(0-10000)  lParam - ProgressInfo*
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ 
//           101 ������Ϣ  wParam - ����(0-10000)  lParam - 0
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
// ����FALSE ��ֹͣת��

