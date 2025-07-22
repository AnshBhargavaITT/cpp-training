#include<iostream>
class Test
{
    int x;
    Test() // compiler error: Test::Test() is private.
    {
        x=5;
    }
};
int main()
{
    Test* t=new Test;
    std::cout<<t->x;
}