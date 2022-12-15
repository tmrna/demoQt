#include "utils.hpp"

QString utils::getStyling(const char* path){

    // get the file
    QFile file(path);
    // check if file exists
    if(!file.exists()){
        throw QString("DNE");
    }
    // attempt to open
    if(!file.open(QIODevice::ReadOnly)){
        throw QString("FAILED TO OPEN");
    }

    QString style(file.readAll());

    file.close();

    return style;
}
