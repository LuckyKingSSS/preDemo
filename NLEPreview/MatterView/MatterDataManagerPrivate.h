#ifndef MATTERDATAMANAGERPRIVATE_H
#define MATTERDATAMANAGERPRIVATE_H

#include <QObject>
#include <QVector>
//#include "MediaData.h"
//#include "FilterData.h"
#include "MatterDataList.h"
#include "MatterDataDefine.h"

class FilterDataList;
class MediaDataList;
class AudioFilterDataList;
class MontageDataList;
class QPixmap;
class MatterDataManagerPrivate : public QObject
{
	Q_OBJECT

public:
	MatterDataManagerPrivate(QObject *parent = nullptr);
	~MatterDataManagerPrivate();
	void Init(int nDataType);

	MediaDataList *m_pMediaDataList;
	FilterDataList *m_pFilterDataList;
	TextDataList *m_pTextDataList;
	AudioFilterDataList *m_pAudioFilterDataList;
	MontageDataList* m_pMontageDataList;
};

#endif // MATTERDATAMANAGERPRIVATE_H
