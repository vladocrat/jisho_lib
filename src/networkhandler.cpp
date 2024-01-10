#include "networkhandler.h"

struct NetworkHandler::impl_t
{
    QNetworkAccessManager qnam;
    QSslConfiguration configuration;
};

NetworkHandler::NetworkHandler() noexcept
{
    createImpl();

    QObject::connect(&impl().qnam, &QNetworkAccessManager::sslErrors, [](QNetworkReply* rep, const QList<QSslError>& errs) {
        for (const auto& e: errs)
        {
            qDebug() << "QSslError: " << e;
        }
    });

    impl().configuration = QSslConfiguration::defaultConfiguration();
    impl().configuration.setProtocol(QSsl::TlsV1_2);
}

NetworkHandler::~NetworkHandler() noexcept
{

}

QNetworkReply* NetworkHandler::request(const QUrl& url) noexcept
{
    QNetworkRequest request(url);
    request.setSslConfiguration(impl().configuration);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");

    return impl().qnam.get(request);
}

QSslConfiguration NetworkHandler::sslConfiguration() const noexcept
{
    return impl().configuration;
}

const QNetworkAccessManager* NetworkHandler::qnam() const noexcept
{
    return &impl().qnam;
}
