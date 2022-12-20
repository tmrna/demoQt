#include "adminConnection.hpp"


adminConnection::adminConnection(){
    query = nullptr;

    conn.addDatabase(connSpecs.DriverType);
    conn.setHostName(connSpecs.Host);
    conn.setDatabaseName(connSpecs.Schema);

    if(!conn.open(connSpecs.User, connSpecs.Password)){
        throw sqlException("connection user credentials rejected");
    }

}


adminConnection::~adminConnection(){
    if(query != nullptr){
        delete query;
    }
    conn.close();
}
