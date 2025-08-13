#include<iostream>

void D()
{
    std::cout<<"Start D"<<std::endl;
    std::cout<<"D throwing int exception"<<std::endl;
    throw -1;
    std::cout<<"End D"<<std::endl;
}
void C()
{
    std::cout<<"Start C"<<std::endl;
    D();
    std::cout<<"End C"<<std::endl;
}
void B()
{
    std::cout<<"Start B"<<std::endl;
    try
    {
        C();
    }
    catch(double)
    {
        std::cerr << "B caught double exception" << std::endl;
    }

    try{}
    catch(int)
    {
        std::cerr<<"B caught int exception"<<std::endl;
    }
    std::cout<<"End B"<<std::endl;
}
void A()
{
    std::cout<<"Start A"<<std::endl;
    try
    {
        B();
    }
    catch(int)
    {
        std::cerr << "A catch int exception" << std::endl;
    }
    catch(double)
    {
        std::cerr<<"A caught double exception"<<std::endl;
    }
    std::cout<<"End A"<<std::endl;
}
int main()
{
    std::cout<<"Start main"<<std::endl;
    try 
    {
        A();
    }
    catch(int)
    {
        std::cout<<"Main caught int exception"<<std::endl;
    }
    std::cout<<"End Main"<<std::endl;
}