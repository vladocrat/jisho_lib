#include "gtest/gtest.h"

#include <QCoreApplication>
#include <QTimer>

#include "translation.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    QCoreApplication a(argc, argv);

    JL::Translation::registerType();

    QTimer::singleShot(0, [&]()
    {
        auto res = RUN_ALL_TESTS();
        a.exit(res);
    });

    return a.exec();
}
