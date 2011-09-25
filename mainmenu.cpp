#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <form2.h>
#include <plot.h>
#include <history.h>
#include <help.h>
#include <about.h>

MainMenu::MainMenu(QWidget *parent) : QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //сигналы переходов форм

    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(next2()));

    connect (ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(hel()));

    connect (ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(abo()));

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
void MainMenu::abo()
{
    about *x = new about();
x->show();
close();

}


void MainMenu::hel()
{
    help *x = new help();
    x->show();
    close();

}
