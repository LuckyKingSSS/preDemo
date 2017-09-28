#ifndef OPERATORBASE_H
#define OPERATORBASE_H

#include <QObject>
#include "TypeDefine.h"
class ClipBase;
class TrackBase;
class NLETimeline;
class OperatorBase
{
public:
	OperatorBase();
	virtual ~OperatorBase();
	
	virtual int ItemCount() = 0;
	virtual void SetRootTimeline(NLETimeline *pRootTimeline);
protected:
	NLETimeline *m_pRootTimeline;
};

class TrackBase;
class ClipOperatorBase : public OperatorBase
{
public: 
	ClipOperatorBase(TrackBase *pOwner);
	virtual ~ClipOperatorBase();

	int ItemCount() override;
	void AddClip(ClipBase *pClip);
	void RemoveClip(ClipBase *pClip);
	int MoveClip(ClipBase* pClip, ClipOperatorBase* pTo, int nTo); //返回原来的位置
	ClipBase* CopyClip(ClipBase* pClip, ClipOperatorBase* pTo, int nTo);  //返回复制出来的clip

	ClipBase* SplitClip(ClipBase* pClip, int nOffset);				//返回第2个clip
	void SplitClipEx(ClipBase *pClip,ClipBase *pNewClip);			//第二次执行redo时调用，pNewClip是之前切割出来的clip
	void UndoSplitClip(ClipBase* pClip1, ClipBase* pClip2);
	
	std::tuple<int,int> AdjustClip(ClipBase* pClip, int nStartPos, int nLen);
	void CropClip(ClipBase* pClip,const QRectF &region);

	ClipBase* GetClip(int nClipIndex);
	ClipBase* GetPreClip(ClipBase* pClip);
	ClipBase* GetNextClip(ClipBase* pClip);
	ClipList GetClips();
	TrackBase *GetOwnerTrack();
protected:
	friend class VedioTrack;
	friend class AudioTrack;
	friend class EffectTrack;
	int GetInsertIndex(int nPos);
	int GetClipIndex(ClipBase* pClip);
protected:
	ClipList m_listClips;
	TrackBase *m_pOwner;
};

class VedioClipOperator : public ClipOperatorBase
{
public:
	VedioClipOperator(TrackBase *pOwner);
	virtual ~VedioClipOperator();
};

class AudioClipOperator : public ClipOperatorBase
{
public:
	AudioClipOperator(TrackBase *pOwner);
	virtual ~AudioClipOperator();
};

class EffectClipOperator : public ClipOperatorBase
{
public:
	EffectClipOperator(TrackBase *pOwner);
	virtual ~EffectClipOperator();
};

class TrackManager;
class TrackOperator : public OperatorBase
{
public:
	TrackOperator();
	virtual ~TrackOperator();
	void Init(TrackManager *pTrackManager);
	void AddTrack(TrackBase* pTrack,int nIndex);
	void RemoveTrack(TrackBase* pTrack);
	int MoveTrack(TrackBase* pTrack, int nIndexTo);
	void SwapTrack(TrackBase* pTrackFrom, TrackBase* pTrackTo);

	int ItemCount() override;
	int ItemCountWithType(int nType);
	TrackBase* GetTrack(int nIndex);
	TrackList GetTracks();
protected:
	friend class ComplexClip;
	void ResetIndex();
	void Clear();
protected:
	TrackList m_listTracks;
};

#endif // OPERATORBASE_H
