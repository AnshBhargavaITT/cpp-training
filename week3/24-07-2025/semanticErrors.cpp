#include<iostream>

int main()
{
    5=x;  // x not declared, cannot assign a value to 5
    return "Hello"; // "hello" cannot be converted to an int
    std::cout << "Hello, world"<<std::endl; // so this never executes
}