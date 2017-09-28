#ifndef PLAYCONTROLLER_H
#define PLAYCONTROLLER_H

#include <QObject>
class MatterView;
class TimelineView;
class IMediaPlayerControl;
class NLETimeline;
class MediaPlayerView;
class PlayController : public QObject
{
	Q_OBJECT
public:
	enum RenderLoadedType
	{
		RenderLoadedType_None = 0,
		RenderLoadedType_MatterView,
		RenderLoadedType_TimelineView,
	};

	PlayController(MatterView *pMatterView, TimelineView *pTimelineView,MediaPlayerView *pMediaPlayerView,QObject *parent);
	~PlayController();

	void LoadTimeline();
private:
	
	void _LoadTimeline(NLETimeline *timeline);
private:
	MatterView *m_pMatterView;
	TimelineView *m_pTimelineView;
	
	RenderLoadedType m_eLoadedType;
	IMediaPlayerControl* m_pPlayer;
	MediaPlayerView *m_pMediaPlayerView;

private:
	bool m_seekingIsPlaying;
};

#endif // PLAYCONTROLLER_H
