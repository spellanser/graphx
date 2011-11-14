#include <QtGui/QApplication>
#include "mainmenu.h"
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();

    return a.exec();
}
