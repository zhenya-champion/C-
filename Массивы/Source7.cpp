//Пользователь вводит два целых числа.Необходимо вывести все целые числа, на
//которые оба введенных числа делятся без остатка.
#include <iostream>
using namespace std;

int main()
{
    cout << "please enter two integers: ";
    int a, b, l;
    cin >> a >> b;
    if (a > b)
        l = a;
    else
        l = b;
    for (int i = 1; i <= l; i++)
        if (a % i == 0 && b % i == 0)
            cout << i << endl;
    return 0;
}