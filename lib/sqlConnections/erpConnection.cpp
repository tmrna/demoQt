#include "erpConnection.hpp"

erpConnection::erpConnection(){
    query = nullptr;

}


erpConnection::~erpConnection(){
    if(query != nullptr){
        delete query;
    }

}



// prepare a statment
bool erpConnection::setQuery(const QString& queryString){
    if(query != nullptr){
        return query->prepare(queryString);
    }

    query = new QSqlQuery(database.conn);
    return query->prepare(queryString);
}
