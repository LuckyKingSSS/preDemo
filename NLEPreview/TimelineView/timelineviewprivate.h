/*
*Author:		zhy
*Date:			2016.06.13
*Description:	时间线控件
*/

#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QtWidgets/QtWidgets>

#include "inc_TimelineView/TimelineView.h"

class TimelineViewTrack;
class TimelineRuler;
class TimelineViewTrackRulerToolBar;
class TrackSetButton;
class TimelineScrollBar;

class TimelineViewPrivate : public QWidget
{
	Q_OBJECT
public:
	TimelineViewPrivate(QWidget *parent);
	void FocusResize();

	int GetCurrentFrame();
	void SetCurrentFrame(int frames);
	NLETimeline* GetNLETimeline();

	bool PositionOutOfTimelineTrack(int pos);
	void AutoScrollTimelineTrack(bool start);
private:
	void HorizontalScrollBar();
	void ButtonClicked(int id);
	void GlobalShortcut(int id);
	void RemoveClip();
	void UpdatePlayer();
	void InternalSeekTo(int frames);
Q_SIGNALS:
	void StartSeekTo();
	void EndSeekTo();
	void SeekTo(int frames);
	void Play();
	void Pause();
	void DurationChanged();
	void ComplexClipChanged(NLETimeline *timeline);
	void CurrentFramesOutRuler(bool right);
	void TimelineSelectChanged(NLETimeline *pSelected);
	void TimelineDoubleSelectChanged(NLETimeline *pSelectedTimeline);
	void TimelineDelete(NLETimeline *pSelectedTimeline);
protected:
	void resizeEvent(QResizeEvent *event);
	void wheelEvent(QWheelEvent *event);
private:
	TrackSetButton *m_btnTrackSet;
	TimelineViewTrack *m_track;
	TimelineRuler *m_ruler;
	TimelineViewTrackRulerToolBar *m_toolBar;
	TimelineScrollBar *m_scrollbarH;
	QScrollBar *m_scrollbarV;

	int m_realTopPosition;
	QTimer m_scrollbarTimer;
	int m_scrollbarValue;

	bool m_seekManual; // 拖拽时间尺
};




// 时间线工具栏
class BaseButton;
class ScaleUnitSlider;
class TimelineViewTrackRulerToolBar : public QWidget
{
	Q_OBJECT
public:
	enum { TrackRulerToolBar_Redo, TrackRulerToolBar_Undo, TrackRulerToolBar_Cut, TrackRulerToolBar_Delete, TrackRulerToolBar_Crop,
		TrackRulerToolBar_TextEdit};
public:
	TimelineViewTrackRulerToolBar(QWidget *parent);

	void SetScaleUnitValue(int value);
	int GetScaleUnitValue();

	void SetButtonEnabled(int id, bool enable);

Q_SIGNALS:
	void ButtonClicked(int id);
	void ScaleUnitValueChanged(int value);
	void StartScaleUnitValueChanged();

protected:
	BaseButton* GetButton(int id);

	void resizeEvent(QResizeEvent *event);

private:
	//BaseButton *m_redoBtn;
	//BaseButton *m_undoBtn;
	ScaleUnitSlider *m_sliderScaleUnit;

	QList<BaseButton*> m_leftBtns;
	QList<BaseButton*> m_rightBtns;
};




#endif // TIMELINEVIEW_H
