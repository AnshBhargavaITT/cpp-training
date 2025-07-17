#include<iostream>
#include<dlfcn.h>

int main()
{
    void* handle=dlopen("./libmath.so",RTLD_LAZY);
    if(!handle)
    {
        std::cout << dlerror() << std::endl;
        return 1;
    }
    int (*addition)(int,int)=(int (*)(int,int))dlsym(handle,"addition");
    int (*subtraction)(int,int)=(int (*)(int,int))dlsym(handle,"subtraction");
    int (*multiplication)(int,int)=(int (*)(int,int))dlsym(handle,"multiplication");
    int (*division)(int,int)=(int (*)(int,int))dlsym(handle,"division");
    if(!addition || !subtraction || !multiplication || !division)
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
    std::cout<<"Addition of 2 numbers : "<<addition(numberOne,numberTwo)<<std::endl;
    std::cout<<"Subtraction of 2 numbers : "<<subtraction(numberOne,numberTwo)<<std::endl;
    std::cout<<"Multiplication of 2 numbers : "<<multiplication(numberOne,numberTwo)<<std::endl;
    std::cout<<"Division of 2 numbers : "<<division(numberOne,numberTwo)<<std::endl;
    dlclose(handle);
    return 0;
}