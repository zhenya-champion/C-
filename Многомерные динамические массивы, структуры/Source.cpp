//Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию
#include <iostream>

int* ErasePosition(int* array_, size_t size, size_t index)
{
    int* t = new int[size - 1];
    size_t i;

    for (i = 0; i < index; i++) t[i] = array_[i];
    for (i = index + 1; i < size; i++) t[i - 1] = array_[i];

    delete[] array_;
    return t;
}
int** EraseColumn(int** array_,
    size_t sizeRow, size_t sizeColumn, size_t indexColumn)
{
    int** t = new int* [sizeRow];
    for (size_t i = 0; i < sizeRow; i++)
    {
        t[i] = new int[sizeColumn - 1];
        t[i] = ErasePosition(array_[i], sizeColumn, indexColumn);
    }

    return t;
}

int main(int argc, char* argv[])
{
    const size_t size = 3;
    int count = 1;
    int** t = new int* [size];
    for (size_t i = 0; i < size; i++)
        t[i] = new int[size];

    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            t[i][j] = count++;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            std::cout << t[i][j] << ' ';

        std::cout << std::endl;
    }

    std::cout << std::endl;

    t = EraseColumn(t, size, size, 0);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            std::cout << t[i][j] << ' ';

        std::cout << std::endl;
    }

    delete[] * t;
    delete[] t;

    return 0;
}