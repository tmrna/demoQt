#include "employee.hpp"

employee::employee(){
  username = "";
  password = "";
  firstName = "";
  lastName = "";
  jobCode = 0;
  adminStatus = false;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// only sets username
employee::employee(const QString& usr){
  *this = employee();
  username = usr;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// sets username and password
employee::employee(const QString& usr, const QString& pw){
  *this = employee();
    username = usr;
    password = pw;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// cpy ctor
employee::employee(const employee& rhs){
    username = rhs.username;
    password = rhs.password;
    firstName = rhs.firstName;
    lastName = rhs.lastName;
    jobCode = rhs.jobCode;
    adminStatus = rhs.adminStatus;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

employee::~employee(){
  // handled by stl and QString dtor
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// returns if the user currently exists in the database
bool employee::exists(){
  // set the query for the crm database
  crm.setQuery("select username from user where username = ?");
  // bind the param
  crm.bindPositionalParam(username);
  // if we fail to execute notify the user and return false
  if(!crm.executeQuery()){
    QMessageBox notification;
    notification.setText("Failed to execute query.");
    notification.exec();
    return false;
  }
  // check if there are any results, if there are return true (user found) else return false (user dne)
  if(crm.nextRes()){
    return true;
  }
  return false;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool employee::dbEmpty(){
    // set query to select
    crm.setQuery("select username from user");
    // if we can't execute the query for whatever reason let the user know and return false
    if(!crm.executeQuery()){
        QMessageBox notification;
        notification.setText("Failed to execute query.");
        notification.exec();
        return false;
    }
    // if we have a result then the db is not empty, return false
    if(crm.nextRes()){
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// hashes the password and returns a QString. Going this route to avoid accidental double hashing
QString employee::passwordHash(){
    // using Keccak_512, most recent hashing algorithm (Qt 5.9.2)
  QCryptographicHash hash(QCryptographicHash::Keccak_512);
  hash.addData(password.toUtf8());
  return QString(hash.result());
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool employee::verifyPassword(){
    if(!exists()){
        qDebug() << "User does not exist";
        return false;
    }
    crm.setQuery("select password from user where username = ?");
    crm.bindPositionalParam(username);
    if(!crm.executeQuery()){

        return false;
    }
    if(crm.nextRes()){
        return crm.fetchResult(0).toString() == passwordHash();
    }
    return false;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool employee::dropMe(){
    if(!exists()){
        QMessageBox notification;
        notification.setText("Failed to drop user as user DNE");
        notification.exec();
        return false;
    }

    return true;
}
