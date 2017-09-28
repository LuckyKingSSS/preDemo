#include "stdafx.h"
#include "nlepreview.h"

#include <QtCore/QList>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtGui/QMouseEvent>

#include "PlayController.h"
#include "inc_MatterView/matterview.h"
#include "inc_CommonLib/externalapi.h"
#include "inc_CommonLib/CommonWidgets.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_MediaPlayerView/MediaPlayerView.h"

#include "inc_TimelineView/TimelineView.h"
NLEPreview::NLEPreview(QWidget *parent)
: QWidget(parent)
{
	//setWindowFlags(Qt::FramelessWindowHint);
	//setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::WindowSystemMenuHint);
	
	setMinimumSize(970, 600);
	resize(970, 600);
	gSetMainWindow(this);

	m_titleBar = new NLEPreviewTitleBar(this);
	
	m_splitter = new QSplitter(Qt::Vertical, this);
	m_uppterView = new UpperView;
	gSetMatterView(GetMatterView());

	m_timelineView = new TimelineView(this);
	m_pPlayController = new PlayController(m_uppterView->GetMatterView(),m_timelineView,m_uppterView->GetMediaPlayerView(),this);


	m_splitter->addWidget(m_uppterView);
	m_splitter->addWidget(m_timelineView);



	qApp->setStyleSheet(gGetCommonLibStyles() + gGetMediaPlayerStyles());

}

NLEPreview::~NLEPreview()
{

}


void NLEPreview::resizeEvent(QResizeEvent *event)
{
	int margins = m_titleBar->IsMaximized() ? 0 : 3;
	const int titleHeight = 22;
	m_titleBar->setGeometry(margins, margins, width() - 2 * margins, titleHeight);
	int top = m_titleBar->geometry().bottom();
	m_splitter->setGeometry(margins, top, width() - 2 * margins, height() - titleHeight - 2*margins);
}


void NLEPreview::showEvent(QShowEvent *event)
{
	static bool first = true;
	if (first)
	{
		first = false;
		double upviewHeight = 0.64 * height();
		m_splitter->setSizes(QList<int>() << upviewHeight << height() - upviewHeight);
		m_pPlayController->LoadTimeline();

	}
}

//void NLEPreview::paintEvent(QPaintEvent *event)
//{
//	if (!IsMaximized())
//	{
//		QPainter painter(this);
//		painter.setBrush(QColor(250,250,250,20));
//		painter.drawRect(rect());
//
//		QPen pen = painter.pen();
//		int penWidth = 4;
//		pen.setWidth(penWidth);
//		pen.setColor(QColor(73, 73, 250));
//		painter.setPen(pen);
//		painter.setBrush(Qt::NoBrush);
//		painter.drawRect(rect());
//	}
//}

MatterView* NLEPreview::GetMatterView()
{
	return m_uppterView->GetMatterView();
}

TimelineView* NLEPreview::GetTimelineView()
{
	return m_timelineView;
}




void NLEPreview::ShowMaximized()
{
	m_titleBar->ShowMaximized();
}

//////////////////////////////////////////////////////////////////////////

UpperView::UpperView(QWidget *parent /*= nullptr*/)
:QWidget(parent)
{
	m_matterView = new MatterView(this);
	m_playerViewWidget = new MainMediaPlayerView(this);

	NLEWraper::GetInstance().SetMeidaPlayerControl(m_playerViewWidget->GetMediaPlayerControl());

	m_splitter = new QSplitter(this);
	m_splitter->addWidget(m_matterView);
	m_splitter->addWidget(m_playerViewWidget);

}

MatterView* UpperView::GetMatterView()
{
	return m_matterView;
}

MainMediaPlayerView* UpperView::GetMediaPlayerView()
{
	return m_playerViewWidget;
}

void UpperView::resizeEvent(QResizeEvent *event)
{
	m_splitter->setGeometry(rect());
}

void UpperView::showEvent(QShowEvent *event)
{
	static bool first = true;
	if (first)
	{
		first = false;
		double w = 0.5 * width();
		m_splitter->setSizes(QList<int>() << w << width() - w);
	}
}

//////////////////////////////////////////////////////////////////////////
NLEPreviewTitleBar::NLEPreviewTitleBar(NLEPreview *parent)
:TopLevelWindowTitleBar(parent)
{
	setObjectName("NLEPreviewTitleBar");
	setAttribute(Qt::WA_StyledBackground);
	setAttribute(Qt::WA_TransparentForMouseEvents);

	m_icon = new BaseButton(0, "NLEPreviewTitleBar_TitleIcon", this);

	m_menuBar = new QMenuBar(this);
	m_menuBar->setObjectName("NLEPreviewTitleBar_MenuBar");
	m_menuBar->resize(500, 30);
	m_fileMenu = m_menuBar->addMenu(("FILE"));
	m_fileMenu->addAction(tr("Exit"));

	//EDIT
	m_editMenu = m_menuBar->addMenu(("EDIT"));
	m_editMenu->addAction(tr("Test1"));
	m_editMenu->addAction(tr("Test2"));
	m_editMenu->addAction(tr("Test3"));
	//EXPORT
	m_exportMenu = m_menuBar->addMenu(("EXPORT"));
	m_exportMenu->addAction(tr("Test1"));
	m_exportMenu->addAction(tr("Test2"));
	m_exportMenu->addAction(tr("Test3"));

	//REGISTER
	m_registerMenu = m_menuBar->addMenu(("REGISTER"));
	m_registerMenu->addAction(tr("Test1"));
	m_registerMenu->addAction(tr("Test2"));
	m_registerMenu->addAction(tr("Test3"));

	//HELP
	m_helpMenu = m_menuBar->addMenu(("HELP"));
	m_helpMenu->addAction(tr("About..."));
	

	m_projectName = new NLEPreviewTitleBarProjectName(this);
	m_projectName->hide();

	setStyleSheet("QWidget#NLEPreviewTitleBar{ background-color: rgb(250,250,250);}"
		"QMenuBar#NLEPreviewTitleBar_MenuBar{background-color:white;}QMenuBar#NLEPreviewTitleBar_MenuBar::item{background: transparent;}"
		"BaseButton#NLEPreviewTitleBar_TitleIcon {background-image:url(:/NLEPreview/Resources/TitleBar_TitleIcon.png);background-position: center; background-repeat:no-repeat;}"
		);

}

void NLEPreviewTitleBar::resizeEvent(QResizeEvent *event)
{
	const int space = 2;
	const int btnWidth = 20;
	const int btnHeight = 20;
	int left = space;
	int top = 0;

	const int buttonSize = 3;
	const int buttonsWidth = buttonSize * (btnWidth + space) + 5;

	// 图标
	m_icon->setGeometry(space, top, btnWidth, btnHeight);
	left = m_icon->geometry().right() + space;

	// 菜单
	const int menuBarWidth = 320;
	m_menuBar->setGeometry(left, top, menuBarWidth * gGetDevicePixelRatio(), height());
	left = m_menuBar->geometry().right() + space;

	// 工程名
	const int projectNameWidth = width() - 2 * qMax(left, buttonsWidth); // 居中
	m_projectName->setGeometry(left, top, projectNameWidth, height());
	
}


//////////////////////////////////////////////////////////////////////////
NLEPreviewTitleBarProjectName::NLEPreviewTitleBarProjectName(QWidget *parent)
:QWidget(parent)
{
	setAttribute(Qt::WA_TransparentForMouseEvents);

	m_hadRegister = false;

	m_projectName = new QLabel(this);
	
	m_projectName->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	m_registerTip = new QLabel(tr("(UNREGISTERED)"), this);
	m_registerTip->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	m_registerTip->setStyleSheet("QLabel{color:red;}");

	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->addStretch(50);
	hlayout->addWidget(m_projectName, 10);
	hlayout->addWidget(m_registerTip);
	hlayout->addStretch(50);
	hlayout->setContentsMargins(0, 0, 0, 0);
	setLayout(hlayout);

	NewProject();
}

void NLEPreviewTitleBarProjectName::NewProject()
{
	m_projectName->setText(tr("UNTITLE PROJECT"));
}

void NLEPreviewTitleBarProjectName::SaveProject(const QString &projectName)
{
	m_projectName->setText(projectName);
}

QString NLEPreviewTitleBarProjectName::ProjectName()
{
	return m_projectName->text();
}
void NLEPreviewTitleBarProjectName::SetHadRegister(bool reg)
{
	if (reg)
		m_registerTip->hide();
}

//////////////////////////////////////////////////////////////////////////

NLESplashScreen::NLESplashScreen(QWidget *parent /*= nullptr*/)
:QSplashScreen(parent)
{
	setPixmap(QPixmap(":/NLEPreview/Resources/Splash.png"));
}

