#include"../androidsecurestorage.h"



AndroidSecureStorage::AndroidSecureStorage(QObject *parent)
    : SecureStorage{parent}
{}


QString AndroidSecureStorage::get(QString key){
    return "hello";
}



