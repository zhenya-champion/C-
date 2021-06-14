//Шаблоны классов

/*Класс - контейнер ВЕКТОР с элементами типа int.
Реализовать операции :
[] – доступа по индексу;
() – определение размера вектора;
+число – добавляет константу ко всем элементам вектора;
Пользовательский класс Time для работы с временными интервалами.
Интервал должен быть представлен в виде двух полей : минуты типа int и секунды типа int.
при выводе минуты отделяются от секунд двоеточием.*/


#include <iostream>
#include "Vector.h"
#include "Time.h"
int main() {
    //инициализация, ввод и вывод значений вектора
    Vector<int> A(5,0);
    cin>>A;
    cout<<A<<endl;
//инициализация и вывод значений вектора
    Vector <int>B(10,1);
    cout<<B<<endl;
//операция присваивания
    B=A;
    cout<<B<<endl;
    cout <<A[2]<<endl;//доступ по индексу
    cout<<"size="<<A()<<endl;//получение длины вектора
//операция сложения с константой
    B=A+10;
    cout<<B<<endl;
    /*
     * Time testing
     */
    Time t;
    cin>>t;
    cout<<t << endl;
    int k;
    cout<<"k?";
    cin>>k;
    Time p;
    Time time_k(k, 0); // необходимо т.к. мы реализовали перегрузку оператора `+` для `Time`, а не `int`
    p = t + time_k;
    cout<<p;
    /*
     * Vector testing
     */
    Time time;
    cin>>time;
    cout<<time;
    Vector<Time>A_time(5,t);
    cin>>A_time;
    cout<<A_time<<endl;
    Vector <Time>B_time(10,t);
    cout<<B_time<<endl;
    B_time = A_time;
    cout<<B_time<<endl; cout <<A_time[2]<<endl;
    cout<<"size="<<A_time()<<endl;
    B_time = A_time + time;
    cout<<B_time<<endl;
    return 0;
}