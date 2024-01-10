#include "apihandler.h"

#include "networkhandler.h"
#include "requestparser.h"

namespace Constants
{
constexpr static char const* address { "https://jisho.org/search/" };
} // Contants

struct ApiHandler::impl_t
{
    NetworkHandler handler;
    RequestParser parser;
};

ApiHandler::ApiHandler() noexcept
{
    createImpl();
}

ApiHandler::~ApiHandler() noexcept
{

}

void ApiHandler::translate(const QString& word) noexcept
{
    auto reply = impl().handler.request(QUrl(Constants::address + word));;

    QObject::connect(reply, &QNetworkReply::finished, this, [reply, this]() {
        reply->deleteLater();
        auto translations = impl().parser.parse(reply->readAll());
        emit finished(translations);
    });
}
