#include "signinrequest.h"

SignInRequest::SignInRequest(QObject *parent)
    : WebRequest{parent}
{}

void SignInRequest::post(QMap<QString,QVariant> header, QMap<QString,QVariant> body){
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
        //request was sent and we have a reply
        //could be successful login or failure due to wrong credentials
        if(reply->error() == QNetworkReply::NoError){
            emit success(reply->readAll());
        }

    } );
    connect(reply, &QNetworkReply::errorOccurred, this , [=]{
        QNetworkReply::NetworkError networkError = reply->error();
        emit failure(networkError);
        reply->deleteLater();
    } );


}
