//�������� �������, ������� ��������� ��� ��������� : ��������� ������� � ����������
//�������, � ��������� ������� ����� �� ������ ���������� ������.

#include <iostream>
using namespace std;

int powInnumber(int number, int powNum)
{
    if (powNum == 0)
        return 1;
    if (powNum == 1)
        return number;
    int result = number;
    for (int i = 0; i < powNum - 1; i++)
        result *= number;
    return result;
}