#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "androidsecurestorage.h"
#include "SignIn/Logic/signinrepository.h"
#include<QSettings>
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
    qmlRegisterType<SignInRepository>("SignInRepository", 1, 0, "SignInRepository");

    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");
    QCoreApplication::setApplicationName("Star Runner");
        QSettings settings;
    settings.setValue("key", "mee");
    AndroidSecureStorage android = AndroidSecureStorage();



    engine.load(url);

    return app.exec();
}
