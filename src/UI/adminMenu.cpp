#include <iostream>
#include <UI/adminMenu.h>
#include <utils.h>
#include <UI/userMenu.h>

AdminMenu::AdminMenu(Bank &bank, UserManager &userManager, Authentication &auth)
    : bank(bank), userManager(userManager), auth(auth) {}

void AdminMenu::registerUser()
{
    std::cout << "Register as:" << std::endl;
    std::cout << "1. Account Holder" << std::endl;
    std::cout << "2. Admin" << std::endl;
    int choice;
    std::cin >> choice;
    clearInputBuffer();

    switch (choice)
    {
    case 1:
        registerAccountHolder();
        break;

    case 2:
        registerAdmin();
        break;

    default:
        std::cout << "Invalid choice" << std::endl;
    }
}

void AdminMenu::registerAccountHolder()
{
    std::string name, email, phoneNumber, username, password;
    std::cout << "Enter Name: " << std::endl;
    std::getline(std::cin, name);

    do
    {
        std::cout << "Enter Email: " << std::endl;
        std::getline(std::cin, email);
        if (!isValidEmail(email))
        {
            std::cout << "Invalid email" << std::endl;
        }
    } while (!isValidEmail(email));

    do
    {
        std::cout << "Enter Phone Number: " << std::endl;
        std::getline(std::cin, phoneNumber);
        if (!isValidPhone(phoneNumber))
        {
            std::cout << "Invalid phone number" << std::endl;
        }
    } while (!isValidPhone(phoneNumber));

    do
    {
        std::cout << "Enter Username: " << std::endl;
        std::getline(std::cin, username);
        if (userManager.getUserByUsername(username) != nullptr)
        {
            std::cout << "Username already exists" << std::endl;
        }
    } while (userManager.getUserByUsername(username) != nullptr);

    do
    {
        std::cout << "Enter Password: ";
        std::getline(std::cin, password);
        if (!isValidPassword(password))
        {
            std::cout << "Invalid password. Must be at least 7 characters" << std::endl;
        }
    } while (!isValidPassword(password));

    AccountHolder *holder = bank.registerAccountHolder(name, email, phoneNumber, username, password, -1);

    if (holder != nullptr)
    {
        std::cout << "Account Holder registered . User ID: " << holder->getUserId() << std::endl;
    }
}

void AdminMenu::registerAdmin()
{
    std::string name, username, password;
    std::cout << "Enter Name: " << std::endl;
    std::getline(std::cin, name);

    do
    {
        std::cout << "Enter Username: " << std::endl;
        std::getline(std::cin, username);
        if (userManager.getUserByUsername(username) != nullptr)
        {
            std::cout << "Username already exists" << std::endl;
        }
    } while (userManager.getUserByUsername(username) != nullptr);

    do
    {
        std::cout << "Enter Password: " << std::endl;
        std::getline(std::cin, password);
        if (!isValidPassword(password))
        {
            std::cout << "Invalid password" << std::endl;
        }
    } while (!isValidPassword(password));

    Admin *admin = bank.registerAdmin(name, username, password);

    if (admin != nullptr)
    {
        std::cout << "Admin registered . User ID: " << admin->getUserId() << std::endl;
    }
}

void AdminMenu::removeUser(int requesterId)
{
    int userId;
    std::cout << "Enter user ID to remove: " << std::endl;
    std::cin >> userId;
    clearInputBuffer();

    if (userId == requesterId)
    {
        std::cout << "You cannot remove your own account." << std::endl;
        return;
    }

    if (bank.removeUser(userId, requesterId))
    {
        std::cout << "User removed successfully." << std::endl;
    }
    else
    {
        std::cout << "User not found or cannot be removed." << std::endl;
    }
}

void AdminMenu::personalBankAccount(Admin *admin)
{
    AccountHolder *accountHolder = nullptr;
    UserMenu usermenu(bank, auth, userManager);

    if (admin->hasBankAccount())
    {
        accountHolder = admin->getAccountHolderProfile();
    }
    else
    {
        std::cout << "You don't have a personal bank account yet" << std::endl;
        std::cout << "Do you want to open a bank account (y/n): ";
        char option;
        std::cin >> option;
        clearInputBuffer();

        std::string email, phoneNumber;

        do
        {
            std::cout << "Enter Email: " << std::endl;
            std::getline(std::cin, email);
            if (!isValidEmail(email))
            {
                std::cout << "Invalid email" << std::endl;
            }
        } while (!isValidEmail(email));

        do
        {
            std::cout << "Enter Phone Number: " << std::endl;
            std::getline(std::cin, phoneNumber);
            if (!isValidPhone(phoneNumber))
            {
                std::cout << "Invalid phone number" << std::endl;
            }
        } while (!isValidPhone(phoneNumber));

        if (option == 'y' || option == 'Y')
        {
            Credential credential = auth.getUserManager()->getCredentialByUserId(admin->getUserId());

            accountHolder = bank.registerAccountHolder(
                admin->getName(),
                email,
                phoneNumber,
                credential.username,
                credential.password,
                admin->getUserId());

            if (accountHolder)
            {
                admin->setAccountHolderProfile(accountHolder);
                std::cout << "Account Holder profile created and linked to Admin" << std::endl;
            }
            else
            {
                std::cout << "Failed to create account holder profile" << std::endl;
            }
        }
    }

    if (accountHolder)
    {
        usermenu.loginAccountHolder(accountHolder);
    }
}

void AdminMenu::deleteSpecificAccount(Admin *admin)
{
    int userId;
    std::cout << "Enter User ID: " << std::endl;
    std::cin >> userId;
    clearInputBuffer();

    AccountHolder *holder = bank.getAccountHolderById(userId);
    if (holder == nullptr)
    {
        std::cout << "No account holder found with User ID: " << userId << std::endl;
        return;
    }

    std::vector<int> accountNumbers = holder->getAccountNumbers();

    if (accountNumbers.empty())
    {
        std::cout << "This user has no accounts." << std::endl;
        return;
    }

    std::cout << "Select an account to delete:" << std::endl;

    for (int iteratorI = 0; iteratorI < static_cast<int>(accountNumbers.size()); iteratorI++)
    {
        int accountNumber = accountNumbers[iteratorI];
        Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);
        if (account)
        {
            std::cout << iteratorI + 1 << ". Account Number: " << account->getAccountNumber() << ", Balance: " << account->getBalance() << std::endl;
        }
    }

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    clearInputBuffer();

    if (choice < 1 || choice > accountNumbers.size())
    {
        std::cout << "Invalid Choice" << std::endl;
        return;
    }

    int accountNumber = accountNumbers[choice - 1];

    if (bank.removeAccount(userId, accountNumber))
    {
        std::cout << "Account deleted successfully" << std::endl;
    }
    else
    {
        std::cout << "Failed to delete account. Please try again" << std::endl;
    }
}

void AdminMenu::viewAllAccount()
{
    const std::vector<Account *> &accounts = bank.getAllAccounts();
    if (accounts.empty())
    {
        std::cout << "No accounts found" << std::endl;
    }
    else
    {
        for (Account *account : accounts)
        {
            int userId = bank.getUserIdByAccount(account);
            std::cout << "User ID: " << userId << ", Account Number: " << account->getAccountNumber() << ", Balance: " << account->getBalance() << std::endl;
        }
    }
}

void AdminMenu::viewAllUsers()
{
    const std::vector<User *> &users = userManager.getAllUsers();
    if (users.empty())
    {
        std::cout << "No users found" << std::endl;
        return;
    }

    for (User *user : users)
    {
        std::cout << "User ID: " << user->getUserId() << ", Name: " << user->getName() << ", Role: " << (user->getRole() == Role::ADMIN ? "Admin" : "Account Holder") << std::endl;
    }
}
