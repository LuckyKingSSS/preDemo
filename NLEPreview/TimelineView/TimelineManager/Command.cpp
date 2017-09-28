#include "stdafx.h"
#include "Command.h"
#include "ClipBase.h"
#include "TrackBase.h"
#include "OperatorBase.h"


UndoCommandBase::UndoCommandBase(OperatorBase *pOperator, QObject* parent)
: QObject(parent)
, m_pOperator(pOperator)
{
}
UndoCommandBase::~UndoCommandBase()
{

}

void UndoCommandBase::undo()
{
	Undo();
	emit signalUpdate();
}

void UndoCommandBase::redo()
{
	Redo();
	emit signalUpdate();
}

void UndoCommandBase::Undo()
{

}

void UndoCommandBase::Redo()
{

}

/************************************************************************/
/* NestedCommond                                                         */
/************************************************************************/
NestedCommond::NestedCommond(QUndoStack* pNestedStack, QObject *parent)
:UndoCommandBase(nullptr,parent)
, m_pNestedStack(pNestedStack)
{
	m_nCurCmdCounts = 0;
}

NestedCommond::~NestedCommond()
{

}

void NestedCommond::Undo()
{
	if (m_nCurCmdCounts == 0) return;
	int nCnt = m_nCurCmdCounts;
	while (m_pNestedStack->canUndo() && nCnt--)
	{
		m_pNestedStack->undo();
	}
	emit signalNestedCommndExec();
}

void NestedCommond::Redo()
{
	if (m_nCurCmdCounts == 0) return;
	int nCnt = m_nCurCmdCounts;
	while (m_pNestedStack->canRedo() && nCnt--)
	{
		m_pNestedStack->redo();
	}
	emit signalNestedCommndExec();
}

void NestedCommond::SetCurrentCmdCounts(int nCnt)
{
	m_nCurCmdCounts = nCnt;
}

/************************************************************************/
/* ClipCommandBase                                                         */
/************************************************************************/
ClipCommandBase::ClipCommandBase(OperatorBase *pOperator, QObject* parent)
:UndoCommandBase(pOperator, parent)
{

}
ClipCommandBase::~ClipCommandBase()
{

}

/************************************************************************/
/* AddClipCommand                                                         */
/************************************************************************/
AddClipCommand::AddClipCommand(ClipOperatorBase *pOperator, ClipBase *pAddClip, QObject *parent)
:ClipCommandBase(pOperator,parent)
, m_pAddClip(pAddClip)
{

}

AddClipCommand::~AddClipCommand()
{

}

void AddClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->RemoveClip(m_pAddClip);
	emit signalClipChanged(m_pOperator);
}

void AddClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->AddClip(m_pAddClip);
	if (m_pAddClip) m_pAddClip->SetOwnerTrack(pOperator->GetOwnerTrack());
	emit signalClipChanged(m_pOperator);
}


/************************************************************************/
/* RemoveClipCommand                                                        */
/************************************************************************/
RemoveClipCommand::RemoveClipCommand(ClipOperatorBase *pOperator, ClipBase* pRemoveClip, QObject *parent)
:ClipCommandBase(pOperator, parent)
, m_pRemoveClip(pRemoveClip)
{
}

RemoveClipCommand::~RemoveClipCommand()
{
}

void RemoveClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->AddClip(m_pRemoveClip);
	emit signalClipChanged(m_pOperator);
}

void RemoveClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->RemoveClip(m_pRemoveClip);
	emit signalClipChanged(m_pOperator);
}

/************************************************************************/
/* MoveClipCommand                                                        */
/************************************************************************/
MoveClipCommand::MoveClipCommand(ClipOperatorBase *pOperator, ClipBase* pMoveClip, ClipOperatorBase* pTo, int nTo, QObject *parent)
:ClipCommandBase(pOperator,parent)
, m_pMoveClip(pMoveClip)
, m_pToOperator(pTo)
, m_nTo(nTo)
{

}
MoveClipCommand::~MoveClipCommand()
{

}

void MoveClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	m_pToOperator->MoveClip(m_pMoveClip, pOperator, m_nOrigin);
	m_pMoveClip->SetOwnerTrack(pOperator->GetOwnerTrack());
	if (m_pToOperator != m_pOperator)
	{
		emit signalClipChanged(m_pToOperator);
	}
	emit signalClipChanged(m_pOperator);
}

void MoveClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	m_nOrigin = pOperator->MoveClip(m_pMoveClip, m_pToOperator, m_nTo);
	m_pMoveClip->SetOwnerTrack(m_pToOperator->GetOwnerTrack());
	if (m_pToOperator != m_pOperator)
	{
		emit signalClipChanged(m_pToOperator);
	}
	emit signalClipChanged(m_pOperator);
}

/************************************************************************/
/* CopyClipCommand                                                        */
/************************************************************************/
CopyClipCommand::CopyClipCommand(ClipOperatorBase *pOperator, ClipBase* pSrcClip, ClipOperatorBase* pTo, int nTo, QObject *parent)
:ClipCommandBase(pOperator, parent)
, m_pSrcClip(pSrcClip)
, m_pToOperator(pTo)
, m_nTo(nTo)
{

}

CopyClipCommand::~CopyClipCommand()
{

}

void CopyClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->RemoveClip(m_pDestClip);
	m_pDestClip->deleteLater();

	emit signalClipChanged(m_pOperator);
}

void CopyClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	m_pDestClip = pOperator->CopyClip(m_pSrcClip, m_pToOperator, m_nTo);
	m_pDestClip->SetOwnerTrack(m_pToOperator->GetOwnerTrack());
	emit signalClipChanged(m_pOperator);
}

/************************************************************************/
/* SplitClipCommand														*/
/************************************************************************/
SplitClipCommand::SplitClipCommand(ClipOperatorBase *pOperator, ClipBase* pSplitClip, int nOffset, QObject *parent)
:ClipCommandBase(pOperator, parent)
, m_pSplitClip(pSplitClip)
, m_nOffset(nOffset)
{
	m_pNewClip = nullptr;
}

SplitClipCommand::~SplitClipCommand()
{

}

void SplitClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	if (!m_pNewClip) return;
	pOperator->UndoSplitClip(m_pSplitClip, m_pNewClip);
	//m_pNewClip->deleteLater();
	emit signalClipChanged(m_pOperator);

	if (m_pSplitClip->GetType() != ClipBase::ClipType_Vedio) return;
	m_pSplitClip->SetThumbnailTotalLength(m_pSplitClip->GetThumbnailTotalLength() + m_pNewClip->GetThumbnailTotalLength());
}

void SplitClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	int nOrigLenAtTrack = m_pSplitClip->GetLenAtTrack();

	if (!m_pNewClip)
	{
		m_pNewClip = pOperator->SplitClip(m_pSplitClip, m_nOffset);
	}
	else
	{
		pOperator->SplitClipEx(m_pSplitClip, m_pNewClip);
	}
	
	if(m_pNewClip) m_pNewClip->SetOwnerTrack(pOperator->GetOwnerTrack());
	emit signalClipChanged(m_pOperator);

	//¼ÆËãshowlen
	if (m_pSplitClip->GetType() != ClipBase::ClipType_Vedio) return;
	int nOrinShowLen = m_pSplitClip->GetThumbnailTotalLength();

	double df = (double)m_nOffset / (double)nOrigLenAtTrack;
	int nNewLen1 = m_pSplitClip->GetThumbnailTotalLength() * df;
	int nNewlen2 = m_pSplitClip->GetThumbnailTotalLength() - nNewLen1;

	m_pSplitClip->SetThumbnailTotalLength(nNewLen1);
	m_pNewClip->SetThumbnailTotalLength(nNewlen2);
}

/************************************************************************/
/* AdjustClipCommand														*/
/************************************************************************/
AdjustClipCommand::AdjustClipCommand(ClipOperatorBase *pOperator, ClipBase* pClip, int nNewStartPos, int nNewLen, QObject *parent)
:ClipCommandBase(pOperator, parent)
, m_pAdjustClip(pClip)
, m_nNewStartPos(nNewStartPos)
, m_nNewLen(nNewLen)
{

}

AdjustClipCommand::~AdjustClipCommand()
{

}

void AdjustClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->AdjustClip(m_pAdjustClip, std::get<0>(m_OriginData), std::get<1>(m_OriginData));
	emit signalClipChanged(m_pOperator);
}

void AdjustClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	m_OriginData = pOperator->AdjustClip(m_pAdjustClip, m_nNewStartPos, m_nNewLen);
	emit signalClipChanged(m_pOperator);
}

/************************************************************************/
/* CropClipCommand														*/
/************************************************************************/
CropClipCommand::CropClipCommand(ClipOperatorBase *pOperator, ClipBase* pClip, const QRectF &newRegion, QObject *parent)
:ClipCommandBase(pOperator, parent)
, m_pCropClip(pClip)
, m_newRegion(newRegion)
{
	m_oldRegion = m_pCropClip->GetSrcTimeline()->GetCropRegion();
}

CropClipCommand::~CropClipCommand()
{

}

void CropClipCommand::Undo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->CropClip(m_pCropClip,m_oldRegion);
	emit signalClipChanged(m_pOperator);
}

void CropClipCommand::Redo()
{
	ClipOperatorBase *pOperator = dynamic_cast<ClipOperatorBase *>(m_pOperator);
	if (!pOperator) return;
	pOperator->CropClip(m_pCropClip, m_newRegion);
	emit signalClipChanged(m_pOperator);
}

/************************************************************************/
/* TrackCommondBase														*/
/************************************************************************/
TrackCommondBase::TrackCommondBase(OperatorBase *pOperator, QObject* parent)
:UndoCommandBase(pOperator, parent)
{

}
TrackCommondBase::~TrackCommondBase()
{

}


/************************************************************************/
/* AddTrackCommond														*/
/************************************************************************/
AddTrackCommond::AddTrackCommond(TrackOperator *pOperator, TrackBase *pTrack, int nIndex, QObject *parent)
:TrackCommondBase(pOperator, parent)
, m_pAddTrack(pTrack)
, m_nAddIndex(nIndex)
{

}

AddTrackCommond::~AddTrackCommond()
{

}

void AddTrackCommond::Undo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->RemoveTrack(m_pAddTrack);
	emit signalTrackChanged();
}

void AddTrackCommond::Redo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->AddTrack(m_pAddTrack, m_nAddIndex);
	emit signalTrackChanged();
}

/************************************************************************/
/* RemoveTrackCommond														*/
/************************************************************************/
RemoveTrackCommond::RemoveTrackCommond(TrackOperator *pOperator, TrackBase *pTrack, QObject *parent)
:TrackCommondBase(pOperator, parent)
, m_pRemoveTrack(pTrack)
{

}

RemoveTrackCommond::~RemoveTrackCommond()
{

}

void RemoveTrackCommond::Undo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->AddTrack(m_pRemoveTrack, m_pRemoveTrack->GetIndex());
	emit signalTrackChanged();
}

void RemoveTrackCommond::Redo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->RemoveTrack(m_pRemoveTrack);
	emit signalTrackChanged();
}

/************************************************************************/
/* MoveTrackCommond														*/
/************************************************************************/
MoveTrackCommond::MoveTrackCommond(TrackOperator *pOperator, TrackBase *pTrack, int nIndexTo, QObject *parent)
:TrackCommondBase(pOperator, parent)
, m_pMoveTrack(pTrack)
, m_nIndexTo(nIndexTo)
{

}

MoveTrackCommond::~MoveTrackCommond()
{

}

void MoveTrackCommond::Undo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->MoveTrack(m_pMoveTrack, m_nIndexFrom);
	emit signalTrackChanged();
}

void MoveTrackCommond::Redo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	m_nIndexFrom = pOperator->MoveTrack(m_pMoveTrack, m_nIndexTo);
	emit signalTrackChanged();
}

/************************************************************************/
/* SwapTrackCommond														*/
/************************************************************************/
SwapTrackCommond::SwapTrackCommond(TrackOperator *pOperator, TrackBase *pTrack1, TrackBase *pTrack2, QObject *parent)
:TrackCommondBase(pOperator, parent)
, m_pTrack1(pTrack1)
, m_pTrack2(pTrack2)
{

}

SwapTrackCommond::~SwapTrackCommond()
{

}

void SwapTrackCommond::Undo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->SwapTrack(m_pTrack1, m_pTrack2);
	emit signalTrackChanged();
}

void SwapTrackCommond::Redo()
{
	TrackOperator *pOperator = dynamic_cast<TrackOperator *>(m_pOperator);
	if (!pOperator) return;
	pOperator->SwapTrack(m_pTrack1, m_pTrack2);
	emit signalTrackChanged();
}