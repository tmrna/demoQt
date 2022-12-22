#include "sqlConnection.hpp"

// tell if query is set or not
bool sqlConnection::querySetStatus(){
    return (query != nullptr);
}

bool sqlConnection::nextRes(){
    if(query == nullptr) return false;
    return query->next();
}
