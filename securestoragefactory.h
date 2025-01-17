#ifndef SECURESTORAGEFACTORY_H
#define SECURESTORAGEFACTORY_H

#include <QObject>
#include <androidsecurestorage.h>
#include <securestorage.h>

class SecureStorageFactory
{
public:
    explicit SecureStorageFactory();

    inline static SecureStorage *getSecureStorage(QObject *parent = 0)
    {
#ifdef Q_OS_ANDROID
        return new AndroidSecureStorage(parent);
#endif
    }
};

#endif // SECURESTORAGEFACTORY_H
