#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "transactions.h"
#include "enums.h"

class Account
{
protected:
    int accountNumber;
    double balance;
    std::vector<Transaction *> transactions;

public:
    Account();

    virtual ~Account();

    virtual bool deposit(double amount);

    virtual bool withdraw(double amount) = 0;

    virtual std::vector<Transaction *> bankStatement();

    virtual AccountType getAccountType() const = 0;

    virtual int getAccountNumber() const;

    virtual double getBalance() const;

    virtual void setAccountNumber(int accountNumber);
};

#endif
