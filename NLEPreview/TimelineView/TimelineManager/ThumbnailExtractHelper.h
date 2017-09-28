#ifndef THUMBNAILEXTRACTHELPER_H
#define THUMBNAILEXTRACTHELPER_H

#include <QObject>
class ThumbnailInfo
{
public:
	ThumbnailInfo(const QString &guid)
		: strGuid(guid)
	{}

	int GetSize()
	{
		return mapThumbnails.size();
	}
	void insertItem(int nFrame, QPixmap pix)
	{
		m_Lock.lock();

		if (!mapThumbnails.contains(nFrame))
		{
			mapThumbnails.insert(nFrame, pix);
		}
		m_Lock.unlock();
	}

	QPixmap GetThumbnail(int nFrame)
	{
		m_Lock.lock();
		QPixmap pix = mapThumbnails.value(nFrame);
		m_Lock.unlock();
		return pix;
	}

	bool IsThumbnailExist(int nFrame)
	{
		return mapThumbnails.contains(nFrame);
	}

	QMap<int, QPixmap>& GetThumbnailInfo()
	{
		return mapThumbnails;
	}
private:
	QString strGuid;
	QMap<int, QPixmap> mapThumbnails;
	QMutex m_Lock;
};

class ThumbnailExtractHelper : public QObject
{
	Q_OBJECT

public:
	static ThumbnailExtractHelper* GetInstance();
	~ThumbnailExtractHelper();

	void InsertThumbnail(const QString &strGuid, int nFrame, QPixmap pix);
	QPixmap GetThumbnail(const QString &strGuid, int nFrame);
	int GetSize(const QString &strGuid);

	bool IsThumbnailExist(const QString &strGuid, int nFrame);

	ThumbnailInfo* GetThumbnailInfo(const QString &strGuid);
private:
	static ThumbnailExtractHelper *pThis;
	ThumbnailExtractHelper(QObject *parent = nullptr);
	QMap<QString, ThumbnailInfo*> m_mapThumbnails;

};

#endif // THUMBNAILEXTRACTHELPER_H
