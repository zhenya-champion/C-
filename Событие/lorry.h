#pragma once
#include <iostream>
#include "bike.h"

using namespace std;

class Lorry :
	public Car
{
public:
Lorry(void); 
public:
	~Lorry(void); 
	void Show(); 
	void Input();
	Lorry(string, int, int, int); 
	Lorry(const Lorry&);
	int Get_gruz() { return gruz; } 
	void Set_Gruz(int);
Lorry& operator=(const Lorry&); 
protected:
	int gruz;
};

