#ifndef ADMINCONNECTION_HPP
#define ADMINCONNECTION_HPP

#include "sqlConnection.hpp"
#include "../exceptions/sqlException.hpp"
#include "configuration.hpp"

class adminConnection: public sqlConnection{
private:
    adminDatabase database;
public:
    adminConnection();
    ~adminConnection();
};


#endif
