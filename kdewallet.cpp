#include "kdewallet.h"

KDEWalletController::KDEWalletController(QObject *parent)
    : Storage{parent},wallet{KWallet::Wallet::openWallet(KWallet::Wallet::LocalWallet(), 0, KWallet::Wallet::OpenType::Synchronous)}
{
    qDebug()<<QCoreApplication::applicationName();
    if(wallet->createFolder(QCoreApplication::applicationName())){
        wallet->setFolder(QCoreApplication::applicationName());

    }
}
void KDEWalletController::write(const QString& key,const  QByteArray & value)
{



    wallet->writeEntry(key, value, KWallet::Wallet::Password);


}

int KDEWalletController::read(const QString& key,QByteArray &  buffer)
{

      return wallet->readEntry(key, buffer);
}
