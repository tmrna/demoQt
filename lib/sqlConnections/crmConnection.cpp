#include "crmConnection.hpp"


crmConnection::crmConnection(){
    query = nullptr;
    conn.setHostName(connSpecs.Host);
    conn.setDatabaseName(connSpecs.Schema);

    if(!conn.open(connSpecs.User, connSpecs.Password)){
        throw sqlException("connection user credentials rejected");
    }

}


crmConnection::~crmConnection(){
    if(query != nullptr){
        delete query;
    }
    conn.close();
}
