#include "requestparser.h"

#include <QXmlStreamReader>
#include <QDebug>
#include <QString>
#include <QRegularExpressionMatchIterator>

namespace Internal
{

QVector<QString> getBlocks(const QString& htmlContent)
{
    QVector<QString> blocks;
    static QRegularExpression regex("<div\\s+class=\"concept_light\\s+clearfix\"[^>]*>(.*?)Details \xE2\x96\xB8</a></div>", QRegularExpression::DotMatchesEverythingOption);

    QRegularExpressionMatchIterator matchIterator = regex.globalMatch(htmlContent);

    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        QString matchedDiv = match.captured(0);
        blocks.append(matchedDiv);
    }

    return blocks;
}

[[nodiscard]] bool hasClass(QXmlStreamReader& xml, const QString& className)
{
    return xml.attributes().value("class").toString().contains(className);
}

QString prepareDoc(const QString& doc)
{
    auto temp = doc;
    temp.replace("\\\"", "\"");
    temp.remove("\n");

    return temp;
}

} //! Internal

namespace JL
{

QVector<Translation> RequestParser::parse(const QString& data) noexcept
{
    auto body = Internal::prepareDoc(data);
    auto blocks = Internal::getBlocks(body);

    QVector<Translation> ret;

    for (const auto& block : blocks)
    {
        QXmlStreamReader xml(block);

        QStringList furigana;
        QStringList kanji;
        QStringList meaning;

        bool isFurigana = false;
        bool isKanji = false;
        bool isMeaning = false;

        while (!xml.atEnd() && !xml.hasError())
        {
            auto token = xml.readNext();

            if (token == QXmlStreamReader::StartElement && xml.name().toString() == "span")
            {
                if (Internal::hasClass(xml, "kanji-2-up kanji"))
                {
                    isFurigana = true;
                }
                else if (Internal::hasClass(xml, "text") || xml.attributes().isEmpty())
                {
                    isKanji = true;
                }
                else if (Internal::hasClass(xml, "meaning-meaning"))
                    isMeaning = true;
            }
            else if (token == QXmlStreamReader::Characters)
            {
                if (isFurigana)
                {
                    auto text = xml.text().toString();
                    text.replace(" ", "");

                    if (!text.isEmpty())
                        furigana.append(text);

                    isFurigana = false;
                }

                if (isKanji)
                {
                    auto text = xml.text().toString();
                    text.replace(" ", "");

                    if (!text.isEmpty())
                        kanji.append(text);

                    isKanji = false;
                }

                if (isMeaning)
                {
                    meaning.append(xml.text().toString());
                    isMeaning = false;
                }
            }
        }

        ret.append({furigana.join(""), kanji.join(""), meaning.join("")});
    }

    return ret;
}

} //! JL
