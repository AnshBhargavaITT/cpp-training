#include<iostream>

class Base;
class GFG
{
    public:
    void display(Base& b);
};
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
    friend void GFG::display(Base&);
};
void GFG::display(Base& b)
{
    std::cout<<b.private_var<<std::endl;
    std::cout<<b.protected_var<<std::endl;
}
int main()
{
    Base b;
    GFG g;
    g.display(b);
    return 0;
}