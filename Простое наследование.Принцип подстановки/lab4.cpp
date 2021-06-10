//Простое наследование. Принцип подстановки.

/*Базовый класс:
МАШИНА
торговая_марка - string 
число_цилиндров - int 
мощность - int
Создать производный класс ГРУЗОВИК, добавив в него характеристику грузоподъемности кузова типа int.
*/

#include <iostream> 
#include "Car.h" 
#include "Грузовик.h" 
using namespace std;
void f1(Car&c)
{
c.Set_mark("Opel");

cout << c;
}
Car f2()
{
	Lorry l("Kia", 1, 2, 3); 
	return l;
}
void main()
{
	//работа с классом Car 
	Car a;
	cin >> a; 
	cout << a;
	Car b("Ford", 4, 115); 
	cout << b;
	a = b; 
	cout << a;                     
	//работа с классом Lorry 
	Lorry c;
	cin >> c; 
	cout << c;                            
	//принцип подстановки 
	f1(c);                              //передаем объект класса Lorry
	a = f2();                                //создаем в функции объект класса Lorry 
	cout<<a;
}

