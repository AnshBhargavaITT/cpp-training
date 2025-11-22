#include<iostream>

class Foo
{
    int x; // member initializer list
    int y{3}; // default member intializer
    int z;
    public:
    Foo(int a):x{a}
    {

    }
    void print()
    {
        std::cout<<x<<" "<<y<<" "<<z<<std::endl;
    }
};
int main()
{
    Foo foo(6);
    foo.print();
    return 0;
}