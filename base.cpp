#include "base.h"

Base::Base(QObject *parent)
    : QObject{parent}
{
    connect(this, &Base::sessionExpired, this, &Base::fixSession);
    connect(this, &Base::sessionFixed, this, &Base::doThis);


}
