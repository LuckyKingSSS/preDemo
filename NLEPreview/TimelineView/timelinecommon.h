#ifndef TIMELINECOMMON_H
#define TIMELINECOMMON_H

// 时间线控制滚动条
class TimelineScrollBar : public QScrollBar
{
	Q_OBJECT
public:
	TimelineScrollBar(Qt::Orientation orientation, QWidget *parent);

	bool IsPressDown();

private:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	bool m_isPressDown;
};


class BaseButton;
class TrackSetButton :public QWidget
{
	Q_OBJECT
public:
	TrackSetButton(QWidget *parent);

Q_SIGNALS:
	void Clicked();
private:
	void resizeEvent(QResizeEvent *event);
private:
	BaseButton *m_btn;
};


// 时间线状态管理器
class TimelineViewTrackRulerToolBar;
class TimelineViewTrack;
class TimelineViewTrackRulerToolBarState : public QObject
{
public:
	TimelineViewTrackRulerToolBarState(TimelineViewTrackRulerToolBar *toolbar, TimelineViewTrack *track, QObject *parent);

private:
	void TrackStateChanged(int state);
private:
	TimelineViewTrackRulerToolBar *m_toolbar;
	TimelineViewTrack *m_track;
};







#endif // TIMELINECOMMON_H
