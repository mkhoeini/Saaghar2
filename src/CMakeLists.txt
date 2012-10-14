
include_directories(${CMAKE_BINARY_DIR})
include_directories(
	${CMAKE_SOURCE_DIR}/pQjWidgets/QExtendedSplashScreen
	${CMAKE_SOURCE_DIR}/pQjWidgets/QMultiSelectWidget
	${CMAKE_SOURCE_DIR}/pQjWidgets/QSearchLineEdit
	${CMAKE_SOURCE_DIR}/pQjWidgets/QTextBrowserDialog
)
link_directories(${CMAKE_BINARY_DIR}/pQjWidgets)

set(saaghar_HDRS
	mainwindow.h
	SearchItemDelegate.h
	SaagharWidget.h
	QGanjoorDbBrowser.h
	settings.h
	SearchResultWidget.h
	SearchPatternManager.h
        bookmarks.h)
# These files have been excluded due to the point that they don't have Q_OBJECT macro:
        #commands.h)
        #QGanjoorDbStuff.h
        #version.h

set(saaghar_SRCS
	main.cpp
	mainwindow.cpp
	SearchItemDelegate.cpp
	SaagharWidget.cpp
	QGanjoorDbBrowser.cpp
	settings.cpp
	SearchResultWidget.cpp
	SearchPatternManager.cpp
	bookmarks.cpp
	commands.cpp)

set(saaghar_FORMS
	mainwindow.ui
	settings.ui)

set(saaghar_RCCS
	saaghar.qrc)

set(saaghar_TRANS
	saaghar_fa.ts)


qt4_wrap_cpp(saaghar_HDRS_files ${saaghar_HDRS})
qt4_wrap_ui(saaghar_FORMS_files ${saaghar_FORMS})
qt4_add_resources(saaghar_RCCS_files ${saaghar_RCCS})
qt4_add_translation(saaghar_TRANS_files ${saaghar_TRANS})


add_executable(saaghar
        ${saaghar_SRCS}
        ${saaghar_HDRS_files}
	${saaghar_FORMS_files}
	${saaghar_RCCS_files}
	${saaghar_TRANS_files})
target_link_libraries(saaghar ${QT_LIBRARIES} pQjWidgets)


