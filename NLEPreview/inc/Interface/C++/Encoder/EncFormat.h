// EncFormat.h: �������������ӿ�
#pragma once

#include "EncodeParam.h"
#include "CodecFrame.h"


struct ENCODER_ITEM;	// ��������Ϣ
typedef void* HENCODER;	// �������������

// ��ȡ��������Ϣ
extern "C" const ENCODER_ITEM* __stdcall GetEncoders();
typedef const ENCODER_ITEM* (__stdcall* GET_ENCODERS_API)();



// ����dwFourCC��־����������������ֵΪ���������
// HENCODER __stdcall EncoderInit(DWORD dwFourCC, const EncodeParam* pEncParam);
typedef HENCODER (__stdcall* ENCODER_INIT_API)(DWORD dwFourCC, const EncodeParam* pEncParam);

// ���룬������ 1.hEnc - �����������  2.pFrameIn - ������Ƶ���ݣ���ѹ��PCM���ݣ�����Ƶ����(YV12��ʽͼ���޶�Ϊһ֡)��  
//              3.ppFrameOut - ѹ�������ݣ��ɱ����������ڴ棻  
//				4.ppPacketInfo - ���ڴ��pFrameOutѹ�����ݵ���Ϣ����������Ƶ
// ����ֵ�� ѹ�����ݳ��ȣ���λ byte
// int __stdcall Encode(HENCODER hEnc, const MEDIA_FRAME* pFrameIn, MEDIA_FRAME** ppFrameOut, int** ppPacketInfo);
typedef int (__stdcall* ENCODE_API)(HENCODER hEnc, const MEDIA_FRAME* pFrameIn, MEDIA_FRAME** ppFrameOut, int** ppPacketInfo);

// ��ȡVosData���ݿ��ָ��ͳ��ȣ�������AAC��Ƶ������
// void __stdcall GetVosData(HENCODER hEnc, BYTE** ppVosData, int* pVosLen);
typedef void (__stdcall* GET_VOSDATA_API)(HENCODER hEnc, BYTE** ppVosData, int* pVosLen);

// ��ȡPPSData, SPSData�������ݿ��ָ��ͳ��ȣ�������H264��Ƶ������
// void __stdcall GetXPSData(HENCODER hEnc, BYTE** ppPPSData, int* pPPSLen, BYTE** ppSPSData, int* pSPSLen);
typedef void (__stdcall* GET_XPSDATA_API)(HENCODER hEnc, BYTE** ppPPSData, int* pPPSLen, BYTE** ppSPSData, int* pSPSLen);

//Ϊ�˽�������ڱ����е���󲿷�����δ�ܱ��룬ѯ�ʱ���������Ҫ�������ݲ��ܱ���
typedef int (__stdcall * GET_LAST_NEED_PCMDATA_NUM_API) (HENCODER hEnc);
// ���ٱ�����
// void __stdcall DestroyEncoder(HENCODER hEnc);
typedef void (__stdcall* ENCODER_CLOSE_API)(HENCODER hEnc);

// У����Ƶ����������ӱ�����֧�ֵĲ����л�ȡ���봫��ֵ�������һ������Ӵ���ṹ��ָ���з���
// int __stdcall ReviseAudioParam(AudioParam* pAudioParam);
typedef BOOL (__stdcall* REVISE_AUDIO_PARAM_API)(AudioParam* pAudioParam);

// У����Ƶ����������ӱ�����֧�ֵĲ����л�ȡ���봫��ֵ�������һ������Ӵ���ṹ��ָ���з���
// int __stdcall ReviseVideoParam(VideoParam* pVideoParam);
typedef BOOL (__stdcall* REVISE_VIDEO_PARAM_API)(VideoParam* pVideoParam);


//
typedef BOOL (__stdcall* ENCODE_FIRSTEND_API)(HENCODER hEnc,EncodeParam* pEncParam);
typedef BOOL (__stdcall* SET_ENCODE_PARAMEX_API)(EncodeParamEx* pEncParamEx);


struct ENCODER_ITEM
{
	DWORD						dwFourCC;
	wchar_t						szName[64];
	wchar_t						szDescription[128];	
	EncMediaType				Type;			// Audio: 0, Video: 1;

	ENCODER_INIT_API			fnInit;
	ENCODE_API					fnEncode;
	GET_LAST_NEED_PCMDATA_NUM_API	fnGetLastNeedPCMDataNum;
	ENCODER_CLOSE_API			fnClose;

	GET_VOSDATA_API				fnGetVos;
	GET_XPSDATA_API				fnGetXPS;

	REVISE_AUDIO_PARAM_API		fnReviseAudio;
	REVISE_VIDEO_PARAM_API		fnReviseVideo;

	ENCODE_FIRSTEND_API         fnEncodefirstEnd;
	SET_ENCODE_PARAMEX_API      fnSetEncodeParamEx; 
};


