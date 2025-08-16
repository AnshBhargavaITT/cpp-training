#include <iostream>
#include <UI/accountHolderMenu.h>
#include <utils.h>

AccountMenu::AccountMenu(Bank &bank, AccountHolder *holder)
    : bank(bank), holder(holder) {}

void AccountMenu::printTransactions(const std::vector<Transaction *> &transactions)
{
    std::cout << "Transactions" << std::endl;
    for (Transaction *transaction : transactions)
    {
        std::cout << transaction->getTransactionDetail() << std::endl;
    }
}

void AccountMenu::viewMiniStatements()
{
    int accountNumber = selectAccountNumber();

    if (accountNumber == -1)
        return;

    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);

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

void AccountMenu::createAccount()
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
    std::cout << "Account created . Account Number: " << account->getAccountNumber() << std::endl;
}

void AccountMenu::depositMoney()
{
    double amount;
    int accountNumber = selectAccountNumber();

    if (accountNumber == -1)
        return;

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

void AccountMenu::withdrawMoney()
{
    double amount;
    int accountNumber = selectAccountNumber();

    if (accountNumber == -1)
        return;

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

void AccountMenu::showBalance()
{
    int accountNumber = selectAccountNumber();

    if (accountNumber == -1)
        return;

    Account *account = holder->getAccountDetailsByAccountNumber(accountNumber);

    if (account)
    {
        std::cout << "Current Balance: " << account->getBalance() << std::endl;
    }
    else
    {
        std::cout << "Account not found" << std::endl;
    }
}

void AccountMenu::showAllAccountNumbers()
{
    std::vector<int> accounts = holder->getAccountNumbers();

    if (accounts.empty())
    {
        std::cout << "You have no accounts." << std::endl;
        return;
    }

    std::cout << "Your Accounts:" << std::endl;
    for (int accountNumber : accounts)
    {
        std::cout << "- Account Number: " << accountNumber << std::endl;
    }
}

int AccountMenu::selectAccountNumber()
{
    std::vector<int> accounts = holder->getAccountNumbers();

    if (accounts.empty())
    {
        std::cout << "You have no accounts" << std::endl;
        return -1;
    }

    std::cout << "Select an account:" << std::endl;

    for (int iteratorI = 0; iteratorI < accounts.size(); iteratorI++)
    {
        std::cout << iteratorI + 1 << " Account Number: " << accounts[iteratorI] << std::endl;
    }

    int choice = 0;
    std::cin >> choice;
    clearInputBuffer();

    if (choice < 1 || choice > accounts.size())
    {
        std::cout << "Invalid selection" << std::endl;
        return -1;
    }

    return accounts[choice - 1];
}