#include<iostream>

int main()
{
    try
    {
        throw -1.3;
    }
    catch(int value)
    {
        std::cout <<"We caught an exception with int value : " <<value << '\n';
    }
    catch(double)
    {
        std::cout<<"We caught an excepiton with double type"<<std::endl;
    }
    std::cout<<"Print everytime"<<std::endl;
    return 0;
}