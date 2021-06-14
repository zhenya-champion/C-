#pragma once

#include <iostream>
#include "header.h"

using namespace std;

class Car :
	public Object
{
public:
	Car(void);                //конструктор без параметров 
public:
	virtual ~Car(void);              //деструктор
	void Show();                        //функция для просмотра атрибутов класса с помощью указателя 
	void Input();                   //функция для ввода значений атрибутов 
	Car(string,int,int);                        //конструктор с параметрами
	Car(const Car&);                 //конструктор копирования
void HandleEvent(const TEvent& e);
protected:
	string mark;
	int cyl;
	int power;
	          //селекторы
	string Get_mark() { return mark; } 
	int Get_cyl() { return cyl; }
	int Get_power() { return power; }

	          //модификаторы
	void Set_mark(string);
	void Set_cyl(int);
	void Set_power(int);
	Car& operator=(const Car&);                     //перегрузка операции присваивания 
};

