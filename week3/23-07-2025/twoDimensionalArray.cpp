#include<iostream>
int main()
{
    int m, n;
    std::cout << "Enter number of rows" << std::endl;
    std::cin >> m;
    std::cout << "Enter number of columns" << std::endl;
    std::cin >> n;

    int** array = new int*[m];
    for (int i = 0; i < m; i++)
    {
        *(array + i) = new int[n];
    }

    std::cout << "Enter input values" << std::endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> *(*(array + i) + j);
        }
    }

    int** transposed = new int*[n];
    for (int i = 0; i < n; i++)
    {
        *(transposed + i) = new int[m];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(transposed + j) + i) = *(*(array + i) + j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << *(*(transposed + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] *(array + i);
    }
    delete[] array;

    for (int i = 0; i < n; i++)
    {
        delete[] *(transposed + i);
    }
    delete[] transposed;

    return 0;
}
