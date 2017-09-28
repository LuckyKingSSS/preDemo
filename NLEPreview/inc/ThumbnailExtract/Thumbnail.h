/* ### WS@H Project:NLE ### */
#pragma once
/***********************************************************************/
/**
* Copyright(c) Wondershare software Corporation
* All rights reserved.
*
* @file		Thumbnail.h
* @brief	Thumbnail类接口定义
* @class	
* @brief	
*  															
* 功能:	缩略图创建和管理 \n
* IDE:	Visual Studio 2008 \n
* 															
* @version	1.0.0.0
* @author	程伟
* @date		2010/08/06
*/
/***********************************************************************/
#include "..\\Type\\scombase.h"
#include "..\\Type\\COMMacro.h"

struct MEDIA_FRAME;


// {673E8AE7-0AA1-4916-B65D-0929E9AACE0E}
DEFINE_GUID(IID_IThumbnail, 
			0x673e8ae7, 0xaa1, 0x4916, 0xb6, 0x5d, 0x9, 0x29, 0xe9, 0xaa, 0xce, 0xe);
EXTERN_C const IID IID_IThumbnail;
MACRO_MIDL_INTERFACE(IThumbnail, "673E8AE7-0AA1-4916-B65D-0929E9AACE0E")
: public IUnknown
{
	virtual bool __stdcall IsThumbImageNULL()	= 0;

	virtual HRESULT __stdcall CreateThumbByFrame(const MEDIA_FRAME& mediaFrame)	= 0;
	virtual HRESULT __stdcall CreateThumbByFile(const wchar_t* wszThumbPath)	= 0;
	virtual HRESULT __stdcall CreateThumbByData(
		const LPBITMAPINFOHEADER pbiHedader, 
		const LPBYTE pData)	= 0;

	virtual HRESULT __stdcall GetThumbFilePath(BSTR* pPath)	= 0;
	
	virtual HRESULT __stdcall GetThumbData(
		LPBITMAPINFOHEADER* ppbiHedader, 
		LPBYTE* ppData)	= 0;
	virtual HRESULT __stdcall GetThumbSize(int* pnWidth, int* pnHeight)	= 0;
	virtual HRESULT __stdcall SaveThumbnail(const wchar_t* wszFilePath)	= 0;

	virtual HRESULT __stdcall Clone(IThumbnail **ppObj) = 0;
};

