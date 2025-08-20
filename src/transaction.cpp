#include "transactions.h"

Transaction::Transaction(AccountType type, double amount, const std::string &date)
    : accountType(type), amount(amount), date(date) {}

std::string Transaction::getTransactionDetail() const
{
    return "Date: " + date + ", Amount: " + std::to_string(amount);
}
