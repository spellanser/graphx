#include "history.h"
#include "ui_history.h"

#include <mainmenu.h>


history::history(QWidget *parent) : QDialog(parent),

    ui(new Ui::history)
{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(back()));

}


history::~history()
{
    delete ui;
}

void history::back()
{
    MainMenu *x = new MainMenu();
    x->show();
    close();

}
