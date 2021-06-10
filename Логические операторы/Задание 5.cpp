#include <iostream>

using namespace std;


int main()

{
	setlocale(0, "rus");
	int d, m, y, a, b, c, e, f, h = 0, x;
	int d1, m1, y1;
	int a1 = 31; //1.3.5.7.8.10.12
	int a2 = 30; //4.6.9.11.
	int a3 = 28; //2
	cout << "Введите первую дату (Д-М-Г): " << endl;
	cin >> d >> m >> y;
	cout << "Введите вторую дату (Д-М-Г): " << endl;
	cin >> d1 >> m1 >> y1;
	a = y % 4;
	if (a == 0) {
		a3++;
	}

	if (m == 1) {
		x = d;
	}
	else if (m == 2) {
		x = a1 + d;
	}
	else if (m == 3) {
		x = a1 + a3 + d;
	}
	else if (m == 4) {
		x = a1 + a3 + a1 + d;
	}
	else if (m == 5) {
		x = a1 + a3 + a1 + a2 + d;
	}
	else if (m == 6) {
		x = a1 + a3 + a1 + a2 + a1 + d;
	}
	else if (m == 7) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + d;
	}
	else if (m == 8) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + a1 + d;
	}
	else if (m == 9) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + d;
	}
	else if (m == 10) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + d;
	}
	else if (m == 11) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + a1 + d;
	}
	else if (m == 12) {
		x = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + a1 + a2 + d;
	}

	b = y1 % 4;
	if (b == 0) {
		a3++;
	}

	if (m1 == 1) {
		h = d;
	}
	else if (m1 == 2) {
		h = a1 + d;
	}
	else if (m1 == 3) {
		h = a1 + a3 + d;
	}
	else if (m1 == 4) {
		h = a1 + a3 + a1 + d;
	}
	else if (m1 == 5) {
		h = a1 + a3 + a1 + a2 + d;
	}
	else if (m1 == 6) {
		h = a1 + a3 + a1 + a2 + a1 + d;
	}
	else if (m1 == 7) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + d;
	}
	else if (m1 == 8) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + a1 + d;
	}
	else if (m1 == 9) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + d;
	}
	else if (m1 == 10) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + d;
	}
	else if (m1 == 11) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + a1 + d;
	}
	else if (m1 == 12) {
		h = a1 + a3 + a1 + a2 + a1 + a2 + a1 + a1 + a2 + a1 + a2 + d;
	}

	if (y == y1 && m == m1) {
		cout << "Количество дней: " << d1 - d << endl;
	}
	else if (y == y1 && m1 > m) {
		cout << "Количество дней: " << (d1 - d) + h << endl;
	}
	else {
		cout << "Количество дней: " << (y1 - y) * 365 + (h - x) << endl;
	}

	return 0;
}