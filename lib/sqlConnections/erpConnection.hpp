#ifndef ERPCONNECTION_HPP
#define ERPCONNECTION_HPP

#include "sqlConnection.hpp"
#include "../exceptions/sqlException.hpp"
#include "configuration.hpp"

class erpConnection : public sqlConnection{
private:
    erpDatabase database;
public:
    bool init();
    bool commit();
    bool setQuery(const QString& queryString);
    // ctor + dtor
    erpConnection();
    ~erpConnection();

};


#endif
