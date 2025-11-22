#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include <string>

class AccountHolder {
    std::string name;
    int balance;

public:
    AccountHolder(const std::string& name, int initial_balance);
    
    std::string getName() const;
    int getBalance() const;
    void deposit(int amount);
    bool withdraw(int amount);
};

#endif
