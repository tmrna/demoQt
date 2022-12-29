#ifndef USER_HPP
#define USER_HPP

#include "../sqlConnections/crmConnection.hpp"
#include <vector>

#include "../credentials/credentials.hpp"
class user: public credentials{
  private:
    int jobCode;
    bool adminStatus;

  public:
    user();
    user(const QString&);
    user(const QString&, const QString&);
    user(const user&);
    ~user();

    // login/signup credentials
    bool exists() override;
    bool verifyPassword() override;
    void passwordHash();

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
