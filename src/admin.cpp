#include "admin.h"
#include "accountHolder.h"

Admin::Admin(int id, const std::string &name, const std::string &username, const std::string &password)
{
    this->userId = id;
    this->name = name;
    this->username = username;
    this->password = password;
    this->role = Role::ADMIN;
}

int Admin::getUserId() const { return userId; }

std::string Admin::getName() const { return name; }

std::string Admin::getUsername() const { return username; }

std::string Admin::getPassword() const { return password; }

Role Admin::getRole() const { return role; }

void Admin::setAccountHolderProfile(AccountHolder *profile)
{
    accountHolderProfile = profile;
}

bool Admin::hasBankAccount() const
{
    return accountHolderProfile != nullptr;
}

AccountHolder *Admin::getAccountHolderProfile()
{
    return accountHolderProfile;
}