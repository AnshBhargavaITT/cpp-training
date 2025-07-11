#include<iostream>
#include<string>

char toUpper(char& character)
{
    if(character>='a' && character<='z')
    {
        character=character-32;
    }
    return character;
}
int main()
{
    std::string inputString;
    std::cout<<"Enter input String"<<std::endl;
    getline(std::cin,inputString);
    int length=inputString.length();
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        if(iteratorI==0 || inputString[iteratorI-1]==' ')
        {
            //inputString[iteratorI]=toupper(inputString[iteratorI]);
            inputString[iteratorI]=toUpper(inputString[iteratorI]);
        }
    }
    std::cout<<"String :"<<inputString<<std::endl;
    return 0;
}