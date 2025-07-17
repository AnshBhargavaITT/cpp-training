#include<iostream>
#include "division.h"

extern "C" int division(int numberOne , int numberTwo)
{
    if(numberTwo==0)
    {
        std::cout << "Error: Division by zero"<<std::endl;
        return 0;
    }
    return numberOne/numberTwo;
}