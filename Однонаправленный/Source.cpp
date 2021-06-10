//Однонаправленный список

/*Тип информационного поля double.
Удалить из списка все элементы с четными номерами(2, 4, 6 и.т.д.).*/

#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<double> flist{ 1,2,3,4,5,6,7,8 };
    flist.remove_if([](int i) { return !(i % 2); });
    for (double i : flist) 
        cout << i << ", ";
}
