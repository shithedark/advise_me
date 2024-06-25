#ifndef BASE_H
#define BASE_H

#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(QObject *parent = nullptr);

signals:
    void sessionExpired();
    void sessionFixed(int a);
public slots:
    inline virtual void doThis(int a) = 0;
    inline void fixSession()
    {
        qDebug() << "Fixing session";
        //Working code
        qDebug() << "Session fixed";

        emit sessionFixed(1);
    }
};

#endif // BASE_H
