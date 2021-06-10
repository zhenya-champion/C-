//Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.
//Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.

#include "pch.h"
#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 3;
struct directory {

	char name[100];
	char telefon[100];
};
directory L[N];
// поиск абонента по телефону или имени
int serch()//поиск абонента по телефону или имени

{
	char name[100];
	cout << " \n\n\nenter name jr telefon to serch\t" << endl;
	cin >> name;
	cout << " \nname jr telefon to serch\t" << name;
	int i;
	for (i = 0; i < N; i++)
	{
		if (!(strcmp(name, L[i].name))) { break; }
		if (!(strcmp(name, L[i].telefon))) { break; }
	}
	if (i == N) { cout << "\n there is no such subscriber in the directory"; return -1; }
	cout << "\n name\t" << L[i].name;

	cout << "\n enter telefon\t" << L[i].telefon;
	return i;
}
int main()

{
	char y; int num = 0;
	//////////////////////////////////////
	for (int i = 0; i < N; i++)

	{
		cout << "\n enter name\t";
		cin >> L[i].name;
		cout << "\n enter telefon\t";
		cin >> L[i].telefon;
	}

	for (int i = 0; i < N; i++)

	{
		cout << "\n  name\t" << L[i].name;

		cout << "\n enter telefon\t" << L[i].telefon;
	}
	//////////////////////////////////////////////////
	num = serch();

	while (num >= 0)
	{
		cout << "\n\nwant to change subscriber data.if yes press 'y'? if not any key\t";
		cin >> y;
		if (y == 'y' || y == 'Y')
		{
			cout << "\n enter name\t";
			cin >> L[num].name;
			cout << "\n enter telefon\t";
			cin >> L[num].telefon;
		}
		else
		{
			break;
		}
		for (int i = 0; i < N; i++)

		{
			cout << "\n  name\t" << L[i].name;

			cout << "\n enter telefon\t" << L[i].telefon;
		}
	}
	return 0;
}