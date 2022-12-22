#include "adminConnection.hpp"


adminConnection::adminConnection(){

    query = nullptr;

}


adminConnection::~adminConnection(){

    if(query != nullptr){
        delete query;
    }

}

// prepare a statment
bool adminConnection::setQuery(const QString& queryString){

    if(query != nullptr){
        return query->prepare(queryString);
    }

    query = new QSqlQuery(database.conn);
    return query->prepare(queryString);

}
