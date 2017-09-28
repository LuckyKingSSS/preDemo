unit YUVImage;

interface

type
//#ifndef _YUVIMAGE_DEF
//#define _YUVIMAGE_DEF

{$ifndef _YUVIMAGE_DEF}
   {$define _YUVIMAGE_DEF}
  // YUVͼ���ʽ����
  YUV_IMAGE_FORMAT =
   (
      YIF_444,
      YIF_422,
      YIF_YV12   // 420
   );

// YUVͼ�����ݽṹ����
  _YUVImage = record
    format  :YUV_IMAGE_FORMAT;

    y       :pByte;     // Y����ָ��
    u       :pByte;     // U����ָ��
    v       :pByte;     // V����ָ��
    a       :pByte;     // Alpha ͨ������͸���ȣ�

    width   :integer;   // ͼ����
    height  :integer;   // ͼ��߶�

    y_pitch :integer;   // Y����ÿ����ռ�ֽ���
    u_pitch :integer;   // U����ÿ����ռ�ֽ���
    v_pitch :integer;   // V����ÿ����ռ�ֽ���
  end;
  PYUVImage = ^_YUVImage;
{$endif}
implementation

end.
