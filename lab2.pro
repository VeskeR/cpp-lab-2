TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Database.cpp \
    DatabaseTest.cpp \
    Employee.cpp \
    EmployeeTest.cpp \
    UserInterface.cpp

HEADERS += \
    Database.h \
    Employee.h
