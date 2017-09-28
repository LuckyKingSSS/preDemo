#include "stdafx.h"
#include "ClipBase.h"
#include "ComplexClipController.h"
#include "INLETimelineBase.h"
#include "NLEWraper.h"
#include "PlayerMaterProvider.h"
#include "TrackBase.h"
#include "ThumbnailExtractor.h"
#include "TrackManager.h"
#include "OperatorBase.h"
ClipBase::ClipBase(int nType, TrackBase* pOwnerTrack, QObject *parent)
:QObject(parent)
{
	m_pParentClip = nullptr;
	m_nClipType = nType;
	m_bSelected = false;
	m_nStartAtTrack = 0;
	m_pSrc = nullptr;
	m_pOwnerTrack = pOwnerTrack;
}

ClipBase::~ClipBase()
{

}

ClipBase::ClipBase(QObject *parent)
:QObject(parent)
{

}

void ClipBase::CloneAble(ClipBase* pAnther)
{
	this->m_nClipType = pAnther->m_nClipType;
	this->m_bSelected = pAnther->m_bSelected;
	this->m_nStartAtTrack = pAnther->m_nStartAtTrack;
	this->m_pOwnerTrack = pAnther->m_pOwnerTrack;
	this->m_pSrc = pAnther->m_pSrc->Clone();
	this->m_pParentClip = pAnther->m_pParentClip;
}

int ClipBase::GetStartAtTrack() const
{
	return m_nStartAtTrack;
}

void ClipBase::SetStartAtTrack(int nNewPos)
{
	m_nStartAtTrack = nNewPos;
}

int ClipBase::GetLenAtTrack() const
{

	return m_pSrc ? m_pSrc->GetPlayLen() : 0;
}


int ClipBase::GetStartAtSrc() const
{
	return m_pSrc ? m_pSrc->GetTrimin() : 0;
}

int ClipBase::GetSrcLen() const
{
	return m_pSrc ? m_pSrc->GetTotalLength() : 0;
}


bool ClipBase::IsSelected() const
{
	return m_bSelected;
}

void ClipBase::Select(bool bSelected)
{
	this->m_bSelected = bSelected;
}

bool ClipBase::IsCropable()
{
	if (m_nClipType == ClipType_Vedio) return true;
	return false;
}

NLETimeline *ClipBase::GetSrcTimeline()
{
	return m_pSrc;
}

void ClipBase::SetSrcTimeline(NLETimeline *pSrc)
{
	if (m_pSrc)
		delete m_pSrc;
	this->m_pSrc = pSrc;
}

int ClipBase::GetType() const
{
	return m_nClipType;
}

QString ClipBase::GetName() const
{
	return m_pSrc->GetName();
}

ClipBase* ClipBase::PreClip()
{
	if (!m_pOwnerTrack) return nullptr;
	return m_pOwnerTrack->GetPreClip(this);
}

ClipBase* ClipBase::NextClip()
{
	if (!m_pOwnerTrack) return nullptr;
	return m_pOwnerTrack->GetNextClip(this);
}

void ClipBase::SetOwnerTrack(TrackBase* pOwner)
{
	m_pOwnerTrack = pOwner;
}

TrackBase* ClipBase::GetOwnerTrack()
{
	return m_pOwnerTrack;
}

int ClipBase::GetThumbnailTotalLength()
{
	return 0;
}

ClipBase* ClipBase::ParentClip()
{
	return m_pParentClip;
}

void ClipBase::SetParentClip(ClipBase *pParentClip)
{
	m_pParentClip = pParentClip;
}

/************************************************************************/
/*        ComplexClip                                                   */
/************************************************************************/
ComplexClip::ComplexClip(TrackBase* pOwnerTrack, QObject *parent)
:ClipBase(ClipBaseType::ClipType_Complex, pOwnerTrack, parent)
{
	m_nSeekPos = 0;
	NLEComPtr<INLETimelineBase> pSrcTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateEmptyTimeline();
	m_pSrc = new NLETimeline(pSrcTimeline);
	m_pSrc->SetName("ComplexClip");
	m_pComplexClipController = new ComplexClipController(m_pSrc,this);
}

ComplexClip::ComplexClip(QObject *parent)
:ClipBase(parent)
{
}

ComplexClip::~ComplexClip()
{

}

ComplexClipController* ComplexClip::GetComplexClipController()
{
	return m_pComplexClipController;
}

void ComplexClip::CloneAble(ClipBase* pAnther)
{
	ClipBase::CloneAble(pAnther);
	ComplexClip* pClip = dynamic_cast<ComplexClip*>(pAnther);
	m_nSeekPos = pClip->m_nSeekPos;
	m_pComplexClipController = new  ComplexClipController(m_pSrc, this);
	m_pComplexClipController->GetTrackManager()->m_pTrackOperator->Clear();

	TrackBase *pNewTrack = nullptr;
	for (TrackBase *pTrack : pClip->GetComplexClipController()->GetTrackManager()->m_pTrackOperator->m_listTracks)
	{
		pNewTrack = pTrack->Clone();
		pNewTrack->SetTrackManager(m_pComplexClipController->GetTrackManager());
		m_pComplexClipController->GetTrackManager()->m_pTrackOperator->m_listTracks.push_back(pNewTrack);
	}
}

ClipBase* ComplexClip::Clone()
{
	ComplexClip *pNew = new ComplexClip((QObject*)nullptr);
	pNew->CloneAble(this);
	return pNew;
}

void ComplexClip::SetThumbnailTotalLength(int nLen)
{ 
	for (TrackBase* pTrack : m_pComplexClipController->GetTrackManager()->GetTracks())
	{
		if (pTrack->GetType() != TrackBase::TrackType_Vedio) continue;
		
		for (ClipBase *pClip : pTrack->GetClips())
		{
			if (pClip->GetType() != ClipBase::ClipType_Vedio) continue;
			pClip->SetThumbnailTotalLength(pClip->GetThumbnailTotalLength());
		}
	}
}

void ComplexClip::SetSeekPos(int nPos)
{
	m_nSeekPos = nPos;
}

int ComplexClip::GetSeekPos()
{
	return m_nSeekPos;
}

/************************************************************************/
/*        SimplexClip                                                   */
/************************************************************************/
SimplexClip::SimplexClip(NLETimeline *pSrc, int nType, TrackBase* pOwnerTrack, const QString &strAncestralGuid, QObject *parent)
: ClipBase(nType,pOwnerTrack, parent)
{
	m_pSrc = pSrc;
	if(m_pSrc) m_pSrc->SetAncestralGuid(strAncestralGuid);
}

SimplexClip::~SimplexClip()
{
	SAFE_DELETE(m_pSrc);
}

SimplexClip::SimplexClip(QObject *parent)
:ClipBase(parent)
{

}
void SimplexClip::CloneAble(ClipBase* pAnther)
{
	ClipBase::CloneAble(pAnther);
}


ClipBase* SimplexClip::Clone()
{
	SimplexClip *pNewClip = new SimplexClip();
	pNewClip->CloneAble(this);
	return pNewClip;
}


/************************************************************************/
/*                  VedioClip                                           */
/************************************************************************/
VedioClip::VedioClip(NLETimeline* pSrc, TrackBase* pOwnerTrack, const QString &strAncestralGuid, QObject *parent)
:SimplexClip(pSrc, ClipBase::ClipType_Vedio, pOwnerTrack, strAncestralGuid,parent)
{
	m_pThumbnailExtractor = new ThumbnailExtractor(m_pSrc,this);
	connect(m_pThumbnailExtractor, &ThumbnailExtractor::signalGetNeededThumbnail, this, [&]{
		emit signalThumbnailAvalible(this);
	});
}

VedioClip::VedioClip(QObject *parent)
:SimplexClip(parent)
{
}

VedioClip::~VedioClip()
{
	m_pThumbnailExtractor->Stop();	
	m_pThumbnailExtractor->WaitForQuit();
}

void VedioClip::CloneAble(ClipBase* pAnther)
{
	SimplexClip::CloneAble(pAnther);

	VedioClip* pAntherV = dynamic_cast<VedioClip*>(pAnther);


	m_pThumbnailExtractor = new ThumbnailExtractor(m_pSrc, this);
	m_pThumbnailExtractor->m_nShowLen = pAntherV->GetThumbnailTotalLength();
	connect(m_pThumbnailExtractor, &ThumbnailExtractor::signalGetNeededThumbnail, this, [&]{
		emit signalThumbnailAvalible(this);
	});
}

ClipBase* VedioClip::Clone()
{
	VedioClip *pNew = new VedioClip();
	pNew->CloneAble(this);
	connect(pNew, &ClipBase::signalThumbnailAvalible, pNew->GetOwnerTrack()->GetTrackManager(), &TrackManager::signalThumbnailAvalible);
	return pNew;
}

void VedioClip::SetThumbnailTotalLength(int nLen)
{
	m_pThumbnailExtractor->SetTotalLen(nLen);
}

int VedioClip::GetThumbnailTotalLength()
{
	return m_pThumbnailExtractor->GetTotalLen();
}

QSize VedioClip::GetThumbnailSize()
{
	return m_pThumbnailExtractor->GetThumbnailSize();
}

QList<QPixmap> VedioClip::GetThumbnails()
{
	return m_pThumbnailExtractor->GetThumbnails();
}

/************************************************************************/
/*                  AudioClip                                           */
/************************************************************************/
AudioClip::AudioClip(NLETimeline* pSrc, TrackBase* pOwnerTrack, const QString &strAncestralGuid, QObject *parent)
:SimplexClip(pSrc, ClipBase::ClipType_Audio, pOwnerTrack, strAncestralGuid, parent)
{

}
AudioClip::~AudioClip()
{

}

/************************************************************************/
/*                  AudioClip                                           */
/************************************************************************/
EffectClip::EffectClip(NLETimeline* pSrc, TrackBase* pOwnerTrack, const QString &strAncestralGuid, QObject *parent)
:SimplexClip(pSrc, ClipBase::ClipType_Effect, pOwnerTrack, strAncestralGuid, parent)
{

}

EffectClip::EffectClip(QObject *parent /*= nullptr*/)
: SimplexClip(parent)
{

}

EffectClip::~EffectClip()
{

}

ClipBase* EffectClip::Clone()
{
	EffectClip *pNew = new EffectClip();
	pNew->CloneAble(this);
	//connect(pNew, &ClipBase::signalThumbnailAvalible, pNew->GetOwnerTrack()->GetTrackManager(), &TrackManager::signalThumbnailAvalible);
	return pNew;
}

int EffectClip::GetStartAtTrack() const
{
	return ClipBase::GetStartAtTrack();
}

void EffectClip::SetStartAtTrack(int nNewPos)
{
	return ClipBase::SetStartAtTrack(nNewPos);
}

int EffectClip::GetLenAtTrack() const
{
	return ClipBase::GetLenAtTrack();
}

int EffectClip::GetStartAtSrc() const
{
	return INT_MAX / 2;
}

int EffectClip::GetSrcLen() const
{
	return INT_MAX;
}

