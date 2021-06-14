//Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается
//в строке.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int count = 0;
    char searchKey = 'a';
    cout << "enter string: ";
    getline(cin, line);
    for (unsigned int i = 0; i < line.length(); i++)
        if (line[i] == searchKey)
            count++;
    cout << "string has " << count << " symbol(s) " << """ << searchKey << ""!" << endl;
    return 0;
}