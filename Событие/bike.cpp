#include "bike.h"
#include <iostream>

using namespace std;

Car::Car(void)
{
	mark = ""; 
	cyl = 0; 
	power = 0;
}

//���������� 

Car::~Car(void)
{
}

//���������� � ����������� 

Car::Car(string M,int C,int P)
{
	mark = M; 
	cyl = C; 
	power = P;
}
//����������� ����������� 

Car::Car(const Car& car)
{
	mark = car.mark; 
	cyl = car.cyl;
	power = car.power;
}

//���������

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

//�������� ������������

Car& Car::operator=(const Car& c)
{
	if (&c == this)return *this; 
	mark = c.mark; 
	power = c.power;
	cyl = c.cyl;
	return *this;
}
//����� ��� ��������� ���������

void Car::Show()
{
	cout << "\nMARK : " << mark;
	cout << "\nCYL : " << cyl;
	cout << "\nPOWER : " << power; 
	cout << "\n";
}
//����� ��� ����� �������� ��������� 

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
	if (e.what == evMessage)                 //�������
	{
		switch (e.command)
		{
		case cmGet:cout << "mark=" << Get_mark() << endl; break;
		}
	}
}


