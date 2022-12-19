#include "sqlConnection.hpp"


bool sqlConnection::beginTransaction(){
    return conn.transaction();
}
bool sqlConnection::endTransaction(){
    return conn.commit();
}

// tell if query is set or not
bool sqlConnection::querySetStatus(){
    return (query != nullptr);
}
// prepare a statment
bool sqlConnection::setQuery(const QString& queryString){
    if(query != nullptr){
        return query->prepare(queryString);
    }

    query = new QSqlQuery();
    return query->prepare(queryString);
}

void sqlConnection::bindPositionalParam(const QString& param){
    if(!querySetStatus()){
        throw queryException("Query is not set!");
    }
    query->addBindValue(param);
}
