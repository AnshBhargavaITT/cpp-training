#ifndef USER_MENU_H
#define USER_MENU_H

#include "bank.h"
#include "authentication.h"
#include "userManager.h"
#include "accountHolder.h"
#include "admin.h"

class UserMenu 
{
    Bank& bank;
    Authentication& auth;
    UserManager& userManager;

public:

    UserMenu(Bank& bank, Authentication& auth, UserManager& userManager);

    void loginUser(); 

    void loginAdmin(Admin* admin);

    void loginAccountHolder(AccountHolder* holder);
};

#endif
