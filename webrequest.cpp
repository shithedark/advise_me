#include "webrequest.h"

WebRequest::WebRequest(QObject *parent)
    : QObject{parent}
{}


void WebRequest::post(QMap<QString,QVariant> header, QMap<QString,QVariant> body){
    QNetworkRequest request;

    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Accept", "application/json");
    request.setUrl(QUrl("http://127.0.0.1:8000/api/login"));

    QJsonObject obj;
    obj["email"] = body["email"].toString();
    obj["password"] = body["password"].toString();
    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    QNetworkReply* reply = NetworkManagerAccessor::getInstance()->post(request, data );

    connect(reply, &QNetworkReply::finished, this , [=]{
        QNetworkReply::NetworkError networkError = reply->error();
        if(networkError == QNetworkReply::InternalServerError){
            reply->deleteLater();
            this->post(header, body);
        }else if(reply->error() == QNetworkReply::NoError){
            qDebug()<< reply->readAll();
            emit success(reply->readAll());
            reply->deleteLater();
        }else{
            qDebug()<< reply->errorString();

        }
    } );
    connect(reply, &QNetworkReply::errorOccurred, this , [=]{
        emit success(reply->readAll());
        reply->deleteLater();
    } );


}
