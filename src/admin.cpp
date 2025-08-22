#include "admin.h"
#include "accountHolder.h"
#include "userInfo.h"

Admin::Admin(const UserInfo &info)
    : IUser(info) {}

int Admin::getUserId() const { return userId; }

std::string Admin::getName() const { return name; }

Role Admin::getRole() const { return role; }

void Admin::setAccountHolderProfile(AccountHolder *profile) { accountHolderProfile = profile; }

bool Admin::hasBankAccount() const { return accountHolderProfile != nullptr; }

AccountHolder *Admin::getAccountHolderProfile() { return accountHolderProfile; }