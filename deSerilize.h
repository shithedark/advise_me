#ifndef DESERILIZE_H
#define DESERILIZE_H
#include<QObject>
#include<QJsonDocument>
#include<QJsonObject>

template<typename T = QObject>
T* deSerilize(QJsonObject json, QObject*parent){
    T* object = new  T(parent);
    auto type = T::staticMetaObject;
    for(int i=0; i<type.propertyCount();i++){
        type.property(i).write(object, json.value(type.property(i).name()));
    }
    return object;
}

#endif // DESERILIZE_H
