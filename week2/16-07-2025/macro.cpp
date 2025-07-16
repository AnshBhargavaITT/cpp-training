#include <iostream>

#define MACRO 1

int main()
{
    #ifdef MACRO 
    std::cout << "Macro are defined" << std::endl;
    #endif
    
    #if MACRO
    std::cout << "Macro" << std::endl;
    #endif

    return 0;
}
