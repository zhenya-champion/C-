/*Создайте класс Complex (комплексное число) или используйте уже созданный вами класс. Создайте перегруженные
операторы для реализации арифметических операций для
по работе с комплексными числами (операции +, -, *, /).*/

#include <iostream>

class complex
{
private:
    double re, im;

public:
    complex() {}

    complex(double real, double imaginary)
        : re(real), im(imaginary) {}

    friend std::ostream& operator<<(std::ostream& os, complex& cpl);

    friend std::istream& operator>>(std::istream& is, complex& cpl);
};

std::ostream& operator<<(std::ostream& os, complex& cpl)
{
    os << cpl.re << '+' << cpl.im << 'i';
}

std::istream& operator>>(std::istream& is, complex& cpl)
{
    is >> cpl.re >> cpl.im;
}

int main()
{
    complex c;
    std::cin >> c;
    std::cout << c << std::endl;

    return EXIT_SUCCESS;
}