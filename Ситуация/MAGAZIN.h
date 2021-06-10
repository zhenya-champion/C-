#pragma once

#include <iostream>
using namespace std;

class MAGAZIN : public Object
{
public:
	MAGAZIN(void);
public:
	virtual ~MAGAZIN(void);
	void Show();
	void Input();
	MAGAZIN(const MAGAZIN&);


	string Get_mark() { return mark; } string Get_cyl() { return cyl; }
	


	void Set_mark(string); void Set_cyl(string);
	MAGAZIN& operator=(const MAGAZIN&);
protected:
	string mark; string cyl;
};
class MAGAZIN : public Object
{
public:

void HandleEvent(const TEvent& e); protected:
	string mark;
	string cyl;

};
