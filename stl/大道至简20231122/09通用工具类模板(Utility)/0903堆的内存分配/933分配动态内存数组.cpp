#include <iostream>
#include <cstdlib>
int main()
{

    std::cout << "Enter the array size: ";
    int size;
    std::cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "\n"
                  << array[i];
    }
    std::cout << std::endl;
    delete[] array;
    return 0;
}
