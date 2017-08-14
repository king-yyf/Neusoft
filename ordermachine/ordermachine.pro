#-------------------------------------------------
#
# Project created by QtCreator 2016-07-10T15:40:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += sql
QT       += network
QT       += testlib
TARGET = ordermachine
TEMPLATE = app


SOURCES += main.cpp\
        ordermachine.cpp \
    orderuifunc.cpp \
    dishes.cpp \
    orderdishpage.cpp \
    alterdeskpage.cpp \
    loginpage.cpp \
    canceldishpage.cpp \
    showdishespage.cpp \
    menupage.cpp \
    socket.cpp

HEADERS  += ordermachine.h \
    dishes.h

FORMS    += ordermachine.ui

RESOURCES += \
    images/image.qrc
