#ifndef PROFILE_H
#define PROFILE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QQmlEngine>
class Profile : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString fiestName READ firstName WRITE setFirstName NOTIFY firstNameChanged FINAL)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged FINAL)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged FINAL)

public:
    explicit Profile(QObject *parent = nullptr);
    static Profile *fromJson(QJsonObject json, QObject *parent);
public slots:
    const QString &firstName();
    const QString &lastName();
    const QString &email();
    void setFirstName(const QString &value);
    void setLastName(const QString &value);
    void setEmail(const QString &value);

signals:
    void firstNameChanged(const QString &value);
    void lastNameChanged(const QString &value);
    void emailChanged(const QString &value);

private:
    QString _firstName;
    QString _lastName;
    QString _email;
};

#endif // PROFILE_H
