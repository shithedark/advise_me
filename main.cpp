#include <QDataStream>
#include <QGuiApplication>
#include <QJsonArray>
#include <QJsonObject>
#include <QQmlApplicationEngine>
#include <QSettings>
#include "androidsecurestorage.h"
#include <kdewallet.h>
#include <networkmanageraccessor.h>
#include <profile.h>

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



    return app.exec();
}
