#include <iostream>
#include "matrixFunction.h"

int** createMatrix(int row, int column, const std::string& matrixName)
{
    int** matrix = new int*[row];
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        *(matrix+iteratorI) = new int[column];
    }

    std::cout << "Enter elements of " << matrixName << " : " << std::endl;
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            while(!(std::cin >> *(*(matrix+iteratorI)+iteratorJ)))
            {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout<<"Invalid Input"<<std::endl;
            }
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int row, int column)
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            std::cout <<*(*(matrix+iteratorI)+iteratorJ)<< " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int** matrix, int row)
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        delete[] *(matrix+iteratorI);
    }
    delete[] matrix;
}
