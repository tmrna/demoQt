#include "sqlConnection.hpp"


bool sqlConnection::init(){
    return conn.transaction();
}
bool sqlConnection::commit(){
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

    query = new QSqlQuery(conn);
    return query->prepare(queryString);
}

void sqlConnection::bindPositionalParam(const QString& param){
    query->addBindValue(param);
}

bool sqlConnection::nextRes(){
    if(query == nullptr) return false;
    return query->next();
}
