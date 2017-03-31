#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T19:53:48
#
#-------------------------------------------------

QT       += core gui




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = test9




INCLUDEPATH += "E:/VS2015/boost_1_61_0"
LIBS += -L"E:\VS2015\boost_1_61_0\lib\vc2015_x64\lib"

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogem.cpp \
    dialognb.cpp \
    nb.cpp \
    stopword.cpp \
    qcustomplot.cpp \
    dialoghmm.cpp \
    HMM.cpp \
    dialogcrf.cpp \
    crf.cpp

HEADERS  += mainwindow.h \
    dialogem.h \
    dialognb.h \
    common.h \
    nb.h \
    stopword.h \
    qcustomplot.h \
    dialoghmm.h \
    HMM.h \
    dialogcrf.h \
    crf.h

FORMS    += mainwindow.ui \
    dialogem.ui \
    dialognb.ui \
    dialoghmm.ui \
    dialogcrf.ui
	

RESOURCES +=

