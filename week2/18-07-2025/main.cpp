#include <iostream>
#include "mathlib.h"

int main() 
{
    int num1 = 3;
    int num2 = 4;
    std::cout << "Square of " << num1 << " is " << square(num1) << std::endl;
    std::cout << "Sum of " << num1 << "and "<<num2<<" is " << sum(num1, num2) << std::endl;
    return 0;
}