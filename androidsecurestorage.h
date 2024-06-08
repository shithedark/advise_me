#ifndef ANDROIDSECURESTORAGE_H
#define ANDROIDSECURESTORAGE_H

#include "securestorage.h"

#include <QGuiApplication>


class AndroidSecureStorage : public SecureStorage
{
    Q_OBJECT
public:
    explicit AndroidSecureStorage(QObject *parent = nullptr);

signals:


public slots :
    QString get(QString key);

};


#endif // ANDROIDSECURESTORAGE_H
