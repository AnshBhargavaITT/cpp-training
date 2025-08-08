#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <string>
#include "enums.h"

class Transaction
{
    AccountType accountType;
    double amount;
    std::string date;

public:
    Transaction(AccountType type, double amount, const std::string &date);

    std::string displayTransactionDetail() const;
};

#endif
