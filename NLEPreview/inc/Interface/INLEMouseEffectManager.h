/**                                     
 * Copyright (c) 2016 Wondershare.inc   
 * All rights reserved.                 
 *                                      
 *@file  INLEMouseEffectManager.h
 *@brief                                
 *@version 1.0                          
 *@author  yaoyj                       
 *@date    3/20/2017 15:10
 */

#ifndef _H_INLEMOUSEEFFECTMANAGER_H_
#define _H_INLEMOUSEEFFECTMANAGER_H_

#include "NLEType.h"                                                          
#include <Guiddef.h>                                                            
#include <objbase.h>                                                            

#include "INLETimelineBase.h"
#include "cMouseStreamCtrl.h"
                                                                                
//{96BE27DD-B8E4-F9CD-4D95-5CE8B83BFC0C}
DEFINE_GUID(CLSID_INLEMouseEffectManager, 0x96BE27DD, 0xB8E4, 0xF9CD, 0x4D, 0x95, 0x5C, 0xE8, 0xB8, 0x3B, 0xFC, 0x0C);                   
//{E51D060F-13C7-7272-FDB3-3EFAF75BCD70}
DEFINE_GUID(IID_INLEMouseEffectManager, 0xE51D060F, 0x13C7, 0x7272, 0xFD, 0xB3, 0x3E, 0xFA, 0xF7, 0x5B, 0xCD, 0x70);                         
class INLEMouseEffectManager :public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE AddEffectFilter(INLETimelineBase *pFilter, MouseEvent mouseEvent = MouseEvent_None, int level = 0) = 0;

	virtual int STDMETHODCALLTYPE EffectFilterCount() = 0;

	virtual HRESULT STDMETHODCALLTYPE GetEffectFilter(int index, INLETimelineBase **ppFilter) = 0;

	/**
	@brief ���ù������ű���
	@param scale ���ű�������0.2��ʾ20%
	@return ��׼����
	*/
	virtual HRESULT STDMETHODCALLTYPE SetMouseScale(double scale) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetMouseScale(double *pScale) = 0;

	/**
	@brief ���ù���͸����
	@param opacity ֵΪ0 - 1.0
	@return ��׼������
	*/
	virtual HRESULT STDMETHODCALLTYPE SetOpacity(double opacity) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetOpacity(double *pOpacity) = 0;

	/**
	@brief ���õ��������ʱ���ŵ������ļ�·��
	@param pSoundFilePath ȫ·��
	@return ��׼������
	*/
	virtual HRESULT STDMETHODCALLTYPE SetSoundFilePath(LPCWSTR pSoundFilePath) = 0;
};                                                                              


/**
�ýӿڽ���NLE�ڲ�ʹ��
*/
// {B08E7AC3-71C4-44A7-AA9B-98E82469EB35}
DEFINE_GUID(IID_INLEMouseEffectManagerInternal,
	0xb08e7ac3, 0x71c4, 0x44a7, 0xaa, 0x9b, 0x98, 0xe8, 0x24, 0x69, 0xeb, 0x35);

class INLEMouseEffectManagerInternal : public IUnknown
{
public:
	/**
	*@brief ����SourceTimeline
	*@param[in] pSourceTimeline
	*@return ��׼���
	*/
	virtual HRESULT STDMETHODCALLTYPE InstallSourceTimeline(INLETimelineBase *pSourceTimeline) = 0;
};

#endif //_H_INLEMOUSEEFFECTMANAGER_H_
