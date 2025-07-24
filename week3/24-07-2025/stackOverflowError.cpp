#include<iostream>
int counter=0;
void eatStack()
{
    std::cout<<++counter<<std::endl;
    if(counter>0)
    {
        eatStack(); 
    }
    std::cout<<"Hello World"<<std::endl;
}
int main()
{
    eatStack();
    return 0;
}