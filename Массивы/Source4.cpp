//Пользователь вводит любое целое число А.Необходимо вывести все целые числа В,
//для которых А делиться без остатка на В* В и не делиться без остатка на В* В* В
#include <iostream>

using namespace std;

int main()
{
int a = 900;
cout << "A:";
cin >> a;
int c = (int)sqrt((double)a);
for (int b = 2; b <= c; b++)
if (a % (b * b) == 0 && a % (b * b * b))
cout << b << endl;
}