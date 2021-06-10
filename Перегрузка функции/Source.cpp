//Написать перегруженные функции и основную программу, которая их вызывает.
//а) для вычитания десятичных дробей;
//б) для вычитания обыкновенных дробей.


#include <iostream>
using namespace std;

void subtraction(int aU, int aD, int bU, int bD)
{
    cout << (aU * bD) - (bU * aD) << "/" << bD * aD << endl;
}
void subtraction(double a, double b)
{
    cout << a - b << endl;
}

int main()
{
    subtraction(32.12, 31.2);
    subtraction(2, 5, 1, 6);

    return 0;
}