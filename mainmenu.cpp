#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <form2.h>
#include <plot.h>
#include <history.h>
#include <help.h>


MainMenu::MainMenu(QWidget *parent) : QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //сигналы переходов форм

    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(next2()));

    connect (ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(hel()));

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::next2()
{
    plot *y = new plot();
    y->show();
    close();


}


void MainMenu::hel()
{
    help *x = new help();
    x->show();
    close();

}
