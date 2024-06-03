#ifndef ANDROIDSECURESTORAGE_H
#define ANDROIDSECURESTORAGE_H

#include <QObject>
#include <securestorage.h>
#include<QJniObject>
#include <QGuiApplication>


class AndroidSecureStorage : public SecureStorage
{
    Q_OBJECT
public:
    explicit AndroidSecureStorage(QObject *parent = nullptr);

signals:

public slots :
    QString get(QString key);
private :
    QJniObject activity;
    QJniObject secureStorage;

};

#endif // ANDROIDSECURESTORAGE_H
