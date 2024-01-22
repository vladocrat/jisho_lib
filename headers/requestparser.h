#pragma once

#include <QObject>

#include "translation.h"

namespace JL
{

class RequestParser final : public QObject
{
    Q_OBJECT
public:
    RequestParser() noexcept = default;
    ~RequestParser() noexcept = default;

    [[nodiscard]] QVector<Translation> parse(const QString& data) noexcept;

signals:
    void finishedProcessing(const Translation&);

private:
    void processBlock(const QByteArray& block);
};

} //! JL
