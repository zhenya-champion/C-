/*—оздайте класс ƒробь (или используйте уже ранее созданный вами). »спользу€ перегрузку операторов реализуйте
дл€ него арифметические операции дл€ работы с дроб€ми
(операции +, -, *, /).*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Drob
{
public:
    Drob(int num1 = 0, int num2 = 1);


    Drob operator *(const Drob& rhs) const
    {
        return Drob(num1 * rhs.num1, num2 * rhs.num2);
    }

    Drob operator +(const Drob& rhs) const
    {
        if (num2 != rhs.num2)
            cout << "ERROR............." << endl;

        return Drob(num1 + rhs.num1, num2);
    }

    Drob operator -(const Drob& rhs) const
    {
        if (num2 != rhs.num2)
            cout << "ERROR............." << endl;

        return Drob(num1 - rhs.num1, num2);
    }

    Drob operator /(const Drob& rhs) const
    {
        return Drob(num1 * rhs.num1, num2 * rhs.num2);
    }

protected:
    int num1;
    int num2;
};