#include<iostream>
void incrementPointer(int* ptr)
{
    if(ptr)
    {
        (*ptr)++;
    }
}
void incrementReference(int& ref)
{
    ref++;
}

int main()
{
    int a=5;
    int b=10;
    incrementPointer(&a);
    incrementReference(b);
    std::cout << "Values after incrementation: \n";
    std::cout << "a = " << a <<std::endl;
    std::cout << "b = " << b << std::endl;
    return 0;
}