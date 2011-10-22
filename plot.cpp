#include "plot.h"
#include "ui_plot.h"

#include <mainmenu.h>
#include <functionhelp.h>
#include <QtGui>
#include "text_analiz.cpp"
#include "postfix_result_and_stroka_postfix.cpp"


#include "qwtchartzoom.h"

// ==================== Конструктор =============================

plot::plot(QWidget *parent) : QWidget(parent),
    ui(new Ui::plot)
{
    ui->setupUi(this);


    //заголовок
    ui->qwtPlot->setTitle(QString::fromUtf8(" График введенной функции "));


    // Создаем сетку

    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->qwtPlot);


    QString str;

    int str1,str2;
    int str11, str22;

    str = ui->lineEdit->text();
    str1 = ui->lineEdit_3->text().toInt();
    str2 = ui->lineEdit_2->text().toInt();
    str11 = ui->lineEdit_3->text().toDouble();
    str22 = ui->lineEdit_2->text().toDouble();

    char* value = new char[100];
    QByteArray ar = str.toAscii();
    char *sometext = ar.data();
    value = sometext;
    char *input1,*output1;
    input1 = output1 = new char[100];
    input1 = value;
    input1 = proobraz(input1);
    input1 = len(input1,value);
    output1=vixod(input1);

   /*
    // легенда
    leg = new QwtLegend();
        // запрещаем ее редактировать
        leg->setItemMode(QwtLegend::ReadOnlyItem);
        //  добавляем легенду в верхнюю часть графика
        ui->qwtPlot->insertLegend(leg,QwtPlot::TopLegend);
*/

    // устанавливаем границы осей
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString::fromUtf8("Ось Х"));
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,(str1),(str2));
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString::fromUtf8("Ось Y"));
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,(str1),(str2));


    // Задаем кривые графиков

    curv1 = new QwtPlotCurve(QString(str));
    curv1->setRenderHint(QwtPlotItem::RenderAntialiased);
    curv1->setPen(QPen(Qt::red));

    // обозначаем точки кривой

    symbol1 = new QwtSymbol();
    //symbol1->setStyle(QwtSymbol::Ellipse);
    symbol1->setPen(QColor(Qt::black));
    symbol1->setSize(4);
    curv1->setSymbol(symbol1);


    // обработка ошибок


    if (output1 == "Error" )
        {

            QMessageBox msgBox(QMessageBox::Information,
                ("Error!"),
                ("Check the correctness of the function! (See the instructions for writing) "),
                QMessageBox::Ok);
 msgBox.exec();
//  ui->lineEdit->clear();
  ui->lineEdit->selectAll();
 ui->lineEdit->setFocus();



}
    bool key2 = false;
    if (str[0]=='-' || str[0]=='+' || str[0]== '/' || str[0] == '*')
    {
        key2 = true;
        QMessageBox msgBox(QMessageBox::Information,
            ("Error!"),
            ("Read instruction!"),
            QMessageBox::Ok);
    msgBox.exec();
  //  ui->lineEdit->clear();
    ui->lineEdit->selectAll();
    ui->lineEdit->setFocus();



    }


if (key2!=true)
{


    //кол-во точек кривой
        const int N1 = 25600000;
            const int N2 = 262144;


            double *X1 = (double *)malloc((2*N1+2*N2)*sizeof(double));
                double *Y1 = X1 + N1;
        // вычисляем точки кривой
       // задаем шаг
        int i = 0;


        double k = str11;

        for ( k ; k <= str22; k = k + 0.001)
        {
            double rez,rez11;
            rez11 = k ;
            rez = polka(vixod(input1),rez11,0);
            QString rez1;
            rez1.setNum(rez);
            if (rez1 != "nan" )
                if (rez1 != "inf")
                     if (rez1 != "-inf")
            {
                X1[i] = k;
                Y1[i] = polka(vixod(input1),X1[i],0);
                i++;
            }

        }






    // передаем данные для построения



    curv1->setSamples(X1,Y1,i-1);
    //высвобождаем память
    free((void *)X1);
}
    // помещаем кривые на виджет


    if (str!="")
    {
        curv1->attach(ui->qwtPlot);
}

    //перестраиваем
    ui->qwtPlot->replot();

    // зуммирование

   // zoom = new QwtPlotZoomer(ui->qwtPlot->canvas());
    zoom = new QwtChartZoom(ui->qwtPlot);
    //zoom->setRubberBandPen(QPen(Qt::blue));
    zoom->setRubberBandColor(Qt::blue);

    ui->qwtPlot->replot();

        //сигналы переходов форм
        connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(plot1()));
        connect (ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(erase()));
        connect (ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(plot1()));
        connect (ui->lineEdit_2,SIGNAL(editingFinished()),this,SLOT(plot1()));
        connect (ui->lineEdit_3,SIGNAL(editingFinished()),this,SLOT(plot1()));
        connect (ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(main()));
        connect (ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(instruct()) );
        connect (ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(eraseall()));

}




// ===================== Функция построения =========================




void plot::plot1()

{
    // Заголовок
    ui->qwtPlot->setTitle(QString::fromUtf8(" График введенной функции "));
    // задаем  график


    QString str;

    int str1,str2;
    int str11, str22;

    str = ui->lineEdit->text();

    str1 = ui->lineEdit_3->text().toInt();
    str2 = ui->lineEdit_2->text().toInt();

    str11 = ui->lineEdit_3->text().toDouble();
    str22 = ui->lineEdit_2->text().toDouble();

    curv1 = new QwtPlotCurve(QString(str));
    curv1->setRenderHint(QwtPlotItem::RenderAntialiased);
    curv1->setPen(QPen(Qt::red));
    // обозначаем точки кривой


    symbol1 = new QwtSymbol();
    //symbol1->setStyle(QwtSymbol::Ellipse);
    symbol1->setPen(QColor(Qt::black));
    symbol1->setSize(4);
    curv1->setSymbol(symbol1);






    // Создаем сетку


    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->qwtPlot);

    // устанавливаем границы осей
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString::fromUtf8("Ось Х"));
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,(str1),(str2));
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString::fromUtf8("Ось Y"));
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,(str1),(str2));

 //ui->qwtPlot->replot();

// передача введенной функции в польскую запись для разбора
    char* value = new char[100];
    QByteArray ar = str.toAscii();
    char *sometext = ar.data();
    value = sometext;
    char *input1,*output1;
    input1 = output1 = new char[100];
    input1 = value;
    input1 = proobraz(input1);
    input1 = len(input1,value);
    output1=vixod(input1);
/*
    // легенда

    leg = new QwtLegend();
        // запрещаем ее редактировать
        leg->setItemMode(QwtLegend::ReadOnlyItem);
        //  добавляем легенду в верхнюю часть графика
        ui->qwtPlot->insertLegend(leg,QwtPlot::TopLegend);
*/
    // обработка ошибок
bool key1 = false;


    if (output1 == "Error" )
        {
                key1 = true;
                QMessageBox msgBox(QMessageBox::Information,
                ("Error!"),
                ("Check the correctness of the function! (See the instructions for writing) "),
                QMessageBox::Ok);
 msgBox.exec();
// ui->lineEdit->clear();
ui->lineEdit->selectAll();
 ui->lineEdit->setFocus();


}
    bool key2 = false;
    if (str[0]=='-' || str[0]=='+' || str[0]== '/' || str[0] == '*')
    {
        key2 = true;
        QMessageBox msgBox(QMessageBox::Information,
            ("Error!"),
            ("Read instruction!"),
            QMessageBox::Ok);
    msgBox.exec();
 //   ui->lineEdit->clear();
    ui->lineEdit->selectAll();
    ui->lineEdit->setFocus();



    }


if (key2!=true)
{


    //кол-во точек кривой
        const int N1 = 25600000;
            const int N2 = 262144;


            double *X1 = (double *)malloc((2*N1+2*N2)*sizeof(double));
                double *Y1 = X1 + N1;
        // вычисляем точки кривой
       // задаем шаг
        int i = 0;
        double k = str11;

        for ( k ; k <= str22; k = k + 0.001)
        {
          double rez,rez11;
          rez11 = k ;
          rez = polka(vixod(input1),rez11,0);
          QString rez1;
          rez1.setNum(rez);
          if (rez1 != "nan" )
              if (rez1 != "inf")
                   if (rez1 != "-inf")
          {
              X1[i] = k;
              Y1[i] = polka(vixod(input1),X1[i],0);
              i++;
          }





}



    // передаем данные для построения



    curv1->setSamples(X1,Y1,i-1);
    //высвобождаем память
    free((void *)X1);
}
    // помещаем кривые на виджет

    if (str!="" )
    {
        if (key1==false)
        curv1->attach(ui->qwtPlot);
}
 else
{
    QMessageBox msgBox(QMessageBox::Information,
        ("Function is not implemented"),
        ("LineEdit is empty, enter funtion  "),
        QMessageBox::Ok);
msgBox.exec();
ui->lineEdit->setFocus();


}
    //перестраиваем
    ui->qwtPlot->replot();

    // зуммирование

   // zoom = new QwtPlotZoomer(ui->qwtPlot->canvas());
   zoom = new QwtChartZoom(ui->qwtPlot);
  //  zoom->setRubberBandPen(QPen(Qt::blue));
   zoom->setRubberBandColor(Qt::blue);

   ui->qwtPlot->replot();

}

// ========= Деструктор ===========

plot::~plot()
{
    delete ui;
    delete leg;
    delete grid;
    delete curv1;
    delete curv2;
    delete symbol1;
    delete zoom;
}
// Обработка сигналов нажатий клавиш

void plot::main()
{

MainMenu *x = new MainMenu;
x->show();
close();

}

void plot::erase()
{
    curv1->hide();

    ui->qwtPlot->replot();

}

void plot::eraseall()
{
    plot *x1 = new plot;
    x1->show();
    close();

}

void plot::instruct()
{
    functionhelp *x = new functionhelp;
    x->show();
   //hide();

}

