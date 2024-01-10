#include <gtest/gtest.h>
#include <QDebug>

#include "apihandler.h"

TEST(TranslationEq, TranslationObj)
{
    JL::Translation t1 {"あり", "がと", "おう"};
    JL::Translation t2 {"あり", "がと", "おう"};
    JL::Translation t3 {"あり", "がと", " "};

    EXPECT_EQ(t1, t2);
    ASSERT_NE(t1, t3);
}

TEST(JishoLib, GeneralTranslateTest)
{
    JL::Translation t1 {};
    JL::Translation t2 {};
    JL::Translation t3 {};

    auto handler = new JL::ApiHandler;

    QObject::connect(handler, &JL::ApiHandler::finished, [](const QVector<JL::Translation>& translations){
        for (const auto& translation : translations)
        {
            qDebug() << translation;
        }
    });

    handler->translate("こんにちは");
}
