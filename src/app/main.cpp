#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "logging/Logger.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    rxfg::Logger::Initialize();
    rxfg::Logger::Info("RXFG-RXSR startup");

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        [](){ QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("RXFG", "Main");

    return app.exec();
}
