#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T13:44:21
#
#-------------------------------------------------

QT       += core gui
QT +=network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = workserver
TEMPLATE = app


SOURCES += main.cpp\
    socket.cpp \
    socketthread.cpp \
    server.cpp \
    servermainwindow.cpp

HEADERS  += \
    db.h \
    socket.h \
    socketthread.h \
    server.h \
    servermainwindow.h

FORMS    += \
    servermainwindow.ui
