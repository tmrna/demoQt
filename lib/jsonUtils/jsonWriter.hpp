#ifndef JSONWRITER_HPP
#define JSONWRITER_HPP

#include <QString>
#include <QFile>
#include <QTextStream>

class jsonWriter
{
private:
    QString destination;
    QString body;

public:
    jsonWriter();

    jsonWriter(const QString&);
    jsonWriter(const QString& dest, const QString& bod);
    jsonWriter(const jsonWriter&);
    ~jsonWriter(){/* handled by QString*/}

    void setDestination(const QString&);
    void setBody(const QString&);

    bool clearDestination();
    bool writeFile();
    bool readNewBody();

    QString getBody();
};

#endif // JSONWRITER_HPP
