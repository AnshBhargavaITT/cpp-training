#include<iostream>

class Account
{
    int balance;
    int accountNumber;
    std::string accountHolder;
    public:
    Account(int balance,int accNum,std::string accountHolder):accountHolder(accountHolder),accountNumber(accNum)
    {
        if(balance<0)
        {
            std::cout<<"Invalid initial balance"<<std::endl;
            balance=0;
        }
        else
        {
            this->balance=balance;
        }
    };
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance() const  // This means the function does not modify the object.
    {
        return balance;
    }
    void setBalance(int balance)
    {
        if(balance<0)
        {
            std::cout<<"Can't update the balance"<<std::endl;
        }
        else
        {
            this->balance=balance;
            std::cout<<"Updated balance:"<<balance<<std::endl;
        }
    }
    int getAccountNumber() const
    {
        return accountNumber;
    }
    void setAccountHolder(const std::string& name) 
    {
        accountHolder = name;
    }
};
void Account::deposit(int amount)
{
    if(amount<0)
    {
        std::cout<<"Deposit not possible"<<std::endl;
        return ;
    }
    balance+=amount;
    std::cout<<"Updated balance:"<<balance<<std::endl;
}
void Account::withdraw(int amount)
{
    if(amount<0)
    {
        std::cout<<"Withdraw not possible"<<std::endl;
        return ;
    }
    int remAmount=balance-amount;
    if(remAmount<0)
    {
        std::cout<<"Can't withdraw Amount"<<std::endl;
        return;
    }
    else
    {
        balance=remAmount;
        std::cout<<"Updated balance:"<<balance<<std::endl;
    }
}
int main()
{
    Account acc(2000,123456789,"Ram");
    int size=sizeof(acc);
    std::cout<<size<<std::endl;
    std::cout<<acc.getBalance()<<std::endl;
    std::cout<<acc.getAccountNumber()<<std::endl;
    acc.setBalance(3200);
    acc.deposit(-90);
    acc.deposit(4000);
    acc.deposit(0);
    acc.withdraw(400);
    acc.withdraw(-100);
    acc.withdraw(8000);
    return 0;
}