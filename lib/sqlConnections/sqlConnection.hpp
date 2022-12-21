#ifndef SQLCONNECTION_HPP
#define SQLCONNECTION_HPP

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>


class sqlConnection{
protected:

    QSqlQuery*  query;

public:

    // To be inherited

    bool executeQuery(){return query->exec();}

    // tell if query is set or not
    bool querySetStatus();



    // bind in the format select * from user where username = ?
    void bindPositionalParam(const QString& param);

    bool nextRes();

    QVariant fetchResult(int i){
        return query->value(i);


    }


    int querySize(){
         return query->size();
     }



};

#endif
