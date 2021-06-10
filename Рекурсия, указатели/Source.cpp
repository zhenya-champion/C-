//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел

#include <iostream>


int gmd(int  a, int  b)
{
    if (!b) return a;
    return gmd(b, a % b);
}