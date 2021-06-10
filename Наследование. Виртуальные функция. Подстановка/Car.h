

#ifndef MAX_OOP_5_CAR_H
#define MAX_OOP_5_CAR_H


#include "Object.h"
#include <string>
#include <iostream>

using namespace std;


class Car: public Object
{
public:
Car();
virtual ~Car();
void Show();//функция для просмотра атрибутов класса с помощью указателя
Car(string,int,int);
Car(const Car&);
string Get_mark(){return mark;}
int Get_cyl(){return cyl;}
int Get_power(){return power;}
void Set_mark(string);
void Set_cyl(int);
void Set_power(int);
Car& operator=(const Car&);
friend istream& operator>>(istream&in,Car&c);
friend ostream& operator<<(ostream&out,const Car&c);
protected:
string mark; int cyl;
int power;

};

#endif //MAX_OOP_5_CAR_H
