#include "stdafx.h"
#include "nlepreview.h"
#include <QtWidgets/QApplication>

#include "NLEApplication.h"

#include "inc_CommonLib/GlobalResources.h"

#ifndef WIN32
#include <mach-o/dyld.h>
#include <wchar.h>
#include <objbase.h>
#include "WSLog.h"
#endif


static void InitGlobalResource()
{
//#ifdef WIN32
    ICaptionEnvironment::GetInstance();
//#endif
}

void sSetApplicationStyleSheet();

#include "inc_CommonLib/CommonWidgets.h"
int main(int argc, char *argv[])
{
	
	qputenv("QT_DEVICE_PIXEL_RATIO", "auto");
	NLEApplication a(argc, argv);

#ifndef WIN32
	//char exe_path_temp[MAX_PATH] = { 0 };
	//uint32_t executable_length = 0;
	//_NSGetExecutablePath(NULL, &executable_length);
	//_NSGetExecutablePath(exe_path_temp, &executable_length);
	//*(strrchr(exe_path_temp, '/')) = L'\0';
	//QString workDir = exe_path_temp; 
	//bool bOK = QDir::setCurrent(workDir);
	//printf("%d\n", bOK);
	//qDebug() << workDir;

	QString appDir = QApplication::applicationDirPath();
	bool bOK = QDir::setCurrent(appDir);
	WSLogInit();
	std::wstring str = appDir.toStdWString();
	SetAppPath(str.c_str());
#endif
	

	NLESplashScreen splash;
	splash.show();

	InitGlobalResource();

	NLEPreview nlePreview;
	splash.finish(&nlePreview);

	nlePreview.ShowMaximized();
	return a.exec();
}
