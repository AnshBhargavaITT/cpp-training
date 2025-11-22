#include<iostream>

void processValue(int& rValue)
{
    std::cout<<rValue<<std::endl;
}
int main()
{
    int a=40;
    processValue(a);
    return 0;
}