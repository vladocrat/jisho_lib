#include <QCoreApplication>

#include <QDebug>

#include "apihandler.h"
#include "translation.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto handler = new ApiHandler;

    QObject::connect(handler, &ApiHandler::finished, [](const QVector<Translation>& translations){
        for (const auto& translation : translations)
        {
            qDebug() << translation;
        }
    });

    handler->translate("こんにちは");

    return a.exec();
}
