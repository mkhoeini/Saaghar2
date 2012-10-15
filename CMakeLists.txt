cmake_minimum_required(VERSION 2.8.7)
project(saaghar)

find_package(Qt4 REQUIRED QtCore QtGui QtSql QtXml QtNetwork)
include(${QT_USE_FILE})

add_subdirectory(pQjWidgets)
#add_subdirectory(translations)

add_subdirectory(src)
