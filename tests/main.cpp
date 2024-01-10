#include "gtest/gtest.h"

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    QCoreApplication a(argc, argv);

    QTimer::singleShot(0, [&]()
    {

        auto res = RUN_ALL_TESTS();
        a.exit(res);
    });

    return a.exec();
}
