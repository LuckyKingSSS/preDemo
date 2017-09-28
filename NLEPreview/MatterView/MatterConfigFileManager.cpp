#include "stdafx.h"
#include "MatterConfigFileManager.h"
#include "FileOperation.h"
#include "XmlOperation.h"
#include "inc_MatterView/MatterDataBase.h"
#include <QFile>


MatterConfigFileManager::MatterConfigFileManager(QObject *parent)
	: QObject(parent)
{

}

MatterConfigFileManager::~MatterConfigFileManager()
{

}

MatterConfigFileManager& MatterConfigFileManager::GetInstance()
{
	static MatterConfigFileManager instance;
	return instance;
}

void MatterConfigFileManager::SetMediaConfigFile(const QString &strPath)
{
	m_strMediaConfigFile = strPath;
}

void MatterConfigFileManager::AddMediaItem(MediaData *pData)
{
	if (!pData) return;
	if (!FileOperation::IsFileExist(m_strMediaConfigFile)) return;

	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strMediaConfigFile)) return;

	QDomElement rootElem = doc.documentElement();

	QDomElement newElem = doc.createElement("FileResourceInfo");
	newElem.setAttribute("id", pData->strSourceFileUrl);
	XmlOperation::AddXmlElement(doc, newElem, "ResType", QString("%1").arg(pData->nResType));
	XmlOperation::AddXmlElement(doc, newElem, "SourceFileUrl", pData->strSourceFileUrl);
	XmlOperation::AddXmlElement(doc, newElem, "Caption", pData->strCaption);
	XmlOperation::AddXmlElement(doc, newElem, "ResourceTag", pData->strResourceTag);
	XmlOperation::AddXmlElement(doc, newElem, "ThumbFileName", FileOperation::GetFileName(pData->strThumbFilePath));
	XmlOperation::AddXmlElement(doc, newElem, "Visible", pData->bVisible ? "1" : "0");
	rootElem.appendChild(newElem);

	QFile file(m_strMediaConfigFile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;
	QTextStream outStream(&file);
	doc.save(outStream,4);
	file.close();
}

void MatterConfigFileManager::RemoveMediaItem(MediaData *pData)
{
	if (!pData) return;
	if (!FileOperation::IsFileExist(m_strMediaConfigFile)) return;

	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strMediaConfigFile)) return;

	QDomElement rootElem = doc.documentElement();
	
	QDomElement childElem = rootElem.firstChildElement("FileResourceInfo");
	while (!childElem.isNull())
	{
		if(childElem.attribute("id") == pData->strId)
			break;
		childElem = childElem.nextSiblingElement();
	}
	rootElem.removeChild(childElem);

	QFile file(m_strMediaConfigFile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;
	QTextStream outStream(&file);
	doc.save(outStream, 4);
	file.close();
}
