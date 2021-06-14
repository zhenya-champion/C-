//Решить указанную в варианте задачу, используя функции с переменным числом параметров.
//Написать функцию kvadr с переменным числом параметров,
//которая определяет количество чисел, являющихся точными квадратами (2, 4, 9, 16,. . . ) типа int.
//Написать вызывающую функцию main, которая обращается к функции kvadr не менее трех раз с количеством параметров 3, 7, 11.

#include <iostream>
#include <algorithm>

template <int ... Args>
size_t kvadr()
{
    auto list = { Args... };
    return std::count_if(list.begin(), list.end(), [](int val)
        {
            return (val > 0 && sqrt(val) - static_cast<int>(sqrt(val)) <= std::numeric_limits<double>::epsilon());
        });
}

int main()
{
    std::cout << kvadr<1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17>();

    return 0;
}