//���������� ���������� ����� ����� � ��������� �� 100 �� 999 � ������� ��� �����
//������


#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int k = 0;
    int i1, i2, i3;
    for (int i = 100; i <= 999; i++)
    {
        i1 = i / 100; //������ �����
        i2 = i % 10; // ������ �����
        i3 = (i % 100) / 10; //������ �����
        if (i1 == i2 || i2 == i3 || i3 == i1) k++;

    }
    cout << "Result: " << k << "\n";
    system("pause");
}