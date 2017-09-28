#ifndef COMPLEXCLIPCONTROLLER_H
#define COMPLEXCLIPCONTROLLER_H

#include <QObject>
//#include "windows.h"
#include "NLEComPtr.h"
class INLETimelineBase;
class TrackManager;
class ClipBase;
class TrackBase;
class SimplexClip;
class ComplexClip;
class NLETimeline;


class ComplexClipController : public QObject
{
	Q_OBJECT

public:
	ComplexClipController(NLETimeline *pRootTimeline,QObject *parent);
	~ComplexClipController();

	TrackManager* GetTrackManager();
Q_SIGNALS:
	void signalThumbnailAvalible(int nTrackIndex);
	void signalTrackChanged();
	void signalTrackUpdate(int nTrackIndex);

	void signalNestedCommndExec();
private:
	friend class TimelineManager;
	ClipBase* AddClip(int nTrackIndexTo, int nPosTo, NLETimeline *pSrc, int nClipType, bool bForceCreate = false);
	void MoveClip(int nTrackIndexTo, int nPosTo, bool bForceCreate);

	void CopyFrom(bool bCut);
	ClipBase* CopyTo(int nPosTo);

	void SplitClip(int nPos);
	void RemoveClip();
	/*
	*  AdjustClip： 调整时长
	*  nLeftOrRight:拉动clip的左边或右边，0表示左边,1表示右边;
	*  nPosTo: 拉动到哪个位置
	*/
	void AdjustClip(int nLeftOrRight, int nPosTo);
	void CropClip();
	void TextEdit();

	void SelectClip(int nTrackIndexAt, int nPosAt);
	void UnselectAll(bool bForceUpdate = false);
	ClipBase* GetSelectedClip();
	ComplexClip* GetComplexClip();
	//将当前clip转换为Complex clip
	void ConvertToComplex();

	
private:
	int TrackTypeFromClipType(int nClipType);
	TrackBase* GetTrack(ClipBase* pClip);
	bool IsCollided(TrackBase* pTrackTo,int nPosTo, ClipBase *pSrcClip);

	SimplexClip* CreateSimplexClip(int nSimplexType, NLETimeline* pSrc, const QString &strAncestralGuid = "");
	ComplexClip* CreateComplexClip(SimplexClip* pClip);
private: 
	TrackManager *m_pTrackManager;
	ClipBase* m_pCopyedClip;
	ComplexClip *m_pCurComplexClip;
};

#endif // COMPLEXCLIPCONTROLLER_H
