#include "stdafx.h"
#include "ComplexClipController.h"
#include "TrackManager.h"
#include "ClipBase.h"
//#include <QUndoStack>
#include "NLEWraper.h"
#include "PlayerMaterProvider.h"
#include "inc_CommonLib/externalapi.h"
#include "inc_MatterView/matterview.h"
#include "Tools/MediaCropDialog.h"

ComplexClipController::ComplexClipController(NLETimeline *pRootTimeline, QObject *parent)
	: QObject(parent)
{
	m_pCopyedClip = nullptr;
	m_pCurComplexClip = qobject_cast<ComplexClip*>(parent);
	m_pTrackManager = new TrackManager(pRootTimeline, this);
	connect(m_pTrackManager, &TrackManager::signalThumbnailAvalible, this, [&](ClipBase* pClip){
		emit signalThumbnailAvalible(pClip->GetOwnerTrack()->GetIndex());
	});
	connect(m_pTrackManager, &TrackManager::signalTrackChanged, this, &ComplexClipController::signalTrackChanged);
	connect(m_pTrackManager, &TrackManager::signalTrackUpdate, this, &ComplexClipController::signalTrackUpdate);
	connect(m_pTrackManager, &TrackManager::signalNestedCommndExec, this, &ComplexClipController::signalNestedCommndExec);
}

ComplexClipController::~ComplexClipController()
{

}

int ComplexClipController::TrackTypeFromClipType(int nClipType)
{
	if (nClipType == SimplexClip::ClipType_Vedio)
	{
		return TrackBase::TrackType_Vedio;
	}
	else if (nClipType == SimplexClip::ClipType_Effect)
	{
		return TrackBase::TrackType_Effect;
	}
	else if (nClipType == SimplexClip::ClipType_Audio)
	{
		return TrackBase::TrackType_Audio;
	}
	return TrackBase::TrackType_All;
}

ClipBase* ComplexClipController::AddClip(int nTrackIndexTo, int nPosTo, NLETimeline *pSrc, int nClipType, bool bForceCreate)
{
	GUID guid = pSrc->GetGuid();
	QUuid uuid(guid.Data1,guid.Data2,guid.Data3
		,guid.Data4[0]
		, guid.Data4[1]
		, guid.Data4[2]
		, guid.Data4[3]
		, guid.Data4[4]
		, guid.Data4[5]
		, guid.Data4[6]
		, guid.Data4[7]);
	QString strAncestralGuid = uuid.toString();
	ClipBase *pClip = CreateSimplexClip(nClipType, pSrc->Clone(), strAncestralGuid);

	if (!pClip) return nullptr;
	pClip->SetStartAtTrack(nPosTo);
	pClip->SetParentClip(m_pCurComplexClip);

	int nTrackType = TrackTypeFromClipType(nClipType);
	int nVedioTrackCnt = m_pTrackManager->GetTrackCount(TrackBase::TrackType_Vedio);
	int nEffectTrackCnt = m_pTrackManager->GetTrackCount(TrackBase::TrackType_Effect);
	if ((nTrackIndexTo == nVedioTrackCnt && nTrackType == TrackBase::TrackType_Vedio)
		||(nTrackIndexTo == nVedioTrackCnt + nEffectTrackCnt && nTrackType == TrackBase::TrackType_Effect)
		||(nTrackIndexTo == m_pTrackManager->GetTrackCount() && nTrackType == TrackBase::TrackType_Audio))
	{
		TrackBase* pNewTrack = m_pTrackManager->CreateTrack(nTrackType);
		m_pTrackManager->BeginComposite();
		m_pTrackManager->AddTrack(pNewTrack, nTrackIndexTo);
		pNewTrack->AddClip(pClip);
		m_pTrackManager->EndComposite();
		return pClip;
	}

	TrackBase* pTrackTo = m_pTrackManager->GetTrack(nTrackIndexTo);
	if (!pTrackTo) return nullptr;
	
	if (!pTrackTo->IsCompatibled(pClip)) return nullptr;

	bool bCollided = IsCollided(pTrackTo, nPosTo, pClip);
	if (bCollided || bForceCreate)
	{
		TrackBase* pNewTrack = m_pTrackManager->CreateTrack(pTrackTo->GetType());
		m_pTrackManager->BeginComposite();
		m_pTrackManager->AddTrack(pNewTrack, nTrackIndexTo);
		pNewTrack->AddClip(pClip);
		m_pTrackManager->EndComposite();
	}
	else
	{
		pTrackTo->AddClip(pClip);
	}

	return pClip;
}

void ComplexClipController::MoveClip(int nTrackIndexTo, int nPosTo, bool bForceCreate)
{
	ClipBase* pClip = GetSelectedClip();
	TrackBase* pTrackFrom = GetTrack(pClip);
	if (!pTrackFrom) return;

	int nVedioTrackCnt = m_pTrackManager->GetTrackCount(TrackBase::TrackType_Vedio);
	int nEffectTrackCnt = m_pTrackManager->GetTrackCount(TrackBase::TrackType_Effect);
	if ((nTrackIndexTo == nVedioTrackCnt && pTrackFrom->GetType() == TrackBase::TrackType_Vedio) ||
		(nTrackIndexTo == nVedioTrackCnt + nEffectTrackCnt && pTrackFrom->GetType() == TrackBase::TrackType_Effect) ||
		(nTrackIndexTo == m_pTrackManager->GetTrackCount() && pTrackFrom->GetType() == TrackBase::TrackType_Audio))
	{
		TrackBase* pNewTrack = m_pTrackManager->CreateTrack(pTrackFrom->GetType());
		m_pTrackManager->BeginComposite();
		m_pTrackManager->AddTrack(pNewTrack, nTrackIndexTo);
		pTrackFrom->MoveClip(pClip, pNewTrack, nPosTo);
		m_pTrackManager->EndComposite();
		return;
	}

	TrackBase* pTrackTo = m_pTrackManager->GetTrack(nTrackIndexTo);
	if (!pTrackTo) return;
	if (pTrackFrom->GetType() != pTrackTo->GetType()) return;

	bool bCollided = IsCollided(pTrackTo, nPosTo, pClip);
	//ͬһ���������
	if (pTrackTo == pTrackFrom)
	{
		if (bCollided || bForceCreate) //bForceCreate : �߼�������������ײ����ʵ����UI������ײ��
		{
			TrackBase* pNewTrack = m_pTrackManager->CreateTrack(pTrackFrom->GetType());
			m_pTrackManager->BeginComposite();
			m_pTrackManager->AddTrack(pNewTrack, nTrackIndexTo);
			pTrackFrom->MoveClip(pClip, pNewTrack, nPosTo);
			m_pTrackManager->EndComposite();
		}
		else
		{
			pTrackFrom->MoveClip(pClip, pTrackTo, nPosTo);
		}
		return;
	}

	//��ͬ�������
	int nTrackFromClipCnt = pTrackFrom->GetClips().size();
	if (bCollided || bForceCreate)   //bForceCreate : �߼�������������ײ����ʵ����UI������ײ��
	{
		if (nTrackFromClipCnt == 1)
		{
			m_pTrackManager->BeginComposite();
			m_pTrackManager->SwapTrack(pTrackFrom, pTrackTo);
			pTrackFrom->MoveClip(pClip, pTrackFrom, nPosTo);
			m_pTrackManager->EndComposite();
		}
		else
		{
			TrackBase* pNewTrack = m_pTrackManager->CreateTrack(pTrackFrom->GetType());
			m_pTrackManager->BeginComposite();
			m_pTrackManager->AddTrack(pNewTrack, nTrackIndexTo);
			pTrackFrom->MoveClip(pClip, pNewTrack, nPosTo);
			m_pTrackManager->EndComposite();
		}
	}
	else
	{
		pTrackFrom->MoveClip(pClip, pTrackTo, nPosTo);
	}
}

void ComplexClipController::CopyFrom(bool bCut)
{
	ClipBase *pClip = GetSelectedClip();
	if (!pClip) return;

	if (m_pCopyedClip) SAFE_DELETE(m_pCopyedClip);
	m_pCopyedClip = pClip->Clone();
	if (!m_pCopyedClip) return;
	m_pCopyedClip->Select(false);
	//Ϊ���޸��������timeline���Ⱥ�ԭ���Ȳ�һ�µ�bug��������
	m_pCopyedClip->GetSrcTimeline()->SetRange(pClip->GetSrcTimeline()->GetRange().x(), pClip->GetSrcTimeline()->GetRange().y());

	if (!bCut) return;

	TrackBase* pTrackFrom = GetTrack(pClip);
	if (!pTrackFrom) return;
	pTrackFrom->RemoveClip(pClip);
}

ClipBase* ComplexClipController::CopyTo(int nPosTo)
{
	if (!m_pCopyedClip)	return nullptr; 
	TrackBase* pTrackTo = m_pCopyedClip->GetOwnerTrack();
	if (!m_pTrackManager->GetTracks().contains(pTrackTo)) return nullptr;
	

	ClipBase* pClipCopyed = m_pCopyedClip->Clone();
	pClipCopyed->SetStartAtTrack(nPosTo);
	pClipCopyed->SetThumbnailTotalLength(-1);

	//Ϊ���޸��������timeline���Ⱥ�ԭ���Ȳ�һ�µ�bug��������
	pClipCopyed->GetSrcTimeline()->SetRange(m_pCopyedClip->GetSrcTimeline()->GetRange().x(), m_pCopyedClip->GetSrcTimeline()->GetRange().y()); 
	bool bCollided = IsCollided(pTrackTo, nPosTo, pClipCopyed);
	if (bCollided)
	{
		TrackBase* pNewTrack = m_pTrackManager->CreateTrack(pTrackTo->GetType());
		m_pTrackManager->BeginComposite();
		m_pTrackManager->AddTrack(pNewTrack, pTrackTo->GetIndex());
		pNewTrack->AddClip(pClipCopyed);
		m_pTrackManager->EndComposite();
	}
	else
	{
		pTrackTo->AddClip(pClipCopyed);
	}
	return pClipCopyed;
}

void ComplexClipController::SplitClip(int nPos)
{
	ClipBase* pClip = GetSelectedClip();
	if (!pClip) return;

	if (nPos <= pClip->GetStartAtTrack() || nPos > pClip->GetStartAtTrack() + pClip->GetLenAtTrack() - 1)
	{
		return;
	}

	int nOffset = nPos - pClip->GetStartAtTrack();
	if (nOffset < 0) return;
	TrackBase *pTrack = GetTrack(pClip);
	if (pTrack) pTrack->SplitClip(pClip, nOffset);
}

void ComplexClipController::RemoveClip()
{
	ClipBase *pSelectedClip = GetSelectedClip();
	if (!pSelectedClip) return;
	TrackBase *pTrack = GetTrack(pSelectedClip);
	if (pTrack) pTrack->RemoveClip(pSelectedClip);
}

void ComplexClipController::AdjustClip(int nLeftOrRight, int nPosTo)
{
	ClipBase *pSelectedClip = GetSelectedClip();
	if (!pSelectedClip) return;
	TrackBase *pTrack = GetTrack(pSelectedClip);

	int nNewStart = 0;
	int nNewLen = 0;

	if (nLeftOrRight == 0)
	{
		nNewStart = nPosTo;
		nNewLen = pSelectedClip->GetLenAtTrack() + pSelectedClip->GetStartAtTrack() - nNewStart;
	}
	else
	{
		nNewStart = pSelectedClip->GetStartAtTrack();
		nNewLen =  nPosTo - pSelectedClip->GetStartAtTrack();
	}
	pTrack->AdjustClip(pSelectedClip, nNewStart, nNewLen);
}

void ComplexClipController::CropClip()
{
	ClipBase *pSelectedClip = GetSelectedClip();
	Q_ASSERT(pSelectedClip);
	NLETimeline *pSelectedTimeline = pSelectedClip->GetSrcTimeline();
	NLETimeline *pDestTimeline = pSelectedTimeline->Clone();

	MediaCropDialog dlg(pDestTimeline, gGetMainWindow());
	if (dlg.DoModal())
	{
		QRectF newRegion = pDestTimeline->GetCropRegion();
		pSelectedClip->GetOwnerTrack()->CropClip(pSelectedClip, newRegion);
	}

	SAFE_DELETE(pDestTimeline);
}

//------------------------------------------------------------------------------
#include "inc_CaptionEditorView/nlecaptioneditorview.h"

void ComplexClipController::TextEdit()
{
//#ifdef WIN32
	ClipBase *pSelectedClip = GetSelectedClip();

	if (pSelectedClip && pSelectedClip->GetSrcTimeline()->GetExactType() == ExactType_Caption)
	{
		NLETimeline *captionTimeline = pSelectedClip->GetSrcTimeline();

		ClipBase *parentClip = pSelectedClip->ParentClip();
		Q_ASSERT(parentClip);
		NLETimeline *playerTimeline = parentClip->GetSrcTimeline();

		auto cloneCaptionTimeline = captionTimeline->Clone();
		NLECaptionEditorView dlg(gGetMainWindow());
		if (!dlg.DoModal(captionTimeline, playerTimeline))
		{
			playerTimeline->RemoveClip(captionTimeline);
			playerTimeline->AddClip(cloneCaptionTimeline);
			cloneCaptionTimeline->SetRange(captionTimeline->GetTrimin(), captionTimeline->GetTrimout());
			cloneCaptionTimeline->SetPosition(captionTimeline->GetPosition());
			pSelectedClip->SetSrcTimeline(cloneCaptionTimeline);
		}
	}


//#endif
}

void ComplexClipController::SelectClip(int nTrackIndexAt, int nPosAt)
{
	m_pTrackManager->SelectClip(nTrackIndexAt, nPosAt);
}

void ComplexClipController::UnselectAll(bool bForceUpdate)
{
	m_pTrackManager->UnselectAll(bForceUpdate);
}

ClipBase* ComplexClipController::GetSelectedClip()
{
	return m_pTrackManager->GetSelectedClip();
}

ComplexClip* ComplexClipController::GetComplexClip()
{
	return m_pCurComplexClip;
}

void ComplexClipController::ConvertToComplex()
{
	ClipBase *pSelectedClip = GetSelectedClip();
	if (!pSelectedClip) return;
	if (pSelectedClip->GetType() == ClipBase::ClipType_Complex) return;

	SimplexClip *pClip = dynamic_cast<SimplexClip*>(pSelectedClip);
	if (!pClip) return;

	ComplexClip *pComplexClip = CreateComplexClip(pClip);
	if (!pComplexClip) return;
	pComplexClip->Select(true);
	pComplexClip->SetParentClip((ComplexClip *)parent());

	TrackBase *pTrack = GetTrack(pSelectedClip);
	if (!pTrack) return;

	m_pTrackManager->BeginComposite();
	pTrack->AddClip(pComplexClip);
	pTrack->RemoveClip(pSelectedClip);
	m_pTrackManager->EndComposite();
}



TrackBase* ComplexClipController::GetTrack(ClipBase* pClip)
{
	for (TrackBase* pTrack : m_pTrackManager->GetTracks())
	{
		if (pTrack->GetClips().contains(pClip))
		{
			return  pTrack;
		}
	}
	return nullptr;
}

TrackManager* ComplexClipController::GetTrackManager()
{
	return m_pTrackManager;
}

bool ComplexClipController::IsCollided(TrackBase* pTrackTo, int nPosTo, ClipBase *pSrcClip)
{
	int nLeft1, nRight1, nLeft2, nRight2;
	nLeft2 = nPosTo;
	nRight2 = nLeft2 + pSrcClip->GetLenAtTrack() - 1;
	for (ClipBase *pClip : pTrackTo->GetClips())
	{
		if (pClip == pSrcClip) continue;
		nLeft1 = pClip->GetStartAtTrack();
		nRight1 = nLeft1 + pClip->GetLenAtTrack() - 1;

		if (nLeft1 > nRight2 || nLeft2 > nRight1)
		{
			continue;
		}
		else
		{
			return  true;
		}
	}
	return false;
}

SimplexClip* ComplexClipController::CreateSimplexClip(int nClipType, NLETimeline* pSrc, const QString &strAncestralGuid)
{
	if (!pSrc) return nullptr;
	SimplexClip *pClip = nullptr;
	if (nClipType == SimplexClip::ClipType_Vedio)
	{
		pClip = new VedioClip(pSrc, nullptr, strAncestralGuid);
		connect(pClip, &ClipBase::signalThumbnailAvalible, m_pTrackManager, &TrackManager::signalThumbnailAvalible);
	}
	else if (nClipType == SimplexClip::ClipType_Effect)
	{
		pClip = new EffectClip(pSrc, nullptr, strAncestralGuid);
	}
	else if (nClipType == SimplexClip::ClipType_Audio)
	{
		pClip = new AudioClip(pSrc, nullptr, strAncestralGuid);
	}
	return pClip;
}

ComplexClip* ComplexClipController::CreateComplexClip(SimplexClip* pSrcClip)
{
	SimplexClip* pClip = (SimplexClip*)pSrcClip->Clone();
	if (!pClip) return nullptr;

	ComplexClip *pComClip = new ComplexClip();
	pComClip->SetStartAtTrack(pClip->GetStartAtTrack());
	pClip->SetStartAtTrack(0);
	pComClip->GetComplexClipController()->GetTrackManager()->GetTrack(0)->AddClip(pClip);
	pComClip->GetComplexClipController()->GetTrackManager()->GetUndoStack()->clear();

	pComClip->GetSrcTimeline()->SetRange(0,pClip->GetSrcTimeline()->GetPlayLen() - 1);

	pClip->SetParentClip(pComClip);
	pClip->SetThumbnailTotalLength(pSrcClip->GetThumbnailTotalLength());

	return pComClip;
}
