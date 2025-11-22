#include<iostream>

class Base
{
    public:
    int n;
    void print()
    {
        std::cout<<n<<std::endl;
    }
};
class Derived:public Base
{
    public:
    void setValue()
    {
        n=22;
    }
};
int main()
{
    Derived d;
    d.setValue();
    d.print();
    return 0;
}