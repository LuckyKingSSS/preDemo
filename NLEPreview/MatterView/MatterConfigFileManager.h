#ifndef MATTERCONFIGFILEMANAGER_H
#define MATTERCONFIGFILEMANAGER_H

//����Դxml�ļ��Ĳ���

#include <QObject>
class MediaData;
class MatterConfigFileManager : public QObject
{
	Q_OBJECT

public:
	static MatterConfigFileManager& GetInstance();
	~MatterConfigFileManager();
	void SetMediaConfigFile(const QString &strPath);
	
	void AddMediaItem(MediaData *pData);
	void RemoveMediaItem(MediaData *pData);
private:
	MatterConfigFileManager(QObject *parent = nullptr);

	QString m_strMediaConfigFile;
};

#endif // MATTERCONFIGFILEMANAGER_H
