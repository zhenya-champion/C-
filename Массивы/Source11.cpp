/*������������ ������ ������� ����� �� ���(12 �������).����� ������������
������ ��������(��������, 3 � 6 � ����� ����� 3 - � � 6 - � �������).���������� ����������
�����, � ������� ������� ���� ����������� � �����, � ������� ������� ���� ���������� �
������ ���������� ���������.*/

#include <iostream>
using namespace std;

int main()
{
    double a[12], max = 0.0, min = 0.0;

    cout << "Enter the profit:\n";
    for (int i = 0; i < 12; i++)
    {
        cout << i + 1 << " month: "; cin >> a[i];
        if (i == 0 || a[i] > max) max = a[i];
        if (i == 0 || a[i] < min) min = a[i];
    }

    cout << "MAX profit:\n";
    for (int i = 0; i < 12; i++)
        if (a[i] == max) cout << "month " << i + 1 << "\n";

    cout << "MIN profit:\n";
    for (int i = 0; i < 12; i++)
        if (a[i] == min) cout << "month " << i + 1 << "\n";

    system("pause");
    return 0;
}