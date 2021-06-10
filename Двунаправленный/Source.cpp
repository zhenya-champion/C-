/*��� ��������������� ���� char* .
�������� � ������ ������� ����� �������� � �������� �������������� �����.*/

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
        strcpy(info, ch);           //����������� ������� � ����������� � ���������
    }
    int key;                        //����
    char* info;                     //����������
    point* next;                     //��������� ������� ������
    int length;                     //����� ����������
    int shift;                      //�������� � ����� (����)
};

//��������� ����������� �� ���� ������

bool Belong(point*& list, int key)
{
    point* temp(list);
    while (temp && temp->key != key)     //���� ���� �������� � ������ � ���� �������� ������� �� ����� ����� ��� �� ����
        temp = temp->next;

    return (temp ? true : false);        //���������� true ���� temp!=NULL, �� ���� ���� ������ � ������
}

//��������� � ������ �������

void Add(point*& list, int key, const char* val)
{
    if (Belong(list, key))              //��������� ��� �� � ��� �������� ��� � ����� ������
    {
        cerr << "Element with key = " << key << " already exist\n";
        return;
    }

    if (!list)                          //���� ������ ���� �� ������� � ������ ������ �������
        list = new point(key, val, NULL);
    else                                //����� ����� ����� � ������� ����� ���� �������
    {
        point* temp(list);
        while (temp->next)
            temp = temp->next;
        temp->next = new point(key, val, NULL);
    }
}
