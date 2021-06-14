

#ifndef MAX_OOP_7_VECTOR_H
#define MAX_OOP_7_VECTOR_H


#include <iostream>

using namespace std;

template <class T> //T - параметр шаблона
class Vector
{
public:
//конструктор с параметрами: выделяет память под s элементов и заполняет их
//значением k
    Vector(int s,T k){
        size=s;
        data=new T[size];
        for(int i=0;i<size;i++)
            data[i]=k;
    }
//конструктор с параметрами
    Vector(const Vector<T>&a) {
        size=a.size; data= new T[size];
        for(int i=0;i<size;i++)
            data[i]=a.data[i];
    }
//деструктор
    ~Vector() {
        delete[]data; data=0;
    }
//оператор присваивания
    Vector&operator=(const Vector<T>&a){
        if(this==&a)return *this; size=a.size;
        if (data!=0) delete[]data; data=new T[size];
        for(int i=0;i<size;i++) data[i]=a.data[i];
        return *this;
    }
//операция доступа по индексу
    T&operator[](int index) {
        if (index<size)
            return data[index];
        else
            cout<<"\nError! Index>size";
    }
//операция для добавление константы
    Vector operator+(const T k) {
        Vector<T> temp(size,k);//инициализируем временный вектор любым значением
        for (int i=0;i<size;++i)
            temp.data[i]=data[i]+k;
        return temp;
    }
//операция, возвращающая длину вектора
    int operator()() {
        return size;
    }
//перегруженные операции ввода-вывода
// <> - указывают на то, что функция является шаблоном
    friend ostream& operator<< (ostream& out, const Vector<T>&a){
        for(int i=0;i<a.size;++i)
            out<<a.data[i]<<" ";
        return out;
    }
    friend istream& operator>> (istream& in, Vector<T>&a){
        for(int i=0;i<a.size;++i)
            in>>a.data[i];
        return in;
    }
private:
    int size;//размер вектора
    T*data;//укзатель на динамический массив значений вектора
}; 
#endif
