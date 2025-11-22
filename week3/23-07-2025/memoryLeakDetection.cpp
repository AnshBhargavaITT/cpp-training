// Valgrind
#include<iostream>

int main()
{
    int* ptr=new int[10];
    return 0;
}

// Commands : 
// g++ -g -o memory_leak memoryLeakDetection.cpp
// valgrind --leak-check=full ./memory_leak
