#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <QMessageBox>
#include <QString>

class basicNotification{
protected:
    QMessageBox notification;
public:
    basicNotification(){/* handled by QMessageBox ctor */}
    basicNotification(const QString& msg){ notification.setText(msg); }
    ~basicNotification(){/* handled by QMessasgeBox dtor */}
    void setMsg(const QString& msg){ notification.setText(msg);}
    void exec(){notification.exec();}
};

#endif
