#include "jsonWriter.hpp"

#define jw jsonWriter
#define R_T QIODevice::ReadOnly | QIODevice::Text
// Default ctor
jsonWriter::jsonWriter()
{

}

// ctor given destination only
jsonWriter::jsonWriter(const QString& dest) {
    destination = dest;
}

// sets destination to given dest and text to bod
jw::jsonWriter(const QString& dest, const QString& bod){
    destination = dest;
    body = bod;
}

jw::jsonWriter(const jsonWriter& rhs){
    destination = rhs.destination;
    body = rhs.body;
}

// setter for destination file
void jw::setDestination(const QString& dest){
    destination = dest;
}

// setter for body
void jw::setBody(const QString& bod){
    body = bod;
}

// clears the given file (destination)
bool jw::clearDestination(){
        QFile file(destination);
        if(!file.open(R_T)) return false;
        // clears the file
        file.resize(0);
        file.close();
       return true;
}

// clear the given file then write the new body
bool jw::writeFile(){
    if (!clearDestination()){
        return false;
    }

    // get and open file
    QFile file(destination);
    if(!file.open(R_T)){
        return false;
    }

    // open a stream to the file
    QTextStream out(&file);

     // write to the body
    out << body;

    file.close();

    return true;
}

// clears body and replaces with body read from destination file.
bool jw::readNewBody(){

    QFile file(destination);

    // return flase if cannot read
    if(!file.open(R_T)){
        return false;
    }

    // stream to read file
    QTextStream in(&file);

    // clear body
    body = "";

    while(!in.atEnd()){
        body += in.readLine() + "\n";
    }

    file.close();
    return true;
}

#undef jw
