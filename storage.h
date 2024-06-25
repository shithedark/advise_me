#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = nullptr);

signals:

public slots:
    virtual void write(const QString &key, const QByteArray &value) = 0;
    //write into buffer,
    //0 if failed and 1 if successfull
    virtual int read(const QString &key, QByteArray &buffer) = 0;
};

#endif // STORAGE_H
