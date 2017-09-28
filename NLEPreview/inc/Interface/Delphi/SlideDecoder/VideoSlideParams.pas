{
	   ��Ƶ�ϳɵĴ������
}

unit VideoSlideParams;

interface

uses
  Windows, DecoderParam, CodecDefine;

type

  WatermarkParam = record
    hModule       : HMODULE;
    szID          : array [0..511] of WideChar;  // ˮӡ��ԴID
    Rect          : TRect;                       // ����ڼ��ú��ͼ��ֱ����е�λ��
    nOpacity      : Integer;                     // ˮӡ��͸���� (0 - 100)  0 - ��ȫ͸��  100 - ��ȫ��͸��
    lpbi          : PBITMAPINFO;                 // lpbi ��0��ʹ��hModule��֧��32λ͸��ͼ���Լ�Y41A�Զ����ʽ
    lpBits        : PBYTE;                       // lpbi��lpBits��ҪӦ�ó�������������
 		nAlign		    : Integer;										 // ˮӡ���뷽��Ϊ0ʱȡRect���꣬ȡֵ1-9��Ӧ�Ź�λ��	 
  end;
  PWatermarkParam = ^WatermarkParam;

  VideoSlideParam = record
    nWidth          : Integer;                // �ֱ��ʿ��
    nHeight         : Integer;
    dFrameRate      : Double;                 // ֡�� 0��ʾ�Զ�ѡ��
    dwCompression   : DWORD;                  // ͼ���ʽ��Ŀǰֻ֧��'21VY'
    nBitsDepth      : Integer;                // ͼ��λ��� YV12Ϊ12λ
    Watermark       : WatermarkParam;         // ˮӡ����
  end;
  PVideoSlideParam = ^VideoSlideParam;


  VideoProcessParam	= record
    Time          : CLIP_TIME;	   // ʱ������
    CropRect      : TRecT;         // ��������Ϊ�������������
    nBrightness   : Integer;       // ���ȣ�-100��100��0����ԭ����
    nContrast     : Integer;       // �Աȶȣ�-100��100��0����ԭ�Աȶ�
    nSaturation   : Integer;       // ���Ͷ�,-100��100��0����ԭ���Ͷ�
    uExFilterID   : UINT;          // ��չ�˾�ID
    uFlipFlag     : UINT;          // ͼ��ת����
    DecMod        : DEC_MODEL;     // ���뷽ʽ
    vidDecParam   : DecParam;		// �������
	uDeintelace	  : DEINTERLACE_STYLE;		// ȥ������ɨ�跽ʽ
    nResizeStyle    : IMAGE_RESIZE_METHOD;    // ͼ�����ŷ�ʽ
    nInterpolation  : IMAGE_INTERPOLATION;    // ͼ���ֵ�㷨
  end;
  PVideoProcessParam = ^VideoProcessParam;


implementation

end.
        
