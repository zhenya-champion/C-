//Дана строка символов.Определить количество букв, цифр и остальных символов,
//присутствующих в строке.

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
    cout << "Введите строку:" << endl;
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
    cout << "Количество букв в строке: " << countLetter << endl;
    cout << "Количество цифр в строке: " << countDigit << endl;
    cout << "Количество других символов в строке: " << countSymb << endl;
    system("pause");
    return 0;
}