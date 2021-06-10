//»спользу€ два указател€ на массив целых чисел, скопировать один массив в другой.
//»спользовать в программе арифметику указателей дл€ продвижени€ по массиву, а также
//оператор разыменовани€.

#include "iostream"
#include "ctime"
#include "stdlib.h"
#include "stdlib.h"
#include "stdio.h"
#include "cstdio"
#include "cstring"
using namespace std;
int sum(int& a, int& b);
const size_t N = 10;
typedef int T[N];

int main()
{
	T A; T B;
	int* a, * b;
	
	for (int i = 0; i < N; i++)
	{
		A[i] = (int)(((float)rand() / (float)RAND_MAX) * 100);
		cout << "\n" << A[i];
	}
	a = A; b = B;
	cout << "\n new array output" << endl;
	for (int i = 0; i < N; i++)
	{
		b[i] = a[i];
		
		cout << b[i] << endl;
	}

	

	return 0;
}
int sum(int& a, int& b)
{
	int c;
	c = a + b;
	return c;
}