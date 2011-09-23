#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_zoomer.h>


namespace Ui {
    class plot;
}
//Создаем виджет позволяющий на себе рисовать при помощи Qpainter
//class QPaintEvent;

class plot : public QWidget
{
    Q_OBJECT


public:
    explicit plot(QWidget *parent = 0);
    ~plot();

protected:
  QwtLegend *leg;
  QwtPlotGrid *grid;
  QwtPlotCurve *curv1,*curv2;
    QwtSymbol *symbol1;
    QwtPlotZoomer *zoom;


private:
    Ui::plot *ui;


public slots:
 // слоты  переходов форм
    void prevv();
    void vvod();
    void plot1();



};

#endif // PLOT_H











