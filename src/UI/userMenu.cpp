#include <iostream>
#include "UI/userMenu.h"
#include <utils.h>
#include <UI/adminMenu.h>
#include <UI/accountHolderMenu.h>

UserMenu::UserMenu(Bank &bank, Authentication &auth, UserManager &userManager)
    : bank(bank), auth(auth), userManager(userManager) {}

void UserMenu::loginUser()
{
    std::string username, password;
    std::cout << "Enter Username: " << std::endl;
    std::getline(std::cin, username);
    std::cout << "Enter Password: " << std::endl;
    std::getline(std::cin, password);

    IUser *user = auth.login(username, password);

    if (!user)
    {
        std::cout << "Login failed. Invalid credentials" << std::endl;
        return;
    }

    if (user->getRole() == Role::ADMIN)
    {
        loginAdmin(static_cast<Admin *>(user));
    }
    else
    {
        loginAccountHolder(static_cast<AccountHolder *>(user));
    }
}

void UserMenu::loginAdmin(Admin *admin)
{
    AdminMenu adminMenu(bank, userManager, auth);
    bool session = true;
    while (session)
    {
        std::cout << "1. View All Accounts" << std::endl;
        std::cout << "2. Remove User" << std::endl;
        std::cout << "3. Register User" << std::endl;
        std::cout << "4. Personal Bank Account" << std::endl;
        std::cout << "5. Delete Specific Account" << std::endl;
        std::cout << "6. View All Users Registered" << std::endl;
        std::cout << "7. Logout" << std::endl;

        int choice;
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        {
            adminMenu.viewAllAccount();
            break;
        }

        case 2:
        {
            adminMenu.removeUser(admin->getUserId());
            break;
        }

        case 3:
        {
            adminMenu.registerUser();
            break;
        }

        case 4:
        {
            adminMenu.personalBankAccount(admin);
            break;
        }

        case 5:
        {
            adminMenu.deleteSpecificAccount(admin);
            break;
        }

        case 6:
        {
            adminMenu.viewAllUsers();
            break;
        }

        case 7:
            auth.logout();
            std::cout << "Logged out" << std::endl;
            session = false;
            break;

        default:
            std::cout << "Invalid option" << std::endl;
        }
    }
}

void UserMenu::loginAccountHolder(AccountHolder *holder)
{
    AccountMenu accountMenu(bank, holder);
    bool session = true;
    while (session)
    {
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. View Mini Statement" << std::endl;
        std::cout << "5. Show balance" << std::endl;
        std::cout << "6. Show all Account Numbers" << std::endl;
        std::cout << "7. Logout" << std::endl;

        int choice;
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        {
            accountMenu.createAccount();
            break;
        }

        case 2:
        {
            accountMenu.depositMoney();
            break;
        }

        case 3:
        {
            accountMenu.withdrawMoney();
            break;
        }

        case 4:
        {
            accountMenu.viewMiniStatements();
            break;
        }
        case 5:
            accountMenu.showBalance();
            break;

        case 6:
            accountMenu.showAllAccountNumbers();
            break;

        case 7:
            auth.logout();
            std::cout << "Logged out" << std::endl;
            session = false;
            break;

        default:
            std::cout << "Invalid option" << std::endl;
        }
    }
}
