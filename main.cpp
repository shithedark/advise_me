#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <networkmanageraccessor.h>
#include "androidsecurestorage.h"
#include<QSettings>
#include<QJsonObject>
#include<QJsonArray>
#include<profile.h>
 #include <QDataStream>
#include<kdewallet.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/base/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    NetworkManagerAccessor::init(&engine);

    QCoreApplication::setOrganizationName("Advise Me");
    QCoreApplication::setOrganizationDomain("advise_me.com");
    QCoreApplication::setApplicationName("Advise Me");
    QSettings settings;
    settings.setValue("key", "mee");
    AndroidSecureStorage android = AndroidSecureStorage();

    engine.load(url);

    KDEWalletController kDEWalletController;
    kDEWalletController.write("asd" , QString("sdfsd").toUtf8());
    QByteArray buffer;
    kDEWalletController.read("asd", buffer);
    qDebug() <<buffer;

    return app.exec();
}
