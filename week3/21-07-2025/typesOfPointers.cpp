#include<iostream>

int main()
{
    //wild pointer
    int *ptr;
    std::cout<<*ptr<<std::endl; // Segmentation fault
    std::cout<<ptr<<std::endl; // 0
    std::cout<<&ptr<<std::endl; // address of pointer : 0x7ffdf3216a70

    // null pointer
    int* ptr=NULL;
    std::cout<<*ptr<<std::endl; // Segmentation fault
    std::cout<<ptr<<std::endl; // 0
    std::cout<<&ptr<<std::endl; // address of pointer : 0x7ffdf3216a70
    return 0;

    // void pointer
    int a=10;
    void *ptr=&a; 
    // std::cout<<*ptr<<std::endl; void pointer cannot be directly dereferenced
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;

    //dangling pointer
    int* ptr=new int(5);
    delete(ptr);
    std::cout << "ptr is now a dangling pointer" << std::endl;
    return 0;    
    
    //constant pointer
    int a=20;
    int* const ptr=&a;
    std::cout<<*ptr<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;

    int b=10;
    ptr=&b; //Error :  error: assignment of read-only location ‘* ptr’
    std::cout<<*ptr<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;

    //Pointer to constant
    int a=20;
    const int*ptr=&a;
    std::cout<<*ptr<<std::endl; //20 
    std::cout<<ptr<<std::endl; // 0x7ffd182e5f98
    std::cout<<&ptr<<std::endl; // 0x7ffd182e5fa0
    int b=10;
    //*ptr=b;//Error  error: assignment of read-only location ‘* ptr’
    ptr=&b; // Work correctly
    std::cout<<*ptr<<std::endl; //10
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl; // 0x7ffd182e5fa0


    // constant pointer to constant
    const int a=10;
    const int* const ptr=&a;
    std::cout<<*ptr<<std::endl; 
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;
    const int b=20;
    *ptr=b; //Error
    std::cout<<*ptr<<std::endl; 
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;
    ptr=&b; // Error
    std::cout<<*ptr<<std::endl; 
    std::cout<<ptr<<std::endl;
    std::cout<<&ptr<<std::endl;
}