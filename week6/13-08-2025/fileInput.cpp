#include<iostream>
#include<fstream>

int main()
{
    std::ifstream FileName;
    FileName.open("FileName",std::ios::in);
    std::string s;
    //FileName>>s;
    //getline(FileName,s);
    std::string line;
    while(getline(FileName,line))
    {
        std::cout<<line<<"\n";
    }
    //std::cout<<s<<std::endl;
}