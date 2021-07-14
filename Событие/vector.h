#pragma once
#include "header.h"

class Vector
{
public:
	Vector(int);//конструктор с параметрами

public:
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор 
	void Del();
	void Show();
	int operator()();//размер вектора
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};
