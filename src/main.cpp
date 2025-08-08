#include <iostream>
#include <vector>
#include "userManager.h"
#include "bank.h"
#include "authentication.h"
#include "utils.h"

void registerUser(Bank &bank, UserManager &userManager);
void registerAccountHolder(Bank &bank, UserManager &userManager);
void registerAdmin(Bank &bank, UserManager &userManager);
void loginUser(Authentication &auth, Bank &bank, UserManager &userManager);
void loginAccountHolder(AccountHolder *holder, Authentication &auth, Bank &bank);
void loginAdmin(Admin *admin, Authentication &auth, Bank &bank, UserManager &userManager);
void removeUser(Bank &bank);
void viewAllAccount(Bank &bank);
void printTransactions(const std::vector<Transaction *> &txs);
void createAccount(Bank &bank, AccountHolder *holder);
void depositMoney(AccountHolder *holder);
void withdrawMoney(AccountHolder *holder);
void showBalance(AccountHolder *holder);
void viewMiniStatements(AccountHolder *holder);
void personalBankAccount(Admin* admin, Authentication& auth, Bank& bank);

int main()
{
    UserManager userManager;
    Bank bank(&userManager);
    Authentication auth(&userManager);
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
            loginUser(auth, bank, userManager);
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

void registerUser(Bank &bank, UserManager &userManager)
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
        registerAccountHolder(bank, userManager);
        break;
    case 2:
        registerAdmin(bank, userManager);
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
    }
}

void registerAccountHolder(Bank &bank, UserManager &userManager)
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

    AccountHolder *holder = bank.registerAccountHolder(name, email, phoneNumber, username, password);
    if (holder != nullptr)
    {
        std::cout << "Account Holder registered . User ID: " << holder->getUserId() << std::endl;
    }
}

void registerAdmin(Bank &bank, UserManager &userManager)
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

void loginUser(Authentication &auth, Bank &bank, UserManager &userManager)
{
    std::string username, password;
    std::cout << "Enter Username: " << std::endl;
    std::getline(std::cin, username);
    std::cout << "Enter Password: " << std::endl;
    std::getline(std::cin, password);

    User *user = auth.login(username, password);
    if (!user)
    {
        std::cout << "Login failed. Invalid credentials" << std::endl;
        return;
    }

    if (user->getRole() == Role::ADMIN)
    {
        loginAdmin(static_cast<Admin *>(user), auth, bank, userManager);
    }
    else
    {
        loginAccountHolder(static_cast<AccountHolder *>(user), auth, bank);
    }
}

void loginAdmin(Admin *admin, Authentication &auth, Bank &bank, UserManager &userManager)
{
    bool session = true;
    while (session)
    {
        std::cout << "1. View All Accounts" << std::endl;
        std::cout << "2. Remove User" << std::endl;
        std::cout << "3. Register User" << std::endl;
        std::cout << "4. Personal Bank Account" << std::endl;
        std::cout << "5. Logout" << std::endl;

        int choice;
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        {
            viewAllAccount(bank);
            break;
        }
        case 2:
        {
            removeUser(bank);
            break;
        }
        case 3:
        {
            registerUser(bank, userManager);
            break;
        }
        case 4:
        {
            personalBankAccount(admin,auth,bank);
            break;
        }
        case 5:
            auth.logout(admin);
            std::cout << "Logged out" << std::endl;
            session = false;
            break;
        default:
            std::cout << "Invalid option" << std::endl;
        }
    }
}

void loginAccountHolder(AccountHolder *holder, Authentication &auth, Bank &bank)
{
    bool session = true;
    while (session)
    {
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. View Mini Statement" << std::endl;
        std::cout << "5. Show balance" << std::endl;
        std::cout << "6. Logout" << std::endl;

        int choice;
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        {
            createAccount(bank, holder);
            break;
        }
        case 2:
        {
            depositMoney(holder);
            break;
        }
        case 3:
        {
            withdrawMoney(holder);
            break;
        }
        case 4:
        {
            viewMiniStatements(holder);
            break;
        }
        case 5:
            showBalance(holder);
            break;
        case 6:
            auth.logout(holder);
            std::cout << "Logged out" << std::endl;
            session = false;
            break;
        default:
            std::cout << "Invalid option" << std::endl;
        }
    }
}

void printTransactions(const std::vector<Transaction *> &transactions)
{
    std::cout << "Transactions" << std::endl;
    for (Transaction *transaction : transactions)
    {
        std::cout << transaction->displayTransactionDetail() << std::endl;
    }
}

void viewMiniStatements(AccountHolder *holder)
{
    int accountNumber;
    std::cout << "Enter Account Number:" << std::endl;
    std::cin >> accountNumber;
    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);
    clearInputBuffer();
    if (account)
    {
        std::vector<Transaction *> transaction = holder->getMiniStatement(accountNumber);
        printTransactions(transaction);
    }
    else
    {
        std::cout << "Account not found" << std::endl;
    }
}
void viewAllAccount(Bank &bank)
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
            std::cout << "Account Number: " << account->accountNumber << ", Balance: " << account->balance << std::endl;
        }
    }
}

void removeUser(Bank &bank)
{
    int userId;
    std::cout << "Enter user ID to remove: " << std::endl;
    std::cin >> userId;
    clearInputBuffer();
    if (bank.removeUser(userId))
    {
        std::cout << "User removed" << std::endl;
    }
    else
    {
        std::cout << "User not found" << std::endl;
    }
}

void createAccount(Bank &bank, AccountHolder *holder)
{
    std::cout << "Select Account Type :" << std::endl;
    std::cout << "1. Current Account" << std::endl;
    std::cout << "2. Saving Account" << std::endl;
    int accountType;
    std::cin >> accountType;
    clearInputBuffer();

    if (accountType != 1 && accountType != 2)
    {
        std::cout << "Invalid account type" << std::endl;
        return;
    }

    AccountType type = (accountType == 1) ? AccountType::CURRENT_ACCOUNT : AccountType::SAVING_ACCOUNT;
    Account *account = bank.createAccount(holder, type);
    std::cout << "Account created . Account Number: " << account->accountNumber << std::endl;
}

void depositMoney(AccountHolder *holder)
{
    int accountNumber;
    double amount;
    std::cout << "Enter Account Number: " << std::endl;
    std::cin >> accountNumber;
    std::cout << "Enter Amount to Deposit: " << std::endl;
    std::cin >> amount;
    clearInputBuffer();
    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);
    if (account)
    {
        if (holder->depositToAccount(accountNumber, amount))
        {
            std::cout << "Deposited successfully" << std::endl;
        }
        else
        {
            std::cout << "Deposit failed" << std::endl;
        }
    }
    else
    {
        std::cout << "Account not found" << std::endl;
    }
}

void withdrawMoney(AccountHolder *holder)
{
    int accountNumber;
    double amount;
    std::cout << "Enter Account Number: " << std::endl;
    std::cin >> accountNumber;
    std::cout << "Enter Amount to withdraw: " << std::endl;
    std::cin >> amount;
    clearInputBuffer();
    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);
    if (account)
    {
        if (holder->withdrawFromAccount(accountNumber, amount))
        {
            std::cout << "Withdraw successfully" << std::endl;
        }
        else
        {
            std::cout << "Withdraw failed" << std::endl;
        }
    }
    else
    {
        std::cout << "Account not found" << std::endl;
    }
}

void showBalance(AccountHolder *holder)
{
    int accountNumber;
    std::cout << "Enter Account Number: " << std::endl;
    std::cin >> accountNumber;
    clearInputBuffer();

    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);
    if (account)
    {
        std::cout << "Current Balance: " << account->balance << std::endl;
    }
    else
    {
        std::cout << "Account not found" << std::endl;
    }
}

void personalBankAccount(Admin* admin, Authentication& auth, Bank& bank)
{
    AccountHolder *accountHolder = nullptr;

    if (admin->hasBankAccount())
    {
        accountHolder = admin->getAccountHolderProfile();
    }
    else
    {
        std::cout << "You don't have a personal bank account yet" << std::endl;
        std::cout << "Do you want to open bank account : ";
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
            accountHolder = bank.registerAccountHolder(
                admin->getName(), email, phoneNumber, admin->getUsername(), admin->getPassword());
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
        loginAccountHolder(accountHolder, auth, bank);
    }
}