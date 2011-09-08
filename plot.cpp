#include "plot.h"
#include "ui_plot.h"
#include <mainmenu.h>

plot::plot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plot)
{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(prevv()));
}

plot::~plot()
{
    delete ui;
}
void plot::prevv()
{

MainMenu *x = new MainMenu;
x->show();
close();

}
