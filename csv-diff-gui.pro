######################################################################
# Automatically generated by qmake (3.1) Mon Dec 2 15:49:43 2019
######################################################################

TEMPLATE = app
TARGET = csv-diff-gui
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += dialog.h dialog2.h mainwindow.h results.h session.h u_widget.h
FORMS += dialog.ui dialog2.ui mainwindow.ui results.ui u_widget.ui
SOURCES += dialog.cpp \
           dialog2.cpp \
           main.cpp \
           mainwindow.cpp \
           results.cpp \
           session.cpp \
           u_widget.cpp
RESOURCES += qdarkstyle/style.qrc
