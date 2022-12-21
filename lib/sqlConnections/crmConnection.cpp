#include "crmConnection.hpp"


crmConnection::crmConnection(){

    query = nullptr;

}


crmConnection::~crmConnection(){
    if(query != nullptr){
        delete query;
    }

}


// prepare a statment
bool crmConnection::setQuery(const QString& queryString){
    if(query != nullptr){
        return query->prepare(queryString);
    }

    query = new QSqlQuery(database.conn);
    return query->prepare(queryString);
}
