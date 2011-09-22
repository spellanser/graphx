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
    form2.cpp \
    plot.cpp \
    history.cpp \
    help.cpp \
    functionhelp.cpp

HEADERS  += mainmenu.h \
    form2.h \
    plot.h \
    history.h \
    help.h \
    functionhelp.h

FORMS    += mainmenu.ui \
    form2.ui \
    plot.ui \
    history.ui \
    help.ui \
    functionhelp.ui

RESOURCES += \
    res.qrc
