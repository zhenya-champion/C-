#pragma once
#include "header.h"

class Vector
{
public:
	Vector(int);//����������� � �����������

public:
	~Vector(void);//����������
	void Add();//���������� �������� � ������ 
	void Del();
	void Show();
	int operator()();//������ �������
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;//��������� �� ������ ������� ������� 
	int size;//������
	int cur;//������� �������
};
