#include "stdafx.h"
#include "timelineviewprivate.h"


#include <QtWidgets/QApplication>


static void sSetApplicationStyleSheet();
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	sSetApplicationStyleSheet();

	TimelineViewPrivate timelineView(nullptr);
	timelineView.setMinimumSize(1000, 350);
	timelineView.showMaximized();


	return a.exec();
}



void sSetApplicationStyleSheet()
{
	qApp->setStyleSheet(
		// 时间线
		// 时间线
		"QWidget#TimelineView_TimelineViewRuler{ background-color: rgb(240,240,240);}"

		"QWidget#TimelineView_TimelineViewTrackRulerToolBar {background-color: rgb(245,240,240); }"

		"BaseButton#TimelineView_TimelineViewTrackRuler_TrackSet { background-image:rgb(240,240,240) url(:/TimelineViewPrivate/Resources/normal/TimelineView_TrackSet_n.png); background-position: center; background-repeat:no-repeat; }"
		"BaseButton#TimelineView_TimelineViewTrackRuler_TrackSet:hover { background-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_TrackSet_h.png); background-position: center; background-repeat:no-repeat; }"
		"BaseButton#TimelineView_TimelineViewTrackRuler_TrackSet:disabled { background-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_TrackSet_d.png); background-position: center; background-repeat:no-repeat; }"

		"QWidget#TimelineView_TimelineViewTrackItem_Head_Video { background-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Header_Video_n.png); background-position: center; background-repeat:no-repeat; }"
		"QWidget#TimelineView_TimelineViewTrackItem_Head_Effect { background-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Header_Effect_n.png); background-position: center; background-repeat:no-repeat;}"
		"QWidget#TimelineView_TimelineViewTrackItem_Head_Audio { background-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Header_Audio_n.png); background-position: center; background-repeat:no-repeat;}"

		"BaseButton#TimelineView_TrackRulerToolBar_Undo { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Undo_n.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Undo:hover { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Undo_h.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Undo:disabled { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Undo_d.png) }"

		"BaseButton#TimelineView_TrackRulerToolBar_Redo { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Redo_n.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Redo:hover { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Redo_h.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Redo:disabled { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Redo_d.png) }"

		"BaseButton#TimelineView_TrackRulerToolBar_Cut { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Cut_n.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Cut:hover { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Cut_h.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Cut:disabled { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Cut_d.png) }"

		"BaseButton#TimelineView_TrackRulerToolBar_Delete { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Delete_n.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Delete:hover { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Delete_h.png) }"
		"BaseButton#TimelineView_TrackRulerToolBar_Delete:disabled { border-image:url(:/TimelineViewPrivate/Resources/normal/TimelineView_Delete_d.png) }"

		// Scrollbar
		"QScrollBar:vertical { border: none; background: transparent; width: 15px; margin: 10px 0px 10px 0px; } QScrollBar::handle:vertical {  border: 1px solid #9A9CC0; border-radius: 4px; background: #9A9CC0; min-height: 20px; margin-left: 3px; margin-right: 3px; }  QScrollBar::add-line:vertical { border: none; background: #32CC99; height: 0px; subcontrol-position: right; subcontrol-origin: margin; }   QScrollBar::sub-line:vertical { border: none; background: #32CC99; height: 0px; subcontrol-position: left; subcontrol-origin: margin; }   QScrollBar:up-arrow:vertical, QScrollBar::down-arrow:vertical { border: 2px solid grey; width: 0px; height: 0px; background: transparent; }   QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: transparent; }"
		"QScrollBar:horizontal { border: none; background: transparent; height: 15px; margin: 0px 10px 0px 10px; } QScrollBar::handle:horizontal {  border: 1px solid #9A9CC0; border-radius: 4px; background: #9A9CC0; min-height: 20px; margin-top: 3px; margin-bottom: 3px; }  QScrollBar::add-line:horizontal { border: none; background: transparent; width: 0px; subcontrol-position: right; subcontrol-origin: margin; }   QScrollBar::sub-line:horizontal { border: none; background: transparent; wdith: 0px; subcontrol-position: left; subcontrol-origin: margin; }   QScrollBar:up-arrow:horizontal, QScrollBar::down-arrow:horizontal { border: 2px solid grey; width: 0px; height: 0px; background: transparent; }   QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal { background: transparent; }"

		);


	QString s = "QScrollBar:vertical { border: none; background: white; width: 15px; margin: 10px 0px 10px 0px; } QScrollBar::handle:vertical {  border: 1px solid #9A9CC0; border-radius: 4px; background: #9A9CC0; min-height: 20px; margin-left: 3px; margin-right: 3px; }  QScrollBar::add-line:vertical { border: none; background: #32CC99; height: 0px; subcontrol-position: right; subcontrol-origin: margin; }   QScrollBar::sub-line:vertical { border: none; background: #32CC99; height: 0px; subcontrol-position: left; subcontrol-origin: margin; }   QScrollBar:up-arrow:vertical, QScrollBar::down-arrow:vertical { border: 2px solid grey; width: 0px; height: 0px; background: white; }   QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; } ";
}
