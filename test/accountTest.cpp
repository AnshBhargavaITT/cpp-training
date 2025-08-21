#include <gtest/gtest.h>
#include "currentAccount.h"
#include "savingAccount.h"

TEST(CurrentAccountTest, WithdrawReducesBalance) 
{
    CurrentAccount account;
    account.deposit(1000);
    bool success = account.withdraw(500);
    EXPECT_TRUE(success);
    EXPECT_EQ(account.getBalance(), 500);
}

TEST(SavingsAccountTest, WithdrawFailsIfInsufficientBalance) 
{
    SavingsAccount account;
    account.deposit(100);
    bool success = account.withdraw(200);
    EXPECT_FALSE(success);
    EXPECT_EQ(account.getBalance(), 100);
}
