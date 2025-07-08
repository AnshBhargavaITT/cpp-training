#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int iteratorI=0;iteratorI<n-1;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            if((iteratorJ%2)==0)
            {
                cout<<"1";
            }
            else 
            {
                cout<<"0";
            }
        }
        int emptySpace=2*(n-iteratorI-1)-1;
        for(int iteratorJ=0;iteratorJ<emptySpace;iteratorJ++)
        {
            cout<<" ";
        }
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            if((iteratorJ%2)==0)
            {
                cout<<"1";
            }
            else 
            {
                cout<<"0";
            }
        }
        cout<<endl;
    }
    for(int iteratorI=0;iteratorI<(2*n-1);iteratorI++)
    {
        if((iteratorI%2)==0)
        {
            cout<<"1";
        }
        else 
        {
            cout<<"0";
        }
    }
    cout<<endl;
    for(int iteratorI=n-2;iteratorI>=0;iteratorI--)
    {
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            if((iteratorJ%2)==0)
            {
                cout<<"1";
            }
            else 
            {
                cout<<"0";
            }
        }
        int emptySpace=2*(n-iteratorI-1)-1;
        for(int iteratorJ=0;iteratorJ<emptySpace;iteratorJ++)
        {
            cout<<" ";
        }
        for(int iteratorJ=0;iteratorJ<=iteratorI;iteratorJ++)
        {
            if((iteratorJ%2)==0)
            {
                cout<<"1";
            }
            else 
            {
                cout<<"0";
            }
        }
        cout<<endl;
    }
}