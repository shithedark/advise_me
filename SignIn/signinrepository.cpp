#include "signinrepository.h"

SignInRepository::SignInRepository(QObject *parent)
    : Repository{parent}
{
    qDebug()<< "hello";
    connect(&webrequest , &WebRequest::success, this , &SignInRepository::processResponse);
    connect(&webrequest , &WebRequest::failure, this , &SignInRepository::handleError);

}


void SignInRepository::request(QMap<QString,QVariant> header, QMap<QString,QVariant> body){
            emit loading();
            webrequest.post(header, body);
}


void SignInRepository::processResponse(const QByteArray& response){
    QJsonDocument document = QJsonDocument::fromJson(response);
    QJsonObject rootObj = document.object();
    qDebug() <<rootObj["code"].toInt();


}

void SignInRepository::handleError(QNetworkReply::NetworkError error){
    switch(error){
    case (QNetworkReply::UnknownContentError): {
        emit invalidData() ;
        break;
    }
    default:{
        qDebug() << error;
        break;}


    }

}
