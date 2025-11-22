#include<iostream>
#include<fstream>

int main()
{
    std::fstream FileName;
    FileName.open("FileName",std::ios::out);
    if(FileName.is_open())
    {
        std::cout<<"File open already"<<std::endl;
    }
    else if(!FileName)
    {
        std::cout<<"Error creating new file"<<std::endl;
    }
    else
    {
        std::cout<<"File Created Successfully"<<std::endl;
        FileName.close();
    }
    return 0;
}