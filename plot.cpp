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

    // Заголовок
        ui->qwtPlot->setTitle(QString::fromUtf8(" График введенной функции "));
    // Создаем сетку

        grid = new QwtPlotGrid;
        grid->enableXMin(true);
        grid->setMajPen(QPen(Qt::black,0,Qt::DotLine));
        grid->setMinPen(QPen(Qt::gray,0,Qt::DotLine));
        grid->attach(ui->qwtPlot);

    // устанавливаем границы осей
        ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString::fromUtf8("Ось Х"));
        ui->qwtPlot->setAxisScale(QwtPlot::xBottom,-0.25,8.25);
        ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString::fromUtf8("Ось Y"));
        ui->qwtPlot->setAxisScale(QwtPlot::yLeft,-1.25,1.25);

        // строим график

        curv1 = new QwtPlotCurve(QString("U1(t)"));
        curv1->setRenderHint(QwtPlotItem::RenderAntialiased);
        curv1->setPen(QPen(Qt::red));
    // обозначаем точки кривой


        symbol1 = new QwtSymbol();
        symbol1->setStyle(QwtSymbol::Ellipse);
        symbol1->setPen(QColor(Qt::black));
        symbol1->setSize(4);
        curv1->setSymbol(symbol1);



        //кол-во точек кривой
            const int N1 = 128;
                const int N2 = 262144;


            double *X1 = (double *)malloc((2*N1+2*N2)*sizeof(double));
            double *Y1 = X1 + N1;
            // вычисляем точки кривой
           // задаем шаг
            double h = 8./(N1-1);

            for (int k = 0; k < N1; k++)
            {
              X1[k] = k*h;
              Y1[k] = cos(M_PI*X1[k]-5*M_PI/12);
            }

    // передаем данные для построения

        curv1->setSamples(X1,Y1,N1);
    //высвобождаем память
        free((void *)X1);
    // помещаем кривые на виджет
    curv1->attach(ui->qwtPlot);

    //перестраиваем
    ui->qwtPlot->replot();

    // зуммирование

    zoom = new QwtPlotZoomer(ui->qwtPlot->canvas());
    zoom->setRubberBandPen(QPen(Qt::white));


}






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

