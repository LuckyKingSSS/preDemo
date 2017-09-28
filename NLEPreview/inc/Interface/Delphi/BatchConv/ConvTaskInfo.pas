unit
	ConvTaskInfo; 

{$MINENUMSIZE 4}
    
interface

uses
    Windows, EncParam, CodecDefine, DecoderParam;

type
ConvertState =  // ת��״̬
(
    CS_NONE,		//
    CS_RUNNING,		// ����ת��
    CS_COMPLETE,	// �ɹ�ת��
    CS_ERROR      	// ��������
);



// ��չ�˾�ID���� 
// EX_FILTER_ID
const 
 EX_FILTER_GRAY			= $0001;
 EX_FILTER_EMBOSS		= $0002;
 EX_FILTER_NEGATIVE		= $0004;
 EX_FILTER_BLACK_WHITE	= $0008;
 EX_FILTER_WHITE_BLACK	= $0010;
 EX_FILTER_OLD_PHOTO	= $0020;
	

// FLIP_FLAG
 FLIP_HORIZONTAL		= $0001;
 FLIP_VERTICAL			= $0002;

type

{$IFNDEF WATERMARK_PARAM}
{$DEFINE WATERMARK_PARAM}

  WatermarkParam = record
    hModule       : HMODULE;
    szID          : array [0..511] of WideChar;  // ˮӡ��ԴID
    Rect          : TRect;                       // ����ڼ��ú��ͼ��ֱ����е�λ��
    nOpacity      : Integer;                     // ˮӡ��͸���� (0 - 100)  0 - ��ȫ͸��  100 - ��ȫ��͸��
    lpbi          : PBITMAPINFO;                 // lpbi ��0��ʹ��hModule��֧��32λ͸��ͼ���Լ�Y41A�Զ����ʽ
    lpBits        : PBYTE;                       // lpbi��lpBits��ҪӦ�ó�������������
    nAlign		  : Integer;
  end;
  PWatermarkParam = ^WatermarkParam;
  
{$ENDIF}  //  WATERMARK_PARAM

// Effect����

 EffectData = Record

    nVolume : Integer;	// 0 - 200
    nBrightness : Integer;	// -100��100
    nContrast : Integer; 	// -100��100
    nSaturation : Integer;	// -100��100
    uExFilterID : UINT; 	// �˾�ID
    uFlipID : UINT; 	// ��תID
    uDeintelace : DEINTERLACE_STYLE;// ȥ������ɨ�跽ʽ
end;



 TaskItem = record

     szInputFile: array [0..511] of WideChar;   //�����ļ���

     VidDecParam : DecParam; 	//��Ƶ�������
     AudDecParam : DecParam; 	//��Ƶ�������
     Effect : EffectData;   	//��Ч����
     crCrop : TRECT;         	//��Ƶ��������
     Watermark : WatermarkParam;	//ˮӡ
    // Slide Time Ƭ����ʱ�����ϵ�ʱ��
     dStart : double;		// ��������������Ƶ����ֹʱ�䣬��λ���룬�� ���г��� != ������ȣ�����������Ч��
     dEnd : double;		// ��ֵΪ����������Ч�� 
				// Slide Time Ϊʱ�����ϵ�ʱ��

     dTrimStart : double;        	// ���п�ʼʱ�䣨�ļ�����ʱ�䣩
     dTrimEnd : double;        	// ���н���ʱ�䣨�ļ�����ʱ�䣩��Ƶ����ʱ������д��ȷ��ʱ��

     uDecMode : DEC_MODEL;

     EncParam : EncodeParam;
     szOutputFile : array [0..511] of WideChar;	// ����ļ���, ·��ȫ��

     nConvState : ConvertState;
    
     dwUserData : DWORD;		// �û�����
    
  end;
  PTaskItem = ^TaskItem;



implementation

end.


