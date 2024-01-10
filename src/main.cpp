#include <QCoreApplication>

#include <QDebug>

#include "apihandler.h"
#include "translation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto handler = new JL::ApiHandler;

    QObject::connect(handler, &JL::ApiHandler::finished, [](const QVector<JL::Translation>& translations){
        for (const auto& translation : translations)
        {
            qDebug() << translation;
        }
    });

    handler->translate("こんにちは");

    return a.exec();
}
