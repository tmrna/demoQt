#ifndef USER_HPP
#define USER_HPP

#include "../../sqlConnections/crmConnection.hpp"
#include "../credentials/credentials.hpp"

#include <QMessageBox>

class employee: public credentials{
  private:
    int jobCode;
    bool adminStatus;
    crmConnection crm;

  public:
    employee();
    employee(const QString&);
    employee(const QString&, const QString&);
    employee(const employee&);
    ~employee();

    // login/signup credentials
    bool exists() override;
    bool verifyPassword() override;
    bool dbEmpty();
    QString passwordHash();

    // adding and removing
    bool dropMe();
    bool addMe(const QString& stateProvince,
              const QString& city,
              const int& streetNumber,
              const QString& streetName,
              const int& postalCode);
    bool setAdminStatus(const QString& rootName, const QString& rootPassword);
};

#endif
