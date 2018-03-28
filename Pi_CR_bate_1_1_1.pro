#-------------------------------------------------
#
# Project created by QtCreator 2018-02-20T15:01:56
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pi_CR_bate_1_1_1
TEMPLATE = app


SOURCES += main.cpp\
        CentralProcessModule.cpp \
    login.cpp \
    mainui.cpp \
    mylistwidgetitem.cpp \
    mylistwidget.cpp \
    chat.cpp

HEADERS  += CentralProcessModule.h \
    login.h \
    mainui.h \
    mylistwidgetitem.h \
    mylistwidget.h \
    chat.h

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    icon.qrc

