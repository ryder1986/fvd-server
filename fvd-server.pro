QT += core network
QT -= gui

TARGET = fvd-server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    broadcast_buffer.cpp \
    server.cpp

HEADERS += \
    broadcast_buffer.h \
    server.h

