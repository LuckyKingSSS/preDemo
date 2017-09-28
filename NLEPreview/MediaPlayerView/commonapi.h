#pragma once


#include <QtWidgets/QtWidgets>
#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include "Linux32_Typedef.h"


//////////////////////////////////////////////////////////////////////////

#ifndef WIN32

typedef  void*  HWND;

//struct RECT
//{
//	long    left;
//	long    top;
//	long    right;
//	long    bottom;
//};

#endif


class ToolBarBase;
class QPropertyAnimation;
class QTimer;

class FullScreenControl : public QObject
{
public:
	FullScreenControl( QWidget *w);

	void SetToolbar(ToolBarBase *toolbar){ m_toolbar = toolbar; }
	void FullScreen();
	void Restore();
	bool IsFullScreen();
	void ResizeEvent(QWidget *displayView, QRect rect);
	// ����������Ч��
	void MayShowToolbar(QRect rect, QPoint p);
private:
	void StopAnimation();
	bool IsToolBarShow();
	bool IsAnimationRunning();

	void SetFullScreen(bool fullscreen);
	
private:
	QWidget *m_mediaPlayerViewPrivate;
	ToolBarBase *m_toolbar;

	QPropertyAnimation *m_hideAnimation;
	QPropertyAnimation *m_showAnimation;
	QTimer *m_hideAnimTimer;
	QPoint m_curPoint;
	QRect m_dispplayRect;
};


class IMediaPlayerControl;
class DisplayViewMouseEvent;
class DisplayView : public QWidget
{
	Q_OBJECT
public:
	DisplayView(IMediaPlayerControl *control, QWidget *parent);
	~DisplayView();

	// ������ʾ���ڱ����磺4:3
	void setRatio(double ratio);

	HWND getHwnd(){ return (HWND)m_display->winId(); }
	QWidget* GetDisplayWidget();

	void ShowCompareLabel(bool bShow);
Q_SIGNALS:
	void signalDisplayRect(const QRect &r);

protected:
	virtual void SetPlayerViewHwnd(const RECT &r);

	void resizeEvent(QResizeEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void showEvent(QShowEvent *event);

	IMediaPlayerControl *m_control;
	double m_ratio;
	QWidget *m_display;
	DisplayViewMouseEvent *m_DisplayViewMouseEvent;
	QLabel *m_pLbBefore;
	QLabel *m_pLbAfter;
};

class DisplayViewMouseEvent :public QAbstractNativeEventFilter
{
public:
	DisplayViewMouseEvent(DisplayView *view);
	~DisplayViewMouseEvent();

	bool	nativeEventFilter(const QByteArray & eventType, void * message, long * result) override;


private:
	DisplayView *m_displayView;
	QElapsedTimer m_elapsedTimer;
};


//////////////////////////////////////////////////////////////////////////
class ToolBarLabel : public QLabel
{
	Q_OBJECT
public:
	ToolBarLabel(QWidget *parent, const QString &objectName = "")
		:QLabel(parent)
	{
		setObjectName(objectName);
	}
};



class ToolBarSlider;
class AudioVolumeSlider : public QDialog
{
	Q_OBJECT
public:
	static AudioVolumeSlider* GetInstance();

	AudioVolumeSlider(QWidget *parent);

	void DoModal(QPoint p);
protected:
	void resizeEvent(QResizeEvent *event);
	void hideEvent(QHideEvent *event);

private:
	ToolBarSlider *m_slider;
	bool m_show;
};


class AsepctRatioLabel : public QLabel
{
	Q_OBJECT
public:
	AsepctRatioLabel(QWidget *parent);
	void SetRatio(float ratio);

};

class CurrentFrameLabel : public QWidget
{
	Q_OBJECT
public:
	CurrentFrameLabel(QWidget *parent);
	void SetFPS(float fps);
	void SetCurrentFrame(int frames);
	void SetDuration(int duration);
	void SetPreciseFrames(bool enable);

protected:
	void resizeEvent(QResizeEvent *event);

private:
	ToolBarLabel *m_curFrame;
	ToolBarLabel *m_desc;
	float m_fps;
	int m_duration;

	bool m_preciseFrames;
};
