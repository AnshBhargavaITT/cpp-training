#include<iostream>
#include<fstream>

int main()
{
    std::fstream FileName;
    FileName.open("FileName", std::ios::out | std::ios::trunc); 
    if(!FileName)
    {
        std::cout<<"File does not exist"<<std::endl;
    }
    else
    {
        std::cout<<"File opened successfully"<<std::endl;
        FileName<<"This is a blog posted on Great Learning"<<std::endl;  
        FileName.close();   
    }
}