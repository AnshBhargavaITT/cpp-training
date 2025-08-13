#include<iostream>

int main()
{
    try
    {
        throw 4.5;
        std::cout<<"Never prints";
    }
    catch(double value)
    {
        std::cout <<"Double Value : "<< value << std::endl;
    }
    return 0;
}