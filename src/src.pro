#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T08:04:59
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = asteriskmanager
TEMPLATE = lib
CONFIG += staticlib c++11

SOURCES += asteriskmanager.cpp \
    packet.cpp \
    action.cpp \
    loginaction.cpp \
    logoffaction.cpp

HEADERS += asteriskmanager.h \
    packettransport.h \
    packet.h \
    action.h \
    loginaction.h \
    logoffaction.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
