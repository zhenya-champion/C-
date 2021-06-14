//Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.
//Пользователь вводит a и b.Проиллюстрируйте работу функции примером.


#include <iostream>
using namespace std;

int summa(int a, int b)
{
	if (a == b) return b;
	else return a + summa(a + 1, b);
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	if (a > b) {
		std::swap(a, b);
	}
	cout << summa(a, b);

	return 0;
}