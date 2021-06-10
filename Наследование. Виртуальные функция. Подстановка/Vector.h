

#ifndef MAX_OOP_5_VECTOR_H
#define MAX_OOP_5_VECTOR_H

#include "Object.h"
#include <string>
#include <iostream>

using namespace std;


class Vector
{
public:
    Vector(void);//конструктор без параметров
    Vector(int);//конструктор копирования
public:
    ~Vector(void);//деструктор
    void Add(Object *);//добавление элемента в вектор
    friend ostream& operator<<(ostream&out,const Vector&);//операция вывода
private:
    Object**beg;//указатель на первый элемент вектора
    int size;//размер
    int cur;//текущая позиция
};


#endif //MAX_OOP_5_VECTOR_H
