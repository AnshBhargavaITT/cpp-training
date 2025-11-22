#include "accountHolder.h"

AccountHolder::AccountHolder(const std::string& name, int initial_balance)
    : name(name), balance(initial_balance) {}

std::string AccountHolder::getName() const {
    return name;
}

int AccountHolder::getBalance() const {
    return balance;
}

void AccountHolder::deposit(int amount) {
    if (amount > 0)
    {
        balance += amount;
    }
}

bool AccountHolder::withdraw(int amount) {
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}
