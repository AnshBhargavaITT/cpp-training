#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "bank.h"
#include "accountHolder.h"
#include "admin.h"
#include "currentAccount.h"
#include "savingAccount.h"
#include "mockUserManager.h"

using ::testing::_;
using ::testing::Return;
using ::testing::ReturnRef;

class BankTest : public ::testing::Test
{
protected:
    MockUserManager mockUserManager;
    Bank bank;

    std::vector<IUser *> users;

    AccountHolder existingAccountHolder{AccountHolderInfo{12345, "Yash Singh", Role::ACCOUNT_HOLDER, "yash@gmail.com", "9876543210"}};

    Admin existingAdmin{UserInfo{54321, "Arpit Jain", Role::ADMIN}};

    BankTest() : bank(&mockUserManager) {}

    void SetUp() override
    {
        users.clear();
        users.push_back(&existingAccountHolder);
        users.push_back(&existingAdmin);
    }
};

TEST_F(BankTest, WhenRegisterAccountHolderWithValidDetails_ThenReturnValidAccountHolder)
{
    std::string name = "Ansh Bhargava";
    std::string username = "ansh@981";
    std::string password = "ansh@12345";
    std::string email = "ansh03@gmail.com";
    std::string phone = "9876543210";

    EXPECT_CALL(mockUserManager, getUserByUsername(username)).WillOnce(Return(nullptr));

    EXPECT_CALL(mockUserManager, addUser(_, username, password)).WillOnce(Return(true));

    AccountHolder *holder = bank.registerAccountHolder(name, email, phone, username, password, -1);

    ASSERT_NE(holder, nullptr);

    EXPECT_EQ(holder->getName(), name);
}

TEST_F(BankTest, WhenRegisterAccountHolderWithInvalidPhoneNumber_ThenReturnNull)
{
    AccountHolder *holder = bank.registerAccountHolder("Sumit Kumar", "sumit@gmail.com", "812345678", "sumit", "sumit@3456", -1);
    EXPECT_EQ(holder, nullptr);
}

TEST_F(BankTest, WhenRegisterAccountHolderWithDuplicateUsername_ThenReturnNull)
{
    EXPECT_CALL(mockUserManager, getUserByUsername("yash")).WillOnce(Return(&existingAccountHolder));
    AccountHolder *holder = bank.registerAccountHolder("Yash Singh", "yash@gmail.com", "9876543210", "yash", "yash@9837", -1);
    EXPECT_EQ(holder, nullptr);
}

TEST_F(BankTest, WhenRegisterAdminWithValidDetails_ThenReturnAdmin)
{
    std::string name = "Vansh Gupta";
    std::string username = "vansh";
    std::string password = "vansh@5566";

    EXPECT_CALL(mockUserManager, getUserByUsername(username)).WillOnce(Return(nullptr));

    EXPECT_CALL(mockUserManager, addUser(_, username, password)).WillOnce(Return(true));

    Admin *admin = bank.registerAdmin(name, username, password);

    ASSERT_NE(admin, nullptr);

    EXPECT_EQ(admin->getName(), name);
}

TEST_F(BankTest, WhenRegisterAdminWithInvalidPassword_ThenReturnNull)
{
    Admin *admin = bank.registerAdmin("Dheeraj Sharma", "dheeraj", "123");
    EXPECT_EQ(admin, nullptr);
}

TEST_F(BankTest, WhenRegisterAdminWithDuplicateUsername_ThenReturnNull)
{
    EXPECT_CALL(mockUserManager, getUserByUsername("arpit")).WillOnce(Return(&existingAdmin));
    Admin *admin = bank.registerAdmin("Arpit Jain", "arpit", "arpit@7890");
    EXPECT_EQ(admin, nullptr);
}

TEST_F(BankTest, WhenCreateCurrentAndSavingAccountForRegisteredAccountHolder_ThenReturnAccounts)
{
    std::string name = "Ansh Bhargava";
    std::string username = "ansh@987";
    std::string password = "ansh@12453";
    std::string email = "ansh03@gmail.com";
    std::string phone = "9876543210";

    EXPECT_CALL(mockUserManager, getUserByUsername(username)).WillOnce(Return(nullptr));

    EXPECT_CALL(mockUserManager, addUser(_, username, password)).WillOnce(Return(true));

    AccountHolder *holder = bank.registerAccountHolder(name, email, phone, username, password, -1);
    ASSERT_NE(holder, nullptr);

    Account *currentAccount = bank.createAccount(holder, AccountType::CURRENT_ACCOUNT);

    ASSERT_NE(currentAccount, nullptr);

    EXPECT_EQ(currentAccount->getAccountType(), AccountType::CURRENT_ACCOUNT);

    Account *savingAccount = bank.createAccount(holder, AccountType::SAVING_ACCOUNT);

    ASSERT_NE(savingAccount, nullptr);

    EXPECT_EQ(savingAccount->getAccountType(), AccountType::SAVING_ACCOUNT);
}

TEST_F(BankTest, WhenCloseCurrentAccountOfAccountHolder_ThenReturnTrue)
{
    AccountHolder holderForAccountClose{AccountHolderInfo{10001, "Sumit Kumar", Role::ACCOUNT_HOLDER, "sumit@gmail.com", "9876543210"}};

    Account *currentAccount = bank.createAccount(&holderForAccountClose, AccountType::CURRENT_ACCOUNT);

    ASSERT_NE(currentAccount, nullptr);

    currentAccount->setAccountNumber(123456789);

    users.push_back(&holderForAccountClose);

    EXPECT_CALL(mockUserManager, getAllUsers()).WillRepeatedly(ReturnRef(users));

    EXPECT_TRUE(bank.closeAccount(123456789));

    users.pop_back();
}
TEST_F(BankTest, WhenGetAccountsByRegisteredUser_ThenReturnAllAccounts)
{
    std::string name = "Yash Singh";
    std::string username = "yash2";
    std::string password = "yash@9837";
    std::string email = "yash2@gmail.com";
    std::string phone = "9876543210";

    EXPECT_CALL(mockUserManager, getUserByUsername(username)).WillOnce(Return(nullptr));

    EXPECT_CALL(mockUserManager, addUser(_, username, password)).WillOnce(Return(true));

    AccountHolder *holder = bank.registerAccountHolder(name, email, phone, username, password, -1);

    ASSERT_NE(holder, nullptr);

    bank.createAccount(holder, AccountType::CURRENT_ACCOUNT);

    bank.createAccount(holder, AccountType::SAVING_ACCOUNT);

    std::vector<Account *> accounts = bank.getAccountsByUser(holder);
    EXPECT_EQ(accounts.size(), 2);
}

TEST_F(BankTest, WhenRemoveUserWithValidUserId_ThenReturnTrue)
{
    AccountHolder holder{AccountHolderInfo{10002, "Vansh Gupta", Role::ACCOUNT_HOLDER, "vansh@gmail.com", "9876543210"}};
    Account *account = bank.createAccount(&holder, AccountType::CURRENT_ACCOUNT);
    holder.addAccount(account);

    users.push_back(&holder);

    EXPECT_CALL(mockUserManager, getUserById(10002)).WillOnce(Return(&holder));

    EXPECT_CALL(mockUserManager, getAllUsers()).WillRepeatedly(ReturnRef(users));

    EXPECT_CALL(mockUserManager, removeUser(10002)).WillOnce(Return(true));

    EXPECT_TRUE(bank.removeUser(10002, 99999));

    users.pop_back();
}

TEST_F(BankTest, WhenRemoveUserWithAdminHavingAccountHolderProfile_ThenReturnTrue)
{
    Admin admin{UserInfo{88888, "Sumit Kumar", Role::ADMIN}};
    users.push_back(&admin);

    AccountHolder holder{
        AccountHolderInfo{88888, "Sumit Kumar", Role::ACCOUNT_HOLDER, "sumit@gmail.com", "9876543210"}};

    Account *account = bank.createAccount(&holder, AccountType::SAVING_ACCOUNT);
    account->setAccountNumber(123789456);
    holder.addAccount(account);

    admin.setAccountHolderProfile(&holder);

    EXPECT_CALL(mockUserManager, getUserById(88888)).WillOnce(Return(&admin));

    EXPECT_CALL(mockUserManager, getCredentialByUserId(88888)).WillOnce(Return(Credential{"sumit", "sumit@7890", &admin}));

    EXPECT_CALL(mockUserManager, removeUser(88888)).WillOnce(Return(true));

    EXPECT_CALL(mockUserManager, addUser(_, "sumit", "sumit@7890")).WillOnce(Return(true));

    EXPECT_TRUE(bank.removeUser(88888, 10000));

    users.pop_back();
}

TEST_F(BankTest, WhenRemoveUserWithSameIdAsAdmin_ThenReturnFalse)
{
    Admin admin{UserInfo{88888, "Sumit Kumar", Role::ADMIN}};
    users.push_back(&admin);

    EXPECT_CALL(mockUserManager, getUserById(88888)).WillOnce(Return(&admin));

    EXPECT_FALSE(bank.removeUser(88888, 88888));

    users.pop_back();
}

TEST_F(BankTest, WhenGetUserByValidUserId_ThenReturnUser)
{
    Admin admin{UserInfo{77777, "Vansh Gupta", Role::ADMIN}};
    users.push_back(&admin);

    EXPECT_CALL(mockUserManager, getUserById(77777)).WillOnce(Return(&admin));

    IUser *result = bank.getUser(77777);
    EXPECT_EQ(result, &admin);

    users.pop_back();
}

TEST_F(BankTest, WhenGetUserIdByValidAccount_ThenReturnUserId)
{
    std::string name = "Ansh Bhargava";
    std::string username = "ansh";
    std::string password = "ansh@123";
    std::string email = "ansh@gmail.com";
    std::string phone = "9876543210";

    EXPECT_CALL(mockUserManager, getUserByUsername(username)).WillOnce(Return(nullptr));
    EXPECT_CALL(mockUserManager, addUser(_, username, password)).WillOnce(Return(true));

    AccountHolder *holder = bank.registerAccountHolder(name, email, phone, username, password, -1);
    ASSERT_NE(holder, nullptr);

    Account *account = bank.createAccount(holder, AccountType::CURRENT_ACCOUNT);
    account->setAccountNumber(987654321);

    users.push_back(holder);
    EXPECT_CALL(mockUserManager, getAllUsers()).WillRepeatedly(ReturnRef(users));

    int userId = bank.getUserIdByAccount(account);
    EXPECT_EQ(userId, holder->getUserId());

    users.pop_back();
}

TEST_F(BankTest, WhenRemoveAccountWithValidUserIdAndAccountNumber_ThenReturnTrue)
{
    AccountHolder holder{AccountHolderInfo{10004, "Yash Singh", Role::ACCOUNT_HOLDER, "yash@gmail.com", "9876543210"}};
    Account *account = bank.createAccount(&holder, AccountType::SAVING_ACCOUNT);
    account->setAccountNumber(123789456);
    holder.addAccount(account);

    users.push_back(&holder);

    EXPECT_CALL(mockUserManager, getUserById(10004)).WillOnce(Return(&holder));
    
    EXPECT_CALL(mockUserManager, getAllUsers()).WillRepeatedly(ReturnRef(users));

    EXPECT_TRUE(bank.removeAccount(10004, 123789456));

    users.pop_back();
}
