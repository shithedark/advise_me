#ifndef NETWORKMANAGERACCESSOR_H
#define NETWORKMANAGERACCESSOR_H

#include <QNetworkAccessManager>
#include <QObject>

class NetworkManagerAccessor : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManagerAccessor(QObject *parent = nullptr);

    inline static void init(QObject *parent)
    {
        assert(parent != nullptr);
        networkAccessManager = new QNetworkAccessManager(parent);
    }

    static QNetworkAccessManager *getInstance();
signals:

private:
    inline static QNetworkAccessManager *networkAccessManager;
};

#endif // NETWORKMANAGERACCESSOR_H
