#ifndef FUNCTIONHELP_H
#define FUNCTIONHELP_H

#include <QDialog>

namespace Ui {
    class functionhelp;
}

class functionhelp : public QDialog
{
    Q_OBJECT

public:
    explicit functionhelp(QWidget *parent = 0);
    ~functionhelp();

private:
    Ui::functionhelp *ui;
public slots:
void back();


};

#endif // FUNCTIONHELP_H
