#ifndef SIGNINREPOSITORY_H
#define SIGNINREPOSITORY_H

#include <QObject>
#include <QNetworkReply>
#include <webrequest.h>

class SignInRepository : public QObject
{
    Q_OBJECT
public:
    explicit SignInRepository(QObject *parent = nullptr);

signals:
    void loading();
public slots :
    void request(QMap<QString,QVariant> header, QMap<QString,QVariant> body);
    void processResponse(QByteArray response);

private :
    WebRequest webrequest;



};

#endif // SIGNINREPOSITORY_H
