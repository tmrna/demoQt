#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP

#include <QString>


// will be used for user, and clients
class credentials {

protected:

  QString username;
  QString password;
  QString firstName;
  QString lastName;
  QString email;

public:
  virtual bool exists();
  virtual bool verifyPassword();

  void setUsername(const QString& newName){
    username = newName;
  }
  void setPassword(const QString& newPword){
    password = newPword;
  }
  void setFirstName(const QString& newFirst){
    firstName = newFirst;
  }
  void setLastName(const QString& newLast){
    lastName = newLast;
  }
  void setEmail(const QString& newEmail){
    email = newEmail;
  }
};

#endif
