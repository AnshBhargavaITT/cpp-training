#include<iostream>

void processValue(int&& rValue)
{
    std::cout<<rValue<<std::endl;
}
int main()
{
    processValue(40);
    return 0;
}