#include "bike.h"
#include <iostream>

using namespace std;

Car::Car(void)
{
	mark = ""; 
	cyl = 0; 
	power = 0;
}

//деструктор 

Car::~Car(void)
{
}

//констрктор с параметрами 

Car::Car(string M,int C,int P)
{
	mark = M; 
	cyl = C; 
	power = P;
}
//конструктор копирования 

Car::Car(const Car& car)
{
	mark = car.mark; 
	cyl = car.cyl;
	power = car.power;
}

//селекторы

void Car::Set_cyl(int C)
{
	cyl = C;
}
void Car::Set_mark(string M)
{
	mark = M;
}
void Car::Set_power(int P)
{
	power = P;
}

//оператор присваивания

Car& Car::operator=(const Car& c)
{
	if (&c == this)return *this; 
	mark = c.mark; 
	power = c.power;
	cyl = c.cyl;
	return *this;
}
//метод для просмотра атрибутов

void Car::Show()
{
	cout << "\nMARK : " << mark;
	cout << "\nCYL : " << cyl;
	cout << "\nPOWER : " << power; 
	cout << "\n";
}
//метод для ввода значений атрибутов 

void Car::Input()
{
	cout << "\nMark:"; 
	cin >> mark; 
	cout << "\nPower:"; 
	cin >> power; 
	cout << "\nCyl:"; 
	cin >> cyl;
}

void Car::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)                 //событие
	{
		switch (e.command)
		{
		case cmGet:cout << "mark=" << Get_mark() << endl; break;
		}
	}
}


