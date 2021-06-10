/*В двумерном массиве целых числе посчитать :
? Сумму всех элементов массива
? Среднее арифметическое всех элементов массива
? Минимальный элемент
? Максимальный элемент*/
#include <iostream>
#define N 100
#define M 100

void main()
{
	int arr[N][M], i, j, min, max, sum = 0, count = 0;

	max = min = arr[0][0];

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			sum += arr[i][j];
			count++;
			if (arr[i][j] > max) max = arr[i][j];
			if (arr[i][j] < min) min = arr[i][j];
		}
	std::cout << "Сумма = " << sum << "\nСреднее арифметическое = " << sum / count << "\nMIN = " << min << "\nMAX = " << max;
}