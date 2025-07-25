#include<iostream>
#include "matrix_operations.h"

int getInputOperation();
int main()
{
    while(true)
    {
        int operation=getInputOperation();
        if(operation==3)
        {
            std::cout << "Exit program" << std::endl;
            return 0;
        }
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
        switch(operation)
        {
            case 1:
            if (row1 == row2 && column1 == column2)
            {
                int** matrixOne = createMatrix(row1, column1);
                std::cout << "Enter elements of Matrix 1 :" << std::endl;
                inputMatrix(matrixOne,row1,column1);
                std::cout << "Enter elements of Matrix 2 :" << std::endl;
                int** matrixTwo = createMatrix(row1, column1);
                inputMatrix(matrixTwo,row1,column1);
                int** resultMatrix = createMatrix(row1,column1);
                addMatrix(matrixOne, matrixTwo, resultMatrix, row1, column1);
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
            break;
            case 2:
            if (column1 == row2)
            {
                int** matrixOne = createMatrix(row1, column1);
                std::cout << "Enter elements of Matrix 1 :" << std::endl;
                inputMatrix(matrixOne,row1,column1);
                int** matrixTwo = createMatrix(row2, column2);
                std::cout << "Enter elements of Matrix 2 :" << std::endl;
                inputMatrix(matrixTwo,row2,column2);
                int** resultMatrix = createMatrix(row1, column2);
                multiplyMatrix(matrixOne, matrixTwo, resultMatrix, row1, column1, column2);
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
            break;
            default:
            std::cout << "Invalid choice"<<std::endl;
        }
    }
    
    return 0;
}

int getInputOperation()
{
    int operation;
    std::cout << "Choose Matrix Operation : "<<std::endl;
    std::cout << "1. Matrix Addition " <<std::endl;
    std::cout << "2. Matrix Multiplication "<<std::endl;
    std::cout << "3. Exit "<<std::endl;
    std::cout << "Enter your operation : "<<std::endl;

    while (!(std::cin >> operation) || (operation < 1 || operation > 3)) 
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input"<<std::endl;
    }
    return operation;
}
