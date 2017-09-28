#ifndef THUMBNAILEXTRACTOR_H
#define THUMBNAILEXTRACTOR_H

#include <QObject>
#include <QThread>
class NLETimeline;
class INLERender;
class ThumbnailExtractHelper;
class ThumbnailExtractor : public QThread
{
	Q_OBJECT

public:
	ThumbnailExtractor(NLETimeline *pTimeline, QObject *parent);
	~ThumbnailExtractor();
	//ThumbnailExtractor* Clone();

	void SetTotalLen(int nLen);
	int GetTotalLen();
	QSize GetThumbnailSize();
	QList<QPixmap> GetThumbnails();

	void Stop();
	void WaitForQuit();
Q_SIGNALS:
	void signalGetNeededThumbnail();
protected:
	void run() override;
	QPixmap ExtractImage(int nFrame);
	void FillNeededList();

	void CalToGetFrames();
	void CloneTimeline();
	QString GetAncestralGuid();
	bool IsFull();
private:
	friend class VedioClip;
	
	NLETimeline *m_pNLETimeline;
	NLETimeline *m_pClonedTimeline;

	int m_nShowLen;
	bool m_bReStart;
	int m_nTotalFrames;

	bool m_bFirst;
	QSize m_RenderSize;
	QList<int> m_listFramesToGet;
	QList<QPixmap> m_listNeededs;

	ThumbnailExtractHelper *m_pHelper;
	bool m_bQuit;
};

#endif // THUMBNAILEXTRACTOR_H
