//������������ ������ ����� ����� ����� �.���������� ������� ��� ����� ����� �,
//��� ������� � �������� ��� ������� �� �* � � �� �������� ��� ������� �� �* �* �
#include <iostream>

using namespace std;

int main()
{
int a = 900;
cout << "A:";
cin >> a;
int c = (int)sqrt((double)a);
for (int b = 2; b <= c; b++)
if (a % (b * b) == 0 && a % (b * b * b))
cout << b << endl;
}