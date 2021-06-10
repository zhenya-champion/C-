
//Транспонирование матрицы – это операция, после которой столбцы прежней матрицы
//становятся строками, а строки столбцами.Напишите функцию транспонирования матрицы.
#include <iostream>
using namespace std;
// функция вывода матрицы на экран
void print(int** array, size_t n, size_t m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl << endl;
    }
}
// выделение памяти под матрицу
int** alloc_matrix(size_t n, size_t m) {
    int** array = new int* [n];
    for (size_t i = 0; i < n; ++i) {
        array[i] = new int[m];
    }
    return array;
}
void free_matrix(int** array, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;
}
int main() {
    size_t n = 5, m = 6;
    int** source = alloc_matrix(n, m);
    int** transposed = alloc_matrix(m, n);
    // заполнение исходной матрицы
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            source[i][j] = i * n + j; //
        }
    }
    cout << "source matrix: " << endl << endl;
    print(source, n, m);
    cout << endl;
    // транспонирование
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            transposed[j][i] = source[i][j];
    cout << "transposed matrix: " << endl << endl;
    print(transposed, m, n);
    cout << endl;
    free_matrix(source, n, m);
    free_matrix(transposed, m, n);
}