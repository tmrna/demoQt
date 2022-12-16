#include "forms/login/login.h"
#include "lib/utils/utils.hpp"

#include <QApplication>
#include <QDir>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try{
       // QString style = utils::getStyling("../demoQt/lib/styling/style.qss");
        QString style = utils::getGeneralStyling();
        Login w;
        w.setStyleSheet(style);
        w.show();
        return a.exec();
    }
    catch(QString err){
        qWarning() << err;
        QString path = QDir::currentPath();
        qWarning() << path;
        return -1;
    }


}
