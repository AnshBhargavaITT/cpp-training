#include<iostream>
#include<fstream>
int main()
{
    std::fstream FileName;
    FileName.open("FileName",std::ios::in | std::ios::out );
    FileName.seekg(6,std::ios_base::beg);
    FileName<<"Hello World";
    char A[10];
    FileName.read(A,10);
    A[10]=0;
    std::cout<<A<<std::endl;
    return 0;
}