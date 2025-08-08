#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include "users.h"
#include "account.h"
#include <vector>

class AccountHolder : public User
{
    std::string email;
    std::string phoneNumber;
    std::vector<Account *> accounts;

public:
    AccountHolder(int id,
                  const std::string &name,
                  const std::string &email,
                  const std::string &phone,
                  const std::string &username,
                  const std::string &password);

    bool depositToAccount(int accountNumber, double amount);

    bool withdrawFromAccount(int accountNumber, double amount);

    std::vector<Transaction *> getMiniStatement(int accountNumber);

    std::vector<int> getAccountNumbers();

    Account *getAccountDetailsByAccountNumber(int accountNumber);

    void addAccount(Account *account);

    int getUserId() const override;

    std::string getName() const override;

    std::string getUsername() const override;

    std::string getPassword() const override;

    Role getRole() const override;
};

#endif
