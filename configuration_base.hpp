#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <QSqlDatabase>

// comment out this line to have multiple hosts
#define SINGULAR_HOST true

// setup singular host here
#ifdef SINGULAR_HOST

    // Connection credentials here, specific schemas below
    #define MAIN_HOST "<your host>"
    #define MAIN_USER "<your user>"
    #define MAIN_PASSWORD "<your password"
    // hosts
    #define ERP_HOST MAIN_HOST
    #define CRM_HOST MAIN_HOST
    #define EMPLOYEE_HOST MAIN_HOST
    // users
    #define ERP_USER MAIN_USER
    #define CRM_USER MAIN_USER
    #define EMPLOYEE_USER MAIN_USER
    // passwords
    #define ERP_PASSWORD MAIN_PASSWORD
    #define CRM_PASSWORD MAIN_PASSWORD
    #define EMPLOYEE_PASSWORD MAIN_PASSWORD
    // driver (only mysql supported currently)
    #define DRIVER_TYPE "QMYSQL"


    // Enter specific schemas here
    #define ERP_SCHEMA "<your erp schema>"
    #define CRM_SCHEMA "<your crm schema>"
    #define EMPLOYEE_SCHEMA "<your employee schema>"

#endif

// setup multiple hosts here
#ifndef SINGULAR_HOST

    // multiple hosts
    #define ERP_HOST "<your erp host>"
    #define CRM_HOST "<your crm host>"
    #define EMPLOYEE_HOST "<your employee host>"
    // users
    #define ERP_USER "<your erp user>"
    #define CRM_USER "<your crm user>"
    #define EMPLOYEE_USER "<your employee user>"
    // passwords
    #define ERP_PASSWORD MAIN_PASSWORD
    #define CRM_PASSWORD MAIN_PASSWORD
    #define EMPLOYEE_PASSWORD MAIN_PASSWORD
    // driver (only mysql supported currently)
    #define DRIVER_TYPE "QMYSQL"
    // schemas
    #define ERP_SCHEMA "<your erp schema>"
    #define CRM_SCHEMA "<your crm schema>"
    #define EMPLOYEE_SCHEMA "<your employee schema>"

#endif



class erpDatabase{
  private:
    QSqlDatabase conn;

  public:

   erpDatabase(){
       conn.addDatabase(DRIVER_TYPE);
       conn.setHostName(ERP_HOST);
       if(!conn.open(ERP_USER, ERP_PASSWORD)){
           qFatal("Failed to form connnection, please reconfigure properly");
           exit(1);
       }
       conn.setDatabaseName(ERP_SCHEMA);
   }
   ~erpDatabase(){
     // handled by QSqlDatabase dtor
   }

  friend class erpConnection;
};

class crmDatabase{
  private:
    QSqlDatabase conn;

  public:

    crmDatabase(){
        conn.addDatabase(DRIVER_TYPE);
        conn.setHostName(CRM_HOST);
        if(!conn.open(CRM_USER, CRM_PASSWORD)){
            qFatal("Failed to form connnection, please reconfigure properly");
            exit(1);
        }
        conn.setDatabaseName(CRM_SCHEMA);
    }
    ~crmDatabase(){

    }

    friend class crmConnection;
};

class employeeDatabase{

  private:
    QSqlDatabase conn;
  public:
    employeeDatabase(){
        conn.addDatabase(DRIVER_TYPE);
        conn.setHostName(EMPLOYEE_HOST);
        if(!conn.open(EMPLOYEE_USER, EMPLOYEE_PASSWORD)){
            qFatal("Failed to form connnection, please reconfigure properly");
            exit(1);
        }
        conn.setDatabaseName(CRM_SCHEMA);
    }
    ~employeeDatabase(){

    }
  friend class employeeConnection;
};

#undef ERP_HOST
#undef CRM_HOST
#undef EMPLOYEE_HOST

#undef ERP_USER
#undef CRM_USER
#undef EMPLOYEE_USER

#undef ERP_PASSWORD
#undef CRM_PASSWORD
#undef EMPLOYEE_PASSWORD

#undef DRIVER_TYPE

#undef ERP_SCHEMA
#undef CRM_SCHEMA
#undef EMPLOYEE_SCHEMA

#ifdef SINGULAR_HOST
    #undef SINGULAR_HOST
    #undef MAIN_HOST
    #undef MAIN_USER
    #undef MAIN_PASSWORD
#endif

#endif
