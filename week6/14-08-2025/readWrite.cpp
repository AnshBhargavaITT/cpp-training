#include<iostream>
#include<fstream>

int main()
{
    std::fstream File;
    File.open("ReadWrite", std::ios::out);
    if(!File.is_open())
    {
        std::cerr<<"File not opened"<<std::endl;
        return 1;
    }
    File<<"Hi there , I am working on C++ \n I am performing Read Write Operation on File"<<std::endl;
    File.close();

    File.open("ReadWrite", std::ios::in | std::ios::out | std::ios::app);
    if(!File.is_open())
    {
        std::cerr<<"File not opened"<<std::endl;
        return 1;
    }
    File<<"Hi there , I am working on C++ \n I am performing Read Write Operation on File"<<std::endl;

    File.seekg(0,std::ios::beg);
    std::string line;
    while(getline(File,line))
    {
        std::cout<<line<<std::endl;
    }
    File.close();
}