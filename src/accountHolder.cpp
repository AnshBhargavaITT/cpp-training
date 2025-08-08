#include "accountHolder.h"

AccountHolder::AccountHolder(int id, 
                             const std::string& name, 
                             const std::string& email,
                             const std::string& phone,
                             const std::string& username,
                             const std::string& password)
{
    this->userId = id;
    this->name = name;
    this->email = email;
    this->phoneNumber = phone;
    this->username = username;
    this->password = password;
    this->role = Role::ACCOUNT_HOLDER;
}

bool AccountHolder::depositToAccount(int accountNumber, double amount) 
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++) 
    {
        if (accounts[iteratorI]->accountNumber == accountNumber) 
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
        if (accounts[iteratorI]->accountNumber == accountNumber) 
        {
            return accounts[iteratorI]->withdraw(amount);
        }
    }
    return false;
}

std::vector<Transaction*> AccountHolder::getMiniStatement(int accountNumber) 
{
    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++) 
    {
        if (accounts[iteratorI]->accountNumber == accountNumber) 
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
        account.push_back(accounts[iteratorI]->accountNumber);
    }
    return account;
}

void AccountHolder::addAccount(Account* account) 
{
    accounts.push_back(account);
}

Account* AccountHolder::getAccountDetailsByAccountNumber(int accountNumber) 
{
    for (Account* account : accounts) 
    {
        if (account->accountNumber == accountNumber) 
        {
            return account;
        }
    }
    return nullptr;
}

int AccountHolder::getUserId() const {return userId;}

std::string AccountHolder::getName() const {return name;}

std::string AccountHolder::getUsername() const {return username;}

std::string AccountHolder::getPassword() const {return password;}

Role AccountHolder::getRole() const {return role;}
