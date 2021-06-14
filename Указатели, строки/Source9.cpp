//Написать функцию, которая вставляет в строку в указанную позицию заданный символ.

#include <iostream>
#include <string>
using namespace std;

void InsertSymbol(string& s, char ch, size_t pos)
{
    s += ch;
    for (size_t i = s.size() - 1; i >= pos; i--)
        s[i] = s[i - 1];
    s[pos - 1] = ch;
}

int main()
{
    char ch;
    size_t pos, size;
    string s;
    cout << "String:\n";
    getline(cin, s);
    cout << "Symbol:\n";
    cin >> ch;

    size = s.size();
    do
    {
        cout << "Position:\n";
        cin >> pos;
        if (pos<1 || pos>size) cout << "1<=pos<=" << size << "  Repeat please...\n";
    }     while (pos<1 || pos>size);

    InsertSymbol(s, ch, pos);

    cout << s << "\n";

    system("pause");
    return 0;
}