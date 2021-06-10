/*Дана матрица порядка MxN(M строк, N столбцов).Необходимо заполнить ее значениями и
написать функцию, осуществляющую циклический сдвиг строк и / или столбцов массива
указанное количество раз и в указанную сторону.*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void DownShift(double** a, int n, int m, int k)
{
    double* temp;
    for (int p = 1; p <= k; p++)
    {
        temp = a[n - 1];
        for (int i = n - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = temp;
    }
}

int main()
{
    srand((int)time(0));
    int n, m, k;
    cout << "n="; cin >> n;
    cout << "m="; cin >> m;

    double** a = new double* [n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 9 + 1;
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Shift k="; cin >> k;

    DownShift(a, n, m, k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    system("pause");
    return 0;
}