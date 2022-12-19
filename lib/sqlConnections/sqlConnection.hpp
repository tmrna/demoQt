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
    // virtual
    virtual void connect();
    virtual void setCursor();
    virtual void bindParam(const QString&);
    virtual void executeQuery();


    // To be inherited


    // begin /close transacitons
    bool beginTransaction();
    bool endTransaction();

    // tell if query is set or not
    bool querySetStatus();

    // prepare a statment
    bool setQuery(const QString& queryString);

    // bind in the format select * from user where username = ?
    void bindPositionalParam(const QString& param);

    // bind in the format select * from user where username = :username
    //                  query->bindValue(:username, "the username")
    template<typename T1,typename T2>
    void bindParam(const T1& target, const T2& param){
        query->bindValue(target, param);
    }

};

#endif
