//Подсчитать количество слов во введенном предложении.

#include <iostream>
#include <string>
using namespace std;


void main()
{
    setlocale(LC_ALL, "rus");
    int counter = 0;
    cout << "Введите предложение: ";
    string st;
    getline(cin, st);

    for (int i = 1; i < st.size(); i++)
    {
        if (st[i - 1] != ' ' && (st[i] == ' ' || st[i + 1] == '\0')) counter++;
    }

    cout << "Количество слов в данном предложении " << counter << endl;
}