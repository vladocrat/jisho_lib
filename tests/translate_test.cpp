#include <gtest/gtest.h>
#include <QDebug>
#include <QEventLoop>

#include "apihandler.h"
#include "networkhandler.h"

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

    QObject::connect(handler, &JL::ApiHandler::finished, [handler](const QVector<JL::Translation>& translations){
        handler->deleteLater();

        QVector<JL::Translation> actual{ {"こんにち", "今日は\u200B", "hello; good day; good afternoon今日は 【こんにちわ】"},
                                         {"", "こんにちはアン〜BeforeGreenGables\u200B", "Kon'nichiwa Anne: Before Green Gables"},
                                         {"", "こんにちは\u200B", "Aló Presidente"} };

        EXPECT_EQ(actual, translations);
    });


    handler->translate("こんにちは");

    QEventLoop loop; //! Without this loop connect won't work
    QObject::connect(handler, &JL::ApiHandler::finished, &loop, &QEventLoop::quit);
    loop.exec();
}
