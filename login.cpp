#include "login.h"
#include "./ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // set the shadow to sunken
    ui->frame->setFrameShadow(QFrame::Sunken);

    //ui->frame->setStyleSheet();

}



Login::~Login()
{
    delete ui;
}

