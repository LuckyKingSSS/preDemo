// AudioSlideParam.h

/*
	   ��Ƶ�ϳɵĴ������
*/

#pragma once

#include "DecodeParam.h"
#include "CodecDefine.h"


struct AudioSlideParam
{
	int					nSampleRate;
	int					nChannels;
	int					nBitsPerSample; // ������ȣ�Ŀǰ��֧��16λ
	AUDIO_INTERPOLATION	nInterpolation;	// ������ת����ֵ�㷨
};

struct VolumEffect			// ������Ч
{
	int	bUseEffect;		// �Ƿ�ʹ����Ч
	double	dStartTime;		// ��Ч��ֹʱ�䣬��λ���룬�����ʱ��߶�ΪΪ׼�������¹�ϵ��
	double	dEndTime;		//				0.0 <= dStartTime < dEndTime <= dTimeEnd - dTimeStart
	int		nStartVoulm;	// ��ʼ����
	int		nEndVoulm;		// ��������
	int		nEffectID;		// �����㷨ID
};

struct AudioProcessParam			// ��Ƶ���������ע�⣺nVolum��Start/EndEffectЧ���е��ӣ�����nVolum = 90,  
{									// StartEffect.nStartVoulm = 80,�����տ�ʼ����Ϊ  ԭ������90%��80% �� ԭ������72%
	CLIP_TIME		Time;			// ʱ������
	int				nVolum;			// ����,0��200, 100����ԭ����
	VolumEffect		StartEffect;	// ��Ƶ��ʼ���ֹ���Ч�����ݲ�ʹ�ã�
	VolumEffect		EndEffect;		// ��Ƶ��β���ֹ���Ч�����ݲ�ʹ�ã�
	DEC_MODEL		DecMod;			// ���뷽ʽ
	DecParam		decParam;		// ��Ƶ�������
};
