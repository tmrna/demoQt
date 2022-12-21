#include "erpConnection.hpp"

erpConnection::erpConnection(){
    query = nullptr;

}


erpConnection::~erpConnection(){
    if(query != nullptr){
        delete query;
    }

}

