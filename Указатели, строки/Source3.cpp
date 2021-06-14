//Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
//массив минимально возможного размера, в котором нужно собрать общие элементы двух
//массивов без повторений.

#include <iostream>

using namespace std;


int main()

{
cout << "Даны два массива: А [M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов\n\n";
int sizeA, sizeB;
cout << "Введите размер первого массива: ";
cin >> sizeA;
cout << "Введите размер второго массива: ";
cin >> sizeB;
int* arrA = new int[sizeA];
int* arrB = new int[sizeB];
cout << "\n\nПервый массив: ";
for (int x = 0; x < sizeA; x++)
{
	arrA[x] = rand() % 9 + 1;
	cout << arrA[x] << " ";
}
cout << "\n\nВторой массив: ";
for (int x = 0; x < sizeB; x++)
{
	arrB[x] = rand() % 9 + 1;
	cout << arrB[x] << " ";
}
int sizeC = sizeA + sizeB;
int* arrC = new int[sizeC];
cout << "\n\nТретий массив: ";
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