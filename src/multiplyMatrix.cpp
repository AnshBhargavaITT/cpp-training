#include <iostream>
#include "matrixFunction.h"

void multiplyMatrices(int** matrixOne, int** matrixTwo, int** resultMatrix, int row1, int column1, int column2);

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

    if (column1 == row2)
    {
        int** matrixOne = createMatrix(row1, column1, "Matrix 1");
        int** matrixTwo = createMatrix(row2, column2, "Matrix 2");
        int** resultMatrix = new int*[row1];
        for (int iteratorI = 0; iteratorI < row1; iteratorI++)
        {
            *(resultMatrix+iteratorI)= new int[column2];
        }

        multiplyMatrices(matrixOne, matrixTwo, resultMatrix, row1, column1, column2);
        std::cout << "Multiplication Matrix : "<<std::endl;
        printMatrix(resultMatrix, row1, column2);
        freeMatrix(matrixOne, row1);
        freeMatrix(matrixTwo, row2);
        freeMatrix(resultMatrix, row1);
    }
    else
    {
        std::cout << "Matrix Multiplication not possible "<<std::endl;
    }

    return 0;
}

void multiplyMatrices(int** matrixOne, int** matrixTwo, int** resultMatrix, int row1, int column1, int column2)
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