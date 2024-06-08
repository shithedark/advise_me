#ifndef SIGNINREPOSITORY_H
#define SIGNINREPOSITORY_H

#include <QObject>

class SignInRepository : public QObject
{
    Q_OBJECT
public:
    explicit SignInRepository(QObject *parent = nullptr);

signals:
};

#endif // SIGNINREPOSITORY_H
