#include<iostream>
#include<utility>

void processValue(int&& value)
{
    std::cout<<value<<std::endl;
}
int main()
{
    int x=42;
    processValue(std::move(x)); // Cast x (lvalue) into an rvalue
    std::cout<<x<<std::endl;
    return 0;
}