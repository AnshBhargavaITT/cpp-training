#include<iostream>

void printPattern(int,int);

int main()
{
    int n;
    std::cout << "Enter the value of n" << std::endl;
    std::cin >> n;

    if(n <= 0)
    {
        std::cout << "Invalid input : Enter a positive integer." << std::endl;
        return 1;
    }

    for(int iteratorI = 0; iteratorI < n-1; iteratorI++)
    {
        printPattern(iteratorI, n);
        std::cout << std::endl;
    }

    for(int iteratorI = 0; iteratorI < 2*n-1; iteratorI++)
    {
        if((iteratorI % 2) == 0)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << std::endl;

    for(int iteratorI = n-2; iteratorI >= 0; iteratorI--)
    {
        printPattern(iteratorI, n);
        std::cout << std::endl;
    }

    return 0;
}

void printPattern(int iteratorI, int n)
{
    for(int iteratorJ = 0; iteratorJ <= iteratorI; iteratorJ++)
    {
        if((iteratorJ % 2) == 0)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }

    int emptySpace = 2*(n-iteratorI- 1)- 1;

    for(int iteratorJ = 0; iteratorJ < emptySpace; iteratorJ++)
    {
        std::cout << " ";
    }

    for(int iteratorJ = 0; iteratorJ <= iteratorI; iteratorJ++)
    {
        if((iteratorJ % 2) == 0)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
}
