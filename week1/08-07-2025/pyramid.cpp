#include<iostream>
using namespace std;
int main()
{
    int numberOfLines;
    cout<<"Enter number of lines to be printed"<<endl;
    cin>>numberOfLines;
    for(int iteratorI=0;iteratorI<numberOfLines;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}