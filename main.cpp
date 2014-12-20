#include <QtQml>
#include <QApplication>
#include <QQmlApplicationEngine>

#include <register.h>
#include <registermodel.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<RegisterModel>();

    RegisterModel *registerModel = new RegisterModel();
    registerModel->addRegister(new Register("reg0", 0xFF));
    registerModel->addRegister(new Register("reg1", 0xFF));

    engine.rootContext()->setContextProperty("registerModel", registerModel);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
