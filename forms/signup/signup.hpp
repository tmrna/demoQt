#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QMainWindow>

#include "../login/login.h"
#include "../../lib/utils/utils.hpp"

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_passwordChkBox_stateChanged(int arg1);

    void on_radioButton_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_HPP
