#pragma once

#include <QString>
#include <tuple>
#include <QMetaType>

namespace JL{struct Translation;}; //! Forwarding for metatype macro

Q_DECLARE_METATYPE(JL::Translation);

namespace JL
{

struct Translation {
    QString furigana;
    QString kanji;
    QString meaning;

    Translation() = default;
    ~Translation() = default;

    operator QString() const noexcept
    {
        return "Furigana: " + furigana + " Kanji: " + kanji + " Meaning: " + meaning;
    }

    [[nodiscard]] constexpr auto asTuple() const noexcept
    {
        return std::tie(furigana, kanji, meaning);
    }

    static void registerType()
    {
        qRegisterMetaType<Translation>("Translation");
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

