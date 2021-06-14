//�������� �������, ������� �������� ��������� �� ������������ ������ � ��� ������.�������
//������ ������� �� ������� ��� ������� ����� � ������� ��������� �� ����� ������������
//������.

#include <iostream>
#include <ctime>
using namespace std;

int* delete_simple_numbers(int* arr, int& size)
{
    int tmpsize = 0; // ������ ���������� ������� �����
    for (int i = 0; i < size; i++)
    {
        int tmp = *(arr + i);

        for (int j = 2; j <= tmp; j++)
        {
            if (j != tmp && tmp % j == 0)
                break;
            if (j == tmp && tmp % j == 0)
            {
                tmpsize++;
            }
        }
    }

    int* tmppoint = new int[tmpsize];
    int count = 0;

    for (int i = 0; i < size; i++) // ������ ��������� ������ � �������� ��� ��������� ����� �� ������� �������, ������� �������� ��������
    {
        int tmp = *(arr + i);
        for (int j = 2; j <= tmp; j++)
        {
            if (j != tmp && tmp % j == 0)
                break;
            if (j == tmp && tmp % j == 0)
            {
                *(tmppoint + count) = i;
                count++;
            }
        }
    }

    int newsize = size - tmpsize;
    int* newpoint = new int[newsize]; // ������ ������ ������, ��������� � ��������� � �������� ���������� ����� � ����
    count = 0;
    int count2 = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(tmppoint + count2) == *(arr + i)) // ����� �������� ���������� ������
        {
            count2++;
            continue;
        }
        else
        {
            *(newpoint + count) = *(arr + i);
            count++;
        }
    }

    delete[] arr, tmppoint;
    size = newsize;
    return newpoint;
}

int main()
{
    srand(time(NULL));

    int size = 10;
    int* point = new int[size];

    for (int i = 0; i < size; i++)
    {
        *(point + i) = rand() % 8 + 2;
        cout << *(point + i) << " ";
    }
    cout << endl;

    point = delete_simple_numbers(point, size);

    for (int i = 0; i < size; i++)
    {
        cout << point[i] << " ";
    }
    cout << endl;


    delete[] point;
    system("pause");
    return 0;
}