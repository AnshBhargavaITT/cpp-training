#include <iostream>
#include <string>

int main()
{
    std::string inputString;
    std::cout << "Enter input string" << std::endl;
    getline(std::cin, inputString);

    int length = inputString.length();
    int iteratorI = 0;
    bool sign = true; 
    double number = 0.0;
    bool isDigit = false;

    while (iteratorI < length && inputString[iteratorI] == ' ')
    {
        iteratorI++;
    }

    if (iteratorI < length && inputString[iteratorI] == '-')
    {
        sign = false;
        iteratorI++;
    }

    while (iteratorI < length && inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9')
    {
        isDigit = true;
        number = (number * 10) + (inputString[iteratorI] - '0');
        iteratorI++;
    }

    if (iteratorI < length && inputString[iteratorI] == '.')
    {
        iteratorI++;
        double fraction = 0.0;
        double divisor = 10.0;
        while (iteratorI < length && inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9')
        {
            isDigit = true;
            fraction += (inputString[iteratorI] - '0') / divisor;
            divisor *= 10.0;
            iteratorI++;
        }
        number += fraction;
    }

    if (!isDigit)
    {
        std::cout << "0" << std::endl;
        return 1; 
    }

    if (!sign)
    {
        number = -number;
    }

    std::cout << "Number: " << number << std::endl;

    return 0;
}
