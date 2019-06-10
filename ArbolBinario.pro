TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    node.cpp \
    btree.cpp

HEADERS += \
    node.h \
    error.h \
    btree.h
