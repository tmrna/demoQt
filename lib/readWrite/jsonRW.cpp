#include "jsonRW.hpp"

#define IO_R QIODevice::ReadOnly

json::reader::reader(){

}

// sets file paths and Json members. Throws QString if file or path dne
json::reader::reader(const QString& path){
    // set path
    file.setFileName(path);
    // check if file exists
    if(!file.exists()) throw QString(path + " does not exist.");
    // attempt to open
    if(!file.open(IO_R)) throw QString("failed to open " + path);
    // read file
    contents = file.readAll();
    // convert contents into JsonDocument
    document = QJsonDocument::fromJson(contents);
}
