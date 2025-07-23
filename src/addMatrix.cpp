#include <iostream>
#include "matrixFunction.h"

void addMatrices(int** matrixOne, int** matrixTwo, int** resultMatrix, int row, int column);

int main()
{
    int row1, column1, row2, column2;
    std::cout << "Enter number of rows and columns for matrix 1 : ";
    while (!(std::cin >> row1 >> column1) || row1 < 0 || column1 < 0) 
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid Input" << std::endl;
    }
    std::cout << "Enter number of rows and columns for matrix 2 : ";
    while (!(std::cin >> row2 >> column2) || row2 < 0 || column2 < 0) 
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid Input" << std::endl;
    }

    if (row1 == row2 && column1 == column2)
    {
        int** matrixOne = createMatrix(row1, column1, "Matrix 1");
        int** matrixTwo = createMatrix(row1, column1, "Matrix 2");
        int** resultMatrix = new int*[row1];
        for (int iteratorI = 0; iteratorI < row1; iteratorI++)
        {
            *(resultMatrix+iteratorI) = new int[column1];
        }
        addMatrices(matrixOne, matrixTwo, resultMatrix, row1, column1);
        std::cout << "Addition Matrix :" << std::endl;
        printMatrix(resultMatrix, row1, column1);
        freeMatrix(matrixOne, row1);
        freeMatrix(matrixTwo, row2);
        freeMatrix(resultMatrix, row1);
    }
    else
    {
        std::cout << "Matrix Addition not possible" << std::endl;
    }
    
    return 0;
}

void addMatrices(int** matrixOne, int** matrixTwo, int** resultMatrix, int row, int column)
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            *(*(resultMatrix+iteratorI)+iteratorJ) = *(*(matrixOne+iteratorI)+iteratorJ) + *(*(matrixTwo+iteratorI)+iteratorJ);
        }
    }
}
