#pragma once

#include "translation.h"

namespace JL
{

class RequestParser final
{
public:
    RequestParser() noexcept = default;
    ~RequestParser() noexcept = default;

    [[nodiscard]] QVector<Translation> parse(const QString& data) noexcept;
};

} //! JL
