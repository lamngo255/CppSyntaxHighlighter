#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "documenthandler.h"
#include "highlighter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DocumentHandler document;

    qmlRegisterType<Highlighter>("org.sample", 1, 0, "Highlighter");
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("documentHandler", &document);
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
