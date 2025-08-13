#include<iostream>
#include<fstream>

int main()
{
    std::fstream FileName;
    FileName.open("File", std::ios::in);
    // File Open Failure
    if(!FileName.is_open())
    {
        std::cout<<"Error , Unable to open file"<<std::endl;
        return 1;
    }
    FileName.close();

    // Failure to read / write data
    std::fstream File;
    // File.open("FileName",std::ios::out | std::ios::in);
    File.open("FileName",std::ios::out);
    if(!File.is_open())
    {
        std::cout<<"Error , Unable to open file"<<std::endl;
        return 1;
    }
    //File<<"Hi there"<<std::endl;
    std::string line;
    if(!getline(File,line))
    {
        std::cout<<"Error in reading input"<<std::endl;
    }
    std::cout<<line;
    File.close();
    return 0;
}