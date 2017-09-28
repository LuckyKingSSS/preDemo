#ifndef COMMOND_H
#define COMMOND_H

//#include <QUndoCommand>
class TrackBase;
class ClipBase;
class SimplexClip;
class OperatorBase;
class ClipOperatorBase;

class UndoCommandBase : public QObject, public QUndoCommand
{
	Q_OBJECT
public:
	UndoCommandBase(OperatorBase *pOperator, QObject* parent = nullptr);
	virtual ~UndoCommandBase();

	virtual void undo() override;
	virtual void redo() override;
protected:
	virtual void Undo();
	virtual void Redo();
Q_SIGNALS:
	void signalUpdate();
protected:
	OperatorBase *m_pOperator;
};

class  NestedCommond : public UndoCommandBase
{
	Q_OBJECT
public:
	NestedCommond(QUndoStack* pNestedStack, QObject *parent = nullptr);
	virtual ~NestedCommond();
	void Undo() override;
	void Redo() override;

	void SetCurrentCmdCounts(int nCnt);
Q_SIGNALS:
	void signalNestedCommndExec();
protected:
	QUndoStack *m_pNestedStack;
	int m_nCurCmdCounts; //本次执行的command数量
};


class ClipCommandBase : public UndoCommandBase
{
	Q_OBJECT
public:
	ClipCommandBase(OperatorBase *pOperator, QObject* parent = nullptr);
	virtual ~ClipCommandBase();
Q_SIGNALS:
	void signalClipChanged(OperatorBase *);
};


class  AddClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	AddClipCommand(ClipOperatorBase *pOperator, ClipBase *pAddClip, QObject *parent = nullptr);
	virtual ~AddClipCommand();
	void Undo() override;
	void Redo() override;
private:
	ClipBase* m_pAddClip;
};

class RemoveClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	RemoveClipCommand(ClipOperatorBase *pOperator, ClipBase* pRemoveClip, QObject *parent = nullptr);
	virtual ~RemoveClipCommand();

	void Undo() override;
	void Redo() override;

protected:
	ClipBase* m_pRemoveClip;
	int m_nPos;
};

class MoveClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	MoveClipCommand(ClipOperatorBase *pOperator, ClipBase* pMoveClip, ClipOperatorBase* pTo, int nTo, QObject *parent = nullptr);
	virtual ~MoveClipCommand();

	void Undo() override;
	void Redo() override;

protected:
	ClipBase* m_pMoveClip;
	ClipOperatorBase* m_pToOperator;
	int m_nTo;
	int m_nOrigin;
};

class CopyClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	CopyClipCommand(ClipOperatorBase *pOperator, ClipBase* pSrcClip, ClipOperatorBase* pTo, int nTo, QObject *parent = nullptr);
	virtual ~CopyClipCommand();

	void Undo() override;
	void Redo() override;

protected:
	ClipBase* m_pSrcClip;
	ClipBase* m_pDestClip;
	ClipOperatorBase* m_pToOperator;
	int m_nTo;
};

class SplitClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	SplitClipCommand(ClipOperatorBase *pOperator, ClipBase* pSplitClip, int nOffset, QObject *parent = nullptr);
	virtual ~SplitClipCommand();

	void Undo() override;
	void Redo() override;

private:
	ClipBase* m_pSplitClip;
	ClipBase* m_pNewClip;
	int m_nOffset;
};

class AdjustClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	AdjustClipCommand(ClipOperatorBase *pOperator, ClipBase* pClip, int nNewStartPos,int nNewLen, QObject *parent = nullptr);
	virtual ~AdjustClipCommand();

	void Undo() override;
	void Redo() override;

private:
	ClipBase* m_pAdjustClip;
	int m_nNewStartPos;
	int m_nNewLen;

	std::tuple<int, int> m_OriginData;
};


class CropClipCommand : public ClipCommandBase
{
	Q_OBJECT
public:
	CropClipCommand(ClipOperatorBase *pOperator, ClipBase* pClip, const QRectF &newRegion,QObject *parent = nullptr);
	virtual ~CropClipCommand();

	void Undo() override;
	void Redo() override;

private:
	ClipBase* m_pCropClip;
	QRectF m_newRegion;
	QRectF m_oldRegion;
};

class TrackCommondBase : public UndoCommandBase
{
	Q_OBJECT
public:
	TrackCommondBase(OperatorBase *pOperator, QObject* parent = nullptr);
	virtual ~TrackCommondBase();

Q_SIGNALS:
	void signalTrackChanged();
};

class TrackOperator;
class AddTrackCommond : public TrackCommondBase
{
	Q_OBJECT
public:
	AddTrackCommond(TrackOperator *pOperator, TrackBase *pTrack, int nIndex, QObject *parent = nullptr);
	virtual ~AddTrackCommond();

	void Undo() override;
	void Redo() override;

private:
	TrackBase* m_pAddTrack;
	int m_nAddIndex;
};

class RemoveTrackCommond : public TrackCommondBase
{
	Q_OBJECT
public:
	RemoveTrackCommond(TrackOperator *pOperator, TrackBase *pTrack,QObject *parent = nullptr);
	virtual ~RemoveTrackCommond();

	void Undo() override;
	void Redo() override;

private:
	TrackBase* m_pRemoveTrack;
};

class MoveTrackCommond : public TrackCommondBase
{
	Q_OBJECT
public:
	MoveTrackCommond(TrackOperator *pOperator, TrackBase *pTrack,int nIndexTo, QObject *parent = nullptr);
	virtual ~MoveTrackCommond();

	void Undo() override;
	void Redo() override;

private:
	TrackBase* m_pMoveTrack;
	int m_nIndexTo;
	int m_nIndexFrom;
};

class SwapTrackCommond : public TrackCommondBase
{
	Q_OBJECT
public:
	SwapTrackCommond(TrackOperator *pOperator, TrackBase *pTrack1, TrackBase *pTrack2, QObject *parent = nullptr);
	virtual ~SwapTrackCommond();

	void Undo() override;
	void Redo() override;

private:
	TrackBase* m_pTrack1;
	TrackBase* m_pTrack2;
};

#endif // COMMOND_H
