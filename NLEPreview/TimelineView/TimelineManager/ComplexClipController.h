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
	*  AdjustClip�� ����ʱ��
	*  nLeftOrRight:����clip����߻��ұߣ�0��ʾ���,1��ʾ�ұ�;
	*  nPosTo: �������ĸ�λ��
	*/
	void AdjustClip(int nLeftOrRight, int nPosTo);
	void CropClip();
	void TextEdit();

	void SelectClip(int nTrackIndexAt, int nPosAt);
	void UnselectAll(bool bForceUpdate = false);
	ClipBase* GetSelectedClip();
	ComplexClip* GetComplexClip();
	//����ǰclipת��ΪComplex clip
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
