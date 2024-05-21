QT += testlib core network widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../clientAppRadamant/serverconnector.h \
           ../clientAppRadamant/Person.h

SOURCES +=  tst_radamanttests.cpp \
            ../clientAppRadamant/serverconnector.cpp

