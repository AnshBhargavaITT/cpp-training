#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "users.h"
#include "account.h"
#include "userInfo.h"
#include <vector>
#include <string>

class AccountHolder : public User
{
    std::string email;
    std::string phoneNumber;
    std::vector<Account *> accounts;

public:

    AccountHolder(const AccountHolderInfo &info);

    bool depositToAccount(int accountNumber, double amount);

    bool withdrawFromAccount(int accountNumber, double amount);

    std::vector<Transaction *> getMiniStatement(int accountNumber);

    std::vector<int> getAccountNumbers();

    bool deleteAccount(int accountNumber);

    Account *getAccountDetailsByAccountNumber(int accountNumber);

    void addAccount(Account *account);

    void setAccounts(const std::vector<Account *> &account);

    std::vector<Account *> getAccounts() const;

    std::string getEmail() const;

    std::string getPhoneNumber() const;

    int getUserId() const override;

    std::string getName() const override;

    Role getRole() const override;
};

#endif
