//Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) и
//вычисляет разность в днях между этими датами.Для решения этой задачи необходимо также
//написать функцию, которая определяет, является ли год високосным.

#include <iostream>
using namespace std;

bool vys(int year)
{
    bool res = false;
    if (year % 4 == 0)
        res = true;
    if (year % 100 == 0)
        res = false;
    if (year % 400 == 0)
        res = true;
    return res;
}
int date(int d, int m, int y)
{
    int k = d;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: if (vys(y)) k += 29; else k += 28;
    case  1: k += 31;
    }
    k += (y - 1) * 365 + ((y - 1) / 4);
    return k;
}
int difference(int d1, int d2, int m1, int m2, int y1, int y2)
{
    int k = date(d1, m1, y1) - date(d2, m2, y2);
    return k;
}
int main()
{
    int d1, d2, m1, m2, y1, y2;
    cout << "Input first day: ";
    cin >> d2;
    cout << "Input first month: ";
    cin >> m2;
    cout << "Input first year: ";
    cin >> y2;
    cout << "Input second day: ";
    cin >> d1;
    cout << "Input second month: ";
    cin >> m1;
    cout << "Input second year: ";
    cin >> y1;
    cout << "Raznica mejdu dvumya datami sostavlyaet " << difference(d1, d2, m1, m2, y1, y2) << " dney\n";
    system("PAUSE");
}
