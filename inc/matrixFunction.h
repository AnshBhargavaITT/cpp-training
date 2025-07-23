#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H
#include <string>

int** createMatrix(int row, int column, const std::string& matrixName);
void printMatrix(int** matrix, int row, int column);
void freeMatrix(int** matrix, int row);

#endif
