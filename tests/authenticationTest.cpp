#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "authentication.h"
#include "mockUserManager.h"
#include "mockUser.h"
#include "userInfo.h"

using ::testing::_;
using ::testing::Return;

class AuthenticationTest : public ::testing::Test
{
protected:
    MockUserManager mockUserManager;
    Authentication *auth;

    void SetUp() override
    {
        auth = new Authentication(&mockUserManager);
    }

    void TearDown() override
    {
        delete auth;
    }
};

TEST_F(AuthenticationTest, LoginSuccess)
{
    MockUser *mockUser = new MockUser({11500, "Sumit", Role::ACCOUNT_HOLDER});

    EXPECT_CALL(*mockUser, getUserId()).WillRepeatedly(Return(11500));

    EXPECT_CALL(*mockUser, getName()).WillRepeatedly(Return("Sumit"));

    EXPECT_CALL(*mockUser, getRole()).WillRepeatedly(Return(Role::ACCOUNT_HOLDER));

    EXPECT_CALL(mockUserManager, verifyCredentials("admin", "admin@123")).WillOnce(Return(true));

    EXPECT_CALL(mockUserManager, getUserByUsername("admin")).WillOnce(Return(mockUser));

    IUser *user = auth->login("admin", "admin@123");
    EXPECT_EQ(user, mockUser);

    delete mockUser;
}

TEST_F(AuthenticationTest, LoginFailWrongPassword)
{
    EXPECT_CALL(mockUserManager, verifyCredentials("ansh@123", "5674321")).WillOnce(Return(false));

    EXPECT_CALL(mockUserManager, getUserByUsername("ansh@123")).Times(0);

    IUser *user = auth->login("ansh@123", "5674321");

    EXPECT_EQ(user, nullptr);
}

TEST_F(AuthenticationTest, LogoutWhenLoggedIn)
{
    MockUser *mockUser = new MockUser({11500, "Sumit", Role::ACCOUNT_HOLDER});

    EXPECT_CALL(*mockUser, getUserId()).WillRepeatedly(Return(11500));

    EXPECT_CALL(*mockUser, getName()).WillRepeatedly(Return("Sumit"));

    EXPECT_CALL(*mockUser, getRole()).WillRepeatedly(Return(Role::ACCOUNT_HOLDER));

    EXPECT_CALL(mockUserManager, verifyCredentials(_, _)).WillOnce(Return(true));

    EXPECT_CALL(mockUserManager, getUserByUsername(_)).WillOnce(Return(mockUser));

    auth->login("sumit@123", "5674321");

    EXPECT_TRUE(auth->logout());

    delete mockUser;
}

TEST_F(AuthenticationTest, LogoutWhenNoUser)
{
    EXPECT_FALSE(auth->logout());
}

TEST_F(AuthenticationTest, GetCurrentUser)
{
    MockUser *mockUser = new MockUser({11500, "Sumit", Role::ACCOUNT_HOLDER});

    EXPECT_CALL(*mockUser, getUserId()).WillRepeatedly(Return(11500));

    EXPECT_CALL(*mockUser, getName()).WillRepeatedly(Return("Sumit"));

    EXPECT_CALL(*mockUser, getRole()).WillRepeatedly(Return(Role::ACCOUNT_HOLDER));

    EXPECT_CALL(mockUserManager, verifyCredentials("sumit", "sumit@1234")).WillOnce(Return(true));

    EXPECT_CALL(mockUserManager, getUserByUsername("sumit")).WillOnce(Return(mockUser));

    auth->login("sumit", "sumit@1234");

    IUser *user = auth->getCurrentUser();

    ASSERT_EQ(user, mockUser);

    EXPECT_EQ(user->getUserId(), 11500);

    EXPECT_EQ(user->getName(), "Sumit");

    EXPECT_EQ(user->getRole(), Role::ACCOUNT_HOLDER);

    delete mockUser;
}