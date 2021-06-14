//Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
//массив минимально возможного размера, в котором нужно собрать элементы массивов A и B,
//которые не являются общими для них, без повторений.



#include "iostream"
#include "ctime"
#include "cstdio"
#include "cstring"
#include "cstdio"
#include "cstring"
#include "cstdlib"


using namespace std;
const size_t N = 10;
typedef int T[N];

int main()
{
	int* a = 0, * b = 0, * c = 0, * res, * buf;
	int m = 0, n = 0, k = 0, index = 0;
	cout << "enter the numbers m and n, separated by a space";
	cin >> m >> n;
	a = new int[m]; b = new int[n];
	c = new int[m + n];
	cout << "\na[j]";
	for (int j = 0; j < m; j++)
	{
		a[j] = (int)((((float)rand() / (float)RAND_MAX) * 10) + 0);
		cout << "\n" << a[j] << endl;
	}

	cout << "\n b[j]";
	for (int j = 0; j < n; j++)
	{
		b[j] = (int)((((float)rand() / (float)RAND_MAX) * 10) + 0);
		cout << "\n " << b[j] << endl;
	}
	//проверяем элемента массива Б на пересечение
	for (int i = 0; i < m; i++)
	{
		k = 0;
		for (int j = 0; j < n; j++)
		{

			if (a[i] != b[j]) { k++; };
		}
		if (k == n) {
			c[index] = a[i]; index++;
		}
	}

	//проверяем элемента массива A на пересечение

	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < m; j++)
		{

			if (b[i] != a[j]) { k++; };
		}
		if (k == n) {
			c[index] = b[i]; index++;
		}
	}



	delete[]a; delete[]b;
	//Оставляем одинаковые элементы
	k = 0; int buf1 = 0;
	buf = new int[index];
	buf[buf1] = c[0];
	for (int j = 0; j < index; j++)
	{
		k = 0;
		for (int i = 0; i < index; i++)
			if (c[j] != buf[i]) { k++; }
		if (k == index) { buf1++; buf[buf1] = c[j]; }
	}



	delete[]c;
	res = new int[buf1 + 1]; cout << "\nres[i]=";
	//печатаем итоговый массив
	for (int i = 0; i <= buf1; i++)
	{
		res[i] = buf[i];
		cout << "\n" << res[i];
	}
	delete[]buf; delete[]res;

	return 0;
}