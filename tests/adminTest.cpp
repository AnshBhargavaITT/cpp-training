#include <gtest/gtest.h>
#include "admin.h"

class AdminTest : public ::testing::Test
{
protected:
    Admin *admin;
    UserInfo info;

    void SetUp() override
    {
        info.id = 11012;
        info.name = "Ansh";
        info.role = Role::ADMIN;
        admin = new Admin(info);
    }

    void TearDown() override
    {
        delete admin;
    }
};

TEST_F(AdminTest, WhenGetUserId_ThenReturnId)
{
    EXPECT_EQ(admin->getUserId(), 11012);
}

TEST_F(AdminTest, WhenGetName_ThenReturnName)
{
    EXPECT_EQ(admin->getName(), "Ansh");
}

TEST_F(AdminTest, WhenGetRole_ThenReturnAdminRole)
{
    EXPECT_EQ(admin->getRole(), Role::ADMIN);
}

TEST_F(AdminTest, WhenCheckingHasBankAccountInitially_ThenReturnFalse)
{
    EXPECT_FALSE(admin->hasBankAccount());
}

TEST_F(AdminTest, WhenSetAccountHolderProfile_ThenHasBankAccountReturnsTrue)
{
    AccountHolderInfo accountHolderProfile;
    accountHolderProfile.id = 11012;
    accountHolderProfile.name = "Ansh";
    accountHolderProfile.role = Role::ACCOUNT_HOLDER;
    accountHolderProfile.email = "ansh06@mail.com";
    accountHolderProfile.phoneNumber = "9087654321";

    AccountHolder accountHolder(accountHolderProfile);
    admin->setAccountHolderProfile(&accountHolder);

    EXPECT_TRUE(admin->hasBankAccount());
    EXPECT_EQ(admin->getAccountHolderProfile(), &accountHolder);
}
