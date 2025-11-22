#include<string>
#include "practice.h"
std::string practiceCode(const char character)
{
    if(character=='a' || character=='A')
    {
        return "Arrays";
    }
    else if(character=='s' || character=='S')
    {
        return "String";
    }
    else if(character=='q' || character=='Q')
    {
        return "Queue";
    }
    else 
    {
        return "Stack";
    }
}