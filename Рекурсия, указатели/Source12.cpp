//»спользу€ указатели и оператор разыменовани€, обмен€ть местами значени€ двух переменных.


#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "iomanip"
using namespace std;

int main()
{
	int a, b, temp;
	cout << "Vvedite 2 chisla ";
	cin >> a >> b;
	int* a1 = &a;
	int* b1 = &b;
	int* temp1 = &temp;
	*temp1 = *a1;
	*a1 = *b1;
	*b1 = *temp1;
	cout << *a1 << *b1;

	return 0;
}