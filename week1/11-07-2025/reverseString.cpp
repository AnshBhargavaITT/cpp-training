#include<iostream>
#include<string>
void reverseString(std::string& inputString);
int main()
{
    std::string inputString;
    std::cout<<"Enter Input String"<<std::endl;
    getline(std::cin,inputString);
    std::cout<<"Reverse String :"<<std::endl;
    int length=inputString.length();
    reverseString(inputString);
    std::cout<<inputString<<std::endl;
}
void reverseString(std::string& inputString)
{
    int start=0;
    int end=inputString.length()-1;
    while(start<=end)
    {
        char temp=inputString[start];
        inputString[start]=inputString[end];
        inputString[end]=temp;
        start++;
        end--;
    }
}