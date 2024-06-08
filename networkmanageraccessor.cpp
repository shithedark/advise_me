#include "networkmanageraccessor.h"

NetworkManagerAccessor::NetworkManagerAccessor(QObject *parent)
    : QObject{parent}
{}


QNetworkAccessManager* NetworkManagerAccessor::getInstance(){
    assert(networkAccessManager != nullptr);
    return networkAccessManager;
}
