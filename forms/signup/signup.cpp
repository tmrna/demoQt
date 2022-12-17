#include "signup.hpp"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

    // fix window size
    setFixedSize(geometry().width(), geometry().height());

    // placeholder text
    ui->emailLine->setPlaceholderText("Email");
    ui->fNameLine->setPlaceholderText("First Name");
    ui->lNameLine->setPlaceholderText("Last Name");
    ui->usernameLine->setPlaceholderText("Username");
    ui->passwordLine->setPlaceholderText("Password");
    ui->confirmPasswordLine->setPlaceholderText("Confirm Password");

    // hide passwords by default
    ui->passwordLine->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLine->setEchoMode((QLineEdit::Password));

    // set heavy shadow to frame
    ui->frame->setGraphicsEffect(heavyShadow());

    // set skinny shadow for text fields
    ui->emailLine->setGraphicsEffect(skinnyShadow());
    ui->fNameLine->setGraphicsEffect(skinnyShadow());
    ui->lNameLine->setGraphicsEffect(skinnyShadow());
    ui->usernameLine->setGraphicsEffect(skinnyShadow());
    ui->passwordLine->setGraphicsEffect(skinnyShadow());
    ui->confirmPasswordLine->setGraphicsEffect(skinnyShadow());

    // set buttons to mild shadow
    ui->radioButton->setGraphicsEffect(mildShadow());
    ui->pushButton->setGraphicsEffect(mildShadow());
}

signup::~signup()
{
    delete ui;
}

void signup::on_passwordChkBox_stateChanged(int arg1)
{
    // check current state. If not checked set echomode to password, if checked then
    // echo mode is normal
    ui->passwordLine->setEchoMode( ui->passwordChkBox->checkState() ==
                Qt::Checked ? QLineEdit::Normal : QLineEdit::Password);

    // set confirm line to the same echo mode as password line.
    ui->confirmPasswordLine->setEchoMode(ui->passwordLine->echoMode());
}


void signup::on_radioButton_clicked()
{
    Login* loginPage = new Login();
    loginPage->setStyleSheet(utils::getGeneralStyling());
    this->hide();
    loginPage->show();
    this->close();
}

