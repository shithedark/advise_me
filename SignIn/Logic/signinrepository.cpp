#include "signinrepository.h"

SignInRepository::SignInRepository(QObject *parent)
    : QObject{parent}
{
    connect(&webrequest , &WebRequest::success, this , &SignInRepository::processResponse);
}


void SignInRepository::request(QMap<QString,QVariant> header, QMap<QString,QVariant> body){
            emit loading();
            webrequest.post(header, body);
}


void SignInRepository::processResponse(QByteArray response){
    qDebug()<< "Hello from SignInRepo";
}
