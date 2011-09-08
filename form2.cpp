#include "form2.h"
#include "ui_form2.h"
#include <mainmenu.h>

Form2::Form2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(prev()));
}

Form2::~Form2()
{
    delete ui;
}

void Form2::prev()
{
  MainMenu *y = new MainMenu;
y->show();
close();


}
