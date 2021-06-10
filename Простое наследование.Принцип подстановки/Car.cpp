#include "Car.h"
//конструктор без параметров 
Car::Car(void)
{
mark = ""; cyl = 0; power = 0;
}
//деструктор 
Car::~Car(void)
{
}
//конструктор с параметрами 
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
//модификаторы
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
//перегрузка операции присваивания 
Car& Car::operator=(const Car&c)
{
	if (&c == this)return *this; 
	mark = c.mark; 
	power = c.power; 
	cyl = c.cyl;
	return *this;
}
//глобальная функция для ввода 
istream& operator>>(istream&in,Car&c)
{
	cout << "\nMark:"; in >> c.mark; 
	cout << "\nPower:"; in >> c.power; 
	cout << "\nCyl:"; in >> c.cyl; return in;
}
//глобальная функция для вывода
ostream& operator<<(ostream& out, const Car& c)
{
	out << "\nMARK : " << c.mark; 
	out << "\nCYL : " << c.cyl; 
	out << "\nPOWER : " << c.power; 
	out << "\n";
	return out;
}
