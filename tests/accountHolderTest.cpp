#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "accountHolder.h"
#include "mockAccount.h"

using ::testing::_;
using ::testing::Return;

class AccountHolderTest : public ::testing::Test
{
protected:
    AccountHolder *accountHolder;
    std::vector<MockAccount *> account;

    void SetUp() override
    {
        AccountHolderInfo info;
        info.name = "Ansh Bhargava";
        info.email = "ansh@gmail.com";
        info.phoneNumber = "9087654321";
        info.role = Role::ACCOUNT_HOLDER;
        accountHolder = new AccountHolder(info);
    }

    void TearDown() override
    {
        delete accountHolder;

        for (int iteratorI = 0; iteratorI < account.size(); iteratorI++)
        {
            delete account[iteratorI];
        }
        account.clear();
    }

    MockAccount *createMockAccount(int accountNumber)
    {
        MockAccount *mockAccount = new MockAccount();
        mockAccount->setAccountNumber(accountNumber);
        account.push_back(mockAccount);
        return mockAccount;
    }
};

TEST_F(AccountHolderTest, DepositToAccount)
{
    MockAccount *mockAccount = createMockAccount(987654321);

    EXPECT_CALL(*mockAccount, getAccountNumber()).WillRepeatedly(Return(987654321));

    EXPECT_CALL(*mockAccount, deposit(500.0)).Times(1).WillOnce(Return(true));

    accountHolder->addAccount(mockAccount);

    bool result = accountHolder->depositToAccount(987654321, 500.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, WithdrawFromAccount)
{
    MockAccount *mockAccount = createMockAccount(987654345);

    EXPECT_CALL(*mockAccount, getAccountNumber()).WillRepeatedly(Return(987654345));

    EXPECT_CALL(*mockAccount, withdraw(200.0)).Times(1).WillOnce(Return(true));

    accountHolder->addAccount(mockAccount);

    bool result = accountHolder->withdrawFromAccount(987654345, 200.0);
    EXPECT_TRUE(result);
}

TEST_F(AccountHolderTest, GetMiniStatement)
{
    MockAccount *mockAccount = createMockAccount(987657651);
    std::vector<Transaction *> transactions;

    EXPECT_CALL(*mockAccount, getAccountNumber()).WillRepeatedly(Return(987657651));

    EXPECT_CALL(*mockAccount, bankStatement()).Times(1).WillOnce(Return(transactions));

    accountHolder->addAccount(mockAccount);

    std::vector<Transaction *> result = accountHolder->getMiniStatement(987657651);
    EXPECT_EQ(result.size(), 0);
}

TEST_F(AccountHolderTest, DeleteAccount)
{
    MockAccount *mockAccount = createMockAccount(998877661);

    EXPECT_CALL(*mockAccount, getAccountNumber()).WillRepeatedly(Return(998877661));

    accountHolder->addAccount(mockAccount);

    EXPECT_TRUE(accountHolder->deleteAccount(998877661));

    EXPECT_FALSE(accountHolder->deleteAccount(998877661));
}

TEST_F(AccountHolderTest, GetAccountNumbers)
{
    MockAccount *mockAccount1 = createMockAccount(901234567);

    MockAccount *mockAccount2 = createMockAccount(991209765);

    EXPECT_CALL(*mockAccount1, getAccountNumber()).WillRepeatedly(Return(901234567));
    EXPECT_CALL(*mockAccount2, getAccountNumber()).WillRepeatedly(Return(991209765));

    accountHolder->addAccount(mockAccount1);
    accountHolder->addAccount(mockAccount2);

    std::vector<int> accounts = accountHolder->getAccountNumbers();

    ASSERT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0], 901234567);
    EXPECT_EQ(accounts[1], 991209765);
}

TEST_F(AccountHolderTest, DepositToNotExistentAccount)
{
    bool result = accountHolder->depositToAccount(123451235, 100.0);
    EXPECT_FALSE(result);
}

TEST_F(AccountHolderTest, WithdrawFromNotExistentAccount)
{
    bool result = accountHolder->withdrawFromAccount(123451235, 50.0);
    EXPECT_FALSE(result);
}

TEST_F(AccountHolderTest, GetMiniStatementFromNotExistentAccount)
{
    std::vector<Transaction *> result = accountHolder->getMiniStatement(123451235);
    EXPECT_TRUE(result.empty());
}

TEST_F(AccountHolderTest, GetAccountDetailsByAccountNumber)
{
    MockAccount *account = createMockAccount(123456789);
    EXPECT_CALL(*account, getAccountNumber()).WillRepeatedly(Return(123456789));

    accountHolder->addAccount(account);

    Account *result = accountHolder->getAccountDetailsByAccountNumber(123456789);
    EXPECT_EQ(result, account);
}

TEST_F(AccountHolderTest, GetAccountHolderDetails)
{
    EXPECT_EQ(accountHolder->getEmail(), "ansh@gmail.com");
    EXPECT_EQ(accountHolder->getPhoneNumber(), "9087654321");
    EXPECT_EQ(accountHolder->getName(), "Ansh Bhargava");
    EXPECT_EQ(accountHolder->getRole(), Role::ACCOUNT_HOLDER);
}
