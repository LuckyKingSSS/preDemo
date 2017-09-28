#include "stdafx.h"
#include "timelinecontrol.h"


#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/CommonWidgets.h"

#include "inc_CommonLib/TimelineRuler.h"

#include "timelineviewtrack.h"
#include "timelineviewprivate.h"


DragClip::DragClip()
{
	Clear();
}

DragClip::DragClip(ClipBase *clipBase)
{
	Clear();
	SetClip(clipBase);
}

void DragClip::SetDragPixmap(QPixmap pixmap)
{
	QPixmap temp(pixmap.size());
	temp.fill(Qt::transparent);

	QPainter painter(&temp);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.drawPixmap(0, 0, pixmap);
	painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
	painter.fillRect(temp.rect(), QColor(0, 0, 0, 180));
	painter.end();
	dragPixmap = temp;
}

QPixmap DragClip::GetDragPixmap()
{
	return dragPixmap;
}

void DragClip::SetClip(ClipBase *clipTemp)
{
	clip = clipTemp;
	if (clip)
	{
		clipType = clip->GetType();
		startPos = clip->GetStartAtTrack();
		length = clip->GetLenAtTrack();
	}
}

ClipBase* DragClip::GetClip() const
{
	return clip;
}

void DragClip::SetTimeline(NLETimeline *timeline, int matterType, int duration)
{
	clip = nullptr;

	this->timeline = timeline;
	this->matterType = matterType;

	startPos = 0;
	length = duration;

}

std::tuple<NLETimeline*, int> DragClip::GetTimeline() const
{
	return std::make_tuple(timeline, matterType);
}

void DragClip::SetTrackIndex(int index)
{
	curTrackIndex = index;
	if (originalTrackIndex == -1)
		originalTrackIndex = index;
}

int DragClip::GetClipType()
{
	return clip ? clip->GetType() : clipType;

}

int DragClip::GetStartAtTrack()
{
	return clip ? clip->GetStartAtTrack() : startPos;
}

int DragClip::GetLenAtTrack()
{
	return clip ? clip->GetLenAtTrack() : length;
}

bool DragClip::IsSelected()
{
	return clip ? clip->IsSelected() : false;
}

void DragClip::Clear()
{
	originalTrackIndex = -1;
	curTrackIndex = -1;
	clipType = -1;
	startPos = -1;
	length = -1;
	dragType = DragType_MatterView;
	clip = nullptr;
	timeline = nullptr;
	matterType = -1;

	dragPixmap = QPixmap(TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO, TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO);
	QPainter painter(&dragPixmap);
	painter.fillRect(QRect(QPoint(0, 0), dragPixmap.size()), QColor(196, 196, 196));
}

bool DragClip::IsNull()
{
	return clip == nullptr && timeline == nullptr;
}

bool DragClip::operator<(const DragClip &other)
{
	return clip->GetStartAtTrack() < other.clip->GetStartAtTrack();
}

bool DragClip::operator==(const DragClip &other)
{
	return clip == other.clip;
}

DragClip& DragClip::operator=(const DragClip &other)
{
	if (&other != this)
	{
		originalTrackIndex = other.originalTrackIndex;
		curTrackIndex = other.curTrackIndex;
		clipType = other.clipType;
		startPos = other.startPos;
		length = other.length;
		dragType = other.dragType;
		clip = other.clip;
		timeline = other.timeline;
		matterType = other.matterType;
		dragPixmap = other.dragPixmap;
	}
	return *this;
}

void TimelineDragControl::HintLinesMoveClip()
{
	HintLines lines;
	for (auto item : *m_items)
	{
		for (auto clip : item->GetClips())
		{
			lines.push_back((clip.GetClip()->GetStartAtTrack()));
			lines.push_back((clip.GetClip()->GetStartAtTrack() + clip.GetClip()->GetLenAtTrack()));
		}
	}
	lines.push_back(m_track->CurrentFrames());


	// 片段移动辅助磁贴功能
	DragClip hintLinesClip;
	auto resultLines = lines.Hint(m_dragInClip.startPos, m_dragInClip.startPos + m_dragInClip.length, m_track->Ruler());
	if (std::get<0>(resultLines))
	{
		m_dragInClip.startPos = std::get<1>(resultLines);
		hintLinesClip = m_dragInClip;
		hintLinesClip.startPos = std::get<2>(resultLines);
	}

	m_hintLinesClip = hintLinesClip;

}

//////////////////////////////////////////////////////////////////////////



TimelineDragControl::TimelineDragControl(QObject *parent)
:QObject(parent)
, m_items(nullptr)
, m_track(nullptr)
, m_timelineViewPrivate(nullptr)
{
	m_dragClipOffset = 0;
}

TimelineDragControl::~TimelineDragControl()
{
}


static TimelineDragControl* s_TimelineDragControl = nullptr;
TimelineDragControl* TimelineDragControl::GetInstance(QObject *parent /*= nullptr*/)
{
	if (s_TimelineDragControl == nullptr)
	{
		s_TimelineDragControl = new TimelineDragControl(parent);
	}
	return s_TimelineDragControl;
}

void TimelineDragControl::StartDrag()
{

}

bool TimelineDragControl::DragMove(TimelineViewTrackItem *child, QPoint point)
{
	if (child)
	{
		TimelineViewTrackItem* acceptChildItem = child;

		bool isCompatibled = IsCompatibled(acceptChildItem, m_dragInClip);
		if (!isCompatibled)
		{
			// 片段拖拽到兼容轨道外时，计算兼容最近轨道
			acceptChildItem = nullptr;
			auto fristTrackItem = GetTrackItemFromType(m_dragInClip);
			bool reverse = fristTrackItem->geometry().bottom() < point.y();
			auto items = m_trackBuilder->GetTrackItems();
			if (!reverse)
			{
				for (int i = 0; i < items->size(); ++i)
				{
					if (IsCompatibled((*items)[i], m_dragInClip))
					{
						acceptChildItem = (*items)[i];
						break;
					}
				}
			}
			else
			{
				for (int i = items->size() - 1; i >= 0; --i)
				{
					if (IsCompatibled((*items)[i], m_dragInClip))
					{
						acceptChildItem = (*items)[i];
						break;
					}
				}
			}

			if (!reverse)
			{
				// 轨道看不到则scroll到相应位置
				int trackItemPosY = fristTrackItem->geometry().bottom();
				if (m_timelineViewPrivate->PositionOutOfTimelineTrack(trackItemPosY))
				{
					m_track->TimelineTrackScrollTo(fristTrackItem->geometry().top());
				}
			}

		}
		Q_ASSERT(acceptChildItem);

		auto ruler = m_track->Ruler();

		// 时间线上拖拽,clip点击偏移
		int offset = m_dragInClip.dragType == DragClip::DragType_MatterView ? 0 : GetDragClipOffsetPosition();
		m_dragInClip.startPos = qMax(0, (int)ruler->Position2FramesF(point.x() - offset - TIMELINEVIEW_TRACKITEM_WIDTH_HEADER));

		// 片段移动辅助磁贴功能
		HintLinesMoveClip();

		m_dragInClip.startPos = qMax(0, m_dragInClip.startPos);

		// 计算是否发生碰撞
		UpdateDragInClip(acceptChildItem);

		// 修改dragClip当前轨道index
		m_dragInClip.SetTrackIndex(acceptChildItem->GetTrackIndex());

		m_timelineViewPrivate->AutoScrollTimelineTrack(false);

		emit SeekTo(m_dragInClip.startPos);
	}
	else
	{
		m_timelineViewPrivate->AutoScrollTimelineTrack(true);
	}

	return true;
}

void TimelineDragControl::DragLeave()
{
	if (m_dragInClip.dragType == DragClip::DragType_MatterView)
	{
		m_dragInClip = DragClip();
	}

	StartFilter();
}




void TimelineDragControl::DropDown()
{
	emit m_track->Pause();

	auto dragClip = GetDragInClip();
	if (dragClip.IsNull())
		return;

	bool bNeedRebuild = false;

	auto bForceCreate = false;
	int realTrackIndex = dragClip.curTrackIndex;
	bool bNewItem = false;
	for (auto item : *m_items)
	{
		if (item->GetTrackBase() == nullptr)
		{
			bNewItem = true;
			break;
		}
	}

	// 有新建trackitem
	if (bNewItem)
	{
		realTrackIndex = GetTrackItemFromType(dragClip)->GetTrackIndex();;
		for (int i = realTrackIndex; i < dragClip.curTrackIndex; ++i)
		{
			if (!m_items->at(i)->GetClips().isEmpty())
				++realTrackIndex;
		}
		auto curTrackItem = m_items->at(dragClip.curTrackIndex)->GetTrackBase();
		if (curTrackItem == nullptr)
		{
			bForceCreate = true;
		}

		bNeedRebuild = true;
	}
	else
	{
		bool bEmptyTrack = false;
		int emptyTrackIndex = 0;
		auto firstTrackItem = GetTrackItemFromType(dragClip);
		for (int i = firstTrackItem->GetTrackIndex(); i < m_items->size(); ++i)
		{
			auto trackItem = (*m_items)[i];
			if (!IsCompatibled(trackItem, dragClip))
				break;

			if (trackItem->GetClips().isEmpty() && m_dragInClip.IsNull())
			{
				emptyTrackIndex = i;
				bEmptyTrack = true;
				break;
			}
		}

		// 当dragClip.curTrackIndex未来得及设置时，可能会发生==-1情况，直接过滤掉
		if (realTrackIndex == -1)
			return;

		if (!bEmptyTrack)
		{	// 无空轨
			auto realTrackItem = m_items->at(realTrackIndex);
			if (dragClip.originalTrackIndex != dragClip.curTrackIndex &&
				realTrackItem->GetClips().isEmpty() && ContainDragOutClip(realTrackItem)/*!realTrackItem->GetDragOutClip().isNull()*/ &&
				realTrackItem->GetTrackBase()->GetTrackManager()->GetTrackCount(realTrackItem->GetTrackType()) != 1)
				bForceCreate = true;
		}
		else
		{

			if (emptyTrackIndex > dragClip.originalTrackIndex)
			{
				if (dragClip.curTrackIndex >= dragClip.originalTrackIndex && dragClip.curTrackIndex < emptyTrackIndex)
					++realTrackIndex;
			}
			else if (emptyTrackIndex < dragClip.originalTrackIndex)
			{
				if (dragClip.curTrackIndex >= emptyTrackIndex && dragClip.curTrackIndex <= dragClip.originalTrackIndex)
					--realTrackIndex;
			}
			bNeedRebuild = true;

		}

	}
	if (dragClip.dragType == DragClip::DragType_MatterView)
	{
		auto timelineTuple = dragClip.GetTimeline();
		auto newClip = TimelineManager::GetInstance()->AddClip(realTrackIndex, dragClip.startPos,
			std::get<0>(timelineTuple), m_track->GetTimelineManager()->MatterType2ClipType(std::get<1>(timelineTuple)), bForceCreate);
		m_track->GetTimelineManager()->SelectClip(realTrackIndex, dragClip.startPos);
		newClip->SetThumbnailTotalLength(m_track->Ruler()->Frames2DurationF(newClip->GetLenAtTrack()));

		m_track->SetCurrentSelectClip(newClip);
	}
	else
		TimelineManager::GetInstance()->MoveClip(realTrackIndex, dragClip.startPos, bForceCreate);

	// 移动播放头
	auto selectClip = TimelineManager::GetInstance()->GetSelectedClip();
	Q_ASSERT(selectClip);
	m_track->Ruler()->SetCurrentFrames(selectClip->GetStartAtTrack());
	m_track->Ruler()->FramesChanged(selectClip->GetStartAtTrack());


	if (bNeedRebuild)
	{
		m_trackBuilder->RebuildTrackBase(true);
	}



	DropClear();

}

void TimelineDragControl::DropClear()
{
	m_dragInClip = DragClip();
	m_dragOutClip = DragClip();
	m_hintLinesClip = DragClip();

	m_timelineViewPrivate->AutoScrollTimelineTrack(false);

}



void TimelineDragControl::Init(QList<TimelineViewTrackItem*>* items, TimelineViewTrack *track, TimelineTrackBuilder *builder)
{
	m_items = items;
	m_track = track;
	m_timelineViewPrivate = qobject_cast<TimelineViewPrivate*>(m_track->parentWidget());
	Q_ASSERT(m_timelineViewPrivate);
	m_trackBuilder = builder;
	connect(this, &TimelineDragControl::ClipCollision, m_trackBuilder, &TimelineTrackBuilder::DragClipCollision, Qt::QueuedConnection);
}



DragClip TimelineDragControl::GetDragInClip()
{
	return m_dragInClip;
}


DragClip TimelineDragControl::GetDragInClip(int index)
{
	if (index == m_dragInClip.curTrackIndex)
	{
		return m_dragInClip;
	}
	return DragClip();
}

DragClip TimelineDragControl::GetDragOutClip()
{
	return m_dragOutClip;
}

DragClip TimelineDragControl::GetHintLinesClip()
{
	return m_hintLinesClip;
}

void TimelineDragControl::SetDragInClip(DragClip clip)
{
	m_dragInClip = clip;
}

void TimelineDragControl::SetDragOutClip(DragClip clip)
{
	m_dragOutClip = clip;
}

void TimelineDragControl::UpdateDragInClip(TimelineViewTrackItem *item)
{

	auto dragInClip = m_dragInClip;
	
	auto dragInClipLeft = dragInClip.startPos;
	auto dragInClipRight = dragInClip.startPos + dragInClip.length;

	bool collistion = false;
	for (auto clip : item->GetClips())
	{
		auto left = clip.GetStartAtTrack();
		auto right = clip.startPos + clip.GetLenAtTrack();
		if (clip == dragInClip)
			continue;
		if (left >= dragInClipRight || dragInClipLeft >= right)
			continue;
		else
		{
			collistion = true;
			break;
		}

	}
	if (collistion)
	{
		emit ClipCollision(dragInClip.curTrackIndex, item->GetTrackIndex());
	}
	


	UpdateItems();
}

void TimelineDragControl::UpdateItems()
{
	for (auto temp : *m_items)
	{
		temp->update();
	}
}

bool TimelineDragControl::ContainDragOutClip(TimelineViewTrackItem *item)
{
	auto trackBase = item->GetTrackBase();
	if (trackBase)
	{
		auto clips = trackBase->GetClips();
		for (auto clip : clips)
		{
			if (m_dragOutClip == clip)
			{
				return true;
			}
		}
	}
	return false;
}

bool TimelineDragControl::IsCompatibled(TimelineViewTrackItem *item, DragClip &dragClip)
{
	if (item == nullptr)
		return false;

	bool isCompatibled = false;
	auto timelineManager = m_track->GetTimelineManager();
	if (dragClip.dragType == DragClip::DragType_MatterView)
	{
		auto timelineTuple = dragClip.GetTimeline();
		isCompatibled = timelineManager->IsCompatible(timelineManager->MatterType2ClipType(std::get<1>(timelineTuple)), item->GetTrackType());
	}
	else
		isCompatibled = timelineManager->IsCompatible(dragClip.GetClip()->GetType(), item->GetTrackType());
	return isCompatibled;
}

TimelineViewTrackItem* TimelineDragControl::GetTrackItemFromType(const DragClip &dragClip)
{
	bool isCompatibled = false;
	auto timelineManager = m_track->GetTimelineManager();
	for (auto item : *m_items)
	{
		if (dragClip.dragType == DragClip::DragType_MatterView)
		{
			auto timelineTuple = dragClip.GetTimeline();
			isCompatibled = timelineManager->IsCompatible(timelineManager->MatterType2ClipType(std::get<1>(timelineTuple)), item->GetTrackType());
		}
		else
			isCompatibled = timelineManager->IsCompatible(dragClip.GetClip()->GetType(), item->GetTrackType());

		if (isCompatibled)
			return item;

	}
	Q_ASSERT(false);
	return nullptr;
}



void TimelineDragControl::SetDragClipOffsetPosition(int offset)
{
	m_dragClipOffset = offset;
}

int TimelineDragControl::GetDragClipOffsetPosition()
{
	return m_dragClipOffset;
}




void TimelineDragControl::StartFilter()
{
	qApp->installEventFilter(this);
}

void TimelineDragControl::StopFilter()
{
	qApp->removeEventFilter(this);
}

bool TimelineDragControl::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonRelease)
	{
		StopFilter();
		if (m_dragInClip.dragType == DragClip::DragType_Timeline)
			DropDown();
		else
		{
			m_trackBuilder->RebuildTrackBase(true);
			DropClear();
		}
	}
	else if (event->type() == QEvent::DragMove)
	{
		if (m_dragInClip.dragType == DragClip::DragType_Timeline)
			DragMove(nullptr, m_track->mapFromGlobal(QCursor::pos()));

	}

	return false;
}

static TimelineTrackBuilder *s_TimelineTrackBuilder = nullptr;
TimelineTrackBuilder* TimelineTrackBuilder::GetInstance(QObject *parent /*= nullptr*/)
{
	if (s_TimelineTrackBuilder == nullptr)
	{
		s_TimelineTrackBuilder = new TimelineTrackBuilder(parent);
	}
	return s_TimelineTrackBuilder;
}


///
TimelineTrackBuilder::TimelineTrackBuilder(QObject *parent)
:QObject(parent)
, m_trackManager(nullptr)
{
	m_complexTypeAvailableLength = 0;
}



void TimelineTrackBuilder::RebuildTrackBase(bool sendmsg)
{
	auto size = m_trackManager->GetTrackCount();

	QApplication::processEvents(); // 防止轨道还有事件未处理
	qDeleteAll(m_items);
	m_items.clear();

	for (int i = 0; i < size; ++i)
	{
		m_items << CreateTrack(m_trackManager->GetTrack(i), m_trackManager->GetTrack(i)->GetType());
	}

	if (sendmsg)
		ResizeTimelineTrack();
}

void TimelineTrackBuilder::UpdateTrackItem(int trackIndex)
{
	if (trackIndex < m_items.size() - 1 && trackIndex >= 0);
	m_items.at(trackIndex)->update();
}

void TimelineTrackBuilder::DragClipCollision(int srcTrackIndex, int destTrackIndex)
{
	TimelineViewTrackItem *srcItem = nullptr;
	if (srcTrackIndex >= 0)
		srcItem = m_items.at(srcTrackIndex);
	TimelineViewTrackItem *destItem = m_items.at(destTrackIndex);


	// 判断碰撞方式
	int collisionType = Collision_AddNewTrack;

	// 同轨道碰撞
	if (srcTrackIndex == destTrackIndex)
	{
		if (srcTrackIndex - 1 >= 0)
		{
			if ((m_items.at(srcTrackIndex)->GetTrackType() == m_items.at(srcTrackIndex - 1)->GetTrackType()) &&
				(m_items.at(srcTrackIndex - 1)->GetClips().isEmpty()))
			{
				--srcTrackIndex;
				collisionType = Collision_Exchanged;
			}
		}
		else if (srcTrackIndex + 1 < m_items.size())
		{
			if ((m_items.at(srcTrackIndex)->GetTrackType() == m_items.at(srcTrackIndex + 1)->GetTrackType()) &&
				m_items.at(srcTrackIndex + 1)->GetClips().isEmpty())
			{
				++srcTrackIndex;
				collisionType = Collision_Exchanged;
			}
		}
	}
	else
	{
		// 源轨道是空或者源轨道上还有其它片段为增加，否则都为交换
		if ((srcTrackIndex == -1) || (srcItem && !srcItem->GetClips().isEmpty()))
			collisionType = Collision_AddNewTrack;
		else
			collisionType = Collision_Exchanged;
	}


	TimelineViewTrackItem *updateDragClipItem = nullptr;
	if (collisionType == Collision_AddNewTrack)
	{
		auto newSrcItem = CreateTrack(nullptr, destItem->GetTrackType());
		m_items.insert(destTrackIndex, newSrcItem);
		updateDragClipItem = newSrcItem;
	}
	else
	{
		m_items.swap(srcTrackIndex, destTrackIndex);
		updateDragClipItem = m_items.at(destTrackIndex);

	}

	// 更新拖拽中片段在新轨道上的显示，避免拖拽片段在两轨道中出现闪烁
	//auto dragClip = TimelineDragControl::GetInstance()->GetDragInClip();
	//for (auto temp : m_items)
	//{
	//	temp->SetDragInClip(temp == updateDragClipItem ? dragClip : DragClip());
	//}
	//TimelineDragControl::GetInstance()->UpdateDragInClip();

	ResizeTimelineTrack();

}





void TimelineTrackBuilder::SetThumbnailsLength()
{
	for (auto item : m_items)
	{
		item->SetThumbnailsLength();
	}
}

void TimelineTrackBuilder::SetTrackManager(TrackManager *manager)
{
	m_trackManager = manager;
}

void TimelineTrackBuilder::SetTimelineViewTrack(TimelineViewTrack *track)
{
	m_track = track;
}

TimelineViewTrackItems* TimelineTrackBuilder::GetTrackItems()
{
	return &m_items;
}



int TimelineTrackBuilder::Duration()
{
	int duration = 0;
	if (!m_items.isEmpty())
	{
		auto iter = std::max_element(m_items.begin(), m_items.end(), [](TimelineViewTrackItem* l, TimelineViewTrackItem *r){
			return l->Duration() < r->Duration();
		});
		duration = (*iter)->Duration();
	}

	return duration;
}

void TimelineTrackBuilder::SetCurrentFrames(int pos)
{
	for (auto item : m_items)
	{
		item->SetCurrentFrames(pos);
	}
}

void TimelineTrackBuilder::SetOffsetFrames(int frames)
{
	for (auto item : m_items)
	{
		item->SetOffsetFrames(frames);
	}
}

int TimelineTrackBuilder::Height()
{
	int height = 0;
	for (auto item : m_items)
	{
		height += item->Height();
	}
	return height;
}



void TimelineTrackBuilder::SetComplexTypeAvailableLength(int length)
{
	m_complexTypeAvailableLength = length;
	for (auto item : m_items)
	{
		item->SetComplexTypeAvailableLength(length);
	}

}

int TimelineTrackBuilder::GetComplexTypeAvailableLength()
{
	return m_complexTypeAvailableLength;
}

TimelineViewTrackItem* TimelineTrackBuilder::CreateTrack(TrackBase *track, int trackType)
{
	TimelineViewTrackItem *item = nullptr;

	if (trackType == TrackBase::TrackType_Vedio)
		item = new TimelineViewTrackItem_Video(m_track);
	else if (trackType == TrackBase::TrackType_Audio)
		item = new TimelineViewTrackItem_Audio(m_track);
	else if (trackType == TrackBase::TrackType_Effect)
		item = new TimelineViewTrackItem_Effect(m_track);
	else
		Q_ASSERT(false);

	item->SetTrackBase(track);
	item->SetTrackItems(&m_items);
	item->SetTimelineViewTrack(m_track);

	auto ruler = m_track->Ruler();
	item->SetCurrentFrames(ruler->CurrentFrames());
	item->SetOffsetFrames(ruler->OffsetFrames());
	item->SetComplexTypeAvailableLength(m_complexTypeAvailableLength);

	return item;
}


void TimelineTrackBuilder::ResizeTimelineTrack()
{
	auto viewTrackRuler = qobject_cast<TimelineViewPrivate*>(m_track->parentWidget());
	viewTrackRuler->FocusResize();
}

//////////////////////////////////////////////////////////////////////////

TimelineViewTrackItemHead::TimelineViewTrackItemHead(QWidget *parent)
:QWidget(parent)
{
	m_headPixmap = new QLabel(this);
	m_headPixmap->setAttribute(Qt::WA_StyledBackground);

	// 不需要鼠标事件，让主时间线DragMove处理拖拽功能
	m_headPixmap->setAttribute(Qt::WA_TransparentForMouseEvents);
	setAttribute(Qt::WA_TransparentForMouseEvents);


}

void TimelineViewTrackItemHead::SetHeadObjectName(QString name)
{
	m_headPixmap->setObjectName(name);
}

void TimelineViewTrackItemHead::SetBackgroundColor(QColor color)
{
	m_backgroundColor = color;
}

void TimelineViewTrackItemHead::resizeEvent(QResizeEvent *event)
{
	const int headWidth = 35;
	m_headPixmap->setGeometry((width() - headWidth) / 2, (height() - headWidth) / 2, headWidth, headWidth);
}

void TimelineViewTrackItemHead::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect(rect(), m_backgroundColor);

	QPen pen = painter.pen();
	pen.setWidth(1);
	pen.setColor(QColor(189, 189, 189));
	painter.setPen(pen);
	painter.drawLine(0, height() - 2, width(), height() - 2);

}



//////////////////////////////////////////////////////////////////////////
void HintLines::push_back(int point)
{
	m_lines.insert(point);
}

void HintLines::push_back(const HintLines &lines)
{
	for (auto p : lines.m_lines)
	{
		m_lines.insert(p);
	}
}

std::tuple<bool, int, int> HintLines::Hint(int startFrames, int endFrames, TimelineRuler *calculator)
{
	const int margins = 10;
	bool canHint = false;
	int curFramesPos = 0;
	int curLine = 0;
	for (auto line : m_lines)
	{
		if (qAbs(calculator->Frames2PositionF(line) - calculator->Frames2PositionF(startFrames)) <= margins)
		{
			curLine = line;
			curFramesPos = line;
			canHint = true;
			break;
		}
		else if (qAbs(calculator->Frames2PositionF(line) - calculator->Frames2PositionF(endFrames)) <= margins)
		{
			curFramesPos = line - (endFrames - startFrames);
			curLine = line;
			canHint = true;
			break;
		}
	}
	return std::make_tuple(canHint, curFramesPos, curLine);
}

//////////////////////////////////////////////////////////////////////////

TimelineTrimControl::TimelineTrimControl(QObject *parent)
:QObject(parent)
{

	m_isTriming = false;
	m_bLeftDrag = false;
	m_bRightDrag = false;

	m_ruler = nullptr;
	m_item = nullptr;
}

static TimelineTrimControl *s_TimelineTrimControl = nullptr;
TimelineTrimControl* TimelineTrimControl::GetInstance(QObject *parent /*= nullptr*/)
{
	if (s_TimelineTrimControl == nullptr)
	{
		s_TimelineTrimControl = new TimelineTrimControl(parent);
	}
	return s_TimelineTrimControl;
}

bool TimelineTrimControl::StartTrim(ClipBase *clip, QPoint point, TimelineViewTrackItem *item)
{
	m_pressPoint = point;
	m_item = item;
	HintTriming(clip, point);
	m_isTriming = (m_bLeftDrag || m_bRightDrag);
	if (m_isTriming)
	{
		SetClip(clip);
	}
	return m_isTriming;
}

void TimelineTrimControl::MoveTrim(ClipBase *clip, QPoint point, TimelineViewTrackItem *item)
{

	m_item = item;

	auto moveFrames = m_ruler->Position2FramesF(RealPointX(point.x()));
	const int hintMargins = 6;

	auto dragLenght = m_ruler->Frames2DurationF(clip->GetLenAtTrack());
	if (!m_isTriming)
	{
		// 可拖拽长度
		if (dragLenght >= hintMargins)
		{
			HintTriming(clip, point, hintMargins);

			QRect dragInternal(m_ruler->Frames2PositionF(clip->GetStartAtTrack()), 0, m_ruler->Frames2DurationF(clip->GetLenAtTrack()), m_item->height());
			if (m_bLeftDrag || m_bRightDrag)
				m_item->setCursor(Qt::SplitHCursor);
			else if (dragInternal.contains(RealPoint(point)))
				m_item->setCursor(Qt::ClosedHandCursor);
			else
				m_item->setCursor(Qt::ArrowCursor);

		}
	}
	else
	{
		DragClip dragClip;
		dragClip.curTrackIndex = item->GetTrackIndex();
		dragClip.SetClip(clip);
		if (m_bLeftDrag)
		{
			int deltaTrim = m_ruler->Duration2FramesF(point.x() - m_pressPoint.x());
			GetLeftTrimRange(clip, deltaTrim, dragClip.startPos, dragClip.length);

			emit SeekTo(dragClip.startPos);
		}
		else if (m_bRightDrag)
		{
			int deltaTrim = m_ruler->Duration2FramesF(point.x() - m_pressPoint.x());
			GetRightTrimRange(clip, deltaTrim, dragClip.startPos, dragClip.length);

			emit SeekTo(dragClip.startPos + dragClip.length);

		}
		else
			Q_ASSERT(false);

		SetClip(dragClip);


		//emit TrimClipFramesChanged(m_bLeftDrag ? dragClip.startPos : dragClip.startPos + dragClip.length);
	}
}

void TimelineTrimControl::EndTrim()
{
	if (m_isTriming)
	{
		//m_track->Pause();
		auto trimingClip = GetClip();
		if (m_bLeftDrag)
		{
			m_item->GetTimelineManager()->AdjustClip(0, trimingClip.startPos);
		}
		else if (m_bRightDrag)
		{
			m_item->GetTimelineManager()->AdjustClip(1, trimingClip.startPos + trimingClip.length);
		}
		else
			Q_ASSERT(false);

		//_SetThumbnailsLength(trimingClip.GetClip());


		m_isTriming = false;
		m_bLeftDrag = m_bRightDrag = false;
		SetClip(DragClip());
	}
}

bool TimelineTrimControl::IsTriming()
{
	return m_isTriming;
}

DragClip TimelineTrimControl::GetClip()
{
	return m_clip;
}
DragClip TimelineTrimControl::GetClip(int index)
{
	if (index == m_clip.curTrackIndex)
	{
		return m_clip;
	}
	return DragClip();
}

void TimelineTrimControl::SetRuler(TimelineRuler *ruler)
{
	m_ruler = ruler;
}

void TimelineTrimControl::HintTriming(ClipBase *selectClip, QPoint point, int hintMargins)
{
	auto calculator = m_ruler;
	if (calculator->Frames2DurationF(selectClip->GetLenAtTrack()) > hintMargins)
	{
		QRect leftDragRect(calculator->Frames2PositionF(selectClip->GetStartAtTrack()), 0, hintMargins, m_item->height());
		QRect rightDragRect(calculator->Frames2PositionF(selectClip->GetStartAtTrack()) + calculator->Frames2DurationF(selectClip->GetLenAtTrack()) - hintMargins,
			0, hintMargins, m_item->height());
		m_bLeftDrag = leftDragRect.contains(RealPoint(point));
		m_bRightDrag = rightDragRect.contains(RealPoint(point));
	}
}

void TimelineTrimControl::GetLeftTrimRange(ClipBase *selectClip, int deltaTrim, int &left, int &lenght)
{
	Q_ASSERT(selectClip);
	left = qBound(selectClip->GetStartAtTrack() - selectClip->GetStartAtSrc(),
		deltaTrim + selectClip->GetStartAtTrack(),
		selectClip->GetStartAtTrack() + selectClip->GetLenAtTrack() - 1
		);
	left = qMax(0, left);
	auto preClip = selectClip->PreClip();
	if (preClip)
		left = qMax(preClip->GetStartAtTrack() + preClip->GetLenAtTrack(), left);

	lenght = selectClip->GetStartAtTrack() + selectClip->GetLenAtTrack() - left;
}
void TimelineTrimControl::GetRightTrimRange(ClipBase *selectClip, int deltaTrim, int &left, int &lenght)
{
	Q_ASSERT(selectClip);
	left = selectClip->GetStartAtTrack();
	lenght = selectClip->GetSrcLen() - selectClip->GetStartAtSrc();
	auto nextClip = selectClip->NextClip();
	if (nextClip)
		lenght = qMin(nextClip->GetStartAtTrack() - left, lenght);

	lenght = qBound(1, deltaTrim + selectClip->GetLenAtTrack(), lenght);
}

void TimelineTrimControl::SetClip(DragClip clip)
{
	m_clip = clip;
	m_item->update();
}

int TimelineTrimControl::RealPointX(int x)
{
	return x - TIMELINEVIEW_TRACKITEM_WIDTH_HEADER;

}

QPoint TimelineTrimControl::RealPoint(QPoint p)
{
	return QPoint(p.x() - TIMELINEVIEW_TRACKITEM_WIDTH_HEADER, p.y());

}
