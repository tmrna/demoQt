#ifndef JSONREADER_HPP
#define JSONREADER_HPP

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QByteArray>

namespace json{

    // interface for reader/writer
    class readWrite{
    protected:
        QFile file;
        QJsonDocument document;
        QJsonArray array;
        QJsonObject object;
        QByteArray contents;
    public:
        virtual void setFilePath(const QString&);
        virtual void bindDocument();
        virtual void bindDocument(const QString&);

    };


    // class to read json files
    class reader: public readWrite {

    public:
        reader();
        reader(const QString&);
        reader(const reader&);
        ~reader();

        void setFilePath(const QString&);
        void bindDocument();
        void bindDocument(const QString&);
    };

     // class to write json files
    class writer: public readWrite {
    public:

        writer();
        writer(const QString&);
        writer(const writer&);
        ~writer();

    };

}

#endif
