#include<iostream>

template<typename T>
void printIdAndValue(T value)
{
    static int id{0};
    std::cout<<id++<<" "<<value<<std::endl;
}

template<>
void printIdAndValue<double>(double value)
{
    static int id{0};
    std::cout<<++id<<" "<<value<<std::endl;
}

int main()
{
    printIdAndValue<int>(5);
    printIdAndValue<int>(7);
    printIdAndValue<double>(4.123);
}

// printIDAndValue<int> and printIDAndValue<double> each have their own independent 
// static local variable named id, not one that is shared between them.

