#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>


namespace Ui {
    class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();


private:
    Ui::history *ui;

public slots:
    void back();


};

#endif // HISTORY_H
