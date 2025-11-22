#include <iostream>
#include "helper.h"

int main() 
{
    printValue();          
    sharedValue = 99;     
    // std::cout << internalValue;    error: ‘internalValue’ was not declared in this scope
    int localValue = 5;           
    std::cout << "localValue = " << localValue << "\n";

    return 0;
}
