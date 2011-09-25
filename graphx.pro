#-------------------------------------------------
#
# Project created by QtCreator 2011-09-07T19:35:39
#
#-------------------------------------------------

QT       += core gui

TARGET = graphx
TEMPLATE = app
INCLUDEPATH += /home/sarkis/qwt-6.0.1/src
qtAddLibrary(qwt)

SOURCES += main.cpp\
        mainmenu.cpp \
    plot.cpp \
    help.cpp \
    functionhelp.cpp \
    about.cpp\
qwtchartzoom.cpp

HEADERS  += mainmenu.h \
    plot.h \
    help.h \
    functionhelp.h \
    about.h \
qwtchartzoom.h


FORMS    += mainmenu.ui \
    plot.ui \
    history.ui \
    help.ui \
    functionhelp.ui \
    about.ui

RESOURCES += \
    res.qrc
