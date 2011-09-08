#include "form2.h"
#include "ui_form2.h"
#include <mainmenu.h>
#include <plot.h>
Form2::Form2(QWidget *parent) : QDialog(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);

    //сигналы переходов форм
    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(prev()));
    connect (ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(plott()));
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
void Form2::plott()
{
    plot *y = new plot();
    y->show();
    close();


}
