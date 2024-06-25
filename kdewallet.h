#ifndef KDEWALLET_H
#define KDEWALLET_H

#include <QObject>
#include<QDebug>
#include <storage.h>
#include <kwallet.h>
#include <QGuiApplication>

class KDEWalletController : public Storage
{
    Q_OBJECT
public:
    explicit KDEWalletController(QObject *parent = nullptr);

signals:


// Storage interface
public slots:
    void write(const QString& key,const  QByteArray & value)override;
    int read(const QString& key,  QByteArray &  buffer)override;
private :
    KWallet::Wallet* wallet;
};

#endif // KDEWALLET_H
