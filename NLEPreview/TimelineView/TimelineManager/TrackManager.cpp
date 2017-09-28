#include "stdafx.h"
#include "TrackManager.h"
#include "TrackBase.h"
#include "Command.h"
//#include <QUndoStack>
//#include <QUndoCommand>
#include "commonlib_global.h"
#include "OperatorBase.h"
#include "ClipBase.h"
TrackManager::TrackManager(NLETimeline *pRootTimeline,QObject *parent)
	: QObject(parent)
	, m_pRootTimeline(pRootTimeline)
{
	m_UndoStack = new QUndoStack(this);
	m_pTrackOperator = new TrackOperator;
	m_pTrackOperator->Init(this);
}

TrackManager::~TrackManager()
{
	SAFE_DELETE(m_pTrackOperator);
}

void TrackManager::AddTrack(TrackBase *pTrack, int nIndex)
{
	PushCommand(new AddTrackCommond(m_pTrackOperator, pTrack, nIndex));
}

void TrackManager::RemoveTrack(TrackBase *pTrack)
{
	PushCommand(new RemoveTrackCommond(m_pTrackOperator, pTrack));
}

void TrackManager::MoveTrack(TrackBase *pTrack, int nIndexTo)
{
	PushCommand(new MoveTrackCommond(m_pTrackOperator, pTrack, nIndexTo));
}

void TrackManager::SwapTrack(TrackBase *pTrack1, TrackBase *pTrack2)
{
	PushCommand(new SwapTrackCommond(m_pTrackOperator, pTrack1, pTrack2));
}

void TrackManager::PushCommand(TrackCommondBase *pCommond)
{
	connect(pCommond, &TrackCommondBase::signalTrackChanged, this, &TrackManager::signalTrackChanged);
	m_UndoStack->push(pCommond);
}

void TrackManager::BeginComposite()
{
	m_UndoStack->beginMacro("command composite");
}

void TrackManager::EndComposite()
{
	m_UndoStack->endMacro();
}

void TrackManager::CompositeSubUndoStack(QUndoStack* pSubUndoStack, int nCommandCounts)
{
	if (!pSubUndoStack) return;
	NestedCommond *pCmd = new NestedCommond(pSubUndoStack);
	pCmd->SetCurrentCmdCounts(nCommandCounts);
	connect(pCmd, &NestedCommond::signalNestedCommndExec, this, &TrackManager::signalNestedCommndExec);
	m_UndoStack->push(pCmd);
}

int TrackManager::GetTrackCount(int nTrackType)
{
	return m_pTrackOperator->ItemCountWithType(nTrackType);
}

TrackBase* TrackManager::GetTrack(int nIndex)
{
	return m_pTrackOperator->GetTrack(nIndex);
}

TrackList TrackManager::GetTracks()
{
	return m_pTrackOperator->GetTracks();
}

QUndoStack* TrackManager::GetUndoStack()
{
	return m_UndoStack;
}

TrackBase* TrackManager::CreateTrack(int nTrackType)
{
	TrackBase* pTrack = nullptr;
	if (nTrackType == TrackBase::TrackType_Vedio)
	{
		pTrack = new VedioTrack(this);
	}
	else if (nTrackType == TrackBase::TrackType_Effect)
	{
		pTrack = new EffectTrack(this);
	}
	else if (nTrackType == TrackBase::TrackType_Audio)
	{
		pTrack = new AudioTrack(this);
	}
	if (pTrack) m_pTrackOperator->SetRootTimeline(m_pRootTimeline);

	connect(pTrack, &TrackBase::signalTrackUpdate, this, &TrackManager::signalTrackUpdate);
	return pTrack;
}

NLETimeline *TrackManager::GetRootTimeline()
{
	return m_pRootTimeline;
}

void TrackManager::SelectClip(int nTrackIndexAt, int nPosAt)
{
	TrackBase *pTrack = GetTrack(nTrackIndexAt);
	if (!pTrack) return;
	ClipBase *pSelectedClip = pTrack->GetClipByPos(nPosAt);

	if (!pSelectedClip)
	{
		UnselectAll(true);
		return;
	}
	UnselectAll();
	pSelectedClip->Select(true);
	emit signalTrackUpdate(nTrackIndexAt);
}

void TrackManager::UnselectAll(bool bForceUpdate)
{
	for (TrackBase* pTrack : GetTracks())
	{
		for (ClipBase* pClip : pTrack->GetClips())
		{
			if (pClip->IsSelected())
			{
				pClip->Select(false);
				if (bForceUpdate) emit signalTrackUpdate(pTrack->GetIndex());
				return;
			}
		}
	}
}

ClipBase* TrackManager::GetSelectedClip()
{
	ClipBase *pSelectedClip = nullptr;
	for (TrackBase* pTrack : GetTracks())
	{
		pSelectedClip = pTrack->GetSelectedClip();
		if (pSelectedClip) return pSelectedClip;
	}
	return nullptr;
}
