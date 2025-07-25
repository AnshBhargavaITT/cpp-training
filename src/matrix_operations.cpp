#include <iostream>
#include "matrix_operations.h"

int** createMatrix(int row, int column) 
{
    int** matrix = new int*[row];
    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        *(matrix+iteratorI) = new int[column];
    }
    return matrix;
}

void inputMatrix(int** matrix, int row, int column) 
{
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

void addMatrix(int** matrixOne, int** matrixTwo, int** resultMatrix, int row, int column)
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            *(*(resultMatrix+iteratorI)+iteratorJ) = *(*(matrixOne+iteratorI)+iteratorJ) + *(*(matrixTwo+iteratorI)+iteratorJ);
        }
    }
}

void multiplyMatrix(int** matrixOne, int** matrixTwo, int** resultMatrix, int row1, int column1, int column2)
{
    for (int iteratorI = 0; iteratorI < row1; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column2; iteratorJ++)
        {
            *(*(resultMatrix+iteratorI)+iteratorJ) = 0;
            for (int iteratorK = 0; iteratorK < column1; iteratorK++)
            {
                *(*(resultMatrix+iteratorI)+iteratorJ) += *(*(matrixOne+iteratorI)+iteratorK) * *(*(matrixTwo+iteratorK)+iteratorJ);
            }
        }
    }
}
