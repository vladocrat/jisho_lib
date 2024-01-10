#pragma once

#include "pimpl.h"
#include "translation.h"

class RequestParser final
{
public:
    RequestParser() noexcept = default;
    ~RequestParser() noexcept = default;

    [[nodiscard]] QVector<Translation> parse(const QString& data) noexcept;
};
