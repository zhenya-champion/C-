/*Тип информационного поля char* .
Добавить в список элемент после элемента с заданным информационным полем.*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#pragma warning(disable : 4996)

using namespace std;

char* file;

struct point
{
    point(int k, const char* ch, point* n = NULL)
        :key(k), info(new char[strlen(ch) + 1]), next(n), length(strlen(ch) + 1)
    {
        strcpy(info, ch);           //копирование строчки с информацией в структуру
    }
    int key;                        //ключ
    char* info;                     //информация
    point* next;                     //следующий элемент списка
    int length;                     //длина информации
    int shift;                      //смещение в файле (байт)
};

//проверяет принадлежит ли ключ списку

bool Belong(point*& list, int key)
{
    point* temp(list);
    while (temp && temp->key != key)     //пока есть элементы в списке и ключ текущего элемнта не равен ключу что мы ищем
        temp = temp->next;

    return (temp ? true : false);        //возвращаем true если temp!=NULL, те если ключ найден в списке
}

//добавляет в список элемент

void Add(point*& list, int key, const char* val)
{
    if (Belong(list, key))              //проверяем нет ли у нас элемента уже с таким ключом
    {
        cerr << "Element with key = " << key << " already exist\n";
        return;
    }

    if (!list)                          //если список пуст то добавим в голову списка элемент
        list = new point(key, val, NULL);
    else                                //иначе найдём хвост и добавим после него элемент
    {
        point* temp(list);
        while (temp->next)
            temp = temp->next;
        temp->next = new point(key, val, NULL);
    }
}
