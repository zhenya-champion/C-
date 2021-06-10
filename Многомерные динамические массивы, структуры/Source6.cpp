/*Реализовать структуру «Автомобиль»(длина, клиренс(высота посадки), объем двигателя,
	мощность двигателя, диаметр колес, цвет, тип коробки передач).Создайте функции для задания
	значений, отображения значений, поиска значений.*/
#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 3;
struct car {

	float dlina;
	float clirenc;
	float V;
	float R;
	char color[100];
	char AT[100];
};
car avto[N];
int serch_i()
{
	int k1;
	for (k1 = 0; k1 < N; k1++)
	{

		if (!avto[k1].dlina) { break; }
	}

	return k1;
}
void print1(int i)
{

	cout << "\nenter dlina\t" << avto[i].dlina;
	cout << "\nenter clirenc\t" << avto[i].clirenc;
	cout << "\nenter V\t" << setw(12) << avto[i].V;
	cout << "\nenter R\t" << setw(12) << avto[i].R;
	cout << "\nenter color\t" << avto[i].color;
	cout << "\nenter AT\t" << avto[i].AT;
}
void enter(int i)
{
	cout << "\nenter dlina\t";
	cin >> avto[i].dlina;
	cout << "\nenter clirenc\t";
	cin >> avto[i].clirenc;
	cout << "\nenter V\t";
	cin >> avto[i].V;
	cout << "\nenter R\t";
	cin >> avto[i].R;
	cout << "\nenter color\t";
	cin >> avto[i].color;
	cout << "\nenter AT\t";
	cin >> avto[i].AT;
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		cout << "\nYour values";
		cout << "\nenter dlina\t" << avto[i].dlina;
		cout << "\nenter clirenc\t" << avto[i].clirenc;
		cout << "\nenter V\t" << setw(12) << avto[i].V;
		cout << "\nenter R\t" << setw(12) << avto[i].R;
		cout << "\nenter color\t" << avto[i].color;
		cout << "\nenter AT\t" << avto[i].AT;
	}

}

void serch(int dlina)
{
	int i;
	for (i = 0; i, N; i++)
		if (avto[i].dlina == dlina) { break; }
	print1(i);
}
int main()
{
	char k = 'y';
	int k1;

	for (int i = 0; i < N; i++)
	{
		cout << "\n      enter " << i + 1 << "car";
		enter(i);
		cout << "\n If you want to continue, press 'y' to stop input. Press any key.";
		cin >> k;
		if (k != 'y') { break; }
	}

	cout << "\n what length to search enter value ";
	cin >> k1;
	serch(k1);

	//enter(serch_i());
//print();
	return 0;
}