#pragma once

#include <QNetworkReply>

#include "pimpl.h"
#include "singleton.h"

class NetworkHandler final : public Singleton<NetworkHandler>
{
public:
    NetworkHandler() noexcept;
    ~NetworkHandler() noexcept;

    [[nodiscard]] QNetworkReply* request(const QUrl& url) noexcept;

    [[nodiscard]] QSslConfiguration sslConfiguration() const noexcept;
    [[nodiscard]] const QNetworkAccessManager* qnam() const noexcept;

private:
    DECLARE_PIMPL
};


