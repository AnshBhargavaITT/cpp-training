#include<iostream>

class BankAccount 
{
    int accountNumber;
    double balance;
    static int numberOfAccounts;
    public:
    BankAccount(int accountNumber, double balance);
    void deposit(double amount);
    void withdraw(double amount);
    static int getNumberOfAccounts();
};

int BankAccount::numberOfAccounts = 0;

BankAccount::BankAccount(int accountNumber, double balance) 
{
    this->accountNumber = accountNumber;
    this->balance = balance;
    numberOfAccounts++;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::withdraw(double amount) 
{
    balance -= amount;
}

int BankAccount::getNumberOfAccounts() 
{
    return numberOfAccounts;
}

int main()
{
    BankAccount obj(123456789,4320);
    BankAccount objOne(123456789,4000);
    obj.deposit(2300);
    objOne.withdraw(1000);
    std::cout<<BankAccount::getNumberOfAccounts()<<std::endl;
    BankAccount objTwo(987654321,7000);
    std::cout<<BankAccount::getNumberOfAccounts()<<std::endl;
    return 0;
}