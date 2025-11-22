#include<iostream>
int main()
{
    int x=10;
    void* ptr=&x;
    int* int_ptr=(int *)ptr;
    std::cout<<*int_ptr<<std::endl;
    return 0;
}