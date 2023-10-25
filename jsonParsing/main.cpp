#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "readinfo.h"

static QObject *UserInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ReadInfo *m_ReadInfo = ReadInfo::getInstance();
    return m_ReadInfo;
}

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ReadInfo *readInfo= new ReadInfo();
    qmlRegisterSingletonType<ReadInfo>("readInfo", 1, 0, "ReadInfo", UserInstance);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
