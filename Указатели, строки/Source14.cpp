//���� ������ ��������.���������� ���������� ����, ���� � ��������� ��������,
//�������������� � ������.

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int countLetter = 0, countDigit = 0, countSymb = 0;
    char str[500];
    cout << "������� ������:" << endl;
    cin.getline(str, 500);
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
            countLetter++;
        else if (isdigit(str[i]))
            countDigit++;
        else
            countSymb++;
    }
    cout << "���������� ���� � ������: " << countLetter << endl;
    cout << "���������� ���� � ������: " << countDigit << endl;
    cout << "���������� ������ �������� � ������: " << countSymb << endl;
    system("pause");
    return 0;
}