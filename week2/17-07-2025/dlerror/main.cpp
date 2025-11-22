#include<iostream>
#include<dlfcn.h>

int main()
{
    void* handle=dlopen("./liboperation.so",RTLD_LAZY);
    if(!handle)
    {
        std::cout << dlerror() << std::endl;
        return 1;
    }
    int (*add)(int,int)=(int (*)(int,int))dlsym(handle,"add");
    int (*division)(int,int)=(int (*)(int,int))dlsym(handle,"division");
    if(!add || !division)
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
    std::cout<<"Addition of 2 numbers : "<<add(numberOne,numberTwo)<<std::endl;
    std::cout<<"Division of 2 numbers : "<<division(numberOne,numberTwo)<<std::endl;
    dlclose(handle);
    return 0;
}