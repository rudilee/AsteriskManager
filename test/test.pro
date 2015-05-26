#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T08:07:37
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_loginactiontest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    loginactiontest.cpp \
    logoffactiontest.cpp \
    packettransportmock.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    loginactiontest.h \
    logoffactiontest.h \
    packettransportmock.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lasteriskmanager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lasteriskmanager
else:unix: LIBS += -L$$OUT_PWD/../src/ -lasteriskmanager

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/libasteriskmanager.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/libasteriskmanager.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/asteriskmanager.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/asteriskmanager.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/libasteriskmanager.a
