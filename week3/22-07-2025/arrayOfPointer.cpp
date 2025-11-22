#include<iostream>

int main()
{
    int N=3;
    int** p=new int*[N];
    int x=1;
    for(int i=0;i<N;i++)
    {
        p[i]=new int[N];
        for(int j=0;j<N;j++)
        {
            p[i][j]=10*x;
            x++;
        }
    }
    std::cout<<*p<<std::endl;
    std::cout<<**p<<std::endl;
    std::cout << *p + 1 << std::endl;
    std::cout << **p + 1 << std::endl;
    std::cout << *(*(p + 1) + 0) << std::endl;
    std::cout << p[2][2] << std::endl;
}