#include <gtest/gtest.h>
#include "transactions.h"

TEST(TransactionTest, GetCurrentAccountTransactionDetail)
{
    Transaction transaction(AccountType::CURRENT_ACCOUNT, 150.5, "2025-08-20");
    std::string detail = transaction.getTransactionDetail();
    EXPECT_EQ(detail, "Date: 2025-08-20, Amount: 150.500000");
}

TEST(TransactionTest, GetSavingAccountTransactionDetail)
{
    Transaction transaction(AccountType::SAVING_ACCOUNT, -200.0, "2025-08-21");
    std::string detail = transaction.getTransactionDetail();
    EXPECT_EQ(detail, "Date: 2025-08-21, Amount: -200.000000");
}
