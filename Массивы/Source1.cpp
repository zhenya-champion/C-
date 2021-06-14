//Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры
//разные


#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int k = 0;
    int i1, i2, i3;
    for (int i = 100; i <= 999; i++)
    {
        i1 = i / 100; //первая цифра
        i2 = i % 10; // третья цифра
        i3 = (i % 100) / 10; //вторая цифра
        if (i1 == i2 || i2 == i3 || i3 == i1) k++;

    }
    cout << "Result: " << k << "\n";
    system("pause");
}