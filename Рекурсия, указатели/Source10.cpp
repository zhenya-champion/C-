//Используя указатели и оператор разыменования, определить наибольшее из двух чисел.

#include <iostream>

using namespace std;

void findMax(int* number1, int* number2);

int main()
{
    int userNumber1;
    int userNumber2;
    cout << "This program looks for the maximum of two numbers" << endl <<
        "Enter first number: ";
    cin >> userNumber1;
    cout << "Enter second number: ";
    cin >> userNumber2;

    int* pUserNumber1 = &userNumber1;
    int* pUserNumber2 = &userNumber2;

    findMax(pUserNumber1, pUserNumber2);
}

void findMax(int* number1, int* number2)
{
    cout << *number1;

    if (*number1 > *number2)
    {
        cout << " > ";
    }
    else if (*number1 < *number2)
    {
        cout << " < ";
    }
    else
    {
        cout << " = ";
    }
    cout << *number2 << endl;
}