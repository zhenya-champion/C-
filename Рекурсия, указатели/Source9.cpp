//Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы
//во втором массиве элементы находились в обратном порядке.

#include <iostream>
#include <string>

void func(int* array_1, int* array_2, int value) {
    for (int i(0); i != value; i++) {
        std::cout << array_1[i] << std::endl;
        array_2[(value - 1) - i] = array_1[i];
    }
    std::cout << "***" << std::endl;
    for (int i(0); i != value; i++) {
        std::cout << array_2[i] << std::endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int value(5);
    int* array_1, * array_2;

    array_1 = new int[value];
    array_2 = new int[value];

    for (int i(0); i != value; i++) {
        array_1[i] = rand() % 10;
    }

    func(array_1, array_2, value);

    system("pause");
    return 0;
}