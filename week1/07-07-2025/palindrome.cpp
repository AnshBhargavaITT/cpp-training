#include<iostream>
#include<string>
using namespace std;
int main()
{
    string inputString;
    cout<<"Enter Input String"<<endl;
    cin>>inputString;
    int length=inputString.length();
    bool isPalindrome=true;
    for(int iteratorI=0;iteratorI<length/2;iteratorI++)
    {
        if(inputString[iteratorI]!=inputString[length-iteratorI-1])
        {
            isPalindrome=false;
        }
    }
    if(isPalindrome)
    {
        cout<<"String ia Palindrome"<<endl;
    }
    else 
    {
        cout<<"String is not Palindrome"<<endl;
    }
}