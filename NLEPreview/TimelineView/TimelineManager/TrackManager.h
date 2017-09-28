#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include <QObject>
#include <QVector>
#include "TrackBase.h"

class TrackBase;
class QUndoStack;
class TrackOperator;
class TrackCommondBase;
class NLETimeline;
class ClipBase;
class TrackManager : public QObject
{
	Q_OBJECT

public:
	TrackManager(NLETimeline *pRootTimeline,QObject *parent = nullptr);
	~TrackManager();
	
	//带命令方法
	void AddTrack(TrackBase *pTrack, int nIndex);
	void RemoveTrack(TrackBase *pTrack);
	void MoveTrack(TrackBase *pTrack, int nIndexTo);
	void SwapTrack(TrackBase *pTrack1, TrackBase *pTrack2);
	//用于组合当前stack的命令，调用必须成对出现
	void BeginComposite();  
	void EndComposite();

	//进入编辑子的complex clip前调用，目的是将该子clip的所有commond组合起来
	void CompositeSubUndoStack(QUndoStack* pSubUndoStack,int nCommandCounts);

	//普通方法
	int GetTrackCount(int nTrackType = TrackBase::TrackType_All);
	TrackBase* GetTrack(int nIndex);
	TrackList GetTracks();
	QUndoStack* GetUndoStack();
	TrackBase* CreateTrack(int nTrackType);
	NLETimeline *GetRootTimeline();

	void SelectClip(int nTrackIndexAt, int nPosAt);
	void UnselectAll(bool bForceUpdate = false);
	ClipBase* GetSelectedClip();
protected:
	void PushCommand(TrackCommondBase *pCommond);
Q_SIGNALS:
	void signalThumbnailAvalible(ClipBase *);
	void signalTrackChanged();
	void signalTrackUpdate(int nTrackIndex);

	void signalNestedCommndExec();
private:
	friend class ComplexClip;
	QUndoStack *m_UndoStack;
	TrackOperator *m_pTrackOperator;
	NLETimeline *m_pRootTimeline;
};



#endif // TRACKMANAGER_H
