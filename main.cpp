#include <QCoreApplication>

#include "networkhandler.h"
#include "requestparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NetworkHandler handler;
    auto reply = handler.request(QUrl("https://jisho.org/search/こんにちは"));

    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        RequestParser parser;
        auto translations = parser.parse(reply->readAll());
        qDebug() << translations;
    });

    return a.exec();
}
