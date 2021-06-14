

#ifndef MAX_OOP_5_LORRY_H
#define MAX_OOP_5_LORRY_H

#include "Car.h"


class Lorry : public Car
{
public:
Lorry(void); public:
~Lorry(void);
void Show();//функция для просмотра атрибутов класса с помощью указателя
Lorry(string,int,int,int);
Lorry(const Lorry & );
int Get_gruz(){return gruz;}
void Set_Gruz(int);
Lorry& operator=(const Lorry&);
friend istream& operator>>(istream&in,Lorry&l);
friend ostream& operator<<(ostream&out,const Lorry&l);
protected:
int gruz;

};

#endif //MAX_OOP_5_LORRY_H
