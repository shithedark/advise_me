#ifndef DERIVED_H
#define DERIVED_H

#include <QObject>
#include "base.h"

class Derived : public Base
{
    Q_OBJECT
public:
    explicit Derived(QObject *parent = nullptr);

signals:
public slots:
    inline void doThis(int a) override
    {
        qDebug() << "Entered the job";

        if (a == 0) {
            emit sessionExpired();
        } else {
            qDebug() << "I am doing my usual job";
        }
    }
};

#endif // DERIVED_H
