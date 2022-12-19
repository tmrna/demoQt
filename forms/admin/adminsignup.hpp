#ifndef ADMINSIGNUP_HPP
#define ADMINSIGNUP_HPP

#include <QMainWindow>

namespace Ui {
class adminSignup;
}

class adminSignup : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminSignup(QWidget *parent = nullptr);
    ~adminSignup();

private:
    Ui::adminSignup *ui;
};

#endif // ADMINSIGNUP_HPP
