#ifndef NETWORKMANAGERACCESSOR_H
#define NETWORKMANAGERACCESSOR_H

#include <QObject>
#include<QNetworkAccessManager>

class NetworkManagerAccessor : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManagerAccessor(QObject *parent = nullptr);

    inline static void init(QObject* parent){
        assert(parent != nullptr);
        networkAccessManager=new QNetworkAccessManager(parent);
    }

    QNetworkAccessManager* getInstance();
signals:

private :
    inline static QNetworkAccessManager* networkAccessManager;
};

#endif // NETWORKMANAGERACCESSOR_H
