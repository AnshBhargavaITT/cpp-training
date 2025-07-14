#include<iostream>

// object like macro : textual replacements. 
#define PI 3.14

// function like macro 
#define SQUARE(n) (n*n)

//Chain macro 
#define LINE 3
#define WORKER LINE

int main()
{
    std::cout<<"Area of Circle : "<<PI*3*3<<std::endl;
    std::cout<<"Area of Sqaure :"<<SQUARE(4)<<std::endl;
    std::cout<<WORKER<<std::endl;
}