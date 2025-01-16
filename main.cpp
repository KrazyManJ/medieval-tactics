#include "GameContext.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameContext gameContext;
    engine.rootContext()->setContextProperty("gameContext",&gameContext);
    const QUrl url(QStringLiteral("qrc:/assets.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);
    app.setWindowIcon(QIcon(":/assets/menu-background.png"));
    engine.loadFromModule("medieval-tactics", "Main");
    return app.exec();
}
