#include "signup.hpp"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->emailLine->setPlaceholderText("Email");
    ui->fNameLine->setPlaceholderText("First Name");
    ui->lNameLine->setPlaceholderText("Last Name");

    ui->usernameLine->setPlaceholderText("Username");

    ui->passwordLine->setPlaceholderText("Password");
    ui->confirmPasswordLine->setPlaceholderText("Confirm Password");

    ui->passwordLine->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLine->setEchoMode((QLineEdit::Password));
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

