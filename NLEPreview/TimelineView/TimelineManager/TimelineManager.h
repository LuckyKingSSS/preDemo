#ifndef TIMELINEMANAGER_H
#define TIMELINEMANAGER_H

#include <QObject>
#include <QStack>
#include <QPoint>


class ComplexClip;
class ComplexClipController;
class INLETimelineBase;
class ClipBase;
class PlayController;
class NLETimeline;
class TimelineManager : public QObject
{
	Q_OBJECT

public:
	static TimelineManager* GetInstance();
	~TimelineManager();
	
	ClipBase* AddClip(int nTrackIndexTo, int nPosTo, NLETimeline *pSrc, int nClipType, bool bForceCreate = false);
	void MoveClip(int nTrackIndexTo, int nPosTo,bool bForceCreate = false);  //bForceCreate:ǿ�ƽ����������ǿ�������¹��
	void CopyFrom(bool bCut = false);
	ClipBase* CopyTo(int nPos);
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
	void UnselectAll();
	ClipBase* GetSelectedClip();


	//����ǰclipת��ΪComplex clip
	void ConvertToComplex();
	void EnterComplexClip();
	void LeaveComplexClip();
	
	bool CanUndo();
	bool CanRedo();
	void Undo();
	void Redo();
	ComplexClipController* CurrentController();
	ComplexClip *CurrentComplexClip();

	int MatterType2ClipType(int nMatterType);
	bool IsCompatible(int nClipType,int nTrackType);
	
	void AdjustRootClipLength();
Q_SIGNALS:
	void signalThumbnailAvalible(int nTrackIndex);
	void signalTrackRebuild();
	void signalTrackUpdate(int nTrackIndex);
	void signalCanUndoChanged(bool canUndo);
	void signalCanRedoChanged(bool canRedo);
protected:
	void ConnectSignals(ComplexClip* pClip);
	void DisconnectSignals(ComplexClip* pClip);
	void SetCurrentComplexClip(ComplexClip* pClip);

	void BackupRange(ComplexClip* pClip);
	void RestoreRange(ComplexClip* pClip);

	void RestoreAllRange();

	int GetCmdCount(ComplexClip* pClip);
	QUndoStack *CurrentUndoStack();
	QUndoStack *GetUndoStack(ComplexClip* pClip);

private:
	TimelineManager(QObject *parent = nullptr);
	ComplexClip* m_pCurComplexClip;    
	QStack<ComplexClip*> m_BackupComplexClips;
	QMap<ComplexClip*, QPoint> m_mapBackupRanges;
	QMap<ComplexClip*, int> m_mapBackupCmdCnts;
};


#endif // TIMELINEMANAGER_H
