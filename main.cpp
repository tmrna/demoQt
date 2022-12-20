#include "forms/login/login.h"
#include "lib/utils/utils.hpp"

#include <QApplication>
#include <QDir>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

        Login w;
        w.setStyleSheet(utils::getGeneralStyling());
        w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        w.show();
        return a.exec();


}
