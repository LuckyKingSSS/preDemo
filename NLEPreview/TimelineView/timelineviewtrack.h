/*
*Author:		zhy
*Date:			2016.06.13
*Description:	时间线轨道控件
*/


#ifndef TIMELINEVIEWTRACK_H
#define TIMELINEVIEWTRACK_H


#include <functional>
#include "timelinecommon.h"
#include "timelinecontrol.h"


class TimelineRuler;
class TimelineViewTrackItem;
class TrackBase;
class TimelineManager;

// 时间线轨道控件
class TimelineViewTrack : public QWidget
{
	Q_OBJECT
public:
	enum { State_FrameChanged, State_ClipChanged, State_DoubleClicked };
public:
	TimelineViewTrack(TimelineRuler *ruler, QWidget *parent);
	~TimelineViewTrack();

	int Duration();
	void SetCurrentFrames(int frames);
	int CurrentFrames();
	void SetOffsetFrames(int frames);
	int OffsetFrames();

	int Height();

	void SeekTimelineRuler(int frames);
	void SetThumbnailsLength();
	void ResizeGeometry(int x, int y, int width, int height);

	void ResetRootClipLength();

	TimelineRuler* Ruler();
	TimelineManager* GetTimelineManager();

public:
	static ClipBase* CurrentSelectClip();
	static void SetCurrentSelectClip(ClipBase *clip);
Q_SIGNALS:
	void Pause();
	void DurationChanged(int duration);
	void TrackStateChanged(int state);
	void ComplexClipChanged(NLETimeline *timeline);
	void TimelineTrackScrollTo(int pos);
	void TimelineTrackScrollOffset(int pos);
protected:
	void resizeEvent(QResizeEvent *event);

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent * event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	void dropEvent(QDropEvent * event);

private:
	void AfterComplexClipChanged(ComplexClip *complexClip);
	bool CanDrag(QPoint p);
private:
	TimelineRuler *m_ruler;
	TimelineTrackBuilder *m_trackBuilder;
	TimelineManager *m_timelineManager;
	TimelineDragControl *m_drag;

	bool m_mousePress;
	QPoint m_pressPoint;
};

// 一条轨道
class TimelineViewTrackItemDraw;
class TimelineViewTrackItemHead;
class TimelineViewTrackItem : public QWidget
{
	Q_OBJECT
public:
	TimelineViewTrackItem(TimelineViewTrackItemDraw *draw, QWidget *parent);
	~TimelineViewTrackItem();

	int Duration();
	int Height();

	void SetCurrentFrames(int frames);
	void SetOffsetFrames(int frames);

	DragClips GetClips();

	void SetThumbnailsLength();


	TimelineRuler* Ruler();
	TimelineManager* GetTimelineManager();


	void SetTrackBase(TrackBase *trackBase);
	TrackBase* GetTrackBase();
	int GetTrackIndex();
	int GetTrackType();

	void SetComplexTypeAvailableLength(int length);
	int GetComplexTypeAvailableLength();

	void SetTrackItems(TimelineViewTrackItems *items);
	void SetTimelineViewTrack(TimelineViewTrack *track);


Q_SIGNALS:
	void ClipCollision(int srcTrackIndex, int destTrackIndex);
	//void TrimClipFramesChanged(int frames);

protected:
	void paintEvent(QPaintEvent *event);

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void resizeEvent(QResizeEvent *event);

	void _SetThumbnailsLength(ClipBase *clip);
protected:
	TimelineViewTrackItemDraw *m_draw;
	TimelineViewTrackItems *m_items;
	int m_itemHeight;
	int m_trackType;
	TrackBase *m_trackBase;
	TimelineViewTrack *m_track;

	TimelineViewTrackItemHead *m_trackHead;

	TimelineTrimControl *m_trimControl;
private:
	int m_complexTypeAvailableLength;
};

// 轨道的头控件
class TimelineViewTrackItemHead : public QWidget
{
	Q_OBJECT
public:
	TimelineViewTrackItemHead(QWidget *parent);

	void SetHeadObjectName(QString name);
	void SetBackgroundColor(QColor color);
protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	QLabel *m_headPixmap;
	QColor m_backgroundColor;
};

class TimelineViewTrackItem_Video : public TimelineViewTrackItem
{
	Q_OBJECT
public:
	TimelineViewTrackItem_Video(QWidget *parent);
};


class TimelineViewTrackItem_Audio : public TimelineViewTrackItem
{
	Q_OBJECT
public:
	TimelineViewTrackItem_Audio(QWidget *parent);
};

class TimelineViewTrackItem_Effect : public TimelineViewTrackItem
{
	Q_OBJECT
public:
	TimelineViewTrackItem_Effect(QWidget *parent);
};


//////////////////////////////////////////////////////////////////////////

// 轨道绘制控制类
class TimelineViewTrackItemDraw : public QObject
{
	Q_OBJECT
public:
	virtual void Draw(QPainter *painter, QRect rect);
	QRect Rect();

	void SetCurrentFramesPosition(int pos);
	void SetOffsetFrames(int frames);

	void SetTrackItem(TimelineViewTrackItem *item);

	QColor GetBackgroundColor();

	TimelineViewTrackItemDraw();
	~TimelineViewTrackItemDraw();


protected:
	TimelineRuler* Ruler();
	
protected:
	QColor m_backgroundColor;
	QColor m_highlightColor;
	QColor m_clipColor;
	TimelineViewTrackItem *m_trackItem;

private:
	QRect m_rect;
	int	m_handlePosition;
	int m_offsetFrames;
	
	
};


class TimelineViewTrackItemDraw_Video : public TimelineViewTrackItemDraw
{
public:
	TimelineViewTrackItemDraw_Video();

};

class TimelineViewTrackItemDraw_Audio : public TimelineViewTrackItemDraw
{
public:
	TimelineViewTrackItemDraw_Audio();

};

class TimelineViewTrackItemDraw_Effect : public TimelineViewTrackItemDraw
{
public:
	TimelineViewTrackItemDraw_Effect();

};



//////////////////////////////////////////////////////////////////////////


#endif // TIMELINEVIEWTRACK_H
