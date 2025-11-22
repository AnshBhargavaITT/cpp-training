#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int number=1;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            cout<<number<<" ";
            number++;
        }
        cout<<endl;
    }
}