//Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

#include <iostream>
#include <iomanip>

void delColumn(int** pData, int pRows, int pCols, int pIndex) {
    for (int i = 0; i < pRows; i++) {
        auto newRow = new int[pCols - 1];
        int currentCol = 0;
        for (int j = 0; j < pCols; j++) {
            if (j != pIndex) {
                newRow[currentCol] = pData[i][j];
                currentCol++;
            }
        }
        delete[] pData[i];
        pData[i] = newRow;
    }
}

int main()
{
    int rows = 5;
    int cols = 5;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j;
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << std::endl;
    }

    delColumn(array, rows, cols, 3);
    cols--;
    delColumn(array, rows, cols, 1);
    cols--;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(4) << array[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    std::cin.get();
}