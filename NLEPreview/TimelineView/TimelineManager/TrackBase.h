#ifndef TRACKBASE_H
#define TRACKBASE_H

#include <QObject>
#include <QVector>
#include <QMap>
#include "TypeDefine.h"
class INLETimelineBase;
class ClipBase;
class ClipOperatorBase;
class QUndoStack;
class TrackManager;
class ClipCommandBase;
class TrackBase : public QObject
{
	Q_OBJECT

public:
	enum TrackType
	{
		TrackType_All = 0,
		TrackType_Vedio,
		TrackType_Effect,
		TrackType_Audio,
	};
	TrackBase(int nTrackType, TrackManager *pTrackManager,QObject *parent = nullptr);
	virtual ~TrackBase();
	//带命令方法
	virtual void AddClip(ClipBase* pClip);
	virtual void RemoveClip(ClipBase* pClip);
	virtual void MoveClip(ClipBase* pClip, TrackBase* pTo, int nTo);		
	virtual void CopyClip(ClipBase* pClip, TrackBase* pTo, int nTo);
	virtual void SplitClip(ClipBase* pClip, int nOffset);	//nOffset: 相对于该clip的偏移量
	virtual void AdjustClip(ClipBase* pClip, int nNewStartPos, int nNewLen);
	virtual void CropClip(ClipBase* pClip, const QRectF &newRegion);
	
	//普通方法
	int GetType() const;
	void SetIndex(int nIndex);
	int GetIndex() const;
	ClipList GetClips();
	ClipOperatorBase *GetClipOperator();
	ClipBase *GetSelectedClip();
	ClipBase* GetClipByPos(int nPos);
	TrackManager *GetTrackManager();

	bool IsCompatibled(ClipBase* pClip);
	bool IsCompatibled(int nClipType);

	int GetDuration();
	ClipBase* GetPreClip(ClipBase* pClip);
	ClipBase* GetNextClip(ClipBase* pClip);

	
	virtual TrackBase* Clone();

Q_SIGNALS:
	void signalTrackUpdate(int nTrackIndex);
protected:

	friend class ComplexClip;
	virtual void CloneAble(TrackBase *pFrom);
	void PushCommond(ClipCommandBase *pCommand);

	virtual void SetTrackManager(TrackManager *pTrackManager);
protected:
	TrackBase(QObject *parent = nullptr);
	TrackManager *m_pTrackManager;
	ClipOperatorBase *m_pClipOperator;
	int m_nTrackType;
	int m_nIndex;
};

class VedioTrack : public TrackBase
{
	Q_OBJECT
public:
	VedioTrack(TrackManager *pTrackManager, QObject *parent = nullptr);
	virtual ~VedioTrack();
	virtual TrackBase* Clone() override;
protected:
	VedioTrack(QObject *parent = nullptr);
	virtual void CloneAble(TrackBase *pFrom) override;
};

class AudioTrack : public TrackBase
{
	Q_OBJECT
public:
	AudioTrack(TrackManager *pTrackManager, QObject *parent = nullptr);
	virtual ~AudioTrack();
	virtual TrackBase* Clone() override;
protected:
	AudioTrack(QObject *parent = nullptr);
	virtual void CloneAble(TrackBase *pFrom) override;
};

class EffectTrack : public TrackBase
{
	Q_OBJECT
public:
	EffectTrack(TrackManager *pTrackManager, QObject *parent = nullptr);
	virtual ~EffectTrack();
	virtual TrackBase* Clone() override;
protected:
	EffectTrack(QObject *parent = nullptr);
	virtual void CloneAble(TrackBase *pFrom) override;
};

#endif // TRACKBASE_H
