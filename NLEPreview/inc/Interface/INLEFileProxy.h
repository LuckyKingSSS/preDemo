#pragma once

/**
* Copyright (c) 2016 Wondershare.inc
* All rights reserved.
*
*@file  INLEFileProxy.h
*@brief
*@version 1.0
*@author  34973832
*@date    12/01/2017 09:29
*/

#ifndef _H_INLEFILEPROXY_H_
#define _H_INLEFILEPROXY_H_

#include <string>
#include <vector>
#include <functional>

#include <Guiddef.h>
#include <objbase.h>

#include "NLEType.h"

#include "INLETimelineBase.h"

// {8118E2FE-2ADF-4D92-BA5D-0EA6A4050C98}
DEFINE_GUID(CLSID_NLEFileProxy,
	0x8118e2fe, 0x2adf, 0x4d92, 0xba, 0x5d, 0xe, 0xa6, 0xa4, 0x5, 0xc, 0x98);

// {89F9BD71-FAF0-48DF-B343-BBAC72E78FFD}
DEFINE_GUID(IID_INLECacheAudio,
	0x89f9bd71, 0xfaf0, 0x48df, 0xb3, 0x43, 0xbb, 0xac, 0x72, 0xe7, 0x8f, 0xfd);
class INLECacheAudio : public IUnknown
{
public:
	/**
	*@brief  	����ָ���Ĳ���������Ƶ����
	*@param	samplerate ����Ĳ�����
	*@param	channels �����ͨ����
	*@param	bitspersample ����Ĳ���λ��
	*@param	frame_size �����֡���ȡ���λ���ֽ�
	*@param	window ����Ĵ���
	*@param	path �����·��
	*@param	clear �Ƿ�ɾ����������
	*@return 	HRESULT __stdcall
	*@see 		�ο����ϡ�
	*/
	virtual HRESULT __stdcall Start(int samplerate, int channels, int bitspersample, int frame_size, NLERange &window, std::wstring &path) = 0;
	virtual HRESULT __stdcall Stop(bool clear) = 0;

	/**
	*@brief  	��λ/ǰ��/��Ⱦ
	*@param	pos ��λ��λ��
	*@param	step ǰ����֡��������ָ����fame_size����
	*@param	pFrame ��Ⱦ��Ŀ�껺��
	*@return 	HRESULT __stdcall
	*@see 		�ο�����
	*/
	virtual HRESULT __stdcall Seek(NLEFrameIndex pos) = 0;
	virtual HRESULT __stdcall Forward(NLEFrameIndex step) = 0;
	virtual HRESULT __stdcall Render(NLEComPtr<INLEFrame> &pFrame) = 0;
};

// {4D4EEEDB-EB8B-46CE-9AAC-B82542D43A47}
DEFINE_GUID(IID_INLECacheVideo,
	0x4d4eeedb, 0xeb8b, 0x46ce, 0x9a, 0xac, 0xb8, 0x25, 0x42, 0xd4, 0x3a, 0x47);
class INLECacheVideo : public IUnknown
{
public:
	/**
	*@brief  	����ָ���Ĳ���������Ƶ����
	*@param	size ����ĳߴ�
	*@param	framerate �����֡��
	*@param	window ����Ĵ���
	*@param	path �����·��
	*@param	clear �Ƿ�ɾ����������
	*@return 	HRESULT __stdcall
	*@see 		�ο�����
	*/
	virtual HRESULT __stdcall Start(NLESize &size, NLERational &framerate, NLERange &window, std::wstring &path) = 0;
	virtual HRESULT __stdcall Stop(bool clear) = 0;

	/**
	*@brief  	��λ/ǰ��/��Ⱦ
	*@param	pos ��λ��λ��
	*@param	step ǰ����֡��
	*@param	pFrame ��Ⱦ��Ŀ�껺��
	*@return 	HRESULT __stdcall
	*@see 		�ο�����
	*/
	virtual HRESULT __stdcall Seek(NLEFrameIndex pos) = 0;
	virtual HRESULT __stdcall Forward(NLEFrameIndex step) = 0;
	virtual HRESULT __stdcall Render(NLEComPtr<INLEFrame> &pFrame) = 0;
};

// {C7084860-ED5A-46DB-961D-B8A6286EF287}
DEFINE_GUID(IID_INLEFileProxy,
	0xc7084860, 0xed5a, 0x46db, 0x96, 0x1d, 0xb8, 0xa6, 0x28, 0x6e, 0xf2, 0x87);
class INLEFileProxy : public IUnknown
{
public:
	/**
	*@brief  	��/�ر�ý���ļ�
	*@param	path �ļ�·��{�ļ���ȫ·����֧�ֻ�������}
	*@return 	HRESULT __stdcall
	*@see 		�ο�����
	*/
	virtual HRESULT __stdcall Open(std::wstring &path) = 0;
	virtual HRESULT __stdcall Close() = 0;
};

#endif //_H_INLEFILEPROXY_H_


