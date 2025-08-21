#include <gtest/gtest.h>
#include "userManager.h"
#include "users.h"
#include "mockUserTest.h"

class UserManagerTest : public ::testing::Test 
{
protected:
    UserManager userManager;

    MockUser user11003{UserInfo{11003, "Ansh", Role::ACCOUNT_HOLDER}};
    MockUser user11987{UserInfo{11987, "Yash", Role::ACCOUNT_HOLDER}};
    MockUser user12312{UserInfo{12312, "John", Role::ACCOUNT_HOLDER}};
    MockUser user19876{UserInfo{19876, "Rishabh", Role::ACCOUNT_HOLDER}};
    MockUser user12345{UserInfo{12345, "Sumit", Role::ADMIN}}; 
    MockUser user28345{UserInfo{28345, "Aditya", Role::ACCOUNT_HOLDER}};
    MockUser user13590{UserInfo{14590, "Arpit", Role::ACCOUNT_HOLDER}};

    void SetUp() override 
    {
        userManager.addUser(&user11003, "ansh@6603", "ansh@123");
        userManager.addUser(&user11987, "yash@309", "yash@1234");
        userManager.addUser(&user12345, "sumit@612", "sumit@9876");
    }

    void TearDown() override 
    {
        userManager.removeUser(user11003.getUserId());
        userManager.removeUser(user11987.getUserId());
        userManager.removeUser(user12312.getUserId());
        userManager.removeUser(user19876.getUserId());
        userManager.removeUser(user12345.getUserId());
        userManager.removeUser(user28345.getUserId());
        userManager.removeUser(user13590.getUserId());
    }
};

TEST_F(UserManagerTest, AddNewUserReturnsTrue) 
{
    EXPECT_TRUE(userManager.addUser(&user19876, "rishabh@8181", "rish@pass"));
}

TEST_F(UserManagerTest, AddUserFailsIfUserAlreadyExists) 
{
    EXPECT_FALSE(userManager.addUser(&user11003, "duplicateAnsh", "pass@3456"));
}

TEST_F(UserManagerTest, RemoveExistingUserReturnsTrue) 
{
    EXPECT_TRUE(userManager.removeUser(user11003.getUserId()));
    EXPECT_EQ(userManager.getUserById(user11003.getUserId()), nullptr);
}

TEST_F(UserManagerTest, RemoveNonexistentUserReturnsFalse) 
{
    EXPECT_FALSE(userManager.removeUser(9999));
}

TEST_F(UserManagerTest, GetUserByIdReturnsCorrectUser) 
{
    EXPECT_EQ(userManager.getUserById(user11987.getUserId()), &user11987);
}

TEST_F(UserManagerTest, GetUserByIdReturnsNullIfNotFound) 
{
    EXPECT_EQ(userManager.getUserById(99999), nullptr);
}

TEST_F(UserManagerTest, GetUserByUsernameReturnsCorrectUser) 
{
    EXPECT_EQ(userManager.getUserByUsername("yash@309"), &user11987);
}

TEST_F(UserManagerTest, GetUserByUsernameReturnsNullIfNotFound) 
{
    EXPECT_EQ(userManager.getUserByUsername("dheeraj"), nullptr);
}

TEST_F(UserManagerTest, VerifyCorrectCredentials) 
{
    EXPECT_TRUE(userManager.verifyCredentials("ansh@6603", "ansh@123"));
    EXPECT_TRUE(userManager.verifyCredentials("yash@309", "yash@1234"));
    EXPECT_TRUE(userManager.verifyCredentials("sumit@612", "sumit@9876"));
}

TEST_F(UserManagerTest, VerifyIncorrectCredentialsFails) 
{
    EXPECT_FALSE(userManager.verifyCredentials("ansh@6603", "wrongpass"));
}

TEST_F(UserManagerTest, VerifyCredentialsFailsForUnknownUser) 
{
    EXPECT_FALSE(userManager.verifyCredentials("dheeraj", "password"));
}

TEST_F(UserManagerTest, GetCredentialByUserIdReturnsCorrectData) 
{
    Credential cred = userManager.getCredentialByUserId(user12345.getUserId());
    EXPECT_EQ(cred.username, "sumit@612");
    EXPECT_EQ(cred.user, &user12345);
}

TEST_F(UserManagerTest, GetCredentialReturnsEmptyIfUserNotFound) 
{
    Credential cred = userManager.getCredentialByUserId(404);
    EXPECT_EQ(cred.username, "");
    EXPECT_EQ(cred.user, nullptr);
}

TEST_F(UserManagerTest, UserRoleIsStoredCorrectly) 
{
    EXPECT_EQ(user11003.getRole(), Role::ACCOUNT_HOLDER);
    EXPECT_EQ(user12345.getRole(), Role::ADMIN);
}
