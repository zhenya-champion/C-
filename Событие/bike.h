#pragma once

#include <iostream>
#include "header.h"

using namespace std;

class Car :
	public Object
{
public:
	Car(void);                //����������� ��� ���������� 
public:
	virtual ~Car(void);              //����������
	void Show();                        //������� ��� ��������� ��������� ������ � ������� ��������� 
	void Input();                   //������� ��� ����� �������� ��������� 
	Car(string,int,int);                        //����������� � �����������
	Car(const Car&);                 //����������� �����������
void HandleEvent(const TEvent& e);
protected:
	string mark;
	int cyl;
	int power;
	          //���������
	string Get_mark() { return mark; } 
	int Get_cyl() { return cyl; }
	int Get_power() { return power; }

	          //������������
	void Set_mark(string);
	void Set_cyl(int);
	void Set_power(int);
	Car& operator=(const Car&);                     //���������� �������� ������������ 
};

