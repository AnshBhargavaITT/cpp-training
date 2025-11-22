#include<iostream>
namespace first_space
{
    void func()
    {
        std::cout<<"function"<<std::endl;
    }
    int var=20;
}

int main()
{
    first_space::func(); 
    std::cout<<first_space::var<<std::endl;

    // :: scope resolution operator -> to access members of a class or namespace 
    // that might be hidden by local variables or other scopes. 
    return 0;
}