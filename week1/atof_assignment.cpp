#include <iostream>
#include <string>
#include <cmath>

int extraWhiteSpace(const std::string& inputString, int index);
void integerPart(const std::string& inputString, int& index, double& number, bool& isDigit);
void fractionPart(const std::string& inputString, int& index, double& number, bool& isDigit);
void exponentPart(const std::string& inputString, int& index, double& number);
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
        std::cout << "0.0" << std::endl;
        return 1;
    }

    std::cout << "Number: " << number << std::endl;
    return 0;
}

int extraWhiteSpace(const std::string& inputString, int index)
{
    int length = inputString.length();
    while (index < length && inputString[index] == ' ')
    {
        index++;
    }
    return index;
}

void integerPart(const std::string& inputString, int& index, double& number, bool& isDigit)
{
    int length = inputString.length();
    while (index < length && inputString[index] >= '0' && inputString[index] <= '9')
    {
        isDigit = true;
        number = (number * 10) + (inputString[index] - '0');
        index++;
    }
}

void fractionPart(const std::string& inputString, int& index, double& number, bool& isDigit)
{
    int length = inputString.length();
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
}

void exponentPart(const std::string& inputString, int& index, double& number)
{
    int length = inputString.length();
    if (index < length && (inputString[index] == 'e' || inputString[index] == 'E'))
    {
        index++;
        bool expPositive = true;
        if (index < length && (inputString[index] == '+' || inputString[index] == '-'))
        {
            if (inputString[index] == '-')
            {
                expPositive = false;
            }
            index++;
        }

        int exponent = 0;

        while (index < length && inputString[index] >= '0' && inputString[index] <= '9')
        {
            exponent = (exponent * 10) + (inputString[index] - '0');
            index++;
        }

        if (!expPositive)
        {
            exponent = -exponent;
        }

        number *= pow(10.0, exponent);
    }

}

double parseStringToDouble(const std::string& inputString, bool& isValid)
{
    int length = inputString.length();
    int index = 0;
    bool isPositive = true;
    double number = 0.0;
    bool isDigit = false;

    index = extraWhiteSpace(inputString, index);

    if (index < length && inputString[index] == '-')
    {
        isPositive = false;
        index++;
    }
    else if (index < length && inputString[index] == '+')
    {
        index++;
    }

    integerPart(inputString, index, number, isDigit);
    fractionPart(inputString, index, number, isDigit);
    exponentPart(inputString, index, number);

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
