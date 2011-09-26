#include "about.h"
#include "ui_about.h"
#include <mainmenu.h>



about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(back()));

}

about::~about()
{
    delete ui;
}
void about::back()
{
    MainMenu *x = new MainMenu ();
x->show();
close();


}
