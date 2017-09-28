unit DecoderParam;

{$MINENUMSIZE 4}

interface

uses
  Windows, CodecDefine;


// DECODE_EX_PARAM_MESSAGE
// SetExDecodeParam����ʹ�õ�uMsg
const DEM_DEINTERLACE = 			1000;	// ����ɨ���ֵ�㷨�� wParam - DEINTERLACE_STYLE


{$IFNDEF STREAM_TYPE_DEF}
{$DEFINE STREAM_TYPE_DEF}
type
  DecParam = record
    uMediaType:       UINT;        // ' FWS'  ' BOV'  ' GPM'
    uProgramID:       UINT;        // uPID of ProgramInfo
    nTrack:      Integer;     //��Ƶ������
    nSubTrack:   Integer;     //��Ļ��� ��������Video��������
    bDirectCopy: BOOL;
    uDeintelace : DEINTERLACE_STYLE;	// ����ɨ���ֵ�㷨
    wParam:      WPARAM;
    lParam:      LPARAM;
	bUseThreadDecode : BOOL;	// ʹ���߳̽��뻺�� ����������������ʱ��Ҫ���ò�����FALSE��������ʵʱDeintelace
	                        	// ���CPUϵͳ�ϴ��߳̿�������CPUʹ����  
  end;
 
  PDecParam = ^DecParam;
  
{$ENDIF}  //  STREAM_TYPE_DEF


implementation

end.
