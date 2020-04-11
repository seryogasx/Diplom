######################################################################
# Automatically generated by qmake (3.1) Wed Apr 8 16:58:19 2020
######################################################################

TEMPLATE = app
TARGET = qmake
INCLUDEPATH += .
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += sort_test.hpp
SOURCES += main.cpp sort_test.cpp
QMAKE_CXXFLAGS += -std=c++14

_BOOST_PATH = /usr/local/Cellar/boost/1.72.0_1
INCLUDEPATH += "$${_BOOST_PATH}/include/"
LIBS += -L$${_BOOST_PATH}/lib