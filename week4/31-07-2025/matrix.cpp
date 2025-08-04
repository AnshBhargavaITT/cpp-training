#include<iostream>
#include "matrix.h"

void Matrix::createMatrix() 
{
    matrix = new int *[rows];
    for (int rowIteratorI = 0; rowIteratorI < rows; rowIteratorI++)
    {
        *(matrix + rowIteratorI) = new int[columns];
    }
}

void Matrix::freeMatrix() 
{
    for (int rowIteratorI = 0; rowIteratorI < rows; rowIteratorI++)
    {
        delete[] *(matrix + rowIteratorI);
    }
    delete[] matrix;
}

void Matrix::inputMatrix() 
{
    std::cout << "Enter matrix elements :"<<std::endl;
    for (int rowIteratorI = 0; rowIteratorI < rows; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < columns; columnIteratorJ++)
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

void Matrix::printMatrix()
{
    for (int rowIteratorI = 0; rowIteratorI < rows; rowIteratorI++)
    {
        for (int columnIteratorJ = 0; columnIteratorJ < columns; columnIteratorJ++)
        {
            std::cout << *(*(matrix + rowIteratorI) + columnIteratorJ) << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::addMatrix(const Matrix& matrixTwo) 
{
    Matrix result(this->rows, this->columns);
    for (int rowIteratorI = 0; rowIteratorI < this->rows;rowIteratorI++ )
    {
        for (int columnIteratorJ= 0; columnIteratorJ < this->columns; columnIteratorJ++)
        {
            *(*(result.matrix + rowIteratorI) + columnIteratorJ) = *(*(this->matrix + rowIteratorI) + columnIteratorJ) + *(*(matrixTwo.matrix + rowIteratorI) + columnIteratorJ);
        }
    }
        
    return result;
}

Matrix Matrix::multiplyMatrix(const Matrix& matrixTwo)
{
    Matrix result(this->rows, matrixTwo.columns);
    for(int rowIteratorI=0;rowIteratorI<this->rows;rowIteratorI++)
    {
        for(int columnIteratorJ=0;columnIteratorJ<matrixTwo.columns;columnIteratorJ++)
        {
            *(*(result.matrix + rowIteratorI) + columnIteratorJ)=0;
            for(int iteratorK=0;iteratorK<this->columns;iteratorK++)
            {
                *(*(result.matrix + rowIteratorI) + columnIteratorJ)+= (*(*(this->matrix + rowIteratorI) + iteratorK) ) * (*(*(matrixTwo.matrix + iteratorK) + columnIteratorJ));
            }
        }
    }
    return result;
}
