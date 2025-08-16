#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include "bank.h"
#include "userManager.h"
#include "admin.h"
#include "authentication.h"

class AdminMenu
{
    Bank &bank;
    UserManager &userManager;
    Authentication &auth;

public:
    AdminMenu(Bank &bank, UserManager &userManager, Authentication &auth);

    void registerUser();

    void registerAccountHolder();

    void registerAdmin();

    void removeUser(int requesterId);

    void viewAllAccount();

    void personalBankAccount(Admin *admin);

    void deleteSpecificAccount(Admin *admin);

    void viewAllUsers();
};

#endif
