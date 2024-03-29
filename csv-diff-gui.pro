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
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
    dialog.cpp \
    dialog2.cpp \
    main.cpp \
    mainwindow.cpp \
    results.cpp \
    session.cpp \
    u_widget.cpp

HEADERS += \
    dialog.h \
    dialog2.h \
    mainwindow.h \
    results.h \
    session.h \
    u_widget.h

FORMS += \
    dialog.ui \
    dialog2.ui \
    mainwindow.ui \
    results.ui \
    u_widget.ui

RESOURCES += qdarkstyle/style.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


SUBDIRS += \
    Qt-Frameless-Window-DarkStyle/frameless_window_dark.pro

DISTFILES +=
