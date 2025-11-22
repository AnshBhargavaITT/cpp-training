#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double inputNumberOne;
    double inputNumberTwo;
    cout<<"Enter operand 1"<<endl;
    cin>>inputNumberOne;
    cout<<"Enter operand 2"<<endl;
    cin>>inputNumberTwo;
    char inputOperator;
    cout<<"Enter Operator"<<endl;
    cin>>inputOperator;
    double result;
    switch(inputOperator)
    {
        case '+':
        result=inputNumberOne+inputNumberTwo;
        break;
        case '-':
        result=inputNumberOne-inputNumberTwo;
        break;
        case '*':
        result=inputNumberOne*inputNumberTwo;
        break;
        case '/':
        if (inputNumberTwo == 0) 
        {
            cout << "Error: Division by zero" << endl;
            return 1;
        }
        result=inputNumberOne/inputNumberTwo;
        break;
        case '%':
        if (inputNumberTwo == 0) 
        {
            cout << "Error: Modulo by zero" << endl;
            return 1;
        }
        result=fmod(inputNumberOne,inputNumberTwo);
        break;
        default:
        cout<<"Invalid Operator"<<endl;
        return 1;
    }
    cout<<"Result is :"<<result<<endl;
    return 0;

}