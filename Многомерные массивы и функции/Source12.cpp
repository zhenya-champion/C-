//Написать функцию, определяющую среднее арифметическое элементов передаваемого ей
//массива.

#include <iostream>
using namespace std;
const int SIZE = 10;
double averege(int array[][SIZE])
{
    double SUMMA = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            SUMMA += array[i][j];
    return SUMMA / (SIZE * SIZE);
}
void Print(int array[][SIZE])
{
    cout << " Array" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << array[i][j] << "\t";
        cout << endl;
    }
}
void Set(int array[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            array[i][j] = rand() % 100;
}

void main()
{
    int a[SIZE][SIZE];
    Set(a);
    Print(a);
    cout << "Average = " << averege(a) << endl;
    system("pause");
    
}