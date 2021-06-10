/*Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и играющий
должен угадать его.После ввода пользователем числа программа сообщает, сколько цифр числа
угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).После отгадывания
числа на экран необходимо вывести количество сделанных пользователем попыток.В
программе необходимо использовать рекурсию.*/


#include <iostream>
#include <time.h>

struct game
{
    int q[4];
    int a[4];

    void init()
    {
        for (int i = 0; i < 4; ++i)
        {
            q[i] = rand() % 10;
        }
    }

    void proceed(int n)
    {
        ++n;
        int num;

        std::cout << "\nInput num: ";
        std::cin >> num;


        if (check(num))
        {
            std::cout << "\n******\n\nOK, attempts = " << n;

            char x;
            do
            {
                std::cout << "\n\nAnother run? (y/n) ";
                std::cin >> x;
            } while (x != 'y' && x != 'n');

            if (x == 'y') run();


        }
        else {
            proceed(n);
        }
    }

    bool check(int num)
    {
        for (int i = 3; i >= 0; --i)
        {
            a[i] = num % 10;
            num /= 10;
        }

        int b = 0;
        int c = 0;
        bool c_check[4] = { false };

        for (int i = 0; i < 4; ++i)
        {
            if (q[i] == a[i])
            {
                ++b;
                c_check[i] = true;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (i == j || c_check[j]) continue;
                if (a[i] == q[j])
                {
                    ++c;
                    c_check[j] = true;
                    break;
                }
            }
        }

        if (b == 4) return true;

        std::cout << "\n b = " << b << " c = " << c << "\n------------------------";

        return false;
    }

    void run()
    {
        init();
        proceed(0);
    }
};

int main()
{
    srand(time(0));

    game A;

    A.run();

    system("pause");
    return 0;
}