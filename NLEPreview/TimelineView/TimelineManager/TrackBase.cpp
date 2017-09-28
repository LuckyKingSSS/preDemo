#include "stdafx.h"
#include "TrackBase.h"
#include "command.h"
#include "ClipBase.h"
//#include <QUndoStack>
#include "commonlib_global.h"
#include "OperatorBase.h"
#include "TrackManager.h"

TrackBase::TrackBase(int nTrackType, TrackManager *pTrackManager,QObject *parent)
	: QObject(parent)
	, m_pTrackManager(pTrackManager)
	, m_nTrackType(nTrackType)
	, m_nIndex(-1)
{
	m_pClipOperator = nullptr;
}

TrackBase::TrackBase(QObject *parent)
:QObject(parent)
{

}

TrackBase::~TrackBase()
{
	SAFE_DELETE(m_pClipOperator);
}

TrackBase* TrackBase::Clone()
{
	return nullptr;
}

void TrackBase::CloneAble(TrackBase *pFrom)
{
	m_nIndex = pFrom->m_nIndex;
	m_nTrackType = pFrom->m_nTrackType;
}

void TrackBase::SetTrackManager(TrackManager *pTrackManager)
{
	m_pTrackManager = pTrackManager;
	m_pClipOperator->SetRootTimeline(m_pTrackManager->GetRootTimeline());
}

ClipOperatorBase *TrackBase::GetClipOperator()
{
	return m_pClipOperator;
}

int TrackBase::GetType() const
{
	return m_nTrackType;
}

void TrackBase::SetIndex(int nIndex)
{
	m_nIndex = nIndex;
}

int TrackBase::GetIndex() const
{
	return m_nIndex;
}

bool TrackBase::IsCompatibled(ClipBase* pClip)
{
	return IsCompatibled(pClip->GetType());
}

bool TrackBase::IsCompatibled(int nClipType)
{
	switch (m_nTrackType)
	{
	case TrackBase::TrackType_Vedio:
		if (nClipType == SimplexClip::ClipType_Vedio || nClipType == ClipBase::ClipType_Complex) return true;
		break;
	case TrackBase::TrackType_Effect:
		if (nClipType == SimplexClip::ClipType_Effect) return true;
		break;
	case TrackBase::TrackType_Audio:
		if (nClipType == SimplexClip::ClipType_Audio) return true;
		break;
	}
	return false;
}

int TrackBase::GetDuration()
{
	ClipBase *pLastClip = m_pClipOperator->GetClip(m_pClipOperator->ItemCount() - 1);
	if (!pLastClip) return 0;
	return pLastClip->GetStartAtTrack() + pLastClip->GetLenAtTrack();
}

ClipBase* TrackBase::GetPreClip(ClipBase* pClip)
{
	return m_pClipOperator->GetPreClip(pClip);
}

ClipBase* TrackBase::GetNextClip(ClipBase* pClip)
{
	return m_pClipOperator->GetNextClip(pClip);
}

ClipBase *TrackBase::GetSelectedClip()
{
	for (ClipBase* pClip : GetClips())
	{
		if (pClip->IsSelected()) return pClip;
	}
	return nullptr;
}

ClipBase* TrackBase::GetClipByPos(int nPos)
{
	for (ClipBase* pClip : GetClips())
	{
		if (pClip->GetStartAtTrack() <= nPos && nPos < pClip->GetStartAtTrack() + pClip->GetLenAtTrack())
			return pClip;
	}
	return nullptr;
}

TrackManager * TrackBase::GetTrackManager()
{
	return m_pTrackManager;
}

ClipList TrackBase::GetClips()
{
	return m_pClipOperator->GetClips();
}

void TrackBase::PushCommond(ClipCommandBase *pCommand)
{
	connect(pCommand, &ClipCommandBase::signalClipChanged, this, [&](OperatorBase* pOperator){
		
		for (TrackBase* pTrack : m_pTrackManager->GetTracks())
		{
			if (pTrack->GetClipOperator() == pOperator)
			{
				emit signalTrackUpdate(pTrack->GetIndex());
				break;
			}
		}
	});
	m_pTrackManager->GetUndoStack()->push(pCommand);
}

void TrackBase::AddClip(ClipBase* pClip)
{
	PushCommond(new AddClipCommand(m_pClipOperator, pClip));
}

void TrackBase::RemoveClip(ClipBase* pClip)
{
	if (!GetClips().contains(pClip)) return;

	int nTrackCnt = m_pTrackManager->GetTrackCount(m_nTrackType);
	int nItemCnt = m_pClipOperator->ItemCount();
	if (nTrackCnt>1 && nItemCnt == 1 && m_pClipOperator->GetClips().at(0) == pClip)
	{
		m_pTrackManager->BeginComposite();
		PushCommond(new RemoveClipCommand(m_pClipOperator, pClip));
		m_pTrackManager->RemoveTrack(this);
		m_pTrackManager->EndComposite();
	}
	else
	{
		PushCommond(new RemoveClipCommand(m_pClipOperator, pClip));
	}
}

void TrackBase::MoveClip(ClipBase* pClip, TrackBase* pTo,int nTo)
{
	if (!GetClips().contains(pClip)) return;
	int nTrackCnt = m_pTrackManager->GetTrackCount(m_nTrackType);
	int nItemCnt = m_pClipOperator->ItemCount();
	if (pTo!= this && nTrackCnt > 1 && nItemCnt == 1 && m_pClipOperator->GetClips().at(0) == pClip)
	{
		m_pTrackManager->BeginComposite();
		PushCommond(new MoveClipCommand(m_pClipOperator, pClip, pTo->GetClipOperator(), nTo));
		m_pTrackManager->RemoveTrack(this);
		m_pTrackManager->EndComposite();
	}
	else
	{
		PushCommond(new MoveClipCommand(m_pClipOperator, pClip, pTo->GetClipOperator(), nTo));
	}
}

void TrackBase::CopyClip(ClipBase* pClip, TrackBase* pTo, int nTo)
{
	PushCommond(new CopyClipCommand(m_pClipOperator, pClip, pTo->GetClipOperator(), nTo));
}

void TrackBase::SplitClip(ClipBase* pClip, int nOffset)
{
	PushCommond(new SplitClipCommand(m_pClipOperator, pClip, nOffset));
}

void TrackBase::AdjustClip(ClipBase* pClip, int nNewStartPos, int nNewLen)
{
	PushCommond(new AdjustClipCommand(m_pClipOperator, pClip, nNewStartPos, nNewLen));
}

void TrackBase::CropClip(ClipBase* pClip, const QRectF &newRegion)
{
	
	PushCommond(new CropClipCommand(m_pClipOperator, pClip, newRegion));
}

/************************************************************************/
/*								VedioTrack                              */
/************************************************************************/
VedioTrack::VedioTrack(TrackManager *pTrackManager, QObject *parent)
: TrackBase(TrackBase::TrackType_Vedio, pTrackManager, parent)
{
	m_pClipOperator = new VedioClipOperator(this);
	m_pClipOperator->SetRootTimeline(m_pTrackManager->GetRootTimeline());
}

VedioTrack::VedioTrack(QObject *parent)
:TrackBase(parent)
{

}

VedioTrack::~VedioTrack()
{

}

TrackBase* VedioTrack::Clone()
{
	VedioTrack *pNew = new VedioTrack();
	pNew->CloneAble(this);

	pNew->m_pClipOperator = new VedioClipOperator(pNew);

	ClipBase *pNewClip = nullptr;
	for (ClipBase* pClip : m_pClipOperator->m_listClips)
	{
		pNewClip = pClip->Clone();
		pNew->m_pClipOperator->m_listClips.push_back(pNewClip);
	}
	return pNew;
}

void VedioTrack::CloneAble(TrackBase *pFrom)
{
	TrackBase::CloneAble(pFrom);
}

/************************************************************************/
/*								AudioTrack                             */
/************************************************************************/
AudioTrack::AudioTrack(TrackManager *pTrackManager, QObject *parent)
:TrackBase(TrackBase::TrackType_Audio, pTrackManager, parent)
{
	m_pClipOperator = new AudioClipOperator(this);
	m_pClipOperator->SetRootTimeline(m_pTrackManager->GetRootTimeline());
}

AudioTrack::AudioTrack(QObject *parent)
:TrackBase(parent)
{

}

AudioTrack::~AudioTrack()
{
}

TrackBase* AudioTrack::Clone()
{
	AudioTrack *pNew = new AudioTrack();
	pNew->CloneAble(this);

	pNew->m_pClipOperator = new AudioClipOperator(pNew);

	ClipBase *pNewClip = nullptr;
	for (ClipBase* pClip : m_pClipOperator->m_listClips)
	{
		pNewClip = pClip->Clone();
		pNew->m_pClipOperator->m_listClips.push_back(pNewClip);
	}
	return pNew;
}

void AudioTrack::CloneAble(TrackBase *pFrom)
{
	TrackBase::CloneAble(pFrom);
}

/************************************************************************/
/*								EffectTrack                             */
/************************************************************************/
EffectTrack::EffectTrack(TrackManager *pTrackManager, QObject *parent)
:TrackBase(TrackBase::TrackType_Effect, pTrackManager, parent)
{
	m_pClipOperator = new EffectClipOperator(this);
	m_pClipOperator->SetRootTimeline(m_pTrackManager->GetRootTimeline());
}

EffectTrack::EffectTrack(QObject *parent)
:TrackBase(parent)
{

}

EffectTrack::~EffectTrack()
{
}

TrackBase* EffectTrack::Clone()
{
	EffectTrack *pNew = new EffectTrack();
	pNew->CloneAble(this);

	pNew->m_pClipOperator = new EffectClipOperator(pNew);

	ClipBase *pNewClip = nullptr;
	for (ClipBase* pClip : m_pClipOperator->m_listClips)
	{
		pNewClip = pClip->Clone();
		pNew->m_pClipOperator->m_listClips.push_back(pNewClip);
	}
	return pNew;
}

void EffectTrack::CloneAble(TrackBase *pFrom)
{
	TrackBase::CloneAble(pFrom);
}
