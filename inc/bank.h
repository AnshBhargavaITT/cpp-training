#ifndef BANK_H
#define BANK_H

#include "userManager.h"
#include "accountHolder.h"
#include "admin.h"
#include "account.h"
#include <vector>

class Bank 
{
    std::vector<Account*> accounts;
    UserManager* userManager;

public:
    Bank(UserManager* manager);

    AccountHolder* registerAccountHolder(const std::string& name,
                                         const std::string& email,
                                         const std::string& phone,
                                         const std::string& username,
                                         const std::string& password);

    Admin* registerAdmin(const std::string& name,
                         const std::string& username,
                         const std::string& password);

    Account* createAccount(AccountHolder* holder, AccountType type);

    bool closeAccount(int accountNumber);

    std::vector<Account*> getAccountsByUser(AccountHolder* holder);

    bool removeUser(int userId);
    
    User* getUser(int userId);

    const std::vector<Account*>& getAllAccounts() const;
};

#endif
