#include "functionhelp.h"
#include "ui_functionhelp.h"

#include <form2.h>

functionhelp::functionhelp(QWidget *parent) :  QDialog(parent),


    ui(new Ui::functionhelp)
{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(back()));
}

functionhelp::~functionhelp()
{
    delete ui;
}

void functionhelp::back()
{
    Form2 *x = new Form2();
    x->show();
    close();
}
