#include "sqlConnection.hpp"

// tell if query is set or not
bool sqlConnection::querySetStatus(){
    return (query != nullptr);
}


void sqlConnection::bindPositionalParam(const QString& param){
    query->addBindValue(param);
}

bool sqlConnection::nextRes(){
    if(query == nullptr) return false;
    return query->next();
}
