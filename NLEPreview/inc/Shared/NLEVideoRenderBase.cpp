#include "stdafx.h"

#include <algorithm>
#include <functional>

#include "NLEMatrix.h"
#include "NLEMatrix.cpp"

#include "NLEVideoRenderBase.h"
#include "INLEFrameControl.h"
#include "INLEFrameOperate.h"
#include "INLETimelineBase.h"
#include "NLEComPtr.h"
#include "NLECommon.h"
#include "NLEMacroDefine.h"

#include "NLEKey.h"
#include "NLEKeyShortcut.h"
#include "INLEFactory.h"

#include "INLEVideoFilter.h"
#include "INLEFrameRateCalculator.h"
#include "NLECommon_Const.h"
#include "NLEComError.h"

using namespace NLEKey::Transition;
using namespace NLEKey::Motion;
using namespace NLECommon;
using namespace NLECommon::Const;

PROPERTY_LISTEN_BEGIN(CNLEVideoRenderBase)
PROPERTY_LISTEN_END

CNLEVideoRenderBase::CNLEVideoRenderBase(IUnknown *pUnkOuter) :CNLERenderBase(pUnkOuter)
{
	HRESULT hr = E_NLE_UNEXPECTED;
	m_pRegionFrame = NULL;
	m_nClipCount = 0;
	m_pRenderFrame = NULL;
	m_pRegionFrame = NULL;
	m_pInternalFrame = NULL;
	
	PROPERTY_LISTENERS_REGISTER(CNLEVideoRenderBase);

}
 

CNLEVideoRenderBase::~CNLEVideoRenderBase()
{
}

STDOVERRIDEMETHODIMP CNLEVideoRenderBase::NonDelegatingQueryInterface(REFIID riid, LPVOID *ppObj)
{
	if (riid == IID_INLEVideoRender)
	{
		return CNLERenderBase::NonDelegatingQueryInterface(IID_INLERender, ppObj);
	}
	return CNLERenderBase::NonDelegatingQueryInterface(riid, ppObj);
}

HRESULT __stdcall  CNLEVideoRenderBase::Seek(NLEFrameIndex nFrameIndex, NLEFrameIndex *pRealFrameIndex/* = NULL*/)
{
	LOGGER_INFO_(L"seek pos:%d", nFrameIndex);

	NLEFrameIndex retIdx = 0;
	HRESULT hr = CNLERenderBase::Seek(nFrameIndex, &retIdx);
	if (pRealFrameIndex != NULL)
	{
		*pRealFrameIndex = retIdx;
	}
	NLEComPtr<INLETimelineBase> pTimeline = GetTimeline();
	hr = pTimeline->GetClipCount(&m_nClipCount); CHECK(hr);
// 	LOGGER_INFO_(L"sv %d", nFrameIndex);
	return hr;
}

HRESULT __stdcall CNLEVideoRenderBase::Forward(INT nFrameCount, INT *pRealFrameCount)
{
	NLEFrameIndex retIdx = 0;
	HRESULT hr = CNLERenderBase::Forward(nFrameCount, &retIdx);
	if (pRealFrameCount != NULL)
	{
		*pRealFrameCount = retIdx;
	}
	
// 	LOGGER_INFO_(L"fv %d, %d", GetOffset(), nFrameCount);

	return hr;
}

HRESULT __stdcall CNLEVideoRenderBase::Prepare(INLEFrame* pGraphics)
{
	// 视频渲染的Prepare，没有调用基类的CNLERenderBase::Prepare(pFrame)
	// 所以，实际上需要应用保证在Prepare之前，至少调用一次Seek/Forward，以保证渲染列表的正确性

	HRESULT hr = E_NLE_UNEXPECTED;
	m_pRenderFrame = NULL;

	RETURN_IF_FALSE(m_bNotEndOfTimeline, S_OK); // 如果已经超出范围，则直接返回

	NLE_ASSERT(pGraphics);
	NLEPropDecorator pTimelineProp = NLECommon::NLEGetProperties(this);

	NLESize curGrahicsSize = FRAME_SIZE(pGraphics);
	m_bGraphicsChanged = !m_oGraphicsSize.Equals(curGrahicsSize);
	m_oGraphicsSize = curGrahicsSize;
	
	m_pRegionFrame = this->GetRegionFrame(TRUE);
	if(NULL == m_pRegionFrame)
	{
		LOGGER_ERROR_(L"Failed to create region frame "); _ASSERT(FALSE); 
		return E_OUTOFMEMORY;
	}
// 	FRAME_IMAGE(m_pRegionFrame)->FillColor(NLECommon::Const::Color::BLACK_TRANSPARENT);

	if (FAILED(hr = this->PrepareInternal(&m_pRenderFrame)))
	{
		LOGGER_ERROR_(L"Failed to prepare intenal"); CHECK(hr); 
		return hr;
	}

	CNLERenderBase::Prepare(m_pRenderFrame);

// 	// 处理子片段的准备情况
// 	INT bConCurrency = pTimelineProp[kRender_PrepareConcurrency]; //是否使用并发
// 	if (m_nClipCount > 0 && FAILED(hr = this->ConCurrencyPrepare(m_pRenderFrame, bConCurrency) ) )
// 	{
// 		LOGGER_ERROR_(L"concurrency prepare prepare failed"); CHECK(hr);
// 		return hr;
// 	}

	if (FAILED(hr = this->WillPostProcess(m_pRenderFrame, m_pRegionFrame, pTimelineProp)))
	{
		LOGGER_ERROR_(L"Failed to will postprocess"); CHECK(hr);
		return hr;
	}

	if (FAILED(hr = this->WillCompose(m_pRegionFrame, pGraphics) ) )
	{
		LOGGER_ERROR_(L"Failed to will compose"); CHECK(hr);
		return hr;
	}

	return hr;
}

HRESULT __stdcall CNLEVideoRenderBase::Render(INLEFrame* pGraphics)
{
	HRESULT hr = E_NLE_UNEXPECTED;

	do
	{
		BREAK_IF_FALSE(m_bNotEndOfTimeline); // 如果已经超出范围，则直接返回
		BREAK_IF_NULL(m_pRenderFrame);
		_ASSERT(m_pRenderFrame);
		_ASSERT(m_pRegionFrame);
		_ASSERT(pGraphics);

		hr = this->RenderInternal(m_pRenderFrame); CHECK(hr);
		BREAK_IF_FAILED(hr);

		// 递归自己的子片段，将自己的子片段的数据渲染到m_pRenderFrame
		hr = CNLERenderBase::Render(m_pRenderFrame);
		BREAK_IF_FAILED(hr);

		//保留透明度
		NLEComPtr<INLEImage> pSrcImage = m_pRenderFrame->GetImage();		
		if (pSrcImage && !pSrcImage->IsOpaque())
		{
			NLEComPtr<INLEFrameOperate> pOp = NULL;
			QUERY_INTERFACE(m_pRegionFrame, IID_INLEFrameOperate, (void**)&pOp); NLE_ASSERT(pOp);
			pOp->SetOpaque(FALSE);
		}

		hr = this->DoPostProcess(m_pRenderFrame, m_pRegionFrame); CHECK(hr);
		BREAK_IF_FAILED(hr);

		hr = this->DoCompose(m_pRegionFrame, pGraphics); CHECK(hr);
		BREAK_IF_FAILED(hr);
	} while (FALSE);

	// 计算帧的时间戳， 不同的片段，最终出来的时间戳进行连续统一
	LONGLONG pts = 0, dur = 0;
	GetCurrentVideoFrameTimestamp(pGraphics, pts, dur);
	pGraphics->SetTimestamp(pts, dur);

	NLEComPtr<INLEFrameOperate> pFrameOperator = NULL;
	hr = QUERY_INTERFACE(pGraphics, IID_INLEFrameOperate, &pFrameOperator);
	pFrameOperator->SetMediaFrameNumber(this->GetOffset());

	m_pRenderFrame = NULL;
	m_pPostRequest->Reset();
	
	return hr;
}

HRESULT __stdcall CNLEVideoRenderBase::Cleanup()
{	
	HRESULT hr =  CNLERenderBase::Cleanup();
	m_pImageProc = NULL;
	m_pRegionFrame = NULL;
	m_oTransitioner.Reset();

	return hr;
}

HRESULT CNLEVideoRenderBase::WillCompose(INLEFramePtr pCurFrame, INLEFramePtr pGraphics)
{
	m_oTransitioner.SetRender(this);
	m_oTransitioner.SetFrom(pGraphics);
	m_oTransitioner.SetTo(pCurFrame);
	m_oTransitioner.SetOut(pGraphics);
	m_oTransitioner.CheckTransition();
	if(m_oTransitioner.Enable() )
	{
		return S_OK;
	}
	m_oTransitioner.Reset();

	if (NULL == GetImageProc())
	{
		LOGGER_ERROR_(L"Failed to get image proc"); _ASSERT(FALSE);
		return E_NLE_UNEXPECTED;
	}

	return S_OK;
}

HRESULT CNLEVideoRenderBase::DoCompose(INLEFramePtr pCurFrame, INLEFramePtr pGraphics)
{
	if (m_oTransitioner.Enable())
	{
		return	m_oTransitioner.DoTransition();
	}

	_ASSERT(GetImageProc());

	NLEComPtr<INLEImage> pCurrentImage = pCurFrame->GetImage();
	NLEComPtr<INLEImage> pGraphicsImage = pGraphics->GetImage();
	if (pCurrentImage->IsOpaque() )
	{
		GetImageProc()->BitBlt(pGraphicsImage, pCurrentImage,
			m_rcRegion.X,
			m_rcRegion.Y,
			m_rcRegion.Width,
			m_rcRegion.Height);		
	}
	else
	{
		GetImageProc()->AlphaComp(pGraphicsImage,
			pCurrentImage,
			m_rcRegion.X,
			m_rcRegion.Y,
			m_rcRegion.Width,
			m_rcRegion.Height);
	}
	return S_OK;
}

HRESULT CNLEVideoRenderBase::PrepareInternal(INLEFrame** ppOutFrame)
{	
	if (PropChanged() )
	{
		NLEPropDecorator pProp = NLECommon::NLEGetProperties(this);
		NLERectF rcRender = pProp[kRender_Region];

		rcRender.Scale((NLEREAL)m_oGraphicsSize.Width, (NLEREAL)m_oGraphicsSize.Height);
		NLERect rcRegion;
		rcRender.GetRect(&rcRegion);
		rcRegion.Width = ALIGIN(rcRegion.Width, 4);
		if (NULL == m_pInternalFrame ||
			!FRAME_SIZE(m_pInternalFrame).Equals(NLESize(rcRegion.Width, rcRegion.Height)))
		{
			m_pInternalFrame = CreateVideoFrame(rcRegion.Width, rcRegion.Height); _ASSERT(m_pInternalFrame);
			if (m_pInternalFrame == NULL)
			{
				LOGGER_ERROR_(L"Failed to create video frame, size:(%d, %d)", rcRegion.Width, rcRegion.Height);
				return E_OUTOFMEMORY;
			}
		}
	}
	_ASSERT(m_pInternalFrame);

	m_pInternalFrame->QueryInterface(IID_INLEFrame, (LPVOID*)ppOutFrame);
	(*ppOutFrame)->GetImage()->FillColor(Color::BLACK_OPAQUE);

 	return S_OK;
}

HRESULT CNLEVideoRenderBase::RenderInternal(INLEFrame* ppOutFrame)
{
	return S_OK;
}

NLEComPtr<INLEFrame> CNLEVideoRenderBase::CreateVideoFrame(int nWidth, int nHeight)
{
	NLEComPtr<INLEFactory> pFactory = NULL;
	HRESULT hr = NLECommon::GetInterface(CLSID_NLEFactory, NULL, 0, IID_INLEFactory, (LPVOID *)&pFactory);
	if (SUCCEEDED(hr) )
	{
		return pFactory->CreateNLEVideoFrame(nWidth, nHeight);
	}
	NLE_ASSERT(0);

	return NULL;
}

NLEComPtr<INLEImageProc> &CNLEVideoRenderBase::GetImageProc()
{
	HRESULT hr = E_OUTOFMEMORY;
	if (m_pImageProc == NULL)
	{
		if (FAILED(hr = NLECommon::GetInterface(CLSID_NLEImageProc, NULL, 0, IID_INLEImageProc, (LPVOID*)&m_pImageProc)))
		{
			LOGGER_ERROR_(L"Failed to create imageproc instance "); _ASSERT(FALSE);			
		}
	}
	return m_pImageProc;
}

NLEComPtr<INLERender> CNLEVideoRenderBase::GetRender(INLETimelineBase *clip)
{
	NLEComPtr<INLERender> pVideoRender = NULL;

	NLE_ASSERT(clip != NULL);

	HRESULT hr = clip->GetRender(NULL, &pVideoRender);
	
	return pVideoRender;
}

BOOL CNLEVideoRenderBase::IsAudioRender()
{
	return FALSE;
}

void CNLEVideoRenderBase::UpdateNeedRenderList(NLEFrameIndex nFrameOffset)
{
	// 检查遮盖的情况

	m_lstNeedRenders.clear();

	// 倒序{沿Z序负方向}查询所有子层的是否有完全覆盖的情况，以减少不必要的处理
	BOOL seek_uncovered = FALSE;
	NLEFrameIndex nNextChildFrameOffset = FRAMEINDEX_MIN;
	for (auto render = m_lstCurrentRenders.rbegin(); render != m_lstCurrentRenders.rend(); render++)
	{

		// 存在强制转换{被逼的，inlerender不能拿到自己的tl}
		NLEComPtr<INLETimelineBase> pClip = ((CNLERenderBase *)(INLERender *)*render)->GetTimeline();
		NLEPropDecorator propClip = NLEGetProperties(pClip);

		INT bHidden = FALSE;
		if (SUCCEEDED(propClip.GetInt(kRender_Hidden, &bHidden)) && bHidden)
		{
			// 明确指定该片段隐藏，则继续测试下一片断
			continue;
		}

		INT video_enabled = FALSE;
		if (FAILED(propClip.GetInt(kRender_VideoEnable, &video_enabled)) || !video_enabled)
		{
			// 视频流禁用
			continue;
		}

		INT has_video = FALSE;
		if (FAILED(propClip.GetInt(kSource_HasVideoStream, &has_video)) || !has_video)
		{
			// 视频流不存在
			continue;
		}

		NLERational framerate = (CNLEValue)propClip[NLEKey::Render::kRender_Framerate];

		NLERange rngClip = (CNLEValue)propClip[kRender_RangFrameNumber];
		NLEFrameIndex pos = (CNLEValue)propClip[kRender_Position];

		if (nFrameOffset < pos || nFrameOffset >= pos + rngClip.Count())
		{
			// 不在该片段的渲染区间，则继续测试下一片断
			continue;
		}

		if (seek_uncovered)
		{
			// 将需要定位的，记录到列表里面，待后续一次性处理

			auto found = std::find_if(m_lstSeekRenders.begin(), m_lstSeekRenders.end(), [&](std::pair<INLERenderPtr, NLEFrameIndex> const &v) {
				return v.first == *render;
			});

			NLEFrameIndex childOffset = (*render)->GetOffset();
			if (nNextChildFrameOffset > childOffset
				&& nNextChildFrameOffset < pos + rngClip.Count())
			{
				// 部分覆盖了，则需要定位

				NLEFrameIndex seek_pos = nNextChildFrameOffset - pos;

				if (found == m_lstSeekRenders.end())
				{
					m_lstSeekRenders.push_back(std::make_pair(*render, seek_pos));
				}
				else
				{
					// 已经在定位列表的，为了避免重复定位，仅改变位置
					found->second = seek_pos;
				}
			}
			else if (found != m_lstSeekRenders.end())
			{
				// 完全覆盖了，则不需要定位了
				m_lstSeekRenders.erase(found);
			}
			continue;
		}

		(*render)->SendCommand(RENDER_CMD_ENTER_RENDERING, nFrameOffset);

		m_lstNeedRenders.push_back(*render);

		if (m_lstCurrentRenders.size() <= 1)
		{
			break;
		}

		// 判断是否覆盖其他的层
		// 当前判断准则是：
		// 1、kRender_Region必须是NLERectF(0, 0, 1.0, 1.0)
		// 2、不存在动画或者动画已经结束{动画结束会保持最后一帧状态，即完全遮盖}
		// 3、如果设置了kRender_NoCover标识，且为1，则不检查遮盖
		// 4、如果设置了kRender_FullCover标识，且为1，也是遮盖
		// 4、当前没有考虑Alpha通道的问题！！！

		INT bNoCover = FALSE;
		if (SUCCEEDED(propClip.GetInt(kRender_NoCover, &bNoCover)) && bNoCover)
		{
			// 明确指定不检查覆盖
			continue;
		}

		INT bFullCover = FALSE;
		if (!(SUCCEEDED(propClip->GetInt(kRender_FullCover, &bFullCover)) && bFullCover))
		{
			// 没有明确指定覆盖下层

			NLERectF rcRegion = propClip[kRender_Region];
			if (!rcRegion.Equals(NLERectF(0, 0, 1.0, 1.0)))
			{
				// 渲染区域不符合覆盖条件
				continue;
			}

// 			if (m_pPostRequest != NULL) // 这家伙的值，在这里始终是初始值。。。。
// 			{
// 				NLEMatrix::CNLEAffineMatrix matrix = *(m_pPostRequest->GetMatrix());
// 
// 				PostTransform *pTransform = (PostTransform *)m_pPostRequest->GetTransform();
// 				if (pTransform->fRotate != 0
// 					|| pTransform->ptfTranslate.X - pTransform->sfScale.Width / 2 > 0 || pTransform->ptfTranslate.Y - pTransform->sfScale.Height / 2 > 0
// 					|| pTransform->ptfTranslate.X + pTransform->sfScale.Width / 2 < 1 || pTransform->ptfTranslate.Y + pTransform->sfScale.Height / 2 < 1)
// 				{
// 					// 存在旋转、或者缩放的情况
// 					continue;
// 				}
// 			}

			NLEBOOL bMotionEnabled = propClip[NLEKey::Motion::kMotion_Enable];
			NLEBOOL bMotioning = FALSE;
			if (bMotionEnabled)
			{
				// 由时长和帧率，计算动画的帧数
				NLERange rngMSec = (CNLEValue)propClip[kMotion_RangeTime];

				INT nFrameStart = (INT)(rngMSec.Start *framerate.Value() / 1000);
				INT nFrameEnd = nFrameStart + (INT)(rngMSec.End *framerate.Value() / 1000);

				bMotioning = ((nFrameOffset - pos) >= nFrameStart) && ((nFrameOffset - pos) < nFrameEnd);
			}

			if (bMotionEnabled && bMotioning)
			{
				// 在动画的过程中，不算覆盖
				continue;
			}

			WCHAR szMaskFile[256];
			if (SUCCEEDED(propClip->GetString(NLEKey::Render::kRender_MaskFile, szMaskFile, 256)) && wcslen(szMaskFile) > 0)
			{
				// 存在蒙版
				continue;
			}

			INT bTranstition = 0; //存在转场
			if (SUCCEEDED(propClip->GetInt(NLEKey::Transition::kTransition_Enable, &bTranstition)) && bTranstition)
			{
				continue;
			}
		}

		// 已经覆盖
		nNextChildFrameOffset = pos + rngClip.Count(); // 完全覆盖的下一帧
		if ((nNextChildFrameOffset - nFrameOffset) < (int)(m_nCoveredSeekMSec * framerate.Value() / 1000))
		{
			// 没超前指定时间，不要seek，以免因为seek造成卡顿
			break;
		}

		seek_uncovered = TRUE; // 从下一轮开始，只进行定位操作
	}
	// 需要反序以保证正确的渲染顺序
	std::reverse(m_lstNeedRenders.begin(), m_lstNeedRenders.end());
}

TIMELINE_RENDER_LIST& CNLEVideoRenderBase::GetNeedRenderList()
{
	return m_lstNeedRenders;
}

HRESULT CNLEVideoRenderBase::ConCurrencyPrepare(NLEComPtr<INLEFrame> pGraphics, BOOL bConcurrentcy)
{
	HRESULT hr = S_OK;
	BOOL bPrepareConcurrency = bConcurrentcy;

	if (this->GetNeedRenderList().size() > 1 && bPrepareConcurrency) //并行处理
	{
		if (m_pPrepareTask == NULL) {
			hr = NLECommon::GetInterface(CLSID_NLEPrepareTask, NULL, 0, IID_INLEPrepareTask, (LPVOID*)&m_pPrepareTask);
			RETURN_IF_FAILED(hr, hr);
		}

		hr = m_pPrepareTask->Prepare(this->GetNeedRenderList(), m_pRenderFrame);
	}
	else
	{
		std::vector<NLEComPtr<INLERender> >::iterator iter = this->GetNeedRenderList().begin();
		while (iter != this->GetNeedRenderList().end())
		{
			hr = (*iter)->Prepare(m_pRenderFrame);
			iter++;
		}
	}
	return hr;
}

NLEComPtr<INLEFrame> CNLEVideoRenderBase::GetRegionFrame(BOOL bCreateIfNotExists /*= TRUE*/)
{
	if (FALSE == bCreateIfNotExists)
	{
		return m_pRegionFrame;
	}

	if (PropChanged() || NULL == m_pRegionFrame || m_bGraphicsChanged)
	{
		NLEPropDecorator pProp = NLECommon::NLEGetProperties(this);
		NLERectF rcRender = pProp[kRender_Region];
		NLERect  rcOld = m_rcRegion;

		rcRender.Scale((NLEREAL)m_oGraphicsSize.Width, (NLEREAL)m_oGraphicsSize.Height);
		rcRender.GetRect(&m_rcRegion);

		if (NULL == m_pRegionFrame ||
			!FRAME_SIZE(m_pRegionFrame).Equals(NLESize(m_rcRegion.Width, m_rcRegion.Height)))
		{
			m_pRegionFrame = CreateVideoFrame(m_rcRegion.Width, m_rcRegion.Height); _ASSERT(m_pRegionFrame);			
		}

		if (!rcOld.Equals(m_rcRegion))
		{
			LOGGER_INFO_(L"render region change:%s -->%s ", rcOld.toString().c_str(), m_rcRegion.toString().c_str());
		}
	}
	_ASSERT(m_pRegionFrame);

	return m_pRegionFrame;
}


scombase::CUnknown* CALLBACK CreateVideoRenderBaseInstance(LPUNKNOWN pUnkOuter, HRESULT *phr)
{
	HRESULT hr = E_OUTOFMEMORY;
	scombase::CUnknown* pNewObj = (scombase::CUnknown*)new CNLEVideoRenderBase(pUnkOuter);
	if (pNewObj) {
		pNewObj->NonDelegatingAddRef();
		hr = S_OK;
	}
	if (phr) {
		*phr = hr;
	}
	return pNewObj;
}