#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class addNumberFrom {
    int current;// текущее значение
    int delta;// шаг изменения
public:
    addNumberFrom(int _delta, int numberFrom = 0) : delta(_delta), current(numberFrom) {}
    int operator() () {
        return current += delta;
    }
};

int main()
{
    cout << "TABLE: " << "\n\n";
    cout << "____________________________________\n\n";
    for (int i = 1; i <= 10; i++) {
        list <int> l(10);
        generate_n(l.begin(), l.size(), addNumberFrom(i));
        copy(l.begin(), l.end(),
            ostream_iterator<int>(cout, "\t"));
    }
}



