#ifndef SECURESTORAGE_H
#define SECURESTORAGE_H

#include <QObject>

class SecureStorage : public QObject
{
    Q_OBJECT
public:
    explicit SecureStorage(QObject *parent = nullptr);

signals:
public slots:
    virtual QString get(QString key) = 0;
};

#endif // SECURESTORAGE_H
