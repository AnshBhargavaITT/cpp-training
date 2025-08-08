#include <iostream>
#include <string>
#include "bank.h"
#include "authentication.h"

std::string getCurrentDate() 
{
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    char date[11];
    sprintf(date, "%04d-%02d-%02d",
            localTime->tm_year + 1900,
            localTime->tm_mon + 1,
            localTime->tm_mday);

    return std::string(date);
}

bool isValidEmail(const std::string& email) 
{
    const std::string suffix = "@gmail.com";
    int emailLength = email.length();
    int suffixLength = suffix.length();

    if (emailLength < suffixLength) {return false;}

    for (int iteratorI = 0; iteratorI < suffixLength; iteratorI++) 
    {
        if (email[emailLength - suffixLength + iteratorI] != suffix[iteratorI]){return false;}
    }

    return true;
}

bool isValidPhone(const std::string& phoneNumber) 
{
    if (phoneNumber.length() != 10){return false;}

    for (char phoneCharacter : phoneNumber) 
    {
        if (phoneCharacter < '0' || phoneCharacter > '9'){return false;} 
    }

    return true;
}

bool isValidName(const std::string& name) 
{
    bool hasLetter = false;

    for (char character : name) 
    {
        if ((character >= 'a' && character <= 'z') ||
            (character >= 'A' && character <= 'Z')) { hasLetter = true; } 
        else if (character != ' ') {return false; }
    }
    return hasLetter; 
}


bool isValidPassword(const std::string& password) {return password.length() >= 7;}

void clearInputBuffer() {std::cin.ignore(1000000, '\n');}


