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
};
