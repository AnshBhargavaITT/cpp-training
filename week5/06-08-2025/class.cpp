#include<iostream>
class Car
{
};

struct Vechile
{};

int main()
{
    Car c;
    Vechile v;
    int size=sizeof(c);
    int structSize=sizeof(v);
    std::cout<<size<<std::endl;
    std::cout<<structSize<<std::endl;
}

// Why class has size 1 bytes even it does not have any member varaibles ? (Unique Address identification)
// The primary reason for this 1-byte size is to ensure that every object, even an 
// empty one, has a unique and distinct memory address. If an empty class had a size of 
// 0 bytes, multiple instances of that class could potentially occupy the same memory
// address, making it impossible to differentiate between them. 
