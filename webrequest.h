#ifndef WEBREQUEST_H
#define WEBREQUEST_H

#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include "networkmanageraccessor.h"

enum Response { Successful, WrongCredentials };

class WebRequest : public QObject
{
    Q_OBJECT
public:
    explicit WebRequest(QObject *parent = nullptr);

signals:
    void success(QByteArray response);
    void failure(QNetworkReply::NetworkError responseError);

public slots:
    virtual void post(QMap<QString, QVariant> header, QMap<QString, QVariant> body) = 0;
};

#endif // WEBREQUEST_H
