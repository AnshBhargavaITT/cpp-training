#include<iostream>
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "division.h"

int main()
{
    int numberOne;
    int numberTwo;
    std::cout<<"Enter Input Number 1 :"<<std::endl;
    std::cin>>numberOne;
    std::cout<<"Enter Input Number 2 :"<<std::endl;
    std::cin>>numberTwo;
    std::cout<<"Addition of 2 numbers : "<<addition(numberOne,numberTwo)<<std::endl;
    std::cout<<"Subtraction of 2 numbers : "<<subtraction(numberOne,numberTwo)<<std::endl;
    std::cout<<"Multiplication of 2 numbers : "<<multiplication(numberOne,numberTwo)<<std::endl;
    std::cout<<"Division of 2 numbers : "<<division(numberOne,numberTwo)<<std::endl;
}