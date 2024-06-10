#include "signinrepository.h"

SignInRepository::SignInRepository(QObject *parent)
    : QObject{parent}
{}


void SignInRepository::request(QMap<QString,QVariant> header, QMap<QString,QVariant> body){
            webrequest.post(header, body);

}
