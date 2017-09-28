#include "stdafx.h"
#include "timelineviewprivate.h"
#include "inc_TimelineView/timelineview_global.h"
#include "inc_CommonLib/CommonWidgets.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_CommonLib/NLEBaseWidget.h"
#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/TimelineRuler.h"
#include "inc_MatterView/matterview.h"

#include "timelineviewtrack.h"
#include "Tools/MediaCropDialog.h"

#include "TimelineManager/ClipBase.h"
#include "inc_MatterView/MatterDataDefine.h"

#include "Shared/NLECommon.h"
#include "Include/NLEKey.h"
#include "Include/NLEPropComPtr/NLERenderPropComPtr.h"
#include "inc_CaptionEditorView/nlecaptioneditorview.h"


TimelineView::TimelineView(QWidget *parent /*= nullptr*/)
:NLEBaseWidget(parent)
{
	
	m_p = new TimelineViewPrivate(this);
	connect(m_p, &TimelineViewPrivate::StartSeekTo, this, &TimelineView::StartSeekTo);
	connect(m_p, &TimelineViewPrivate::EndSeekTo, this, &TimelineView::EndSeekTo);
	connect(m_p, &TimelineViewPrivate::SeekTo, this, &TimelineView::SeekTo);
	connect(m_p, &TimelineViewPrivate::Play, this, &TimelineView::Play);
	connect(m_p, &TimelineViewPrivate::Pause, this, &TimelineView::Pause);
	connect(m_p, &TimelineViewPrivate::DurationChanged, this, &TimelineView::DurationChanged);
	connect(m_p, &TimelineViewPrivate::ComplexClipChanged, this, &TimelineView::ComplexClipChanged);
	connect(m_p, &TimelineViewPrivate::TimelineSelectChanged, this, &TimelineView::TimelineSelectChanged);
	connect(m_p, &TimelineViewPrivate::TimelineDoubleSelectChanged, this, &TimelineView::TimelineDoubleSelectChanged);
	connect(m_p, &TimelineViewPrivate::TimelineDelete, this, &TimelineView::TimelineDelete);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(m_p);
	setLayout(layout);

	setStyleSheet(gGetStyleSheet(":/TimelineViewPrivate/Resources/styles.qss"));
}

int TimelineView::GetCurrentFrame()
{
	return m_p->GetCurrentFrame();
}

void TimelineView::SetCurrentFrame(int frames)
{
	m_p->SetCurrentFrame(frames);
}



NLETimeline* TimelineView::GetNLETimeline()
{
	return m_p->GetNLETimeline();
}

//////////////////////////////////////////////////////////////////////////

TimelineViewPrivate::TimelineViewPrivate(QWidget *parent)
:QWidget(parent)
, m_realTopPosition(0)
, m_scrollbarValue(1)
, m_seekManual(false)
{
	setAutoFillBackground(true);
	
	m_btnTrackSet = new TrackSetButton(this);
	connect(m_btnTrackSet, &TrackSetButton::Clicked, [&](){
		//QMessageBox::information(nullptr, "hehe", "u can u up.");
	});


	m_ruler = new TimelineRuler(this);
	m_ruler->SetFPS(25.0f);
	m_ruler->SetMousePressEmitFramesChangedEnabled(false);
	
	connect(m_ruler, &TimelineRuler::ZoomChanged, [&](int zoom)
	{
		m_toolBar->SetScaleUnitValue(zoom);

		HorizontalScrollBar();

		
		m_track->SetCurrentFrames(m_ruler->CurrentFrames());
		m_track->SetThumbnailsLength();



	});

	connect(m_ruler, &TimelineRuler::StartFramesChanged, [&]()
	{
		m_seekManual = true;
		emit StartSeekTo();
	});
	connect(m_ruler, &TimelineRuler::EndFramesChanged, [&]()
	{
		m_seekManual = false;
		emit EndSeekTo();
	});

	connect(m_ruler, &TimelineRuler::FramesChanged, [&](int frames)
	{
		InternalSeekTo(frames);
	});

	connect(m_ruler, &TimelineRuler::OffsetFramesChanged, [&](int frames)
	{
		m_track->SetOffsetFrames(frames);
		m_track->SetCurrentFrames(m_ruler->CurrentFrames());
	});

	m_toolBar = new TimelineViewTrackRulerToolBar(this);
	connect(m_toolBar, &TimelineViewTrackRulerToolBar::ButtonClicked, this, &TimelineViewPrivate::ButtonClicked);
	connect(m_toolBar, &TimelineViewTrackRulerToolBar::ScaleUnitValueChanged, this, [&](int value)
	{
		m_ruler->SetZoom(value);

		HorizontalScrollBar();

		m_track->SetCurrentFrames(m_ruler->CurrentFrames());
		m_track->SetThumbnailsLength(); 
	
	});

	connect(m_toolBar, &TimelineViewTrackRulerToolBar::StartScaleUnitValueChanged, this, [&]()
	{
		m_ruler->StartZoomAndScrollRuler();

	});
	m_ruler->SetZoom(m_toolBar->GetScaleUnitValue());

	m_track = new TimelineViewTrack(m_ruler, this);
	connect(m_track, &TimelineViewTrack::DurationChanged, [&](int duration)
	{
		//HorizontalScrollBar();

		m_ruler->SetTotalFrames(duration);

		emit DurationChanged();
	});
	connect(m_track, &TimelineViewTrack::Pause, this, &TimelineViewPrivate::Pause);
	connect(m_track, &TimelineViewTrack::TimelineTrackScrollTo, [&](int pos)
	{
		m_scrollbarV->setValue(pos);
	});
	connect(m_track, &TimelineViewTrack::TimelineTrackScrollOffset, [&](int pos)
	{
		m_scrollbarV->setValue(qMax(0, m_scrollbarV->value()+ pos));
	});

	connect(m_track, &TimelineViewTrack::ComplexClipChanged, this, &TimelineViewPrivate::ComplexClipChanged);

	connect(this, &TimelineViewPrivate::CurrentFramesOutRuler, [&](int right)
	{
		if (!m_scrollbarH->IsPressDown())
		{
			if (right)
				m_scrollbarH->setValue((m_ruler->CurrentFrames() - m_scrollbarH->value()) / 2 + m_scrollbarH->value());
			else
				m_scrollbarH->setValue((m_ruler->CurrentFrames()));
		}
	});


	auto trackState = new TimelineViewTrackRulerToolBarState(m_toolBar, m_track, this);

	m_scrollbarH = new TimelineScrollBar(Qt::Horizontal, this);
	m_scrollbarH->setRange(0, 100);
	m_scrollbarH->hide();
	connect(m_scrollbarH, &QSlider::valueChanged, this, [&](int value)
	{
		m_ruler->SetOffsetFrames(value);
	});

	m_scrollbarV = new QScrollBar(Qt::Vertical, this);
	m_scrollbarV->hide();
	m_scrollbarV->setRange(0, 0);
	connect(m_scrollbarV, &QSlider::valueChanged, this, [&](int value)
	{

		m_track->move(QPoint(0, m_ruler->geometry().bottom() - value));
		m_realTopPosition = m_track->pos().y();
	});

	connect(&m_scrollbarTimer, &QTimer::timeout, this, [&](){
		
		m_track->TimelineTrackScrollOffset(m_scrollbarValue);
	});

	connect(NLEGlobalShortcut::GetInstance(), &NLEGlobalShortcut::actived, this, &TimelineViewPrivate::GlobalShortcut);


	connect(m_track, &TimelineViewTrack::TrackStateChanged, this, [&](int nType){

		if (nType == TimelineViewTrack::State_DoubleClicked)
		{
			ClipBase *pClip = m_track->CurrentSelectClip();
			emit TimelineDoubleSelectChanged(pClip ? pClip->GetSrcTimeline() : nullptr);
			
		}
		else if (nType == TimelineViewTrack::State_ClipChanged)
		{
			static ClipBase* pSelected = nullptr;
			if (pSelected != m_track->CurrentSelectClip())
			{
				pSelected = m_track->CurrentSelectClip();
				emit TimelineSelectChanged(pSelected ? pSelected->GetSrcTimeline() : nullptr);
			}

		}

	});


	auto dragControl = TimelineDragControl::GetInstance(this);
	//connect(dragControl, &TimelineDragControl::SeekTo, this, &TimelineViewPrivate::InternalSeekTo);

	auto trimControl = TimelineTrimControl::GetInstance(this);
	connect(trimControl, &TimelineTrimControl::SeekTo, this, &TimelineViewPrivate::InternalSeekTo);



	// 确保最后一个链接信号（最后一个响应此信号，因为会修改caption timeline的指针）
	QTimer::singleShot(100, [&](){
		connect(this, &TimelineViewPrivate::TimelineDoubleSelectChanged, this, [&, this](){

			m_track->GetTimelineManager()->TextEdit();
			UpdatePlayer();
		});
	});


}

void TimelineViewPrivate::FocusResize()
{
	resizeEvent(nullptr);
}

int TimelineViewPrivate::GetCurrentFrame()
{
	return m_track->CurrentFrames();
}

void TimelineViewPrivate::SetCurrentFrame(int frames)
{
	if (m_seekManual)
		return;

	m_ruler->SetCurrentFrames(frames);
	m_track->SetCurrentFrames(frames);

	int curPos = m_ruler->Frames2PositionF(m_ruler->CurrentFrames());
	if (curPos < 0)
	{
		emit CurrentFramesOutRuler(false);
	}
	else if (curPos > m_ruler->width())
	{
		emit CurrentFramesOutRuler(true);
	}
}



NLETimeline* TimelineViewPrivate::GetNLETimeline()
{
	return m_track->GetTimelineManager()->CurrentComplexClip()->GetSrcTimeline();
}

bool TimelineViewPrivate::PositionOutOfTimelineTrack(int pos)
{
	return pos + m_track->geometry().y() > height() - m_ruler->Height() || pos + m_track->geometry().y() < m_ruler->Height();

}

void TimelineViewPrivate::AutoScrollTimelineTrack(bool start)
{
	if (start)
	{
		if (!m_scrollbarTimer.isActive())
		{
			int curCursorPos = mapFromGlobal(QCursor::pos()).y();
			if (curCursorPos < m_ruler->geometry().bottom())
			{
				m_scrollbarValue = -10;	
			}
			else
			{
				m_scrollbarValue = 10;
			}
			m_scrollbarTimer.start(100);

		}
	}
	else
	{
		m_scrollbarTimer.stop();
	}

}

void TimelineViewPrivate::HorizontalScrollBar()
{
	auto value = qMax(m_ruler->AvailableTotaleFrames(), m_track->Duration());
	m_scrollbarH->setRange(0, value);
	m_scrollbarH->show();

	int offset = m_ruler->GetZoomAndScrollRulerOffsetPosition();
	//qDebug() << "----------offset:" << offset;
	m_scrollbarH->setValue(qMax(0.0f, m_ruler->Duration2FramesF(offset)));
	//m_ruler->SetOffsetFrames(qMax(0.0f, m_ruler->Duration2FramesF(offset)));
}

void TimelineViewPrivate::ButtonClicked(int id)
{
	emit Pause();
	if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_Redo)
	{
		m_track->GetTimelineManager()->Redo();
	}
	else if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_Undo)
	{
		m_track->GetTimelineManager()->Undo();
	}
	else if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_Cut)
	{
		m_track->GetTimelineManager()->SplitClip(m_track->Ruler()->CurrentFrames());
	}
	else if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_Delete)
	{
		RemoveClip();

	}
	else if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_Crop)
	{
		m_track->GetTimelineManager()->CropClip();
		UpdatePlayer();
	}
	else if (id == TimelineViewTrackRulerToolBar::TrackRulerToolBar_TextEdit)
	{
		m_track->GetTimelineManager()->TextEdit();
		UpdatePlayer();
	}
}

void TimelineViewPrivate::resizeEvent(QResizeEvent *event)
{
	int left = 0;
	const int sliderHeight = 15;
	m_toolBar->setGeometry(left, 0, width()-sliderHeight, 40);
	int top = m_toolBar->geometry().bottom();

	m_btnTrackSet->setGeometry(left, top, TIMELINEVIEW_TRACKITEM_WIDTH_HEADER+1, m_ruler->Height());
	left = m_btnTrackSet->geometry().right();

	m_ruler->setGeometry(left, top, width() - sliderHeight - left, m_ruler->Height());
	
	if (m_realTopPosition == 0)
		top = m_ruler->geometry().bottom();
	else
		top = m_realTopPosition;

	left = 0;
	m_track->ResizeGeometry(left, top, width() - sliderHeight, m_track->Height());
	m_track->stackUnder(m_ruler);
	m_track->stackUnder(m_btnTrackSet);

	top = height() - 30;
	m_scrollbarH->setGeometry(left, height()-sliderHeight, width() - sliderHeight, sliderHeight);
	left = m_scrollbarH->geometry().right();
	top = sliderHeight;
	m_scrollbarV->setGeometry(left, top, sliderHeight, height() - 2 * sliderHeight);
	int trackHeightTemp = height() - m_ruler->geometry().bottom() - m_track->Height();
	m_scrollbarV->setVisible(trackHeightTemp < 0);
	m_scrollbarV->setRange(0, qMax(0, -trackHeightTemp) + sliderHeight);
}

void TimelineViewPrivate::wheelEvent(QWheelEvent *event)
{
	int step = event->angleDelta().y() > 0 ? -TIMELINEVIEW_TRACKITEM_WIDTH_HEADER : TIMELINEVIEW_TRACKITEM_WIDTH_HEADER;
	m_scrollbarV->setValue(qMax(0, m_scrollbarV->value() + step));
}

void TimelineViewPrivate::GlobalShortcut(int id)
{
	auto timelineManager = m_track->GetTimelineManager();
	switch (id)
	{
	case NLEGlobalShortcut::Key_Delete:
	{
		if (m_track->GetTimelineManager()->GetSelectedClip())
		{
			Pause();
			RemoveClip();
		}

	}

		break;
	case NLEGlobalShortcut::Key_Copy:
		timelineManager->CopyFrom();
		break;
	case NLEGlobalShortcut::Key_Cut:
		emit Pause();
		timelineManager->CopyFrom(true);
		break;
	case NLEGlobalShortcut::Key_Pasete:
	{
		emit Pause();
		auto clip = timelineManager->CopyTo(m_track->CurrentFrames());
		if (clip)
			clip->SetThumbnailTotalLength(m_track->Ruler()->Frames2DurationF(clip->GetLenAtTrack()));
	}
		break;
	}
}


void TimelineViewPrivate::RemoveClip()
{
	auto selectTimeline = m_track->GetTimelineManager()->GetSelectedClip();
	if (selectTimeline)
	{
		m_track->GetTimelineManager()->RemoveClip();
		if (GetCurrentFrame() > m_track->Duration())
		{
			InternalSeekTo(m_track->Duration());
		}
		else
		{
			// 更新播放器画面
			UpdatePlayer();
		}
		emit TimelineDelete(selectTimeline->GetSrcTimeline());

	}

}

void TimelineViewPrivate::UpdatePlayer()
{
	emit SeekTo(m_ruler->CurrentFrames());
}

void TimelineViewPrivate::InternalSeekTo(int frames)
{
	int totalFrames = m_track->Duration();
	if (frames > totalFrames)
	{
		frames = totalFrames;
	}
	//SetCurrentFrame(frames);
	m_ruler->SetCurrentFrames(frames);
	m_track->SetCurrentFrames(frames);
	emit SeekTo(frames);
}

//////////////////////////////////////////////////////////////////////////
TimelineViewTrackRulerToolBar::TimelineViewTrackRulerToolBar(QWidget *parent)
:QWidget(parent)
{
	setAttribute(Qt::WA_StyledBackground);
	setObjectName("TimelineView_TimelineViewTrackRulerToolBar");

	m_leftBtns << new BaseButton(TrackRulerToolBar_Undo, "TimelineView_TrackRulerToolBar_Undo", this);
	m_leftBtns << new BaseButton(TrackRulerToolBar_Redo, "TimelineView_TrackRulerToolBar_Redo", this);
	m_leftBtns << new BaseButton(TrackRulerToolBar_Cut, "TimelineView_TrackRulerToolBar_Cut", this);
	m_leftBtns << new BaseButton(TrackRulerToolBar_Delete, "TimelineView_TrackRulerToolBar_Delete", this);
	m_leftBtns << new BaseButton(TrackRulerToolBar_Crop, "TimelineView_TrackRulerToolBar_Crop", this);

	m_leftBtns << new BaseButton(TrackRulerToolBar_TextEdit, "TimelineView_TrackRulerToolBar_TextEdit", this);


	for (auto btn : m_leftBtns)
	{
		connect(btn, &BaseButton::Clicked, this, [&](int id, QPoint){
			emit ButtonClicked(id);
		});

		btn->setEnabled(false);
	}

	m_sliderScaleUnit = new ScaleUnitSlider(this);
	connect(m_sliderScaleUnit, &ScaleUnitSlider::valueChanged, this, [&](int value){
		ScaleUnitValueChanged(m_sliderScaleUnit->duration() - value);
	});

	connect(m_sliderScaleUnit, &ScaleUnitSlider::startValueChanged, this, &TimelineViewTrackRulerToolBar::StartScaleUnitValueChanged);
}

void TimelineViewTrackRulerToolBar::SetScaleUnitValue(int value)
{
	m_sliderScaleUnit->setValue(m_sliderScaleUnit->duration() - value);
}

int TimelineViewTrackRulerToolBar::GetScaleUnitValue()
{
	return m_sliderScaleUnit->value();
}

void TimelineViewTrackRulerToolBar::SetButtonEnabled(int id, bool enable)
{
	GetButton(id)->SetEnabled(enable);
}

BaseButton* TimelineViewTrackRulerToolBar::GetButton(int id)
{
	for (auto temp : m_leftBtns)
	{
		if (temp->GetId() == id)
		{
			return temp;
		}
	}
	for (auto temp : m_rightBtns)
	{
		if (temp->GetId() == id)
		{
			return temp;
		}
	}
	Q_ASSERT(false);
	return nullptr;
}

void TimelineViewTrackRulerToolBar::resizeEvent(QResizeEvent *event)
{
	int left = 30;
	int top = 10;
	const int btnw = 24;
	const int margins = 10;
	for (auto btn : m_leftBtns)
	{
		if (btn->isVisible())
		{
			btn->setGeometry(left, top, btnw, btnw);
			left = btn->geometry().right() + margins;
		}
	}

	left = width() - 160;
	m_sliderScaleUnit->setGeometry(left, top, 130, 15);


}

