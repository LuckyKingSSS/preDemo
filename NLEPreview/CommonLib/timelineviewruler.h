/*
*Author:		zhy
*Date:			2016.06.13
*Description:	ʱ����ʱ��߿ؼ�
*/

#ifndef TIMELINEVIEWRULER_H
#define TIMELINEVIEWRULER_H


#include <QtWidgets/QWidget>

class TimelineViewRulerDrawMgr;
class TimelineViewRulerDraw;
class RulerConvertor;
class TimelineViewRuler : public QWidget
{
	Q_OBJECT

public:
	TimelineViewRuler(QWidget *parent);
	~TimelineViewRuler();

	void SetCurrentFrames(int frames);
	int CurrentFrames();

	void SetOffsetFrames(int frames);
	int OffsetFrames();

	void SetOffsetPosition(int position);
	int OffsetPosition();


	void SetTotalFrames(int frames);
	int TotaleFrames();
	int AvailableTotaleFrames();

	void SetZoom(int zoom);
	int Zoom();

	void StartZoomAndScrollRuler();
	int GetZoomAndScrollRulerOffsetPosition();

	int MaxZoom();
	void SetMaxZoom(int zoom);
	void SetFPS(float fps);
	float FPS();

	int ScaleUnit();

	int Height();

	
	void SetCursorEnable(bool enable);
	void SetDragable(bool enable);
	void SetFramesRound(bool round); // ����Ƿ���������
	bool GetFramesRound();

	void SetMouseReleaseEmitFramesChangedEnabled(bool enable);
	void SetMousePressEmitFramesChangedEnabled(bool enable);

	RulerConvertor* GetRulerConvertor();

	void StartRulerZoomChanged();

Q_SIGNALS:
	void StartFramesChanged();
	void EndFramesChanged();
	void FramesChanged(int frame);
	void StartZoomChanged();
	void EndZoomChanged();
	void ZoomChanged(int zoom);
	void OffsetFramesChanged(int frames);
protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void resizeEvent(QResizeEvent *event);

	void RulerHandlePositionChanged(QPoint p);
	TimelineViewRulerDraw* Draw();

private:
	bool m_pressDown;
	QPoint m_pressPoint;
	int m_FindZoomPressFrame;
	// ����ʱ�Ƿ�㵽handle��
	bool m_hintRulerHandle;
	// �Ƿ���קʱ���,�ı�zoom
	bool m_mouseMoveZoom;

	TimelineViewRulerDrawMgr *m_draw;
	RulerConvertor *m_rulerConvertor;

	bool m_bStartZoomChanged;

	// ����Ĭ��cursorshape
	bool m_cursorEnable;
	// �Ƿ���ק�ɸı�zoomֵ
	bool m_dragable;

	int m_curFramePositionWhenDragRuler;
	
	// ����ת֡��ʱ�Ƿ�4��5��
	bool m_framesRound;

	bool m_mouseReleaseFramesChangedEnabled;
	bool m_mousePressFramesChangedEnabled;

};

//////////////////////////////////////////////////////////////////////////

// ʱ�������֡ת����
class RulerConvertor
{
public:
	RulerConvertor(TimelineViewRulerDrawMgr *draw);

	float Position2FramesF(int pos);
	float Frames2PositionF(int frames);

	int Position2Frames(int pos);
	int Frames2Position(int frames);

	float Frames2DurationF(int frames);
	float Duration2FramesF(int duration);

	int ZoomFromWidthAndTotaleFramesF(int rulerWidth, int totalFrames);

	
	void RebuildRulerConvertor(QList<std::tuple<int, int, int>> zoomPixelUnit);

	TimelineViewRulerDraw* Draw();
private:
	TimelineViewRulerDrawMgr *m_draw;
};


//////////////////////////////////////////////////////////////////////////

// ʱ���Draw������
class TimelineViewRulerDrawMgr
{
public:
	TimelineViewRulerDrawMgr();
	~TimelineViewRulerDrawMgr();

	void SetZoom(int zoom);
	int Zoom();
	int MaxZoom();

	void SetMaxZoom(int zoom);
	// ͨ��ʱ��߳��Ⱥ�Ҫ��ʾ�����֡���������Zoomֵ
	int ZoomFromWidthAndTotaleFramesF(int rulerWidth, int totalFrames);

	void RebuildRulerConvertor(QList<std::tuple<int, int, int>> zoomAndPixels);

	void SetDrawRect(QRect rect);

	TimelineViewRulerDraw* Draw();

private:
	TimelineViewRulerDraw* CurrentDrawFromZoom(int zoom);

	TimelineViewRulerDraw* CreateDraw(int minZoom, int maxZoom, int rulerUnit, int scaleUnit);
	void Clear();
private:
	QList<TimelineViewRulerDraw*> m_draws;
	TimelineViewRulerDraw *m_curDraw;
	int m_maxZoom;

	//QList<std::tuple<int, int, int>> m_converParam;
	QRect m_rect;
};

// ʱ��߻�����
class TimelineViewRulerDraw
{
public:
	// rulerUnit:�߶ȣ���λ�����أ�	scaleUnit:һ��̶ȿ̶ȱ�����һ�̶����ڹ涨Ϊ5֡��
	TimelineViewRulerDraw(int rulerUnit, int scaleUnit);

	void SetZoom(int zoom);
	int Zoom();

	void SetFPS(float fps);
	float FPS();

	void SetZoomRange(int minv, int maxv);
	std::tuple<int, int> ZoomRange();

	int RulerUnit();
	int ScaleUnit();
	void SetScaleUnit(int scaleUnit);

	int CurrentFrames();
	void SetTotalFrames(int frames);
	int TotaleFrames();
	int AvailableTotaleFrames();
	void SetCurrentFrames(int frames);
	void SetOffsetFrames(int frames);
	int OffsetFrames();

	void SetOffsetPosition(int position);
	int OffsetPosition();

	int Position2Frames(int pos);
	int Frames2Position(int frames);

	int Frames2PositionForBigScale(int frames);

	float Position2FramesF(int pos);	  // λ�û�ȡ֡��
	float Frames2PositionF(int frames); // ֡����ȡλ��

	float Frames2DurationF(int frames); // ֡����ȡ����
	float Duration2FramesF(int duration);

	int Duration2MaxFramesF(int duration); // ������ʾ֡��
	float ZoomFromWidthAndTotaleFramesF(int rulerWidth, int totalFrames);

	int OffsetFramesFromPosition(int position);

	bool HintRulerHandle(QPoint p);
	
	int OffsetFramesFromZoomChange(int offsetPosition);
	void Copy(TimelineViewRulerDraw *other);

	void Draw(QPainter *painter, QRect rect, QFontMetrics metrics);

	void SetDrawRect(QRect rect);
	QRect GetDrawRect();

private:
	QPolygonF GetRulerHandle();

private:
	QRect m_rect;
	int m_rulerUnit;
	int m_scaleUnit;
	int m_zoom;
	int m_oneBigScaleFrameCounts;

	float m_fps;
	int m_curFrames;
	int m_totalFrames;
	int m_offsetFrames;
	int m_framesTextUnit;

	std::tuple<int, int> m_zoomRange;

	int m_pixelOffsetPosition;
};

#endif // TIMELINEVIEWRULER_H
