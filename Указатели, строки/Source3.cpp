//���� ��� ������� : �[M] � B[N](M � N �������� � ����������).���������� ������� ������
//������ ���������� ���������� �������, � ������� ����� ������� ����� �������� ����
//�������� ��� ����������.

#include <iostream>

using namespace std;


int main()

{
cout << "���� ��� �������: � [M] � B[N] (M � N �������� � ����������). ���������� ������� ������ ������ ���������� ���������� �������, � ������� ����� ������� �������� ����� ��������\n\n";
int sizeA, sizeB;
cout << "������� ������ ������� �������: ";
cin >> sizeA;
cout << "������� ������ ������� �������: ";
cin >> sizeB;
int* arrA = new int[sizeA];
int* arrB = new int[sizeB];
cout << "\n\n������ ������: ";
for (int x = 0; x < sizeA; x++)
{
	arrA[x] = rand() % 9 + 1;
	cout << arrA[x] << " ";
}
cout << "\n\n������ ������: ";
for (int x = 0; x < sizeB; x++)
{
	arrB[x] = rand() % 9 + 1;
	cout << arrB[x] << " ";
}
int sizeC = sizeA + sizeB;
int* arrC = new int[sizeC];
cout << "\n\n������ ������: ";
for (int x = 0; x < sizeA; x++)
{
	arrC[x] = arrA[x];
}
int i = 0;
for (int x = sizeA; x < sizeC; x++)
{
	arrC[x] = arrB[i];
	i++;
}
for (int x = 0; x < sizeC; x++)
{
	cout << arrC[x] << " ";
}

delete arrA;
delete arrB;
delete arrC;
}