#include "stdafx.h"
#include "NLEApplication.h"


#include "inc_CommonLib/NLEBaseWidget.h"


NLEApplication::NLEApplication(int & argc, char ** argv)
:QApplication(argc, argv)
{

}


bool NLEApplication::notify(QObject *reciver, QEvent *event)
{

	NLEBaseWidgetEvent(reciver, event);

	return QApplication::notify(reciver, event);
}

bool NLEApplication::NLEBaseWidgetEvent(QObject *reciver, QEvent *event)
{
	auto isWindow = reciver->isWindowType();
	auto type = event->type();
	if (type == QEvent::MouseButtonPress || type == QEvent::MouseMove)
	{
		QWidget *pWidget = nullptr;
		if (reciver->isWindowType())
		{
			QWindow *pWindow = qobject_cast<QWindow*>(reciver);
			if (pWindow)
				pWidget = static_cast<QWidget*>(pWindow->focusObject());
		}
		else
			pWidget = qobject_cast<QWidget*>(reciver);
		
		
		
		QString objectName("NLEBaseWidget");
		QObject *nleBaseWidget = nullptr;
		QObject *parent = pWidget;
		while (parent)
		{
			if (parent->objectName() == objectName)
			{
				nleBaseWidget = parent;
				break;
			}
			parent = parent->parent();
		}

		if (nleBaseWidget)
		{
			auto list = NLEBaseWidget::GetNLEBaseWidgets();
			for (auto widget : list)
			{
				if (type == QEvent::MouseButtonPress)
					widget->SetFocus(widget == nleBaseWidget);
				else if (type == QEvent::MouseMove)
					widget->MouseMove((static_cast<QMouseEvent*>(event))->globalPos());
			}
		}
		

		return nleBaseWidget;
	}

	return false;
}

