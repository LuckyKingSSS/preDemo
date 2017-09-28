/**                                     
 * Copyright (c) 2016 Wondershare.inc   
 * All rights reserved.                 
 *                                      
 *@file  INLEMouseSetting.h
 *@brief                                
 *@version 1.0                          
 *@author  yaoyj                       
 *@date    3/3/2017 14:21
 */
#ifndef _H_INLEMOUSESETTING_H_
#define _H_INLEMOUSESETTING_H_

#include "NLEType.h"                                                          
#include <Guiddef.h>                                                            
#include <objbase.h>                                                            

#include "NLEComPtr.h"
                          
class INLEProperties;

//{4FFE528E-0136-CF1B-2208-C7B204849F52}
DEFINE_GUID(CLSID_INLEMouseSetting, 0x4FFE528E, 0x0136, 0xCF1B, 0x22, 0x08, 0xC7, 0xB2, 0x04, 0x84, 0x9F, 0x52);                   
//{D4ECA24E-0C60-F859-E0F6-384DAD443885}
DEFINE_GUID(IID_INLEMouseSetting, 0xD4ECA24E, 0x0C60, 0xF859, 0xE0, 0xF6, 0x38, 0x4D, 0xAD, 0x44, 0x38, 0x85);                         
class INLEMouseSetting :public IUnknown
{
public:
	/**
	*@brief ����һ����Ƶ�������ʾ��Ϣ
	*@param[in] prop �����Ϣ����������Ϣ�� NLEKey.h�е�namespace MouseSegmentInfo	
	*@return ��׼����
	*/
	virtual HRESULT AddSegmentInfo(NLEComPtr<INLEProperties> prop) = 0;

	/**
	*@brief ��ȡָ��λ�õ����������Ϣ
	*@param[in] nFrameIndex ָ����λ�ã�������ļ���ͷ
	*@param[out] ppProp ���ص�ǰ�����Ϣ�����ã���û�����ã����滻������ΪNULL
	*@return ��׼����
	*/
	virtual HRESULT GetSegmentInfo(NLEFrameIndex nFrameIndex, INLEProperties **ppProp) = 0;

	virtual HRESULT RemoveAllSegments(void) = 0;
};                                                                              



#endif //_H_INLEMOUSESETTING_H_
