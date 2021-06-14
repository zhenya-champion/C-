//Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
//массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.

#include <iostream>

int main()
{
    int* mas1 = new int[];
    int* mas2 = new int[];
    std::cout << "Enter M \n";
    int m;
    std::cin >> m;
    std::cout << "Enter N \n";
    int n;
    std::cin >> n;
    for (int i = 0; i < m; ++i)
    {
        mas1[i] = rand() % 10;
        std::cout << mas1[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i)
    {
        mas2[i] = rand() % 10;
        std::cout << mas2[i];
    }
    std::cout << std::endl;
    int* mas3 = new int[];
    for (int i = 0; i < m; ++i)
    {
        mas3[i] = mas1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        mas3[m + i] = mas2[i];
    }
    for (int i = 0; i < m + n; ++i)
    {
        std::cout << mas3[i];
    }
    system("pause>>null");
}