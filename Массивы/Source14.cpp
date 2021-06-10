//Напишите программу, которая выполняет поэлементную сумму двух массивов и результат
//заносит в третий массив.

#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    int arr1[size];
    int arr2[size];
    int arrs[size];
    cout << "Enter the random numbers to fill first array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "arr1[" << i << "] = ";
        cin >> arr1[i];
    }
    cout << "\nEnter the random numbers to fill second array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "arr2[" << i << "] = ";
        cin >> arr2[i];
    }
    cout << "\nThe third array with the sum of two arrays:\n";
    for (int i = 0; i < size; i++)
    {
        arrs[i] = arr1[i] + arr2[i];
        cout << "arr3[" << i << "] = ";
        cout << arrs[i] << "\n";
    }  
}