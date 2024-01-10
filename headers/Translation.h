#pragma once

#include <QString>

struct Translation {
    QString furigana;
    QString kanji;
    QString meaning;

    operator QString() const noexcept
    {
        return "Furigana: " + furigana + " Kanji: " + kanji + " Meaning: " + meaning;
    }

    [[nodiscard]] bool operator==(const Translation& rhs)
    {
        return this->furigana == rhs.furigana
               && this->kanji == rhs.kanji
               && this->meaning == rhs.meaning;
    }
};
