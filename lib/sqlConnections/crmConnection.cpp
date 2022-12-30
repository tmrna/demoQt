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
    // clears prior query and positional params
    if(query != nullptr){
        delete query;
    }

    query = new QSqlQuery(database.conn);
    return query->prepare(queryString);
}
