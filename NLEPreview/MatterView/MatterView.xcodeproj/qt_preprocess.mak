#############################################################################
# Makefile for building: libMatterView.1.0.0.dylib
# Generated by qmake (3.0) (Qt 5.4.1)
# Project:  MatterView.pro
# Template: lib
# Command: /Users/admin/Qt5.4.1/5.4/clang_64/bin/qmake -spec macx-xcode -o MatterView.xcodeproj/project.pbxproj MatterView.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/admin/Qt5.4.1/5.4/clang_64/bin/moc
UIC       = 
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I. -IControls -I../../../../Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Versions/5/Headers -I../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks/AGL.framework/Headers -I../../../../Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -F/Users/admin/Qt5.4.1/5.4/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

IMAGES = 
PARSERS =
preprocess: $(PARSERS) compilers
clean preprocess_clean: parser_clean compiler_clean

parser_clean:
mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compilers: qrc_Resource.cpp moc_ImportHelper.cpp moc_ImportMediaDlg.cpp moc_MatterConfigFileManager.cpp\
	 moc_MatterDataManagerPrivate.cpp moc_matterviewprivate.cpp moc_matterviewtoolbar.cpp\
	 moc_ColorBlock.cpp moc_EffectItemView.cpp moc_IconButton.cpp\
	 moc_ImageItemView.cpp moc_ImgButton.cpp moc_ItemBaseView.cpp\
	 moc_MusicItemView.cpp moc_NormalItemView.cpp moc_ResListView.cpp\
	 moc_ResProgressBar.cpp moc_SelectionBorder.cpp moc_VideoItemView.cpp
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all: qrc_Resource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_Resource.cpp
qrc_Resource.cpp: Resource.qrc \
		Resources/delete5213.png \
		Resources/music_1613.png \
		Resources/filter2222.png \
		Resources/media2222.png \
		Resources/addbutton.png \
		Resources/video_1612.png \
		Resources/import5213.png
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/rcc -name Resource Resource.qrc -o qrc_Resource.cpp

compiler_moc_header_make_all: moc_ImportHelper.cpp moc_ImportMediaDlg.cpp moc_MatterConfigFileManager.cpp moc_MatterDataManagerPrivate.cpp moc_matterviewprivate.cpp moc_matterviewtoolbar.cpp moc_ColorBlock.cpp moc_EffectItemView.cpp moc_IconButton.cpp moc_ImageItemView.cpp moc_ImgButton.cpp moc_ItemBaseView.cpp moc_MusicItemView.cpp moc_NormalItemView.cpp moc_ResListView.cpp moc_ResProgressBar.cpp moc_SelectionBorder.cpp moc_VideoItemView.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ImportHelper.cpp moc_ImportMediaDlg.cpp moc_MatterConfigFileManager.cpp moc_MatterDataManagerPrivate.cpp moc_matterviewprivate.cpp moc_matterviewtoolbar.cpp moc_ColorBlock.cpp moc_EffectItemView.cpp moc_IconButton.cpp moc_ImageItemView.cpp moc_ImgButton.cpp moc_ItemBaseView.cpp moc_MusicItemView.cpp moc_NormalItemView.cpp moc_ResListView.cpp moc_ResProgressBar.cpp moc_SelectionBorder.cpp moc_VideoItemView.cpp
moc_ImportHelper.cpp: ../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QThread \
		../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QStringList \
		ImportHelper.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib ImportHelper.h -o moc_ImportHelper.cpp

moc_ImportMediaDlg.cpp: ImportMediaDlg.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib ImportMediaDlg.h -o moc_ImportMediaDlg.cpp

moc_MatterConfigFileManager.cpp: ../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QObject \
		MatterConfigFileManager.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib MatterConfigFileManager.h -o moc_MatterConfigFileManager.cpp

moc_MatterDataManagerPrivate.cpp: ../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QObject \
		../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QVector \
		MatterDataManagerPrivate.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib MatterDataManagerPrivate.h -o moc_MatterDataManagerPrivate.cpp

moc_matterviewprivate.cpp: Controls/ListItemData.h \
		matterviewprivate.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib matterviewprivate.h -o moc_matterviewprivate.cpp

moc_matterviewtoolbar.cpp: matterviewtoolbar.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib matterviewtoolbar.h -o moc_matterviewtoolbar.cpp

moc_ColorBlock.cpp: Controls/ColorBlock.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ColorBlock.h -o moc_ColorBlock.cpp

moc_EffectItemView.cpp: Controls/NormalItemView.h \
		Controls/ItemBaseView.h \
		Controls/EffectItemView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/EffectItemView.h -o moc_EffectItemView.cpp

moc_IconButton.cpp: Controls/IconButton.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/IconButton.h -o moc_IconButton.cpp

moc_ImageItemView.cpp: Controls/NormalItemView.h \
		Controls/ItemBaseView.h \
		Controls/ImageItemView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ImageItemView.h -o moc_ImageItemView.cpp

moc_ImgButton.cpp: Controls/ImgButton.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ImgButton.h -o moc_ImgButton.cpp

moc_ItemBaseView.cpp: Controls/ItemBaseView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ItemBaseView.h -o moc_ItemBaseView.cpp

moc_MusicItemView.cpp: Controls/NormalItemView.h \
		Controls/ItemBaseView.h \
		Controls/MusicItemView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/MusicItemView.h -o moc_MusicItemView.cpp

moc_NormalItemView.cpp: Controls/ItemBaseView.h \
		Controls/NormalItemView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/NormalItemView.h -o moc_NormalItemView.cpp

moc_ResListView.cpp: ../../../../Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Versions/5/Headers/QMouseEvent \
		../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QTimer \
		../../../../Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers/QTime \
		Controls/NormalItemView.h \
		Controls/ItemBaseView.h \
		Controls/ListItemData.h \
		Controls/ResListView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ResListView.h -o moc_ResListView.cpp

moc_ResProgressBar.cpp: ../../../../Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Versions/5/Headers/QColor \
		Controls/ResProgressBar.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/ResProgressBar.h -o moc_ResProgressBar.cpp

moc_SelectionBorder.cpp: Controls/SelectionBorder.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/SelectionBorder.h -o moc_SelectionBorder.cpp

moc_VideoItemView.cpp: Controls/NormalItemView.h \
		Controls/ItemBaseView.h \
		Controls/VideoItemView.h
	/Users/admin/Qt5.4.1/5.4/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I/Users/admin/Qt5.4.1/5.4/clang_64/mkspecs/macx-clang -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView -I/Users/admin/Documents/project/NLEPreview/MatterView/Controls -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtGui.framework/Headers -I/Users/admin/Qt5.4.1/5.4/clang_64/lib/QtCore.framework/Headers -F/Users/admin/Qt5.4.1/5.4/clang_64/lib Controls/VideoItemView.h -o moc_VideoItemView.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_header_clean 

