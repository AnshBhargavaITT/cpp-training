#include<iostream>
#include<string>

int main()
{
    std::string inputStringOne;
    std::cout<<"Enter input string 1"<<std::endl;
    std::cin>>inputStringOne;
    std::string inputStringTwo;
    std::cout<<"Enter input string 2"<<std::endl;
    std::cin>>inputStringTwo;
    std::string result=inputStringOne+" "+inputStringTwo;
    std::cout<<"Concatenated String : "<<result<<std::endl;
    return 0;
}