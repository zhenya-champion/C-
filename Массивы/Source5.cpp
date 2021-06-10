//Пользователь вводит целое число А.Программа должна определить, что куб суммы
//цифр этого числа равен А* А
#include<iostream>

#include<cmath>

using namespace std;

int main()

{

	int a, sum = 0;

	cin >> a;

	for (int b = a; b > 0; b /= 10)

	{

		sum += b % 10;

	}

	if (sum * sum * sum == a * a) cout << "Podhodit" << endl;

	else cout << "Ne podhodit" << endl;

	return 0;

}