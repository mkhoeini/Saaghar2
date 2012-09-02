
project(pQjWidgets)


set(HDRS
	QExtendedSplashScreen/qextendedsplashscreen.h
	QMultiSelectWidget/qmultiselectwidget.h
	QSearchLineEdit/qsearchlineedit.h
	QTextBrowserDialog/qtextbrowserdialog.h)

set(SRCS
	QExtendedSplashScreen/qextendedsplashscreen.cpp
	QMultiSelectWidget/qmultiselectwidget.cpp
	QSearchLineEdit/qsearchlineedit.cpp
	QTextBrowserDialog/qtextbrowserdialog.cpp)


qt4_wrap_cpp(MOC_files ${HDRS})
qt4_add_resources(RCS_files QSearchLineEdit/qsearchlineedit.qrc)

add_library(pQjWidgets ${SRCS} ${RCS_files} ${MOC_files})
