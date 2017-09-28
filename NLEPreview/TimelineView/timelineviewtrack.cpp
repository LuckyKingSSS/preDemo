#include "stdafx.h"
#include "timelineviewtrack.h"
#include "inc_CommonLib/TimelineRuler.h"

#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/NLEBaseWidget.h"

#include "timelinecommon.h"

TimelineViewTrack::TimelineViewTrack(TimelineRuler *ruler, QWidget *parent)
: QWidget(parent)
, m_ruler(ruler)
{
	m_mousePress = false;
	setAcceptDrops(true);


	m_timelineManager = TimelineManager::GetInstance();
	connect(m_timelineManager, &TimelineManager::signalTrackRebuild, this, [&]()
	{
		m_trackBuilder->SetTrackManager(m_timelineManager->CurrentController()->GetTrackManager());
		m_trackBuilder->RebuildTrackBase(true);
		emit TrackStateChanged(State_ClipChanged);
	});

	connect(m_timelineManager, &TimelineManager::signalTrackUpdate, this, [&](int trackIndex)
	{
		m_trackBuilder->UpdateTrackItem(trackIndex);
		emit TrackStateChanged(State_ClipChanged);
	});

	connect(m_timelineManager, &TimelineManager::signalThumbnailAvalible, this, [&](int trackIndex)
	{
		m_trackBuilder->UpdateTrackItem(trackIndex);
		
	});

	connect(this, &TimelineViewTrack::TrackStateChanged, this, [&](int state)
	{
		static int preDuration = 0;
		if (preDuration != m_trackBuilder->Duration())
		{
			preDuration = m_trackBuilder->Duration();
			emit DurationChanged(preDuration);
		}
	});
	///
	m_trackBuilder = TimelineTrackBuilder::GetInstance(this);
	m_trackBuilder->SetTrackManager(m_timelineManager->CurrentController()->GetTrackManager());
	m_trackBuilder->SetTimelineViewTrack(this);
	m_trackBuilder->RebuildTrackBase();

	TimelineTrimControl::GetInstance(this)->SetRuler(m_ruler);

	m_drag = TimelineDragControl::GetInstance();
	m_drag->Init(m_trackBuilder->GetTrackItems(), this, m_trackBuilder);
	//connect(m_drag, &TimelineDragControl::SeekTo, m_ruler, &TimelineRuler::FramesChanged);
}

TimelineViewTrack::~TimelineViewTrack()
{

}


int TimelineViewTrack::Duration()
{
	return m_trackBuilder->Duration();
}


void TimelineViewTrack::SetCurrentFrames(int pos)
{
	m_trackBuilder->SetCurrentFrames(pos);

	emit TrackStateChanged(State_FrameChanged);
}

int TimelineViewTrack::CurrentFrames()
{
	return m_ruler->CurrentFrames();
}

void TimelineViewTrack::SetOffsetFrames(int frames)
{
	m_trackBuilder->SetOffsetFrames(frames);
}

int TimelineViewTrack::OffsetFrames()
{
	return Ruler()->OffsetFrames();
}

int TimelineViewTrack::Height()
{
	return m_trackBuilder->Height();
}


void TimelineViewTrack::SeekTimelineRuler(int frames)
{
	Ruler()->SetCurrentFrames(frames);
	Ruler()->FramesChanged(frames);
}

void TimelineViewTrack::SetThumbnailsLength()
{
	m_trackBuilder->SetThumbnailsLength();
}

TimelineRuler* TimelineViewTrack::Ruler()
{
	return m_ruler;
}


TimelineManager* TimelineViewTrack::GetTimelineManager()
{
	return m_timelineManager;
}


static ClipBase *s_currentSelectClip = nullptr;
ClipBase* TimelineViewTrack::CurrentSelectClip()
{
	return s_currentSelectClip;
}

void TimelineViewTrack::SetCurrentSelectClip(ClipBase *clip)
{
	s_currentSelectClip = clip;
}

void TimelineViewTrack::ResizeGeometry(int x, int y, int width, int height)
{
	setGeometry(x, y, width, height);
	resizeEvent(nullptr);
}


void TimelineViewTrack::ResetRootClipLength()
{
	TimelineManager::GetInstance()->AdjustRootClipLength();
	emit DurationChanged(Duration());
}

void TimelineViewTrack::resizeEvent(QResizeEvent *event)
{
	int left = 0;
	int top = 0;
	const int titleWidth = 0;
	auto items = m_trackBuilder->GetTrackItems();
	for (int i = 0; i < items->size(); ++i)
	{
		(*items)[i]->setGeometry(left, top, width() - titleWidth, (*items)[i]->Height());
		(*items)[i]->show();
		top = (*items)[i]->geometry().bottom();
	}

}

static void sDrawClipPixmap(QPainter *painter, QRect clipRect, ClipBase *clip)
{
	painter->save();
	auto pen = painter->pen();
	pen.setColor(QColor(250, 250, 250));
	painter->setPen(pen);

	// 缩例图
	auto thumbnails = clip->GetThumbnails();
	auto thumbnailsSize = clip->GetThumbnailSize();
	const int thumbnailsMargins = 2;
	int left = clipRect.left();
	QRect thumbnailRect;
	for (auto pixmap : thumbnails)
	{
		if (left < -thumbnailsSize.width())
		{
			left += thumbnailsSize.width();
			continue;
		}

		thumbnailRect = QRect(QPoint(left, clipRect.y()), thumbnailsSize).intersected(clipRect);
		painter->drawPixmap(thumbnailRect, pixmap, QRect(QPoint(0, 0), thumbnailRect.size()));
		left += thumbnailsSize.width();
		if (left >= clipRect.right())
			break;
	}
	if (!thumbnails.isEmpty())
	{
		auto lastPixmap = thumbnails.first();
		//auto lastPixmap = thumbnails.last();
		while (left < clipRect.right())
		{
			thumbnailRect = QRect(QPoint(left, clipRect.y()), thumbnailsSize).intersected(clipRect);
			painter->drawPixmap(thumbnailRect, lastPixmap, QRect(QPoint(0, 0), thumbnailRect.size()));
			left += thumbnailsSize.width();
		}
	}

	painter->drawText(QRect(qMax(0, clipRect.x()) + 10, clipRect.y(), 200, clipRect.height()), Qt::AlignVCenter | Qt::AlignLeft, clip->GetName());

	painter->restore();
}

void TimelineViewTrack::mouseMoveEvent(QMouseEvent *event)
{
	if (m_mousePress)
	{
		
		TimelineViewTrackItem *child = qobject_cast<TimelineViewTrackItem*>(childAt(event->pos()));
		auto selectClip = m_timelineManager->GetSelectedClip();
		if (child && selectClip)
		{
			if (m_pressPoint.manhattanLength() > QApplication::startDragDistance())
			{

				DragClip dragClip(selectClip);
				// 获取拖拽缩例图
				QRect dragRenderRect(0,0, Ruler()->Frames2DurationF(selectClip->GetLenAtTrack()), child->Height());
				QPixmap dragPixmap(dragRenderRect.size());
				QPainter painter(&dragPixmap);
				painter.fillRect(dragRenderRect, QColor(217, 78, 55));
				sDrawClipPixmap(&painter, dragRenderRect, selectClip);
				dragClip.SetDragPixmap(dragPixmap);

				dragClip.SetTrackIndex(child->GetTrackIndex());
				m_drag->SetDragInClip(dragClip);

				auto offsetPosition = event->pos().x() - Ruler()->Frames2PositionF(selectClip->GetStartAtTrack()) - TIMELINEVIEW_TRACKITEM_WIDTH_HEADER;
				m_drag->SetDragClipOffsetPosition(offsetPosition);

				auto mimeData = new QMimeData;
				mimeData->setData("TimelineView_ClipBase", "");
				QDrag drag(this);
				drag.setMimeData(mimeData);
				drag.exec();
			}
		}
		


	}

	QWidget::mouseMoveEvent(event);
}

void TimelineViewTrack::mousePressEvent(QMouseEvent *event)
{

	m_mousePress = true;
	m_pressPoint = event->pos();

	TimelineViewTrackItem *child = qobject_cast<TimelineViewTrackItem*>(childAt(event->pos()));
	if (child)
	{
		int preTrackIndex = m_timelineManager->GetSelectedClip() ? m_timelineManager->GetSelectedClip()->GetOwnerTrack()->GetIndex() : 0;
		m_timelineManager->SelectClip(child->GetTrackIndex(), Ruler()->Position2FramesF(qMax(0, event->pos().x()) - TIMELINEVIEW_TRACKITEM_WIDTH_HEADER));

		auto selectClip = m_timelineManager->GetSelectedClip();
		ClipBase *preSelectClip = CurrentSelectClip();
		if (selectClip && (preSelectClip != selectClip &&
			(CurrentFrames() < selectClip->GetStartAtTrack() || CurrentFrames() > (selectClip->GetStartAtTrack() + selectClip->GetLenAtTrack()))
			))
		{
			Ruler()->SetCurrentFrames(selectClip->GetStartAtTrack());
			Ruler()->FramesChanged(selectClip->GetStartAtTrack());
		}
		else
		{
			m_trackBuilder->UpdateTrackItem(preTrackIndex);
		}
		SetCurrentSelectClip(selectClip);
		TrackStateChanged(State_ClipChanged);
	}
	
	QWidget::mousePressEvent(event);
}

void TimelineViewTrack::mouseReleaseEvent(QMouseEvent *event)
{
	m_mousePress = false;

	QWidget::mouseReleaseEvent(event);
}

void TimelineViewTrack::contextMenuEvent(QContextMenuEvent *event)
{
	auto selectClip = m_timelineManager->GetSelectedClip();
	ClipBase *complexClip = TimelineManager::GetInstance()->CurrentComplexClip();

	QMenu menu(this);
	auto convertToComplexAction = menu.addAction(tr("Convert To Complex"));
	auto enterComplexAction = menu.addAction(tr("Enter Complex"));
	auto leaveComplexAction = menu.addAction(tr("Leave Complex"));
	convertToComplexAction->setEnabled(selectClip && selectClip->GetType() != ClipBase::ClipType_Complex);
	enterComplexAction->setEnabled(selectClip && selectClip->GetType() == ClipBase::ClipType_Complex);
	leaveComplexAction->setEnabled(complexClip->ParentClip());

	
	auto action = menu.exec(event->globalPos());
	if (action)
		emit Pause();


	if (action == enterComplexAction)
	{
		TimelineManager::GetInstance()->CurrentComplexClip()->SetSeekPos(CurrentFrames());

		GetTimelineManager()->EnterComplexClip();

		auto complexClip = TimelineManager::GetInstance()->CurrentComplexClip();
		m_trackBuilder->SetComplexTypeAvailableLength(complexClip->GetLenAtTrack());

		AfterComplexClipChanged(complexClip);
	
	}
	else if (action == leaveComplexAction)
	{
		TimelineManager::GetInstance()->CurrentComplexClip()->SetSeekPos(CurrentFrames());

		GetTimelineManager()->LeaveComplexClip();

		auto complexClip = TimelineManager::GetInstance()->CurrentComplexClip();
		if (complexClip->ParentClip() != nullptr)
			m_trackBuilder->SetComplexTypeAvailableLength(complexClip->GetLenAtTrack());
		else
			m_trackBuilder->SetComplexTypeAvailableLength(0);


		AfterComplexClipChanged(complexClip);
	}
	else if (action == convertToComplexAction)
	{
		GetTimelineManager()->ConvertToComplex();
		SetCurrentSelectClip(m_timelineManager->GetSelectedClip());
	}
	
}

void TimelineViewTrack::mouseDoubleClickEvent(QMouseEvent *event)
{
	emit TrackStateChanged(State_DoubleClicked);
	
	QWidget::mouseDoubleClickEvent(event);
}

void TimelineViewTrack::AfterComplexClipChanged(ComplexClip *complexClip)
{
	emit ComplexClipChanged(complexClip->GetSrcTimeline());

	SeekTimelineRuler(complexClip->GetSeekPos());
	SetCurrentSelectClip(m_timelineManager->GetSelectedClip());
}



bool TimelineViewTrack::CanDrag(QPoint x)
{
	return x.x() >= TIMELINEVIEW_TRACKITEM_WIDTH_HEADER;
}

void TimelineViewTrack::dragEnterEvent(QDragEnterEvent *event)
{
	if ((event->mimeData()->hasFormat("MatterView_TimelineItem") || event->mimeData()->hasFormat("TimelineView_ClipBase")))
	{

		TimelineViewTrackItem *child = qobject_cast<TimelineViewTrackItem*>(childAt(event->pos()));
		if (child)
		{
			auto mimeData = event->mimeData();

			DragClip dragClip;// = m_drag->GetDragClip();
			if (mimeData->hasFormat("MatterView_TimelineItem"))
			{
				m_timelineManager->UnselectAll();
				NLETimeline *timeline = reinterpret_cast<NLETimeline*>(mimeData->property("MatterView_TimelineItem").value<qptrdiff>());
				auto matterType = mimeData->property("MatterType").toInt();
				auto duration = mimeData->property("Duration").toInt();
				dragClip.SetTimeline(timeline, matterType, duration);
				dragClip.dragType = DragClip::DragType_MatterView;
			}
			else if (mimeData->hasFormat("TimelineView_ClipBase"))
			{
				dragClip.SetClip(m_timelineManager->GetSelectedClip());
				dragClip.dragType = DragClip::DragType_Timeline;
			}
			else
				Q_ASSERT(false);

			m_drag->StopFilter();

			auto dragOutClip = m_timelineManager->GetSelectedClip();
			m_drag->SetDragInClip(dragClip);
			m_drag->SetDragOutClip(dragOutClip);
			m_drag->StartDrag();
			event->accept();
		}
	}
	else
		event->ignore();

}

void TimelineViewTrack::dragMoveEvent(QDragMoveEvent * event)
{
	if (CanDrag(event->pos()))
	{
		TimelineViewTrackItem *child = qobject_cast<TimelineViewTrackItem*>(childAt(event->pos()));
		if (child)
		{
			m_drag->DragMove(child, event->pos());
		}
		event->accept();
	}
}
//
//void TimelineViewTrack::DragMove(QDragMoveEvent * event)
//{
//	TimelineViewTrackItem *child = qobject_cast<TimelineViewTrackItem*>(childAt(event->pos()));
//	
//	if (child)
//	{
//		auto mimeData = event->mimeData();
//
//		DragClip dragClip = m_drag->GetDragInClip();
//		if (mimeData->hasFormat("MatterView_TimelineItem"))
//		{
//			m_timelineManager->UnselectAll();
//			NLETimeline *timeline = reinterpret_cast<NLETimeline*>(mimeData->property("MatterView_TimelineItem").value<qptrdiff>());
//			auto matterType = mimeData->property("MatterType").toInt();
//			auto duration = mimeData->property("Duration").toInt();
//			dragClip.SetTimeline(timeline, matterType, duration);
//			dragClip.dragType = DragClip::DragType_MatterView;
//		}
//		else if (mimeData->hasFormat("TimelineView_ClipBase"))
//		{
//			dragClip.SetClip(m_timelineManager->GetSelectedClip());
//			dragClip.dragType = DragClip::DragType_Timeline;
//		}
//		else
//		{
//			Q_ASSERT(false);
//		}
//		m_drag->StopFilter();
//
//		m_drag->SetDragInClip(dragClip);
//		m_drag->DragMove(child, event->pos());
//	}
//	event->accept();
//}





void TimelineViewTrack::dragLeaveEvent(QDragLeaveEvent *event)
{
	m_drag->DragLeave();

}

void TimelineViewTrack::dropEvent(QDropEvent * event)
{
	m_drag->DropDown();


	emit TrackStateChanged(State_ClipChanged);
}



//////////////////////////////////////////////////////////////////////////
TimelineViewTrackItem::TimelineViewTrackItem(TimelineViewTrackItemDraw *draw, QWidget *parent)
:QWidget(parent)
{
	m_track = nullptr;
	m_trackType = -1;
//	m_mousePress = false;
	m_complexTypeAvailableLength = 0;
	setAutoFillBackground(true);
	setMouseTracking(true);

	m_itemHeight = 0;

	m_draw = draw;
	m_draw->SetTrackItem(this);

	m_trackHead = new TimelineViewTrackItemHead(this);
	m_trackHead->SetBackgroundColor(m_draw->GetBackgroundColor());

	m_trimControl = TimelineTrimControl::GetInstance();
}

TimelineViewTrackItem::~TimelineViewTrackItem()
{
	delete m_draw;
}

int TimelineViewTrackItem::Duration()
{
	if (m_trackBase)
		return m_trackBase->GetDuration();
	else
		return 0;
}

int TimelineViewTrackItem::Height()
{
	return m_itemHeight;
}



void TimelineViewTrackItem::SetCurrentFrames(int frames)
{
	m_draw->SetCurrentFramesPosition(Ruler()->Frames2PositionF(frames));
	update();
}

void TimelineViewTrackItem::SetOffsetFrames(int frames)
{
	m_draw->SetOffsetFrames(frames);
	update();
}
//
//void TimelineViewTrackItem::SetDragInClip(const DragClip &clip)
//{
//	m_dragInClip = clip;
//
//	auto dragInClipLeft = m_dragInClip.startPos;
//	auto dragInClipRight = m_dragInClip.startPos + m_dragInClip.length;
//
//	bool collistion = false;
//	for (auto clip : GetClips())
//	{
//		auto left = clip.GetStartAtTrack();
//		auto right = clip.startPos + clip.GetLenAtTrack();
//		if (clip == m_dragInClip)
//			continue;
//		if (left >= dragInClipRight || dragInClipLeft >= right)
//			continue;
//		else
//		{
//			collistion = true;
//			break;
//		}
//
//	}
//	if (collistion)
//	{
//		QTimer::singleShot(0, [&](){
//			emit ClipCollision(m_dragInClip.curTrackIndex, GetTrackIndex());
//		});
//	}
//
//	update();
//}
//
//DragClip TimelineViewTrackItem::GetDragInClip()
//{
//	return m_dragInClip;
//}
//
//DragClip TimelineViewTrackItem::GetTrimingClip()
//{
//	return m_trimControl->GetClip();
//}
//
//void TimelineViewTrackItem::SetHintLinesClip(const DragClip &clip)
//{
//	m_hintLinesClip = clip;
//	update();
//}
//
//DragClip TimelineViewTrackItem::GetHintLinesClip()
//{
//	return m_hintLinesClip;
//}
//
//
//void TimelineViewTrackItem::SetDragOutClip(const DragClip &clip)
//{
//	m_dragOutClip = clip;
//}
//
//DragClip TimelineViewTrackItem::GetDragOutClip()
//{
//	return m_dragOutClip;
//}
DragClips TimelineViewTrackItem::GetClips()
{
	DragClips dragClipList;

	auto dragOutClip = TimelineDragControl::GetInstance()->GetDragOutClip();
	if (m_trackBase)
	{
		auto clips = m_trackBase->GetClips();
		std::copy_if(clips.begin(), clips.end(), std::back_inserter(dragClipList), [&](ClipBase *clip){
			return !(dragOutClip == clip);
		});
	}

	return dragClipList;
}


void TimelineViewTrackItem::SetThumbnailsLength()
{
	for (auto clip : GetClips())
	{
		_SetThumbnailsLength(clip.GetClip());
	}
}



TimelineRuler* TimelineViewTrackItem::Ruler()
{
	return m_track->Ruler();
}

TimelineManager* TimelineViewTrackItem::GetTimelineManager()
{
	return m_track->GetTimelineManager();
}

//TimelineViewTrack* TimelineViewTrackItem::GetTimelineTrack()
//{
//	return m_track;
//}


//TimelineViewTrackItemDraw* TimelineViewTrackItem::Draw()
//{
//	return m_draw;
//}

void TimelineViewTrackItem::SetTrackBase(TrackBase *trackBase)
{
	m_trackBase = trackBase;
	update();
}

TrackBase* TimelineViewTrackItem::GetTrackBase()
{
	return m_trackBase;
}

int TimelineViewTrackItem::GetTrackIndex()
{
	// m_trackbase可能还是空的
	return m_items->indexOf(this);
}

int TimelineViewTrackItem::GetTrackType()
{
	return m_trackType;
}

void TimelineViewTrackItem::SetComplexTypeAvailableLength(int length)
{
	m_complexTypeAvailableLength = length;
	update();
}

int TimelineViewTrackItem::GetComplexTypeAvailableLength()
{
	return m_complexTypeAvailableLength;
}

void TimelineViewTrackItem::SetTrackItems(TimelineViewTrackItems *items)
{
	m_items = items;
}

void TimelineViewTrackItem::SetTimelineViewTrack(TimelineViewTrack *track)
{
	m_track = track;
}

void TimelineViewTrackItem::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	
	m_draw->Draw(&painter, rect());
}

void TimelineViewTrackItem::mousePressEvent(QMouseEvent *event)
{
	bool retEvent = true;
	auto selectClip = m_trackBase->GetSelectedClip();
	if (selectClip && m_trimControl->StartTrim(selectClip, event->pos(), this))
	{
		retEvent = false;
	}

	if (retEvent)
		QWidget::mousePressEvent(event);
}

void TimelineViewTrackItem::mouseMoveEvent(QMouseEvent *event)
{
	auto selectClip = m_trackBase ? m_trackBase->GetSelectedClip() : nullptr;
	if (selectClip)
	{
		m_trimControl->MoveTrim(selectClip, event->pos(), this);
	}
	else
		setCursor(Qt::ArrowCursor);

	if (!m_trimControl->IsTriming())
		QWidget::mouseMoveEvent(event);
}


void TimelineViewTrackItem::mouseReleaseEvent(QMouseEvent *event)
{
//	m_mousePress = false;
	
	//setCursor(Qt::ArrowCursor);
	
	bool isTrim = m_trimControl->IsTriming();
	if (isTrim)
	{
		m_track->Pause();
		auto clip = m_trimControl->GetClip().GetClip();
		m_trimControl->EndTrim();
		_SetThumbnailsLength(clip);
	}
	QWidget::mouseReleaseEvent(event);
}

void TimelineViewTrackItem::resizeEvent(QResizeEvent *event)
{
	m_trackHead->setGeometry(0, 0, TIMELINEVIEW_TRACKITEM_WIDTH_HEADER, height());
}


void TimelineViewTrackItem::_SetThumbnailsLength(ClipBase *clip)
{
	clip->SetThumbnailTotalLength(Ruler()->Frames2DurationF(clip->GetLenAtTrack()));
}


//////////////////////////////////////////////////////////////////////////


TimelineViewTrackItem_Video::TimelineViewTrackItem_Video(QWidget *parent)
:TimelineViewTrackItem(new TimelineViewTrackItemDraw_Video(), parent)
{
	m_itemHeight = TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO;
	m_trackType = TrackBase::TrackType_Vedio;
	m_trackHead->SetHeadObjectName("TimelineView_TimelineViewTrackItem_Head_Video");
}

TimelineViewTrackItem_Audio::TimelineViewTrackItem_Audio(QWidget *parent)
: TimelineViewTrackItem(new TimelineViewTrackItemDraw_Audio(), parent)
{
	m_itemHeight = TIMELINEVIEW_TRACKITEM_HEIGHT_AUDIO;
	m_trackType = TrackBase::TrackType_Audio;
	m_trackHead->SetHeadObjectName("TimelineView_TimelineViewTrackItem_Head_Audio");
}

TimelineViewTrackItem_Effect::TimelineViewTrackItem_Effect(QWidget *parent)
: TimelineViewTrackItem(new TimelineViewTrackItemDraw_Effect(), parent)
{
	m_itemHeight = TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT;
	m_trackType = TrackBase::TrackType_Effect;
	m_trackHead->SetHeadObjectName("TimelineView_TimelineViewTrackItem_Head_Effect");
}

//////////////////////////////////////////////////////////////////////////
TimelineViewTrackItemDraw::TimelineViewTrackItemDraw()
:QObject(nullptr)
{
	m_offsetFrames = 0;
	m_handlePosition = 0;

	m_backgroundColor = QColor(245, 244, 244);
	m_highlightColor = QColor(217, 78, 55);
	m_clipColor = QColor(143, 194, 199);
}

TimelineViewTrackItemDraw::~TimelineViewTrackItemDraw()
{
	//qDeleteAll(m_clips);
}

TimelineRuler* TimelineViewTrackItemDraw::Ruler()
{
	return m_trackItem->Ruler();
}

void TimelineViewTrackItemDraw::SetTrackItem(TimelineViewTrackItem *item)
{
	m_trackItem = item;
}


QColor TimelineViewTrackItemDraw::GetBackgroundColor()
{
	return m_backgroundColor;
}

void TimelineViewTrackItemDraw::Draw(QPainter *painter, QRect rect)
{
	painter->save();
	painter->translate(TIMELINEVIEW_TRACKITEM_WIDTH_HEADER, 0);

	m_rect = rect.adjusted(0, 0, 0, -3);
	
	QPen pen = painter->pen();

	painter->setPen(Qt::NoPen);
	painter->setBrush(m_backgroundColor);
	painter->drawRect(m_rect);

	pen.setWidth(1);
	pen.setColor(QColor(163, 160, 159));
	painter->setPen(pen);
	painter->drawLine(rect.x(), rect.height() - 2, rect.width(), rect.height() - 2);
	//painter->drawLine(m_rect.x(), 0, m_rect.width(), 0);

	// clips
	int left = 0;
	auto ruler = Ruler();
	auto clips = m_trackItem->GetClips();
	for (auto clip : clips)
	{
		left = ruler->Frames2PositionF(clip.GetStartAtTrack());
		if (left > m_rect.right())
			break;
		int duration = ruler->Frames2DurationF(clip.GetLenAtTrack());
		if (clip.IsSelected())
			painter->setBrush(m_highlightColor);
		else
			painter->setBrush(m_clipColor);
		QRect clipRect(left, m_rect.y(), duration, m_rect.height());
		painter->drawRect(clipRect);

		auto thumbnailsSize = clip.GetClip()->GetThumbnailSize(); 
		sDrawClipPixmap(painter, clipRect, clip.GetClip());
	}

	
	
	// draging clip
	auto dragInClip = TimelineDragControl::GetInstance()->GetDragInClip(m_trackItem->GetTrackIndex());
	if (!dragInClip.IsNull())
	{
		int left = ruler->Frames2PositionF(dragInClip.startPos);
		int duration = ruler->Frames2DurationF(dragInClip.length);
		QRect simulateRect(left, m_rect.y(), duration, m_trackItem->Height());
		painter->drawPixmap(simulateRect, dragInClip.GetDragPixmap());

		//pen.setColor(Qt::gray);
		//painter->setPen(pen);
		//painter->setBrush(QColor(196, 196, 196));
		//painter->drawRect(simulateRect);
	}
	
	// triming clip
	auto trimingClip = TimelineTrimControl::GetInstance()->GetClip(m_trackItem->GetTrackIndex());
	if (!trimingClip.IsNull())
	{
		int left = ruler->Frames2PositionF(trimingClip.startPos);
		int duration = ruler->Frames2DurationF(trimingClip.length);
		QRect simulateRect(left, m_rect.y()+1, duration, m_rect.height()-1);
		pen.setColor(Qt::red);
		painter->setPen(pen);
		painter->setBrush(Qt::NoBrush);
		painter->drawRoundedRect(simulateRect, 2, 2);
	}

	// complexclip available rect
	int complexClipLength = m_trackItem->GetComplexTypeAvailableLength();
	if (complexClipLength > 0)
	{
		complexClipLength = ruler->Frames2PositionF(complexClipLength);
		int leftDown = complexClipLength;
		int leftTop = complexClipLength + m_rect.height();
		pen.setWidth(1);
		pen.setColor(QColor(163, 160, 159));
		painter->setPen(pen);
		QRect fillRect = m_rect;
		fillRect.setLeft(complexClipLength);
		painter->fillRect(fillRect, QColor(163, 160, 159, 80));
		while (leftDown <= m_rect.width())
		{
			painter->drawLine(QPoint(leftDown, m_rect.height()), QPoint(leftTop, m_rect.y()));
			leftDown += 20;
			leftTop += 20;
		}
	}

	// hintlines clip
	auto hintLinesClip = TimelineDragControl::GetInstance()->GetHintLinesClip();
	if (!hintLinesClip.IsNull())
	{
		pen.setColor(QColor(163, 160, 159));
		painter->setPen(pen);
		left = ruler->Frames2PositionF(hintLinesClip.startPos);
		painter->drawLine(left, m_rect.y(), left, m_rect.height());
	}

	// 标尺
	pen.setColor(QColor(61, 65, 69));
	painter->setPen(pen);
	painter->setBrush(QColor(61, 65, 69));
	left = m_handlePosition;
	painter->drawLine(left, m_rect.y(), left, m_rect.height());

	painter->restore();
}

QRect TimelineViewTrackItemDraw::Rect()
{
	return m_rect;
}

void TimelineViewTrackItemDraw::SetCurrentFramesPosition(int pos)
{
	m_handlePosition = pos;
}


void TimelineViewTrackItemDraw::SetOffsetFrames(int frames)
{
	m_offsetFrames = frames;
}



//////////////////////////////////////////////////////////////////////////
TimelineViewTrackItemDraw_Video::TimelineViewTrackItemDraw_Video()
:TimelineViewTrackItemDraw()
{
	//m_backgroundColor = QColor(206, 228, 244);
}

TimelineViewTrackItemDraw_Audio::TimelineViewTrackItemDraw_Audio()
: TimelineViewTrackItemDraw()
{
	//m_backgroundColor = QColor(190, 255, 190);
	//m_highlightColor = QColor(143, 194, 199);
	//m_clipColor = QColor(126, 255, 126);
}

TimelineViewTrackItemDraw_Effect::TimelineViewTrackItemDraw_Effect()
:TimelineViewTrackItemDraw()
{
	//m_backgroundColor = QColor(208, 184, 250);
	//m_highlightColor = QColor(143, 194, 199);
	//m_clipColor = QColor(183, 139, 252);
}

//////////////////////////////////////////////////////////////////////////
