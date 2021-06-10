//»спользу€ указатели и оператор разыменовани€, определить знак числа, введЄнного с
//клавиатуры.

#include <iostream>

using namespace std;

void deerminePosNeg(int* number);

int main()
{
    int userNumber;
    cout << "This program defines positive or negative number is entered from the keyboard" << endl <<
        "Enter number: ";
    cin >> userNumber;

    int* pUserNumber = &userNumber;
    deerminePosNeg(pUserNumber);
}

void deerminePosNeg(int* number)
{
    cout << "Our number " << *number;
    if (*number > 0)
    {
        cout << " = positive" << endl;
    }
    else if (*number < 0)
    {
        cout << " = negative" << endl;
    }
    else
    {
        cout << " = zero" << endl;
    }
}