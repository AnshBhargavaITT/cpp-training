#include<iostream>

class Customer
{
    std::string name;
    int* ptr;
    public:
    Customer()
    {
        name="Ansh";
        ptr=new int;
        *ptr=10;
        std::cout<<"Constructor is called \n";
    }
    ~Customer()
    {
        delete ptr;
        std::cout<<"DeConstructor is called \n";
    }
};
int main()
{
    Customer c;
}