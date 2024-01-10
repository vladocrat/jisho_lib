#pragma once

#include <QString>

struct Translation {
    QString furigana;
    QString kanji;
    QString meaning;

    operator QString() const noexcept
    {
        return furigana + " " + kanji + " " + meaning;
    }
};
