#include<iostream>

class Base 
{
    int private_var;
    protected:
    int protected_var;
    public:
    Base()
    {
        private_var=20;
        protected_var=40;
    };
    friend void display(Base& b);
};
void display(Base& b)
{
    std::cout<<b.private_var<<std::endl;
    std::cout<<b.protected_var<<std::endl;
}
int main()
{
    Base b;
    display(b);
    return 0;
}