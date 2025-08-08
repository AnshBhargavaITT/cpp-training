#include "account.h"
#include "utils.h"

Account::Account()
{
    accountNumber = 0;
    balance = 0.0;
}

Account::~Account()
{
    for (int iteratorI = 0; iteratorI < transactions.size(); iteratorI++)
    {
        delete transactions[iteratorI];
    }
}

bool Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }
    balance += amount;
    std::string currentDate = getCurrentDate();
    transactions.push_back(new Transaction(getAccountType(), amount, currentDate));
    return true;
}

std::vector<Transaction *> Account::bankStatement() { return transactions; }
