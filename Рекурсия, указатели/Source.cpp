//�������� ����������� ������� ���������� ����������� ������ �������� ���� ����� �����

#include <iostream>


int gmd(int  a, int  b)
{
    if (!b) return a;
    return gmd(b, a % b);
}