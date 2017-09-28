#include "stdafx.h"
#include "OperatorBase.h"
#include "TrackBase.h"
#include "ClipBase.h"
#include "TrackManager.h"
//#include "NLETimeline.h"
OperatorBase::OperatorBase()
:m_pRootTimeline(nullptr)
{

}

OperatorBase::~OperatorBase()
{

}

void OperatorBase::SetRootTimeline(NLETimeline *pRootTimeline)
{
	m_pRootTimeline = pRootTimeline;
}

ClipOperatorBase::ClipOperatorBase(TrackBase *pOwner)
: m_pOwner(pOwner)
{
	
}

ClipOperatorBase::~ClipOperatorBase()
{

}

int ClipOperatorBase::ItemCount()
{
	return m_listClips.size();
}

void ClipOperatorBase::AddClip(ClipBase *pClip)
{
	int nStart = pClip->GetStartAtTrack();
	int insertIndex = GetInsertIndex(nStart);
	m_listClips.insert(insertIndex, pClip);
	m_pRootTimeline->AddClip(pClip->GetSrcTimeline(),nStart,m_pOwner->GetIndex());
	m_pRootTimeline->SetClipRange(pClip->GetSrcTimeline(), pClip->GetSrcTimeline()->GetTrimin(), pClip->GetSrcTimeline()->GetTrimout());
}

void ClipOperatorBase::RemoveClip(ClipBase *pClip)
{
	m_listClips.removeOne(pClip);
	m_pRootTimeline->RemoveClip(pClip->GetSrcTimeline());
}

int ClipOperatorBase::MoveClip(ClipBase* pClip, ClipOperatorBase* pTo, int nTo)
{
	int nOrigin = pClip->GetStartAtTrack();
	pClip->SetStartAtTrack(nTo);
	m_pRootTimeline->SetClipPos(pClip->GetSrcTimeline(), nTo);
	//if (this == pTo) return nOrigin;
	RemoveClip(pClip);
	pTo->AddClip(pClip);
	return nOrigin;
}

ClipBase* ClipOperatorBase::CopyClip(ClipBase* pClip, ClipOperatorBase* pTo, int nTo)
{
	ClipBase* pNewClip = pClip->Clone();
	if (!pNewClip) return nullptr;
	pNewClip->SetStartAtTrack(nTo);
	pTo->AddClip(pNewClip);
	return pNewClip;
}

ClipBase* ClipOperatorBase::SplitClip(ClipBase* pClip, int nOffset)
{
	if (pClip->GetType() == ClipBase::ClipType_Complex) return nullptr;
	SimplexClip *pSimplexClip = dynamic_cast<SimplexClip *>(pClip);
	if (!pSimplexClip) return nullptr;

	SimplexClip *pSimplexClip2 = (SimplexClip *)pSimplexClip->Clone();


	NLETimeline *pSrc1 = pSimplexClip->GetSrcTimeline();
	if (!pSrc1) return nullptr;
	m_pRootTimeline->SetClipRange(pSrc1, pSrc1->GetTrimin(), pSrc1->GetTrimin() + nOffset - 1);
	
	NLETimeline *pSrc2 = pSimplexClip2->GetSrcTimeline();
	if (!pSrc2) return nullptr;
	pSimplexClip2->SetStartAtTrack(pSimplexClip->GetStartAtTrack() + nOffset);
	
	int nIndex = GetClipIndex(pSimplexClip);
	m_listClips.insert(nIndex + 1,pSimplexClip2);
	m_pRootTimeline->AddClip(pSrc2, pSimplexClip->GetStartAtTrack() + nOffset, m_pOwner->GetIndex());
	m_pRootTimeline->SetClipRange(pSrc2, pSrc2->GetTrimin() + nOffset, pSrc2->GetTrimout());

	m_pOwner->GetTrackManager()->SelectClip(m_pOwner->GetIndex(), pSimplexClip2->GetStartAtTrack());

	return pSimplexClip2;
}

void ClipOperatorBase::SplitClipEx(ClipBase *pClip, ClipBase *pNewClip)
{
	NLETimeline *pClipSrc = pClip->GetSrcTimeline();

	m_pRootTimeline->SetClipRange(pClipSrc, pClipSrc->GetTrimin(), pClip->GetLenAtTrack() - pNewClip->GetLenAtTrack() -1);

	m_pRootTimeline->RemoveClip(pNewClip->GetSrcTimeline());
	int nIndex = GetClipIndex(pClip);
	m_listClips.insert(nIndex + 1, pNewClip);
}

void ClipOperatorBase::UndoSplitClip(ClipBase* pClip1, ClipBase* pClip2)
{
	NLETimeline *pSrc = pClip1->GetSrcTimeline();
	if (!pSrc) return;
	 
	int nLen1 = pClip1->GetLenAtTrack();
	int nLen2 = pClip2->GetLenAtTrack();

	m_pRootTimeline->SetClipRange(pSrc, pSrc->GetTrimin(), nLen1 + nLen2 - 1);
	m_pRootTimeline->RemoveClip(pClip2->GetSrcTimeline());

	m_listClips.removeOne(pClip2);
	m_pOwner->GetTrackManager()->SelectClip(m_pOwner->GetIndex(), pClip1->GetStartAtTrack());
}

std::tuple<int, int> ClipOperatorBase::AdjustClip(ClipBase* pClip, int nStartPos, int nLen)
{
	if (pClip->GetType() == ClipBase::ClipType_Complex) return std::tuple<int, int>();
	SimplexClip *pSimplexClip = dynamic_cast<SimplexClip *>(pClip);
	if (!pSimplexClip) return std::tuple<int, int>();

	int nOldLen = pSimplexClip->GetLenAtTrack();
	int nOldStartPos = pSimplexClip->GetStartAtTrack();
	
	int nDelta = nStartPos - nOldStartPos;

	NLETimeline *pSrc = pSimplexClip->GetSrcTimeline();
	if (!pSrc) return std::tuple<int, int>();

	int nNewTrimin = pSrc->GetTrimin() + nDelta;
	int nNewLen = nLen;
	if (pClip->GetType() == ClipBase::ClipType_Effect)
	{
		m_pRootTimeline->SetClipRange(pSrc, nStartPos, nStartPos + nNewLen - 1);
	}
	else
	{
		m_pRootTimeline->SetClipRange(pSrc, nNewTrimin, nNewTrimin + nNewLen - 1);
	}
	m_pRootTimeline->SetClipPos(pSrc, nStartPos);
	pSimplexClip->SetStartAtTrack(nStartPos);

	return std::make_tuple(nOldStartPos, nOldLen);
}

void ClipOperatorBase::CropClip(ClipBase* pClip, const QRectF &region)
{
	pClip->GetSrcTimeline()->SetCropRegion(region);
}

ClipBase* ClipOperatorBase::GetClip(int nClipIndex)
{
	if (nClipIndex < 0 || nClipIndex >= ItemCount()) return nullptr;
	return m_listClips[nClipIndex];
}

ClipBase* ClipOperatorBase::GetPreClip(ClipBase* pClip)
{
	if (!m_listClips.contains(pClip)) return nullptr;
	int nIndex = m_listClips.indexOf(pClip);
	if (nIndex == 0) return nullptr;
		
	return m_listClips[nIndex - 1];
}

ClipBase* ClipOperatorBase::GetNextClip(ClipBase* pClip)
{
	if (!m_listClips.contains(pClip)) return nullptr;
	int nIndex = m_listClips.indexOf(pClip);
	if (nIndex >= ItemCount() - 1) return nullptr;
	return m_listClips[nIndex + 1];
}

ClipList ClipOperatorBase::GetClips()
{
	return m_listClips;
}

TrackBase *ClipOperatorBase::GetOwnerTrack()
{
	return m_pOwner;
}

int ClipOperatorBase::GetInsertIndex(int nPos)
{
	int nCnt = ItemCount();
	if (nCnt <= 0) return 0;

	int nIndex = 0;
	if (nCnt == 1)
	{
		ClipBase* pClip = m_listClips.at(0);
		if (nPos < pClip->GetStartAtTrack())
		{
			nIndex = 0;
		}
		else
		{
			nIndex = 1;
		}
		return nIndex;
	}

	for (int i = 0; i < nCnt - 1;++i)
	{
		ClipBase* pClip1 = m_listClips.at(i);
		ClipBase* pClip2 = m_listClips.at(i + 1);
		if (i == 0 && nPos < pClip1->GetStartAtTrack())  //第一个
		{
			nIndex = i;
			break;
		}
		else if (i == nCnt - 2 && nPos > pClip2->GetStartAtTrack() + pClip2->GetLenAtTrack() - 1)  //最后一个
		{
			nIndex = i + 2;
			break;
		}
		else if (nPos > pClip1->GetStartAtTrack() + pClip1->GetLenAtTrack() - 1 && nPos < pClip2->GetStartAtTrack())
		{
			nIndex = i + 1;
			break;
		}
		else if ( (nPos >= pClip1->GetStartAtTrack() && nPos<= pClip1->GetStartAtTrack() + pClip1->GetLenAtTrack() -1)
			
			|| (nPos >= pClip2->GetStartAtTrack() && nPos <= pClip2->GetStartAtTrack() + pClip2->GetLenAtTrack() -1))
		{
			nIndex = nCnt - 1;
			break;
		}
	}
	return nIndex;
}

int ClipOperatorBase::GetClipIndex(ClipBase* pClip)
{
	for (int i = 0; i < ItemCount();++i)
	{
		if (m_listClips[i] == pClip)
			return i;
	}
	return -1;
}

/************************************************************************/
/*            VedioClipOperator                                             */
/************************************************************************/
VedioClipOperator::VedioClipOperator(TrackBase *pOwner)
:ClipOperatorBase(pOwner)
{

}

VedioClipOperator::~VedioClipOperator()
{

}

/************************************************************************/
/*            AudioClipOperator                                             */
/************************************************************************/

AudioClipOperator::AudioClipOperator(TrackBase *pOwner)
:ClipOperatorBase(pOwner)
{

}

AudioClipOperator::~AudioClipOperator()
{

}

/************************************************************************/
/*            EffectClipOperator                                             */
/************************************************************************/
EffectClipOperator::EffectClipOperator(TrackBase *pOwner)
:ClipOperatorBase(pOwner)
{

}

EffectClipOperator::~EffectClipOperator()
{

}


/************************************************************************/
/*            TrackOperator                                             */
/************************************************************************/
TrackOperator::TrackOperator()
{

}

TrackOperator::~TrackOperator()
{

}

void TrackOperator::Init(TrackManager *pTrackManager)
{
	TrackBase* pVedioTrack = pTrackManager->CreateTrack(TrackBase::TrackType_Vedio);
	pVedioTrack->SetIndex(0);
	TrackBase* pEffectTrack = pTrackManager->CreateTrack(TrackBase::TrackType_Effect);
	pEffectTrack->SetIndex(1);
	TrackBase* pAudioTrack = pTrackManager->CreateTrack(TrackBase::TrackType_Audio);
	pAudioTrack->SetIndex(2);
	m_listTracks.push_back(pVedioTrack);
	m_listTracks.push_back(pEffectTrack);
	m_listTracks.push_back(pAudioTrack);
}

int TrackOperator::ItemCount()
{
	return m_listTracks.size();
}

int TrackOperator::ItemCountWithType(int nType)
{
	if (nType == TrackBase::TrackType_All) return ItemCount();

	int nCnt = 0;
	for (TrackBase* pTrack: m_listTracks)
	{
		if (pTrack->GetType() == nType) ++nCnt;
	}
	return nCnt;
}

TrackBase* TrackOperator::GetTrack(int nIndex)
{
	if (nIndex < 0 || nIndex >= ItemCount()) return nullptr;
	return m_listTracks[nIndex];
}

TrackList TrackOperator::GetTracks()
{
	return m_listTracks;
}


void TrackOperator::AddTrack(TrackBase* pTrack, int nIndex)
{
	if (nIndex <0 || nIndex>ItemCount()) return;
	m_listTracks.insert(nIndex, pTrack);
	ResetIndex();
}

void TrackOperator::RemoveTrack(TrackBase* pTrack)
{
	m_listTracks.removeOne(pTrack);
	ResetIndex();
}

int TrackOperator::MoveTrack(TrackBase* pTrack, int nIndexTo)
{
	if (nIndexTo <0 || nIndexTo>ItemCount()) return -1;
	int nIndexFrom = pTrack->GetIndex();
	if (nIndexFrom == nIndexTo) return -1;

	m_listTracks.move(nIndexFrom, nIndexTo);
	ResetIndex();
	return nIndexFrom;
}

void TrackOperator::SwapTrack(TrackBase* pTrackFrom, TrackBase* pTrackTo)
{
	if (pTrackFrom == pTrackTo) return;
	m_listTracks.removeOne(pTrackFrom);
	m_listTracks.insert(pTrackTo->GetIndex(), pTrackFrom);
	ResetIndex();
}

void TrackOperator::ResetIndex()
{
	TrackBase *pTrack = nullptr;
	for (int i = 0; i < ItemCount(); ++i)
	{
		pTrack = m_listTracks[i];
		if (pTrack)
		{
			pTrack->SetIndex(i);
			for (ClipBase *pClip : pTrack->GetClips())
			{
				m_pRootTimeline->SetClipLevel(pClip->GetSrcTimeline(),i);
			}
		}
	}
}

void TrackOperator::Clear()
{
	m_listTracks.clear();
}