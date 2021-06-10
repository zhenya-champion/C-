//Пользователь вводит число.Определить количество цифр в этом числе, посчитать их сумму и
//среднее арифметическое.Определить количество нулей в этом числе.Общение с пользователем
//организовать через меню.


#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, cp, n = 0, sum = 0, c = 0;
    //c - кол-во нулей

    cout << "Number:";
    cin >> a;
    cp = a;

    //Кол-во нулей
    while (a)
    {
        if (a % 10 == 0)
            c++;
        a /= 10;
    }
    cout << "\nКол-во нулей: " << c;

    //Среднее арифметическое
    for (n = 0; cp > 0; n++)
    {
        sum += cp % 10;
        cp /= 10;
    }
    cout << "\nКол-во цифр = " << n << " \nSum = " << sum << "\nSredn arif = " << (double)sum / n << "\n";

    system("pause");
    return 0;
}