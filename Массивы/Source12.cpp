/*� ���������� �������, ��������� �� N ������������ ����� ��������� :
� ����� ������������� ���������.
� ������������ ���������, ����������� ����� min � max ����������.
� ������������ ��������� � ������� ��������.
� ����� ���������, ����������� ����� ������ � ��������� ��������������
����������.*/

#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "������� ����������� �������: ";
    int n;
    std::cin >> n;
    int* a = new int[n];
    std::cout << "������� " << n << " ���������:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "a[" << i + 1 << "]: ";
        std::cin >> a[i];
    }
    int negativ = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            negativ += a[i];
        }
    }
    std::cout << "����� ������������� ����� ������� = " << negativ << std::endl;
    int max = a[1], i_max, min = a[1], i_min;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            i_max = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            i_min = i;
        }
    }
    i_min++;
    i_max--;
    int mult = 1;
    for (int i = i_min; i < i_max; i++)
    {
        mult *= a[i];
    }
    std::cout << "������������ ��������� ����� ����������� � ������������� ���������� = " << mult << std::endl;
    mult = 1;
    for (int i = 1; i < n; i += 2)
    {
        mult *= a[i];
    }
    std::cout << "������������ ��������� � ������� �������� = " << mult << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            i_min = i;
            break;
        }
    }
    for (int i = n - 1; i > i_min; i--)
    {
        if (a[i] < 0)
        {
            i_max = i;
            break;
        }
    }
    i_min++;
    mult = 1;
    for (int i = i_min; i < i_max; i++)
    {
        mult *= a[i];
    }
    std::cout << "������������ ��������� ������� ����� ������ � ��������� �������������� ������� = " << mult << std::endl;
    system("Pause >> 0");
    return 0;
}