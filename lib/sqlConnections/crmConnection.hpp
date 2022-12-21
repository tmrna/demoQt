#ifndef CRMCONNECTION_HPP
#define CRMCONNECTION_HPP

#include "sqlConnection.hpp"
#include "../exceptions/sqlException.hpp"
#include "configuration.hpp"

class crmConnection: public sqlConnection{
private:
    crmDatabase database;
public:
    bool init() ;
    bool commit();
    bool setQuery(const QString& queryString);
    crmConnection();
    ~crmConnection();
};



#endif
