#ifndef SIGNINREQUEST_H
#define SIGNINREQUEST_H


#include <QObject>
#include <webrequest.h>

class SignInRequest : public WebRequest
{
    Q_OBJECT
public:
    explicit SignInRequest(QObject *parent = nullptr);

    void post(QMap<QString,QVariant> header, QMap<QString,QVariant> body)override;

signals:
};

#endif // SIGNINREQUEST_H
