#include<iostream>

template<typename T>
void print(T value)
{
    std::cout<<value<<std::endl;
}

template<>
void print<int>(int value)
{
    std::cout<<"Integer Value : "<<value<<std::endl;
}

template<typename T1, typename T2>
T2 square(T1 x)
{
    return x*x;
} 

int main()
{
    print(2); // Argument deduction 
    print<float>(5.4f);

    std::cout<<square<float ,int>(5.5)<<std::endl;
}