//���� ������ ��������.���������� ��������� �������� �� ��� ������ �����������.

#include <iostream>
#include <string.h>
using namespace std;
bool palindrom(char s[100]);
int main()
{
    char s[100];
    cout << "������� ������" << endl;
    cin.getline(s, 100);
    if (palindrom(s))
        cout << "��������� " << endl;
    else
        cout << "�� ���������" << endl;
    return 0;
}
bool palindrom(char s[]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return false;
    return true;
}