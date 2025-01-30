#include "GameContext.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    GameContext gameContext;
    engine.rootContext()->setContextProperty("gameContext",&gameContext);
    const QUrl url(QStringLiteral("qrc:/assets.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );

    app.setWindowIcon(QIcon(":/assets/menu-background.png"));

    qint32 fontId = QFontDatabase::addApplicationFont(":/assets/fonts/Macondo-Regular.ttf");
    QStringList fontList = QFontDatabase::applicationFontFamilies(fontId);

    QString family = fontList.first();
    QGuiApplication::setFont(QFont(family));

    engine.loadFromModule("medieval-tactics", "Main");
    return app.exec();
}
