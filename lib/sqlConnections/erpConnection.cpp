#include "erpConnection.hpp"

erpConnection::erpConnection(){
    query = nullptr;

    conn = QSqlDatabase::addDatabase(connSpecs.DriverType);
    conn.setHostName(connSpecs.Host);
    conn.setDatabaseName(connSpecs.Schema);

    if(!conn.open(connSpecs.User, connSpecs.Password)){
        throw sqlException("connection user credentials rejected");
    }

}


erpConnection::~erpConnection(){
    if(query != nullptr){
        delete query;
    }
    conn.close();
}

