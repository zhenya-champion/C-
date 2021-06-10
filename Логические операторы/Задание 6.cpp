#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, c;
    double sa, sb, sc;

    cout << "Введите уровень продаж для трех менеджеров =\n";
    cin >> a >> b >> c;

    if (a < 500)
        sa = 0.03 * a + 200;
    else
        if (a >= 500 && a <= 1000)
            sa = 0.05 * a + 200;
        else
            if (a > 1000)
                sa = 0.08 * a + 200;



    if (b < 500)
        sb = 0.03 * b + 200;
    else
        if (b >= 500 && b <= 1000)
            sb = 0.05 * b + 200;
        else
            if (b > 1000)
                sb = 0.08 * b + 200;


    if (c < 500)
        sc = 0.03 * c + 200;
    else
        if (c >= 500 && c <= 1000)
            sc = 0.05 * c + 200;
        else
            if (c > 1000)
                sc = 0.08 * c + 200;

    if (a > b && a > c)
        sa += 200;
    else
        if (b > c)
            sb += 200;
        else
            sc += 200;

    cout << "ЗП 1 менеджера:" << sa << "$" << endl;
    cout << "ЗП 2 менеджера:" << sb << "$" << endl;
    cout << "ЗП 3 менеджера:" << sc << "$" << endl;
    system("pause");
    return 0;
}