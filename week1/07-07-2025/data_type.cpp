#include<iostream>
#define val 10
using namespace std;
int main()
{
    int number;
    cout<<"Enter the number"<<endl;
    cin>>number;
    cout<< number<<endl;
    char character;
    cout<<"Enter the character"<<endl;
    cin>>character;
    cout<<character<<endl;
    float num;
    cout<<"Enter the number"<<endl;
    cin>>num;
    cout<<num<<endl;
    auto ch='a';
    cout<<ch<<endl;
    double inputNumber;
    cout<<"Enter the number"<<endl;
    cin>>inputNumber;
    cout<<inputNumber<<endl;

    cout<<val<<endl;

    const float floatVal=5.4f;
    // floatVal=5.5f; // Error 
    cout<<floatVal<<endl;

    // Implicit Type Casting
    int inputNum=25;
    float floatInputNum=inputNum;
    cout<<floatInputNum<<endl;
    
    // Explicit Type Casting 
    float floatNumber=25.9f;
    int intNumber=(int)floatNumber;
    cout<<intNumber<<endl;
}