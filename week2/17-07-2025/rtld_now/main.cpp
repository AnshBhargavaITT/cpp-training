#include<iostream>
#include<dlfcn.h>

int main()
{
    void* handle=dlopen("./libcalculator.so",RTLD_NOW);
    if(!handle)
    {
        std::cout<<dlerror()<<std::endl;
        return 1;
    }
    int (*subtract)(int,int)=(int (*)(int,int))dlsym(handle,"subtract");
    int (*multiply)(int,int)=(int (*)(int,int))dlsym(handle,"multiply");
    if(!subtract || !multiply)
    {
        std::cout << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }
    int numberOne;
    int numberTwo;
    std::cout<<"Enter Input Number 1 :"<<std::endl;
    std::cin>>numberOne;
    std::cout<<"Enter Input Number 2 :"<<std::endl;
    std::cin>>numberTwo;
    std::cout<<"Subtraction of 2 numbers : "<<subtract(numberOne,numberTwo)<<std::endl;
    std::cout<<"Multiplication of 2 numbers : "<<multiply(numberOne,numberTwo)<<std::endl;
    return 0;
}