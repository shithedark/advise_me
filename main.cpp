#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QJniObject>
#include <androidsecurestorage.h>
#include<securestoragefactory.h>

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

    SecureStorage* s = SecureStorageFactory::getSecureStorage(&engine);
    qDebug() << s->get("key");



    engine.load(url);

    return app.exec();
}
