#include <iostream>  
#include <cstdlib>   

int main() 
{
    int* arr1 = (int*)malloc(5 * sizeof(int));
    if (arr1 == nullptr) 
    {
        std::cerr << "malloc failed" << std::endl;
        return 1;
    }
    std::cout << "Memory allocated using malloc:" << std::endl;
    for (int i = 0; i < 5; ++i) 
    {
        arr1[i] = i + 1;
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    int* arr2 = (int*)calloc(5, sizeof(int));
    if (arr2 == nullptr) 
    {
        std::cerr << "calloc failed" << std::endl;
        free(arr1); 
        return 1;
    }
    std::cout << "Memory allocated using calloc:" << std::endl;
    for (int i = 0; i < 5; ++i) 
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    int* arr3 = (int*)realloc(arr1, 10 * sizeof(int));
    if (arr3 == nullptr)
    {
        std::cerr << "realloc failed" << std::endl;
        free(arr1);
        free(arr2);
        return 1;
    }
    arr1 = arr3;  

    std::cout << "Memory after realloc to 10 integers:" << std::endl;
    for (int i = 5; i < 10; ++i) 
    {
        arr1[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    free(arr1);
    free(arr2);

    std::cout << "Memory freed successfully." << std::endl;

    return 0;
}
