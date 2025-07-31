#ifndef MATRIX_OPERATION
#define MATRIX_OPERATION

class Matrix 
{
    int rows;
    int columns;
    int** matrix;

    void createMatrix();
    void freeMatrix();

public:
    Matrix(int row, int column) : rows(row), columns(column) 
    {
        createMatrix();
    }

    ~Matrix() 
    {
        freeMatrix();
    }
    void inputMatrix();
    void printMatrix();
    static Matrix addMatrix(const Matrix& a, const Matrix& b);
    static Matrix multiplyMatrix(const Matrix& a, const Matrix& b);
};

#endif