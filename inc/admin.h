#ifndef ADMIN_H
#define ADMIN_H

#include "users.h"
#include "accountHolder.h"
#include "userInfo.h"

class Admin : public User
{
    AccountHolder *accountHolderProfile = nullptr;

public:
    Admin(const UserInfo &info);

    int getUserId() const override;

    std::string getName() const override;

    Role getRole() const override;

    void setAccountHolderProfile(AccountHolder *profile);

    bool hasBankAccount() const;

    AccountHolder *getAccountHolderProfile();
};

#endif
