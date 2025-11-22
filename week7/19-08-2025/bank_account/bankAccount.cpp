#include <iostream>
#include <gtest/gtest.h>

class BankingSystem 
{
    double balance;
public:
    BankingSystem() : balance(0.0) {}

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(int amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
        }
    }

    double getBalance() const
    {
        return balance;
    }
};

class BankingSystemTest : public ::testing::Test
{
protected:
    BankingSystem* bank;

    void SetUp() override
    {
        bank = new BankingSystem();
        bank->deposit(1000);
    }

    void TearDown() override
    {
        delete bank;
        bank = nullptr;
    }
};

TEST_F(BankingSystemTest, InitialBalance)
{
    EXPECT_DOUBLE_EQ(bank->getBalance(), 1000.0);
}

TEST_F(BankingSystemTest , DepositFund)
{
    bank->deposit(5000);
    EXPECT_DOUBLE_EQ(bank->getBalance(),6000.0);
}

TEST_F(BankingSystemTest , WithdrawFund)
{
    bank->withdraw(1000);
    EXPECT_DOUBLE_EQ(bank->getBalance(),0.0);
}

TEST_F(BankingSystemTest , CannotWithdrawMoreAmount)
{
    bank->withdraw(2000);
    EXPECT_DOUBLE_EQ(bank->getBalance(),1000.0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
