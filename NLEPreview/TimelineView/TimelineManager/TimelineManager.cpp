#include "stdafx.h"
#include "TimelineManager.h"
#include "ClipBase.h"
#include "ComplexClipController.h"
#include "TrackManager.h"
//#include <QUndoStack>
#include "Command.h"
#include "inc_MatterView/MatterDataDefine.h"

TimelineManager::TimelineManager(QObject *parent)
: QObject(parent)
{
	ComplexClip* pRoot = m_pCurComplexClip = new ComplexClip(nullptr, this);
	ConnectSignals(pRoot);
	SetCurrentComplexClip(pRoot);
}

TimelineManager::~TimelineManager()
{

}

TimelineManager* TimelineManager::GetInstance()
{
	static TimelineManager instance;
	return &instance;
}

ComplexClipController* TimelineManager::CurrentController()
{
	ComplexClip *pClip = CurrentComplexClip();
	if (pClip) return pClip->GetComplexClipController();
	return nullptr;
}


bool TimelineManager::IsCompatible(int nClipType, int nTrackType)
{
	switch (nTrackType)
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

ComplexClip *TimelineManager::CurrentComplexClip()
{
	return m_pCurComplexClip;
}

void TimelineManager::ConvertToComplex()
{
	CurrentController()->ConvertToComplex();
}

void TimelineManager::EnterComplexClip()
{
	ComplexClip * pEnterClip = dynamic_cast<ComplexClip *>(m_pCurComplexClip->GetComplexClipController()->GetSelectedClip());
	if (!pEnterClip) return;

	DisconnectSignals(m_pCurComplexClip);
	ConnectSignals(pEnterClip);
	BackupRange(pEnterClip);

	m_BackupComplexClips.push(m_pCurComplexClip);
	m_mapBackupCmdCnts.insert(pEnterClip, GetCmdCount(pEnterClip));

	SetCurrentComplexClip(pEnterClip);
	AdjustRootClipLength();
	emit signalTrackRebuild();
}

void TimelineManager::LeaveComplexClip()
{
	ComplexClip * pPreClip = m_BackupComplexClips.pop();
	if (!pPreClip) return;

	DisconnectSignals(m_pCurComplexClip);
	ConnectSignals(pPreClip);

	RestoreAllRange();

	int nCmdCnt = GetCmdCount(m_pCurComplexClip);
	int nDelta = nCmdCnt - m_mapBackupCmdCnts[m_pCurComplexClip];
	if (nDelta > 0)
	{
		//产生一个NestCommand放进pPreClip里面
		pPreClip->GetComplexClipController()->GetTrackManager()->CompositeSubUndoStack(GetUndoStack(m_pCurComplexClip), nDelta);
	}
	SetCurrentComplexClip(pPreClip);
	AdjustRootClipLength();
	emit signalTrackRebuild();
}

void TimelineManager::BackupRange(ComplexClip* pClip)
{
	if (m_mapBackupRanges.contains(pClip)) return;
	m_mapBackupRanges.insert(pClip, pClip->GetSrcTimeline()->GetRange());
}

void TimelineManager::RestoreRange(ComplexClip* pClip)
{
	if (pClip->ParentClip() == nullptr) return;
	if (!m_mapBackupRanges.contains(pClip)) return;
	QPoint range = m_mapBackupRanges.value(pClip);
	pClip->ParentClip()->GetSrcTimeline()->SetClipRange(pClip->GetSrcTimeline(), range.x(), range.y());
}

void TimelineManager::RestoreAllRange()
{
	QList<ComplexClip*> listBk = m_mapBackupRanges.keys();
	for (int i = listBk.count() - 1; i >= 0; --i)
	{
		RestoreRange(listBk[i]);
	}
}

void TimelineManager::ConnectSignals(ComplexClip* pClip)
{
	if (!pClip) return;
	connect(pClip->GetComplexClipController(), &ComplexClipController::signalThumbnailAvalible, this, &TimelineManager::signalThumbnailAvalible);
	connect(pClip->GetComplexClipController(), &ComplexClipController::signalTrackChanged, this, &TimelineManager::signalTrackRebuild);
	connect(pClip->GetComplexClipController(), &ComplexClipController::signalTrackUpdate, this, &TimelineManager::signalTrackUpdate);
	connect(pClip->GetComplexClipController()->GetTrackManager()->GetUndoStack(), &QUndoStack::canUndoChanged, this, &TimelineManager::signalCanUndoChanged);
	connect(pClip->GetComplexClipController()->GetTrackManager()->GetUndoStack(), &QUndoStack::canRedoChanged, this, &TimelineManager::signalCanRedoChanged);
	connect(pClip->GetComplexClipController(), &ComplexClipController::signalNestedCommndExec, this, [&]{
		RestoreAllRange();

	});
}

void TimelineManager::DisconnectSignals(ComplexClip* pClip)
{
	if (!pClip) return;
	pClip->GetComplexClipController()->disconnect();
	pClip->GetComplexClipController()->GetTrackManager()->GetUndoStack()->disconnect();
}

void TimelineManager::SetCurrentComplexClip(ComplexClip* pClip)
{
	m_pCurComplexClip = pClip;
}

ClipBase* TimelineManager::AddClip(int nTrackIndexTo, int nPosTo, NLETimeline *pSrc, int nClipType, bool bForceCreate)
{
	return CurrentController()->AddClip(nTrackIndexTo, nPosTo, pSrc, nClipType, bForceCreate);
}

void TimelineManager::MoveClip(int nTrackIndexTo, int nPosTo, bool bForceCreate)
{
	CurrentController()->MoveClip(nTrackIndexTo, nPosTo, bForceCreate);
}

void TimelineManager::CopyFrom(bool bCut)
{
	CurrentController()->CopyFrom(bCut);
}

ClipBase* TimelineManager::CopyTo(int nPos)
{
	return CurrentController()->CopyTo(nPos);
}

void TimelineManager::SplitClip(int nPos)
{
	CurrentController()->SplitClip(nPos);
}
void TimelineManager::RemoveClip()
{
	CurrentController()->RemoveClip();
}

void TimelineManager::AdjustClip(int nLeftOrRight, int nPosTo)
{
	CurrentController()->AdjustClip(nLeftOrRight, nPosTo);
}

void TimelineManager::CropClip()
{
	CurrentController()->CropClip();
}

void TimelineManager::TextEdit()
{
	CurrentController()->TextEdit();
}

void TimelineManager::SelectClip(int nTrackIndexAt, int nPosAt)
{
	CurrentController()->SelectClip(nTrackIndexAt, nPosAt);
}

void TimelineManager::UnselectAll()
{
	CurrentController()->UnselectAll(true);
}

bool TimelineManager::CanUndo()
{
	return CurrentController()->GetTrackManager()->GetUndoStack()->canUndo();
}

bool TimelineManager::CanRedo()
{
	return CurrentController()->GetTrackManager()->GetUndoStack()->canRedo();
}

void TimelineManager::Undo()
{
	CurrentController()->GetTrackManager()->GetUndoStack()->undo();
}

void TimelineManager::Redo()
{
	CurrentController()->GetTrackManager()->GetUndoStack()->redo();
}

ClipBase* TimelineManager::GetSelectedClip()
{
	return CurrentController()->GetSelectedClip();
}
int TimelineManager::MatterType2ClipType(int nMatterType)
{
	int nClipType = -1;
	if (nMatterType == MatterType_Video)
	{
		nClipType = ClipBase::ClipType_Vedio;
	}
	else if (nMatterType == MatterType_Effect)
	{
		nClipType = ClipBase::ClipType_Effect;
	}
	else if (nMatterType == MatterType_Audio)
	{
		nClipType = ClipBase::ClipType_Audio;
	}
	return nClipType;
}

void TimelineManager::AdjustRootClipLength()
{
	ComplexClip* pClip = CurrentComplexClip();
	ComplexClip* pParent = (ComplexClip*)pClip->ParentClip();

	if (pParent)
	{
		QPoint range = m_mapBackupRanges.value(pClip);
		pClip->GetSrcTimeline()->SetRange(range.x(), range.y());
		//pParent->GetSrcTimeline()->SetClipRange(pClip->GetSrcTimeline(), range.x(), range.y());
	}
	else
	{
		int nMaxDuration = 0;
		int nTemp = 0;
		for (TrackBase *pTrack : pClip->GetComplexClipController()->GetTrackManager()->GetTracks())
		{
			nTemp = pTrack->GetDuration();
			if (nTemp > nMaxDuration) nMaxDuration = nTemp;
		}
		pClip->GetSrcTimeline()->SetTrimout(nMaxDuration);
	}
}

int TimelineManager::GetCmdCount(ComplexClip* pClip)
{
	return GetUndoStack(pClip)->count();
}

QUndoStack *TimelineManager::CurrentUndoStack()
{
	return CurrentController()->GetTrackManager()->GetUndoStack();
}

QUndoStack *TimelineManager::GetUndoStack(ComplexClip* pClip)
{
	return pClip->GetComplexClipController()->GetTrackManager()->GetUndoStack();
}

