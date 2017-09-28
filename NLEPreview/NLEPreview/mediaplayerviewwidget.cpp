#include "stdafx.h"

#define  min(x,y) (x)<(y)?(x):(y)
#define  max(x,y) (x)>(y)?(x):(y)
#include "mediaplayerviewwidget.h"

//#include "inc_CommonLib/NLEWraper.h"
//#include "inc_CommonLib/PlayerMaterProvider.h"
//
//#include "COM/MultiMediaSDKHelper.h"


MediaPlayerViewWidget::MediaPlayerViewWidget(QWidget *parent)
: NLEBaseWidget(parent)
{
	m_mediaPlayerViewWidget = new MainMediaPlayerView(this);

}

MediaPlayerViewWidget::~MediaPlayerViewWidget()
{
}


void MediaPlayerViewWidget::SetFocus(bool focus)
{
	//qDebug() << ("MediaPlayerViewWidget::SetFocus:") << focus;
}

void MediaPlayerViewWidget::resizeEvent(QResizeEvent *event)
{
	m_mediaPlayerViewWidget->setGeometry(rect());
}

