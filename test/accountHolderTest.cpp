#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "accountHolder.h"
#include "mockAccount.h"

using ::testing::Return;
using ::testing::Exactly;
using ::testing::_;

class AccountHolderTest : public ::testing::Test 
{
protected:
    AccountHolder* accountHolder;

    void SetUp() override 
    {
        AccountHolderInfo info;
        info.name = "Ansh Bhargava";
        info.email = "ansh@gmail.com";
        info.phoneNumber = "9087654321";

        accountHolder = new AccountHolder(info);
    }

    void TearDown() override 
    {
        delete accountHolder;
    }
};

TEST_F(AccountHolderTest, DepositToAccount) 
{
    MockAccount* mockAccount = new MockAccount();
    mockAccount->setAccountNumber(987654321);

    EXPECT_CALL(*mockAccount, getAccountNumber())
        .WillRepeatedly(Return(987654321));

    EXPECT_CALL(*mockAccount, deposit(500.0))
        .Times(Exactly(1))
        .WillOnce(Return(true));

    accountHolder->addAccount(mockAccount);

    bool result = accountHolder->depositToAccount(987654321, 500.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, WithdrawFromAccount) 
{
    MockAccount* mockAccount = new MockAccount();
    mockAccount->setAccountNumber(987654345);

    EXPECT_CALL(*mockAccount, getAccountNumber())
        .WillRepeatedly(Return(987654345));

    EXPECT_CALL(*mockAccount, withdraw(200.0))
        .Times(Exactly(1))
        .WillOnce(Return(true));

    accountHolder->addAccount(mockAccount);

    bool result = accountHolder->withdrawFromAccount(987654345, 200.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, GetMiniStatement) 
{
    MockAccount* mockAccount = new MockAccount();
    std::vector<Transaction*> transactions;
    mockAccount->setAccountNumber(987657651);

    EXPECT_CALL(*mockAccount, getAccountNumber())
        .WillRepeatedly(Return(987657651));

    EXPECT_CALL(*mockAccount, bankStatement())
        .Times(1)
        .WillOnce(Return(transactions));

    accountHolder->addAccount(mockAccount);

    std::vector<Transaction*> result = accountHolder->getMiniStatement(987657651);
    EXPECT_EQ(result.size(), 0);
}

TEST_F(AccountHolderTest, DeleteAccount) 
{
    MockAccount* mockAccount = new MockAccount();
    mockAccount->setAccountNumber(998877661);

    EXPECT_CALL(*mockAccount, getAccountNumber())
        .WillRepeatedly(Return(998877661));

    accountHolder->addAccount(mockAccount);

    EXPECT_TRUE(accountHolder->deleteAccount(998877661));
    EXPECT_FALSE(accountHolder->deleteAccount(998877661)); 
}

TEST_F(AccountHolderTest, GetAccountNumbers) 
{
    MockAccount* mockAccount1 = new MockAccount();
    MockAccount* mockAccount2 = new MockAccount();

    mockAccount1->setAccountNumber(901234567);
    mockAccount2->setAccountNumber(991209765);

    EXPECT_CALL(*mockAccount1, getAccountNumber())
        .WillRepeatedly(Return(901234567));
    EXPECT_CALL(*mockAccount2, getAccountNumber())
        .WillRepeatedly(Return(991209765));

    accountHolder->addAccount(mockAccount1);
    accountHolder->addAccount(mockAccount2);

    std::vector<int> numbers = accountHolder->getAccountNumbers();

    ASSERT_EQ(numbers.size(), 2);
    EXPECT_EQ(numbers[0], 901234567);
    EXPECT_EQ(numbers[1], 991209765);
}
