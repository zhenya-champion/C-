/*Реализовать структуру «Машина»(цвет, модель, номер).Номер машины может представлять из
себя или пятизначный номер или слово до 8 символов.
Рекомендации: номер реализовать как объединение.*/

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];

union MyUn
{
	char h[7];
	int i;
};
MyUn number;

int main()
{
	cout << "\n enter number\t";
	cin >> number.h;

	cout << number.i;
	return 0;
}

/*Создать экземпляр структуры «Машина» и реализовать для него следующие функции :
Заполнение машины
Печать машины*/

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];

union MyUn
{
	char h[7];
	int i;
};
MyUn number[N];

struct avto
{
	MyUn number[N];
	char color[100];
	char model[100];
	int flag;
};
avto myavto[N];

void liun() //заполнение нулями
{
	for (int t = 0; t < N; t++)
		myavto[t].number[t].h[0] = '\0';
}
//функция strlen
int StringToNumber(char* str)//функция strlen
{
	int k1 = 0;
	while (str[k1])
	{
		k1++;

	}
	return k1;
}
//функция конвертирует строку в число и возвращает это число
int StringToNumber1(char* str)//функция конвертирует строку в число и возвращает это число
{
	char A[10]; int k = 0; int d = 0; int res = 0;
	for (char i = '0'; i <= '9'; i++)
	{
		A[k] = i;
		k++;

	}
	d = StringToNumber(str);
	for (int i = d, k = 0; i >= 0; i--)
		for (int j = 0; j < 10; j++)
			if (str[i] == A[j]) { res = res + j * pow(10, k); k++; }

	return res;
}
//выбор меню, проверка выбора, через функцию strchr

char menu()//выбор меню, проверка выбора, через функцию strchr
{
	char ch;
	do {

		cout << "\n enter'q' Edit car";
		cout << "\n enter'e' Print all cars";
		cout << "\n enter'u' Search for cars by number";
		cout << "\n'z' if you want to exit the program press space";
		cout << endl;
		cin >> ch;
		if (ch == 'z') { return ch; }
	} while (!strchr("euq ", tolower(ch)));
	return ch;
}

// ввод n ой машины
void enter(int n)
{
	int i;
	do
	{
		cout << "\n Enter the number: if the number? then select 1, if characters select 2\t";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].i;

			break;
		case 2:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].h;

			break;
		default:
			break;
		}

	} while (!(i == 1 || i == 2));

	cout << "\nenter color\t";
	cin >> myavto[n].color;
	cout << "\nenter model\t";
	cin >> myavto[n].model;
	myavto[n].flag = i;
}
// печать n ой машины

void print(int n)
{

	cout << "\n YOUR CARS\t";
	cout << "\n Your value number\t";

	if (myavto[n].flag == 1) { cout << myavto[n].number[n].i; }
	else
	{
		cout << myavto[n].number[n].h;
	}
	cout << "\n Your value color\t" << myavto[n].color;
	cout << "\n Your value model\t" << myavto[n].model;
}

//фукция поиска по номеру машины через функцию strcmp
void Search_number()
{
	char name[100]; char* a; int ai;
	cout << "\nenter number cars to search";
	cin >> (name);
	a = name;
	ai = StringToNumber1(name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, myavto[t].number[t].h) || ai == myavto[t].number[t].i)) { break; }
	if (t == N) { cout << "\nno such book"; }
	else
	{
		print(t);
	}
}

int main()
{
	char choice; char vyxod = 'a'; int a;
	liun();
	for (int n = 0; n < N; n++)
	{
		enter(n);
	}

	/*
	do {

		choice = menu();// выбор действия которое необходимо провести

		switch (choice)
		{
		case 'e':
			for( int n=0; n<N;n++)
			print(n);

			break;

		case 'u':

			break;
		case 'q':

			break;
		case 'z':
			vyxod = 'z';

			break;
		default:
			vyxod = 'z';

			break;
		}

	} while (!((vyxod) == 'z'));
	*/

	return 0;
}

/*Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие
функции :
Редактировать машину
Печать всех машин
Поиск машины по номеру*/
#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];

union MyUn
{
	char h[7];
	int i;
};
MyUn number[N];

struct avto
{
	MyUn number[N];
	char color[100];
	char model[100];
	int flag;
};
avto myavto[N];

void liun() //заполнение нулями
{
	for (int t = 0; t < N; t++)
		myavto[t].number[t].h[0] = '\0';
}
//функция strlen
int StringToNumber(char* str)//функция strlen
{
	int k1 = 0;
	while (str[k1])
	{
		k1++;

	}
	return k1;
}
//функция конвертирует строку в число и возвращает это число
int StringToNumber1(char* str)//функция конвертирует строку в число и возвращает это число
{
	char A[10]; int k = 0; int d = 0; int res = 0;
	for (char i = '0'; i <= '9'; i++)
	{
		A[k] = i;
		k++;

	}
	d = StringToNumber(str);
	for (int i = d, k = 0; i >= 0; i--)
		for (int j = 0; j < 10; j++)
			if (str[i] == A[j]) { res = res + j * pow(10, k); k++; }

	return res;
}
//выбор меню, проверка выбора, через функцию strchr

char menu()//выбор меню, проверка выбора, через функцию strchr
{
	char ch;
	do {

		cout << "\n\n\n enter'q' Edit car";
		cout << "\n enter'e' Print all cars";
		cout << "\n enter'u' Search for cars by number";
		cout << "\n'z' if you want to exit the program press space";
		cout << endl;
		cin >> ch;
		if (ch == 'z') { return ch; }
	} while (!strchr("euq ", tolower(ch)));
	return ch;
}

// ввод n ой машины
void enter(int n)
{
	int i;
	do
	{
		cout << "\n Enter the number: if the number? then select 1, if characters select 2\t";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].i;

			break;
		case 2:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].h;

			break;
		default:
			break;
		}

	} while (!(i == 1 || i == 2));

	cout << "\nenter color\t";
	cin >> myavto[n].color;
	cout << "\nenter model\t";
	cin >> myavto[n].model;
	myavto[n].flag = i;
}
// печать n ой машины

void print(int n)
{

	cout << "\n YOUR CARS\t";
	cout << "\n Your value number\t";

	if (myavto[n].flag == 1) { cout << myavto[n].number[n].i; }
	else
	{
		cout << myavto[n].number[n].h;
	}
	cout << "\n Your value color\t" << myavto[n].color;
	cout << "\n Your value model\t" << myavto[n].model;
}

//фукция поиска по номеру машины через функцию strcmp
void Search_number()
{
	char name[100]; char* a; int ai;
	cout << "\nenter number cars to search";
	cin >> (name);
	a = name;
	ai = StringToNumber1(name);
	int t;
	for (t = 0; t < N; t++)
	{
		if (!(strcmp(name, myavto[t].number[t].h)) || myavto[t].number[t].i == ai) { break; }
	}
	if (t == N) { cout << "\nno search cars\t" << endl; }
	else
	{
		print(t);
	}
}

void edit()
{

	char name[100]; char* a; int ai;
	cout << "\nenter number cars to search";
	cin >> (name);
	a = name;
	ai = StringToNumber1(name);
	int t;
	for (t = 0; t < N; t++)
	{
		if (!(strcmp(name, myavto[t].number[t].h)) || myavto[t].number[t].i == ai) { break; }
	}
	if (t == N) { cout << "\nno search cars\t" << endl; }

	enter(t);
}
int main()
{
	char choice; char vyxod = 'a'; int a;
	liun();
	for (int n = 0; n < N; n++)
	{
		enter(n);
	}

	do {

		choice = menu();// выбор действия которое необходимо провести

		switch (choice)
		{
		case 'e':
			for (int n = 0; n < N; n++)
				print(n);

			break;

		case 'u':
			Search_number();
			break;
		case 'q':
			edit();
			break;
		case 'z':
			vyxod = 'z';

			break;
		default:
			vyxod = 'z';

			break;
		}

	} while (!((vyxod) == 'z'));
	return 0;
}