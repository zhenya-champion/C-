//������������ ������ �����.���������� ���������� ���� � ���� �����, ��������� �� ����� �
//������� ��������������.���������� ���������� ����� � ���� �����.������� � �������������
//������������ ����� ����.


#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, cp, n = 0, sum = 0, c = 0;
    //c - ���-�� �����

    cout << "Number:";
    cin >> a;
    cp = a;

    //���-�� �����
    while (a)
    {
        if (a % 10 == 0)
            c++;
        a /= 10;
    }
    cout << "\n���-�� �����: " << c;

    //������� ��������������
    for (n = 0; cp > 0; n++)
    {
        sum += cp % 10;
        cp /= 10;
    }
    cout << "\n���-�� ���� = " << n << " \nSum = " << sum << "\nSredn arif = " << (double)sum / n << "\n";

    system("pause");
    return 0;
}