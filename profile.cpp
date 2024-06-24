#include "profile.h"
#include "deSerilize.h"
Profile::Profile(QObject *parent)
    : QObject{parent}
{}

Profile* Profile::fromJson(QJsonObject json, QObject*parent)
{

    Profile* profile  = deSerilize<Profile>(json, parent);
    return profile;
}

void Profile::setFirstName(const QString& value)
{
    _firstName = value;
    emit firstNameChanged(value);
}

void Profile::setLastName(const QString &value)
{
    _lastName = value;
    emit lastNameChanged(value);
}

void Profile::setEmail(const QString &value)
{
    _email = value;
    emit emailChanged(value);

}


const QString &Profile::firstName()
{
    return _firstName;
}

const QString &Profile::lastName()
{
    return _lastName;

}

const QString &Profile::email()
{
    return _email;

}
