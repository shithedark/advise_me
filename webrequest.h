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


class WebRequest : public QObject
{
    Q_OBJECT
public:
    explicit WebRequest(QObject *parent = nullptr);

signals:
    void success(QByteArray response);


public slots :
    void post(QMap<QString,QVariant> header, QMap<QString,QVariant> body);

};

#endif // WEBREQUEST_H
