#include "currentAccount.h"
#include "utils.h"

bool CurrentAccount::withdraw(double amount)
{
    if (amount <= 0) { return false; }
    balance -= amount;
    std::string currentDate = getCurrentDate();
    transactions.push_back(new Transaction(getAccountType(), -amount, currentDate));
    return true;
}

AccountType CurrentAccount::getAccountType() const { return AccountType::CURRENT_ACCOUNT; }
