#pragma once

#include <QtWidgets/QApplication>

class NLEApplication : public QApplication
{
public:
	NLEApplication(int & argc, char ** argv);
	
protected:
	bool notify(QObject *reciver, QEvent *event);

private:
	bool NLEBaseWidgetEvent(QObject *reciver, QEvent *event);
};
