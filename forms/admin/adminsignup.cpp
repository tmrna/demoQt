#include "adminsignup.hpp"
#include "ui_adminsignup.h"

adminSignup::adminSignup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminSignup)
{
    ui->setupUi(this);
}

adminSignup::~adminSignup()
{
    delete ui;
}
