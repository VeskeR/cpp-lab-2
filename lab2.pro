TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Database.cpp \
    DatabaseTest.cpp \
    UserInterface.cpp \
    railroadticket.cpp

HEADERS += \
    Database.h \
    railroadticket.h
