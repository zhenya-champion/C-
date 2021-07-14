#include "Lorry.h"
#include <iostream>

using namespace std;

Lorry::Lorry(void) :Car()
{
	gruz = 0;
}
Lorry::~Lorry(void)

{
}
Lorry::Lorry(string M, int C, int P, int G) :Car(M, C, P)
{
	gruz = G;
}
Lorry::Lorry(const Lorry& L)
{
	mark = L.mark; 
	cyl = L.cyl; 
	power = L.power; 
	gruz = L.gruz;
}
void Lorry::Set_Gruz(int G)
{
	gruz = G;
}
Lorry& Lorry::operator=(const Lorry& l)
{
	if (&l == this)return *this; 
	mark = l.mark; 
	power = l.power;
	cyl = l.cyl; 
	return *this;
}
void Lorry::Show()
{
	cout << "\nMARK : " << mark;
	cout << "\nCYL : " << cyl; 
	cout << "\nPOWER : " << power; 
	cout << "\nGRUZ : " << gruz; 
	cout << "\n";
}
void Lorry::Input()
{
	cout << "\nMark:"; 
	cin >> mark; 
	cout << "\nPower:"; 
	cin >> power; 
	cout << "\nCyl:";
	cin >> cyl; 
	cout << "\nGRUZ : "; 
	cin >> gruz;
}
