#ifndef SIGNINREPOSITORY_H
#define SIGNINREPOSITORY_H

#include <QObject>
#include <QNetworkReply>
#include <QQmlEngine>
#include<repository.h>
#include<signinrequest.h>
class SignInRepository : public Repository
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit SignInRepository(QObject *parent = nullptr);

signals:
    void wrongCreds();
public slots :
    void request(QMap<QString,QVariant> header, QMap<QString,QVariant> body);
    void processResponse(const QByteArray& response);
    void handleError(QNetworkReply::NetworkError error);

private :
    SignInRequest webrequest;



};

#endif // SIGNINREPOSITORY_H
