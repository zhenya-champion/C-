//"Динамические массивы"

/*Написать программу, в которой создаются динамические массивы
и  выполнить их обработку в соответствии со своим вариантом.*/

/*Сформировать двумерный массив.Удалить из него столбец с заданным номером.*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(NULL));
    size_t CountRows = 4, CountCol = 4;
    int** arr = new int* [CountRows];
    for (size_t i = 0; i < CountRows; i++)
        arr[i] = new int[CountCol];
    std::cout << "Array: \n";
    for (size_t i = 0; i < CountRows; i++) {
        for (size_t j = 0; j < CountCol; j++)
            std::cout << std::setw(5) << (arr[i][j] = rand() % 20 - 10);
        std::cout << std::endl;
    }
    size_t NumberDeleteCol;
    std::cout << "\n Enter the number of the column to remove: ";
    std::cin >> NumberDeleteCol;
    for (size_t j = NumberDeleteCol; j < CountCol - 1; j++) {
        for (size_t i = 0; i < CountRows; i++)
            arr[i][j] = arr[i][j + 1];
    }
    CountCol--;
    std::cout << "\nNew array: \n";
    for (size_t i = 0; i < CountRows; i++) {
        for (size_t j = 0; j < CountCol; j++)
            std::cout << std::setw(5) << arr[i][j];
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}