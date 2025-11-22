#include<iostream>

int* fun()
{
    static int x=5;
    return &x;
}
int main()
{
    // case -1 when memory pointed by pointer is deallocated , pointer becomes dangling pointer 
    int* ptr=new int(5);
    delete(ptr);
    std::cout<<"Dangling Pointer"<<std::endl;
    ptr=NULL;
    // case -2 when local variable is not static and function return a pointer to that local variable 
    int* p=fun();
    std::cout<<*p<<std::endl;
    // case-3 when variable goes out of scope the pointer pointing to that variable becomes dangling pointer
    int* pointer;
    {
        int a=5;
        pointer=&a;
    }
    std::cout<<*pointer<<std::endl;
}