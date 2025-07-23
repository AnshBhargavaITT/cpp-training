#include<iostream>
#include "helper.h"

int sharedValue=42;
static int internalValue=100;

void printValue()
{
    std::cout<<"External Linkage :"<<sharedValue<<std::endl;
    std::cout<<"Internal Linkage :"<<internalValue<<std::endl;
}
