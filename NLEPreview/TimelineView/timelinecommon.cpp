#include "stdafx.h"
#include "timelinecommon.h"

#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/CommonWidgets.h"

#include "inc_CommonLib/TimelineRuler.h"

#include "timelineviewtrack.h"
#include "timelineviewprivate.h"



//////////////////////////////////////////////////////////////////////////
TimelineScrollBar::TimelineScrollBar(Qt::Orientation orientation, QWidget *parent)
:QScrollBar(orientation, parent)
{
	m_isPressDown = false;
}

bool TimelineScrollBar::IsPressDown()
{
	return m_isPressDown;
}

void TimelineScrollBar::mousePressEvent(QMouseEvent *event)
{
	m_isPressDown = true;
	QScrollBar::mousePressEvent(event);
}

void TimelineScrollBar::mouseReleaseEvent(QMouseEvent *event)
{
	m_isPressDown = false;
	QScrollBar::mouseReleaseEvent(event);
}

//////////////////////////////////////////////////////////////////////////
TrackSetButton::TrackSetButton(QWidget *parent)
:QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground);
	setObjectName("TimelineView_TimelineViewTrackRuler_TrackSet_Background");
	m_btn = new BaseButton(0, "TimelineView_TimelineViewTrackRuler_TrackSet", this);
	connect(m_btn, &BaseButton::Clicked, this, &TrackSetButton::Clicked);
}

void TrackSetButton::resizeEvent(QResizeEvent *event)
{
	m_btn->setGeometry(rect());
}



//////////////////////////////////////////////////////////////////////////
TimelineViewTrackRulerToolBarState::TimelineViewTrackRulerToolBarState(TimelineViewTrackRulerToolBar *toolbar, TimelineViewTrack *track, QObject *parent)
:QObject(parent)
{
	Q_ASSERT(toolbar);
	Q_ASSERT(track);
	m_toolbar = toolbar;
	m_track = track;

	connect(m_track, &TimelineViewTrack::TrackStateChanged, this, &TimelineViewTrackRulerToolBarState::TrackStateChanged, Qt::QueuedConnection);
}

void TimelineViewTrackRulerToolBarState::TrackStateChanged(int state)
{
	auto timelineMgr = m_track->GetTimelineManager();
	auto selectClip = timelineMgr->GetSelectedClip();
	if (state == TimelineViewTrack::State_FrameChanged)
	{

	}
	else if (state == TimelineViewTrack::State_ClipChanged)
	{
		m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_Delete, selectClip);

		m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_Crop, selectClip && selectClip->IsCropable());
		m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_TextEdit, selectClip && selectClip->GetType() == ClipBase::ClipType_Effect);

		m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_Redo, m_track->GetTimelineManager()->CanRedo());
		m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_Undo, m_track->GetTimelineManager()->CanUndo());

		m_track->ResetRootClipLength();
	}

	bool cutEnabled = false;
	if (selectClip)
	{
		auto curFrames = m_track->CurrentFrames();
		cutEnabled = (curFrames > selectClip->GetStartAtTrack() && curFrames < selectClip->GetStartAtTrack() + selectClip->GetLenAtTrack());
	}
	m_toolbar->SetButtonEnabled(TimelineViewTrackRulerToolBar::TrackRulerToolBar_Cut, cutEnabled);

}

