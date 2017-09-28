unit
	AudioInfo;

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
 WSAudioInfo = record
	sample_rate : Integer;		// ������
	channels : Integer;			// ������
	bitspersample : Integer;	// ÿ��sampleռ��λ��
	bytespersecond : Integer;	// ÿ���ֽ���
	length : double;			// ��֡��ʱ�䳤��

	dwCapsFlag : DWORD;			// ý�����ԣ���MEDIA_CAPABILITIES��ֵ��������ɣ���MEDIA_CAPABILITIES����
 end;

type
	PWSAudioInfo	= ^WSAudioInfo;

implementation

end.


