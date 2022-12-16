#include "login.h"
#include "./ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // set the shadow to sunken
    ui->frame->setFrameShadow(QFrame::Sunken);

    ui->usrLine->setPlaceholderText("Username");
    ui->pwLine->setPlaceholderText("Password");

    ui->pwLine->setEchoMode(QLineEdit::Password);

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


void Login::on_checkBox_stateChanged(int arg1)
{
    ui->pwLine->setEchoMode(ui->checkBox->checkState() == Qt::Checked ?
                                QLineEdit::Normal : QLineEdit::Password);
}

