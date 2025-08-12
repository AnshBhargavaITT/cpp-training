#include<iostream>

class Matrix
{
    public:
    int matrix;
    Matrix(){};
    Matrix(int m):matrix(m){};
    Matrix operator+(const Matrix& other)
    {
        return Matrix(this->matrix+other.matrix);
    }
    Matrix& operator+=(int value)
    {
        this->matrix+=value;
        return *this;
    }
    Matrix operator-(const Matrix& other)
    {
        return Matrix(this->matrix-other.matrix);
    }
    
    void* operator new(size_t size)
    {
        void* ptr=std::malloc(size);
        return ptr;
    }

    void operator delete(void *ptr)
    {
        std::free(ptr);
    }
};

int main()
{
    Matrix a(0);
    // Matrix b=a+Matrix(1);
    // std::cout<<b.matrix<<std::endl;
    a+=1;
    std::cout<<a.matrix<<std::endl;
    Matrix* matrix=new Matrix();
    delete matrix;
}