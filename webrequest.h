#ifndef WEBREQUEST_H
#define WEBREQUEST_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "networkmanageraccessor.h"
#include <QMap>
#include <QHttpMultiPart>
#include<QJsonObject>
#include <QJsonDocument>

enum Response {
    Successful,WrongCredentials
};


class WebRequest : public QObject
{
    Q_OBJECT
public:
    explicit WebRequest(QObject *parent = nullptr);

signals:
    void success(QByteArray response);
    void failure(QNetworkReply::NetworkError responseError);



public slots :
    virtual void post(QMap<QString,QVariant> header, QMap<QString,QVariant> body)=0;

};

#endif // WEBREQUEST_H
