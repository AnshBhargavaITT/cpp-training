#include <gtest/gtest.h>
#include "bank.h"
#include "userManager.h"

class BankTest : public ::testing::Test 
{
protected:
    UserManager userManager;
    Bank bank{&userManager};
};

TEST_F(BankTest, ValidRegisterAccountHolder) 
{
    AccountHolder *holder = bank.registerAccountHolder("Ansh Bhargava", "ansh@gmail.com", "9087654321", "ansh@123", "ansh@9876",-1);
    EXPECT_NE(holder, nullptr);
    EXPECT_EQ(holder->getName(), "Ansh Bhargava");
}

TEST_F(BankTest, InvalidRegisterAccountHolder) 
{
    AccountHolder *holder = bank.registerAccountHolder("Ansh Bhargava", "ansh@google.com", "909123456", "ansh@123", "ansh@9876",-1);
    EXPECT_EQ(holder, nullptr);
}

TEST_F(BankTest, RegisterAdmin) 
{
    Admin *admin = bank.registerAdmin("Sumit", "admin", "admin@123");
    EXPECT_NE(admin, nullptr);
    EXPECT_EQ(admin->getName(), "Sumit");
}

TEST_F(BankTest, CreateAccount) 
{
    AccountHolder *holder = bank.registerAccountHolder("Vansh Jain", "vansh@gmail.com", "9087654321", "vansh@8765", "vansh@1234",-1);
    Account *account = bank.createAccount(holder, AccountType::CURRENT_ACCOUNT);
    EXPECT_NE(account, nullptr);
    EXPECT_EQ(account->getAccountType(), AccountType::CURRENT_ACCOUNT);

    std::vector<Account*> accounts = bank.getAccountsByUser(holder);
    EXPECT_FALSE(accounts.empty());
    EXPECT_EQ(accounts[0]->getAccountNumber(), account->getAccountNumber());
}
