#ifndef CLIPBASE_H
#define CLIPBASE_H

#include <QObject>
#include <QSize>
//#include "windows.h"
#ifndef min
#define min(a,b) (a) < (b) ? (a) : (b)
#endif 
#ifndef max
#define max(a,b) (a) > (b) ? (a) : (b)
#endif 
#include "NLEComPtr.h"
#include "INLETimelineBase.h"
class NLETimeline;
class INLETimelineBase;
class TrackBase;
class ThumbnailExtractor;
class ClipBase : public QObject
{
	Q_OBJECT
public:
	enum ClipBaseType
	{
		ClipType_Vedio = 0,
		ClipType_Effect,
		ClipType_Audio,
		ClipType_Complex,
	};
	ClipBase(int nType, TrackBase* pOwnerTrack = nullptr,QObject *parent = nullptr);
	virtual ~ClipBase();

	virtual ClipBase* Clone() = 0;
	virtual void SetThumbnailTotalLength(int nLen) = 0;
	virtual int GetThumbnailTotalLength();
	virtual QSize GetThumbnailSize() = 0;
	virtual QList<QPixmap> GetThumbnails() = 0;
	

	virtual int GetStartAtTrack() const;
	virtual void SetStartAtTrack(int nNewPos);
	virtual int GetLenAtTrack() const;
	virtual int GetStartAtSrc() const;
	virtual int GetSrcLen() const;


	virtual bool IsSelected() const;
	virtual void Select(bool bSelected);

	virtual bool IsCropable();


	int GetType() const;
	QString GetName() const;

	ClipBase* PreClip();
	ClipBase* NextClip();
	NLETimeline *GetSrcTimeline();
	void SetSrcTimeline(NLETimeline *pSrc);

	void SetOwnerTrack(TrackBase* pOwner);
	TrackBase* GetOwnerTrack();

	ClipBase* ParentClip();
	void SetParentClip(ClipBase *pParentClip);

Q_SIGNALS:
	void signalThumbnailAvalible(ClipBase*);
protected:
	ClipBase(QObject *parent = nullptr);
	virtual void CloneAble(ClipBase* pAnther);
protected:
	int m_nClipType;
	int m_nStartAtTrack;
	bool m_bSelected;
	TrackBase *m_pOwnerTrack;
	NLETimeline *m_pSrc;
	ClipBase *m_pParentClip;
};

class ComplexClipController;
class ComplexClip : public ClipBase
{
	Q_OBJECT
public:
	ComplexClip(TrackBase* pOwnerTrack = nullptr,QObject *parent = nullptr);
	virtual ~ComplexClip();

	ComplexClipController* GetComplexClipController();
	ClipBase* Clone() override;
	virtual void SetThumbnailTotalLength(int nLen) override;
	virtual QSize GetThumbnailSize() override { return QSize(); };
	virtual QList<QPixmap> GetThumbnails() override { return QList<QPixmap>(); };

	void SetSeekPos(int nPos);
	int GetSeekPos();
protected:
	ComplexClip(QObject *parent);
	void CloneAble(ClipBase* pAnther) override;
protected:
	ComplexClipController *m_pComplexClipController;
	int m_nSeekPos;
};


class SimplexClip : public ClipBase
{
	Q_OBJECT
public:
	SimplexClip(NLETimeline *pSrc, int nType, TrackBase* pOwnerTrack = nullptr, const QString &strAncestralGuid = "", QObject *parent = nullptr);
	virtual ~SimplexClip();
	virtual ClipBase* Clone() override;
	virtual void SetThumbnailTotalLength(int nLen) override {};
	virtual QSize GetThumbnailSize() override { return QSize(); };
	virtual QList<QPixmap> GetThumbnails() override { return QList<QPixmap>(); };

protected:
	SimplexClip(QObject *parent = nullptr);
	virtual void CloneAble(ClipBase* pAnther) override;
};

class VedioClip : public SimplexClip
{
	Q_OBJECT
public:
	VedioClip(NLETimeline* pSrc, TrackBase* pOwnerTrack = nullptr, const QString &strAncestralGuid="", QObject *parent = nullptr);
	virtual ~VedioClip();
	virtual ClipBase* Clone() override;
	virtual void SetThumbnailTotalLength(int nLen) override;
	virtual int GetThumbnailTotalLength() override;
	virtual QSize GetThumbnailSize() override;
	virtual QList<QPixmap> GetThumbnails() override;
protected:
	VedioClip(QObject *parent = nullptr);
	virtual void CloneAble(ClipBase* pAnther) override;

	ThumbnailExtractor *m_pThumbnailExtractor;
};

class AudioClip : public SimplexClip
{
	Q_OBJECT
public:
	AudioClip(NLETimeline* pSrc, TrackBase* pOwnerTrack = nullptr, const QString &strAncestralGuid = "", QObject *parent = nullptr);
	virtual ~AudioClip();
};

class EffectClip : public SimplexClip
{
	Q_OBJECT
public:
	EffectClip(NLETimeline* pSrc, TrackBase* pOwnerTrack = nullptr, const QString &strAncestralGuid = "", QObject *parent = nullptr);
	virtual ~EffectClip();
	virtual ClipBase* Clone() override;
	virtual int GetStartAtTrack() const;
	virtual void SetStartAtTrack(int nNewPos);

	virtual int GetLenAtTrack() const;

	virtual int GetStartAtSrc() const;

	virtual int GetSrcLen() const;
protected:
	EffectClip(QObject *parent = nullptr);
};

#endif // CLIPBASE_H
