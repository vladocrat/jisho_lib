#pragma once

#include <QString>
#include <tuple>

struct Translation {
    QString furigana;
    QString kanji;
    QString meaning;

    operator QString() const noexcept
    {
        return "Furigana: " + furigana + " Kanji: " + kanji + " Meaning: " + meaning;
    }

    constexpr auto asTuple() const
    {
        return std::tie(furigana, kanji, meaning);
    }
};

[[nodiscard]] inline bool operator==(const Translation& lhs, const Translation& rhs)
{
    return lhs.asTuple() == rhs.asTuple();
}

[[nodiscard]] inline bool operator!=(const Translation& lhs, const Translation& rhs)
{
    return lhs.asTuple() != rhs.asTuple();
}
