#include "accountHolder.h"

AccountHolder::AccountHolder(const AccountHolderInfo &info)
    : User(info), email(info.email), phoneNumber(info.phoneNumber) {}

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

bool AccountHolder::deleteAccount(int accountNumber)
{
    for (std::vector<Account *>::iterator iteratorI = accounts.begin(); iteratorI != accounts.end(); iteratorI++)
    {
        if ((*iteratorI)->getAccountNumber() == accountNumber)
        {
            accounts.erase(iteratorI);
            return true;
        }
    }
    return false;
}

Account *AccountHolder::getAccountDetailsByAccountNumber(int accountNumber)
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        if (accounts[iteratorI]->getAccountNumber() == accountNumber)
        {
            return accounts[iteratorI];
        }
    }
    return nullptr;
}

void AccountHolder::setAccounts(const std::vector<Account *> &account) { accounts = account; }

std::vector<Account *> AccountHolder::getAccounts() const { return accounts; }

std::string AccountHolder::getEmail() const { return email; }

std::string AccountHolder::getPhoneNumber() const { return phoneNumber; }

int AccountHolder::getUserId() const { return userId; }

std::string AccountHolder::getName() const { return name; }

Role AccountHolder::getRole() const { return role; }
