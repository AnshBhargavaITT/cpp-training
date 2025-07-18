#include <iostream>
#include <dlfcn.h>

bool getValidInput(int& value);

int main()
{
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) 
    {
        std::cerr << dlerror() << std::endl;
        return 1;
    }

    int (*addition)(int, int) = (int (*)(int, int))dlsym(handle, "addition");
    int (*subtraction)(int, int) = (int (*)(int, int))dlsym(handle, "subtraction");
    int (*multiplication)(int, int) = (int (*)(int, int))dlsym(handle, "multiplication");
    int (*division)(int, int) = (int (*)(int, int))dlsym(handle, "division");

    if (!addition || !subtraction || !multiplication || !division) 
    {
        std::cerr << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

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

    dlclose(handle);
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