// FileInfo.pas
unit
	FileInfo;


{$MINENUMSIZE 4}

interface

uses
    windows, VideoInfo, AudioInfo, DecoderParam, CodecDefine;


type

{$IFNDEF STREAM_TYPE_DEF}
{$DEFINE STREAM_TYPE_DEF}

 STREAM_TYPE =
(
	ST_NONE,
	ST_NAV,
	ST_VIDEO,
	ST_AUDIO,
	ST_SUBPIC
);
{$ENDIF}  //  STREAM_TYPE_DEF


StreamInfo = record

	uStreamType : STREAM_TYPE;
	uStreamID : UINT;
	dwFourCC : DWORD;
	nState : Integer;	// 0 - ����  -1 �Ҳ���dwFourCC��Ӧ�Ľ�����
	szName	  	: array [0..63] of WideChar;
	szDescription	  	: array [0..127] of WideChar;
	dStreamLength : double;
	nBitrate : Integer;
	vidInfo : WSVideoInfo;	// ��uStreamTypeΪST_VIDEOʱ��Ч
	audInfo : WSAudioInfo;	// ��uStreamTypeΪST_AUDIOʱ��Ч
	ptsStart	: Int64;	// ��ǰ���ĵ�һ��ʱ���
	ptsOffset	: Int64;	// ��ǰ���ĵ�һ��ʱ����͸�·��Ŀ��������ptsStart��С���Ǹ�ptsStart�Ĳ�ֵ

	dwReserved1 : DWORD;
	dwReserved2 : DWORD;
	
end;
  PStreamInfo = ^StreamInfo;
  
SUPPIC_TYPE =
(
	SPT_Internal,	//��Ƕ��Ļ
	SPT_External	//������Ļ
);

SubPicStreamInfo = record

	uSPType : SUPPIC_TYPE;
	uStreamID : UINT;
	dwFourCC : DWORD;
	szLang : array [0..63] of WideChar;
	szDescription : array [0..127] of WideChar;
end;
PSubPicStreamInfo = ^SubPicStreamInfo;

ProgramInfo = record

	dwNumber : DWORD;
	uPID : UINT;

	dMediaLength : double;
	nBitrate : Integer;

	nVideoStreamCount : Integer;
	nAudioStreamCount : Integer;

	pVidStreamInfos : PStreamInfo;
	pAudStreamInfos : PStreamInfo;
	
  uTimeStampReferenceStreamID : UINT;	// ʱ����ο���Ƶ��ID

  nSubPicStreamCount : Integer;
	pSubPicInfos : PSubPicStreamInfo;

end;
  PProgramInfo = ^ProgramInfo;


//MEDIA_INFO_RELEASE_API = procedure(pMediaFileInfo: PMEDIA_FILE_INFO); stdcall;

MEDIA_FILE_INFO = record

	dwFourCC : DWORD;
  szName	  	: array [0..63] of WideChar;
  szDescription	  	: array [0..127] of WideChar;

  dMediaLength : double;
	nBitrate : Integer;

	nProgramCount : Integer;
	pProgramInfos : PProgramInfo;

//	fnRelease : MEDIA_INFO_RELEASE_API;		// �ͷ�MediaInfo�����ڴ�
  fnRelease : Pointer;

end;
  PMEDIA_FILE_INFO = ^MEDIA_FILE_INFO;

          
implementation

end.
