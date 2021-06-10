//Пользователь вводит целое число.Необходимо вывести все целые числа, на которое
//заданное число делиться без остатка.
#include <iostream>

using namespace std;

int main()
{
    cout << "Enter n:";
    int n;
    cin >> n;
    cout << "DIVISORS: " << endl;
    n = (n < 0) ? -n : n;

    for (int i = -n; i <= n; i++) {
        if (i == 0) continue;
        if (n % i == 0) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}