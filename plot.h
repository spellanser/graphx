#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include <qwt-qt4/qwt_plot.h>

namespace Ui {
    class plot;
}

class plot : public QWidget
{
    Q_OBJECT

public:
    explicit plot(QWidget *parent = 0);
    ~plot();


private:
    Ui::plot *ui;

public slots:
void prevv();

};

#endif // PLOT_H
