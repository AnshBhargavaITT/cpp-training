#include "bank.h"

void Bank::addAccount(const AccountHolder& account) 
{
    accounts.push_back(account);
}

int Bank::totalAssets() const 
{
    int total = 0;
    for (AccountHolder account : accounts) 
    {
        total += account.getBalance();
    }
    return total;
}

AccountHolder* Bank::findAccount(const std::string& name) 
{
    for (AccountHolder account  : accounts) 
    {
        if (account.getName() == name) 
        {
            return &account;
        }
    }
    return nullptr;
}
