#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "accountHolder.h"
#include "mockAccount.h"

using ::testing::_;
using ::testing::Return;

class AccountHolderTest : public ::testing::Test
{
protected:
    AccountHolder accountHolder;
    MockAccount mockAccount;
    int accountNumber = 987654321;

    AccountHolderTest()
        : accountHolder(AccountHolderInfo{12345, "Ansh Bhargava", Role::ACCOUNT_HOLDER, "ansh@gmail.com", "9087654321"}) {}

    void SetUp() override
    {
        mockAccount.setAccountNumber(accountNumber);

        EXPECT_CALL(mockAccount, getAccountNumber()).WillRepeatedly(Return(accountNumber));
    }
};

TEST_F(AccountHolderTest, WhenDepositToExistingAccount_ThenReturnTrue)
{
    EXPECT_CALL(mockAccount, deposit(500.0)).Times(1).WillOnce(Return(true));

    accountHolder.addAccount(&mockAccount);

    bool result = accountHolder.depositToAccount(accountNumber, 500.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, WhenWithdrawFromExistingAccount_ThenReturnTrue)
{
    EXPECT_CALL(mockAccount, withdraw(200.0)).Times(1).WillOnce(Return(true));

    accountHolder.addAccount(&mockAccount);

    bool result = accountHolder.withdrawFromAccount(accountNumber, 200.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, WhenGetMiniStatementFromExistingAccount_ThenReturnTransactionList)
{
    std::vector<Transaction *> transactions;

    EXPECT_CALL(mockAccount, bankStatement()).Times(1).WillOnce(Return(transactions));

    accountHolder.addAccount(&mockAccount);

    std::vector<Transaction *> result = accountHolder.getMiniStatement(accountNumber);
    EXPECT_EQ(result.size(), 0);
}

TEST_F(AccountHolderTest, WhenDeleteExistingAccount_ThenReturnTrue)
{
    accountHolder.addAccount(&mockAccount);

    EXPECT_TRUE(accountHolder.deleteAccount(accountNumber));
}

TEST_F(AccountHolderTest, WhenDeleteAlreadyDeletedAccount_ThenReturnFalse)
{
    accountHolder.addAccount(&mockAccount);
    accountHolder.deleteAccount(accountNumber);

    EXPECT_FALSE(accountHolder.deleteAccount(accountNumber));
}

TEST_F(AccountHolderTest, WhenGetAccountNumbers_ThenReturnAllAccountNumbers)
{
    MockAccount mockAccount2;
    int secondAccountNumber = 991209765;
    mockAccount2.setAccountNumber(secondAccountNumber);

    EXPECT_CALL(mockAccount2, getAccountNumber()).WillRepeatedly(Return(secondAccountNumber));

    accountHolder.addAccount(&mockAccount);
    accountHolder.addAccount(&mockAccount2);

    std::vector<int> accounts = accountHolder.getAccountNumbers();

    ASSERT_EQ(accounts.size(), 2);

    EXPECT_EQ(accounts[0], accountNumber);

    EXPECT_EQ(accounts[1], secondAccountNumber);
}

TEST_F(AccountHolderTest, WhenDepositToNonExistingAccount_ThenReturnFalse)
{
    bool result = accountHolder.depositToAccount(accountNumber, 100.0);
    EXPECT_FALSE(result);
}

TEST_F(AccountHolderTest, WhenWithdrawFromNonExistingAccount_ThenReturnFalse)
{
    bool result = accountHolder.withdrawFromAccount(accountNumber, 50.0);
    EXPECT_FALSE(result);
}

TEST_F(AccountHolderTest, WhenGetMiniStatementFromNonExistingAccount_ThenReturnEmptyList)
{
    std::vector<Transaction *> result = accountHolder.getMiniStatement(accountNumber);
    EXPECT_TRUE(result.empty());
}

TEST_F(AccountHolderTest, WhenGetAccountDetailsByValidAccountNumber_ThenReturnAccount)
{
    accountHolder.addAccount(&mockAccount);

    Account *result = accountHolder.getAccountDetailsByAccountNumber(accountNumber);
    EXPECT_EQ(result, &mockAccount);
}

TEST_F(AccountHolderTest, WhenGetAccountHolderDetails_ThenReturnInfo)
{
    EXPECT_EQ(accountHolder.getEmail(), "ansh@gmail.com");

    EXPECT_EQ(accountHolder.getPhoneNumber(), "9087654321");

    EXPECT_EQ(accountHolder.getName(), "Ansh Bhargava");

    EXPECT_EQ(accountHolder.getRole(), Role::ACCOUNT_HOLDER);
}
