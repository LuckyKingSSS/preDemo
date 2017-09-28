unit
	EncParam;

{$MINENUMSIZE 4}
    
interface

uses
    Windows, CodecDefine;


type
 // ��Ƶ����
	VideoParam = record
		dwFourCC : DWORD;		// ��Ƶ������ FourCC �� '1VMW'/'2VMW'/'3VMW' /'DIVX'/'462H'
		nWidth : Integer;		// �ֱ��ʿ��
		nHeight : Integer;		// �ֱ��ʸ߶�
		dFrameRate : double;	// ֡�� 0��ʾ�Զ�ѡ��
		nBitrate : Integer;		// ���� bps ���㶨���ʡ��ɱ���С���ʣ�
		bIsVBR : BOOL;			// �Ƿ�ʹ�ñ�����
		nMaxBitrate : Integer;	// �������
		nResizeStyle : IMAGE_RESIZE_METHOD; // ͼ�����ŷ�ʽ
		nInterpolation : IMAGE_INTERPOLATION;	// ͼ���ֵ�㷨
		dwCompression : DWORD;				// ͼ���ʽ
		nBitsDepth : Integer;					// ͼ��λ���
		
		//=============== MPEG ���������� ===========================//
		// ʹ��Mpeg������ο�     mpeg_param.pas                     // 
		dwFormat   : DWORD;   // �����ʽ                            // 
		dwNorm     : DWORD;     // ������ʽ                          //  
		dwAspect   : DWORD;   // ����                                // 
		bFieldEnc  : BOOL;  // �Ƿ�ʹ�ý���ģʽ                      //  
		//=============== MPEG ���������� ===========================//
		
	end;

// ��Ƶ����
	AudioParam = record
		dwFourCC : DWORD;		// ��Ƶ������ FourCC �� '1AMW'/'2AMW'/'3AMW' /' 3PM'
		nSampleRate : Integer;	// ������ Hz
		nChannels : Integer;	// ��������
		nBitrate : Integer;		// ���� bps ���㶨���ʡ��ɱ���С���ʣ�
		bIsVBR : BOOL;			// �Ƿ�ʹ�ñ�����
		nMaxBitrate : Integer;	// �������
		nBitsPerSample : Integer;	// Number of bits per sample of mono data
	end;	

// �������
	EncodeParam = record
		video : VideoParam;		  // ��Ƶ����
		audio : AudioParam;		  // ��Ƶ����
		bVideoDisable : BOOL;	  // ������Ƶ
		bAudioDisable : BOOL;	  // ������Ƶ
//    case Integer of
//      0: (format : EncoderFormat);	  // �ļ���ʽ
//      1: (dwFourCC: DWORD);           //��Ƶ������
    dwFourCC: DWORD;        // �ļ���ʽFourCC��' 4PM'
	end;
	
	EncoderInfo = record
	    dwFourCC	  	: DWORD;
	    szEncName	  	: array [0..63] of widechar;
	    szDescription	: array [0..127] of widechar;
	end;
	
type 
    PENCODERINFO = ^EncoderInfo;
    PPENCODERINFO = ^PENCODERINFO;
	
	FileFormatInfo = record
	    dwFourCC	  	: DWORD;
	    szExtName	  	: array [0..9] of widechar;
	    szFormatName	: array [0..63] of widechar;
	    szDescription	: array [0..127] of widechar;
	    nAudioEncs		: Integer;
	    nVideoEncs		: Integer;
	    ppAudioEncInfos	: PPENCODERINFO;
	    ppVideoEncInfos	: PPENCODERINFO;
	end;

type
  PFILEFORMATINFO = ^FileFormatInfo;
	    
type
	PENCODEPARAM  = ^EncodeParam;


// ����ʱ��Ԥ��ʹ�ûص�����
//typedef BOOL (__stdcall * ENCODE_CALLBACK)(void* pUserObj, UINT uMsg, WPARAM wParam, LPARAM lParam);
// uMsg -    0 ������Ϣ  wParam - ����(0-100)  lParam - ProgressInfo*
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ 
//           101 ������Ϣ  wParam - ����(0-100)  lParam - 0
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
// ����FALSE ��ֹͣת��
type
  ENCODE_CALLBACK = function(pUserObj: Pointer; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): BOOL; stdcall; 


implementation

end.






