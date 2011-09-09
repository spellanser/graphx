#include "plot.h"
#include "ui_plot.h"

#include <mainmenu.h>
#include <form2.h>


#include <QPainter>




plot::plot(QWidget *parent) : QWidget(parent),

    ui(new Ui::plot)
{
    ui->setupUi(this);

    //сигналы переходов форм
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(prevv()));
    connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(vvod()));



}
/*
void QPainter::translate ( const QPointF & offset );

void plot::paintEvent(QPaintEvent *)
{
    QPainter p(this); // Создаём новый объект рисовальщика



    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования

    p.drawLine(0,0,width(),height()); // Рисование линии

}
*/



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
void plot::vvod()
{

Form2 *x = new Form2;
x->show();
close();

}

