#ifndef MEDIAPLAYERVIEWWIDGET_H
#define MEDIAPLAYERVIEWWIDGET_H

#include "inc_MediaPlayerView/MediaPlayerView.h"
#include "inc_CommonLib/NLEBaseWidget.h"

//#include <QWidget>

class IMediaPlayerControl;
class MediaPlayerView;
class MediaStreamGenerator;
class MediaPlayerViewWidget : public NLEBaseWidget
{
	Q_OBJECT

public:
	MediaPlayerViewWidget(QWidget *parent);
	~MediaPlayerViewWidget();

	void SetFocus(bool foucs) override;

protected:
	void resizeEvent(QResizeEvent *event);

private:
	MediaPlayerView *m_mediaPlayerViewWidget;
};

#endif // MEDIAPLAYERVIEWWIDGET_H
