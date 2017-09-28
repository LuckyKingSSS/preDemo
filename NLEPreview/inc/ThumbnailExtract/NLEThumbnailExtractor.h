/* ### WS@H Project:NLE ### */
#ifndef NLEPLATFORM_THUMBNAILEXTRACTOR_H_
#define NLEPLATFORM_THUMBNAILEXTRACTOR_H_

#include "..\Type\scombase.h"
#include "..\Type\COMMacro.h"
//#include "..\\COM\\NLEInterface.h"

interface IMediaStream;
interface IThumbnail;


// {1EA196DC-741E-4361-BCD2-C7EDC9D68FE9}
DEFINE_GUID(IID_INLEThumbnailExtractor,
			0x1ea196dc, 0x741e, 0x4361, 0xbc, 0xd2, 0xc7, 0xed, 0xc9, 0xd6, 0x8f, 0xe9);
EXTERN_C const IID IID_INLEThumbnailExtractor;
MACRO_MIDL_INTERFACE(INLEThumbnailExtractor, "1EA196DC-741E-4361-BCD2-C7EDC9D68FE9")
:public IUnknown
{
	virtual HRESULT __stdcall SetVideoInput(IMediaStream* pStream, int nMode) = 0;
	virtual HRESULT __stdcall GetThumbnail(IThumbnail** ppObj) = 0;
	virtual HRESULT __stdcall SetVideoStartTime(LONG nStartTime) = 0;	//设置缩略图获取的流开始时间

};

namespace NLEThumbnailExtractorLib{

	extern "C" HRESULT __stdcall CreateNLEThumbExtractorInstance(INLEThumbnailExtractor** ppvObj);
};

#endif
