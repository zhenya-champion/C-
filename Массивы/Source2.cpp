//Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры
//разные
#include <iostream>
using namespace std;
int main()
{
    int n1 = 0, n2 = 0, n3 = 0;

    int count = 0;
    for (int i = 100; i <= 999; i++)
    {
        n1 = i / 100;
        n2 = (i / 10) % 10;
        n3 = i % 10;

        if (n1 != n2 && n2 != n3 && n1 != n3)
        {
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}