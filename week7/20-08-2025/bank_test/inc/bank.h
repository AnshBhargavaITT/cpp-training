#ifndef BANK_H
#define BANK_H

#include <vector>
#include "accountHolder.h"

class Bank {
    std::vector<AccountHolder> accounts;

public:
    void addAccount(const AccountHolder& account);
    int totalAssets() const;
    AccountHolder* findAccount(const std::string& name);
};

#endif
