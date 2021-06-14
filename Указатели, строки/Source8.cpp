//Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    size_t pos = 0;
    size_t i = 0;
    while ((i = str.find(".", pos)) != string::npos)
    {
        str.erase(i, 1);
        pos += i;
    }
    cout << str;
}