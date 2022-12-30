#include "login.h"
#include "./ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // fix window size
    setFixedSize(geometry().width(), geometry().height());

    // set the shadow to sunken
    ui->frame->setFrameShadow(QFrame::Sunken);
    // set a shadow for the frame
    ui->frame->setGraphicsEffect(heavyShadow());

    // placeholder text for fields
    ui->usrLine->setPlaceholderText("Username");
    ui->pwLine->setPlaceholderText("Password");

    // hide password by default
    ui->pwLine->setEchoMode(QLineEdit::Password);

    // set skinny shadows for the text fields
    ui->usrLine->setGraphicsEffect(skinnyShadow());
    ui->pwLine->setGraphicsEffect(skinnyShadow());

    // set mild shadow for buttons
    ui->pushButton->setGraphicsEffect(mildShadow());
    ui->radioButton->setGraphicsEffect(mildShadow());



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
     signupPage->setStyleSheet(utils::getLoginStyling());
     // hide login
     this->hide();
     // show signup
     signupPage->show();
     // kill login
     //this->show();
}


void Login::on_checkBox_stateChanged(int arg1)
{
    ui->pwLine->setEchoMode(ui->checkBox->checkState() == Qt::Checked ?
                                QLineEdit::Normal : QLineEdit::Password);
}

