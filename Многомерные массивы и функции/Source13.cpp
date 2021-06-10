//Написать функцию, определяющую количество положительных, отрицательных и нулевых
//элементов передаваемого ей массива.

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#define WINDOWS "russian"
#define LINUX "ru_RU.UTF-8"

void set_header(void);
void random_array(int[], size_t);
void printf_array(int[], size_t);
void counter_numbers(int[], size_t, int&, int&, int&);
const string ending(int, const string[]);

int main(void)
{
    setlocale(LC_ALL, WINDOWS);
    srand(static_cast<size_t>(time(NULL)));

    const string words[3][3] = {
        {"число", "числа", "чисел"},
        {"положительное", "положительных", "положительных"},
        {"отрицательное", "отрицательных", "отрицательных"}
    };
    const size_t size_array = 5;

    int* array_a = new int[size_array];
    int positive = 0;
    int negative = 0;
    int zero_num = 0;

    set_header();
    random_array(array_a, size_array);
    printf_array(array_a, size_array);
    counter_numbers(array_a, size_array, positive, negative, zero_num);

    cout << "\tВ массиве находится " << positive
        << " " << ending(positive, words[1])
        << " " << ending(positive, words[0])
        << "." << endl;
    cout << "\tВ массиве находится " << negative
        << " " << ending(negative, words[2])
        << " " << ending(negative, words[0])
        << "." << endl;
    cout << "\tВ массиве находится " << zero_num
        << " " << ending(zero_num, words[0])
        << " с нулевым значением." << endl
        << endl << endl << endl;

    system("pause");
    system("cls");
    delete[] array_a;
    return(0);
}

void set_header(void) {
    cout << "\n\n\n\tОсновы программирования на языке С++.\n"
        << "\tТема:  Функции. Передача массивов внутрь функции.\n\n"
        << "\tНаписать функцию, определяющую количество положительных,\n"
        << "\tотрицательных и нулевых элементов передаваемого ей массива.\n"
        << endl << endl << endl << endl;
}

void random_array(int array[], size_t size_array) {
    for (size_t i = 0; i < size_array; i++)
        array[i] = rand() % 21 - 10;
}

void printf_array(int array[], size_t size_array) {
    for (size_t i = 0; i < size_array; i++) {
        cout << "\t" << array[i];
        if ((i + 1) % 10 == 0)
            cout << "\n";
    }
    cout << endl << endl;
}


const string ending(int num, const string str[]) {
    if (num > 99) return ending(num % 100, str);
    else if (num > 19) return ending(num % 10, str);
    else if (num == 1) return str[0];
    else if (num > 1 && num < 5) return str[1];
    else return str[2];
}

void counter_numbers(int a[], size_t size, int& p, int& n, int& z) {
    for (size_t i = 0; i < size; ++i)
        if (a[i] < 0) n++;          // отрицательные
        else if (a[i] > 0) p++;     // положительные
        else z++;                   // нулевые
}