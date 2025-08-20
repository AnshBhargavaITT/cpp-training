#include <gtest/gtest.h>
#include "bank.h"

TEST(BankTest, TotalAssetsIsSumOfBalances) {
    Bank bank;
    bank.addAccount(AccountHolder("Alice", 100));
    bank.addAccount(AccountHolder("Bob", 200));
    EXPECT_EQ(bank.totalAssets(), 300);
}

TEST(BankTest, FindAccountReturnsCorrectAccount) {
    Bank bank;
    bank.addAccount(AccountHolder("Alice", 100));
    AccountHolder* acc = bank.findAccount("Alice");
    ASSERT_NE(acc, nullptr);
    EXPECT_EQ(acc->getName(), "Alice");
}

TEST(BankTest, FindAccountReturnsNullptrIfNotFound) {
    Bank bank;
    AccountHolder* acc = bank.findAccount("NonExistent");
    EXPECT_EQ(acc, nullptr);
}
