#include<iostream>
struct Variable
{
    //int value;
    double val;
    char value;
};

// the struct itself needs to be aligned to the largest alignment requirement of its members
// In structs, padding is the space that’s added between the members to allow efficient 
// access to the data by the CPU. 

// "align" means ensuring that a data item (like a 32-bit integer) is stored at a 
// memory address that is a multiple of its size

// This is done to optimize the speed of memory access by the processor. 

// After structure padding, the memory utilization increases but the CPU cycle is reduced.

// 32-bit architecture reads 4 bytes in a single CPU cycle. For accessing the remaining 2 bytes of int, the processor needs one more CPU cycle.

int main()
{
    int size=sizeof(Variable);
    std::cout<<size<<std::endl;
    return 0;
}