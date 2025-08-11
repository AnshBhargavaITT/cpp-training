#include "accountHolder.h"

AccountHolder::AccountHolder(const UserInfo &info, 
                             const std::string &email, 
                             const std::string &phoneNumber)
    : User(info),  
      email(email),
      phoneNumber(phoneNumber){}

bool AccountHolder::depositToAccount(int accountNumber, double amount)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            return accounts[iteratorI]->deposit(amount);
        }
    }
    return false;
}

bool AccountHolder::withdrawFromAccount(int accountNumber, double amount)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            return accounts[iteratorI]->withdraw(amount);
        }
    }
    return false;
}

std::vector<Transaction *> AccountHolder::getMiniStatement(int accountNumber)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            return accounts[iteratorI]->bankStatement();
        }
    }
    return {};
}

std::vector<int> AccountHolder::getAccountNumbers()
{
    std::vector<int> account;
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        account.push_back(accounts[iteratorI]->getAccountNumber());
    }
    return account;
}

void AccountHolder::addAccount(Account *account)
{
    accounts.push_back(account);
}

Account *AccountHolder::getAccountDetailsByAccountNumber(int accountNumber)
{
    for (Account *account : accounts)
    {
        if (account->getAccountNumber() == accountNumber) { return account; }
    }
    return nullptr;
}

int AccountHolder::getUserId() const { return userId; }

std::string AccountHolder::getName() const { return name; }

std::string AccountHolder::getUsername() const { return username; }

std::string AccountHolder::getPassword() const { return password; }

Role AccountHolder::getRole() const { return role; }
