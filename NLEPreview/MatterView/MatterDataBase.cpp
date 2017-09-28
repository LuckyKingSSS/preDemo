#include "stdafx.h"
#include "MatterDataBase.h"
#include "inc_MatterView/MatterDataDefine.h"


MatterDataBase::MatterDataBase(int nType, const QString &id)
: nDataType(nType)
, strId(id)
{
	pTimeline = nullptr;
}


MatterDataBase::~MatterDataBase()
{
	SAFE_DELETE(pTimeline);
}

//////////////////////////////////////////////////////////////////////////
MediaData::MediaData(const QString &id)
:MatterDataBase(MatterDataType_Media, id)
{
}


MediaData::~MediaData()
{
}

//////////////////////////////////////////////////////////////////////////
FilterData::FilterData(const QString &id)
:MatterDataBase(MatterDataType_Effect, id)
{
}


FilterData::~FilterData()
{
}

//////////////////////////////////////////////////////////////////////////
TextData::TextData(const QString &id)
:MatterDataBase(MatterDataType_Text, id)
{

}

TextData::~TextData()
{

}

//////////////////////////////////////////////////////////////////////////
AudioFilterData::AudioFilterData(const QString &id)
:MatterDataBase(MatterDataType_Audio_Effect, id)
{

}

AudioFilterData::~AudioFilterData()
{

}

//////////////////////////////////////////////////////////////////////////
MontageData::MontageData(const QString &id)
:MatterDataBase(MatterDataType_Montage, id)
{

}

MontageData::~MontageData()
{

}
