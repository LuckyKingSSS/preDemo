unit
	VideoInfo;
	
{$MINENUMSIZE 4}
    
interface

uses
    Windows;

// MEDIA_CAPABILITIES
const
 MCAPS_CANT_SEEK			= $0001;	// ��֧��Seek����
 MCAPS_UNKNOWN_LENGTH		= $0002;	// ý�岥��ʱ��δ֪
 

// ��Ƶ��Ϣ
type
 WSVideoInfo = record
	width : Integer;			// ���
	height : Integer;			// �߶�
	frame_rate : double;		// ֡��
	total_frames : Integer;		// ��֡��
	xratio : Integer;			// x�������
	yratio : Integer;			// y�������
	dwFourCC : DWORD;			// ͼ���ʽ
	nBitsDepth : Integer;		// ͼ��λ���

	dwCapsFlag : DWORD;			// ý�����ԣ���MEDIA_CAPABILITIES��ֵ��������ɣ���MEDIA_CAPABILITIES����
 end;


type
	PWSVideoInfo	= ^WSVideoInfo;


implementation

end.


