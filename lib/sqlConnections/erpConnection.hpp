#ifndef ERPCONNECTION_HPP
#define ERPCONNECTION_HPP

#include "sqlConnection.hpp"
#include "../exceptions/sqlException.hpp"
#include "configuration.hpp"

class erpConnection : public sqlConnection{
private:
    erpInfo connSpecs;
public:
    // ctor + dtor
    erpConnection();
    ~erpConnection();

};


#endif
