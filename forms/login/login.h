#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "lib/utils/utils.hpp"
#include "forms/signup/signup.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

    ~Login();

private slots:
    void on_radioButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
