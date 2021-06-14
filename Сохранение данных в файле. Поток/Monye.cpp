#include "money.h" 

Money::Money()
{
name = ""; 
age = 0;
}
Money::Money(string N, int A)
{
	name = N; 
	age = A;
}
Money::Money(const Money& p)
{
	name = p.name; 
	age = p.age;
}
Money Money::operator =(const Money& p)
{
	if (&p == this) return *this; 
	name = p.name; 
	age = p.age; 
	return*this;
}
Money::~Money()
{
}

ostream& operator<<(ostream& out, const Money& p)
{
	out << "name: " << p.name << " age:" << p.age << "\n"; 
	return out;
}

istream& operator>>(istream& in, Money& p)
{
	cout << "name?"; 
	in >> p.name;

	cout << "age?"; 
	in >> p.age; return in;
}

//дружественные функции для работы с файловыми потоками

fstream& operator>>(fstream& fin, Money&p)
{
	fin >> p.name; fin >> p.age; return fin;
}
fstream& operator<<(fstream& fout, const Money& p)
{
	fout << p.name << "\n" << p.age << "\n"; return fout;
}


