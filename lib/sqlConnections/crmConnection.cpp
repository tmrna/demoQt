#include "crmConnection.hpp"


crmConnection::crmConnection(){

    query = nullptr;

}


crmConnection::~crmConnection(){
    if(query != nullptr){
        delete query;
    }

}
