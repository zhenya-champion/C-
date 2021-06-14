//Дана строка символов.Заменить в ней все пробелы на табуляции.

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str("123 gs sdg ");

    std::cout << str << std::endl;

    std::replace(str.begin(), str.end(), ' ', '\t');

    std::cout << str << std::endl;
}