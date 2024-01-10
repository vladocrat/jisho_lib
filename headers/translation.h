#pragma once

#include <QString>
#include <tuple>

namespace JL
{

struct Translation {
    QString furigana;
    QString kanji;
    QString meaning;

    operator QString() const noexcept
    {
        return "Furigana: " + furigana + " Kanji: " + kanji + " Meaning: " + meaning;
    }

    [[nodiscard]] constexpr auto asTuple() const noexcept
    {
        return std::tie(furigana, kanji, meaning);
    }
};

[[nodiscard]] constexpr inline bool operator==(const Translation& lhs, const Translation& rhs)
{
    return lhs.asTuple() == rhs.asTuple();
}

[[nodiscard]] constexpr inline bool operator!=(const Translation& lhs, const Translation& rhs)
{
    return lhs.asTuple() != rhs.asTuple();
}

} //! JL
