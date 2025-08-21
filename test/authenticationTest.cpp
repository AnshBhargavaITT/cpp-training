#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "authentication.h"
#include "mockUserManager.h"
#include "users.h"  
#include "userInfo.h"

using ::testing::Return;
using ::testing::_;

class AuthenticationTest : public ::testing::Test 
{
protected:
    MockUserManager mockUserManager;  
    Authentication* auth;

    void SetUp() override 
    {
        auth = new Authentication(&mockUserManager);
    }

    void TearDown() override 
    {
        delete auth;
    }
};

class TestUser : public User 
{
public:
    TestUser(const UserInfo& info) : User(info) {}

    int getUserId() const override { return userId; }
    std::string getName() const override { return name; }
    Role getRole() const override { return role; }
};

TEST_F(AuthenticationTest, LoginSuccess) 
{
    User* loginUser = new TestUser({11500, "Sumit", Role::ACCOUNT_HOLDER});

    EXPECT_CALL(mockUserManager, verifyCredentials("admin", "admin@123"))
        .WillOnce(Return(true));
    EXPECT_CALL(mockUserManager, getUserByUsername("admin"))
        .WillOnce(Return(loginUser));

    User* user = auth->login("admin", "admin@123");
    EXPECT_EQ(user, loginUser);

    delete loginUser;
}

TEST_F(AuthenticationTest, LoginFailWrongPassword) 
{
    EXPECT_CALL(mockUserManager, verifyCredentials("ansh@123", "5674321"))
        .WillOnce(Return(false));
    
    EXPECT_CALL(mockUserManager, getUserByUsername("ansh@123")).Times(0);

    User* user = auth->login("ansh@123", "5674321");
    EXPECT_EQ(user, nullptr);
}

TEST_F(AuthenticationTest, LogoutWhenLoggedIn) 
{
    User* loginUser = new TestUser({11500, "Sumit", Role::ACCOUNT_HOLDER});

    EXPECT_CALL(mockUserManager, verifyCredentials(_, _))
        .WillOnce(Return(true));
    EXPECT_CALL(mockUserManager, getUserByUsername(_))
        .WillOnce(Return(loginUser));

    auth->login("sumit@123", "5674321");

    EXPECT_TRUE(auth->logout());

    delete loginUser;
}

TEST_F(AuthenticationTest, LogoutWhenNoUser) 
{
    EXPECT_FALSE(auth->logout());
}
