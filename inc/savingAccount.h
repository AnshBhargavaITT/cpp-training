#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"

class SavingsAccount : public Account 
{
public:
    bool withdraw(double amount) override;

    AccountType getAccountType() const override;
};

#endif
