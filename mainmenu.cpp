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
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(next()));
    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(next2()));
    connect (ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(his()));
    connect (ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(hel()));

}

MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::next()
{
    Form2 *x= new Form2();
    x->show();
close();

}
void MainMenu::next2()
{
    plot *y = new plot();
    y->show();
    close();


}
void MainMenu::his()
{
    history *x = new history();
    x->show();
    close();

}

void MainMenu::hel()
{
    help *x = new help();
    x->show();
    close();

}
