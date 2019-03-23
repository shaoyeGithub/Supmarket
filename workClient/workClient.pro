#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T13:43:19
#
#-------------------------------------------------

QT       += core gui
QT +=network
QT +=sql
//CONFIG +=console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = workClient
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    socket.cpp \
    login.cpp \
    stock_widget.cpp \
    add_stock.cpp

HEADERS  += \
    mainwindow.h \
    socket.h \
    login.h \
    stock_widget.h \
    add_stock.h

FORMS    += \
    mainwindow.ui \
    login.ui \
    stock_widget.ui \
    add_stock.ui

RESOURCES += \
    1.qrc
