#include<iostream>
#include<string>

int main()
{
    std::string inputString;
    std::cout<<"Enter Input String"<<std::endl;
    getline(std::cin,inputString);
    int length=inputString.length();
    std::string maxWord="";
    int maxLength=0;
    std::string currentWord="";
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        if(inputString[iteratorI]!=' ')
        {
            currentWord+=inputString[iteratorI];
        }
        else 
        {
            if(currentWord.length()>maxLength)
            {
                maxLength=currentWord.length();
                maxWord=currentWord;
            }
            currentWord="";
        }
    }
    if (currentWord.length() > maxLength) 
    {
        maxLength = currentWord.length();
        maxWord = currentWord;
    }  

    std::cout<<"Max word : "<<maxWord<<std::endl;
    std::cout<<"Max Length : "<<maxLength<<std::endl;
    return 0;
}
