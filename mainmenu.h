#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

#include <plot.h>


namespace Ui {
    class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private:
    Ui::MainMenu *ui;



public slots:
 // слоты  переходов форм
void next();
void next2();


};

#endif // MAINMENU_H
