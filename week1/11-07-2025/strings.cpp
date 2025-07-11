#include<iostream>
#include<string>

int main()
{
    std::string inputString;
    std::cout<<"Enter Input String"<<std::endl;
    getline(std::cin,inputString);
    std::cout<<"String :"<<inputString<<std::endl;
    std::cout<<"Modified String :"<< inputString.erase(0, 4)<<std::endl;
}