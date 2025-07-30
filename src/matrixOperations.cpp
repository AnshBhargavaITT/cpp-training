#include <iostream>
#include "matrixOperations.h"

int **createMatrix(int row, int column)
{
    int **matrix = new int *[row];
    for (int rowIteratorI = 0; rowIteratorI < row; rowIteratorI++)
    {
        *(matrix + rowIteratorI) = new int[column];
    }
    return matrix;
}

void inputMatrix(int **matrix, int row, int column)
{
    for (int rowIteratorI = 0; rowIteratorI < row; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < column; columnIteratorJ++)
        {
            while (!(std::cin >> *(*(matrix + rowIteratorI) + columnIteratorJ)))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid Input" << std::endl;
            }
        }
    }
}

void printMatrix(int **matrix, int row, int column)
{
    for (int rowIteratorI = 0; rowIteratorI < row; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < column; columnIteratorJ++)
        {
            std::cout << *(*(matrix + rowIteratorI) + columnIteratorJ) << " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int **matrix, int row)
{
    for (int rowIteratorI = 0; rowIteratorI < row; rowIteratorI++)
    {
        delete[] *(matrix + rowIteratorI);
    }
    delete[] matrix;
}

void addMatrix(int **matrixOne, int **matrixTwo, int **resultMatrix, int row, int column)
{
    for (int rowIteratorI = 0; rowIteratorI < row; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < column; columnIteratorJ++)
        {
            *(*(resultMatrix + rowIteratorI) + columnIteratorJ) = *(*(matrixOne + rowIteratorI) + columnIteratorJ) + *(*(matrixTwo + rowIteratorI) + columnIteratorJ);
        }
    }
}

void multiplyMatrix(int **matrixOne, int **matrixTwo, int **resultMatrix, int row1, int column1, int column2)
{
    for (int rowIteratorI = 0; rowIteratorI < row1; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < column2; columnIteratorJ++)
        {
            *(*(resultMatrix + rowIteratorI) + columnIteratorJ) = 0;
            for (int iteratorK = 0; iteratorK < column1; iteratorK++)
            {
                *(*(resultMatrix + rowIteratorI) + columnIteratorJ) += *(*(matrixOne + rowIteratorI) + iteratorK) * *(*(matrixTwo + iteratorK) + columnIteratorJ);
            }
        }
    }
}
