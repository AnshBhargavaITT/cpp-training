#include<iostream>

class Customer
{
    std::string name;
    int accountNumber;
    int balance;
    static int totalCount;
    static int totalBalance;
    public:
    // static int totalCount;
    Customer(std::string name,int accountNumber,int balance)
    {
        this->name=name;
        this->accountNumber=accountNumber;
        this->balance=balance;
        totalCount++;
        totalBalance+=balance;
    }
    void depsoit(int amount)
    {
        if(amount>0)
        {
            totalBalance+=amount;
            balance+=amount;
        }
    }
    void withdrawl(int amount)
    {
        if(amount<=balance && amount>0)
        {
            totalBalance-=amount;
            balance-=amount;
        }
    }
    static void accessCount()
    {
        std::cout<<totalCount<<std::endl;
        std::cout<<totalBalance<<std::endl;
    }
    void display()
    {
        std::cout<<totalCount<<std::endl;
    }
};
int Customer::totalCount=0;
int Customer::totalBalance=0;
int main()
{
    Customer C1("Ansh",123456789,2000);
    Customer C2("Rohit",987653215,3000);
    // C1.display();
    // C2.display();
    Customer::accessCount();
    C1.depsoit(500);
    C2.withdrawl(100);
    Customer::accessCount();
    //std::cout<<Customer::totalCount<<std::endl;
    return 0;
}