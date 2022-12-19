#ifndef SQLEXCEPTION_HPP
#define SQLEXCEPTION_HPP

#include <QException>

class sqlException : public QException{
private:
     QString msg;
public:
     sqlException(const char* txt){
         msg = txt;
     }
    void raise() const override {
        throw  *this;
    }
    void raise(const char* txt){
        msg  = txt;
        throw *this;
    }
    sqlException *clone() const override {return new sqlException(*this);}
    QString getMsg() const {return msg;}

};

#endif
