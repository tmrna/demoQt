#include "crmConnection.hpp"


crmConnection::crmConnection(){


    query = nullptr;

    conn.addDatabase(connSpecs.DriverType);
    conn.setHostName(connSpecs.Host);
    conn.setUserName(connSpecs.User);
    conn.setPassword(connSpecs.Password);
    conn.setDatabaseName(connSpecs.Schema);

    if(!conn.open()){
        throw sqlException("connection user credentials rejected");
    }

}


crmConnection::~crmConnection(){
    if(query != nullptr){
        delete query;
    }
    conn.close();
}
