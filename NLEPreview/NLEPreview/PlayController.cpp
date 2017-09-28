#include "stdafx.h"
//#ifndef min
//#define min(a,b) (a) < (b) ? (a) : (b)
//#endif 
//#ifndef max
//#define max(a,b) (a) > (b) ? (a) : (b)
//#endif
#include "PlayController.h"
#include "inc_MatterView/matterview.h"
#include "inc_TimelineView/TimelineView.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_MediaPlayerView/MediaPlayerControl.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_MediaPlayerView/MediaPlayerView.h"
#include "inc_CommonLib/NLETimeline.h"


PlayController::PlayController(MatterView *pMatterView, TimelineView *pTimelineView, MediaPlayerView *pMediaPlayerView, QObject *parent)
	: QObject(parent)
	, m_seekingIsPlaying(false)
{
	m_eLoadedType = RenderLoadedType_None;
	m_pMatterView = pMatterView;
	m_pTimelineView = pTimelineView;
	m_pMediaPlayerView = pMediaPlayerView;
	m_pPlayer = NLEWraper::GetInstance().GetMeidaPlayerControl();
	

	connect(m_pPlayer, &IMediaPlayerControl::PlayingCallback, this, [&](int nFrame){
		if (m_eLoadedType == RenderLoadedType_TimelineView)
			m_pTimelineView->SetCurrentFrame(nFrame);
	});
	connect(m_pPlayer, &IMediaPlayerControl::RulerSeekCallback, this, [&](int nFrame){
		if (m_eLoadedType == RenderLoadedType_TimelineView) 
			m_pTimelineView->SetCurrentFrame(nFrame);
	});

	connect(m_pMatterView, &MatterView::signalLoad, this, [&](bool bPlay){
		m_eLoadedType = RenderLoadedType_MatterView;
		MainMediaPlayerView* pView = qobject_cast<MainMediaPlayerView*>(m_pMediaPlayerView);
		//if (pView) pView->SetLoadType(false);

		if (!m_pPlayer->Close()) return;
		auto *pTimeline = m_pMatterView->GetTimeline();
		if (!pTimeline) return;
		if (!m_pPlayer->Open(1, pTimeline)) return;
 		if (!bPlay) return;
		//if (!m_pPlayer->Seek(0, 0)) return;
		m_pPlayer->Play();
	});

	connect(m_pMatterView, &MatterView::signlaUnload, this, [&](){
		if (m_eLoadedType == RenderLoadedType_TimelineView) return;
		
		LoadTimeline();
	});

	connect(m_pTimelineView, &TimelineView::SeekTo, this, [&](int nSeekTo){
		if (m_eLoadedType != RenderLoadedType_TimelineView) return;
		m_pPlayer->Seek(nSeekTo, 0);
	});

	connect(m_pTimelineView, &TimelineView::StartSeekTo, this, [&](){
		if (m_eLoadedType != RenderLoadedType_TimelineView) return;
		m_seekingIsPlaying = m_pPlayer->IsPlaying();
		if (m_seekingIsPlaying)
			m_pPlayer->Pause();

	});

	connect(m_pTimelineView, &TimelineView::EndSeekTo, this, [&](){
		if (m_eLoadedType != RenderLoadedType_TimelineView) return;
		if (m_seekingIsPlaying)
		{
			m_seekingIsPlaying = false;
			m_pPlayer->Play();
		}
	});

	connect(m_pTimelineView, &TimelineView::Pause, this, [&](){
		m_pPlayer->Pause();
	});
	connect(m_pTimelineView, &TimelineView::DurationChanged, this, [&](){
		m_pPlayer->DurationChanged();
	});
	connect(m_pTimelineView, &TimelineView::ComplexClipChanged, this, [&](NLETimeline *timeline){
		_LoadTimeline(timeline);
	});	


	//MainMediaPlayerViewEx* pView = dynamic_cast<MainMediaPlayerViewEx*>(m_pMediaPlayerView);
	//connect(m_pTimelineView, &TimelineView::sigSelectChanged, pView, &MainMediaPlayerViewEx::SetSeletedTimeline);
}

PlayController::~PlayController()
{

}

void PlayController::LoadTimeline()
{
	auto *pTimelineBase = m_pTimelineView->GetNLETimeline();
	if (!pTimelineBase)
		return;
	_LoadTimeline(pTimelineBase);
}

void PlayController::_LoadTimeline(NLETimeline *pTimelineBase)
{
	if (!m_pPlayer->Close()) return;
	if (!m_pPlayer->Open(1, pTimelineBase)) return;
	m_pPlayer->Seek(m_pTimelineView->GetCurrentFrame(), 0);
	m_eLoadedType = RenderLoadedType_TimelineView;

	//MainMediaPlayerViewEx* pView = dynamic_cast<MainMediaPlayerViewEx*>(m_pMediaPlayerView);
	//if (pView) pView->SetLoadType(true);
}
