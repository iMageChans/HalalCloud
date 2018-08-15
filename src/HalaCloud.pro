#-------------------------------------------------
#
# Project created by QtCreator 2018-06-22T10:14:24
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HalaCloud
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        controller/main.cpp \
        controller/mainwindow.cpp \
    util/baseapi.cpp \
    util/util.cpp \
    util/multiparupload.cpp \
    model/model.cpp \
    view/loginwidget.cpp \
    view/registerwidget.cpp \
    model/multiparuploadmodel.cpp \
    view/filesitemwidget.cpp \
    view/mkdirwidget.cpp \
    view/mkdirhlep.cpp \
    view/mediaplayer.cpp \
    view/displywidget.cpp

HEADERS += \
        controller/mainwindow.h \
    util/baseapi.h \
    util/util.h \
    util/multiparupload.h \
    util/networkdata.h \
    util/abstract.h \
    model/model.h \
    view/loginwidget.h \
    view/registerwidget.h \
    model/multiparuploadmodel.h \
    view/filesitemwidget.h \
    view/mkdirwidget.h \
    view/mkdirhlep.h \
    model/struct.h \
    view/mediaplayer.h \
    view/displywidget.h \
    view/RenderWidget.h

FORMS += \
    view/loginwidget.ui \
    controller/mainwindow.ui \
    view/registerwidget.ui \
    view/filesitemwidget.ui \
    view/mkdirwidget.ui \
    view/mkdirhlep.ui \
    view/mediaplayer.ui

RESOURCES += \
    resource.qrc

macx {

QT += opengl
DEFINES += MEIDA_PLAYER_MACOSX
LIBS += -framework Foundation -framework Appkit -framework Cocoa

<<<<<<< HEAD
INCLUDEPATH += $$PWD/3rd/mac/libvlc/include
=======
OBJECTIVE_SOURCES += view/RenderWidget.mm

>>>>>>> dev
LIBS += -L$$PWD/3rd/mac/libvlc/lib/ -lvlc.5
INCLUDEPATH += $$PWD/3rd/mac/libvlc/include
}
