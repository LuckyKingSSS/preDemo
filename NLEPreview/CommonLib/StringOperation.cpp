#include "stdafx.h"
#include "StringOperation.h"

StringOperation::StringOperation()
{
}


StringOperation::~StringOperation()
{
}

QString StringOperation::GetElidedString(QFont font, int len, const QString &text)
{
	QFontMetrics metrics(font);
	return metrics.elidedText(text, Qt::ElideRight, len);
}

int StringOperation::GetTextTrueLenght(QFont font, const QString &text)
{
	QFontMetrics metrics(font);
	return metrics.width(text);
}
