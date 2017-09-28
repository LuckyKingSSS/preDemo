#ifndef REGIONEDITVIEW_H
#define REGIONEDITVIEW_H

#include <QtWidgets/QWidget>
#include <QRect>
#include "mediacropviewprivate.h"


class CornerWidget : public QWidget
{
	Q_OBJECT

public:
	CornerWidget(int nIndex,QWidget *parent);
	~CornerWidget();
	
	int Index();
	void SetRotateAngel(float angle);
Q_SIGNALS:
	void sigMouseMove(CornerWidget *pCorner, const QPoint &pt);
	void sigMouseRelease(CornerWidget *pCorner, const QPoint &pt);

protected:
	void paintEvent(QPaintEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;

	void SetCursor();				//������ת�Ƕ����ù�����״

private:
	int m_nIndex;
	float m_RotateAngel;
};


class RegionEditWidget : public QWidget
{
	Q_OBJECT

public:
	RegionEditWidget(QWidget *parent);
	~RegionEditWidget();

	NLETimeline *GetEditTimeline();
	void SetEditTimeline(NLETimeline *pTimeline);
	void Init();
	void SetFrameSize(QSize size);
	void SetBkImg(QPixmap px);
	void SetOffset(int nOffset);
Q_SIGNALS:
	void sigBkChanged();

protected:
	virtual void paintEvent(QPaintEvent *e) override;
	virtual void mouseMoveEvent(QMouseEvent *e) override;
	virtual void mousePressEvent(QMouseEvent *e) override;
	virtual void mouseReleaseEvent(QMouseEvent *e) override;
	void slotCornerMove(CornerWidget* pCorner,QPoint pt);
	void slotCornerRelease(CornerWidget* pCorner, QPoint pt);


	void UpdateDataFromTimeline();
	void CalcRegion();
	void UpdateDisplay();
	void ReallocCornerWidgets();
	void ResizeAfferSetting();		//�������Ժ󣬸�����Ҫ�����ؼ��Ĵ�С
	
	/*
	��oldPt��ԭ�㣨0��0����ʱ����תrotateRadians���ȽǺ󣬵õ��ĵ�����
	*/
	QPointF RotatePoint(QPointF oldPt, float rotateRadians);
	QPointF MiddlePoint(QPointF pt1, QPointF pt2);
	int GetMostLeftPt();			//���ص������ֵ
	int GetMostTopPt();
	int GetMostRightPt();
	int GetMostBottomPt();

protected:
	enum  MousePressPos
	{
		MousePressPos_None = 0,
		MousePressPos_EditRegion,
		MousePressPos_RotateRegion,
	};
	QPixmap m_bkimg;
	NLETimeline *m_pCurEditingTL;
	CornerWidget* m_CornerWidgets[8];
	QPointF m_CornerPts[8];		//8�������,0-1
	QPoint m_CornerPtsReal[8];	//8�������,��ʵ���ص�

	QRegion m_EditRegion;		//�����༭����
	QVector<QPoint> m_regionPts;	//�༭�����ĸ�����
	QRegion m_RotateRegion;		//��ת��������

	int m_RotateAngel;			//��ת�Ƕȣ�˳ʱ�뷽����� 0-360
	QPointF m_Center;			//���ĵ�		0-1
	QPoint m_CenterReal;		//���ĵ㣬����ֵ
	QSizeF m_Scale;				//���ű���	0-1
	QSize m_FrameSize;			//�������ĳߴ�
	QRect m_WholeRect;			//��ǰ�ؼ��Ĵ�С

	QPoint m_PressPt;
	MousePressPos m_MousePressPos;

	int m_offset;
};


class QUndoStack;
class RegionEditViewPrivate;
class RegionEditView : public QWidget
{
	Q_OBJECT

public:
	RegionEditView(QWidget *parent);
	~RegionEditView();

	void SetUndoStack(QUndoStack *pUndoStack);
	NLETimeline *GetEditTimeline();
	void SetEditTimeline(NLETimeline *pTimeline);
	void SetBkImg(QPixmap px);
protected:
	virtual void resizeEvent(QResizeEvent *e) override;
	void Init();
private:
	friend class MainMediaPlayerViewPrivateEx;
	QUndoStack *m_pUndoStack;
	QImage m_bk;				 //��Ƶ����

	QScrollArea *m_scroolArea;
	QLabel *m_bkLabel;
	RegionEditWidget *m_pRegionEditWidget;
};

class NLETimeline;
class MainMediaPlayerViewPrivateEx : public MainMediaPlayerViewPrivate
{
	Q_OBJECT
public:
	MainMediaPlayerViewPrivateEx(QWidget *parent = nullptr);
	void slotTimelineSelectChanged(NLETimeline *pSelected);
	void slotLoadType(bool bTimeline);
	void slotSeekToFrame(int nFrame);
	void slotPause();
	void slotPlay();

protected:
	void resizeEvent(QResizeEvent *e) override;

	void EnterEditModel(bool bEnter);

	RegionEditView *m_pRegionEditView;
	bool m_bTimelineLoaded;
};

#endif // REGIONEDITVIEW_H
