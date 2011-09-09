#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

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


//protected:
  //  void paintEvent(QPaintEvent *);

private:
    Ui::plot *ui;


public slots:
 // слоты  переходов форм
    void prevv();
    void vvod();


};

#endif // PLOT_H
