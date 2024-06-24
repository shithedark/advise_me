#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>
#include <QQmlEngine>

class Repository : public QObject
{
    Q_OBJECT
public:
    explicit Repository(QObject *parent = nullptr);
signals :
    void loading();
    void invalidData();
};

#endif // REPOSITORY_H
