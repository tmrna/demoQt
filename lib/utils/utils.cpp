#include "utils.hpp"

QString utils::getStyling(const char* path){

    // get the file
    QFile file(path);
    // check if file exists
    if(!file.exists()){
        qFatal(path);
        qFatal("Given qss file dne, exiting");
    }
    // attempt to open
    if(!file.open(QIODevice::ReadOnly)){
        qFatal("Failed to open file, exiting");
        exit(1);
    }

    QString style(file.readAll());

    file.close();

    return style;
}

QString utils::getLoginStyling(){
    return utils::getStyling("../demoQt/lib/styling/loginSignup.qss");
}
