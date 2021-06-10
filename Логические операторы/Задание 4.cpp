#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");

	int capacityMax = 300, weightMax = 2000, s1, s2, weight;

	do
	{
		system("cls");

		cout << "\n ������� ���������� ����� A � B: "; cin >> s1;
		cout << "\n ������� ���������� ����� B � C: "; cin >> s2;
		cout << "\n ������� ��� �����: "; cin >> weight;
		if (weight > weightMax)
		{
			cout << "\n ������� ��� ��������! \a";
			Sleep(3000);
			return 0;
		}
		else
		{
			int q1 = 9, q2 = 7, q3 = 4, q4 = 1, rest = capacityMax;

			do
			{
				if (weight >= 1500) rest -= q1;
				else if (weight >= 1000) rest -= q2;
				else if (weight >= 500) rest -= q3;
				else rest -= q4;
				s1--;

				if (rest <= 0 && s1 == 0)
				{
					cout << "\n �� ������ ������� �������� ������� �� ������! \a";
					Sleep(3000);
					return 0;
				}
			} while (s1 > 0);

			int fuelCalculation;

			if (weight >= 1500) fuelCalculation = s2 * q1;
			else if (weight >= 1000) fuelCalculation = s2 * q2;
			else if (weight >= 500) fuelCalculation = s2 * q3;
			else fuelCalculation = s2 * q4;

			if (fuelCalculation > capacityMax)
			{
				cout << "\n �� ������ ������� �������� ������� �� ������! \a";
				Sleep(3000);
				return 0;
			}
			else if (rest > fuelCalculation) cout << "\n ���������� �� ���������. ";
			else cout << "\n ���������� ������� " << fuelCalculation - rest << " ������ �������. ";
		}

		fflush(stdin);
		cin.get();
	} while (true);
}