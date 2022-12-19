#ifndef SQLCONNECTION_HPP
#define SQLCONNECTION_HPP

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>


class sqlConnection{
protected:
    // connection info
    QString driver;
    QString host;
    QString user;
    QString password;
    QString schema;

    // database connection
    QSqlDatabase conn;
    QSqlQuery*  query;

public:

    // To be inherited
    bool executeQuery(){return query->exec();}

    // begin /close transacitons
    bool init();
    bool commit();

    // tell if query is set or not
    bool querySetStatus();

    // prepare a statment
    bool setQuery(const QString& queryString);

    // bind in the format select * from user where username = ?
    void bindPositionalParam(const QString& param);

    bool nextRes();


    // returns the i'th element of the result
    template<typename T>
    T fetchResult(int i){
        return query->value(i);
    }

};

#endif
