#include "help.h"
#include "ui_help.h"

#include <mainmenu.h>


help::help(QWidget *parent) : QDialog(parent),
    ui(new Ui::help)

{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(back()));

}

help::~help()
{
    delete ui;
}

void help::back()
{
    MainMenu *x= new MainMenu();
    x->show();
    close();

}
