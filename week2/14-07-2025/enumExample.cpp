#include<iostream>

// Improved Code Readability

// Enums group related constants together, which helps organize code.
//Automatic Value Assignment

// By default, the first enumerator has the value 0, and each subsequent enumerator is incremented by 1. 
// Easier Maintenance: Changing an enum value doesn’t require hunting through the code.

enum Week
{
    SUNDAY='abc',
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};
int main()
{
    Week week=TUESDAY;
    std::cout<<week<<std::endl;
}

// Limitation : All constants in the enum are in the global scope, which can lead to naming conflicts.

// Traditional enums are not type-safe. They are implicitly convertible to integers.

