#ifndef ADMIN_H
#define ADMIN_H

#include "users.h"
#include "accountHolder.h"

class Admin : public User 
{
    AccountHolder* accountHolderProfile = nullptr;
public:
    Admin(int id, 
          const std::string& name, 
          const std::string& username, 
          const std::string& password);

    int getUserId() const override;

    std::string getName() const override;

    std::string getUsername() const override;

    std::string getPassword() const override;
    
    Role getRole() const override;

    void setAccountHolderProfile(AccountHolder* profile);

    bool hasBankAccount() const;

    AccountHolder* getAccountHolderProfile();
};

#endif
