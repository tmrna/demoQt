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


void Login::on_radioButton_clicked()
{
    // make new page
     signup* signupPage = new signup();
     // set the style to general
     signupPage->setStyleSheet(utils::getGeneralStyling());
     // hide login
     this->hide();
     // show signup
     signupPage->show();
     // kill login
     this->close();
}

