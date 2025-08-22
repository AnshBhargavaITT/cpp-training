#include "savingAccount.h"
#include "utils.h"

bool SavingsAccount::withdraw(double amount)
{
    if (amount > balance) { return false; }
    if( amount <= 0) { return false;}
    balance -= amount;
    std::string currentDate = getCurrentDate();
    transactions.push_back(new Transaction(getAccountType(), -amount, currentDate));
    return true;
}

AccountType SavingsAccount::getAccountType() const { return AccountType::SAVING_ACCOUNT; }
