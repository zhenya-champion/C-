
/*В двумерном массиве целых чисел посчитать сумму элементов : в каждой строке; в каждом
столбце; одновременно по всем строкам и всем столбцам.Оформить следующим образом :
3 5 6 7 | 21
12 1 1 1 | 15
0 7 12 1 | 20
-------------------- -
15 3 19 9 | 56*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    const int m = 7, n = 5;
    int ourMatrix[m][n] = {};
    int rowSum[m] = {};
    int columnSum[n] = {};
    int totalSum = 0;

    srand(time(NULL));
    for (int rowNum = 0; rowNum < m; rowNum++)
    {
        for (int columnNum = 0; columnNum < n; columnNum++)
        {
            ourMatrix[rowNum][columnNum] = rand() % 10;
            cout << setw(4) << ourMatrix[rowNum][columnNum] << "    ";
            rowSum[rowNum] += ourMatrix[rowNum][columnNum];
            columnSum[columnNum] += ourMatrix[rowNum][columnNum];

        }
        cout << " | " << rowSum[rowNum] << endl;
    }
    cout << "-------------------------------------" << endl;
    for (int columnNum = 0; columnNum < n; columnNum++)
    {
        cout << setw(4) << columnSum[columnNum] << "    ";
        totalSum += columnSum[columnNum];
    }
    cout << " | " << totalSum << endl;
    system("pause");
    return 0;
}