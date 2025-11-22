#include <gtest/gtest.h>
#include "accountHolder.h"

TEST(AccountHolderTest, DepositIncreasesBalance) 
{
    AccountHolder acc("Alice", 100);
    acc.deposit(50);
    EXPECT_EQ(acc.getBalance(), 150);
}

TEST(AccountHolderTest, WithdrawDecreasesBalance) 
{
    AccountHolder acc("Bob", 100);
    bool success = acc.withdraw(40);
    EXPECT_TRUE(success);
    EXPECT_EQ(acc.getBalance(), 60);
}

TEST(AccountHolderTest, WithdrawFailsIfInsufficientFunds) {
    AccountHolder acc("Charlie", 50);
    bool success = acc.withdraw(100);
    EXPECT_FALSE(success);
    EXPECT_EQ(acc.getBalance(), 50);
}
