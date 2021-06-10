//Пользуясь  указателем  на  массив  целых  чисел,
//изменить  порядок следования элементов  массива на противоположный.
//Использовать в программе арифметику указателей для продвижения по массиву,
//а также оператор разыменования.

#include <iostream>
using namespace std;

void main()
{
const int size = 5;
int arr[size] = { 5, 7, -8, 3, 9 }, temp;
int* start = arr, * end = &arr[size - 1];

while (start != end)
{
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
}