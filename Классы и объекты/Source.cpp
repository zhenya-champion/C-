/*Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).*/

#include <iostream>
using namespace std;

class Ratio {
private:
    int a, b;
public:
    explicit Ratio(int na = 0, int nb = 0) : a(na), b(nb)
    {
        cout << "Hi: (" << a << "/" << b << ")" << endl << flush;
    }
    Ratio(const Ratio& src) : a(src.a), b(src.b)
    {
        cout << "Hi: (" << a << "/" << b << ")" << endl << flush;
    }

    ~Ratio() { cout << "RIP: (" << a << "/" << b << ")" << endl << flush; }

    Ratio& operator=(const Ratio& src) { a = src.a; b = src.b; return *this; }

    Ratio& operator+=(const Ratio& src)
    {
        a = a * src.b + b * src.a;
        b *= src.b;
        return *this;
    }
    int chislitel()  const { return a; }
    int znamenatel() const { return b; }

    Ratio& reverse() { int tmp = a; a = b; b = tmp; return *this; }

    operator int() const { return a / b; }

    Ratio operator+(const Ratio& src2) const
    {
        Ratio res(*this);
        res += src2;
        return res;
    }
};

ostream& operator<<(ostream& os, const Ratio& src)
{
    cout << "(" << src.chislitel() << "/";
    cout << src.znamenatel() << ")" << flush;
}

istream& operator>> (istream& is, Ratio& r)
{
    int na, nb = 1; is >> na;
    char c;       is >> c;

    if (c == '/') is >> nb;

    r = Ratio(na, nb);
    return is;
}

void main()
{
    Ratio r1, r2, r3;
    char op;
    cout << "enter r1" << flush;
    cin >> r1;
    cout << "enter op" << flush;
    cin >> op;
    cout << "enter r2" << flush;
    cin >> r2;

    switch (op) {
    case'+': r3 = r1 + r2; break;
    case'-': r3 == r1 - r2; break;
    case'*': r3 == r1 * r2; break;
    case'/': r3 == r1 / r2; break;
    default:
        cout << "Error!" << flush;
        return;
    }

    cout << r1 << ' ' << op << ' ' << r2 << " = " << r3 << flush;
}