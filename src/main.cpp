#include <iostream>
#include <vector>
#include "userManager.h"
#include "bank.h"
#include "authentication.h"
#include "utils.h"
#include <UI/userMenu.h>

int main()
{
    UserManager userManager;
    Bank bank(&userManager);
    Authentication auth(&userManager);
    UserMenu usermenu(bank, auth, userManager);
    bank.registerAdmin("Ansh", "admin", "admin123");
    bool session = true;
    while (session)
    {
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            usermenu.loginUser();
            break;

        case 2:
            session = false;
            std::cout << "Exit" << std::endl;
            break;

        default:
            std::cout << "Invalid Input" << std::endl;
        }
    }
    return 0;
}
