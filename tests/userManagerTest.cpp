#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "userManager.h"
#include "users.h"
#include "mockUser.h"

using ::testing::Return;

class UserManagerTest : public ::testing::Test
{
protected:
    UserManager userManager;

    MockUser user11003{UserInfo{11003, "Ansh", Role::ACCOUNT_HOLDER}};

    MockUser user11987{UserInfo{11987, "Yash", Role::ACCOUNT_HOLDER}};

    MockUser user19876{UserInfo{19876, "Rishabh", Role::ACCOUNT_HOLDER}};

    MockUser user12345{UserInfo{12345, "Sumit", Role::ADMIN}};

    void SetUp() override
    {
        ON_CALL(user11003, getUserId()).WillByDefault(Return(11003));

        ON_CALL(user11987, getUserId()).WillByDefault(Return(11987));

        ON_CALL(user19876, getUserId()).WillByDefault(Return(19876));

        ON_CALL(user12345, getUserId()).WillByDefault(Return(12345));

        userManager.addUser(&user11003, "ansh@6603", "ansh@123");

        userManager.addUser(&user11987, "yash@309", "yash@1234");

        userManager.addUser(&user12345, "sumit@612", "sumit@9876");
    }

    void TearDown() override
    {
        userManager.removeUser(user11003.getUserId());

        userManager.removeUser(user11987.getUserId());

        userManager.removeUser(user19876.getUserId());

        userManager.removeUser(user12345.getUserId());
    }
};

TEST_F(UserManagerTest, AddNewUser)
{
    EXPECT_TRUE(userManager.addUser(&user19876, "rishabh@8181", "rish@1234"));
}

TEST_F(UserManagerTest, AddNewUserFailsIfUserAlreadyExists)
{
    EXPECT_FALSE(userManager.addUser(&user11003, "Shyam", "shyam@3456"));
}

TEST_F(UserManagerTest, RemoveExistingUser)
{
    EXPECT_TRUE(userManager.removeUser(user11003.getUserId()));

    EXPECT_EQ(userManager.getUserById(user11003.getUserId()), nullptr);
}

TEST_F(UserManagerTest, RemoveNonexistentUser)
{
    EXPECT_FALSE(userManager.removeUser(9999));
}

TEST_F(UserManagerTest, GetUserById)
{
    EXPECT_EQ(userManager.getUserById(user11987.getUserId()), &user11987);
}

TEST_F(UserManagerTest, GetUserByIdReturnsNull)
{
    EXPECT_EQ(userManager.getUserById(99999), nullptr);
}

TEST_F(UserManagerTest, GetUserByUsername)
{
    EXPECT_EQ(userManager.getUserByUsername("yash@309"), &user11987);
}

TEST_F(UserManagerTest, GetUserByUsernameReturnsNull)
{
    EXPECT_EQ(userManager.getUserByUsername("dheeraj"), nullptr);
}

TEST_F(UserManagerTest, VerifyCredentials)
{
    EXPECT_TRUE(userManager.verifyCredentials("ansh@6603", "ansh@123"));

    EXPECT_TRUE(userManager.verifyCredentials("yash@309", "yash@1234"));

    EXPECT_TRUE(userManager.verifyCredentials("sumit@612", "sumit@9876"));
}

TEST_F(UserManagerTest, VerifyIncorrectCredentials)
{
    EXPECT_FALSE(userManager.verifyCredentials("ansh@6603", "ansh@09876"));
}

TEST_F(UserManagerTest, VerifyCredentialsFailsForUnknownUser)
{
    EXPECT_FALSE(userManager.verifyCredentials("dheeraj", "dhee@123"));
}

TEST_F(UserManagerTest, GetCredentialByUserId)
{
    Credential credential = userManager.getCredentialByUserId(user12345.getUserId());

    EXPECT_EQ(credential.username, "sumit@612");

    EXPECT_EQ(credential.user, &user12345);
}

TEST_F(UserManagerTest, GetCredentialReturnsNULLIfUserNotFound)
{
    Credential credential = userManager.getCredentialByUserId(40412);

    EXPECT_EQ(credential.username, "");

    EXPECT_EQ(credential.user, nullptr);
}
