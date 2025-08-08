#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "account.h"

class CurrentAccount : public Account 
{
public:
    bool withdraw(double amount) override;
    
    AccountType getAccountType() const override;
};

#endif
