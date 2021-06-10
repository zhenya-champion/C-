#include <MAGAZIN.h>


MAGAZIN::MAGAZIN(void)
{
	mark = ""; cyl = 0;
}
MAGAZIN::MAGAZIN(string M, string C)
{
	mark = M; cyl = C;
}
MAGAZIN::MAGAZIN(const MAGAZIN& MAGAZIN)
{
	mark = MAGAZIN.mark; cyl = MAGAZIN.cyl;
}
void MAGAZIN::Set_cyl(string C)
{
	cyl = C;
}
void MAGAZIN::Set_mark(string M)
{
	mark = M;
}
MAGAZIN& MAGAZIN::operator=(const MAGAZIN& c)
{
	if (&c == this)return *this; mark = c.mark;
	cyl = c.cyl; return *this;
}
void MAGAZIN::Show()
{
	cout << "\nMARK : " << mark; cout << "\nCYL : " << cyl << "\n";
}
void MAGAZIN::Input()
{
	cout << "\nMark:"; cin >> mark; cout << "\nCyl:"; cin >> cyl;
}

void MAGAZIN::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "mark=" << Get_mark() << endl; break;
		}
	}
}

