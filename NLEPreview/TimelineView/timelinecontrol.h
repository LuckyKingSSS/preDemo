
#ifndef TIMELINECONTROL_H_H
#define TIMELINECONTROL_H_H

/*
*Author:		zhy
*Date:			2016.07.13
*Description:	ʱ���߿�����
*/

// �����clip,���ڻ�����ͨƬ�Ρ���קƬ�Ρ��������ܵ�
class ClipBase;
class DragClip
{
public:
	enum{ DragType_MatterView, DragType_Timeline, };
public:
	int originalTrackIndex;			// �ʼ����קƬ�����ڹ��index
	int curTrackIndex;				// ��ǰ������קƬ�����ڹ��index
	int startPos;					// �����Ƭ�ο�ʼλ�õ�֡��(����������קģ��������ק��Ƭ��)
	int length;						// �����Ƭ�γ���(����������קģ��������ק��Ƭ��)
	int dragType;					// 0�ز�����ק 1ʱ���߼���ק
	QPixmap dragPixmap;				// ��קʱ��ʾͼƬ

	DragClip();
	DragClip(ClipBase *clipBase);

	void SetDragPixmap(QPixmap pixmap);
	QPixmap GetDragPixmap();

	void SetClip(ClipBase *clipTemp);
	ClipBase* GetClip() const;
	void SetTimeline(NLETimeline *timeline, int matterType, int duration);
	std::tuple<NLETimeline*, int> GetTimeline() const;
	void SetTrackIndex(int index);
	int GetClipType();
	int GetStartAtTrack();
	int GetLenAtTrack();
	bool IsSelected();
	void Clear();
	bool IsNull();
	DragClip& operator = (const DragClip &other);
	bool operator == (const DragClip &other);
	bool operator < (const DragClip &other);

private:
	int clipType;
	ClipBase *clip;
	int matterType;
	NLETimeline *timeline;
};
Q_DECLARE_METATYPE(DragClip)
typedef QList<DragClip> DragClips;



const int TIMELINEVIEW_TRACKITEM_HEIGHT_VIDEO = 65;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_EFFECT = 42;
const int TIMELINEVIEW_TRACKITEM_HEIGHT_AUDIO = 42;
const int TIMELINEVIEW_TRACKITEM_WIDTH_HEADER = 55;

class TimelineViewTrackItem;
typedef QList<TimelineViewTrackItem*> TimelineViewTrackItems;
class TimelineTrackBuilder;
class TimelineViewTrackItem;
class TimelineViewTrack;
class TimelineViewPrivate;
// ʱ������ק����
class TimelineDragControl : public QObject
{
	Q_OBJECT
public:
	static TimelineDragControl* GetInstance(QObject *parent = nullptr);

	void Init(QList<TimelineViewTrackItem*>* items, TimelineViewTrack *track, TimelineTrackBuilder *builder);

	void StartDrag();
	bool DragMove(TimelineViewTrackItem *item, QPoint point);
	void DragLeave();
	void DropDown();


	DragClip GetDragInClip();
	DragClip GetDragInClip(int index);
	DragClip GetDragOutClip();
	DragClip GetHintLinesClip();

	void SetDragInClip(DragClip clip);
	void SetDragOutClip(DragClip clip);

	// Ƭ����קʱ���Ƭ�������ƫ��
	void SetDragClipOffsetPosition(int offset);
	int GetDragClipOffsetPosition();

	void StartFilter();
	void StopFilter();

Q_SIGNALS:
	void ClipCollision(int srcTrackIndex, int destTrackIndex);
	void SeekTo(int frames);
public:
	TimelineDragControl(QObject *parent);
	~TimelineDragControl();

private:
	void HintLinesMoveClip();
	void UpdateDragInClip(TimelineViewTrackItem *item);
	void UpdateItems();
	bool ContainDragOutClip(TimelineViewTrackItem *item);
	bool IsCompatibled(TimelineViewTrackItem *item, DragClip &dragClip);
	TimelineViewTrackItem* GetTrackItemFromType(const DragClip &dragClip);
	void DropClear();

protected:
	bool eventFilter(QObject *watched, QEvent *event);
private:
	TimelineViewTrackItems *m_items;
	TimelineViewTrack *m_track;
	TimelineTrackBuilder *m_trackBuilder;
	TimelineViewPrivate *m_timelineViewPrivate;

	int m_dragClipOffset;
	DragClip m_dragOutClip;
	DragClip m_dragInClip;
	DragClip m_hintLinesClip;


};

//////////////////////////////////////////////////////////////////////////



// ʱ����Ƭ��Trim����
class TimelineRuler;
class TimelineTrimControl : public QObject
{
	Q_OBJECT
public:
	static TimelineTrimControl* GetInstance(QObject *parent = nullptr);

	bool StartTrim(ClipBase *clip, QPoint point, TimelineViewTrackItem *item);
	void MoveTrim(ClipBase *clip, QPoint point, TimelineViewTrackItem *item);
	void EndTrim();

	bool IsTriming();
	DragClip GetClip();
	DragClip GetClip(int index);


	void SetRuler(TimelineRuler *ruler);

	TimelineTrimControl(QObject *parent);

Q_SIGNALS:
	void SeekTo(int frames);

private:
	void HintTriming(ClipBase *clip, QPoint point, int hintMargins = 6);

	void GetLeftTrimRange(ClipBase *clip, int deltaTrim, int &left, int &lenght);
	void GetRightTrimRange(ClipBase *clip, int deltaTrim, int &left, int &lenght);

	void SetClip(DragClip clip);

	int RealPointX(int x);
	QPoint RealPoint(QPoint p);

private:
	TimelineRuler *m_ruler;
	TimelineViewTrackItem *m_item;
	bool m_bLeftDrag;
	bool m_bRightDrag;
	bool m_isTriming;
	QPoint m_pressPoint;

	DragClip m_clip;
};


//////////////////////////////////////////////////////////////////////////

// ����������
class TimelineRuler;
class HintLines
{
public:
	void push_back(int point);
	void push_back(const HintLines &lines);

	// ����ֵ���Ƿ񴥷���clip��λ�ã�hintlinesλ��
	std::tuple<bool, int, int> Hint(int frames, int endFrames, TimelineRuler *calculator);

private:
	QSet<int> m_lines;
};

// ʱ���߹��������
class TrackManager;
class TimelineTrackBuilder :public QObject
{
	Q_OBJECT
public:
	enum{ Collision__None, Collision_AddNewTrack, Collision_Exchanged };
public:
	static TimelineTrackBuilder* GetInstance(QObject *parent = nullptr);

	TimelineTrackBuilder(QObject *parent);

	void DragClipCollision(int srcTrackIndex, int destTrackIndex);


	void RebuildTrackBase(bool sendmsg = false);
	void UpdateTrackItem(int trackIndex);

	void SetThumbnailsLength();

	void SetTrackManager(TrackManager *manager);
	void SetTimelineViewTrack(TimelineViewTrack *track);

	TimelineViewTrackItems* GetTrackItems();

	int Duration();
	void SetCurrentFrames(int pos);
	void SetOffsetFrames(int frames);
	int Height();

	void SetComplexTypeAvailableLength(int length);
	int GetComplexTypeAvailableLength();
private:
	TimelineViewTrackItem* CreateTrack(TrackBase *track, int trackType);
	void ResizeTimelineTrack();

private:
	TrackManager *m_trackManager;
	TimelineViewTrackItems m_items;
	TimelineViewTrack *m_track;

	// ����Ķ���״̬
	int m_complexTypeAvailableLength;
};






























#endif