
#pragma once

#include "CodecFrame.h"

struct TimeData
{
    int hour;
    int minute;
    int second;
    int millisec;
};

/*************************************************************
������Ϣ֪ͨ wParam: 0   ���ڴ���  lParam: 0 - 100
100 �������  lParam : 0 �������
1 �û���ֹ 
2 �ⲿ�ص���ֹ 
3 �������� 
*************************************************************/

// ����ʱ��Ԥ��ʹ�ûص�����
//typedef int (__stdcall * ENCODE_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);
// uMsg -    0 ������Ϣ  wParam - ����(0-100)  lParam - ProgressInfo*
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ 
//           101 ������Ϣ  wParam - ����(0-100)  lParam - 0
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
// ����FALSE ��ֹͣת��

struct ProgressInfo
{
    double dTotalLength;		// �ܳ���
    double dCurrTime;			// ��ǰʱ��
    int	   nPercent;			// �ٷֱȣ�0 - 100��
    int	   nPercentPercent;		// ��ֱȣ�0 - 10000��
    const MEDIA_FRAME* pImageFrame;	//ͼ������

    TimeData	 tmPrepaid; // ��ǰ��������ʱ��(ϵͳʱ��)
    TimeData	 tmRemain;  // ��ǰ����ʣ��ʱ��(ϵͳʱ��)
    double		 dTransedTime;//��ǰ������ת��Ƭ��ʱ��
    double		 dTransRate;  //ת�����ʣ���λ��ÿ��ת����Ƭ�ϳ���
};

enum FileInfoType
{
	ID3,
};

#ifndef FILE_PARAM
#define FILE_PARAM
	struct FileInfoParam
	{
		FileInfoType formateType;
		int  nBufSize;
		BYTE *pBuffer;     
	};
#endif


#ifndef STREAM_PARAM
#define  STREAM_PARAM
	struct StreamParam
	{
		UINT	dwFourCC;
		int      nBufSize;
		BYTE     *pBuffer;
	};
#endif

