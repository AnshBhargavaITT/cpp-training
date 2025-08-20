#ifndef ACCOUNT_MENU_H
#define ACCOUNT_MENU_H

#include <vector>
#include "bank.h"
#include "accountHolder.h"
#include "transactions.h"

class AccountMenu
{
    Bank &bank;
    AccountHolder *holder;

    void printTransactions(const std::vector<Transaction *> &transactions);

public:
    AccountMenu(Bank &bank, AccountHolder* holder);

    void createAccount();

    void depositMoney();

    void withdrawMoney();

    void showBalance();

    void viewMiniStatements();

    void showAllAccountNumbers();

    int selectAccountNumber();
};

#endif
