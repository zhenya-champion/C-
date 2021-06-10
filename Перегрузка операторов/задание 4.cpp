/*Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция
==);
2. Операцию присваивания одного объекта в другой
(операция =);
3. Сравнение двух квартир по цене (операция>).*/

class flat
{
private:
    double price;
    double area;
public:
    flat() : price(0), area(0) { };
    flat(const double& prc, const double& area) : price(prc), area(area) { };
    flat(const flat& date) : price(date.price), area(date.area) { };
    ~flat() { };
    flat& operator = (const flat& date);

    friend bool operator == (const flat& lhs, const flat& rhs);
    friend bool operator != (const flat& lhs, const flat& rhs);

    friend bool operator > (const flat& lhs, const flat& rhs);
    friend bool operator < (const flat& lhs, const flat& rhs);
};

flat& flat::operator = (const flat& date)
{
    if (this == &date)
    {
        return *this;
    }

    price = date.price;
    area = date.area;
    return *this;
}

bool operator == (const flat& lhs, const flat& rhs)
{
    return lhs.area == rhs.area;
}

bool operator != (const flat& lhs, const flat& rhs)
{
    return !(lhs.area == rhs.area);
}

bool operator > (const flat& lhs, const flat& rhs)
{
    return lhs.price > rhs.price;
}

bool operator < (const flat& lhs, const flat& rhs)
{
    return lhs.price < rhs.price;
}