#include <gtest/gtest.h>
#include "currentAccount.h"
#include "savingAccount.h"

TEST(CurrentAccountTest, WithdrawAmount)
{
    CurrentAccount account;
    account.deposit(1000.0);
    bool result = account.withdraw(500.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(CurrentAccountTest, WithdrawAmountZeroFails)
{
    CurrentAccount account;
    account.deposit(500.0);
    EXPECT_FALSE(account.withdraw(0.0));
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(CurrentAccountTest, WithdrawAmountNegativeFails)
{
    CurrentAccount account;
    account.deposit(500.0);
    EXPECT_FALSE(account.withdraw(-100.0));
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(SavingsAccountTest, WithdrawFailsIfInsufficientBalance)
{
    SavingsAccount account;
    account.deposit(100.0);
    bool result = account.withdraw(200.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account.getBalance(), 100.0);
}

TEST(SavingAccountTest, WithdrawAmount)
{
    SavingsAccount account;
    account.deposit(1000.0);
    bool result = account.withdraw(1000.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account.getBalance(), 0.0);
}

TEST(AccountTest, DepositAmount)
{
    CurrentAccount account;
    bool result = account.deposit(500.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(AccountTest, DepositAmountZeroFails)
{
    CurrentAccount account;
    bool result = account.deposit(0.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account.getBalance(), 0.0);
}

TEST(AccountTest, DepositAmountNegativeFails)
{
    CurrentAccount account;
    bool result = account.deposit(-100.0);
    EXPECT_FALSE(result);
    EXPECT_EQ(account.getBalance(), 0.0);
}

TEST(AccountTest, MultipleDepositsAndWithdrawAmount)
{
    CurrentAccount account;
    account.deposit(200.0);
    account.deposit(300.0);
    account.withdraw(100.0);
    EXPECT_EQ(account.getBalance(), 400.0);
}

TEST(AccountTest, SetAndGetAccountNumber)
{
    SavingsAccount account;
    account.setAccountNumber(123456789);
    EXPECT_EQ(account.getAccountNumber(), 123456789);
}

TEST(AccountTest, BankStatement)
{
    SavingsAccount account;
    account.deposit(100.0);
    account.withdraw(50.0);
    std::vector<Transaction *> transactions = account.bankStatement();
    ASSERT_EQ(transactions.size(), 2);
}
