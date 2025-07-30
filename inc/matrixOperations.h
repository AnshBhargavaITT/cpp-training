#ifndef MATRIXOPERATION_H
#define MATRIXOPERATION_H

int **createMatrix(int row, int column);
void inputMatrix(int **matrix, int row, int column);
void printMatrix(int **matrix, int row, int column);
void freeMatrix(int **matrix, int row);
void addMatrix(int **matrixOne, int **matrixTwo, int **resultMatrix, int row, int column);
void multiplyMatrix(int **matrixOne, int **matrixTwo, int **resultMatrix, int row1, int column1, int column2);

#endif
