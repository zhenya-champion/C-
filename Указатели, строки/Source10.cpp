//Написать программу, которая заменяет все символы точки "." в строке, введенной
//пользователем, на символы восклицательного знака "!".

#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
    std::replace_copy(std::istream_iterator<char>(std::cin), 
        std::istream_iterator<char>(), 
        std::ostream_iterator<char>(std::cout), '.', '!');
}