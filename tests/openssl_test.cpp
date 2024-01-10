#include <gtest/gtest.h>
#include <QSslSocket>

TEST(enabled, OpenSSL)
{
    EXPECT_EQ(true, QSslSocket::supportsSsl());
}
