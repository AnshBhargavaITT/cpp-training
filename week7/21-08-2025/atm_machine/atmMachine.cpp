#include<iostream>
#include<atmMachine.h>

bool ATMMachine::withdraw(int accountNumber , int amount)
{
    bool result=false;
    bank->connect();
    int availableBalance=bank->getBalance(accountNumber);
    if(availableBalance >= amount)
    {
        bank->debit(accountNumber,amount);
        result=true;
    }
    bank->disconnect();
    return result;
}

bool ATMMachine::deposit(int accountNumber , int amount)
{
    bool result=false;
    bank->connect();
    if(amount>0)
    {
        bank->credit(accountNumber,amount);
        result=true;
    }
    bank->disconnect();
    return result;
}