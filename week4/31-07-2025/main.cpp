#include <iostream>
#include "matrix.h"

int getInputOperation(int row1, int column1, int row2, int column2);
void getMatrixDimension(int &row,int &column);

int main() 
{
    while (true) 
    {
        int row1, column1, row2, column2;

        std::cout << "Enter rows and columns for Matrix 1 : ";
        getMatrixDimension(row1,column1);
        Matrix matrixOne(row1, column1);
        matrixOne.inputMatrix();

        std::cout << "Enter rows and columns for Matrix 2 : ";
        getMatrixDimension(row2,column2);
        Matrix matrixTwo(row2, column2);
        matrixTwo.inputMatrix();

        int operation = getInputOperation(row1,column1,row2,column2);

        switch (operation)
        {
        case 1:
        {
            Matrix result = Matrix::addMatrix(matrixOne, matrixTwo);
            std::cout << "Matrix Addition Result: "<<std::endl;
            result.printMatrix();
            break;
        }
        case 2:
        {
            Matrix result = Matrix::multiplyMatrix(matrixOne,matrixTwo);
            std::cout << "Matrix Multiplication Result: "<<std::endl;
            result.printMatrix();
            break;
        }
        case 3:
        {
            std::cout << "Exit " << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid Operation" << std::endl;
        }
    }
    return 0;
}

void getMatrixDimension(int &row,int &column)
{
    while (!(std::cin >> row>> column) || row <= 0 || column <= 0) 
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Input"<<std::endl;
    }
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