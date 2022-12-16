#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QMainWindow>

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

private:
    Ui::signup *ui;
};

#endif // SIGNUP_HPP
