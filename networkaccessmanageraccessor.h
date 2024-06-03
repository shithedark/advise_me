#ifndef NETWORKACCESSMANAGERACCESSOR_H
#define NETWORKACCESSMANAGERACCESSOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QSharedPointer>

class NetworkAccessManagerAccessor : public QObject
{
    Q_OBJECT
public:
    explicit NetworkAccessManagerAccessor(QObject *parent = nullptr);
    static QNetworkAccessManager* getNetworkAccessManager();
    static void initNetworkAccessManager(QObject* parent);

signals:


private :
    static QNetworkAccessManager* networkAccessManager;
};

#endif // NETWORKACCESSMANAGERACCESSOR_H
