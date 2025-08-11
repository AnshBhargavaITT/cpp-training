#include "bank.h"
#include "currentAccount.h"
#include "savingAccount.h"
#include "utils.h"
#include <iostream>

Bank::Bank(UserManager *manager)
{
    userManager = manager;
}

AccountHolder *Bank::registerAccountHolder(const std::string &name,
                                           const std::string &email,
                                           const std::string &phone,
                                           const std::string &username,
                                           const std::string &password)
{
    if (!isValidName(name))
    {
        std::cout << "Name must be string" << std::endl;
        return nullptr;
    }

    if (!isValidEmail(email))
    {
        std::cout << "Email must be valid" << std::endl;
        return nullptr;
    }

    if (!isValidPhone(phone))
    {
        std::cout << "Phone must be exactly 10 digits" << std::endl;
        return nullptr;
    }

    if (!isValidPassword(password))
    {
        std::cout << "Password must be min 7 characters" << std::endl;
        return nullptr;
    }

    int id = rand() % 900000 + 100000;

    User *existingUser = userManager->getUserByUsername(username);

    if (existingUser && existingUser->getRole() == Role::ACCOUNT_HOLDER)
    {
        std::cout << "Username already exists for Account Holder" << std::endl;
        return nullptr;
    }

    UserInfo info{id, name, username, password, Role::ACCOUNT_HOLDER};
    AccountHolder *holder = new AccountHolder(info, email, phone);
    userManager->addUser(holder);
    return holder;
}

Admin *Bank::registerAdmin(const std::string &name, const std::string &username, const std::string &password)
{
    if (!isValidName(name))
    {
        std::cout << "Name must be string" << std::endl;
        return nullptr;
    }

    if (!isValidPassword(password))
    {
        std::cout << "Password must be min 7 characters" << std::endl;
        return nullptr;
    }

    if (userManager->getUserByUsername(username))
    {
        std::cout << "Username already exists" << std::endl;
        return nullptr;
    }

    int id = rand() % 900000 + 100000;

    UserInfo info{id, name, username, password, Role::ADMIN};
    Admin *admin = new Admin(info);
    userManager->addUser(admin);
    return admin;
}

Account *Bank::createAccount(AccountHolder *holder, AccountType type)
{
    Account *account = nullptr;

    if (type == AccountType::CURRENT_ACCOUNT)
    {
        account = new CurrentAccount();
    }
    else
    {
        account = new SavingsAccount();
    }

    int accountNumberGenerator = rand() % 900000000 + 100000000;
    account->setAccountNumber(accountNumberGenerator);
    accounts.push_back(account);
    holder->addAccount(account);
    return account;
}

bool Bank::closeAccount(int accountNumber)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            delete accounts[iteratorI];
            accounts.erase(accounts.begin() + iteratorI);
            return true;
        }
    }
    return false;
}

std::vector<Account *> Bank::getAccountsByUser(AccountHolder *holder)
{
    std::vector<Account *> result;
    std::vector<int> userAccountNumbers = holder->getAccountNumbers();

    for (Account *account : accounts)
    {
        for (int accountNumber : userAccountNumbers)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                result.push_back(account);
                break;
            }
        }
    }
    return result;
}

bool Bank::removeUser(int userId)
{
    User *user = userManager->getUserById(userId);
    if (!user)
    {
        return false;
    }

    if (user->getRole() == Role::ADMIN)
    {
        std::cout << "Cannot remove an Admin User" << std::endl;
        return false;
    }

    if (user->getRole() == Role::ACCOUNT_HOLDER)
    {
        AccountHolder *holder = static_cast<AccountHolder *>(user);
        std::vector<Account *> accountsToRemove = getAccountsByUser(holder);
        for (Account *account : accountsToRemove)
        {
            closeAccount(account->getAccountNumber());
        }
    }

    userManager->removeUser(userId);
    return true;
}

User *Bank::getUser(int userId) { return userManager->getUserById(userId); }

const std::vector<Account *> &Bank::getAllAccounts() const { return accounts; }
