#include "androidsecurestorage.h"

AndroidSecureStorage::AndroidSecureStorage(QObject *parent)
    : SecureStorage{parent}, secureStorage{QJniObject("org/qtproject/example/SecureStorage")}, activity{QJniObject(QNativeInterface::QAndroidApplication::context())}
{}


QString AndroidSecureStorage::get(QString key){
   secureStorage.callMethod<jint>("init", "(Landroid/content/Context;)I",activity.object());
    secureStorage.callMethod<void>("put","(Ljava/lang/String;Ljava/lang/String;)V", QJniObject::fromString("key").object<jstring>(), QJniObject::fromString("value").object<jstring>());
    return secureStorage.callMethod<jstring>("get","(Ljava/lang/String;)Ljava/lang/String;", QJniObject::fromString("key").object<jstring>()).toString();
}
