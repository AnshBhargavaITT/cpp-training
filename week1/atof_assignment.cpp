#include <iostream>
#include <string>

double parseStringToDouble(const std::string& inputString, bool& isValid);

int main()
{
    std::string inputString;
    std::cout << "Enter input string" << std::endl;
    getline(std::cin, inputString);

    bool isValidNumber = false;
    double number = parseStringToDouble(inputString, isValidNumber);

    if (!isValidNumber)
    {
        std::cout << "0" << std::endl;
        return 1;
    }

    std::cout << "Number: " << number << std::endl;
    return 0;
}

double parseStringToDouble(const std::string& inputString, bool& isValid)
{
    int length = inputString.length();
    int index = 0;
    bool isPositive = true;
    double number = 0.0;
    bool isDigit = false;

    while (index < length && inputString[index] == ' ')
    {
        index++;
    }

    if (index < length && inputString[index] == '-')
    {
        isPositive = false;
        index++;
    }
    else if(index<length && inputString[index]=='+')
    {
        index++;
    }

    while (index < length && inputString[index] >= '0' && inputString[index] <= '9')
    {
        isDigit = true;
        number = (number * 10) + (inputString[index] - '0');
        index++;
    }

    if (index < length && inputString[index] == '.')
    {
        index++;
        double fraction = 0.0;
        double divisor = 10.0;
        while (index < length && inputString[index] >= '0' && inputString[index] <= '9')
        {
            isDigit = true;
            fraction += (inputString[index] - '0') / divisor;
            divisor *= 10.0;
            index++;
        }
        number += fraction;
    }

    if (!isDigit)
    {
        isValid = false;
        return 0.0;
    }

    if (!isPositive)
    {
        number = -number;
    }

    isValid = true;
    return number;
}        

