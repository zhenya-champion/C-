//�������� �������, ������� �������� � �������� ���������� 2 ����� ����� � ���������� �����
//����� �� ��������� ����� ����.
#include <iostream>
#pragma hdrstop
#pragma argsused

int sum(int a, int b) 
{ 
	int s = 0;
	for (int i = a + 1; i < b; i++)
		s += i;
	return(s);
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << (sum(a, b));
	system("pause");
}