#pragma once
/**                                     
 * Copyright (c) 2016 Wondershare.inc   
 * All rights reserved.                 
 *                                      
 *@file  INLEDocumentSerialize.h
 *@brief                                
 *@version 1.0                          
 *@author  wangyue                       
 *@date    22/4/2016 14:38
 */

#include "NLEType.h"                                                          
#include <Guiddef.h>                                                            
#include <objbase.h>                                                            
#include "INLEXml.h"
#include "INLETimelineBase.h"                                                                          
 

// {7AB64C6D-0AC1-440B-9528-103693AED542}
DEFINE_GUID(CLSID_NLEDocumentSerialize,	0x7ab64c6d, 0xac1, 0x440b, 0x95, 0x28, 0x10, 0x36, 0x93, 0xae, 0xd5, 0x42);

// {9BC82634-1576-4BE1-A570-2DCE9A55534C}
DEFINE_GUID(IID_INLEDocumentSerialize,	0x9bc82634, 0x1576, 0x4be1, 0xa5, 0x70, 0x2d, 0xce, 0x9a, 0x55, 0x53, 0x4c);


/**
 *@brief 序列化接口
 */
class INLEDocumentSerialize :public IUnknown
{
public:
	virtual HRESULT __stdcall Save(INLETimelineBase* pTimeline, LPCWSTR pFileName) = 0;
	virtual HRESULT __stdcall Load(INLETimelineBase** pTimeline, LPCWSTR pFileName) = 0;

	virtual HRESULT __stdcall Save(INLETimelineBase* pTimeline, INLEXml *pArchive) = 0;
	virtual HRESULT __stdcall Load(INLETimelineBase** pTimeline, INLEXml *pArchive) = 0;
};                                                                              
