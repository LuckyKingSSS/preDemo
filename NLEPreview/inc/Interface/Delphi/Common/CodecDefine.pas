unit CodecDefine;

{$MINENUMSIZE 4}

interface

uses
  Windows;

type

{$IFNDEF _DEC_MODEL_DEFINE}
{$DEFINE _DEC_MODEL_DEFINE}
  DEC_MODEL =         // ������뷽ʽ
  (
    AUTO_MODEL =0,
    DSHOW_MODEL,
    FFMPEG_MODEL,
    DVD_MODEL,			// �����VOB�ļ�
	AVDEC_MODEL,			// WS_AVDec.dll ����WS Video Decoder Platform
  IMAGE_MODEL       // ͼƬ������
  );
{$ENDIF}  //  _DEC_MODEL_DEFINE


{$IFNDEF _AUDIO_INTERPOLATION_DEFINE}
{$DEFINE _AUDIO_INTERPOLATION_DEFINE}
  AUDIO_INTERPOLATION =       // ��Ƶ������ת����ֵ�㷨
  (
    SIMPLE_LINEAR = 0,        // һ�����Բ�ֵ
    QUADRATIC_LINEAR  	      // �������Բ�ֵ(��δʵ��)
  );
{$ENDIF}  //  _AUDIO_INTERPOLATION_DEFINE


{$IFNDEF IMAGE_INTERPOLATION_DEFINE}
{$DEFINE IMAGE_INTERPOLATION_DEFINE}
  IMAGE_INTERPOLATION =       // ͼ���ֵ�㷨
  (
	  IIN_AUTO,					        // �Զ�ѡ���ֵ�㷨
    IIN_FAST,			            // Nearest value (�ڽ���ֵ)
    IIN_BI_LINER,		          // Bi-Liner Interpolation (˫���Բ�ֵ)
    IIN_TRI_CONVOLUTE	        // Tri-Convolute Interpolation (�����ֵ)
  );
{$ENDIF}  //  IMAGE_INTERPOLATION_DEFINE


{$IFNDEF IMAGE_RESIZE_METHOD_DEFINE}
{$DEFINE IMAGE_RESIZE_METHOD_DEFINE}
  IMAGE_RESIZE_METHOD =
  (
    IRM_FULLSCREEN,		        // stretch to full screen
    IRM_ORIGINAL_SCALE,       // keep scale, fit to size of output
    IRM_16_9,			            // resize to 16:9, fit to size of output
    IRM_4_3,			              // resize to 4:3, fit to size of output
 	IRM_LETTERBOX,
	IRM_PAN_SCAN
 );
{$ENDIF}  //  IMAGE_RESIZE_METHOD_DEFINE

{$IFNDEF DEINTERLACE_INTERPOLATION_DEF}
{$DEFINE DEINTERLACE_INTERPOLATION_DEF}
 DEINTERLACE_STYLE =
(
	DIS_NONE,				
	DIS_ODD,				// �ظ�������
	DIS_EVEN,				// �ظ�ż����
	DIS_ODD_INTERPOLATE,	// ʹ�������в�ֵ
	DIS_EVEN_INTERPOLATE,	// ʹ��ż���в�ֵ
	DIS_AUTO				// �Զ������ݲ�֧�֣�
);
{$ENDIF}  //  DEINTERLACE_INTERPOLATION_DEF


{$IFNDEF _DOUBLE_RECT_DEFINE}
{$DEFINE _DOUBLE_RECT_DEFINE}
  D_RECT = record            // ����λ��������꣬�ο�ֵΪ���ͼ��ֱ���
    dTop      : Double;      // �������꣬Ϊ������꣬ȡֵ 0.0��1.0����ͬ
    dBottom   : Double;
    dLeft     : Double;
    dRight    : Double;
  end;
{$ENDIF}  //  _DOUBLE_RECT_DEFINE


{$IFNDEF _CLIP_TIME_DEFINE}
{$DEFINE _CLIP_TIME_DEFINE}
  CLIP_TIME = record
    dStart     : Double;      // ��������������Ƶ����ֹʱ�䣬��λ���룬�� ���г��� != ������ȣ�����������Ч��
    dEnd       : Double;      // ��ֵΪ����������Ч��
    dTrimFrom  : Double;      // ����ʱ���֮��㣬��λ���룬��ͬ
    dTrimTo    : Double;      // ����ʱ���֮�յ㣬0ֵ��ʾβ�˲����м���
  end;
{$ENDIF}  //  _CLIP_TIME_DEFINE

  MediaType =
  (
	  AUDIO_TYPE,
	  VIDEO_TYPE
  );

implementation

end.