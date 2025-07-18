#include<iostream>
#include "add.h"
#include "subtract.h"
#include "multiply.h"
#include "division.h"

bool getValidInput(int& value) ;

int main()
{
    int numberOne, numberTwo;
    std::cout <<"Enter Input Number 1: "<<std::endl;
    if(!getValidInput(numberOne))
    {
        return 1;
    }
    std::cout <<"Enter Input Number 2: "<<std::endl;
    if(!getValidInput(numberTwo))
    {
        return 1;
    }
    std::cout<<"Addition of "<<numberOne << " and "<< numberTwo<< " : "<<addition(numberOne,numberTwo)<<std::endl;
    std::cout<<"Subtraction of "<<numberOne << " and "<< numberTwo<< " : "<<subtraction(numberOne,numberTwo)<<std::endl;
    std::cout<<"Multiplication of "<<numberOne << " and "<< numberTwo<< " : "<<multiplication(numberOne,numberTwo)<<std::endl;
    if (numberTwo == 0) 
    {
        std::cout << "Error: Cannot divide by zero" << std::endl;
    } 
    else 
    {
        std::cout << "Division of "<<numberOne << " and "<< numberTwo<< " : "<<division(numberOne, numberTwo) << std::endl;
    }
    return 0; 
}

bool getValidInput(int& value)
{
    std::cin >> value;
    if (!std::cin.fail())
    {
        return true;
    }
    std::cin.clear();                      
    std::cin.ignore(10000, '\n');          
    std::cout << "Invalid input" << std::endl;
    return false;
}