// AudioSlideParam.pas

{
	   ��Ƶ�ϳɵĴ������
}

unit AudioSlideParams;

interface

uses
  Windows, DecoderParam, CodecDefine;

type

  AudioSlideParam = record
    nSampleRate       : Integer;
    nChannels         : Integer;
    nBitsPerSample    : Integer;              // ������ȣ�Ŀǰ��֧��16λ
    nInterpolation    :	AUDIO_INTERPOLATION;  // ������ת����ֵ�㷨
  end;
  PAudioSlideParam = ^AudioSlideParam;

  VolumEffect = record			  // ������Ч
	  bUseEffect    : BOOL;		  // �Ƿ�ʹ����Ч
	  dStartTime    : Double;		// ��Ч��ֹʱ�䣬��λ���룬�����ʱ��߶�ΪΪ׼�������¹�ϵ��
		dEndTime      : Double;		//				0.0 <= dStartTime < dEndTime <= dTimeEnd - dTimeStart
		nStartVoulm   : Integer;	// ��ʼ����
		nEndVoulm     : Integer;	// ��������
		nEffectID     : Integer;	// �����㷨ID
  end;
  PVolumEffect = ^VolumEffect;

  AudioProcessParam	= record		  // ��Ƶ���������ע�⣺nVolum��Start/EndEffectЧ���е��ӣ�����nVolum = 90,
                								  // StartEffect.nStartVoulm = 80,�����տ�ʼ����Ϊ  ԭ������90%��80% �� ԭ������72%
    Time          : CLIP_TIME;	  // ʱ������
    nVolum        : Integer;			// ����,0��200, 100����ԭ����
    StartEffect   : VolumEffect;	// ��Ƶ��ʼ���ֹ���Ч�����ݲ�ʹ�ã�
    EndEffect     : VolumEffect;	// ��Ƶ��β���ֹ���Ч�����ݲ�ʹ�ã�
    DecMod        : DEC_MODEL;    // ���뷽ʽ
    audDecParam   : DecParam;			// ��Ƶ�������
 end;
  PAudioProcessParam = ^AudioProcessParam;

implementation

end.