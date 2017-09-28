#ifndef IMPORTEXPORTHELPER_H
#define IMPORTEXPORTHELPER_H

#include <QThread>
#include <QStringList>


enum ImportFilterType{ FilterType_Video, FilterType_Audio, FilterType_Image, FilterType_All};
static const QString ImportFilter[][2] = {
	{"Video files", "*.wmv *.mov *.mp4 *.avi *.flv *.rmvb *.mkv *3g2 *3gp *dv *flv *m4v *mpg *ts *webm *tp *trp *m2t *m2ts"},
	{"Audio files", "*.mp3 *.mp2 *.wav *.wma" },
	{"Image files", "*.bmp *.jpg *.png *.jpeg"},
	{"All files", "(*.*)"}
};

class MatterDataBase;
class ImportHelper : public QThread
{
	Q_OBJECT

public:
	ImportHelper(const QStringList &list,QObject *parent);
	~ImportHelper();

	void DoImportAsync();
	void UserCancel();

Q_SIGNALS:
	void signalImported(MatterDataBase*);
	void signalImportBegin(const QString &fileName);
	void signalImportProgressText(const QString &progressText);
	void signalImportProgress(int progress);
protected:
	void run();
	bool PreCheck();   //检查要加载的文件，是否已加载过

	MatterDataBase* CreateMatterData(const QString &fullName);
	int GetDataType(const QString &fullName);
	QString GetCaption(const QString &fullName);
	QString ExtractThumbnail(const QString &fullName, const QString &saveDir, int nType); //返回缩略图的保存路径
	QString ExtractVideoThumbnail(const QString &fullName, const QString &saveDir);
	QString ExtractMusicThumbnail(const QString &fullName, const QString &saveDir);
	QString ExtractImageThumbnail(const QString &fullName, const QString &saveDir);
	
private:
	QStringList fileNames;
	bool m_bUserCancel;
};

#endif // IMPORTEXPORTHELPER_H
