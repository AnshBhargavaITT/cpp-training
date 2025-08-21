#include <gtest/gtest.h>
#include "transactions.h"

TEST(TransactionTest, GetTransactionDetail) 
{
    Transaction transaction(AccountType::CURRENT_ACCOUNT, 150.5, "2025-08-20");

    std::string detail = transaction.getTransactionDetail();

    EXPECT_EQ(detail, "Account Type: CURRENT_ACCOUNT, Amount: 150.5, Date: 2025-08-20");
}
