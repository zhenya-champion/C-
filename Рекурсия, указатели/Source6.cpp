//Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел,
//заполненных случайным образом, и находит позицию, с которой начинается
//последовательность из 10 чисел, сумма которых минимальна.

#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>

using namespace std;

int min10(int a[100], int n, int& p)
{
    int s = 0;
    for (int i = n; i < n + 10; ++i) s += a[i];
    cout << "n: " << n << "; s: " << s << endl;
    if (100 - n == 10)
    {
        p = n;
        return s;
    }
    else
    {
        int s1 = min10(a, n + 1, p);
        if (s <= s1)
        {
            p = n;
            return s;
        }
        else return s1;
    }
}

int main()
{
    int a[100];
    int p;

    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rnd(-100, 100);

    for (int i = 0; i < 100; ++i) a[i] = rnd(generator);
    for (int i = 0; i < 100; ++i) cout << a[i] << '\t';
    cout << endl << endl;

    min10(a, 0, p);

    cout << "Minimum position: " << p << endl << endl;

    system("pause");
}