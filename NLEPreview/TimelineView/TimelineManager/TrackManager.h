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
	
	//�������
	void AddTrack(TrackBase *pTrack, int nIndex);
	void RemoveTrack(TrackBase *pTrack);
	void MoveTrack(TrackBase *pTrack, int nIndexTo);
	void SwapTrack(TrackBase *pTrack1, TrackBase *pTrack2);
	//������ϵ�ǰstack��������ñ���ɶԳ���
	void BeginComposite();  
	void EndComposite();

	//����༭�ӵ�complex clipǰ���ã�Ŀ���ǽ�����clip������commond�������
	void CompositeSubUndoStack(QUndoStack* pSubUndoStack,int nCommandCounts);

	//��ͨ����
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
