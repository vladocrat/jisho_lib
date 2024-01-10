#include <gtest/gtest.h>
#include <QDebug>

#include "apihandler.h"

TEST(TranslationEq, TranslationObj)
{
    Translation t1 {"あり", "がと", "おう"};
    Translation t2 {"あり", "がと", "おう"};
    Translation t3 {"あり", "がと", " "};

    EXPECT_EQ(t1, t2);
    ASSERT_NE(t1, t3);
}

TEST(JishoLib, GeneralTranslateTest)
{
    Translation t1 {};
    Translation t2 {};
    Translation t3 {};

    auto handler = new ApiHandler;

    QObject::connect(handler, &ApiHandler::finished, [](const QVector<Translation>& translations){
        for (const auto& translation : translations)
        {
            qDebug() << translation;
        }
    });

    handler->translate("こんにちは");
}
