#include <iostream>
#include "matrixOperations.h"

int **getMatrixInput(int &row, int &column);
int getInputOperation(int row1, int column1, int row2, int column2);

int main()
{
    while (true)
    {
        int row1, column1, row2, column2;
        std::cout << "Enter input for Matrix 1:" << std::endl;
        int **matrixOne = getMatrixInput(row1, column1);
        std::cout << "Enter input for Matrix 2:" << std::endl;
        int **matrixTwo = getMatrixInput(row2, column2);
        int operation = getInputOperation(row1, column1, row2, column2);
        switch (operation)
        {
        case 1:
        {
            int **resultMatrix = createMatrix(row1, column1);
            addMatrix(matrixOne, matrixTwo, resultMatrix, row1, column1);
            std::cout << "Addition Matrix :" << std::endl;
            printMatrix(resultMatrix, row1, column1);
            freeMatrix(resultMatrix, row1);
            break;
        }
        case 2:
        {
            int **resultMatrix = createMatrix(row1, column2);
            multiplyMatrix(matrixOne, matrixTwo, resultMatrix, row1, column1, column2);
            std::cout << "Multiplication Matrix :" << std::endl;
            printMatrix(resultMatrix, row1, column2);
            freeMatrix(resultMatrix, row1);
            break;
        }
        case 3:
        {
            std::cout << "Exit " << std::endl;
            freeMatrix(matrixOne, row1);
            freeMatrix(matrixTwo, row2);
            return 0;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
        }
        freeMatrix(matrixOne, row1);
        freeMatrix(matrixTwo, row2);
    }
    return 0;
}

int **getMatrixInput(int &row, int &column)
{
    std::cout << "Enter number of rows and columns: " << std::endl;
    while (!(std::cin >> row >> column) || row <= 0 || column <= 0)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input" << std::endl;
    }
    int **matrix = createMatrix(row, column);
    std::cout << "Enter matrix elements:" << std::endl;
    inputMatrix(matrix, row, column);
    return matrix;
}

int getInputOperation(int row1, int column1, int row2, int column2)
{
    bool canAdd = (row1 == row2 && column1 == column2);
    bool canMultiply = (column1 == row2);

    std::cout << "Choose Matrix Operation:" << std::endl;
    if (canAdd)
    {
        std::cout << "1. Matrix Addition" << std::endl;
    }
    if (canMultiply)
    {
        std::cout << "2. Matrix Multiplication" << std::endl;
    }
    std::cout << "3. Exit" << std::endl;
    int operation;
    while (true)
    {
        std::cout << "Enter your operation: " << std::endl;
        if (!(std::cin >> operation))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input " << std::endl;
            continue;
        }
        if ((operation == 1 && canAdd) || (operation == 2 && canMultiply) || operation == 3)
        {
            break;
        }
        std::cout << "Operation not possible with given matrix size" << std::endl;
    }

    return operation;
}
