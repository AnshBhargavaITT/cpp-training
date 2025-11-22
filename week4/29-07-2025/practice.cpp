#include<iostream>

int main()
{
    int row,col;
    std::cin>>row>>col;
    int** ptr=new int*[row];
    for(int i=0;i<row;i++)
    {
        ptr[i]=new int[col];
    }
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            ptr[i][j] = i * col + j;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            std::cout<<ptr[i][j]<<std::endl;
    for(int i=0;i<row;i++)
    {
        delete[] ptr[i];
    }
    //delete[] ptr;
}