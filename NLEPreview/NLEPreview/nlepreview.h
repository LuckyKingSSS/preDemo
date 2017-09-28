#ifndef NLEPREVIEWMAIN_H
#define NLEPREVIEWMAIN_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QSplitter>

#include "inc_CommonLib/NLEBaseWidget.h"
#include <inc_CommonLib/TopLevelWindowTitleBar.h>



class MainSplitter;
class MatterView;
class NLEPreviewTitleBar;
class UpperView;
class TimelineView;
class PlayController;
class NLEPreview : public QWidget
{
	Q_OBJECT

public:
	NLEPreview(QWidget *parent = 0);
	~NLEPreview();

	MatterView* GetMatterView();
	TimelineView* GetTimelineView();

	void ShowMaximized();

protected:
	void resizeEvent(QResizeEvent *event);
	void showEvent(QShowEvent *event);
	//void paintEvent(QPaintEvent *event);
private:
	NLEPreviewTitleBar *m_titleBar;

	QSplitter *m_splitter;

	UpperView *m_uppterView;
	TimelineView *m_timelineView;

	PlayController *m_pPlayController;

};



class MediaPlayerViewWidget;
class MatterView;
class MainMediaPlayerView;
class UpperView : public QWidget
{
	Q_OBJECT
public:
	UpperView(QWidget *parent = nullptr);

	MatterView* GetMatterView();
	MainMediaPlayerView* GetMediaPlayerView();
protected:
	void resizeEvent(QResizeEvent *event);
	void showEvent(QShowEvent *event);

private:
	QSplitter *m_splitter;
	MatterView *m_matterView;
	MainMediaPlayerView *m_playerViewWidget;
};

class QLabel;
class QMenuBar;
class QMenu;
class NLEPreviewTitleBarProjectName;
class BaseButton;
class NLEPreviewTitleBar : public TopLevelWindowTitleBar
{
	Q_OBJECT
public:
	NLEPreviewTitleBar(NLEPreview *parent);

protected:
	void resizeEvent(QResizeEvent *event);

private:
	BaseButton *m_icon;
	QMenuBar *m_menuBar;

	QMenu	*m_fileMenu;
	QMenu	*m_editMenu;
	QMenu	*m_exportMenu;
	QMenu	*m_registerMenu;
	QMenu	*m_helpMenu;


	NLEPreviewTitleBarProjectName *m_projectName;
};

class NLEPreviewTitleBarProjectName : public QWidget
{
	Q_OBJECT
public:
	NLEPreviewTitleBarProjectName(QWidget *parent);

	void NewProject();
	void SaveProject(const QString &projectName);
	QString ProjectName();

	void SetHadRegister(bool reg);



private:
	QLabel *m_projectName;
	QLabel *m_registerTip;

	bool m_hadRegister;
};

class NLESplashScreen : public QSplashScreen
{
	Q_OBJECT
public:
	NLESplashScreen(QWidget *parent = nullptr);


};
#endif // NLEPREVIEWMAIN_H
