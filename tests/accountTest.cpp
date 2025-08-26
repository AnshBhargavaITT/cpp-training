#include <gtest/gtest.h>
#include <string>
#include "currentAccount.h"
#include "savingAccount.h"

class AccountTest : public ::testing::Test
{
protected:
    CurrentAccount currentAccount;
    SavingsAccount savingsAccount;

    void SetUp() override
    {
        currentAccount = CurrentAccount();
        savingsAccount = SavingsAccount();
    }
};

TEST_F(AccountTest, WhenDepositValidAmountToCurrentAccount_ThenBalanceIncreases)
{
    EXPECT_TRUE(currentAccount.deposit(500.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 500.0);
}

TEST_F(AccountTest, WhenDepositZeroAmountToCurrentAccount_ThenDepositFails)
{
    EXPECT_FALSE(currentAccount.deposit(0.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 0.0);
}

TEST_F(AccountTest, WhenDepositNegativeAmountToCurrentAccount_ThenDepositFails)
{
    EXPECT_FALSE(currentAccount.deposit(-100.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 0.0);
}

TEST_F(AccountTest, WhenWithdrawValidAmountFromCurrentAccount_ThenBalanceDecreases)
{
    currentAccount.deposit(1000.0);

    EXPECT_TRUE(currentAccount.withdraw(500.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 500.0);
}

TEST_F(AccountTest, WhenWithdrawZeroAmountFromCurrentAccount_ThenWithdrawFails)
{
    currentAccount.deposit(500.0);

    EXPECT_FALSE(currentAccount.withdraw(0.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 500.0);
}

TEST_F(AccountTest, WhenWithdrawNegativeAmountFromCurrentAccount_ThenWithdrawFails)
{
    currentAccount.deposit(500.0);

    EXPECT_FALSE(currentAccount.withdraw(-100.0));

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 500.0);
}

TEST_F(AccountTest, WhenWithdrawMoreThanBalanceFromSavingsAccount_ThenWithdrawFails)
{
    savingsAccount.deposit(100.0);

    EXPECT_FALSE(savingsAccount.withdraw(200.0));

    EXPECT_DOUBLE_EQ(savingsAccount.getBalance(), 100.0);
}

TEST_F(AccountTest, WhenWithdrawValidAmountFromSavingsAccount_ThenBalanceDecreases)
{
    savingsAccount.deposit(1000.0);

    EXPECT_TRUE(savingsAccount.withdraw(1000.0));

    EXPECT_DOUBLE_EQ(savingsAccount.getBalance(), 0.0);
}

TEST_F(AccountTest, WhenMultipleDepositsAndWithdrawalsOnCurrentAccount_ThenBalanceUpdated)
{
    currentAccount.deposit(200.0);

    currentAccount.deposit(300.0);

    currentAccount.withdraw(100.0);

    EXPECT_DOUBLE_EQ(currentAccount.getBalance(), 400.0);
}

TEST_F(AccountTest, WhenSetAccountNumberOnSavingsAccount_ThenGetAccountNumberReturnsValue)
{
    savingsAccount.setAccountNumber(123456789);

    EXPECT_EQ(savingsAccount.getAccountNumber(), 123456789);
}

TEST_F(AccountTest, WhenRequestBankStatementFromSavingsAccount_ThenReturnAllTransactions)
{
    savingsAccount.deposit(100.0);
    savingsAccount.withdraw(50.0);

    std::vector<Transaction *> transactions = savingsAccount.bankStatement();

    ASSERT_EQ(transactions.size(), 2);

    EXPECT_DOUBLE_EQ(transactions[0]->getAmount(), 100.0);

    EXPECT_DOUBLE_EQ(transactions[1]->getAmount(), -50.0);
}
